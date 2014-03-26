#include "html_xpath.h"

int main(int argc, char **argv) {

    char *docname;
    xmlDocPtr doc;
    xmlChar *xpath = (xmlChar*) "//div[@id='I_content']/div[1]/h1";
    xpath = (xmlChar *)"//div[@id='I_nav']/div[1]/ul/li[2]/a/@href";
    xmlNodeSetPtr nodeset;
    xmlXPathObjectPtr result;
    int i;
    xmlChar *keyword;
	
    std::string page;
    downloadPage("http://www.cplusplus.com/reference/iostream/cout/",page);

    std::vector<std::string> output;
    evalXpathOnHtml(page,(const char*)xpath,output);
    for(std::vector<std::string>::const_iterator it = output.begin();
	it != output.end();it++){
	std::cout<<"record:" <<*it<<std::endl;
    }

    return (1);
}
