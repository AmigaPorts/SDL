---
title: 3 / Custom Screen Functions / Screen Attributes
manual: libraries
chapter: libraries
section: 3-custom-screen-functions-screen-attributes
functions: [FindTask, GetColorMap, LoadRGB4, OpenScreen, OpenScreenTagList, PrintIText, SetFont, SetRGB4, ShowTitle, Text]
libraries: [exec.library, graphics.library, intuition.library]
---

# 3 / Custom Screen Functions / Screen Attributes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The sections above discuss only the basic functions and screen types that
Intuition programmers need to understand to [create a custom screen](libraries/3-custom-screen-functions-creating-a-new-custom-screen.md).
Intuition supports an astonishing number of additional display features
and options.  In this section and the sections to follow, the finer points
of screen attributes and the functions that control them are presented.

Screen attributes are specified using the tag item scheme described in the
"[Utility Library](libraries/37-tags-simple-tag-usage.md)" chapter.  Therefore, the screen attributes are listed
here by tag values.  (In V34, the [NewScreen](libraries/3-screen-data-structures-other-screen-data-structures.md) structure was used to set
screen attributes so many of the tag options listed here have a
corresponding flag in NewScreen.)  In general, specifying a tag overrides
the corresponding flag or field in the NewScreen structure if you supply
one.

SA_ErrorCode

```c
    Extended error code.  Data is a pointer to a long which will contain
    the error code on return if [OpenScreenTagList()](libraries/3-screen-data-structures-other-screen-data-structures.md) returns NULL. The
    error codes are described above.
```
SA_Left, SA_Top

```c
    Initial screen position (left edge and top edge).  Data is a long,
    signed value.  Offsets are relative to the text overscan rectangle.

    If SA_Left is not specified and a [NewScreen](libraries/3-screen-data-structures-other-screen-data-structures.md) structure is not passed
    in the [OpenScreenTags/TagList()](libraries/3-intuition-screens-custom-screen-functions.md) call and SA_Width is not specified
    or is specified as STDSCREENWIDTH, then the left edge of the screen
    will default to the left edge of the actual display clip of the
    screen.  If the other conditions are met but some explicit SA_Width
    is specified, then the left edge defaults to zero (text overscan
    rectangle left edge).  Likewise, the top edge may, independent of the
    left edge value, default to zero or to the top edge of the actual
    display clip.  If SA_Top is not specified and a NewScreen structure
    is not passed in the OpenScreenTags/TagList() call and SA_Height is
    not specified or specified as STDSCREENHEIGHT, then the top edge of
    the screen will default to the top edge of the actual display clip of
    the screen.  If the other conditions are met but some explicit
    SA_Height is specified, then the top edge defaults to zero (text
    overscan rectangle top edge).  Prior to V36, left edge positioning is
    ignored and negative top edge positions are illegal.

    When opening a full sized overscan screen, SA_Left should be set to
    the MinX value of the display clip [Rectangle](libraries/29-graphics-library-and-text-does-the-text-fit.md) used for the screen and
    SA_Top should be set to the MinY value of the display clip.  This may
    be taken from the defaults, as explained above, or explicitly set by
    the application.  See the section below "[Overscan and the Display clip](libraries/3-intuition-screens-overscan-and-the-display-clip.md)"
    and the [OpenScreen()](autodocs-2.0/intuition-library-openscreen.md) Autodoc for more details.

    If your screen is larger than your display clip, you may wish to set
    the SA_Left and SA_Top to values less than your display clip MinX and
    MinY in order to center a large screen on a smaller display.  For an
    example of how to open a centered overscan screen, see
    module/[screen.c](libraries/devices-modules-screen-c.md) in the IFF Appendix of the Amiga ROM Kernel Reference
    Manual: Devices.
```
SA_Width, SA_Height

```c
    Screen dimensions.  Data is a long, unsigned value.  These may be
    larger, smaller or the same as the dimensions of the display clip
    [Rectangle](libraries/29-graphics-library-and-text-does-the-text-fit.md).  The use of STDSCREENWIDTH and STDSCREENHEIGHT will make
    the screen size equal to the display clip size.

    To calculate the width of the display clip [Rectangle](libraries/29-graphics-library-and-text-does-the-text-fit.md), subtract the
    MinX value from the MaxX value plus one.  Similarly, the height of
    the display clip may be calculated by subtracting the MinY value from
    the MaxY value plus one.
```
SA_Depth

