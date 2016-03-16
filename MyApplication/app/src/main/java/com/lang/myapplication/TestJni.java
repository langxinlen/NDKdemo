package com.lang.myapplication;

/**
 * @author llp
 *         2016/3/14 0:10
 * @description:
 */
public class TestJni {

    static {
        System.loadLibrary("TestJni");
    }

    public native String logV();

}
