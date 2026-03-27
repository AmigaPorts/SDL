---
title: getfont.gadget/--datasheet--
manual: autodocs-3.5
chapter: autodocs-3.5
section: getfont-gadget-datasheet
functions: []
libraries: []
---

# getfont.gadget/--datasheet--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       getfont_gc -- create getfont BOOPSI objects
   SUPERCLASS

       gadgetclass
   REQUIRES

       button.gadget
   DESCRIPTION

```c
       The getfont gadget class is used to get fonts and font attributes from a
       font requester in an easy and consistent way.  It consists of two button
       gadgets, one read-only and one popfont button, that are used to select
       the font and show the result.

       Advantages that this class provides:

       > Consistent behaviour and look in all applications using this class
         instead of doing their own font selection routines.

       > Easy to use.


    METHODS
       OM_NEW -- Passed to superclass, defaults set, then OM_SET. Children
                 created.

       OM_SET -- Passed to superclass, custom tags set.

       OM_GET -- [Custom](autodocs-3.5/include-hardware-custom-h.md) tag returned or passed to superclass.

       OM_UPDATE -- Passed to superclass, options set then rendered.

       OM_DISPOSE -- Children disposed of, then passed to superclass.

       GM_RENDER -- Passed to superclass, then children are rendered.

       GM_HITTEST -- Overrides superclass, returns GMR_GADGETHIT if within
                 the popfile/drawer button.

       GM_HELPTEST -- Overrides superclass, returns GMR_HELPHIT if within
                 the domain of the gadget.

       GM_GOACTIVE -- Passed to superclass, passed to popfile/drawer button.

       GM_HANDLEINPUT -- Overrides superclass, all input processed.

       GM_GOINACTIVE -- Passed to superclass, popfile/drawer button deactivated.

       GM_DOMAIN -- Returns GDOMAIN_MINIMUM and GDOMAIN_MAXIMUM dimensions.

       GM_KEYACTIVE -- Private method for keyboard control.

       GM_KEYINACTIVE -- Private method for keyboard control.

       GFONT_REQUEST -- getfont gadget method for invoking the font requester.

    ATTRIBUTES
       Most of these tags operate the same as the ASLFO_#? tags in ASL library.
       See <asl.library/AslRequest> for detailed descriptions.

       GETFONT_TitleText (STRPTR)
          [Requester](autodocs-3.5/include-intuition-intuition-h.md) title text.

          Defaults to NULL.

          Applicability is (OM_NEW, OM_SET).

       GETFONT_TextAttr (struct [TextAttr](autodocs-3.5/include-graphics-text-h.md) *)
          Font to show in the gadget. The textattr.ta_Style, textattr.ta_Name
          and textattr.ta_YSize fields are used by the font requester
          as default values in OM_NEW and contain the information about the
          font in the other methods.

          Defaults to none.

          Applicability is (OM_NEW, OM_SET, OM_GET, OM_NOTIFY).

       GETFONT_DoFrontPen (BOOL)
          Do front pen.

          Defaults to FALSE.

          Applicability is (OM_NEW, OM_SET).

       GETFONT_DoBackPen (BOOL)
          Do back pen.

          Default to FALSE.

          Applicability is (OM_NEW, OM_SET).

       GETFONT_DoStyle (BOOL)
          Do style.

          Defaults to FALSE.

          Applicability is (OM_NEW, OM_SET).

       GETFONT_DoDrawMode (BOOL)
          Do draw mode.

          Defaults to FALSE.

          Applicability is (OM_NEW, OM_SET).

       GETFONT_MinHeight (UWORD)
          Minimum font height.

          Defaults to 6.

          Applicability is (OM_NEW, OM_SET).

       GETFONT_MaxHeight (UWORD)
          Maximum font height.

          Defaults to 20.

          Applicability is (OM_NEW, OM_SET).

       GETFONT_FixedWidthOnly (BOOL)
          Only show fixed width fonts.

          Defaults to FALSE.

          Applicability is (OM_NEW, OM_SET).

       GETFONT_Height (WORD)
          Height of the font requester.

          Defaults to 200.

          Applicability is (OM_NEW, OM_SET, OM_GET).

       GETFONT_Width (WORD)
          Width of the font requester.

          Defaults to 300.

          Applicability is (OM_NEW, OM_SET, OM_GET).

       GETFONT_LeftEdge (WORD)
          Left edge of the font requester.

          Defaults to 30.

          Applicability is (OM_NEW, OM_SET, OM_GET).

       GETFONT_TopEdge (WORD)
          Top edge of the font requester.

          Defaults to 20.

          Applicability is (OM_NEW, OM_SET, OM_GET).

       GETFONT_FrontPen (UBYTE)
          Front pen.

          Defaults to 1.

          Applicability is (OM_NEW, OM_SET, OM_GET, OM_NOTIFY).

       GETFONT_BackPen (UBYTE)
          Back pen.

          Defaults to 0.

          Applicability is (OM_NEW, OM_SET, OM_GET, OM_NOTIFY).

       GETFONT_DrawMode (UBYTE)
          [Draw](autodocs-3.5/graphics-library-draw-2.md) mode.

          Defaults to JAM1.

          Applicability is (OM_NEW, OM_SET, OM_GET, OM_NOTIFY).

       GETFONT_MaxFrontPen (UBYTE)
          Max number of colors in front palette.

          Defaults to 255.

          Applicability is (OM_NEW, OM_SET).

       GETFONT_MaxBackPen (UBYTE)
          Max number of colors in back palette.

          Defaults to 255.

          Applicability is (OM_NEW, OM_SET).

       GETFONT_ModeList (STRPTR *)
          Substitute list for drawmodes.

          Defaults to none.

          Applicability is (OM_NEW, OM_SET).

       GETFONT_FrontPens (UBYTE *)
          Color table for front pen palette.

          Defaults to none.

          Applicability is (OM_NEW, OM_SET).

       GETFONT_BackPens (UBYTE *)
          Color table for back pen palette.

          Defaults to none.

          Applicability is (OM_NEW, OM_SET).

       GETFONT_SoftStyle (UBYTE)
          SoftStyle, provided only for making mapping to button.gadget
          easier. Textattr.ta_Style in the GETFONT_TextAttr attribute
          will provide the style in other cases.

          Applicability is (OM_GET, OM_NOTIFY).
```
