# intuition.library/GetScreenData



NAME

    GetScreenData -- Get copy of a screen data structure.
SYNOPSIS

```c
    Success = GetScreenData( Buffer, Size, Type, [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) )
    D0                       A0      D0    D1    A1

    BOOL GetScreenData( APTR, UWORD, UWORD, struct [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) * );
```
FUNCTION

```c
    This function copies into the caller's buffer data from a [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97)
    structure.  Typically, this call will be used to find the size, title
    bar height, and other values for a standard screen, such as the
    Workbench screen.

    To get the data for the Workbench screen, one would call:
        GetScreenData(buff, sizeof(struct Screen), WBENCHSCREEN, NULL)

    NOTE: if the requested standard screen is not open, this function
    will have the effect of opening it.

    This function has been useful for two basic types of things:
    1) Determining information about the Workbench screen, in
       preparation for opening a window on it.
    2) Attempts at discerning the user's preferences in a working
       screen, for "cloning" the Workbench modes and dimensions
       when opening a similar custom screen.

    Providing compatibility with both of these goals has proven
    difficult, as we introduce new display modes and screen scrolling
    in V36.  Read carefully the somewhat involved exceptions we
    elected to implement ...

    Changes as of V36:

    For V36 and later, the function [LockPubScreen()](../Includes_and_Autodocs_2._guide/node0225.html) is an improvement
    over this function, in that it doesn't copy the screen data
    but returns a pointer and a guarantee that the screen will not
    be closed.

    If the global public screen SHANGHAI mode is in effect (see
    [SetPubScreenModes()](../Includes_and_Autodocs_2._guide/node0257.html) ), this function will actually report on
    the default public screen, where "Workbench" windows will
    actually open.

    For V36 and later, this function does some "compatibility tricks"
    when you inquire about the WBENCHSCREEN.  To keep programs from
    "stumbling" into modes they don't understand, and because an NTSC
    machine may be running a PAL Workbench or PRODUCTIVITY, for example,
    the following "false" information is returned.

    The Screen.ViewPort.Modes field will either be HIRES or HIRES+LACE
    (with the SPRITES flag also set, as usual).  HIRES+LACE is
    used if the display mode selected for the Workbench screen
    is an interlaced screen of any type.

    The dimensions returned will be the *smaller* of the OSCAN_TEXT
    dimensions for the returned mode, and the actual dimensions
    of the Workbench screen.

    EXCEPTION: For specific compatibility considerations, if the
    Workbench is in one of the A2024 modes, the mode returned
    in Screen.ViewPort.Modes will be HIRES+LACE (with perhaps
    some "special" bits also set for future improvement), but
    with dimensions equal to the actual A2024-mode Workbench screen.
    This will favor programs which open windows on the A2024
    Workbench, but will cause some problems for programs which
    try to "clone" the Workbench screen using this function.

    If you want the real information about the modern Workbench
    screen, call LockPubScreen( "Workbench" ) and acquire its
    display mode ID by inquiring of the actual [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) (using
    [graphics.library/GetVPModeID()](../Includes_and_Autodocs_2._guide/node044A.html) ).

    You may then use the information you get to clone as many of
    the properties of the Workbench screen that you wish.

    In the long run, it's probably better to provide your user
    with a screen mode selection option, and skip all this.
```
INPUTS

```c
    Buffer = pointer to a buffer into which data can be copied
    Size   = the size of the buffer provided, in bytes
    Type   = the screen type, as specified in [OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html) (WBENCHSCREEN,
        CUSTOMSCREEN, ...)
    [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) = ignored, unless type is CUSTOMSCREEN, which results only in
        copying 'size' bytes from 'screen' to 'buffer'
```
RESULT

    TRUE if successful
    FALSE if standard screen of Type 'type' could not be opened.
BUGS

    You cannot support the new V36 display modes using this function.
SEE ALSO

```c
    [OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html), [LockPubScreen()](../Includes_and_Autodocs_2._guide/node0225.html), [graphics.library/GetVPModeID()](../Includes_and_Autodocs_2._guide/node044A.html),
    [SetPubScreenModes()](../Includes_and_Autodocs_2._guide/node0257.html), [OpenScreen()](../Includes_and_Autodocs_2._guide/node0237.html)
```