```c
    Screen bitmap depth.  Data is a long, unsigned value.  The depth of
    the screen determines the number of available colors.  See the
    "[Graphics Primitives](libraries/27-introduction-forming-an-image.md)" for more information on hardware limitations of
    the display.  Do not set the depth to a value greater than that
    supported by the specific display mode.  This information is
    available to the application through the graphics library display
    database.  The default is one bitplane.
```
SA_DisplayID

```c
    Extended display mode key for the screen.  Data is a long, unsigned
    value.  By using Release 2 DisplayIDs and the display database,
    applications can open a screen in any display mode available on a
    user's system, including PAL and NTSC modes.  See the discussion of
    the display database in the "[Graphics Primitives](libraries/27-the-display-database-and-the-displayinfo-record.md)" chapter and the
    include file <graphics/[displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md)> for more information.
```
SA_Pens

```c
    Pen specification for the screen.  Data is a pointer to a UWORD array
    terminated with ~0, as found in the [DrawInfo](libraries/3-screen-data-structures-other-screen-data-structures.md) structure.  Specifying
    the SA_Pens tag informs the system that the application is prepared
    to handle a screen rendered with the new 3D look of Intuition.  See
    the section below on "[DrawInfo and the 3D Look](libraries/3-drawinfo-and-the-3d-look-the-pen-specification-in-drawinfo.md)". Omitting this tag
    produces a screen with a flat look, but whose color usage is more
    backwards compatible.
```
SA_DetailPen

    Detail pen for the screen.  Data is a long, unsigned value.  Used for
    rendering details in the screen title bar and menus.  Use SA_Pens
    beginning with V36 for more control of pen specification.  If SA_Pens
    is not specified, the screen will not get the new 3D look of
    Intuition available in Release 2.  Instead this value will be used as
    the detail pen.
SA_BlockPen

    Block pen for the screen.  Data is a long, unsigned value.  Used for
    rendering block fills in the screen title bar and menus.  Use SA_Pens
    beginning with V36 for more control of pen specification.  If SA_Pens
    is not specified, the screen will not get the new 3D look and this
    value will be used as the block pen.
SA_Title

    Default screen title.  Data is a pointer to a character string.  This
    is the title displayed when the active window has no screen title or
    when no window is active on the screen.
SA_Colors

```c
    Specifies initial screen palette colors.  Data is a pointer to an
    array of [ColorSpec](autodocs-2.0/includes-intuition-intuition-h.md) structures, terminated by a ColorSpec structure
    with ColorIndex=-1. Screen colors may be changed after the screen is
    opened with the graphics library functions [SetRGB4()](libraries/27-forming-a-basic-display-preparing-the-colormap-structure.md) and [LoadRGB4()](libraries/27-forming-a-basic-display-preparing-the-colormap-structure.md).
    ColorSpec colors are right-justified, four bits per gun.
```
SA_FullPalette

```c
    Initialize color table to entire preferences palette (32 colors
    beginning with V36), rather than the subset from V34 and earlier,
    namely pens 0-3, 17-19, with remaining palette as returned by
    [GetColorMap()](libraries/27-forming-a-basic-display-preparing-the-colormap-structure.md).  Data is a boolean value (use TRUE to set the flag).
    Defaults to FALSE.
```
SA_Font

```c
    Data is a pointer to a [TextAttr](libraries/29-the-text-function-choosing-the-font.md) structure (defined in
    <graphics/[text.h](autodocs-2.0/includes-graphics-text-h.md)> ) which specifies the font, size and style to use
    for the screen.  Equivalent to [NewScreen.Font](libraries/3-screen-data-structures-the-intuition-screen-data-structure.md).
```
SA_SysFont

