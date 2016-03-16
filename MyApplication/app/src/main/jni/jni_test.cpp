//
// Created by lang on 2016/3/14.
//

#include "com_lang_myapplication_TestJni.h"
#include "./utils/android_log.h"

/*
 * Class:     com_lang_myapplication_TestJni
 * Method:    logV
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_lang_myapplication_TestJni_logV
        (JNIEnv * env, jobject jObj){
    LOGE("log string from ndk.");
    return env->NewStringUTF("Hello From JNI!");
}

