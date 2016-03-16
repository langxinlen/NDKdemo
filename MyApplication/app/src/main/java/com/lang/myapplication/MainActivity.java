package com.lang.myapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private TextView mNameTv;
    private TextView mEncryptTv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TestJni jniLog = new TestJni();

        mNameTv = (TextView) findViewById(R.id.tv_name);
        mNameTv.setText(jniLog.logV());

        Encrypt encrypt = new Encrypt();
        mEncryptTv = (TextView) findViewById(R.id.tv_encrypt);
        mEncryptTv.setText(encrypt.encrypt("1234567890"));

    }
}