```c
    Alternative to SA_Font.  Selects one of the preferences system fonts.
    Data is a long, unsigned value, with the following values defined:

        0  Open screen with the user's preferred fixed width font
           (the default).
        1  Open screen with the user's preferred font, which may be
           proportional.

    The Workbench screen is opened with {SA_SysFont , 1}.  Table 3-4
    summarizes how the font selected at [OpenScreen()](libraries/3-intuition-screens-custom-screen-functions.md) time effects
    subsequent text operations in screens and windows.


                Table 3-4: Intuition Font Selection Chart

       What you tell
       [OpenScreen()](libraries/3-intuition-screens-custom-screen-functions.md)            Screen font            Window.RPort font
       -------------           -----------            -----------------
    A. [NewScreen](libraries/3-screen-data-structures-other-screen-data-structures.md).Font=myfont  myfont                  myfont
    B. NewScreen.Font=NULL    GfxBase->DefaultFont    GfxBase->DefaultFont
    C. {SA_Font, myfont}      myfont                  myfont
    D. {SA_SysFont, 0}        GfxBase->DefaultFont    GfxBase->DefaultFont
    E. {SA_SysFont, 1}        Font Prefs Screen text  GfxBase->DefaultFont

       Notes:
     * A and B are the options that existed in V34 and earlier OS versions.
     * C and D are tags in Release 2 equivalent to A and B respectively.
     * E is a new option for V36.  The Workbench screen uses this option.
     * For `myfont', any font may be used including a proportional one.
       This is true under all releases of the OS.
     * GfxBase->DefaultFont is always monospace.  (This is the "System
       Default Text" from Font Preferences.)
     * Font Prefs Screen text (the "Screen Text" choice from Font
       Preferences) can be monospace or proportional.


    The screen's font may not legally be changed after a screen is
    opened. The menu bar, window titles, menu items, and the contents of
    a string gadget all use the screen's font.  The font used for menu
    items can be overridden in the menu item's [IntuiText](libraries/8-creating-text-intuitext-structure.md) structure.
    Under V36 and higher, the font used in a string gadget can be
    overridden through the [StringExtend](libraries/5-string-gadget-type-extended-string-gadgets.md) structure.  The font of the menu
    bar and window titles cannot be overridden.

    The [Window.RPort](libraries/4-intuition-windows-the-window-structure.md) font shown above is the initial font that Intuition
    sets in your window's [RastPort](libraries/4-intuition-windows-basic-window-structures-and-functions.md).  It is legal to change that
    subsequently with [SetFont()](libraries/29-the-text-function-choosing-the-font.md).  [IntuiText](libraries/8-creating-text-intuitext-structure.md) rendered into a window
    (either through [PrintIText()](libraries/8-creating-text-directly-drawing-the-intuitext.md) or as a gadget's [GadgetText](libraries/5-intuition-gadgets-gadget-structure.md)) defaults to
    the window's RastPort font, but can be overridden using its [ITextFont](libraries/8-creating-text-intuitext-structure.md)
    field.  Text rendered with the graphics library call [Text()](libraries/29-graphics-library-and-text-the-text-function.md) uses the
    window's RastPort font.
```
SA_Type

```c
    Equivalent to the SCREENTYPE bits of the [NewScreen](libraries/3-screen-data-structures-other-screen-data-structures.md).Type field.  Data
    is a long, unsigned value which may be set to either CUSTOMSCREEN or
    PUBLICSCREEN (WBENCHSCREEN is reserved for system use).  See the tags
    SA_BitMap, SA_Behind, SA_Quiet, SA_ShowTitle and SA_AutoScroll for
    the other attributes of the NewScreen.Type field.
```
SA_BitMap

```c
    Use a custom bitmap for this screen.  Data is a pointer to a [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md)
    structure.  This tag is equivalent to [NewScreen](libraries/3-screen-data-structures-other-screen-data-structures.md).CustomBitMap and
    implies the CUSTOMBITMAP flag of the NewScreen.Type field.  The
    application is responsible for allocating and freeing the screen's
    bitmap.
```
SA_Behind

```c
    Open this screen behind all other screens in the system.  Data is a
    boolean value (TRUE to set flag).  This tag is equivalent to the
    SCREENBEHIND flag of the [NewScreen](libraries/3-screen-data-structures-other-screen-data-structures.md).Type field.
```
SA_Quiet

```c
    Disable Intuition rendering into screen.  Data is a boolean value
    (TRUE to set flag).  This tag is equivalent to the SCREENQUIET flag
    of the [NewScreen](libraries/3-screen-data-structures-other-screen-data-structures.md).Type field.  The screen will have no visible title
    bar or gadgets, but dragging and depth arrangement still function.
    In order to completely prevent Intuition from rendering into the
    screen, menu operations must be disabled for each window in the
    screen using WFLG_RMBTRAP.
```
SA_ShowTitle

```c
    Setting this flag places the screen's title bar in front of any
    backdrop windows that are opened on the screen.  Data is a boolean
    value (TRUE to set flag).  This tag is equivalent to the SHOWTITLE
    flag of the [NewScreen](libraries/3-screen-data-structures-other-screen-data-structures.md).Type field.  The title bar of the screen is
    always displayed behind any non-backdrop windows on that screen.
    This attribute can be changed after the screen is open with the
    [ShowTitle()](libraries/3-other-screen-functions-miscellaneous-screen-functions.md) function.
```
SA_AutoScroll

```c
    Setting this flag will enable autoscroll for this screen when it is
    the active screen.  (Currently, the screen may only be made active by
    activating a window in that screen either under user or application
    control.)  Data is a boolean value (TRUE to set flag).  This tag is
    equivalent to the AUTOSCROLL flag of the [NewScreen](libraries/3-screen-data-structures-other-screen-data-structures.md).Type field.

    Autoscroll means that screens larger than the visible display will
    automatically scroll when the user moves the mouse to the edge of the
    screen.  Without this tag, the user moves the screen either by using
    the screen drag bar, or by pressing the mouse select button anywhere
    within the screen while holding down the left Amiga key and moving
    the mouse.
```
SA_PubName

```c
    Presence of this tag means that the screen is to be a [public screen](libraries/3-public-screen-functions-taking-a-new-custom-screen-public.md).
    Data is a pointer to a string.  The string is the name of the public
    screen which is used by other applications to find the screen.  This
    tag is order dependent, specify before SA_PubSig and SA_PubTask.
```
SA_PubSig, SA_PubTask

```c
    Task ID (returned by [FindTask()](libraries/21-exec-tasks-function-reference.md)) and signal for notification that the
    last window has closed on a [public screen](libraries/3-intuition-screens-public-screen-functions.md). Data for SA_PubSig is a
    long, unsigned value. Data for SA_PubTask is a pointer to a [Task](libraries/21-exec-tasks-task-structure.md)
    structure. These two tags are order dependent, and must be specified
    after the tag SA_PubName.
```
SA_Overscan

```c
    Set to one of the OSCAN_ specifiers to use a system standard overscan
    display clip and screen dimensions (unless otherwise specified).
    Data is a long, unsigned value.  Do not specify this tag and
    SA_DClip.  SA_Overscan is used to get one of the standard overscan
    dimensions, while SA_DClip is for custom dimensions.  If a display
    clip is not specified with either SA_Overscan or SA_DClip, the
    display clip defaults to [OSCAN_TEXT](libraries/3-overscan-and-the-display-clip-preset-overscan-values.md).  See the section below on
    "[Overscan and the Display Clip](libraries/3-overscan-and-the-display-clip-preset-overscan-values.md)" for more information.
```
SA_DClip

```c
    Custom display clip specification.  Data is a pointer to a [Rectangle](libraries/29-graphics-library-and-text-does-the-text-fit.md)
    structure that defines the screen display clip region.
```

---

## See Also

- [FindTask — exec.library](../autodocs/exec.library.md#findtask)
- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [LoadRGB4 — graphics.library](../autodocs/graphics.library.md#loadrgb4)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenScreenTagList — intuition.library](../autodocs/intuition.library.md#openscreentaglist)
- [PrintIText — intuition.library](../autodocs/intuition.library.md#printitext)
- [SetFont — graphics.library](../autodocs/graphics.library.md#setfont)
- [SetRGB4 — graphics.library](../autodocs/graphics.library.md#setrgb4)
- [ShowTitle — intuition.library](../autodocs/intuition.library.md#showtitle)
- [Text — graphics.library](../autodocs/graphics.library.md#text)
