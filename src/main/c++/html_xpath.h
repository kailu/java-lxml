#include <libxml/parser.h>
#include <libxml/xpath.h>

#include <libxml/HTMLparser.h>

#include <string>
#include <iostream>
#include <stack>
#include <vector>

#include <curl/curl.h>


size_t writeFN(void *ptr, size_t size, size_t nmemb, std::string* stream);

void downloadPage(const char* url, std::string& output);

xmlDocPtr parseHTML(const char* data, const int length);

xmlDocPtr parseXML(const char* data, const int length);

xmlDocPtr getdoc (char *docname);

xmlXPathObjectPtr getNodeSet (xmlDocPtr doc, const char *xpath);

void getTextInNode(xmlNodePtr node, std::string& output);

void evalXpathOnHtml(const std::string& data, const char* xpath, std::vector<std::string> &output);

void finshup();
