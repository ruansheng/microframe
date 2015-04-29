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

#ifndef PHP_MICROFRAME_H
#define PHP_MICROFRAME_H

extern zend_module_entry microframe_module_entry;
#define phpext_microframe_ptr &microframe_module_entry

#define PHP_MICROFRAME_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_MICROFRAME_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_MICROFRAME_API __attribute__ ((visibility("default")))
#else
#	define PHP_MICROFRAME_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

/*声明函数 start*/
PHP_FUNCTION(micro_test);
/*声明函数 end*/

/*类方法声明 start*/
PHP_METHOD(myclass,__construct);
PHP_METHOD(myclass,setName);
PHP_METHOD(myclass,getName);
PHP_METHOD(myclass,__destruct);
/*类方法声明 end*/

PHP_MINIT_FUNCTION(microframe);
PHP_MSHUTDOWN_FUNCTION(microframe);
PHP_RINIT_FUNCTION(microframe);
PHP_RSHUTDOWN_FUNCTION(microframe);
PHP_MINFO_FUNCTION(microframe);




#ifdef ZTS
#define MICROFRAME_G(v) TSRMG(microframe_globals_id, zend_microframe_globals *, v)
#else
#define MICROFRAME_G(v) (microframe_globals.v)
#endif

#endif	/* PHP_MICROFRAME_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
