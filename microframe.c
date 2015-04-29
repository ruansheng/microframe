/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2014 The PHP Group                                |
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
#include "php_microframe.h"



static int le_microframe;

const zend_function_entry microframe_functions[] = {
	PHP_FE(micro_test,NULL)
	PHP_FE_END	/* Must be the last line in microframe_functions[] */
};


zend_module_entry microframe_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"microframe",
	microframe_functions,
	PHP_MINIT(microframe),
	PHP_MSHUTDOWN(microframe),
	PHP_RINIT(microframe),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(microframe),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(microframe),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_MICROFRAME_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};


#ifdef COMPILE_DL_MICROFRAME
ZEND_GET_MODULE(microframe)
#endif

/*定义函数 start*/
PHP_FUNCTION(micro_test)
{
	php_printf("hello world !\n");
}
/*定义函数 end*/

PHP_MINIT_FUNCTION(microframe)
{
	return SUCCESS;
}


PHP_MSHUTDOWN_FUNCTION(microframe)
{
	return SUCCESS;
}



PHP_RINIT_FUNCTION(microframe)
{
	return SUCCESS;
}



PHP_RSHUTDOWN_FUNCTION(microframe)
{
	return SUCCESS;
}


PHP_MINFO_FUNCTION(microframe)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "microframe support", "enabled");
	php_info_print_table_end();

}





