---
title: B / imageclass / New Methods: IM_FRAMEBOX
manual: libraries
chapter: libraries
section: b-imageclass-new-methods-im-framebox
functions: []
libraries: []
---

# B / imageclass / New Methods: IM_FRAMEBOX

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method applies to image classes that are used to put a frame centered
around some other objects.  This method asks a framing image what its
dimensions should be if it had to frame some object or set of objects that
fit into a rectangular bounds.  For example, to draw an [frameiclass](libraries/b-boopsi-class-reference-frameiclass.md) image
around a group of gadgets that fit into a specific rectangle, you first
send the frameiclass object an IM_FRAMEBOX message describing the
dimensions and position of that rectangle.  The frame reports what its
position and dimensions would have to be to surround those gadgets.  Use
these results to draw the frameiclass image.  The return value for this
method is not explicitly defined.

IM_FRAMEBOX uses a custom message structure:


```c
    struct impFrameBox
    {
        ULONG           MethodID;         /* IM_FRAMEBOX  */
        struct IBox     *imp_ContentsBox; /* The object fills in this  */
                                          /* structure with the        */
                                          /* dimensions of a rectangle */
                                          /* big enough to frame...    */
        struct IBox     *imp_FrameBox;    /* <------- this rectangle.  */
        struct DrawInfo *imp_DrInfo;      /* imp_DrInfo can be NULL.   */
        ULONG           imp_FrameFlags;
    };
    #define FRAMEF_SPECIFY  (1<<0)  /* Make do with the dimensions */
                                    /* passed in FrameBox.         */
```
The imp_FrameBox field points to an IBox structure (defined in
<intuition/[intuition.h](autodocs-2.0/includes-intuition-intuition-h.md)>) describing the dimensions and position of the
rectangle to frame.  After the framing image determines the position and
size it should be in order to properly frame imp_FrameBox, it stores the
result in the imp_ContentsBox IBox.  This method allows an application to
use a framing image without having to worry about image specific details
such as the thickness of the frame or centering the frame around the
object.

The imp_FrameFlags field is a bit field used to specify certain options
for the IM_FRAMEBOX method.  Currently, there is only one defined for it,
FRAMEF_SPECIFY.  If this bit is set, the imp_FrameBox contains a width and
height that the frame image has to use as its width and height, even if
the imp_FrameBox is smaller than imp_ContentsBox.  The frame is free to
adjust its position, but it is stuck with the imp_FrameBox dimensions.
This allows an application to set the size of the frame image and still
allow the frame image to position itself so it is centered on a rectangle.

The [imageclass](libraries/b-boopsi-class-reference-imageclass.md) dispatcher does not support this method.  It returns zero.

