---
title: drawlist_ic/--datasheet--
manual: autodocs-3.5
chapter: autodocs-3.5
section: drawlist-ic-datasheet
functions: [AreaCircle, AreaDraw, AreaEllipse, AreaMove, Flood, RectFill, ScalerDiv]
libraries: [graphics.library]
---

# drawlist_ic/--datasheet--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        drawlist_ic -- create drawlist BOOPSI objects

    SUPERCLASS
        imageclass

    REQUIRES
        None.

    DESCRIPTION
        This image class can create custom scaled glyphs via a
        "drawlist". The drawlist is an array of drawing directives
        such as lines, areafills, etc. All coordinates are based
        on an imaginary grid of a user specified size, then
        [ScalerDiv()](autodocs-3.5/graphics-library-scalerdiv-2.md) is used to scale these coordinates to the desired
        image size to be rendered. This is a lower level class utilized
        by glyph.image, if you create some interesting drawlist, please
        consider passing them on to others, or to us for inclusion.

    METHODS
        OM_NEW -- Create the drawlist image.  Passed to superclass, then
            OM_SET.

        OM_GET -- Get object attributes.  Passed to superclass first.

        OM_SET -- Set object attributes.  Passed to superclass first.

        OM_UPDATE -- Set object notification attributes.  Passed to
            superclass first.

        IM_DRAW -- Renders the images.  Overrides the superclass.
        IM_DRAWFRAME -- Renders the images scaled to thee frame size.
            Overrides the superclass.

        All other methods are passed to the superclass, including OM_DISPOSE.

    ATTRIBUTES
        DRAWLIST_Directives (struct [DrawList](autodocs-3.5/include-images-drawlist-h.md) *)
            An array of drawlist directive structures are passed
            to specify the vectors and render operation. The last
            entry must be DLST_END!

            struct [DrawList](autodocs-3.5/include-images-drawlist-h.md)
            {
                WORD dl_Directive;
                WORD dl_X1, dl_Y1;
                WORD dl_X2, dl_Y2;
                WORD dl_Pen;
            };


            The following directives are supported;

            DLST_END      - End the directive list.
            DLST_LINE     - Render a line from dl_x1,dl_y1 to dl_x2,dl_y2
            DLST_RECT     - [Cause](autodocs-3.5/exec-library-cause-2.md) a [RectFill()](autodocs-3.5/graphics-library-rectfill-2.md) of size dl_x1,dl_y1,dl_x2,dl_y2
            DLST_LINEPAT  - Set the line pattern to value held in dl_Pen
            DLST_FILLPAT  - Set the fill pattern to value held in dl_Pen
            DLST_LINESIZE - Set the drawlist line thickness via dl_Pen
            DLST_AMOVE    - [AreaMove()](autodocs-3.5/graphics-library-areamove-2.md) using dl_x1,dl_y1
            DLST_ADRAW    - [AreaDraw()](autodocs-3.5/graphics-library-areadraw-2.md) using dl_x1,dl_y1
            DLST_AFILL    - [Cause](autodocs-3.5/exec-library-cause-2.md) the AreaFill() operation
            DLST_FILL     - [Flood()](autodocs-3.5/graphics-library-flood-2.md) an area.
            DLST_ELLIPSE  - [AreaEllipse()](autodocs-3.5/graphics-library-areaellipse-2.md)
            DLST_CIRCLE   - [AreaCircle()](autodocs-3.5/graphics-library-areacircle-2.md)
            DLST_BEVELBOX - currently unsupported (alpha function removed)
            DLST_ARC      - currently unsupported
            DLST_START    - currently unsupported
            DLST_BOUNDS   - currently unsupported

            Defaults to NULL.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        DRAWLIST_RefHeight (WORD)
            Reference height of the drawlist imagary grid.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        DRAWLIST_RefWidth (WORD)
            Reference width of the drawlist imagary grid.

            Applicability is (OM_NEW, OM_SET, OM_GET)
```

---

## See Also

- [AreaCircle — graphics.library](../autodocs/graphics.library.md#areacircle)
- [AreaDraw — graphics.library](../autodocs/graphics.library.md#areadraw)
- [AreaEllipse — graphics.library](../autodocs/graphics.library.md#areaellipse)
- [AreaMove — graphics.library](../autodocs/graphics.library.md#areamove)
- [Flood — graphics.library](../autodocs/graphics.library.md#flood)
- [RectFill — graphics.library](../autodocs/graphics.library.md#rectfill)
- [ScalerDiv — graphics.library](../autodocs/graphics.library.md#scalerdiv)
