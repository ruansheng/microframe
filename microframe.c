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
	PHP_ME(myclass,__construct,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(myclass,setName,NULL,ZEND_ACC_PUBLIC)
	PHP_ME(myclass,getName,NULL,ZEND_ACC_PUBLIC)
    PHP_ME(myclass,__destruct,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
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

/*注册类方法 start*/
zend_class_entry *myclass_ce;
PHP_MINIT_FUNCTION(microframe)
{
	//注册类
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce,"myclass",microframe_functions);  //使用INIT_CLASS_ENTRY宏初始化类，第二个参数指定类名，第三个参数是函数表
	myclass_ce=zend_register_internal_class(&ce TSRMLS_CC);

	//定义属性
	 zend_declare_class_constant_stringl(myclass_ce,ZEND_STRL("WEL"),ZEND_STRL("welcome\n") TSRMLS_CC);
	 zend_declare_class_constant_stringl(myclass_ce,ZEND_STRL("BYE"),ZEND_STRL("\nbye bye") TSRMLS_CC);
	 zend_declare_property_null(myclass_ce,ZEND_STRL("name"),ZEND_ACC_PRIVATE TSRMLS_CC);

	 return SUCCESS;
}

PHP_METHOD(myclass,__construct)
{
	zval **wel;
	zend_class_entry *ce;
	ce=Z_OBJCE_P(getThis());
	zend_hash_find(&ce->constants_table,ZEND_STRS("WEL"), (void **)&wel);
	php_printf("%s",Z_STRVAL_PP(wel));
}

PHP_METHOD(myclass,setName)
{
	zend_class_entry *ce;
	ce=Z_OBJCE_P(getThis());
	char *name;
	int name_len;
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &name_len) == FAILURE){
		WRONG_PARAM_COUNT
	}
	zend_update_property_stringl(ce,getThis(),ZEND_STRL("name"),name,name_len TSRMLS_CC);
	RETURN_TRUE;
}

PHP_METHOD(myclass,getName)
{
	zval *name;
	char *str;
	zend_class_entry *ce;
	ce=Z_OBJCE_P(getThis());
	name=zend_read_property(ce,getThis(),ZEND_STRL("name"),0 TSRMLS_CC);
	str=Z_STRVAL_P(name);
	RETURN_STRINGL(str,Z_STRLEN_P(name),1);
}

PHP_METHOD(myclass,__destruct)
{
	zval **bye;
	zend_class_entry *ce;
	ce=Z_OBJCE_P(getThis());
	zend_hash_find(&ce->constants_table,ZEND_STRS("BYE"),(void **)&bye);
	php_printf("%s",Z_STRVAL_PP(bye));
}

/*注册类方法 end*/

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





