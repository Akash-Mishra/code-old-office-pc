package com.example.akashmishra.githubreposearch;

import android.os.AsyncTask;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

/**
 * Created by akash.mishra on 15/11/16.
 */

public class DownloadRepoTask extends AsyncTask<String, Void, String> {

    //1
    @Override
    protected String doInBackground(String... params) {
//        is = conn.getInputStream();
//        return null;
        try {
            return downloadData(params[0]);
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
    }


    //2
    @Override
    protected void onPostExecute(String result){

    }

    //3
    private String downloadData(String urlString) throws IOException {
        InputStream is = null;
        try {
            URL url = new URL(urlString);
            HttpURLConnection conn = (HttpURLConnection)url.openConnection();
            conn.setRequestMethod("GET");
            conn.connect();
            is = conn.getInputStream();
            return convertToString(is);
        } finally {
            if (is != null){
                is.close();
            }
        }
    }


    //4
    private String convertToString(InputStream is) throws IOException{
        BufferedReader r = new BufferedReader(new InputStreamReader(is));
        StringBuilder total = new StringBuilder();
        String line;
        while ((line = r.readLine()) != null){
            total.append(line);
        }
        return new String(total);
    }
}
