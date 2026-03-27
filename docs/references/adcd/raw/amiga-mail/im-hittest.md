# IM_HITTEST


IM_HITTEST returns true if a point is within the image.  The Intuition
function PointInImage() uses this method.  IM_HITTEST requires the
following parameters:


```c
    struct impHitTest
    {
        ULONG MethodID;
        struct
        {
            WORD X;
            WORD Y;
        } imp_Point;
    };
```
The mytextlabelclass example blindly passes this method on to its
superclass.  The superclass, imageclass, will return TRUE if the point is
within the old Image structure box.

