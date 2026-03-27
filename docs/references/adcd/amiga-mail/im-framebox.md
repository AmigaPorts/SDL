---
title: IM_FRAMEBOX
manual: amiga-mail
chapter: amiga-mail
section: im-framebox
functions: []
libraries: []
---

# IM_FRAMEBOX

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The IM_FRAMEBOX method returns size information for an image (usually some
sort of frame image).  The following parameters are associated with the
IM_FRAMEBOX method.


```c
    struct impFrameBox
    {
        ULONG MethodID;
        struct IBox *imp_ContentsBox;  /* Application supplied IBox for the result */
        struct IBox *imp_FrameBox;     /* Rectangle to frame */
        struct DrawInfo *imp_DrInfo;
        ULONG imp_FrameFlags;
    };
```
This method is used to ask the image what size it would like to be, if it
had to frame the rectangle in the imp_FrameBox field.  This method
normally applies only to image classes that put a frame around some object
(like frameiclass).  By passing the dimensions and position of a
rectangle, the framing image determines the position and size it should be
to properly "frame" the object bounded by the imp_FrameBox rectangle.
IM_FRAMEBOX stores the result in the IBox structure pointed to by
imp_ContentsBox.  This method allows an application to use a framing image
without having to worry about image specific details such as accounting
for the thickness of the frame or centering the frame around the object.

The imp_FrameFlags field is a bit field used to specify certain options
for the IM_FRAMEBOX method.  Currently, there is only one defined for it,
FRAMEF_SPECIFY.  If this bit is set, IM_FRAMEBOX has to use the width and
height supplied to it in the imp_FrameBox field (even if these are too
small!) as the frame dimensions.  It can only adjust its position,
typically to center the object as best as possible.

This method is not supported by the mytextlabelclass example.  It passes
this message to its superclass which does not support this method either.
When the message returns from the superclass, the return value will be
zero, indicating to the application that this method is not supported.

