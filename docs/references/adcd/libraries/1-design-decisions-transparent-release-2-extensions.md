---
title: 1 / / Design Decisions / Transparent Release 2 Extensions
manual: libraries
chapter: libraries
section: 1-design-decisions-transparent-release-2-extensions
functions: [AddGadget, AvailFonts, OpenDiskFont, OpenScreen, OpenWindow]
libraries: [diskfont.library, intuition.library]
---

# 1 / / Design Decisions / Transparent Release 2 Extensions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To provide [Release 2](libraries/1-operating-system-versions-about-release-2.md) enhancements while remaining compatible with the
older 1.3 [version](libraries/1-programming-in-the-amiga-environment-operating-system.md) of the OS, several familiar 1.3 system structures have
been extended to include an optional pointer to additional information.
The new extended versions of such structures are generally defined in the
same include file as the original structure.  These extended structures
are passed to the same 1.3 system functions as the unextended structure
(e.g., [OpenWindow()](libraries/4-basic-window-structures-and-functions-opening-a-window.md), [OpenScreen()](libraries/3-intuition-screens-custom-screen-functions.md), [AddGadget()](autodocs-2.0/intuition-library-addgadget.md), [OpenDiskFont()](libraries/29-the-text-function-choosing-the-font.md)).  The
existence of the extended information is signified by setting a new flag
bit in the structure.  (In one case, [PROPNEWLOOK](libraries/5-proportional-gadget-type-new-3d-look-proportional-gadgets.md), only the flag bit itself
is significant).  These extensions are transparent to previous versions of
the operating system.  Only the Release 2 operating system will recognize
the bit and act on the extended information.

The table below lists the flag bit for each structure to specify that
extended information is present.


Original  Extended   Flag Field  Flag Bit           Defined In
--------  --------   ----------  --------           ----------
NewScreen ExtNewScreen Type      NS_EXTENDED       <intuition/[screens.h](autodocs-2.0/includes-intuition-screens-h.md)>
NewWindow ExtNewWindow Flags     WFLG_NW_EXTENDED  <intuition/[intuition.h](autodocs-2.0/includes-intuition-intuition-h.md)>
Gadget    Gadget       Flags     GFLG_STRINGEXTEND <intuition/intuition.h>
PropInfo  PropInfo     Flags     PROPNEWLOOK       <intuition/intuition.h
TextAttr  TTextAttr    tta_Style FSF_TAGGED        <graphics/[text.h](autodocs-2.0/includes-graphics-text-h.md)>


Through the use of such extensions, applications can request special
[Release 2](libraries/1-operating-system-versions-about-release-2.md) features in a 1.3-compatible manner.  When the application is
run on a Release 2 machine, the enhanced capabilities will be active.

The enhancements available through these extensions include:


   Screen: Overscan, 3D Look (SA_Pens), public screens, PAL/NTSC, new modes
   Window: Autoadjust sizing, inner dimensions, menu help
   Gadget: Control of font, pens, and editing of string gadgets
 PropInfo: Get 3D Look proportional gadgets when running under Release 2
TTextAttr: Control width of scaled fonts


Extensible longword arrays called TagItem lists are used to specify the
extended information for many of these structures.  Tag lists provide an
open-ended and backwards-compatible method of growing system structures by
storing all new specifications in an extendible array of longwords pairs.

Another transparent [Release 2](libraries/1-operating-system-versions-about-release-2.md) extension is the diskfont library's ability
to [scale](libraries/29-about-amiga-fonts-system-fonts-in-release-2.md) bitmap and outline fonts to arbitrary sizes and the availability
of [scalable outline fonts](libraries/29-about-amiga-fonts-system-fonts-in-release-2.md).  Make sure that these new scalable fonts are
available to your application by not setting the [FPF_DESIGNED](libraries/29-the-text-function-choosing-the-font.md) flag for
[AvailFonts()](libraries/29-graphics-library-and-text-what-fonts-are-available.md) or [OpenDiskFont()](libraries/29-the-text-function-choosing-the-font.md).  Allow the user to create new font sizes
by providing a way for her to manually enter the desired font size (the
1.3 OS returns the closest size, Release 2 returns the requested size).

See the [Intuition](libraries/user-interface-libraries.md) and [graphics](libraries/graphics-libraries.md) library chapters, and the [include file](autodocs-2.0/includes-and-autodocs-2-0.md)
comments for additional information.  See the "[Utility Library](libraries/37-utility-library-tags.md)" chapter
for more information on TagItems and tag lists.

---

## See Also

- [AddGadget — intuition.library](../autodocs/intuition.library.md#addgadget)
- [AvailFonts — diskfont.library](../autodocs/diskfont.library.md#availfonts)
- [OpenDiskFont — diskfont.library](../autodocs/diskfont.library.md#opendiskfont)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
