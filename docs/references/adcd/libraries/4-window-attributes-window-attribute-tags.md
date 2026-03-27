---
title: 4 / Window Attributes / Window Attribute Tags
manual: libraries
chapter: libraries
section: 4-window-attributes-window-attribute-tags
functions: [LockPubScreen, ModifyIDCMP, OpenWindowTagList, SetMouseQueue, SetWindowTitles, WindowLimits]
libraries: [intuition.library]
---

# 4 / Window Attributes / Window Attribute Tags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

WA_Left, WA_Top, WA_Width and WA_Height

```c
    Describe where the window will first appear on the screen and how
    large it will be initially. These dimensions are relative to the top
    left corner of the screen, which has the coordinates (0,0).

    WA_Left is the initial x position, or offset, from the left edge of
    the screen.  The leftmost pixel is pixel 0, and values increase to
    the right.  Equivalent to [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).LeftEdge.

    WA_Top is the initial y position, or offset, from the top edge of the
    screen.  The topmost pixel is pixel 0, and values increase to the
    bottom.  Equivalent to [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).TopEdge.

    WA_Width is the initial window width in pixels.  Equivalent to
    [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Width.

    WA_Height is the initial window height in lines.  Equivalent to
    [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Height.
```
WA_DetailPen and WA_BlockPen

```c
    WA_DetailPen specifies the pen number for the rendering of window
    details like gadgets or text in the title bar.  WA_BlockPen specifies
    the pen number for window block fills, like the title bar.  These
    pens are also used for rendering menus.  Equivalent to
    [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).DetailPen and NewWindow.BlockPen.

    The specific color associated with each pen number depends on the
    screen.  Specifying -1 for these values sets the window's detail and
    block pen the same as the screen's detail and block pen.

    Detail pen and block pen have largely been replaced starting with V36
    by the pen array in the [DrawInfo](libraries/3-screen-data-structures-other-screen-data-structures.md) structure.  See the section on
    "[DrawInfo and the 3D Look](libraries/3-drawinfo-and-the-3d-look-the-pen-specification-in-drawinfo.md)" in the "Intuition Screens" chapter for
    more information.
```
WA_IDCMP

```c
    IDCMP flags tell Intuition what user input events the application
    wants to be notified about.  The IDCMP flags are listed and described
    in the [OpenWindowTagList()](autodocs-2.0/intuition-library-openwindowtaglist.md) description in the Amiga ROM Kernel
    Reference Manual: Includes and Autodocs and in the chapter
    "[Intuition Input and Output Methods](libraries/9-event-message-classes-and-flags-window-flags.md)" in this book.  Equivalent to
    [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).IDCMPFlags.

    If any of these flags are set, Intuition creates a pair of message
    ports for the window (one internal to Intuition and one used by the
    application). These ports are for handling messages about user input
    events.  If WA_IDCMP is NULL or unspecified, no IDCMP is created for
    this window.

    The [ModifyIDCMP()](libraries/9-intuition-input-and-output-methods-function-reference.md) function can be used to change the window's IDCMP
    flags after it is open.
```
WA_Gadgets

```c
    A pointer to the first in the linked list of [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structures that
    are to be included in this window.  These gadgets are application
    gadgets, not system gadgets.  See the "[Intuition Gadgets](libraries/5-about-gadgets-application-gadgets.md)" chapter for
    more information.  Equivalent to [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).FirstGadget.
```
WA_Checkmark

```c
    A pointer to an [Image](libraries/8-creating-images-image-structure.md) structure, which is to be used as the checkmark
    image in this window's menus.  To use the default checkmark, do not
    specify this tag or set this field to NULL.  Equivalent to
    [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).CheckMark.
```
WA_Title

```c
    A pointer to a NULL terminated text string, which is used as the
    window title and is displayed in the window's title bar.

    Intuition draws the text using the colors defined in the [DrawInfo](libraries/3-screen-data-structures-other-screen-data-structures.md) pen
    array (DrawInfo.dri_Pens) and displays as much as possible of the
    window title, depending upon the current width of the title bar.
    Equivalent to [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Title.  See the section on
    "[DrawInfo and the 3D Look](libraries/3-drawinfo-and-the-3d-look-the-pen-specification-in-drawinfo.md)" in the "Intuition Screens" chapter for
    more information on the pen array.

    The title is rendered in the screen's default font.

    A title bar is added to the window if any of the properties
    [WA_DragBar](libraries/4-window-attributes-boolean-window-attribute-tags.md) (WFLG_DRAGBAR), [WA_DepthGadget](libraries/4-window-attributes-boolean-window-attribute-tags.md) (WFLG_DEPTHGADGET),
    [WA_CloseGadget](libraries/4-window-attributes-boolean-window-attribute-tags.md) (WFLG_CLOSEGADGET) or WA_Zoom are specified, or if
    text is specified for a window title.  If no text is provided for the
    title, but one or more of these system gadgets are specified, the
    title bar will be blank.  Equivalent to [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Title.
```
WA_ScreenTitle

