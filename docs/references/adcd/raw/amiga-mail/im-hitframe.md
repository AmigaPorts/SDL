# IM_HITFRAME


The IM_HITFRAME method is used to determine if a point is within an image
that is contained within (or scaled to) the given rectangle. This method
is intended to test images that were rendered using IM_DRAWFRAME.  This
method receives the following parameters:


```c
    struct impHitTest
    {
        ULONG MethodID;
        struct
        {
            WORD X;
            WORD Y;
        } imp_Point;

        struct
        {
            WORD Width;
            WORD Height;
        } imp_Dimensions;
    };
```
The mytextlabelclass example blindly passes this method on to its
superclass.  The superclass treat this meothd just like the IM_HITTEST
method.

