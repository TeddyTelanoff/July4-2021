package com.treidex.july4;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

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

class MyView extends GLSurfaceView {
    private MyRenderer renderer;

    public MyView(Context ctx) {
        super(ctx);

        setEGLContextClientVersion(2);
        renderer = new MyRenderer();
        setRenderer(renderer);
    }
}

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        GLSurfaceView view = new MyView(this);
        setContentView(view);
    }
}
