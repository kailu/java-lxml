
#ACLOCAL_AMFLAGS = -I m4


bin_PROGRAMS = test

test_SOURCES = test.cpp html_xpath.cpp

lib_LTLIBRARIES = libhtmlxpath.la

libhtmlxpath_la_SOURCES = html_xpath.cpp jni.cpp


#change the setting according your build enviorment
test_CPPFLAGS=-I/opt/local/include/libxml2/ -I/opt/local/include/ -I/Library/Java/JavaVirtualMachines/jdk1.7.0_45.jdk/Contents/Home/ -I/Library/Java/JavaVirtualMachines/jdk1.7.0_45.jdk/Contents/Home/include/darwin/

libhtmlxpath_la_CPPFLAGS=-I/opt/local/include/libxml2/ -I/opt/local/include/ -I/Library/Java/JavaVirtualMachines/jdk1.7.0_45.jdk/Contents/Home/include/ -I/Library/Java/JavaVirtualMachines/jdk1.7.0_45.jdk/Contents/Home/include/darwin/

