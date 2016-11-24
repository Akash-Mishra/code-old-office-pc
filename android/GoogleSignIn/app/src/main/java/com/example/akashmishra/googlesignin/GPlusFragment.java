package com.example.akashmishra.googlesignin;

import android.view.View;

/**
 * Created by akash.mishra on 15/11/16.
 */

public class GPlusFragment {

    private void updateUI(boolean signedIn){
        if (signedIn){
            signInButton.setVisibility(View.GONE);
            signOutButton.setVisibility(View.VISIBLE);
        }
        else {

        }
    }
}
