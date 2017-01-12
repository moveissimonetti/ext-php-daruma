/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_daruma_framework.h"
#include "library.h"
#include "daruma_functions.h"

/* True global resources - no need for thread safety here */
static int le_daruma_framework;

/* {{{ PHP_INI
 */
PHP_INI_BEGIN()
    PHP_INI_ENTRY("darumaframework.path", "/opt/DarumaFramework/libDarumaFramework.so", PHP_INI_ALL, NULL)
PHP_INI_END()

PHP_FUNCTION(eBuscarPortaVelocidade_DUAL_DarumaFramework)
{
    if(zend_parse_parameters_none() == FAILURE) {
        return RET_ERRO_ZEND_BIND;
    }
       
    RETURN_LONG(eBuscarPortaVelocidade_DUAL_DarumaFramework());
}

PHP_FUNCTION(iImprimirTexto_DUAL_DarumaFramework)
{
    char* texto;
    int tam;
    int stringLen = 0;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sl", &texto, &stringLen, &tam) == FAILURE) {
        return RET_ERRO_ZEND_BIND;
    }
    
    RETURN_LONG(iImprimirTexto_DUAL_DarumaFramework(texto, tam));
}

PHP_FUNCTION(eDefinirProduto_Daruma)
{
    char* produto;
    int produtoLen = 0;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &produto, &produtoLen) == FAILURE) {
        return RET_ERRO_ZEND_BIND;
    }
    
    RETURN_LONG(eDefinirProduto_Daruma(produto));
}

PHP_FUNCTION(regAlterarValor_Daruma)
{
    char* pathChave;
    char* valor;   
    int pathChaveLen = 0;
    int valorLen = 0;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &pathChave, &pathChaveLen, &valor, &valorLen) == FAILURE) {
        return RET_ERRO_ZEND_BIND;
    }
    
    RETURN_LONG(regAlterarValor_Daruma(pathChave, valor));
}

PHP_FUNCTION(iCFImprimir_NFCe_Daruma)
{
    char* pathXMLVenda;
    char* pathRetornoWS;
    char* linkQrCode;
    
    int numColunas = 0;
    int tipoNF = 0;
    int pathXMLVendaLen = 0;
    int pathRetornoWSLen = 0;
    int linkQrCodeLen = 0;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sssll", &pathXMLVenda, &pathXMLVendaLen, &pathRetornoWS, &pathRetornoWSLen, &linkQrCode, &linkQrCodeLen, &numColunas, &tipoNF) == FAILURE) {
        return RET_ERRO_ZEND_BIND;
    }
    
    RETURN_LONG(iCFImprimir_NFCe_Daruma(pathXMLVenda, pathRetornoWS, linkQrCode, numColunas, tipoNF));
}


PHP_MINIT_FUNCTION(daruma_framework)
{
	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(daruma_framework)
{
    descarregarDarumaFramework();
	return SUCCESS;
}

PHP_RINIT_FUNCTION(daruma_framework)
{
	return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(daruma_framework)
{
	return SUCCESS;
}

PHP_MINFO_FUNCTION(daruma_framework)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "daruma_framework support", "enabled");
    php_info_print_table_row(2, "DarumaFramework carregada em",  INI_ORIG_STR("darumaframework.path"));
    php_info_print_table_row(2, "eBuscarPortaVelocidade_DUAL_DarumaFramework", "Sim");
    php_info_print_table_row(2, "iImprimirTexto_DUAL_DarumaFramework", "Sim");
    php_info_print_table_row(2, "iCFImprimir_NFCe_Daruma", "Sim");
    php_info_print_table_row(2, "eDefinirProduto_Daruma", "Sim");
	php_info_print_table_end();
}

const zend_function_entry daruma_framework_functions[] = {
    PHP_FE(eBuscarPortaVelocidade_DUAL_DarumaFramework, NULL)
    PHP_FE(iImprimirTexto_DUAL_DarumaFramework, NULL)
    PHP_FE(eDefinirProduto_Daruma, NULL)
    PHP_FE(regAlterarValor_Daruma, NULL)
    PHP_FE(iCFImprimir_NFCe_Daruma, NULL)
	PHP_FE_END	
};


zend_module_entry daruma_framework_module_entry = {
	STANDARD_MODULE_HEADER,
	"daruma_framework",
	daruma_framework_functions,
	PHP_MINIT(daruma_framework),
	PHP_MSHUTDOWN(daruma_framework),
	PHP_RINIT(daruma_framework),		
	PHP_RSHUTDOWN(daruma_framework),	
	PHP_MINFO(daruma_framework),
	PHP_DARUMA_FRAMEWORK_VERSION,
	STANDARD_MODULE_PROPERTIES
};


#ifdef COMPILE_DL_DARUMA_FRAMEWORK
ZEND_GET_MODULE(daruma_framework)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
