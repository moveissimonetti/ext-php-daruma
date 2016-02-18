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

/* True global resources - no need for thread safety here */
static int le_daruma_framework;

/* {{{ PHP_INI
 */
PHP_INI_BEGIN()
    PHP_INI_ENTRY("darumaframework.path", "/opt/DarumaFramework/libDarumaFramework.so", PHP_INI_ALL, NULL)
PHP_INI_END()
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(daruma_framework)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(daruma_framework)
{
    descarregarDarumaFramework();
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(daruma_framework)
{
    carregarDarumaFramework(INI_ORIG_STR("darumaframework.path"));
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(daruma_framework)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
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

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ daruma_framework_functions[]
 *
 * Every user visible function must have an entry in daruma_framework_functions[].
 */
const zend_function_entry daruma_framework_functions[] = {
	PHP_FE_END	/* Must be the last line in daruma_framework_functions[] */
};
/* }}} */

/* {{{ daruma_framework_module_entry
 */
zend_module_entry daruma_framework_module_entry = {
	STANDARD_MODULE_HEADER,
	"daruma_framework",
	daruma_framework_functions,
	PHP_MINIT(daruma_framework),
	PHP_MSHUTDOWN(daruma_framework),
	PHP_RINIT(daruma_framework),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(daruma_framework),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(daruma_framework),
	PHP_DARUMA_FRAMEWORK_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

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
