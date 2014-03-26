#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([java-lxml], [0.1], [lukai1984@gmail.com])


AC_CONFIG_SRCDIR([test.cpp])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE
#AM_INIT_AUTOMAKE ([ foreign])

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.
AC_CHECK_LIB([xml2],[xmlXPathFreeObject],[],[
	echo "libxml2 doesn't founded!"
	exit -1
])

AC_CHECK_LIB([curl],[curl_easy_init],[],[
	echo "libcurl doesn't founded!"
	exit -1
])


LT_INIT

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.


#AC_CONFIG_FILES(Makefile)

AC_OUTPUT(Makefile)
