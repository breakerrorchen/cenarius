package com.cenarius.component;

import android.content.Context;
import android.graphics.PixelFormat;
import android.os.Looper;
import android.util.AttributeSet;
import android.view.Choreographer;
import android.view.SurfaceView;
import android.view.inputmethod.InputMethod;
import android.view.inputmethod.InputMethodManager;

public class TorchView
        extends SurfaceView implements Choreographer.FrameCallback{
    public TorchView(Context context) {
        this(context, null);
    }

    public TorchView(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    private TorchController mTorchController = null;
    private Looper mVsyncThreadLooper = null;
    private Choreographer mVsyncReceiver = null;
    private Thread mVsyncThread = null;
    public TorchView(Context context, AttributeSet attrs, int style) {
        super(context, attrs, style);
        this.mTorchController = new TorchController(this);
        this.setFocusable(true);
        this.setFocusableInTouchMode(true);
        this.setClickable(true);
        this.setZOrderOnTop(false);
        this.getHolder().setFormat(PixelFormat.RGBA_8888);
        this.getHolder().addCallback(this.mTorchController);
        // Here, a new thread is started to get vsync notifications,
        // which is mainly to prevent the main thread from running
        // and causing the vsync signal to be distributed quickly
        this.mVsyncThread = new Thread(new Runnable() {
            @Override
            public void run() {
                Looper.prepare();
                mVsyncThreadLooper = Looper.myLooper();
                synchronized(TorchView.this) {
                    TorchView.this.notifyAll();
                }
                mVsyncReceiver = Choreographer.getInstance();
                mVsyncReceiver.postFrameCallback(TorchView.this);
                Looper.loop();
                mVsyncReceiver.removeFrameCallback(TorchView.this);
                synchronized (TorchView.this) {
                    TorchView.this.notifyAll();
                }
            }
        });
        this.mVsyncThread.start();

        // If you exit on startup, you must wait for the startup
        // to complete before executing the exit logic
        synchronized(this) {
            try {
                this.wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        // 显示输入法
        InputMethodManager im = (InputMethodManager)
                context.getSystemService(Context.INPUT_METHOD_SERVICE);
        im.showSoftInput(this, InputMethodManager.SHOW_FORCED);
    }

    @Override
    public void doFrame(long frameTimeNanos) {
        if (null != mVsyncReceiver) {
            mVsyncReceiver.postFrameCallback(this);
        }

        if (null != mTorchController) {
            mTorchController.onReceiveVsync();
        }
    }

    // on show
    public void onShow() {
        if (null != mTorchController) {
            mTorchController.onShow();
        }
    }

    // on hide
    public void onHide() {
        if (null != mTorchController) {
            mTorchController.onHide();
        }
    }

    // External destruction notification
    // should be the same as the host activity life cycle
    public void finalFinalization() {
        if (null != mVsyncThreadLooper) {
            mVsyncThreadLooper.quit();
            try {
                mVsyncThread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            mVsyncThreadLooper = null;
        }

        if (null != mTorchController) {
            mTorchController.onFinalFinalization();
        }
    }
}
