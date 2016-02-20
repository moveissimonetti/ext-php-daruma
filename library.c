#include "library.h"

static void* bibliotecaDinamica = NULL;

void carregarDarumaFramework(const char* local) {
    char* mensagemErro = NULL;

    if (!bibliotecaDinamica) {
        bibliotecaDinamica = dlopen(local, RTLD_NOW);
    }

    if (!bibliotecaDinamica) {
        php_error(E_ERROR, "%s em %s", dlerror(), local);
    }
}

void descarregarDarumaFramework() {
    char* mensagemErro = NULL;
    int descarregada = 0;

    if (bibliotecaDinamica != NULL) {
        descarregada = DL_UNLOAD(bibliotecaDinamica);
    }

    if (descarregada == 0) {
        php_error(E_ERROR, "%s", dlerror());
    }
}


void* carregarFuncaoDarumaFramework(char* nomeFuncao) {
    char* mensagemErro = NULL;
    void* funcao = NULL;

    funcao = DL_FETCH_SYMBOL(bibliotecaDinamica, nomeFuncao);

    if (funcao == NULL) {
        php_error(E_ERROR, "%s", dlerror());
    }

    return funcao;
}
