---
title: intuition.library/OpenScreen
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-openscreen-2
functions: [CloseScreen, CloseWindow, GetColorMap, InstallLayerInfoHook, LoadRGB32, ModeNotAvailable, ObtainPen, OpenDiskFont, OpenScreen, OpenScreenTagList, OpenWindow, PrintIText, PubScreenStatus, QueryOverscan, ScreenDepth, ScreenPosition, ShowTitle, VideoControl]
libraries: [diskfont.library, graphics.library, intuition.library, layers.library]
---

# intuition.library/OpenScreen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	OpenScreen -- [Open](autodocs-3.5/dos-library-open-2.md) an Intuition screen.

    SYNOPSIS
	[Screen](autodocs-3.5/include-intuition-screens-h.md) = OpenScreen( [NewScreen](autodocs-3.5/include-intuition-screens-h.md) )
	D0		     A0

	struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *OpenScreen( struct [NewScreen](autodocs-3.5/include-intuition-screens-h.md) * );

	or

	struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *OpenScreen( struct [ExtNewScreen](autodocs-3.5/include-intuition-screens-h.md) * );

    FUNCTION
	Opens an Intuition screen according to the specified parameters
	found in the [NewScreen](autodocs-3.5/include-intuition-screens-h.md) structure.

	Does all the allocations, sets up the screen structure and all
	substructures completely, and links this screen's viewport into
	Intuition's [View](autodocs-3.5/include-graphics-view-h.md) structure.

	Before you call OpenScreen(), you must initialize an instance of
	a [NewScreen](autodocs-3.5/include-intuition-screens-h.md) structure.  [NewScreen](autodocs-3.5/include-intuition-screens-h.md) is a structure that contains
	all of the arguments needed to open a screen.  The [NewScreen](autodocs-3.5/include-intuition-screens-h.md)
	structure may be discarded immediately after OpenScreen() returns.

	The SHOWTITLE flag is set to TRUE by default when a screen is opened.
	To change this, you must call the routine [ShowTitle()](autodocs-3.5/intuition-library-showtitle-2.md).

    INPUTS
	[NewScreen](autodocs-3.5/include-intuition-screens-h.md) = pointer to an instance of a [NewScreen](autodocs-3.5/include-intuition-screens-h.md) structure.

	New for V36:
	In addition to the information contained in the [NewScreen](autodocs-3.5/include-intuition-screens-h.md) structure,
	Intuition now recognizes extended data passed in the form
	of an array of [TagItem](autodocs-3.5/include-utility-tagitem-h.md) structures (from [<utility/tagitem.h>](autodocs-3.5/include-utility-tagitem-h.md)),
	commonly called a "tag list."

	There are two ways to provide this array.  The first is to
	use the new Intuition entry point [OpenScreenTagList()](autodocs-3.5/intuition-library-openscreentaglist-2.md) and
	pass the tag list as a parameter.  This is the recommended
	method, and has a convenient format variation for C programs
	using a variable number of arguments.

	An older way used for some V36 development uses the OpenScreen()
	entry point, and an extension of the [NewScreen](autodocs-3.5/include-intuition-screens-h.md) structure named
	[ExtNewScreen](autodocs-3.5/include-intuition-screens-h.md).  See the documentation of the flag NS_EXTENDED,
	below.

	While we recommend that you use [OpenScreenTagList()](autodocs-3.5/intuition-library-openscreentaglist-2.md) rather than
	OpenScreen() when using the extension tag list, we document
	the tag ID values here, so that all parameters for opening
	a screen can be found in one place.

	[NewScreen](autodocs-3.5/include-intuition-screens-h.md) is initialized with the following information:
	-------------------------------------------------------------
	Left = initial x-position of your screen (should be zero for
	releases prior to V36)

	Top = initial y-position of the opening screen
	(Note: Left and Top are specified relative to the Intuition's view,
	in same resolution as the screen pixels.)

	Width = the width for this screen's [RastPort](autodocs-3.5/include-graphics-rastport-h.md)

	Height = the height for this screen's [RastPort](autodocs-3.5/include-graphics-rastport-h.md), or the constant
		STDSCREENHEIGHT to get the current default height (at
		this time guaranteed to be at least 200 rows).  The normal
		width and height for a particular system is stored by
		the graphics.library in GfxBase->NormalDisplayRows and
		GfxBase->NormalDisplayColumns.  These values will be different
		depending on factors such as PAL video and overscan.

		For V36, a new constant STDSCREENWIDTH is introduced.  It
		serves the similar function for screen width.  Both
		STDSCREENWIDTH and STDSCREENHEIGHT indicate that your
		screen [RastPort](autodocs-3.5/include-graphics-rastport-h.md) is to be the same dimensions as your
		DisplayClip rectangle.  If you do not specify either a
		standard or custom DisplayClip, the OSCAN_TEXT region
		will be used, which corresponds to the standard dimensions
		of V35 and earlier.

		Furthermore, if you are using [OpenScreenTagList()](autodocs-3.5/intuition-library-openscreentaglist-2.md), and you
		specify STDSCREENWIDTH, and you DO NOT provide a [NewScreen](autodocs-3.5/include-intuition-screens-h.md)
		pointer, and you DO NOT provide sA_Left, then Intuition
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
		in the bitmap field of the [NewScreen](autodocs-3.5/include-intuition-screens-h.md) structure.  Intuition is
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
```c
           These include:
           HIRES for this screen to be HIRES width.
           LACE for the display to switch to interlace.
           SPRITES for this screen to use sprites (the pointer
```
		sprite is always displayed)
