package com.example.akashmishra.githubreposearch;

import android.app.ProgressDialog;
import android.content.Context;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.content.DialogInterface;
import android.support.v7.app.AlertDialog;
import android.widget.ProgressBar;

public class MainActivity extends AppCompatActivity {

    ProgressDialog mProgressBar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        if (isNetworkConnected()){
            mProgressBar = new ProgressDialog(this);
            mProgressBar.setMessage("Please wait...");
            mProgressBar.setCancelable(false);
            mProgressBar.show();

            startDownload();
        } else {
            new AlertDialog.Builder(this)
                    .setTitle("No Internet Connection")
                    .setMessage("It seems that your internet connection is off. Please turn it" +
                            " on and try again")
                    .setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialogInterface, int i) {

                        }
                    }).setIcon(android.R.drawable.ic_dialog_alert).show();
        }
    }

    private void startDownload() {
        new DownloadRepoTask().execute("https://api.github.com/repositories");
    }

    private boolean isNetworkConnected(){
        ConnectivityManager connectivityManager = (ConnectivityManager)getSystemService(Context.CONNECTIVITY_SERVICE); // 1
        NetworkInfo networkInfo = connectivityManager.getActiveNetworkInfo();  // 2
        return networkInfo != null && networkInfo.isConnected();   // 3
    }


}