```c
    A pointer to a NULL terminated text string, which is used as the
    screen title and is displayed, when the window is active, in the
    screen's title bar.  After the screen has been opened the screen's
    title may be changed by calling [SetWindowTitles()](libraries/4-other-window-functions-changing-the-window-or-screen-title.md) (which is the only
    method of setting the window's screen title prior to V36).
```
WA_CustomScreen

```c
    A pointer to the [Screen](libraries/3-screen-data-structures-other-screen-data-structures.md) structure of a screen created by this
    application.  The window will be opened on this screen.  The custom
    screen must already be opened when the [OpenWindowTagList()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) call is
    made.  Equivalent to [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Screen, also implies NewWindow.Type of
    CUSTOMSCREEN.
```
WA_MinWidth, WA_MinHeight, WA_MaxWidth and WA_MaxHeight

```c
    These tags set the minimum and maximum values to which the user may
    size the window.  If the flag [WFLG_SIZEGADGET](libraries/4-window-attributes-boolean-window-attribute-tags.md) is not set, then
    these variables are ignored.  Values are measured in pixels.  Use
    (~0) for the WA_MaxWidth (WA_MaxHeight) to allow for a window as wide
    (tall) as the screen.  This is the complete screen, not the visible
    part or display clip.

    Setting any of these variables to 0, will take the setting for that
    dimension from its initial value.  For example, setting MinWidth to
    0, will make the minimum width of this window equal to the initial
    width of the window.

    Equivalent to [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).MinWidth, NewWindow.MinHeight,
    NewWindow.MaxWidth and NewWindow.MaxHeight.  Use the [WindowLimits()](libraries/4-window-structures-and-functions-changing-window-size.md)
    function to change window size limits after the window is opened.
```
WA_InnerWidth and WA_InnerHeight

```c
    Specify the dimensions of the interior region of the window, i.e.,
    inside the border, independent of the border widths.  When using
    WA_InnerWidth and WA_InnerHeight an application will probably want to
    set [WA_AutoAdjust](libraries/4-window-attributes-boolean-window-attribute-tags.md).
```
WA_PubScreen

```c
    Open the window as a visitor window on the public screen whose
    address is in the ti_Data field of the WA_PubScreen [TagItem](libraries/4-intuition-windows-basic-window-structures-and-functions.md).  To
    ensure that this screen remains open until [OpenWindowTagList()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) has
    completed, the application must either be the screen's owner, have a
    window open on the screen, or use [LockPubScreen()](libraries/3-intuition-screens-public-screen-functions.md).  Setting this tag
    implies screen type of PUBLICSCREEN.
```
WA_PubScreenName

```c
    Declares that the window is to be opened as a visitor on the public
    screen whose name is pointed to by the ti_Data field of the
    WA_PubScreenName [TagItem](libraries/4-intuition-windows-basic-window-structures-and-functions.md).  The [OpenWindowTagList()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) call will fail if
    it cannot obtain a lock on the named public screen and no fall back
    name (WA_PubScreenFallBack) is specified.  Setting this tag implies
    screen type of PUBLICSCREEN.
```
WA_PubScreenFallBack

```c
    A Boolean, specifies whether a visitor window should "fall back" to
    the default public screen (or Workbench) if the named public screen
    isn't available This tag is only meaningful when used in conjunction
    with WA_PubScreenName.
```
WA_Zoom

```c
    Pointer to an array of four WORDs, the initial [LeftEdge](libraries/4-intuition-windows-the-window-structure.md), [TopEdge](libraries/4-intuition-windows-the-window-structure.md),
    [Width](libraries/4-intuition-windows-the-window-structure.md) and [Height](libraries/4-intuition-windows-the-window-structure.md) values for the alternate zoom position and size.  It
    also specifies that the application wants a zoom gadget for the
    window, whether or not it has a sizing gadget.

    A zoom gadget is always supplied to a window if it has both depth and
    sizing gadgets.  This tag allows the application to open a window
    with a zoom gadget when the window does not have both the depth and
    sizing gadgets.
```
WA_MouseQueue

```c
    An initial value for the mouse message backlog limit for this window.
    The [SetMouseQueue()](libraries/4-other-window-functions-changing-message-queue-limits.md) function will change this limit after the window
    is opened.
```
WA_RptQueue

    An initial value of repeat key backlog limit for this window.

---

## See Also

- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [ModifyIDCMP — intuition.library](../autodocs/intuition.library.md#modifyidcmp)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
- [SetMouseQueue — intuition.library](../autodocs/intuition.library.md#setmousequeue)
- [SetWindowTitles — intuition.library](../autodocs/intuition.library.md#setwindowtitles)
- [WindowLimits — intuition.library](../autodocs/intuition.library.md#windowlimits)