```c
           DUALPF for dual-playfield mode (not supported yet)
```
	    [For V36: The ViewModes field is superseded by a [TagItem](autodocs-3.5/include-utility-tagitem-h.md) with
	    tag value SA_DisplayID.]

	Font = pointer to the default [TextAttr](autodocs-3.5/include-graphics-text-h.md) structure for text in this
	    screen and all windows that open in this screen.  [Text](autodocs-3.5/graphics-library-text-2.md) that uses
	    this [TextAttr](autodocs-3.5/include-graphics-text-h.md) includes title bars of both screen and windows,
	    string gadgets, and menu titles.  Of course, [IntuiText](autodocs-3.5/include-intuition-intuition-h.md) that
	    specifies a NULL [TextAttr](autodocs-3.5/include-graphics-text-h.md) field will use the screen/window default
	    fonts.  NOTE: Intuition will *NOT* call [OpenDiskFont()](autodocs-3.5/diskfont-library-opendiskfont-2.md), so
	    the [TextAttr](autodocs-3.5/include-graphics-text-h.md) you supply must be in memory.  The ways to ensure
	    that are to either use a ROM font (Topaz 8 or 9) or first
	    call [OpenDiskFont()](autodocs-3.5/diskfont-library-opendiskfont-2.md) to load the font, and don't close it
	    until after your screen is successfully opened.
	    [For V36: this is superseded by SA_Font and SA_SysFont.]

	DefaultTitle = pointer to a line of text that will be displayed along
	    the screen's title bar.  Null terminated, or just a NULL pointer
           to get no text
	    [For V36: superseded by SA_Title.]

	Gadgets = This field should be set to NULL, since no user gadgets may
	    be attached to a screen with the current versions of Intuition.

	CustomBitMap = if you're not supplying a custom bitmap, this value is
           ignored.  However, if you have your own display memory that you
           want used for this screen, the CustomBitMap field should point to
	    the [BitMap](autodocs-3.5/include-graphics-gfx-h.md) structure that describes your display memory.  See the
           "Screens" chapter and the "Amiga ROM Kernel Manual" for more
           information about bitmaps.
	    [For V36: this is superseded by SA_BitMap.]

	[ All [TagItem](autodocs-3.5/include-utility-tagitem-h.md) extensions below are new for V36.]
	Extension = if NS_EXTENDED is set in NewScreen.Type, this pointer
	    should point to an array (or chain of arrays) of TagItems,
	    as defined in the include file [<utility/tagitem.h>](autodocs-3.5/include-utility-tagitem-h.md).   This
	    field is only defined in the structure [ExtNewScreen](autodocs-3.5/include-intuition-screens-h.md).
	    The values to use for TagItem.ti_Tag are defined below.  We
	    recommend that V36-specific applications use the new Intuition
	    entry point [OpenScreenTagList()](autodocs-3.5/intuition-library-openscreentaglist-2.md), rather than using this field.
	    The [ExtNewScreen](autodocs-3.5/include-intuition-screens-h.md) structure is a convenient way to give V36
	    Intuition some information that V34 and earlier Intuition will
	    ignore.

	    Each [TagItem](autodocs-3.5/include-utility-tagitem-h.md) is an optional tagged data structure which identifies
	    an additional parameter to OpenScreen().  The applicable tag ID
	    values for TagItem.ti_Tag and their corresponding data follow.

	    Several of the tag items are alternative (and overriding) versions
	    to familiar fields in [NewScreen](autodocs-3.5/include-intuition-screens-h.md).  (Defaults only apply if
	    [NewScreen](autodocs-3.5/include-intuition-screens-h.md) == NULL).  They are:

	SA_Left
	SA_Top
	SA_Width
	SA_Height
	    The defaults for the SA_Left, SA_Top, SA_Width, and
	    SA_Height tags end up being a bit complex.  If none of
	    these tags are specified, and no [NewScreen](autodocs-3.5/include-intuition-screens-h.md) structure is
	    used, then the left/top/width/height correctly match the
	    display clip of your screen (see SA_DClip and
	    SA_Overscan).

	    The difficulty comes with overscanned screens, because the
	    normal value of SA_Left or SA_Top for such a screen may be
	    non-zero.  If a [NewScreen](autodocs-3.5/include-intuition-screens-h.md) structure is supplied, then the
	    left/top/width/height come originally from there.  If no
	    [NewScreen](autodocs-3.5/include-intuition-screens-h.md) structure is supplied, but a non-default
	    SA_Width (SA_Height) is specified, then SA_Left (SA_Top)
	    defaults to zero instead.  In these cases, the left and
	    top edge may not be what you want.

	    If you need to specify explicit width or height, or supply
	    a [NewScreen](autodocs-3.5/include-intuition-screens-h.md), you must supply correct values for SA_Left
	    and SA_Top.  The correct normal values are the display
	    clip rectangle's MinX and MinY values respectively.  If
	    you are using the SA_DClip tag, then you already have a
	    rectangle to consult for these values.  If you are using
	    SA_Overscan to get one of the standard overscan types, you
	    may use [QueryOverscan()](autodocs-3.5/intuition-library-queryoverscan-2.md) to get a rectangle for that
	    overscan type.

	SA_Depth (defaults to 1)
	SA_DetailPen (defaults to 0)
	SA_BlockPen (defaults to 1)
	SA_Title (defaults to NULL)
	SA_Font (defaults to NULL, meaning user's preferred monospace font)
	SA_BitMap (whose existence also implies CUSTOMBITMAP).

	    Several tags are Booleans, which means that depending on whether
	    their corresponding ti_Data field is zero (FALSE) or non-zero
	    (TRUE), they specify Boolean attributes.  The ones corresponding
	    to Boolean flags in the NewScreen.Type field are:

	SA_ShowTitle (defaults to TRUE)
	SA_Behind (equiv. to SCREENBEHIND) (defaults to FALSE)
	SA_Quiet (equiv. to SCREENQUIET) (defaults to FALSE)

	    The following tags provide extended information to Intuition
	    when creating a screen:

	SA_Type: ti_Data corresponds to the SCREENTYPE bits of the
	    NewScreen.Type field.  This should be one of PUBLICSCREEN or
	    CUSTOMSCREEN.  The other bits of the NewScreen.Type field
	    must be set with the appropriate tags (SA_Behind, SA_Quiet,
	    etc.)

	SA_DisplayID: ti_Data is a 32-bit extended display mode ID, as
	  defined in the [<graphics/modeid.h>](autodocs-3.5/include-graphics-modeid-h.md) include file (V39 and up)
	  or in [<graphics/displayinfo.h>](autodocs-3.5/include-graphics-displayinfo-h.md) (V37 and V38).

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

	    OSCAN_TEXT - [Text](autodocs-3.5/graphics-library-text-2.md) Overscan region.  A region which is completely
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
	    and any DisplayClip or [Screen](autodocs-3.5/include-intuition-screens-h.md) region within this rectangle
	    is also legal.  It is not a preferences item, but reflects
	    the limits of the graphics hardware and software.

	    OSCAN_VIDEO - This is the largest region that the graphics
	    library can display, comfortable or not.  There is no guarantee
	    that all smaller rectangles are valid.  This region is
	    typically out of sight on any monitor or TV, but provides our
	    best shot at "edge-to-edge" video generation.

	    [Remember](autodocs-3.5/include-intuition-intuition-h.md), using overscan drastically effects memory use and
	    chip memory bandwidth.  Always use the smallest (standard)
	    overscan region that works for your application.

	SA_DClip: ti_Data is a pointer to a rectangle which explicitly
	    defines a DisplayClip region for this screen.  See [QueryOverscan()](autodocs-3.5/intuition-library-queryoverscan-2.md)
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
	    be made public using PubScreenStatus( screen, 0 ).

	SA_Pens: The ti_Data field (if non-NULL) points to a [UWORD](autodocs-3.5/include-exec-types-h.md)
	    array of pen specification, as defined for struct [DrawInfo](autodocs-3.5/include-intuition-screens-h.md).
	    This array will be used to initialize the screen's
	    DrawInfo.dri_Pens array.

	    SA_Pens is also used to decide that a screen is ready
	    to support the full-blown "new look" graphics.  If you
	    want the 3D embossed look, you must provide this tag,
	    and the ti_Data value cannot be NULL.  If it points
	    to a "minimal" array, containing just the terminator ~0,
	    you can specify "new look" without providing any values
	    for the pen array.

	    The way the [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) pens are determined is Intuition
	    picks a default pen-array.  Then, any pens you supply with
	    SA_Pens override the defaults, up until the ~0 in your
	    array.

	    If the screen is monochrome or old-look, the default will
	    be the standard two-color pens.

	    If the screen is two or more planes deep, the default will
	    be the standard four-color pens, which now include the
	    new-look menu colors.

	    If the screen has the SA_LikeWorkbench property, the
	    default will be the user's preferred pen-array, changeable
	    through preferences.

	The following two tag items specify the task and signal to be issued
	to notify when the last "visitor" window closes on a public screen.
	This support is to assist envisioned public screen manager programs.

	SA_PubTask:  [Task](autodocs-3.5/include-exec-tasks-h.md) to be signalled.  If absent (and SA_PubSig is
	    valid), use the task which called OpenScreen() or
	    [OpenScreenTagList()](autodocs-3.5/intuition-library-openscreentaglist-2.md)).

	SA_PubSig:  Data is a [UBYTE](autodocs-3.5/include-exec-types-h.md) signal number (not flag) used to notify
	    a task when the last visitor window closes on a public screen.

	SA_Colors: ti_Data points to an array of [ColorSpec](autodocs-3.5/include-intuition-intuition-h.md) structures
	    (terminated with ColorIndex = -1) which specify initial
	    values of the screen's color palette.

	SA_FullPalette: this is a Boolean attribute.  Prior to V36, there
	    were just 7 RGB color values that Intuition maintained
	    in its user preferences (playfield colors 0-3, and colors
	    17-19 for the sprite).  When opening a screen, the color
	    map for the screens viewport is first initialized by
	    graphics [(graphics.library/GetColorMap()](autodocs-3.5/graphics-library-getcolormap-2.md)) then these
	    seven values are overridden to take the preferences values.

	    In V36, Intuition maintains a full set of 32 preferences colors.
	    If you specify TRUE for SA_FullPalette, Intuition will
	    override ALL color map entries with its full suite of
	    preferred colors.  (Defaults to FALSE).

	SA_ErrorCode: ti_Data points to a ULONG in which Intuition will
	    stick an extended error code if OpenScreen[TagList]() fails.
	    Values are of this include 0, for success, and:
	    OSERR_NOMONITOR	- monitor for display mode not available.
	    OSERR_NOCHIPS	- you need newer custom chips for display mode.
	    OSERR_NOMEM		- couldn't get normal memory
	    OSERR_NOCHIPMEM	- couldn't get chip memory
	    OSERR_PUBNOTUNIQUE	- public screen name already used
	    OSERR_UNKNOWNMODE	- don't recognize display mode requested
	    OSERR_TOODEEP	- screen too deep to be displayed on
				  this hardware (V39)
	    OSERR_ATTACHFAIL	- An illegal attachment of screens was
				  requested (V39)

	    NOTE: These values are not the same as some similar return
	    values defined in [graphics.library/ModeNotAvailable()](autodocs-3.5/graphics-library-modenotavailable-2.md).

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
	    the window [RastPort](autodocs-3.5/include-graphics-rastport-h.md) will be initialized to the old-style
	    DefaultFont (sysfont 0).

	Attached screen tags:  V39 supports attached screens, where
	    one or more child screens can be associated with a parent
	    screen.  Attached screens depth-arrange as a group, and
	    always remain adjacent depth-wise.  Independent
	    depth-arrangement of child screens is possible through
	    the V39 [ScreenDepth()](autodocs-3.5/intuition-library-screendepth.md) call.  If a child screen is
	    made non-draggable through {SA_Draggable, FALSE}, then
	    it will drag exclusively with the parent.  Normal child
	    screens drag independently of the parent, but are pulled
	    down when the parent is.  Use the SA_Parent, SA_FrontChild,
	    and SA_BackChild tags to attach screens.

	SA_Parent:  If you wish to attach this screen to an
	    already-open parent screen, use this tag and set
	    ti_Data to point to the parent screen.  See also
	    SA_FrontChild and SA_BackChild.  (V39).

	SA_FrontChild:  If you wish to attach an already-open child
	    screen to this screen, set ti_Data to point to the child
	    screen.  The child screen will come to the front of the
	    family defined by the parent screen you are opening.  See
	    also SA_Parent and SA_BackChild.  (V39)

	SA_BackChild:  If you wish to attach an already-open child
	    screen to this screen, set ti_Data to point to the child
	    screen.  The child screen will go to the back of the family
	    defined by the parent screen you are opening.  See also
	    SA_Parent and SA_FrontChild.  (V39)

	SA_BackFill:  ti_Data is a pointer to a backfill hook for
	    the screen's [Layer_Info](autodocs-3.5/include-graphics-layers-h.md).
	    (see layers.library/InstallLayerInfoHook()).  (V39).

	SA_Draggable:  ti_Data is a boolean.  Set to FALSE if you
	    wish your screen to be non-draggable.  This tag should be
	    used very sparingly!.  Defaults to TRUE.  For child screens
	    (see SA_Parent, SA_FrontChild, and SA_BackChild) this tag
	    has a slightly different meaning:  non-draggable child
	    screens are non-draggable with respect to their parent,
	    meaning they always drag exactly with the parent, as
	    opposed to having relative freedom.  Also see
	    [ScreenPosition()](autodocs-3.5/intuition-library-screenposition.md).  (V39)

	SA_Exclusive:  ti_Data is a boolean.  Set to TRUE if you
	    never want your screen to share the display with another
	    screen.  This means that your screen can't be pulled down,
	    and will not appear behind other screens that are pulled
	    down.  Your screen may still be depth arranged, though.  Use
	    this tag sparingly!  Defaults to FALSE.  Starting with V40,
	    attached screens may be SA_Exclusive.  Setting SA_Exclusive
	    for each screen will produce an exclusive family.  (V39).

	SA_SharePens:  For those pens in the screen's
	    DrawInfo->dri_Pens, Intuition obtains them in shared mode
	    (see graphics.library/ObtainPen()).  For compatibility,
	    Intuition obtains the other pens of a public screen as
	    PENF_EXCLUSIVE.  Screens that wish to manage the pens
	    themselves should generally set this tag to TRUE.  This
	    instructs Intuition to leave the other pens unallocated.
	    Defaults to FALSE.  (V39).

	SA_Colors32:  [Tag](autodocs-3.5/include-utility-tagitem-h.md) to set the screen's initial palette colors
	    at 32 bits-per-gun.  ti_Data is a pointer to a table to be
	    passed to the [graphics.library/LoadRGB32()](autodocs-3.5/graphics-library-loadrgb32.md) function.  This
	    format supports both runs of color registers and sparse
	    registers.  See the autodoc for that function for full
	    details.  Any color set here has precedence over the same
	    register set by SA_Colors.  (V39).

	SA_Interleaved:  ti_Data is a boolean.  Set to TRUE to
	    request an interleaved bitmap for your screen.  Defaults to
	    FALSE.  If the system cannot allocate an interleaved bitmap for
	    you, it will attempt to allocate a non-interleaved one (V39).

	SA_VideoControl:  ti_Data points to a taglist that will be
	    passed to [VideoControl()](autodocs-3.5/graphics-library-videocontrol-2.md) after your screen is open.  You
	    might use this to turn on border-sprites, for example.
	    (V39).

	SA_ColorMapEntries:  ti_Data is the number of entries that
	    you wish Intuition to allocate for this screen's [ColorMap](autodocs-3.5/include-graphics-view-h.md).
	    While Intuition allocates a suitable number for ordinary
	    use, certain graphics.library features require a
	    [ColorMap](autodocs-3.5/include-graphics-view-h.md) which is larger than default.  (The default value is
	    1<<depth, but not less than 32).  (V39)

	SA_LikeWorkbench:  ti_Data is boolean.  Set to TRUE to get
	    a screen just like the Workbench screen.  This is the
	    best way to inherit all the characteristics of the
	    Workbench, including depth, colors, pen-array, screen mode,
	    etc.  Individual attributes can be overridden through the
	    use of tags.  (SA_LikeWorkbench itself overrides things
	    specified in the [NewScreen](autodocs-3.5/include-intuition-screens-h.md) structure).  Attention
	    should be paid to hidden assumptions when doing this.  For
	    example, setting the depth to two makes assumptions about
	    the pen values in the [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) pens.  Note that this
	    tag requests that Intuition ATTEMPT to open the screen
	    to match the Workbench.  There are fallbacks in case
	    that fails, so it is not correct to make enquiries about
	    the Workbench screen then make strong assumptions about
	    what you're going to get.  (Defaults to FALSE).  (V39)

 	SA_MinimizeISG:  ti_Data is boolean.  For compatibility,
	    Intuition always ensures that the inter-screen gap is at
	    least three non-interlaced lines.  If your application
	    would look best with the smallest possible inter-screen
	    gap, set ti_Data to TRUE.  If you use the new graphics
	    [VideoControl()](autodocs-3.5/graphics-library-videocontrol-2.md) VC_NoColorPaletteLoad tag for your screen's
	    [ViewPort](autodocs-3.5/include-graphics-view-h.md), you should also set this tag.  (V40)


    RESULT
	If all is well, returns the pointer to your new screen
	If anything goes wrong, returns NULL, with further error
	specification in the variable pointed to by the SA_ErrorCode
	data field (V36 and later).

    NOTES
	By default, AmigaDOS requesters related to your process are put on
	the Workbench screen (these are messages like "Disk Full").  If
	you wish them to show up on custom screens, DOS must be told.
	This fragment shows the procedure.  More information is available
	in the AmigaDOS manuals.  Sample code fragment:

	#include "libraries/dosextens.h"
		...
	struct [Process](autodocs-3.5/include-dos-dosextens-h.md)	*process;
	struct [Window](autodocs-3.5/include-intuition-intuition-h.md)	*window;
	[APTR](autodocs-3.5/include-exec-types-h.md)		temp;
		...
		process = (struct [Process](autodocs-3.5/include-dos-dosextens-h.md) *) FindTask(NULL);
		temp = process->pr_WindowPtr;	(save old value)
		process->pr_WindowPtr = (APTR) window;
		( use a pointer to any open window on your screen )
			...
		your code goes here
			...
		process->pr_WindowPtr = temp;
		( restore value BEFORE [CloseWindow()](autodocs-3.5/intuition-library-closewindow-2.md) )
		CloseWindow(window);

	A VERY IMPORTANT NOTE about the Screen->BitMap.  In the future,
	bitmaps will need to grow.  The embedded instance of a bitmap
	in the screen will no longer be large enough to hold the whole
	description of the bitmap.

	YOU ARE STRONGLY URGED to use Screen->RastPort.BitMap in place of
	&Screen->BitMap whenever and whereever possible.

    BUGS

    SEE ALSO
	[OpenScreenTagList()](autodocs-3.5/intuition-library-openscreentaglist-2.md), [OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md), [PrintIText()](autodocs-3.5/intuition-library-printitext-2.md), [CloseScreen()](autodocs-3.5/intuition-library-closescreen-2.md),
	[QueryOverscan()](autodocs-3.5/intuition-library-queryoverscan-2.md) [PubScreenStatus()](autodocs-3.5/intuition-library-pubscreenstatus-2.md), The Intuition Reference Manual,
	[utility/tagitem.h](autodocs-3.5/include-utility-tagitem-h.md), [graphics.library/ModeNotAvailable()](autodocs-3.5/graphics-library-modenotavailable-2.md),
	[diskfont.library/OpenDiskFont()](autodocs-3.5/diskfont-library-opendiskfont-2.md), [graphics.library/GetColorMap()](autodocs-3.5/graphics-library-getcolormap-2.md)

