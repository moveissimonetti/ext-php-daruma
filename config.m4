dnl $Id$
dnl config.m4 for extension daruma_framework


PHP_ARG_ENABLE(daruma_framework, whether to enable daruma_framework support
[  --enable-daruma_framework           Enable daruma_framework support])

if test "$PHP_DARUMA_FRAMEWORK" != "no"; then
  PHP_NEW_EXTENSION(daruma_framework, daruma_framework.c, $ext_shared)
fi
