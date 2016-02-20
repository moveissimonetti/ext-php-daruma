#ifndef PHP_5_6_18_DARUMA_FUNCTIONS_H
#define PHP_5_6_18_DARUMA_FUNCTIONS_H

#include "library.h"

#ifndef WINAPI
#	define WINAPI
#endif

#define RET_ERRO_ZEND_BIND
#define ZEND_PARAM		INTERNAL_FUNCTION_PARAMETERS
#define ZEND_PARAM_PASS INTERNAL_FUNCTION_PARAM_PASSTHRU

#define CARREGA_FUNCAO(variavel, tipo, nome) \
        if(variavel == NULL) { \
                variavel = (tipo) carregarFuncaoDarumaFramework(nome); \
        }

typedef int (WINAPI* eBuscarPortaVelocidade_DUAL_DarumaFramework_type)();
typedef int (WINAPI* iCFImprimir_NFCe_Daruma_type)(char* pszPathXMLVenda, char* pszPathRetornoWS, char* pszLinkQrCode, int iNumColunas, int iTipoNF);
typedef int (WINAPI* regAlterarValor_Daruma_type)(char* pszPathChave, char* pszValor);
typedef int (WINAPI* eDefinirProduto_Daruma_type)(char* pszProduto);
typedef int (WINAPI* iImprimirTexto_DUAL_DarumaFramework_type)(char* pszString, int iTam);
typedef int (WINAPI* iEnviarBMP_DUAL_DarumaFramework_type)(char* pszArqOrigem);
typedef int (WINAPI* iConfigurarGuilhotina_DUAL_DarumaFramework_type)(int iHabilitar, int iQtdeLinha);
typedef int (WINAPI* rStatusGuilhotina_DUAL_DarumaFramework_type)();
typedef int (WINAPI* confProgramarAvancoPapel_ECF_Daruma_type)(char* pszSepEntreLinhas, char* pszSepEntreDoc, char* pszLinhasGuilhotina, char* pszGuilhotina, char* pszImpClicheAntecipada);
typedef int (WINAPI* eAcionarGuilhotina_ECF_Daruma_type)(char* pszTipoCorte);

eBuscarPortaVelocidade_DUAL_DarumaFramework_type EBuscarPortaVelocidade_DUAL_DarumaFramework;
iCFImprimir_NFCe_Daruma_type ICFImprimir_NFCe_Daruma;
regAlterarValor_Daruma_type RegAlterarValor_Daruma;
eDefinirProduto_Daruma_type EDefinirProduto_Daruma;
iImprimirTexto_DUAL_DarumaFramework_type IImprimirTexto_DUAL_DarumaFramework;
iEnviarBMP_DUAL_DarumaFramework_type IEnviarBMP_DUAL_DarumaFramework;
iConfigurarGuilhotina_DUAL_DarumaFramework_type IConfigurarGuilhotina_DUAL_DarumaFramework;
rStatusGuilhotina_DUAL_DarumaFramework_type RStatusGuilhotina_DUAL_DarumaFramework;
confProgramarAvancoPapel_ECF_Daruma_type ConfProgramarAvancoPapel_ECF_Daruma;
eAcionarGuilhotina_ECF_Daruma_type EAcionarGuilhotina_ECF_Daruma;
#endif //PHP_5_6_18_DARUMA_FUNCTIONS_H