---

## See Also

- [CloseScreen — intuition.library](../autodocs/intuition.library.md#closescreen)
- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [InstallLayerInfoHook — layers.library](../autodocs/layers.library.md#installlayerinfohook)
- [LoadRGB32 — graphics.library](../autodocs/graphics.library.md#loadrgb32)
- [ModeNotAvailable — graphics.library](../autodocs/graphics.library.md#modenotavailable)
- [ObtainPen — graphics.library](../autodocs/graphics.library.md#obtainpen)
- [OpenDiskFont — diskfont.library](../autodocs/diskfont.library.md#opendiskfont)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenScreenTagList — intuition.library](../autodocs/intuition.library.md#openscreentaglist)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [PrintIText — intuition.library](../autodocs/intuition.library.md#printitext)
- [PubScreenStatus — intuition.library](../autodocs/intuition.library.md#pubscreenstatus)
- [QueryOverscan — intuition.library](../autodocs/intuition.library.md#queryoverscan)
- [ScreenDepth — intuition.library](../autodocs/intuition.library.md#screendepth)
- [ScreenPosition — intuition.library](../autodocs/intuition.library.md#screenposition)
- [ShowTitle — intuition.library](../autodocs/intuition.library.md#showtitle)
- [VideoControl — graphics.library](../autodocs/graphics.library.md#videocontrol)
