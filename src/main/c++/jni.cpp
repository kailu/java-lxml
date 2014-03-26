#include "jnih.h"


JNIEXPORT jobjectArray JNICALL Java_com_ireeed_XPathApplier_htmlEvalXPath(JNIEnv *env, jobject jobj, jstring page,jstring xpath){
    jboolean isCopy;
    const char *data = env->GetStringUTFChars(page,&isCopy);
    const char *xpathdata = env->GetStringUTFChars(xpath,&isCopy);
    if(data != NULL){
	std::string htmldata(data);

	std::vector<std::string> output;
	evalXpathOnHtml(htmldata,xpathdata,output);
	jobjectArray ret = (jobjectArray)env->NewObjectArray(output.size(),
							     env->FindClass("java/lang/String"),
							     env->NewStringUTF(""));

	for(int i = 0; i < output.size(); i++){
	    env->SetObjectArrayElement(ret,i,env->NewStringUTF(output[i].c_str()));
	}
	return ret;
    }

    env->ReleaseStringUTFChars(page,data);
    env->ReleaseStringUTFChars(xpath,xpathdata);

    return NULL;
}


JNIEXPORT jobjectArray JNICALL Java_com_ireeed_XPathApplier_htmlEvalXPaths(JNIEnv *env, jobject jobj, jstring page, jobjectArray xpaths){
    jboolean isCopy;
    const char *data = env->GetStringUTFChars(page,&isCopy);
    std::string datastr = std::string(data);
    xmlDocPtr doc = parseHTML(datastr.c_str(),datastr.length());
    xmlXPathObjectPtr result;
    xmlNodeSetPtr nodeset;
    std::vector<std::vector<std::string> > ret;

    jsize xpathNum = env->GetArrayLength(xpaths);


    if(doc){
	for(int index = 0; index < xpathNum; index++){

	    jstring string = (jstring)env->GetObjectArrayElement(xpaths,index);

	    const char* xpath = env->GetStringUTFChars(string, &isCopy);

	    std::vector<std::string> output;
	    if(xpath){
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
	    }
	    ret.push_back(output);

	}
    
	xmlFreeDoc(doc);
    }


    /*
      construct std::vector<std::vector<std::string> > back to java type(array of array)
      construct the final result in order according to the order of given xpaths
    */
    jclass stringArrayCls = env->FindClass("java/lang/Object");
    jobjectArray elemObj = env->NewObjectArray(0,env->FindClass("java/lang/String"),env->NewStringUTF(""));

    jobjectArray retVal = env->NewObjectArray(ret.size(),stringArrayCls,elemObj);
    for(int i = 0; i < ret.size(); i++){
	std::vector<std::string> &elem = ret[i];
	elemObj = env->NewObjectArray(elem.size(),env->FindClass("java/lang/String"),env->NewStringUTF(""));
	for(int j = 0; j < elem.size(); j++){
	    std::string &elemField = elem[j];
	    //create java string
	    env->SetObjectArrayElement(elemObj,j,env->NewStringUTF(elemField.c_str()));
	}
	env->SetObjectArrayElement(retVal,i,elemObj);
    }

    return retVal;  
}


JNIEXPORT jobjectArray JNICALL Java_com_ireeed_XPathApplier_xmlEvalXPaths(JNIEnv *env, jobject jobj, jstring page, jobjectArray xpaths){
    jboolean isCopy;
    const char *data = env->GetStringUTFChars(page,&isCopy);
    std::string datastr = std::string(data);
    xmlDocPtr doc = parseXML(datastr.c_str(),datastr.length());
    xmlXPathObjectPtr result;
    xmlNodeSetPtr nodeset;
    std::vector<std::vector<std::string> > ret;

    jsize xpathNum = env->GetArrayLength(xpaths);


    if(doc){
	for(int index = 0; index < xpathNum; index++){

	    jstring string = (jstring)env->GetObjectArrayElement(xpaths,index);

	    const char* xpath = env->GetStringUTFChars(string, &isCopy);

	    std::vector<std::string> output;
	    if(xpath){
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
	    }
	    ret.push_back(output);

	}
    
	xmlFreeDoc(doc);
    }


    /*
      construct std::vector<std::vector<std::string> > back to java type(array of array)
      construct the final result in order according to the order of given xpaths
    */
    jclass stringArrayCls = env->FindClass("java/lang/Object");
    jobjectArray elemObj = env->NewObjectArray(0,env->FindClass("java/lang/String"),env->NewStringUTF(""));

    jobjectArray retVal = env->NewObjectArray(ret.size(),stringArrayCls,elemObj);
    for(int i = 0; i < ret.size(); i++){
	std::vector<std::string> &elem = ret[i];
	elemObj = env->NewObjectArray(elem.size(),env->FindClass("java/lang/String"),env->NewStringUTF(""));
	for(int j = 0; j < elem.size(); j++){
	    std::string &elemField = elem[j];
	    //create java string
	    env->SetObjectArrayElement(elemObj,j,env->NewStringUTF(elemField.c_str()));
	}
	env->SetObjectArrayElement(retVal,i,elemObj);
    }

    return retVal;  
}
