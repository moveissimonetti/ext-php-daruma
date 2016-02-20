#include "daruma_functions.h"
#include "php_daruma_framework.h"

#define CARREGA_FUNCAO(variavel, tipo, nome) \
        if(variavel == NULL) { \
                variavel = (tipo) carregarFuncaoDarumaFramework(nome); \
        }

int eBuscarPortaVelocidade_DUAL_DarumaFramework(ZEND_PARAM){
    
    CARREGA_FUNCAO(EBuscarPortaVelocidade_DUAL_DarumaFramework, eBuscarPortaVelocidade_DUAL_DarumaFramework_type, "eBuscarPortaVelocidade_DUAL_DarumaFramework");

    return EBuscarPortaVelocidade_DUAL_DarumaFramework();
   
}


int iCFImprimir_NFCe_Daruma(char* pszPathXMLVenda, char* pszPathRetornoWS, char* pszLinkQrCode, int iNumColunas, int iTipoNF, ZEND_PARAM){
    
    CARREGA_FUNCAO(ICFImprimir_NFCe_Daruma, iCFImprimir_NFCe_Daruma_type, "iCFImprimir_NFCe_Daruma");

    return ICFImprimir_NFCe_Daruma(pszPathXMLVenda, pszPathRetornoWS, pszLinkQrCode, iNumColunas, iTipoNF);
}

int regAlterarValor_Daruma(char* pszPathChave, char* pszValor, ZEND_PARAM){
    
    CARREGA_FUNCAO(RegAlterarValor_Daruma, regAlterarValor_Daruma_type, "regAlterarValor_Daruma");

    return RegAlterarValor_Daruma(pszPathChave, pszValor);
}

int eDefinirProduto_Daruma(char* pszProduto, ZEND_PARAM){
    
    CARREGA_FUNCAO(EDefinirProduto_Daruma, eDefinirProduto_Daruma_type, "eDefinirProduto_Daruma");

    return EDefinirProduto_Daruma(pszProduto);
}

int iImprimirTexto_DUAL_DarumaFramework(char* pszString, int iTam, ZEND_PARAM){
    
    CARREGA_FUNCAO(IImprimirTexto_DUAL_DarumaFramework, iImprimirTexto_DUAL_DarumaFramework_type, "iImprimirTexto_DUAL_DarumaFramework");

    return IImprimirTexto_DUAL_DarumaFramework(pszString, iTam);
}

int iEnviarBMP_DUAL_DarumaFramework(char* pszArqOrigem, ZEND_PARAM){
	
	CARREGA_FUNCAO(IEnviarBMP_DUAL_DarumaFramework, iEnviarBMP_DUAL_DarumaFramework_type, "iEnviarBMP_DUAL_DarumaFramework");

	return IEnviarBMP_DUAL_DarumaFramework(pszArqOrigem);
}

int iConfigurarGuilhotina_DUAL_DarumaFramework(int iHabilitar, int iQtdeLinha, ZEND_PARAM){
    
	CARREGA_FUNCAO(IConfigurarGuilhotina_DUAL_DarumaFramework, iConfigurarGuilhotina_DUAL_DarumaFramework_type, "iConfigurarGuilhotina_DUAL_DarumaFramework");

	return IConfigurarGuilhotina_DUAL_DarumaFramework(iHabilitar, iQtdeLinha);
}

int rStatusGuilhotina_DUAL_DarumaFramework(ZEND_PARAM){
    
	CARREGA_FUNCAO(RStatusGuilhotina_DUAL_DarumaFramework, rStatusGuilhotina_DUAL_DarumaFramework_type, "rStatusGuilhotina_DUAL_DarumaFramework");

	return RStatusGuilhotina_DUAL_DarumaFramework();
}

int confProgramarAvancoPapel_ECF_Daruma(char* pszSepEntreLinhas, char* pszSepEntreDoc, char* pszLinhasGuilhotina, char* pszGuilhotina, char* pszImpClicheAntecipada, ZEND_PARAM){
	
	CARREGA_FUNCAO(ConfProgramarAvancoPapel_ECF_Daruma, confProgramarAvancoPapel_ECF_Daruma_type, "confProgramarAvancoPapel_ECF_Daruma");

	return ConfProgramarAvancoPapel_ECF_Daruma(pszSepEntreLinhas, pszSepEntreDoc, pszLinhasGuilhotina, pszGuilhotina, pszImpClicheAntecipada);
}

int eAcionarGuilhotina_ECF_Daruma(char* pszTipoCorte, ZEND_PARAM){
    
	CARREGA_FUNCAO(EAcionarGuilhotina_ECF_Daruma, eAcionarGuilhotina_ECF_Daruma_type, "eAcionarGuilhotina_ECF_Daruma");

	return EAcionarGuilhotina_ECF_Daruma(pszTipoCorte);
}