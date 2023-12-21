#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include "library.h"

static void* dynamicLibrary = NULL;

// Load the DarumaFramework for memory
void loadDarumaFramework()
{
	dynamicLibrary = dlopen("/opt/DarumaFramework/libDarumaFramework.so", RTLD_LAZY);
	if (!dynamicLibrary) {
		fputs (dlerror(), stderr);
		exit(1);
	}
}

// Unload Daruma Framework of memory.
//
void unloadDarumaFramework()
{
	char* error = NULL;
	int descarregou = 0;

	if (dynamicLibrary)
	{
#ifdef WIN32
		descarregou = FreeLibrary((HMODULE) dynamicLibrary);
#else
		descarregou = dlclose(dynamicLibrary);
#endif
	}

	if (dynamicLibrary && !descarregou) {
#ifdef WIN32
		error = (char*) GetLastError();
#else
		error = dlerror();
#endif
		printf("Erro ao descarregar a DarumaFrameWork: %s\n", error);
	}

}

// @param nameFunction function name for load memory.
// @return pointer for function or NULL;
//
void* loadFunctionDarumaFramework(const char* nameFunction)
{
	void* function = NULL;
	char* error = NULL;

	if (NULL == dynamicLibrary)
	{
		loadDarumaFramework();
	}

#ifdef WIN32
	function = GetProcAddress((HMODULE) dynamicLibrary, nameFunction);
#else
	function = dlsym(dynamicLibrary, nameFunction);
#endif

	if (NULL == function)
	{
#ifdef WIN32
		error = (char*) GetLastError();
#else
		error = dlerror();
#endif
		printf("error ao carregar a funcao %s: %s\n", nameFunction, error);
	}

	return function;
}
