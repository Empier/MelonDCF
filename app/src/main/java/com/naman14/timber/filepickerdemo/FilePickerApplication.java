package com.naman14.timber.filepickerdemo;

import android.app.Application;

import com.squareup.leakcanary.LeakCanary;

/**
 * <p>
 * Created by Angad on 28-10-2017.
 * </p>
 */

public class FilePickerApplication extends Application {

    @Override
    public void onCreate() {
        super.onCreate();
        if (LeakCanary.isInAnalyzerProcess(this)) {
            return;
        }
        LeakCanary.install(this);
    }
}
