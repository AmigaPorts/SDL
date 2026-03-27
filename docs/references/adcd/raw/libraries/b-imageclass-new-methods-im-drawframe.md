# B / imageclass / New Methods: IM_DRAWFRAME


The IM_DRAWFRAME method instructs an image object to render itself within
the confines of a given rectangle.  The return value for this method is
not explicitly defined.

This method uses a custom message structure that is basically an extension
of the [IM_DRAW](../Libraries_Manual_guide/node04D2.html) message: struct [impDraw](../Libraries_Manual_guide/node04D2.html#line7)


```c
    {
        ULONG           MethodID;    /* IM_DRAWFRAME */
        struct RastPort *imp_RPort;  /* RastPort to render into */
        struct
        {
            WORD X;                  /* X and Y offset relative to the */
            WORD Y;           /* image's IA_Left and IA_Top attributes */
        } imp_Offset;
        ULONG    imp_State;  /* Visual state of image (see defines below)*/
        struct DrawInfo *imp_DrInfo;
                    /* DrawInfo describing target RastPort (can be NULL) */
        struct
        {
            WORD Width;   /* scale, clip, restrict, etc. to these bounds */
            WORD Height;
        } imp_Dimensions;
    };
```
The Width and Height fields provide the object's rectangular bounds.  How
the image object deals with the frame is implementation specific.  If the
[imageclass](../Libraries_Manual_guide/node04D1.html) dispatcher sees this message, it will convert it to an [IM_DRAW](../Libraries_Manual_guide/node04D2.html)
message and send it back to the image's true class.  An image subclass
which assigns proper meaning to this method (i.e., [frameiclass](../Libraries_Manual_guide/node04DF.html)) should
handle this method itself.

This method is useful to classes of images that can scale or clip
themselves to arbitrary dimensions.  Typically, an instance of a class
that truly supports this method will massage its imagery as best it can to
fit into the rectangle.

In general, applications that use this method to draw an object should use
the [IM_ERASEFRAME](../Libraries_Manual_guide/node04D7.html) method to erase it (see below).  This will ensure that
the image erases itself at the proper scale.

