---
title: getscreenmode.gadget/--datasheet--
manual: autodocs-3.5
chapter: autodocs-3.5
section: getscreenmode-gadget-datasheet
functions: []
libraries: []
---

# getscreenmode.gadget/--datasheet--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       getscreenmode_gc -- create getscreenmode BOOPSI objects
   SUPERCLASS

       gadgetclass
   REQUIRES

       button.gadget
   DESCRIPTION

```c
       The getscreenmode gadget class is used to get screenmodes from a
       screenmode requester in an easy and consistent way.  It consists of
       two button gadgets, one read-only and one popscreenmode button,
       that are used to select the screenmode and show the result.

       Advantages that this class provides:

       > Consistent behaviour and look in all applications using this class
         instead of doing their own screenmode selection routines.

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
                 the popscreenmode button.

       GM_HELPTEST -- Overrides superclass, returns GMR_HELPHIT if within
                 the domain of the gadget.

       GM_GOACTIVE -- Passed to superclass, passed to popfile/drawer button.

       GM_HANDLEINPUT -- Overrides superclass, all input processed.

       GM_GOINACTIVE -- Passed to superclass, popfile/drawer button deactivated.

       GM_DOMAIN -- Returns GDOMAIN_MINIMUM and GDOMAIN_MAXIMUM dimensions.

       GM_KEYACTIVE -- Private method for keyboard control.

       GM_KEYINACTIVE -- Private method for keyboard control.

       GSM_REQUEST -- getscreenmode gadget method for invoking the screenmode requester.

    ATTRIBUTES
       Most of these tags operate the same as the ASLSM_#? tags in ASL library.
       See <asl.library/AslRequest> for detailed descriptions.

       GETSCREENMODE_TitleText (STRPTR)
          Title of the screenmode requester.

          Default to none.

          Applicability is (OM_NEW, OM_SET).

       GETSCREENMODE_Height (WORD)
          Height of the screenmode requester.

          Defaults to 200.

          Applicability is (OM_NEW, OM_SET, OM_GET).

       GETSCREENMODE_Width (WORD)
          Width of the screenmode requester.

          Defaults to 300.

          Applicability is (OM_NEW, OM_SET, OM_GET).

       GETSCREENMODE_LeftEdge (WORD)
          Left edge of the screenmode requester.

          Defaults to 30.

          Applicability is (OM_NEW, OM_SET, OM_GET).

       GETSCREENMODE_TopEdge (WORD)
          Top edge of the screenmode requester.

          Defaults to 20.

          Applicability is (OM_NEW, OM_SET, OM_GET).

       GETSCREENMODE_DisplayID (ULONG)
          Display id of screenmode.

          Defaults to 0 (LORES_KEY).

          Applicability is (OM_NEW, OM_SET, OM_GET, OM_NOTIFY).

       GETSCREENMODE_DisplayWidth (ULONG)
          Display width.

          Defaults to 640.

          Applicability is (OM_NEW, OM_SET, OM_GET, OM_NOTIFY).

       GETSCREENMODE_DisplayHeight (ULONG)
          Display height.

          Defaults to 200.

          Applicability is (OM_NEW, OM_SET, OM_GET, OM_NOTIFY).

       GETSCREENMODE_DisplayDepth (UWORD)
          Display depth.

          Defaults to 2.

          Applicability is (OM_NEW, OM_SET, OM_GET, OM_NOTIFY).

       GETSCREENMODE_OverscanType (UWORD)
          Type of overscan.

          Defaults to OSCAN_TEXT.

          Applicability is (OM_NEW, OM_SET, OM_GET, OM_NOTIFY).

       GETSCREENMODE_AutoScroll (BOOL)
          Autoscroll setting.

          Defaults to TRUE.

          Applicability is (OM_NEW, OM_SET, OM_NOTIFY).

       GETSCREENMODE_InfoOpened (BOOL)
          [Info](autodocs-3.5/dos-library-info-2.md) window initially opened?

          Defaults to FALSE.

          Applicability is (OM_NEW, OM_SET).

       GETSCREENMODE_InfoLeftEdge (WORD)
          [Info](autodocs-3.5/dos-library-info-2.md) window left edge.

          Defaults to 30.

          Applicability is (OM_NEW, OM_SET, OM_GET).

       GETSCREENMODE_InfoTopEdge (WORD)
          [Info](autodocs-3.5/dos-library-info-2.md) window top edge.

          Defaults to 20.

          Applicability is (OM_NEW, OM_SET, OM_GET).

       GETSCREENMODE_DoWidth (BOOL)
          Display Width gadget?

          Defaults to FALSE.

          Applicability is (OM_NEW, OM_SET).

       GETSCREENMODE_DoHeight (BOOL)
          Display Height gadget?

          Defaults to FALSE.

          Applicability is (OM_NEW, OM_SET).

       GETSCREENMODE_DoDepth (BOOL)
          Display Depth gadget?

          Defaults to FALSE.

          Applicability is (OM_NEW, OM_SET).

       GETSCREENMODE_DoOverscanType (BOOL)
          Display Overscan Type gadget?

          Defaults to FALSE.

          Applicability is (OM_NEW, OM_SET).

       GETSCREENMODE_DoAutoScroll (BOOL)
          Display AutoScroll gadget?

          Defaults to FALSE.

          Applicability is (OM_NEW, OM_SET).

       GETSCREENMODE_PropertyFlags (ULONG)
          Must have these Property flags.

          Defaults to DIPF_IS_WB.

          Applicability is (OM_NEW, OM_SET).

       GETSCREENMODE_PropertyMask (ULONG)
          Only these should be looked at.

          Defaults to DIPF_IS_WB.

          Applicability is (OM_NEW, OM_SET).

       GETSCREENMODE_MinWidth (ULONG)
          Minimum display width to allow.

          Defaults to 16.

          Applicability is (OM_NEW, OM_SET).

       GETSCREENMODE_MaxWidth (ULONG)
          Maximum display width to allow.

          Defaults to 16368.

          Applicability is (OM_NEW, OM_SET).

       GETSCREENMODE_MinHeight (ULONG)
          Minimum display height to allow.

          Defaults to 16.

          Applicability is (OM_NEW, OM_SET).

       GETSCREENMODE_MaxHeight (ULONG)
          Maximum display height to allow.

          Defaults to 16368.

          Applicability is (OM_NEW, OM_SET).

       GETSCREENMODE_MinDepth (ULONG)
          Minimum display depth to allow.

          Defaults to 1.

          Applicability is (OM_NEW, OM_SET).

       GETSCREENMODE_MaxDepth (ULONG)
          Maximum display depth to allow.

          Defaults to 24.

          Applicability is (OM_NEW, OM_SET).

       GETSCREENMODE_FilterFunc (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *)
          Function to filter mode id's.

          Defaults to none.

          Applicability is (OM_NEW, OM_SET).

       GETSCREENMODE_CustomSMList (struct [List](autodocs-3.5/include-exec-lists-h.md) *)
          Exec list of struct [DisplayMode](autodocs-3.5/include-libraries-asl-h.md).

          Defaults to none.

          Applicability is (OM_NEW, OM_SET).
```
