package com.cenarius.component;

import android.content.Context;
import android.util.AttributeSet;
import android.view.ViewGroup;
import android.widget.FrameLayout;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

public class TorchGround extends FrameLayout {
    private TorchView mTorchView = null;
    public TorchGround(@NonNull Context context) {
        super(context);
    }

    public TorchGround(@NonNull Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
    }

    public TorchGround(@NonNull Context context, @Nullable AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
    }

    public void load() {
        if (null != mTorchView) {
            mTorchView.finalFinalization();
            removeView(mTorchView);
            mTorchView = null;
        }
        mTorchView = new TorchView(this.getContext());
        mTorchView.setLayoutParams(new FrameLayout.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT,
                ViewGroup.LayoutParams.MATCH_PARENT));
        addView(mTorchView);
    }
}
