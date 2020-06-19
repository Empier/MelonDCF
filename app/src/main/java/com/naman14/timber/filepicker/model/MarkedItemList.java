/*
 * Copyright (C) 2016 Angad Singh
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.naman14.timber.filepicker.model;

import java.io.File;
import java.security.AccessControlContext;
import java.util.HashMap;
import java.util.Set;


import android.net.Uri;
import android.util.Log;

import android.content.Intent;
import android.content.Context;
import android.content.BroadcastReceiver;
import android.content.IntentFilter;
import android.os.*;


//import com.naman14.timber.activities.MainActivity;

import com.naman14.timber.activities.MainActivity;
import com.naman14.timber.filepickerdemo.ConvertComplete;



/**<p>
 * Created by Angad Singh on 11-07-2016.
 * </p>
 */

/*  SingleTon containing <Key,Value> pair of all the selected files.
 *  Key: Directory/File path.
 *  Value: FileListItem Object.
 */


public class MarkedItemList{
    static{
        System.loadLibrary("native-lib");
    }



    private static HashMap<String,FileListItem> ourInstance = new HashMap<>();

    public static void addSelectedItem(FileListItem item) {
        ourInstance.put(item.getLocation(),item);

    }

    public static void removeSelectedItem(String key) {
        ourInstance.remove(key);
    }

    public static boolean hasItem(String key) {
        return ourInstance.containsKey(key);
    }

    public static void clearSelectionList() {
        ourInstance = new HashMap<>();
    }

    public static void addSingleFile(FileListItem item) {
        ourInstance = new HashMap<>();
        ourInstance.put(item.getLocation(),item);

    }

    public static native void SHA1(String dir);
    public static String[] getSelectedPaths() {

        Set<String> paths = ourInstance.keySet();
        String fpaths[]=new String[paths.size()];
        //MainActivity AA;
        int i=0;

        //AA=new MainActivity();
        //MainActivity.jj("asdf");
        for(String path:paths)
        {   fpaths[i++]=path;
            SHA1(path);

//            AA.jj(path);

        }

        //sendBroadcast(new Intent(Intent.ACTION_MEDIA_MOUNTED, Uri.parse("file://" + Environment.getExternalStorageDirectory())));
        return fpaths;
    }

    public static int getFileCount() {
        return ourInstance.size();
    }
}
