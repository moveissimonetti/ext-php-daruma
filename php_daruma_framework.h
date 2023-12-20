#ifndef PHP_DARUMA_FRAMEWORK_H
#define PHP_DARUMA_FRAMEWORK_H

extern zend_module_entry daruma_framework_module_entry;
#define phpext_daruma_framework_ptr &daruma_framework_module_entry

#define PHP_DARUMA_FRAMEWORK_VERSION "1.0.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_DARUMA_FRAMEWORK_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_DARUMA_FRAMEWORK_API __attribute__ ((visibility("default")))
#else
#	define PHP_DARUMA_FRAMEWORK_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#ifdef ZTS
#define DARUMA_FRAMEWORK_G(v) TSRMG(daruma_framework_globals_id, zend_daruma_framework_globals *, v)
#else
#define DARUMA_FRAMEWORK_G(v) (daruma_framework_globals.v)
#endif

#include <stdio.h>
#include <stdlib.h>

PHP_FUNCTION(eBuscarPortaVelocidade_DUAL_DarumaFramework);
PHP_FUNCTION(iImprimirTexto_DUAL_DarumaFramework);
PHP_FUNCTION(eDefinirProduto_Daruma);
PHP_FUNCTION(regAlterarValor_Daruma);
PHP_FUNCTION(iCFImprimir_NFCe_Daruma);

#endif	/* PHP_DARUMA_FRAMEWORK_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
