java-lxml
=========

Java XPath evaluator using libxml2


How to build?
   - Go to src/main/c++, build libhtmlxpath library first. [make sure you have automake tool and libtool installed, change configure.ac according your envirment setting.(Header file location, that was based on my computer setting)]
      - autoconf
      - automake
      - ./configure
      - make all

      You will find the library under: src/main/c++/.libs/libhtmlxpath.dylib[so]. [ For mac/linux accordingly]
   - Another way to build c++ library with simple command line:
      - On mac: 
         g++ -I. -I/opt/local/include/libxml2/ -dynamiclib -o libhtmlxpath.dylib ./html_xpath.cpp -lxml2 -lcurl -v

How to Use?
      refer to the test cases in Java code.
      
      
Todo items:
   - performance test;
   - deploy package for linux;
