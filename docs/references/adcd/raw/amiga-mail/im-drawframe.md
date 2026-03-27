# IM_DRAWFRAME


The IM_DRAWFRAME method instructs the image to render itself within the
confines of the given rectangle.  It receives the following parameters:


```c
    struct impDraw
    {
        ULONG MethodID;
        struct RastPort *imp_RPort;
        struct
        {
            WORD X;
            WORD Y;
        } imp_Offset;

        ULONG imp_State;
        struct DrawInfo *imp_DrInfo;

        struct
        {
            WORD Width;
            WORD Height;
        } imp_Dimensions;
    };
```
The Width and Height fields provide the object's rectangular bounds. How
the image object deals with the frame is implementation specific.
Typically, a scaleable image will scale itself as best it can to fit into
the rectangle.  The [mytextlabelclass.c](../AmigaMail_Vol2_guide/node01AF.html) example does not actually implement
this method, instead mytextlabelclass treats IM_DRAWFRAME like the IM_DRAW
method.

In general, applications that use this method to draw an object should use
the IM_ERASEFRAME method (see below) to erase it.  This will ensure that
the image was erased at the proper scale.

