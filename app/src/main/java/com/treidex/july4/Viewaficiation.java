package com.treidex.july4;

import android.content.Context;
import android.opengl.GLSurfaceView;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

class MyRenderer implements GLSurfaceView.Renderer {

    @Override
    public native void onSurfaceCreated(GL10 gl, EGLConfig config);

    @Override
    public native void onSurfaceChanged(GL10 gl, int width, int height);

    @Override
    public native void onDrawFrame(GL10 gl);
}

public class Viewaficiation extends GLSurfaceView {
    private MyRenderer renderer;

    public Viewaficiation(Context ctx) {
        super(ctx);

        setEGLContextClientVersion(2);
        renderer = new MyRenderer();
        setRenderer(renderer);
    }
}