# 4 / Window Attributes / Boolean Window Attribute Tags


These boolean window tags are alternatives to the [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Flags bit
fields with similar names.  Unlike the tags discussed above, the ti_Data
field of these [TagItems](../Libraries_Manual_guide/node0102.html#line8) is set to either TRUE or FALSE.

WA_SizeGadget

```c
    Specifying this flag tells Intuition to add a sizing gadget to the
    window.  Intuition places the sizing gadget in the lower right corner
    of the window.  By default, the right border is adjusted to
    accommodate the sizing gadget, but the application can specify one of
    the following two flags to change this behavior.  The WFLG_SIZEBRIGHT
    flag puts the sizing gadget in the right border.  The
    WFLG_SIZEBBOTTOM flag puts the sizing gadget in the bottom border.
    Both flags may be specified, placing the gadget in both borders.
    Equivalent to [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Flags WFLG_SIZEGADGET.
```
WA_SizeBRight

```c
    Place the size gadget in the right border.  Equivalent to
    [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Flags WFLG_SIZEBRIGHT.
```
WA_SizeBBottom

```c
    Place the size gadget in the bottom border.  Equivalent to
    [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Flags WFLG_SIZEBBOTTOM.
```
WA_DragBar

```c
    This flag turns the entire title bar of the window into a drag
    gadget, allowing the user to position the window by clicking in the
    title bar and dragging the mouse.  Equivalent to [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Flags
    WFLG_DRAGBAR.
```
WA_DepthGadget

```c
    Setting this flag adds a depth gadget to the window.  This allows the
    user to change the window's depth arrangement with respect to other
    windows on the screen.  Intuition places the depth gadget in the
    upper right corner of the window.  Equivalent to [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Flags
    WFLG_DEPTHGADGET.
```
WA_CloseGadget

```c
    Setting this flag attaches a close gadget to the window.  When the
    user selects this gadget, Intuition transmits a message to the
    application.  It is up to the application to close the window with a
    [CloseWindow()](../Libraries_Manual_guide/node0105.html) call. Intuition places the close gadget in the upper
    left corner of the window. Equivalent to [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Flags
    WFLG_CLOSEGADGET.
```
WA_ReportMouse

```c
    Send mouse movement events to the window as x,y coordinates.  Also
    see the description of the IDCMP flag [IDCMP_MOUSEMOVE](../Libraries_Manual_guide/node01DC.html#line23), in the chapter
    "Intuition Input and Output Methods."  Equivalent to [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Flags
    WFLG_REPORTMOUSE.

    The WFLG_REPORTMOUSE flag in the Flags field of the [Window](../Libraries_Manual_guide/node0102.html#line8) structure
    may be modified on the fly  by the program.  Changing this flag must
    be done as an atomic operation.  Most compilers generate atomic code
    for operations such as window->flags |= WFLG_REPORTMOUSE or
    window->flags &= ~WFLG_REPORTMOUSE.  If you are unsure of getting an
    atomic operation from your compiler, you may wish to do this
    operation in assembler, or bracket the code with a [Forbid()/Permit()](../Libraries_Manual_guide/node02D0.html#line10)
    pair.

    The use of the [ReportMouse()](../Libraries_Manual_guide/node01EC.html#line14) function is strongly discouraged, due to
    historic confusion over the parameter ordering.
```
WA_NoCareRefresh

```c
    This window does not want [IDCMP_REFRESHWINDOW](../Libraries_Manual_guide/node01E0.html#line7) events.  Set this flag
    to prevent the window from receiving refresh window messages.
    Equivalent to [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Flags WFLG_NOCAREREFRESH.  Intuition will
    manage [BeginRefresh()](../Libraries_Manual_guide/node011E.html) and [EndRefresh()](../Libraries_Manual_guide/node011E.html#line25) internally.
```
WA_Borderless

```c
    Open a window with no borders rendered by Intuition.  Equivalent to
    [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Flags WFLG_BORDERLESS.

    Use caution setting this flag, as it may cause visual confusion on
    the screen.  Also, some borders may be rendered if any of the system
    gadgets are requested, if text is supplied for the window's title
    bar, or if any of application gadgets are in the borders.
```
WA_Backdrop

```c
    Make this window a [Backdrop](../Libraries_Manual_guide/node0114.html) window.  Equivalent to [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Flags
    WFLG_BACKDROP.
```
WA_GimmeZeroZero

```c
    Set this tag to create a [GimmeZeroZero](../Libraries_Manual_guide/node0116.html) window. GimmeZeroZero windows
    have the window border and border gadgets rendered into an extra
    layer. This extra layer slows down window operations, thus it is
    recommended that applications only use GimmeZeroZero windows when
    they are required. For clipping graphics to the area within the
    borders of a window, see the discussion of "[Regions](../Libraries_Manual_guide/node03F8.html)" in the "Layers
    Library" chapter. Equivalent to [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Flags WFLG_GIMMEZEROZERO.
```
WA_Activate

```c
    Activate the window when it opens.  Equivalent to [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Flags
    WFLG_ACTIVATE.  Use this flag carefully, as it can change where the
    user's input is going.
```
WA_RMBTrap

```c
    Catch right mouse button events for application use.  Set this flag
    to disable menu operations for the window.  When set, right mouse
    button events will be received as [IDCMP_MOUSEBUTTONS](../Libraries_Manual_guide/node01DC.html) with the MENUUP
    and MENUDOWN qualifiers.  Equivalent to [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Flags WFLG_RMBTRAP.

    The WFLG_RMBTRAP flag in the [Window](../Libraries_Manual_guide/node0102.html#line8) structure Flags field may be
    modified on the fly by the program.  Changing this flag must be done
    as an atomic operation, as Intuition can preempt a multistep set or
    clear operation.  An atomic operation can be done in assembler, using
    68000 instructions that operate directly on memory.  If you are
    unsure of generating such an instruction, place the operation within
    a [Forbid()/Permit()](../Libraries_Manual_guide/node02D0.html#line10) pair.  This will ensure proper operation by
    disabling multitasking while the flag is being changed.
```
WA_SimpleRefresh

```c
    The application program takes complete responsibility for updating
    the window.  Only specify if TRUE.  Equivalent to [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Flags
    WFLG_SIMPLE_REFRESH.
```
WA_SmartRefresh

```c
    Intuition handles all window updating, except for parts of the window
    revealed when the window is sized larger.  Only specify if TRUE.
    Equivalent to [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Flags WFLG_SMART_REFRESH.

    WA_SmartRefresh windows without a sizing gadget will never receive
    refresh events due to the user sizing the window.  However, if the
    application sizes the window through a call like [ChangeWindowBox()](../Libraries_Manual_guide/node0129.html),
    [ZipWindow()](../Libraries_Manual_guide/node0129.html) or [SizeWindow()](../Libraries_Manual_guide/node0129.html), a refresh event may be generated.  Use
    WA_NoCareRefresh to disable refresh events.
```
WA_SuperBitMap

```c
    This is a pointer to a [BitMap](../Libraries_Manual_guide/node00F1.html#line4) structure for a SuperBitMap window. The
    application will be allocating and maintaining its own bitmap.
    Equivalent to [NewWindow](../Libraries_Manual_guide/node0102.html#line8).BitMap.  Setting this tag implies the
    WFLG_SUPER_BITMAP property.

    For complete information about SuperBitMap, see
    "[Setting Up a SuperBitMap Window](../Libraries_Manual_guide/node011F.html)" in this chapter.
```
WA_AutoAdjust

```c
    Allow Intuition to change the window's position and dimensions in
    order to fit it on screen.  The window's position is adjusted first,
    then the size.  This property may be especially important when using
    [WA_InnerWidth and WA_InnerHeight](../Libraries_Manual_guide/node0124.html#line115) as border size depends on a user
    specified font.
```
WA_MenuHelp (new for V37, ignored by V36)

```c
    Enables [IDCMP_MENUHELP](../Libraries_Manual_guide/node01DE.html#line21): pressing Help during menus will return
    IDCMP_MENUHELP message.  See the "[Intuition Menus](../Libraries_Manual_guide/node018A.html)" chapter for more
    information.
```
WA_Flags

```c
    Multiple initialization of window flags, equivalent to
    [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Flags. Use the WFLG_ constants to initialize this field,
    multiple bits may be set by ORing the values together.
```
WA_BackFill

```c
    Allows you to specify a backfill hook for your window's layer.  See
    the description of [CreateUpFrontHookLayer()](../Includes_and_Autodocs_2._guide/node0392.html) in the "Includes and
    Autodocs" manual.  Note that this tag is implemented in V37, contrary
    to what some versions of the include files may say.
```
