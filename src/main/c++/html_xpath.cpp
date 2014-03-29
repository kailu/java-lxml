#include "html_xpath.h"


size_t writeFN(void *ptr, size_t size, size_t nmemb, std::string* stream){
    //create new string 
    std::string new_data((const char*)ptr,size*nmemb);
    //append the new data to old string
    stream->append(new_data);

    return size*nmemb;
}

void downloadPage(const char* url, std::string& output){
    CURL *curl = curl_easy_init();
    CURLcode res;
    if(curl){
	curl_easy_setopt(curl,CURLOPT_URL,url);
	curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,writeFN);
	curl_easy_setopt(curl,CURLOPT_WRITEDATA, &output);
	res = curl_easy_perform(curl);

	curl_easy_cleanup(curl);
    }
}


xmlDocPtr parseHTML(const char* data, const int length){
    htmlParserCtxtPtr parser = htmlCreatePushParserCtxt(NULL,NULL,NULL,0,NULL,XML_CHAR_ENCODING_UTF8);
    htmlCtxtUseOptions(parser, HTML_PARSE_NOBLANKS | HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING | HTML_PARSE_NONET|HTML_PARSE_IGNORE_ENC);
    htmlParseChunk(parser, data, length, 0);
    xmlDocPtr ret = parser->myDoc;
    htmlFreeParserCtxt(parser);
    return ret;
}


xmlDocPtr parseXML(const char* data, const int length){
    std::string xmlData(data,length);
    return xmlParseDoc((const xmlChar *)xmlData.c_str());
}


xmlDocPtr getdoc (char *docname) {
    xmlDocPtr doc;
    doc = xmlParseFile(docname);
	
    if (doc == NULL ) {
	fprintf(stderr,"Document not parsed successfully. \n");
	return NULL;
    }

    return doc;
}

xmlXPathObjectPtr getNodeSet (xmlDocPtr doc, const char *xpath){
	
    xmlXPathContextPtr context;
    xmlXPathObjectPtr result;

    context = xmlXPathNewContext(doc);
    if (context == NULL) {
	//	printf("Error in xmlXPathNewContext\n");
	return NULL;
    }
    result = xmlXPathEvalExpression((xmlChar *)xpath, context);
    xmlXPathFreeContext(context);
    if (result == NULL) {
	//	printf("Error in xmlXPathEvalExpression\n");
	return NULL;
    }
    if(xmlXPathNodeSetIsEmpty(result->nodesetval)){
	xmlXPathFreeObject(result);
	//	printf("No result\n");
	return NULL;
    }
    return result;
}

/*
  purpose of this function is try to gether text information from a html node or attribute of a node
*/
void getTextInNode(xmlNodePtr node, std::string& output){
    std::stack<xmlNodePtr> st;
    st.push(node);

    while(st.size() > 0){
	node = st.top(), st.pop();

	if(node->type == XML_ELEMENT_NODE){
	    if(node->last){
		xmlNodePtr tmpNode = node->last;
		st.push(tmpNode);
		while(tmpNode != node->children){
		    tmpNode = tmpNode->prev;
		    st.push(tmpNode);
		}
	    }
	}

	if(node->type == XML_TEXT_NODE){
	    //concate text into final output
	    output += (const char*)node->content;
	}

	if(node->type == XML_CDATA_SECTION_NODE){
	    output += (const char*)node->content;
	}

	if(node->type == XML_ATTRIBUTE_NODE){
	    xmlAttr * attrNode = (xmlAttr *)node;
	    if(node->children)
		output += (const char*)node->children->content;
	}

	//	    std::cout<<"type:"<<node->type<<"\t"<<node->name<<std::endl;
    }
}


void evalXpathOnHtml(const std::string& data, const char* xpath, std::vector<std::string> &output){
    xmlDocPtr doc = parseHTML(data.c_str(),data.length());
    xmlXPathObjectPtr result;
    xmlNodeSetPtr nodeset;

    if(doc){
	result = getNodeSet(doc,xpath);
	if(result){
	    nodeset = result->nodesetval;
	    for(int i = 0; i < nodeset->nodeNr; i++){
		xmlNodePtr nodePtr = nodeset->nodeTab[i];
		std::string record;
		getTextInNode(nodePtr,record);
		output.push_back(record);
	    }
	    xmlXPathFreeObject(result);
	}
	xmlFreeDoc(doc);
    }

}

void finshup(){
    xmlCleanupParser();
}
