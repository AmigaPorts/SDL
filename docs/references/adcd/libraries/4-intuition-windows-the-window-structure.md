---
title: 4 Intuition Windows / The Window Structure
manual: libraries
chapter: libraries
section: 4-intuition-windows-the-window-structure
functions: []
libraries: []
---

# 4 Intuition Windows / The Window Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [Window](autodocs-2.0/includes-intuition-intuition-h.md) structure is the main Intuition data structure used to
represent a window.  For the most part, applications treat this structure
only as a handle.  Window operations are performed by calling system
functions that take Window as an argument instead of directly manipulating
fields within the structure.  However, there are some useful variables in
a Window structure which are discussed in this section.

   struct Window

```c
       {
       struct Window *NextWindow;
       WORD LeftEdge, TopEdge, Width, Height;
       WORD MouseY, MouseX;
       WORD MinWidth, MinHeight;
       UWORD MaxWidth, MaxHeight;
       ULONG Flags;
       struct Menu *MenuStrip;
       UBYTE *Title;
       struct Requester *FirstRequest, *DMRequest;
       WORD ReqCount;
       struct Screen *WScreen;
       struct RastPort *RPort;
       BYTE BorderLeft, BorderTop, BorderRight, BorderBottom;
       struct RastPort *BorderRPort;
       struct Gadget *FirstGadget;
       struct Window *Parent, *Descendant;
       UWORD *Pointer;
       BYTE PtrHeight, PtrWidth;
       BYTE XOffset, YOffset;
       ULONG IDCMPFlags;
       struct MsgPort *UserPort, *WindowPort;
       struct IntuiMessage *MessageKey;
       UBYTE DetailPen, BlockPen;
       struct Image *CheckMark;
       UBYTE *ScreenTitle;
       WORD GZZMouseX, GZZMouseY, GZZWidth, GZZHeight;
       UBYTE *ExtData;
       BYTE *UserData;
       struct Layer *WLayer;
       struct TextFont *IFont;
       ULONG MoreFlags;
       };
```
LeftEdge, TopEdge, Width and Height

    These variables reflect current position and size of the window.  If
    the user sizes or positions the window, then these values will
    change. The position of the window is relative to the upper left
    corner of the screen.
MouseX, MouseY, GZZMouseX, GZZMouseY

```c
    The current position of the Intuition pointer with respect to the
    window, whether or not this window is currently the active one.  For
    [GimmeZeroZero](libraries/4-window-types-gimmezerozero-window-type.md) windows, the GZZ variables reflect the position
    relative to the inner layer (see "Window Types" below).  For normal
    windows, the GZZ variables reflect the position relative to the
    window origin after taking the borders into account.
```
ReqCount

```c
    Contains a count of the number of requesters currently displayed in
    the window.  Do not rely on the value in this field, instead use
    [IDCMP_REQSET](libraries/9-event-message-classes-and-flags-requester-flags.md) and [IDCMP_REQCLEAR](libraries/9-event-message-classes-and-flags-requester-flags.md) to indirectly determine the number of
    open requesters in the window.
```
WScreen

```c
    A pointer to the [Screen](libraries/3-screen-data-structures-other-screen-data-structures.md) structure of the screen on which this window
    was opened.
```
RPort

```c
    A pointer to this window's [RastPort](libraries/4-intuition-windows-basic-window-structures-and-functions.md) structure.  Use this RastPort
    pointer to render into your window with Intuition or graphics library
    rendering functions.
```
BorderLeft, BorderTop, BorderRight, BorderBottom

    These variables describe the actual size of the window borders. The
    border size is not changed after the window is opened.
BorderRPort

```c
    With [GimmeZeroZero](libraries/4-window-types-gimmezerozero-window-type.md) windows, this variable points to the [RastPort](libraries/4-intuition-windows-basic-window-structures-and-functions.md) for
    the outer layer, in which the border gadgets are kept.
```
UserData

    This pointer is available for application use.  The program can
    attach a data block to this window by setting this variable to point
    to the data.
For a commented listing of the [Window](autodocs-2.0/includes-intuition-intuition-h.md) structure see
<intuition/[intuition.h](autodocs-2.0/includes-intuition-intuition-h.md)> in the Amiga ROM Kernel Reference Manual: Includes
and Autodocs.

