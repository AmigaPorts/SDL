---
title: 4 / Window Attributes / Boolean Window Attribute Tags
manual: libraries
chapter: libraries
section: 4-window-attributes-boolean-window-attribute-tags
functions: [BeginRefresh, ChangeWindowBox, CloseWindow, EndRefresh, Forbid, Permit, ReportMouse, SizeWindow, ZipWindow]
libraries: [exec.library, intuition.library]
---

# 4 / Window Attributes / Boolean Window Attribute Tags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

These boolean window tags are alternatives to the [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Flags bit
fields with similar names.  Unlike the tags discussed above, the ti_Data
field of these [TagItems](libraries/4-intuition-windows-basic-window-structures-and-functions.md) is set to either TRUE or FALSE.

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
    Equivalent to [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Flags WFLG_SIZEGADGET.
```
WA_SizeBRight

```c
    Place the size gadget in the right border.  Equivalent to
    [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Flags WFLG_SIZEBRIGHT.
```
WA_SizeBBottom

```c
    Place the size gadget in the bottom border.  Equivalent to
    [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Flags WFLG_SIZEBBOTTOM.
```
WA_DragBar

```c
    This flag turns the entire title bar of the window into a drag
    gadget, allowing the user to position the window by clicking in the
    title bar and dragging the mouse.  Equivalent to [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Flags
    WFLG_DRAGBAR.
```
WA_DepthGadget

```c
    Setting this flag adds a depth gadget to the window.  This allows the
    user to change the window's depth arrangement with respect to other
    windows on the screen.  Intuition places the depth gadget in the
    upper right corner of the window.  Equivalent to [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Flags
    WFLG_DEPTHGADGET.
```
WA_CloseGadget

```c
    Setting this flag attaches a close gadget to the window.  When the
    user selects this gadget, Intuition transmits a message to the
    application.  It is up to the application to close the window with a
    [CloseWindow()](libraries/4-basic-window-structures-and-functions-closing-windows.md) call. Intuition places the close gadget in the upper
    left corner of the window. Equivalent to [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Flags
    WFLG_CLOSEGADGET.
```
WA_ReportMouse

```c
    Send mouse movement events to the window as x,y coordinates.  Also
    see the description of the IDCMP flag [IDCMP_MOUSEMOVE](libraries/9-event-message-classes-and-flags-mouse-flags.md), in the chapter
    "Intuition Input and Output Methods."  Equivalent to [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Flags
    WFLG_REPORTMOUSE.

    The WFLG_REPORTMOUSE flag in the Flags field of the [Window](libraries/4-intuition-windows-basic-window-structures-and-functions.md) structure
    may be modified on the fly  by the program.  Changing this flag must
    be done as an atomic operation.  Most compilers generate atomic code
    for operations such as window->flags |= WFLG_REPORTMOUSE or
    window->flags &= ~WFLG_REPORTMOUSE.  If you are unsure of getting an
    atomic operation from your compiler, you may wish to do this
    operation in assembler, or bracket the code with a [Forbid()/Permit()](libraries/21-exec-tasks-function-reference.md)
    pair.

    The use of the [ReportMouse()](libraries/10-the-pointer-pointer-position.md) function is strongly discouraged, due to
    historic confusion over the parameter ordering.
```
WA_NoCareRefresh

```c
    This window does not want [IDCMP_REFRESHWINDOW](libraries/9-event-message-classes-and-flags-window-flags.md) events.  Set this flag
    to prevent the window from receiving refresh window messages.
    Equivalent to [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Flags WFLG_NOCAREREFRESH.  Intuition will
    manage [BeginRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md) and [EndRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md) internally.
```
WA_Borderless

```c
    Open a window with no borders rendered by Intuition.  Equivalent to
    [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Flags WFLG_BORDERLESS.

    Use caution setting this flag, as it may cause visual confusion on
    the screen.  Also, some borders may be rendered if any of the system
    gadgets are requested, if text is supplied for the window's title
    bar, or if any of application gadgets are in the borders.
```
WA_Backdrop

```c
    Make this window a [Backdrop](libraries/4-window-types-backdrop-window-type.md) window.  Equivalent to [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Flags
    WFLG_BACKDROP.
```
WA_GimmeZeroZero

```c
    Set this tag to create a [GimmeZeroZero](libraries/4-window-types-gimmezerozero-window-type.md) window. GimmeZeroZero windows
    have the window border and border gadgets rendered into an extra
    layer. This extra layer slows down window operations, thus it is
    recommended that applications only use GimmeZeroZero windows when
    they are required. For clipping graphics to the area within the
    borders of a window, see the discussion of "[Regions](libraries/30-layers-library-regions.md)" in the "Layers
    Library" chapter. Equivalent to [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Flags WFLG_GIMMEZEROZERO.
```
WA_Activate

```c
    Activate the window when it opens.  Equivalent to [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Flags
    WFLG_ACTIVATE.  Use this flag carefully, as it can change where the
    user's input is going.
```
WA_RMBTrap

```c
    Catch right mouse button events for application use.  Set this flag
    to disable menu operations for the window.  When set, right mouse
    button events will be received as [IDCMP_MOUSEBUTTONS](libraries/9-event-message-classes-and-flags-mouse-flags.md) with the MENUUP
    and MENUDOWN qualifiers.  Equivalent to [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Flags WFLG_RMBTRAP.

    The WFLG_RMBTRAP flag in the [Window](libraries/4-intuition-windows-basic-window-structures-and-functions.md) structure Flags field may be
    modified on the fly by the program.  Changing this flag must be done
    as an atomic operation, as Intuition can preempt a multistep set or
    clear operation.  An atomic operation can be done in assembler, using
    68000 instructions that operate directly on memory.  If you are
    unsure of generating such an instruction, place the operation within
    a [Forbid()/Permit()](libraries/21-exec-tasks-function-reference.md) pair.  This will ensure proper operation by
    disabling multitasking while the flag is being changed.
```
WA_SimpleRefresh

```c
    The application program takes complete responsibility for updating
    the window.  Only specify if TRUE.  Equivalent to [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Flags
    WFLG_SIMPLE_REFRESH.
```
WA_SmartRefresh

```c
    Intuition handles all window updating, except for parts of the window
    revealed when the window is sized larger.  Only specify if TRUE.
    Equivalent to [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Flags WFLG_SMART_REFRESH.

    WA_SmartRefresh windows without a sizing gadget will never receive
    refresh events due to the user sizing the window.  However, if the
    application sizes the window through a call like [ChangeWindowBox()](libraries/4-other-window-functions-program-control-of-window.md),
    [ZipWindow()](libraries/4-other-window-functions-program-control-of-window.md) or [SizeWindow()](libraries/4-other-window-functions-program-control-of-window.md), a refresh event may be generated.  Use
    WA_NoCareRefresh to disable refresh events.
```
WA_SuperBitMap

```c
    This is a pointer to a [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) structure for a SuperBitMap window. The
    application will be allocating and maintaining its own bitmap.
    Equivalent to [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).BitMap.  Setting this tag implies the
    WFLG_SUPER_BITMAP property.

    For complete information about SuperBitMap, see
    "[Setting Up a SuperBitMap Window](libraries/4-preserving-the-window-display-setting-up-a-superbitmap.md)" in this chapter.
```
WA_AutoAdjust

```c
    Allow Intuition to change the window's position and dimensions in
    order to fit it on screen.  The window's position is adjusted first,
    then the size.  This property may be especially important when using
    [WA_InnerWidth and WA_InnerHeight](libraries/4-window-attributes-window-attribute-tags.md) as border size depends on a user
    specified font.
```
WA_MenuHelp (new for V37, ignored by V36)

```c
    Enables [IDCMP_MENUHELP](libraries/9-event-message-classes-and-flags-menu-flags.md): pressing Help during menus will return
    IDCMP_MENUHELP message.  See the "[Intuition Menus](libraries/6-setting-up-menus-help-key-processing-in-menus.md)" chapter for more
    information.
```
WA_Flags

```c
    Multiple initialization of window flags, equivalent to
    [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Flags. Use the WFLG_ constants to initialize this field,
    multiple bits may be set by ORing the values together.
```
WA_BackFill

```c
    Allows you to specify a backfill hook for your window's layer.  See
    the description of [CreateUpFrontHookLayer()](autodocs-2.0/layers-library-createupfronthooklayer.md) in the "Includes and
    Autodocs" manual.  Note that this tag is implemented in V37, contrary
    to what some versions of the include files may say.
```

---

## See Also

- [BeginRefresh — intuition.library](../autodocs/intuition.library.md#beginrefresh)
- [ChangeWindowBox — intuition.library](../autodocs/intuition.library.md#changewindowbox)
- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [EndRefresh — intuition.library](../autodocs/intuition.library.md#endrefresh)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
- [ReportMouse — intuition.library](../autodocs/intuition.library.md#reportmouse)
- [SizeWindow — intuition.library](../autodocs/intuition.library.md#sizewindow)
- [ZipWindow — intuition.library](../autodocs/intuition.library.md#zipwindow)
