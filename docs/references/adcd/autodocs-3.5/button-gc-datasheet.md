---
title: button_gc/--datasheet--
manual: autodocs-3.5
chapter: autodocs-3.5
section: button-gc-datasheet
functions: [DrawImageState, EraseRect, RawDoFmt, RectFill, Text, TextLength]
libraries: [exec.library, graphics.library, intuition.library]
---

# button_gc/--datasheet--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        button_gc -- create button BOOPSI objects

    SUPERCLASS
        gadgetclass

    REQUIRES
        bevel.image, glyph.image

    DESCRIPTION
        The button gadget class is used to create action buttons that are
        momentary, toggle and sticky.  This class also supports relativity
        and placement within the window border.

        Advantages that this class provides:

         > Centered images.

         > Centered pen-sensitive glyphs.

         > Multi-frame images animation ability (NEW V42)

         > Ability to change the text and background colors for normal
           and selected buttons.

         > Supports window relativity.

         > Supports OS 3.0 BOOPSI [Gadget](autodocs-3.5/include-intuition-intuition-h.md) HelpTest.

     METHODS
        OM_NEW -- Passed to superclass, defaults set, then OM_SET.

        OM_SET -- Passed to superclass, custom tags set.

        OM_GET -- [Custom](autodocs-3.5/include-hardware-custom-h.md) tag returned or passed to superclass.

        OM_UPDATE -- Passed to superclass, options set then rendered.

        OM_NOTIFY -- [Tag](autodocs-3.5/include-utility-tagitem-h.md) set then passed to superclass.

        OM_DISPOSE -- MemPool memory freed, then Passed to superclass.

        GM_RENDER -- Passed to superclass, then button is rendered.

        GM_HITTEST -- Overrides supperclass, returns GMR_HITTEST.

        GM_GOACTIVE -- Passed to superclass, button activated.

        GM_HANDLEINPUT -- Overrides supperclass, all input processed.

        GM_GOINACTIVE -- Passed to superclass, button deactivated.

        GM_DOMAIN -- Returns GDOMAIN_MINIMUM and GDOMAIN_MAXIMUM dimensions.

        GM_KEYACTIVE -- Private method for keyboard control.

        GM_KEYINACTIVE -- Private method for keyboard control.

     ATTRIBUTES

        GA_ID (WORD)

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET, OM_NOTIFY)

        GA_Selected (BOOL)
            Determines whether the button is selected or not.
            Changing selection state will invoke GM_RENDER.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_GET, OM_NOTIFY)

        GA_Disabled (BOOL)
            Determines whether the button is disabled or
            not.  Changing disable state will invoke GM_RENDER.  A disabled
            button's border and label are all rendered in SHADOWPEN and then
            dusted in a ghosting pattern.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET,  OM_NOTIFY)

        GA_Text (STRPTR)
            Used to specify the NULL terminated string to use as the text
            for the gadget.  The [Text()](autodocs-3.5/graphics-library-text-2.md) function is used to draw the text.
            NULL is valid input. Changing the label will invoke GM_RENDER.
            [Text](autodocs-3.5/graphics-library-text-2.md) string is clipped to fit inside the button via the
            [TextLength()](autodocs-3.5/graphics-library-textlength-2.md) function. The text string may contain varargs
            format specifiers compatible to [RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md) if the varargs data
            is supplied via BUTTON_VarArgs.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        GA_Image (struct [Image](autodocs-3.5/include-intuition-intuition-h.md) *)
            Used to specify the image to use for the label of the gadget.
            The [DrawImageState()](autodocs-3.5/intuition-library-drawimagestate-2.md) function is used to draw the image.
            Changing the label will invoke GM_RENDER.

            Defaults to NULL.

            Applicability is (OM_NEW, OM_SET)

        GA_SelectImage (struct [Image](autodocs-3.5/include-intuition-intuition-h.md) *)
            Used to specify the image to use for the label of the gadget
            in the selected state. The [DrawImageState()](autodocs-3.5/intuition-library-drawimagestate-2.md) function is used
            to draw the image. Changing the label will invoke GM_RENDER
            if the gadget is currently selected.

            Defaults to NULL.

            Applicability is (OM_NEW, OM_SET)

        GA_TextAttr (struct [TextAttr](autodocs-3.5/include-graphics-text-h.md) *)
            [Text](autodocs-3.5/graphics-library-text-2.md) attribute for the font to use for the text labels.

            Defaults to RPort->Font, which is often the screen or
            window preferences font.

            Applicability is (OM_NEW, OM_SET)

        GA_ReadOnly (BOOL)
            Read-only gadgets ignore activation attempts.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        BUTTON_AutoButton (UWORD)
            Used to create automatic button with one of the selected
            scaled image glyphs. Accepted settings are;

                BAG_POPFILE		- popup file selection glyph
                BAG_POPDRAWER   - popup drawer selection glyph
                BAG_POPFONT		- popup font selection glyph
                BAG_CHECKBOX	- checkmark glyph (same as checkbox.gadget)
                BAG_CANCELBOX   - NOT IMPLEMENETED!
                BAG_UPARROW		- up arrow
                BAG_DNARROW		- down arrow
                BAG_RTARROW		- right arrow
                BAG_LFARROW		- left arrow
                BAG_POPTIME		- popup time glyph
                BAG_POPSCREEN   - popup screen mode glyph

            Defaults to 0.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        BUTTON_PushButton (BOOL)
            Used to indicate that the button stays pressed in when the
            user selects it with the mouse.  The button may
            programmatically be deselected using {GA_Selected, FALSE}.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        BUTTON_TextPen (LONG)
            Indicate the pen number used to render the IDS_NORMAL text.
            If ~0 is specified, then TEXTPEN is used.

            Defaults to ~0.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        BUTTON_BackgroundPen (LONG)
            Indicate the pen number used to render the IDS_NORMAL
            background.  If ~0 is specified, then BACKGROUNDPEN
            is used.

            Defaults to ~0.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        BUTTON_FillTextPen (LONG)
            Indicate the pen number used to render the IDS_SELECTED text.
            If ~0 is specified, then FILLTEXTPEN is used.

            Defaults to ~0.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        BUTTON_FillPen (LONG)
            Indicate the pen number used to render the IDS_SELECTED
            background.  If ~0 is specified, then FILLPEN is used.

            Defaults to ~0.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        BUTTON_BevelStyle (WORD)
            Button bevel box rendering style, passed to bevel.image.
            Supports:

                BVS_NONE
                BVS_THIN
                BVS_BUTTON
                BVS_GROUP

            Defaults to BVS_BUTTON.

            Applicability is (OM_NEW, OM_SET)

        BUTTON_Transparent (BOOL)
            Make button background rendering transparent.
            [EraseRect()](autodocs-3.5/graphics-library-eraserect-2.md) is used rather than [RectFill()](autodocs-3.5/graphics-library-rectfill-2.md) so that
            custom backfill rendering hooks maybe utilized.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET)

        BUTTON_Justification    (WORD)
            Justification mode of button text label.
            Supports:

                BCJ_LEFT
                BCJ_CENTER
                BCJ_RIGHT

            Defaults to BJ_CENTER.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        BUTTON_SoftStyle (WORD)
            Set the GA_TextAttr font's softstyle, ie BOLD, ITALICS, etc.
            See [<graphics/text.h>](autodocs-3.5/include-graphics-text-h.md) SoftStyle definitions.

            Defaults to 0.

            Applicability is (OM_NEW, OM_SET)

        BUTTON_VarArgs (APTR)
            Varargs data array to supply data for [RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md) when
            format specifiers are to be used in GA_Text text strings.
            The internal VarArgs result buffer is presently fixed at
            a maximum of 128 bytes, take care not to exceed this buffer.

            Defaults to NULL.

            Applicability is (OM_NEW, OM_SET)

        BUTTON_DomainString (STRPTR)
            Used to specify the NULL terminated string to use as the text
            to domain the gadgets minimum size. This string is NEVER
            rendered on screen. This is useful when you need to create
            a button with a empty ("") or NULL string, but want to enforce
            minimum size in a layout group based on some initializing
            string and the current preferenced font, rather some fixed
            pixel or weighted minimum.  Added by request.

            Defaults to NULL.

            Applicability is (OM_NEW, OM_SET)

        BUTTON_Integer (int)  (V42)
            Set an integer value to display a numeric string. Highly useful
            for interconnect notifications from sliders, scrollers, etc.
            Added by request.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        BUTTON_BitMap (struct [BitMap](autodocs-3.5/include-graphics-gfx-h.md) *)  (V42)
            Specify a [BitMap](autodocs-3.5/include-graphics-gfx-h.md) to render in button, rather than image or
            text. Added by request, but use of bitmap.image is highly
            recommended for AmigaOS V39 and later.

            Defaults to NULL.

            Applicability is (OM_NEW, OM_SET)

        BUTTON_AnimButton (BOOL)  (V42)
            Is button animatable?  Use to turn animating on or off.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET)

        BUTTON_AnimImages (struct [Image](autodocs-3.5/include-intuition-intuition-h.md) *)  (V42)
            Sets an array of struct Images for animation

            Defaults to NULL.

            Applicability is (OM_NEW, OM_SET)

        BUTTON_SelAnimImages (struct [Image](autodocs-3.5/include-intuition-intuition-h.md) *)  (V42)
            Sets an array of alternate images for a selected state
            if used, must contain an equal number of images as the
            array used for BUTTON_AnimImages.  It's wise to use the
            same sized images too

            Defaults to NULL.

            Applicability is (OM_NEW, OM_SET)

        BUTTON_MaxAnimImages (LONG)  (V42)
            Number of images available in the arrays

            Defaults to 0.

            Applicability is (OM_NEW, OM_SET)

        BUTTON_AnimImageNumber (LONG)  (V42)
            Current image number in the array(s) to use the range of
            available frames is 0 .. MaxAnimImages-1

            Defaults to 0.

            Applicability is (OM_NEW, OM_SET)

        BUTTON_AddAnimImageNumber (ULONG)  (V42)
           Value to be added to the current image number counter
           the counter will wrap around at MaxAnimImages

            Applicability is (OM_SET, OM_UPDATE)

        BUTTON_SubAnimImageNumber (ULONG)  (V42)
            Value to be subtracted from the current image number counter
            the counter will wrap around when less than 0

            Applicability is (OM_SET, OM_UPDATE)

    BUGS
        Unfortunetly, this class shares the same filename and tag range
        as the button gadget released by David Junod of C=, released in
        the GI1.lha V42 beta archive on BIX, and later the AT DevCD.
        We admit it, we screwed up... but its not a majorly serious issue
        as this class is atleast 90% compatible.

        A few rarely, possibly never, used tags of the original are NOT
        currently supported. The usage of BUTTON_PushButton in ReAction is
        not totally compatible to Junod's. Ours acts like GA_ToggleSelect
        of Junod's.

        Please report any incompatibilities immediatly.
```

---

## See Also

- [DrawImageState — intuition.library](../autodocs/intuition.library.md#drawimagestate)
- [EraseRect — graphics.library](../autodocs/graphics.library.md#eraserect)
- [RawDoFmt — exec.library](../autodocs/exec.library.md#rawdofmt)
- [RectFill — graphics.library](../autodocs/graphics.library.md#rectfill)
- [Text — graphics.library](../autodocs/graphics.library.md#text)
- [TextLength — graphics.library](../autodocs/graphics.library.md#textlength)
