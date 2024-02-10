#include "daruma_functions.h"

int eBuscarPortaVelocidade_DUAL_DarumaFramework(){
    return ((int (*) (void)) loadFunctionDarumaFramework("eBuscarPortaVelocidade_DUAL_DarumaFramework")) ();
}

int iCFImprimir_NFCe_Daruma(char* pszPathXMLVenda, char* pszPathRetornoWS, char* pszLinkQrCode, int iNumColunas, int iTipoNF){
    return ((int (*) (char*, char*, char*, int, int)) loadFunctionDarumaFramework("iCFImprimir_NFCe_Daruma"))(pszPathXMLVenda, pszPathRetornoWS, pszLinkQrCode, iNumColunas, iTipoNF);
}

int regAlterarValor_Daruma(char* pszPathChave, char* pszValor){
    return ((int (*) (char*, char*)) loadFunctionDarumaFramework("regAlterarValor_Daruma")) (pszPathChave, pszValor);
}

int eDefinirProduto_Daruma(char* pszProduto) {
    return ((int (*) (char*)) loadFunctionDarumaFramework("eDefinirProduto_Daruma")) (pszProduto);
}

int iImprimirTexto_DUAL_DarumaFramework(char* pszString, int iTam) {
    return ((int (*) (char*, int)) loadFunctionDarumaFramework("iImprimirTexto_DUAL_DarumaFramework")) (pszString, iTam);
}

int eVerificarVersaoDLL_Daruma(char* pszRetr) {
    return ((int (*) (char*)) loadFunctionDarumaFramework("eVerificarVersaoDLL_Daruma")) (pszRetr);
}

int isDarumaFrameworkCarregada() {
    return isLoaded();
}