#include "library.h"

static void* bibliotecaDinamica = NULL;

void carregarDarumaFramework(const char* local) {

    if (NULL != bibliotecaDinamica) {
        return;
    }

    bibliotecaDinamica = DL_LOAD(local);

    if (!bibliotecaDinamica) {
        php_error(E_WARNING, "A biblioteca nao foi carregada: %s em %s", dlerror(), local);
    }
}

void descarregarDarumaFramework() {
    if (!bibliotecaDinamica) {
        return;
    }
    
    int descarregada = DL_UNLOAD(bibliotecaDinamica);
    

    if (descarregada == 0) {
        php_error(E_WARNING, "Aconteceu um erro ao descarregar a biblioteca: %d - %s. ", descarregada, dlerror());
    }
}

void* carregarFuncaoDarumaFramework(char* nomeFuncao) {

    carregarDarumaFramework("/opt/DarumaFramework/libDarumaFramework.so");

    if (!bibliotecaDinamica) {
        php_error(E_ERROR, "A biblioteca nao foi carregada.");
        return;
    }

    char* mensagemErro = NULL;
    void* funcao = NULL;

    funcao = DL_FETCH_SYMBOL(bibliotecaDinamica, nomeFuncao);

    if (funcao == NULL) {
        php_error(E_WARNING, "%s", dlerror());
    }

    return funcao;
}
