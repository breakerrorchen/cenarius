package com.example.cenariusdashboard;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.FrameLayout;

import com.cenarius.component.TorchGround;
import com.cenarius.component.TorchView;
import com.gyf.immersionbar.ImmersionBar;

public class MainActivity extends Activity {
    private TorchGround mTorchView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        ImmersionBar.with(this).init();
        setContentView(R.layout.activity_main);
        this.mTorchView = findViewById(R.id.dashview);
        //mTorchView.load();
        ((Button)findViewById(R.id.button))
                .setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
//                FrameLayout.LayoutParams lp =
//                        new FrameLayout.LayoutParams(mTorchView.getLayoutParams());
//                lp.setMargins(10, 10, 10, 10);
//                mTorchView.setLayoutParams(lp);
//                Intent intent = new Intent(MainActivity.this, MainActivity.class);
//                MainActivity.this.startActivity(intent);
                mTorchView.load();;

            }
        });

    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
//        if (null != mTorchView) {
//            mTorchView.load();
//        }
    }
}

