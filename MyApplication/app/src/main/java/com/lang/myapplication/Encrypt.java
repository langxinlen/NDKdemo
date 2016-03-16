package com.lang.myapplication;

import android.util.Log;

/**
 * Desc: 加密
 * Author: llp
 * Create Time: 2016-03-16 17:23
 * Email: jacklulu29@gmail.com
 */
public class Encrypt {

    private static final String TAG = Encrypt.class.getSimpleName();
    public int age = 1;
    private String key = "123abc";

    static {
        System.loadLibrary("TestJni");
    }

    public native String encrypt(String word);

    public String getKey(){
        Log.e(TAG, " getKey: " + key);
        return key;
    }

    public int getAge() {
        Log.e(TAG, " getAge: " + age);
        return age;
    }

    public void setAge(int age) {
        this.age = age;
        Log.e(TAG, " setAge: " + age);
    }

    public static String getTag(double d1, double d2){
        Log.e(TAG, " getTag: " + TAG + " d1: " + d1 + " d2: " + d2);
        return TAG;
    }
}