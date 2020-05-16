package com.cenarius.component;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.util.Log;
import android.view.Surface;
import android.view.SurfaceHolder;

class TorchController implements SurfaceHolder.Callback{
    static {
        System.loadLibrary("cenarius");
    }
    private float       mScreenScale = 1.0f;
    private TorchView   mRelatedView = null;
    private Context     mContext     = null;
    private long mNativeCoreHandle = 0;
    protected TorchController(TorchView view) {
        mContext = view.getContext();
        mRelatedView = view;
        mScreenScale = mContext.getResources()
                .getDisplayMetrics().density;
        mNativeCoreHandle = ntCreateInstance();
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        ntSurfaceCreated(mNativeCoreHandle, holder.getSurface());
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int w, int h) {
        ntSurfaceChanged(mNativeCoreHandle, holder.getSurface(), mScreenScale);
//        Canvas canvas = holder.lockCanvas();
//        canvas.drawColor(Color.argb(10, 255, 0, 0));
//        holder.unlockCanvasAndPost(canvas);
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        ntSurfaceDestroyed(mNativeCoreHandle);
    }

    // native interface
    static native long ntCreateInstance  ();
    static native long ntSendVsyncEvent  (long _id);
    static native long ntSetHomePath     (long _id, String path);
    static native long ntSetCachePath    (long _id, String path);
    static native long ntSurfaceCreated  (long _id, Surface surface);
    static native long ntSurfaceChanged  (long _id, Surface surface, float scale);
    static native long ntSurfaceDestroyed(long _id);
    static native long ntOnShow          (long _id);
    static native long ntOnHide          (long _id);
    static native long ntFinalization    (long _id);

    // on show
    protected void onShow() {
        ntOnShow(mNativeCoreHandle);
    }

    // on hide
    protected void onHide() {
        ntOnHide(mNativeCoreHandle);
    }

    // received a vsync signal
    // !!!!
    // for performance reasons this function will be
    // executed in an asynchronous thread
    protected void onReceiveVsync() {
        ntSendVsyncEvent(mNativeCoreHandle);
    }

    // received notification to uninstall the kernel
    // !!!
    // ensure that on_receive_vsync is not called
    // during or after calling on_final_finalization
    protected void onFinalFinalization() {
        if (0 != mNativeCoreHandle) {
            ntFinalization(mNativeCoreHandle);
            mNativeCoreHandle = 0;
        }
    }
}