#include "jni.h"
#include "html_xpath.h"

#ifdef __cplusplus
extern "C"{
#endif

    JNIEXPORT jobjectArray JNICALL Java_com_ireeed_XPathApplier_htmlEvalXPath(JNIEnv *env, jobject jobj, jstring page,jstring xpath);

    JNIEXPORT jobjectArray JNICALL Java_com_ireeed_XPathApplier_htmlEvalXPaths(JNIEnv *env, jobject jobj, jstring page, jobjectArray xpaths);

    JNIEXPORT jobjectArray JNICALL Java_com_ireeed_XPathApplier_xmlEvalXPaths(JNIEnv *env, jobject jobj, jstring page, jobjectArray xpaths);
#ifdef __cplusplus
}
#endif
