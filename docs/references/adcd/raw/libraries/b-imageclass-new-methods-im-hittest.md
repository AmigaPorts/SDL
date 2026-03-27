# B / imageclass / New Methods: IM_HITTEST


This method returns TRUE if a point is within the old [Image](../Libraries_Manual_guide/node01BA.html) structure box
defined by the Image structure's [LeftEdge](../Libraries_Manual_guide/node01BA.html#line17), [TopEdge](../Libraries_Manual_guide/node01BA.html#line17), [Width](../Libraries_Manual_guide/node01BA.html#line32), and [Height](../Libraries_Manual_guide/node01BA.html#line32)
fields.  Subclasses of [imageclass](../Libraries_Manual_guide/node04D1.html) can redefine this method if they need to
change the criteria for deciding if a point is within an image.
Application programs should not call this method directly, instead use the
Intuition function [PointInImage()](../Includes_and_Autodocs_2._guide/node023C.html).  The IM_HITTEST method uses a custom
message structure:


```c
    struct impHitTest
    {
        ULONG MethodID; /* IM_HITTEST */
        struct
        {
            WORD X;     /* Coordinates of point to test for hit */
            WORD Y;
        } imp_Point;
    };
```
If an image object doesn't need to make any changes to how its superclass
handles IM_HITTEST, it can blindly pass this method on to its superclass.

