# 1 / / Design Decisions / Transparent Release 2 Extensions


To provide [Release 2](../Libraries_Manual_guide/node0015.html) enhancements while remaining compatible with the
older 1.3 [version](../Libraries_Manual_guide/node0014.html) of the OS, several familiar 1.3 system structures have
been extended to include an optional pointer to additional information.
The new extended versions of such structures are generally defined in the
same include file as the original structure.  These extended structures
are passed to the same 1.3 system functions as the unextended structure
(e.g., [OpenWindow()](../Libraries_Manual_guide/node0103.html), [OpenScreen()](../Libraries_Manual_guide/node00DF.html), [AddGadget()](../Includes_and_Autodocs_2._guide/node01FC.html), [OpenDiskFont()](../Libraries_Manual_guide/node03D6.html#line5)).  The
existence of the extended information is signified by setting a new flag
bit in the structure.  (In one case, [PROPNEWLOOK](../Libraries_Manual_guide/node0154.html), only the flag bit itself
is significant).  These extensions are transparent to previous versions of
the operating system.  Only the Release 2 operating system will recognize
the bit and act on the extended information.

The table below lists the flag bit for each structure to specify that
extended information is present.


Original  Extended   Flag Field  Flag Bit           Defined In
--------  --------   ----------  --------           ----------
NewScreen ExtNewScreen Type      NS_EXTENDED       <intuition/[screens.h](../Includes_and_Autodocs_2._guide/node00DD.html)>
NewWindow ExtNewWindow Flags     WFLG_NW_EXTENDED  <intuition/[intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html)>
Gadget    Gadget       Flags     GFLG_STRINGEXTEND <intuition/intuition.h>
PropInfo  PropInfo     Flags     PROPNEWLOOK       <intuition/intuition.h
TextAttr  TTextAttr    tta_Style FSF_TAGGED        <graphics/[text.h](../Includes_and_Autodocs_2._guide/node00A8.html)>


Through the use of such extensions, applications can request special
[Release 2](../Libraries_Manual_guide/node0015.html) features in a 1.3-compatible manner.  When the application is
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

Another transparent [Release 2](../Libraries_Manual_guide/node0015.html) extension is the diskfont library's ability
to [scale](../Libraries_Manual_guide/node03D4.html) bitmap and outline fonts to arbitrary sizes and the availability
of [scalable outline fonts](../Libraries_Manual_guide/node03D4.html#line8).  Make sure that these new scalable fonts are
available to your application by not setting the [FPF_DESIGNED](../Libraries_Manual_guide/node03D6.html#line70) flag for
[AvailFonts()](../Libraries_Manual_guide/node03DD.html) or [OpenDiskFont()](../Libraries_Manual_guide/node03D6.html#line5).  Allow the user to create new font sizes
by providing a way for her to manually enter the desired font size (the
1.3 OS returns the closest size, Release 2 returns the requested size).

See the [Intuition](../Libraries_Manual_guide/node0002.html) and [graphics](../Libraries_Manual_guide/node0004.html) library chapters, and the [include file](../Includes_and_Autodocs_2._guide/node0000.html)
comments for additional information.  See the "[Utility Library](../Libraries_Manual_guide/node0496.html)" chapter
for more information on TagItems and tag lists.

