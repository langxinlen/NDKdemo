//
// Created by lang on 2016/3/16.
//

#include "com_lang_myapplication_Encrypt.h"
#include "./utils/android_log.h"
#include <stdlib.h>

char *jstringTostr(JNIEnv *env, jstring jstr) {
    char *pStr = NULL;

    jclass jstrObj = env->FindClass("java/lang/String");
    jstring encode = env->NewStringUTF("utf-8");
    jmethodID methodId = env->GetMethodID(jstrObj, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray byteArray = (jbyteArray) env->CallObjectMethod(jstr, methodId, encode);
    jsize strLen = env->GetArrayLength(byteArray);
    jbyte *jBuf = env->GetByteArrayElements(byteArray, JNI_FALSE);

    if (jBuf > 0) {
        pStr = (char *) malloc(strLen + 1);

        if (!pStr) {
            return NULL;
        }

        memcpy(pStr, jBuf, strLen);

        pStr[strLen] = 0;
    }

    env->ReleaseByteArrayElements(byteArray, jBuf, 0);

    return pStr;
}

//C字符串转java字符串
jstring strToJstring(JNIEnv *env, const char *pStr) {
    int strLen = strlen(pStr);
    jclass jstrObj = env->FindClass("java/lang/String");
    jmethodID methodId = env->GetMethodID(jstrObj, "<init>", "([BLjava/lang/String;)V");
    jbyteArray byteArray = env->NewByteArray(strLen);
    jstring encode = env->NewStringUTF("utf-8");

    env->SetByteArrayRegion(byteArray, 0, strLen, (jbyte *) pStr);

    return (jstring) env->NewObject(jstrObj, methodId, byteArray, encode);
}



/*
 * Class:     com_lang_myapplication_Encrypt
 * Method:    encrypt
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_lang_myapplication_Encrypt_encrypt
        (JNIEnv *env, jobject jObj, jstring word) {
    char * cstr = jstringTostr(env, word);
    LOGE("Encrypt word: %s", cstr);

    // 获取class对象
    jclass clEncrypt = env->GetObjectClass(jObj);

    // 获取属性
    jfieldID fIDAge = env->GetFieldID(clEncrypt, "age", "I");
    jint fAge = env->GetIntField(jObj, fIDAge);

    // 调用getAge方法，返回java int类型
    jmethodID mtGetAge = env->GetMethodID(clEncrypt, "getAge", "()I");
    jint age = env->CallIntMethod(jObj, mtGetAge);

    // 调用setAge方法，设置数值为 2 * fAge
    jmethodID mtSetAge = env->GetMethodID(clEncrypt, "setAge", "(I)V");
    env->CallVoidMethod(jObj, mtSetAge, 2 * fAge);

    // 调用getKey方法，返回java String类型
    jmethodID  mtGetKey = env->GetMethodID(clEncrypt, "getKey", "()Ljava/lang/String;");
    jstring key = (jstring)env->CallObjectMethod(jObj, mtGetKey);

    char * keyChar = jstringTostr(env, key);
    LOGE("Encrypt key: %s", keyChar);

    char nstr[strlen(keyChar)+strlen(cstr)] = "";
    strcat(nstr, keyChar);
    LOGE("Encrypt word 1: %s", nstr);
    strcat(nstr, cstr);
    LOGE("Encrypt word 2: %s", nstr);

    // 调用静态方法getTag，返回java String类型
    jdouble d1 = 2;
    jdouble d2 = 4;
    jmethodID mtGetTag = env->GetStaticMethodID(clEncrypt, "getTag", "(DD)Ljava/lang/String;");
    jstring tag = (jstring) env->CallStaticObjectMethod(clEncrypt, mtGetTag, d1, d2);
    char * tagChar = jstringTostr(env, tag);
    LOGE("Encrypt tag: %s", tagChar);

    return env->NewStringUTF(nstr);
}


