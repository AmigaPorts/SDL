---
title: IM_DRAW
manual: amiga-mail
chapter: amiga-mail
section: im-draw
functions: [DrawImageState]
libraries: [intuition.library]
---

# IM_DRAW

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The IM_DRAW method is used to tell the image to render itself.  The
Intuition function DrawImageState() uses this method.  IM_DRAW receives
the following parameters:


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
    };
```
The imp_State field contains the visual state to render the image. The
visual states (defined in <intuition/imageclass.h>) are:

        IDS_NORMAL              idle state
        IDS_SELECTED            for selected gadgets.
        IDS_DISABLED            for disabled gadgets.
        IDS_BUSY                for future functionality
        IDS_INDETERMINATE       for future functionality
        IDS_INACTIVENORMAL      normal, in inactive window border.
	IDS_INACTIVESELECTED	selected, in inactive border.
	IDS_INACTIVEDISABLED	disabled, in inactive border.

When setting the pens to render an image, use the values from the
imp_DrInfo->dri_Pens pen array (Note that it is possible that imp_DrInfo
will be NULL).  The possible pen values are defined in
<intuition/screens.h>.

The following code fragment shows how to use the shadow color for
rendering.


```c
    UWORD *pens = (imp->imp_DrInfo) ? imp->imp_DrInfo->dri_Pens : NULL;

    if (pens)
    {
        SetAPen (imp->imp_RPort, pens[SHADOWPEN]);
    }
```

---

## See Also

- [DrawImageState — intuition.library](../autodocs/intuition.library.md#drawimagestate)
