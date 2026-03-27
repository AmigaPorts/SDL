# B / imageclass / New Methods: IM_HITFRAME


This method is a special version of [IM_HITTEST](../Libraries_Manual_guide/node04D3.html) for images that support
[IM_DRAWFRAME](../Libraries_Manual_guide/node04D5.html).  It asks an image if a point would be inside it if the image
was confined (scaled, clipped, etc.) to a rectangular bounds.  The return
value for this method is not explicitly defined.

This method uses a custom message structure:


```c
    struct impHitTest
    {
        ULONG MethodID;    /* IM_HITFRAME */
        struct
        {
            WORD X;        /* Coordinates of point to test for hit */
            WORD Y;
        } imp_Point;

        struct
        {
            WORD Width;  /* scale, clip, restrict, etc. to these bounds */
            WORD Height;
        } imp_Dimensions;
    };
```
The [imageclass](../Libraries_Manual_guide/node04D1.html) dispatcher treats IM_HITFRAME just like [IM_HITTEST](../Libraries_Manual_guide/node04D3.html),
ignoring the restricting dimensions.

