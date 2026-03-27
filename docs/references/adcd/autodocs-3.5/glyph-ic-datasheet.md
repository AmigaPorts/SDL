---
title: glyph_ic/--datasheet--
manual: autodocs-3.5
chapter: autodocs-3.5
section: glyph-ic-datasheet
functions: []
libraries: []
---

# glyph_ic/--datasheet--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        glyph_ic -- create glyph BOOPSI objects

    SUPERCLASS
        imageclass

    REQUIRES
        drawlist.image

    DESCRIPTION
        This image class can create scaled glyphs suitable for use
        as gadget imagery or informational requestor imagery.
        Either a penmap or drawlist scaled image is created internally,
        and external user prefered glyph style sets may become possible
        at a later date.

    METHODS
        OM_NEW -- Create the glyph image. Passed to superclass, then OM_SET.

        OM_GET -- Get object attributes. Passed to superclass first.

        OM_SET -- Set object attributes.
            Passed to superclass first.

        OM_UPDATE -- Set object notification attributes. Passed to
            superclass first.

        IM_DRAW -- Renders the image. Overrides the superclass.

        IM_DRAWFRAME -- Renders the image scaled to fit in the frame.
            Following IM_DRAW will be this size. Overrides the superclass.

        All other methods are passed to the superclass.

    ATTRIBUTES
        GLYPH_Glyph (LONG)
            Selects any one of the built-in scaled image glyphs.

            Current supported and defined in <gadgets/glyph.h>:

            GLYPH_NONE - No image.
            GLYPH_DOWNARROW - Indicates downward movement control.
            GLYPH_UPARROW - Indicates upward movement control.
            GLYPH_LEFTARROW - Indicates left movement control.
            GLYPH_RIGHTARROW - Indicates right movement control.
            GLYPH_DROPDOWN - Denotes a drop-down menu.
            GLYPH_POPUP - Denotes a pop-up menu.
            GLYPH_CHECKMARK - Indicates a toggle.
            GLYPH_POPFONT - Font selection.
            GLYPH_POPFILE - File selection.
            GLYPH_POPDRAWER - Drawer (directory) selection.
            GLYPH_POPSCREENMODE - Screenmode selection.
            GLYPH_POPTIME - Time selection.
            GLYPH_RADIOBUTTON - Mutual exclusion item.
            GLYPH_RETURNARROW - RETURN key controlled.

            Defaults to GLYPH_POPFILE.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)
```
