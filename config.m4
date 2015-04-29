dnl $Id$
dnl config.m4 for extension microframe

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(microframe, for microframe support,
dnl Make sure that the comment is aligned:
dnl [  --with-microframe             Include microframe support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(microframe, whether to enable microframe support,
[  --enable-microframe           Enable microframe support])

if test "$PHP_MICROFRAME" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-microframe -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/microframe.h"  # you most likely want to change this
  dnl if test -r $PHP_MICROFRAME/$SEARCH_FOR; then # path given as parameter
  dnl   MICROFRAME_DIR=$PHP_MICROFRAME
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for microframe files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       MICROFRAME_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$MICROFRAME_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the microframe distribution])
  dnl fi

  dnl # --with-microframe -> add include path
  dnl PHP_ADD_INCLUDE($MICROFRAME_DIR/include)

  dnl # --with-microframe -> check for lib and symbol presence
  dnl LIBNAME=microframe # you may want to change this
  dnl LIBSYMBOL=microframe # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $MICROFRAME_DIR/lib, MICROFRAME_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_MICROFRAMELIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong microframe lib version or lib not found])
  dnl ],[
  dnl   -L$MICROFRAME_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(MICROFRAME_SHARED_LIBADD)

  PHP_NEW_EXTENSION(microframe, microframe.c, $ext_shared)
fi
