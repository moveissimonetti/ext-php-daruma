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

ZEND_BEGIN_ARG_INFO(arginfo_eBuscarPortaVelocidade_DUAL_DarumaFramework, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(eBuscarPortaVelocidade_DUAL_DarumaFramework)
{
    if(zend_parse_parameters_none() != SUCCESS) {
        return RET_ERRO_ZEND_BIND;
    }

    RETURN_LONG(eBuscarPortaVelocidade_DUAL_DarumaFramework());
}

ZEND_BEGIN_ARG_INFO_EX(arginfo_iImprimirTexto_DUAL_DarumaFramework, 0, 0, 2)
    ZEND_ARG_INFO(0, texto)
    ZEND_ARG_INFO(0, tam)
ZEND_END_ARG_INFO()

PHP_FUNCTION(iImprimirTexto_DUAL_DarumaFramework)
{
    zend_string *texto;
    zend_long tam;

    if(zend_parse_parameters(ZEND_NUM_ARGS(), "Sl", &texto, &tam) != SUCCESS) {
        return RET_ERRO_ZEND_BIND;
    }

    RETURN_LONG(
        iImprimirTexto_DUAL_DarumaFramework(
            ZSTR_VAL(texto),
            (int) tam
    ));
}

ZEND_BEGIN_ARG_INFO_EX(arginfo_eDefinirProduto_Daruma, 0, 0, 1)
    ZEND_ARG_INFO(0, produto)
ZEND_END_ARG_INFO()

PHP_FUNCTION(eDefinirProduto_Daruma)
{
    zend_string *produto;

    if(zend_parse_parameters(ZEND_NUM_ARGS(), "S", &produto) != SUCCESS) {
        return RET_ERRO_ZEND_BIND;
    }

    RETURN_LONG(
        eDefinirProduto_Daruma(
            ZSTR_VAL(produto)
        )
    );
}

ZEND_BEGIN_ARG_INFO_EX(arginfo_regAlterarValor_Daruma, 0, 0, 2)
    ZEND_ARG_INFO(0, pathChave)
    ZEND_ARG_INFO(0, valor)
ZEND_END_ARG_INFO()

PHP_FUNCTION(regAlterarValor_Daruma)
{
    zend_string *pathChave;
    zend_string *valor;

    if(zend_parse_parameters(ZEND_NUM_ARGS(), "SS", &pathChave, &valor) != SUCCESS) {
        return RET_ERRO_ZEND_BIND;
    }

    RETURN_LONG(regAlterarValor_Daruma(
        ZSTR_VAL(pathChave),
        ZSTR_VAL(valor)
    ));
}

ZEND_BEGIN_ARG_INFO_EX(arginfo_iCFImprimir_NFCe_Daruma, 0, 0, 5)
    ZEND_ARG_INFO(0, pathXMLVenda)
    ZEND_ARG_INFO(0, pathRetornoWS)
    ZEND_ARG_INFO(0, linkQrCode)
    ZEND_ARG_INFO(0, numColunas)
    ZEND_ARG_INFO(0, tipoNF)
ZEND_END_ARG_INFO()

PHP_FUNCTION(iCFImprimir_NFCe_Daruma)
{
    zend_string *pathXMLVenda;
    zend_string *pathRetornoWS;
    zend_string *linkQrCode;
    zend_long numColunas = 0;
    zend_long tipoNF = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "SSSll", &pathXMLVenda, &pathRetornoWS, &linkQrCode, &numColunas, &tipoNF) == FAILURE) {
        return RET_ERRO_ZEND_BIND;
    }

    RETURN_LONG(iCFImprimir_NFCe_Daruma(
        ZSTR_VAL(pathXMLVenda),
        ZSTR_VAL(pathRetornoWS),
        ZSTR_VAL(linkQrCode),
        (int)numColunas,
        (int)tipoNF
    ));
}


PHP_MINIT_FUNCTION(daruma_framework)
{
	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(daruma_framework)
{
	return SUCCESS;
}

PHP_RINIT_FUNCTION(daruma_framework)
{
	return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(daruma_framework)
{
	unloadDarumaFramework();
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
    PHP_FE(eBuscarPortaVelocidade_DUAL_DarumaFramework, arginfo_eBuscarPortaVelocidade_DUAL_DarumaFramework)
    PHP_FE(iImprimirTexto_DUAL_DarumaFramework, arginfo_iImprimirTexto_DUAL_DarumaFramework)
    PHP_FE(eDefinirProduto_Daruma, arginfo_eDefinirProduto_Daruma)
    PHP_FE(regAlterarValor_Daruma, arginfo_regAlterarValor_Daruma)
    PHP_FE(iCFImprimir_NFCe_Daruma, arginfo_iCFImprimir_NFCe_Daruma)
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
