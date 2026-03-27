# 4 / Window Attributes / Window Attribute Tags


WA_Left, WA_Top, WA_Width and WA_Height

```c
    Describe where the window will first appear on the screen and how
    large it will be initially. These dimensions are relative to the top
    left corner of the screen, which has the coordinates (0,0).

    WA_Left is the initial x position, or offset, from the left edge of
    the screen.  The leftmost pixel is pixel 0, and values increase to
    the right.  Equivalent to [NewWindow](../Libraries_Manual_guide/node0102.html#line8).LeftEdge.

    WA_Top is the initial y position, or offset, from the top edge of the
    screen.  The topmost pixel is pixel 0, and values increase to the
    bottom.  Equivalent to [NewWindow](../Libraries_Manual_guide/node0102.html#line8).TopEdge.

    WA_Width is the initial window width in pixels.  Equivalent to
    [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Width.

    WA_Height is the initial window height in lines.  Equivalent to
    [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Height.
```
WA_DetailPen and WA_BlockPen

```c
    WA_DetailPen specifies the pen number for the rendering of window
    details like gadgets or text in the title bar.  WA_BlockPen specifies
    the pen number for window block fills, like the title bar.  These
    pens are also used for rendering menus.  Equivalent to
    [NewWindow](../Libraries_Manual_guide/node0102.html#line8).DetailPen and NewWindow.BlockPen.

    The specific color associated with each pen number depends on the
    screen.  Specifying -1 for these values sets the window's detail and
    block pen the same as the screen's detail and block pen.

    Detail pen and block pen have largely been replaced starting with V36
    by the pen array in the [DrawInfo](../Libraries_Manual_guide/node00DE.html#line6) structure.  See the section on
    "[DrawInfo and the 3D Look](../Libraries_Manual_guide/node00EC.html)" in the "Intuition Screens" chapter for
    more information.
```
WA_IDCMP

```c
    IDCMP flags tell Intuition what user input events the application
    wants to be notified about.  The IDCMP flags are listed and described
    in the [OpenWindowTagList()](../Includes_and_Autodocs_2._guide/node023A.html) description in the Amiga ROM Kernel
    Reference Manual: Includes and Autodocs and in the chapter
    "[Intuition Input and Output Methods](../Libraries_Manual_guide/node01E0.html)" in this book.  Equivalent to
    [NewWindow](../Libraries_Manual_guide/node0102.html#line8).IDCMPFlags.

    If any of these flags are set, Intuition creates a pair of message
    ports for the window (one internal to Intuition and one used by the
    application). These ports are for handling messages about user input
    events.  If WA_IDCMP is NULL or unspecified, no IDCMP is created for
    this window.

    The [ModifyIDCMP()](../Libraries_Manual_guide/node01E3.html#line5) function can be used to change the window's IDCMP
    flags after it is open.
```
WA_Gadgets

```c
    A pointer to the first in the linked list of [Gadget](../Libraries_Manual_guide/node0149.html) structures that
    are to be included in this window.  These gadgets are application
    gadgets, not system gadgets.  See the "[Intuition Gadgets](../Libraries_Manual_guide/node0132.html)" chapter for
    more information.  Equivalent to [NewWindow](../Libraries_Manual_guide/node0102.html#line8).FirstGadget.
```
WA_Checkmark

```c
    A pointer to an [Image](../Libraries_Manual_guide/node01BA.html) structure, which is to be used as the checkmark
    image in this window's menus.  To use the default checkmark, do not
    specify this tag or set this field to NULL.  Equivalent to
    [NewWindow](../Libraries_Manual_guide/node0102.html#line8).CheckMark.
```
WA_Title

