# 3 / Custom Screen Functions / Screen Attributes


The sections above discuss only the basic functions and screen types that
Intuition programmers need to understand to [create a custom screen](../Libraries_Manual_guide/node00E0.html).
Intuition supports an astonishing number of additional display features
and options.  In this section and the sections to follow, the finer points
of screen attributes and the functions that control them are presented.

Screen attributes are specified using the tag item scheme described in the
"[Utility Library](../Libraries_Manual_guide/node0498.html)" chapter.  Therefore, the screen attributes are listed
here by tag values.  (In V34, the [NewScreen](../Libraries_Manual_guide/node00DE.html#line6) structure was used to set
screen attributes so many of the tag options listed here have a
corresponding flag in NewScreen.)  In general, specifying a tag overrides
the corresponding flag or field in the NewScreen structure if you supply
one.

SA_ErrorCode

```c
    Extended error code.  Data is a pointer to a long which will contain
    the error code on return if [OpenScreenTagList()](../Libraries_Manual_guide/node00DE.html#line6) returns NULL. The
    error codes are described above.
```
SA_Left, SA_Top

```c
    Initial screen position (left edge and top edge).  Data is a long,
    signed value.  Offsets are relative to the text overscan rectangle.

    If SA_Left is not specified and a [NewScreen](../Libraries_Manual_guide/node00DE.html#line6) structure is not passed
    in the [OpenScreenTags/TagList()](../Libraries_Manual_guide/node00DF.html#line6) call and SA_Width is not specified
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
    the MinX value of the display clip [Rectangle](../Libraries_Manual_guide/node03DA.html#line49) used for the screen and
    SA_Top should be set to the MinY value of the display clip.  This may
    be taken from the defaults, as explained above, or explicitly set by
    the application.  See the section below "[Overscan and the Display clip](../Libraries_Manual_guide/node00EF.html)"
    and the [OpenScreen()](../Includes_and_Autodocs_2._guide/node0237.html) Autodoc for more details.

    If your screen is larger than your display clip, you may wish to set
    the SA_Left and SA_Top to values less than your display clip MinX and
    MinY in order to center a large screen on a smaller display.  For an
    example of how to open a centered overscan screen, see
    module/[screen.c](../Libraries_Manual_guide/node05D2.html) in the IFF Appendix of the Amiga ROM Kernel Reference
    Manual: Devices.
```
SA_Width, SA_Height

```c
    Screen dimensions.  Data is a long, unsigned value.  These may be
    larger, smaller or the same as the dimensions of the display clip
    [Rectangle](../Libraries_Manual_guide/node03DA.html#line49).  The use of STDSCREENWIDTH and STDSCREENHEIGHT will make
    the screen size equal to the display clip size.

    To calculate the width of the display clip [Rectangle](../Libraries_Manual_guide/node03DA.html#line49), subtract the
    MinX value from the MaxX value plus one.  Similarly, the height of
    the display clip may be calculated by subtracting the MinY value from
    the MaxY value plus one.
```
SA_Depth

```c
    Screen bitmap depth.  Data is a long, unsigned value.  The depth of
    the screen determines the number of available colors.  See the
    "[Graphics Primitives](../Libraries_Manual_guide/node031E.html#line95)" for more information on hardware limitations of
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
    the display database in the "[Graphics Primitives](../Libraries_Manual_guide/node033C.html)" chapter and the
    include file <graphics/[displayinfo.h](../Includes_and_Autodocs_2._guide/node00BD.html)> for more information.
```
SA_Pens

```c
    Pen specification for the screen.  Data is a pointer to a UWORD array
    terminated with ~0, as found in the [DrawInfo](../Libraries_Manual_guide/node00DE.html#line6) structure.  Specifying
    the SA_Pens tag informs the system that the application is prepared
    to handle a screen rendered with the new 3D look of Intuition.  See
    the section below on "[DrawInfo and the 3D Look](../Libraries_Manual_guide/node00EC.html)". Omitting this tag
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
    array of [ColorSpec](../Includes_and_Autodocs_2._guide/node00D4.html#line1241) structures, terminated by a ColorSpec structure
    with ColorIndex=-1. Screen colors may be changed after the screen is
    opened with the graphics library functions [SetRGB4()](../Libraries_Manual_guide/node0331.html) and [LoadRGB4()](../Libraries_Manual_guide/node0331.html).
    ColorSpec colors are right-justified, four bits per gun.
```
SA_FullPalette

```c
    Initialize color table to entire preferences palette (32 colors
    beginning with V36), rather than the subset from V34 and earlier,
    namely pens 0-3, 17-19, with remaining palette as returned by
    [GetColorMap()](../Libraries_Manual_guide/node0331.html).  Data is a boolean value (use TRUE to set the flag).
    Defaults to FALSE.
```
SA_Font

```c
    Data is a pointer to a [TextAttr](../Libraries_Manual_guide/node03D6.html#line21) structure (defined in
    <graphics/[text.h](../Includes_and_Autodocs_2._guide/node00A8.html#line65)> ) which specifies the font, size and style to use
    for the screen.  Equivalent to [NewScreen.Font](../Libraries_Manual_guide/node00DD.html#line76).
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
    summarizes how the font selected at [OpenScreen()](../Libraries_Manual_guide/node00DF.html#line6) time effects
    subsequent text operations in screens and windows.


                Table 3-4: Intuition Font Selection Chart

       What you tell
       [OpenScreen()](../Libraries_Manual_guide/node00DF.html#line6)            Screen font            Window.RPort font
       -------------           -----------            -----------------
    A. [NewScreen](../Libraries_Manual_guide/node00DE.html#line6).Font=myfont  myfont                  myfont
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
    items can be overridden in the menu item's [IntuiText](../Libraries_Manual_guide/node01C7.html) structure.
    Under V36 and higher, the font used in a string gadget can be
    overridden through the [StringExtend](../Libraries_Manual_guide/node016D.html) structure.  The font of the menu
    bar and window titles cannot be overridden.

    The [Window.RPort](../Libraries_Manual_guide/node0121.html#line66) font shown above is the initial font that Intuition
    sets in your window's [RastPort](../Libraries_Manual_guide/node0102.html#line8).  It is legal to change that
    subsequently with [SetFont()](../Libraries_Manual_guide/node03D6.html).  [IntuiText](../Libraries_Manual_guide/node01C7.html) rendered into a window
    (either through [PrintIText()](../Libraries_Manual_guide/node01C8.html) or as a gadget's [GadgetText](../Libraries_Manual_guide/node0149.html#line111)) defaults to
    the window's RastPort font, but can be overridden using its [ITextFont](../Libraries_Manual_guide/node01C7.html#line59)
    field.  Text rendered with the graphics library call [Text()](../Libraries_Manual_guide/node03D5.html) uses the
    window's RastPort font.
```
SA_Type

```c
    Equivalent to the SCREENTYPE bits of the [NewScreen](../Libraries_Manual_guide/node00DE.html#line6).Type field.  Data
    is a long, unsigned value which may be set to either CUSTOMSCREEN or
    PUBLICSCREEN (WBENCHSCREEN is reserved for system use).  See the tags
    SA_BitMap, SA_Behind, SA_Quiet, SA_ShowTitle and SA_AutoScroll for
    the other attributes of the NewScreen.Type field.
```
SA_BitMap

```c
    Use a custom bitmap for this screen.  Data is a pointer to a [BitMap](../Libraries_Manual_guide/node00F1.html#line4)
    structure.  This tag is equivalent to [NewScreen](../Libraries_Manual_guide/node00DE.html#line6).CustomBitMap and
    implies the CUSTOMBITMAP flag of the NewScreen.Type field.  The
    application is responsible for allocating and freeing the screen's
    bitmap.
```
SA_Behind

```c
    Open this screen behind all other screens in the system.  Data is a
    boolean value (TRUE to set flag).  This tag is equivalent to the
    SCREENBEHIND flag of the [NewScreen](../Libraries_Manual_guide/node00DE.html#line6).Type field.
```
SA_Quiet

```c
    Disable Intuition rendering into screen.  Data is a boolean value
    (TRUE to set flag).  This tag is equivalent to the SCREENQUIET flag
    of the [NewScreen](../Libraries_Manual_guide/node00DE.html#line6).Type field.  The screen will have no visible title
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
    flag of the [NewScreen](../Libraries_Manual_guide/node00DE.html#line6).Type field.  The title bar of the screen is
    always displayed behind any non-backdrop windows on that screen.
    This attribute can be changed after the screen is open with the
    [ShowTitle()](../Libraries_Manual_guide/node00FC.html#line10) function.
```
SA_AutoScroll

```c
    Setting this flag will enable autoscroll for this screen when it is
    the active screen.  (Currently, the screen may only be made active by
    activating a window in that screen either under user or application
    control.)  Data is a boolean value (TRUE to set flag).  This tag is
    equivalent to the AUTOSCROLL flag of the [NewScreen](../Libraries_Manual_guide/node00DE.html#line6).Type field.

    Autoscroll means that screens larger than the visible display will
    automatically scroll when the user moves the mouse to the edge of the
    screen.  Without this tag, the user moves the screen either by using
    the screen drag bar, or by pressing the mouse select button anywhere
    within the screen while holding down the left Amiga key and moving
    the mouse.
```
SA_PubName

```c
    Presence of this tag means that the screen is to be a [public screen](../Libraries_Manual_guide/node00E9.html).
    Data is a pointer to a string.  The string is the name of the public
    screen which is used by other applications to find the screen.  This
    tag is order dependent, specify before SA_PubSig and SA_PubTask.
```
SA_PubSig, SA_PubTask

```c
    Task ID (returned by [FindTask()](../Libraries_Manual_guide/node02D0.html#line5)) and signal for notification that the
    last window has closed on a [public screen](../Libraries_Manual_guide/node00E6.html). Data for SA_PubSig is a
    long, unsigned value. Data for SA_PubTask is a pointer to a [Task](../Libraries_Manual_guide/node02BB.html)
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
    display clip defaults to [OSCAN_TEXT](../Libraries_Manual_guide/node00F0.html#line12).  See the section below on
    "[Overscan and the Display Clip](../Libraries_Manual_guide/node00F0.html)" for more information.
```
SA_DClip

```c
    Custom display clip specification.  Data is a pointer to a [Rectangle](../Libraries_Manual_guide/node03DA.html#line49)
    structure that defines the screen display clip region.
```
