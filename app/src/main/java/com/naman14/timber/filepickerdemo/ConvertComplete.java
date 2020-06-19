package com.naman14.timber.filepickerdemo;

import java.io.File;

import android.app.Activity;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.media.MediaScannerConnection;
import android.media.MediaScannerConnection.MediaScannerConnectionClient;
import android.media.MediaScannerConnection.OnScanCompletedListener;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;

import com.naman14.timber.activities.MainActivity;

public class ConvertComplete extends BroadcastReceiver {
    @Override
    public void onReceive(Context arg0, Intent intent) {
        switch (intent.getAction()) {
           // case MainActivity.ACTION_DOWNLOAD_COMPLETE:
           //     Log.i("KOREAMP","Reveive!!!!!");
            // scanDirAsync(arg0);
            // sdScan(arg0);
            //  sdScan(arg0);
            // sdScan2(arg0.getApplicationContext());

            //  break;
            case Intent.ACTION_MEDIA_SCANNER_STARTED:
                break;
            case Intent.ACTION_MEDIA_SCANNER_FINISHED:
                break;
        }
    }

}










    //ctx.sendBroadcast(new Intent(Intent.ACTION_MEDIA_SCANNER_SCAN_FILE, Uri.parse("file://" + Environment.getExternalStorageDirectory())));
//		ctx.sendBroadcast(new Intent(Intent.ACTION_MEDIA_MOUNTED, Uri.parse("file://" + Environment.getExternalStorageDirectory())));

        /*File f = new File("file://"+ path+".mp3");
        Log.i("KOREAMP","file://"+ path+".mp3");
        ctx.sendBroadcast(new Intent(Intent.ACTION_MEDIA_SCANNER_SCAN_FILE, Uri.fromFile(f)));


        //sendBroadcast(new Intent(Intent.ACTION_MEDIA_SCANNER_SCAN_FILE, Uri.parse("file://"+path+".mp3")));

       // Intent intent = new Intent(Intent.ACTION_MEDIA_SCANNER_SCAN_FILE);
     //   File f = new File("file://"+ path+".mp3");
     //   intent.setData(Uri.fromFile(f));
     //   sendBroadcast(intent);
        //this.sendBroadcast(intent);
    */










/*
    @Override
    public void onReceive(Context arg0, Intent intent) {
        switch (intent.getAction()) {
            //case MainActivity.ACTION_DOWNLOAD_COMPLETE:
            // scanDirAsync(arg0);
            // sdScan(arg0);
            //  sdScan(arg0);
            // sdScan2(arg0.getApplicationContext());
            //  break;
            case Intent.ACTION_MEDIA_SCANNER_STARTED:
                break;
            case Intent.ACTION_MEDIA_SCANNER_FINISHED:
                break;
        }
    }
*/

//*
//    public final static String ACTION_DOWNLOAD_COMPLETE = "android.intent.action.DOWNLOAD_COMPLETE";
//    public static void jj(String path)
//    {
//        Intent intent = new Intent(MainActivity.ACTION_DOWNLOAD_COMPLETE);
//    }*/