```c
    A pointer to a NULL terminated text string, which is used as the
    window title and is displayed in the window's title bar.

    Intuition draws the text using the colors defined in the [DrawInfo](../Libraries_Manual_guide/node00DE.html#line6) pen
    array (DrawInfo.dri_Pens) and displays as much as possible of the
    window title, depending upon the current width of the title bar.
    Equivalent to [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Title.  See the section on
    "[DrawInfo and the 3D Look](../Libraries_Manual_guide/node00EC.html)" in the "Intuition Screens" chapter for
    more information on the pen array.

    The title is rendered in the screen's default font.

    A title bar is added to the window if any of the properties
    [WA_DragBar](../Libraries_Manual_guide/node0125.html#line23) (WFLG_DRAGBAR), [WA_DepthGadget](../Libraries_Manual_guide/node0125.html#line29) (WFLG_DEPTHGADGET),
    [WA_CloseGadget](../Libraries_Manual_guide/node0125.html#line36) (WFLG_CLOSEGADGET) or WA_Zoom are specified, or if
    text is specified for a window title.  If no text is provided for the
    title, but one or more of these system gadgets are specified, the
    title bar will be blank.  Equivalent to [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Title.
```
WA_ScreenTitle

```c
    A pointer to a NULL terminated text string, which is used as the
    screen title and is displayed, when the window is active, in the
    screen's title bar.  After the screen has been opened the screen's
    title may be changed by calling [SetWindowTitles()](../Libraries_Manual_guide/node012A.html) (which is the only
    method of setting the window's screen title prior to V36).
```
WA_CustomScreen

```c
    A pointer to the [Screen](../Libraries_Manual_guide/node00DE.html#line6) structure of a screen created by this
    application.  The window will be opened on this screen.  The custom
    screen must already be opened when the [OpenWindowTagList()](../Libraries_Manual_guide/node0103.html) call is
    made.  Equivalent to [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Screen, also implies NewWindow.Type of
    CUSTOMSCREEN.
```
WA_MinWidth, WA_MinHeight, WA_MaxWidth and WA_MaxHeight

```c
    These tags set the minimum and maximum values to which the user may
    size the window.  If the flag [WFLG_SIZEGADGET](../Libraries_Manual_guide/node0125.html#line4) is not set, then
    these variables are ignored.  Values are measured in pixels.  Use
    (~0) for the WA_MaxWidth (WA_MaxHeight) to allow for a window as wide
    (tall) as the screen.  This is the complete screen, not the visible
    part or display clip.

    Setting any of these variables to 0, will take the setting for that
    dimension from its initial value.  For example, setting MinWidth to
    0, will make the minimum width of this window equal to the initial
    width of the window.

    Equivalent to [NewWindow](../Libraries_Manual_guide/node0102.html#line8).MinWidth, NewWindow.MinHeight,
    NewWindow.MaxWidth and NewWindow.MaxHeight.  Use the [WindowLimits()](../Libraries_Manual_guide/node010B.html)
    function to change window size limits after the window is opened.
```
WA_InnerWidth and WA_InnerHeight

```c
    Specify the dimensions of the interior region of the window, i.e.,
    inside the border, independent of the border widths.  When using
    WA_InnerWidth and WA_InnerHeight an application will probably want to
    set [WA_AutoAdjust](../Libraries_Manual_guide/node0125.html#line135).
```
WA_PubScreen

```c
    Open the window as a visitor window on the public screen whose
    address is in the ti_Data field of the WA_PubScreen [TagItem](../Libraries_Manual_guide/node0102.html#line8).  To
    ensure that this screen remains open until [OpenWindowTagList()](../Libraries_Manual_guide/node0103.html) has
    completed, the application must either be the screen's owner, have a
    window open on the screen, or use [LockPubScreen()](../Libraries_Manual_guide/node00E6.html#line34).  Setting this tag
    implies screen type of PUBLICSCREEN.
```
WA_PubScreenName

```c
    Declares that the window is to be opened as a visitor on the public
    screen whose name is pointed to by the ti_Data field of the
    WA_PubScreenName [TagItem](../Libraries_Manual_guide/node0102.html#line8).  The [OpenWindowTagList()](../Libraries_Manual_guide/node0103.html) call will fail if
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
    Pointer to an array of four WORDs, the initial [LeftEdge](../Libraries_Manual_guide/node0121.html#line42), [TopEdge](../Libraries_Manual_guide/node0121.html#line42),
    [Width](../Libraries_Manual_guide/node0121.html#line32) and [Height](../Libraries_Manual_guide/node0121.html#line32) values for the alternate zoom position and size.  It
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
    The [SetMouseQueue()](../Libraries_Manual_guide/node012B.html#line27) function will change this limit after the window
    is opened.
```
WA_RptQueue

    An initial value of repeat key backlog limit for this window.
