/* Source: ADCD 2.1
 * Section: intuition-library-openscreen
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-openscreen.md
 */

    [NewScreen](../Includes_and_Autodocs_2._guide/node00DD.html#line309) = pointer to an instance of a [NewScreen](../Includes_and_Autodocs_2._guide/node00DD.html#line309) structure.

    New for V36:
    In addition to the information contained in the [NewScreen](../Includes_and_Autodocs_2._guide/node00DD.html#line309) structure,
    Intuition now recognizes extended data passed in the form
    of an array of [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) structures (from [<utility/tagitem.h>](../Includes_and_Autodocs_2._guide/node012E.html)),
    commonly called a "tag list."

    There are two ways to provide this array.  The first is to
    use the new Intuition entry point [OpenScreenTagList()](../Includes_and_Autodocs_2._guide/node0238.html) and
    pass the tag list as a parameter.  This is the recommended
    method, and has a convenient format variation for C programs
    using a variable number of arguments.

    An older way used for some V36 development uses the OpenScreen()
    entry point, and an extension of the [NewScreen](../Includes_and_Autodocs_2._guide/node00DD.html#line309) structure named
    [ExtNewScreen](../Includes_and_Autodocs_2._guide/node00DD.html#line345).  See the documentation of the flag NS_EXTENDED,
    below.

    While we recommend that you use [OpenScreenTagList()](../Includes_and_Autodocs_2._guide/node0238.html) rather than
    OpenScreen() when using the extension tag list, we document
    the tag ID values here, so that all parameters for opening
    a screen can be found in one place.

    [NewScreen](../Includes_and_Autodocs_2._guide/node00DD.html#line309) is initialized with the following information:
    -------------------------------------------------------------
    Left = initial x-position of your screen (should be zero for
    releases prior to V36)

    Top = initial y-position of the opening screen
    (Note: Left and Top are specified relative to the Intuition's view,
    in same resolution as the screen pixels.)

    Width = the width for this screen's [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)

    Height = the height for his screen's [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55), or the constant
            STDSCREENHEIGHT to get the current default height (at
            this time guaranteed to be at least 200 rows).  The normal
            width and height for a particular system is stored by
            the graphics.library in GfxBase->NormalDisplayRows and
            GfxBase->NormalDisplayColumns.  These values will be different
            depending on factors such as PAL video and overscan.

            For V36, a new constant STDSCREENWIDTH is introduced.  It
            serves the similar function for screen width.  Both
            STDSCREENWIDTH and STDSCREENHEIGHT indicate that your
            screen [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) is to be the same dimensions as your
            DisplayClip rectangle.  If you do not specify either a
            standard or custom DisplayClip, the OSCAN_TEXT region
            will be used, which corresponds to the standard dimensions
            of V35 and earlier.

            Furthermore, if you are using [OpenScreenTagList()](../Includes_and_Autodocs_2._guide/node0238.html), and you
            specify STDSCREENWIDTH, and you DO NOT provide a [NewScreen](../Includes_and_Autodocs_2._guide/node00DD.html#line309)
            pointer, and you DO NOT provide SA_Left, then Intuition
            will automatically set the LeftEdge of the screen to
            be the left edge of the screen's DisplayClip region.
            Likewise for STDSCREENHEIGHT and the screen's TopEdge.

    Depth = number of bitplanes

    DetailPen = pen number for details (like gadgets or text in title bar)
        The common value for this pen is 0.

    BlockPen = pen number for block fills (like title bar)
        The common value for this pen is 1.

    Type = screen type values
        Set these flags as desired from the set:
        CUSTOMSCREEN -- this is your own screen, not a system screen.
        CUSTOMBITMAP -- this custom screen has bit maps supplied
            in the bitmap field of the [NewScreen](../Includes_and_Autodocs_2._guide/node00DD.html#line309) structure.  Intuition is
            not to allocate any raster bitmaps.
        SCREENBEHIND -- your screen will be created behind all other open
            screens.  This allows a program to prepare imagery in the
            screen, change its colors, and so on, bringing it to the
            front when it is presentable.
        SCREENQUIET -- Intuition will not render system screen gadgets or
            screen title.  In concert with the WFLG_RMBTRAP flag on all
            your screen's windows, this flag will prevent Intuition from
            rendering into your screen's bitplanes.  Without WFLG_RMBTRAP
            (or using the IDCMP_MENUVERIFY facility to cancel menu
            operations), this flag will prevent Intuition from clearing
            your menu bar, which is probably unacceptable.  The menu bar
            layer may still overwrite  a portion of your screen bitmap
            when the screen is opened.  (V36: it won't clobber your bits
            any more.)
        NS_EXTENDED for this screen to use extended attributes pointed
            to by the 'Extended' field, below.

    ViewModes = the appropriate argument for the data type ViewPort.Modes.
       These include:
       HIRES for this screen to be HIRES width.
       INTERLACE for the display to switch to interlace.
       SPRITES for this screen to use sprites (the pointer
            sprite is always displayed)
       DUALPF for dual-playfield mode (not supported yet)
        [For V36: The ViewModes field is superceded by a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) with
        tag value SA_DisplayID.]

    Font = pointer to the default [TextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line66) structure for text in this
        screen and all windows that open in this screen.  Text that uses
        this [TextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line66) includes title bars of both screen and windows,
        string gadgets, and menu titles.  Of course, [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) that
        specifies a NULL [TextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line66) field will use the screen/window default
        fonts.  NOTE: Intuition will *NOT* call [OpenDiskFont()](../Includes_and_Autodocs_2._guide/node01F7.html), so
        the [TextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line66) you supply must be in memory.  The ways to ensure
        that are to either use a ROM font (Topaz 8 or 9) or first
        call [OpenDiskFont()](../Includes_and_Autodocs_2._guide/node01F7.html) to load the font, and don't close it
        until after your screen is successfully opened.
        [For V36: this is superceded by SA_Font and SA_SysFont.]

    DefaultTitle = pointer to a line of text that will be displayed along
        the screen's title bar.  Null terminated, or just a NULL pointer
       to get no text
        [For V36: superceded by SA_Title.]

    Gadgets = This field should be set to NULL, since no user gadgets may
        be attached to a screen with the current versions of Intuition.

    CustomBitMap = if you're not supplying a custom bitmap, this value is
       ignored.  However, if you have your own display memory that you
       want used for this screen, the CustomBitMap field should point to
        the [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47) structure that describes your display memory.  See the
       "Screens" chapter and the "Amiga ROM Kernel Manual" for more
       information about bitmaps.
        [For V36: this is superceded by SA_BitMap.]

    [ All [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) extensions below are new for V36.]
    Extension = if NS_EXTENDED is set in NewScreen.Type, this pointer
        should point to an array (or chain of arrays) of TagItems,
        as defined in the include file [<utility/tagitem.h>](../Includes_and_Autodocs_2._guide/node012E.html).   This
        field is only defined in the structure [ExtNewScreen](../Includes_and_Autodocs_2._guide/node00DD.html#line345).
        The values to use for TagItem.ti_Tag are defined below.  We
        recommend that V36-specific applications use the new Intuition
        entry point [OpenScreenTagList()](../Includes_and_Autodocs_2._guide/node0238.html), rather than using this field.
        The [ExtNewScreen](../Includes_and_Autodocs_2._guide/node00DD.html#line345) structure is a convenient way to give V36
        Intuition some information that V34 and earlier Intuition will
        ignore.

        Each [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) is an optional tagged data structure which identifies
        an additional parameter to OpenScreen().  The applicable tag ID
        values for TagItem.ti_Tag and their corresponding data follow.

        Several of the tag items are alternative (and overriding) versions
        to familiar fields in [NewScreen](../Includes_and_Autodocs_2._guide/node00DD.html#line309).  They are:

    SA_Left
    SA_Top
    SA_Width
    SA_Height
    SA_Depth
    SA_DetailPen
    SA_BlockPen
    SA_Title
    SA_Font
    SA_Type
    SA_BitMap (whose existence also implies CUSTOMBITMAP).

        Several tags are Booleans, which means that depending on whether
        their corresponding ti_Data field is zero (FALSE) or non-zero
        (TRUE), they specify Boolean attributes.  The ones corresponding
        to Boolean flags in the NewScreen.Type field are:

    SA_ShowTitle
    SA_Behind (equiv. to SCREENBEHIND)
    SA_Quiet (equiv. to SCREENQUIET)

        The following tags provide extended information to Intuition
        when creating a screen:

    SA_DisplayID: ti_Data is a 32-bit extended display mode ID
        as defined in [<graphics/displayinfo.h>](../Includes_and_Autodocs_2._guide/node00BD.html)

    SA_Overscan: ti_Data contains a defined constant specifying
        one of the system standard overscan dimensions appropriate for
        the display mode of the screen.  Used with the Width and
        Height dimensions STDSCREENWIDTH and STDSCREEN, this makes
        it trivial to open an overscanned or standard dimension
        screen.  You may also hand-pick your various dimensions
        for overscanned or other screens, by specifying screen position
        and dimensions explicitly, and by using SA_DClip to explicitly
        specify an overscanned DisplayClip region.

        The values for ti_Data of this tag are as follows:

        OSCAN_TEXT - Text Overscan region.  A region which is completely
        on screen and readable ("text safe").  A preferences data
        setting, this is backward equivalent with the old MoreRows,
        and specifies the DisplayClip and default dimensions of the
        Workbench screen.  This is the default.

        OSCAN_STANDARD - Also a preferences setting, this specifies
        a rectangle whose edges are "just out of view."  This yields
        the most efficient position and dimensions of on-monitor
        presentations, such as games and artwork.

        OSCAN_MAX - This is the largest rectangular region that the
        graphics library can handle "comfortably" for a given mode.
        Screens can smoothly scroll (hardware pan) within this region,
        and any DisplayClip or [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) region within this rectangle
        is also legal.  It is not a preferences item, but reflects
        the limits of the graphics hardware and software.

        OSCAN_VIDEO - This is the largest region that the graphics
        library can display, comfortable or not.  There is no guarantee
        that all smaller rectangles are valid.  This region is
        typically out of sight on any monitor or TV, but provides our
        best shot at "edge-to-edge" video generation.

        [Remember](../Includes_and_Autodocs_2._guide/node00D4.html#line1233), using overscan drastically effects memory use and
        chip memory bandwidth.  Always use the smallest (standard)
        overscan region that works for your application.

    SA_DClip: ti_Data is a pointer to a rectangle which explicitly
        defines a DisplayClip region for this screen.  See [QueryOverscan()](../Includes_and_Autodocs_2._guide/node023F.html)
        for the role of the DisplayClip region.

        Except for overscan display screens, this parameter is
        unnecessary, and specifying a standard value using SA_Overscan
        is normally an easier way to get overscan.

    SA_AutoScroll: this is a Boolean tag item, which specifies that
        this screens is to scroll automatically when the mouse pointer
        reaches the edge of the screen.  The operation of this requires
        that the screen dimensions be larger than its DisplayClip
        region.

    SA_PubName: If this field is present (and ti_Data is non-NULL),
        it means that the screen is a public screen, and that
        the public screen name string is pointed to by ti_Data.
        Public screens are opened in "PRIVATE" mode and must
        be made public using [PubScreenStatus()](../Includes_and_Autodocs_2._guide/node023E.html).

    SA_Pens: The ti_Data field (if non-NULL) points to a UWORD
        array of pen specification, as defined for struct [DrawInfo](../Includes_and_Autodocs_2._guide/node00DD.html#line60).
        This array will be used to initialize the screen's
        DrawInfo.dri_Pens array.

        SA_Pens is also used to decide that a screen is ready
        to support the full-blown "new look" graphics.  If you
        want the 3D embossed look, you must provide this tag,
        and the ti_Data value cannot be NULL.  If it points
        to a "minimal" array, containing just the terminator ~0,
        you can specify "new look" without providing any values
        for the pen array.

    The following two tag items specify the task and signal to be issued
    to notify when the last "visitor" window closes on a public screen.
    This support is to assist envisioned public screen manager programs.

    SA_PubTask:  [Task](../Includes_and_Autodocs_2._guide/node008E.html#line25) to be signalled.  If absent (and SA_PubSig is
        valid), use the task which called OpenScreen() or
        [OpenScreenTagList()](../Includes_and_Autodocs_2._guide/node0238.html)).

    SA_PubSig:  Data is a UBYTE signal number (not flag) used to notify
        a task when the last visitor window closes on a public screen.

    SA_Colors: ti_Data points to an array of [ColorSpec](../Includes_and_Autodocs_2._guide/node00D4.html#line1243) structures
        (terminated with ColorIndex = -1) which specify initial
        values of the screen's color palette.

    SA_FullPalette: this is a Boolean attribute.  Prior to V36, there
        were just 7 RGB color values that Intuition maintained
        in its user preferences (playfield colors 0-3, and colors
        17-19 for the sprite).  When opening a screen, the color
        map for the screens viewport is first initialized by
        graphics [(graphics.library/GetColorMap()](../Includes_and_Autodocs_2._guide/node0445.html)) then these
        seven values are overridden to take the preferences values.

        In V36, Intuition maintains a full set of 32 preferences colors.
        If you specify TRUE for SA_FullPalette, Intuition will
        override ALL color map entries with its full suite of
        preferred colors.

    SA_ErrorCode: ti_Data points to a ULONG in which Intuition will
        stick an extended error code if OpenScreen[TagList]() fails.
        Values are of this include 0, for success, and:
        OSERR_NOMONITOR     - monitor for display mode not available.
        OSERR_NOCHIPS       - you need newer custom chips for display mode.
        OSERR_NOMEM         - couldn't get normal memory
        OSERR_NOCHIPMEM     - couldn't get chip memory
        OSERR_PUBNOTUNIQUE  - public screen name already used
        OSERR_UNKNOWNMODE   - don't recognize display mode requested

        NOTE: These values are not the same as some similar return
        values defined in [graphics.library/ModeNotAvailable()](../Includes_and_Autodocs_2._guide/node045C.html).

    SA_SysFont: ti_Data selects one of the system standard fonts
        specified in preferences.  This tag item overrides the
        NewScreen.Font field and the SA_Font tag item.

        Values recognized in ti_Data at present are:
            0 - old DefaultFont, fixed-width, the default.
            1 - Workbench screen preferred font.  You have to
                be very font sensitive to handle a proportional or
                larger than traditional screen font.

        NOTE WELL: if you select sysfont 1, windows opened on
        your screen will not inherit the screen font, but rather
        the window [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) will be initialized to the old-style
        DefaultFont (sysfont 0).
