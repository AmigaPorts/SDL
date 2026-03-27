---
title: intuition.library/OpenWindow
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-openwindow-2
functions: [BeginRefresh, ChangeWindowBox, CloseWindow, EndRefresh, Forbid, GetUniqueID, HelpControl, InstallLayerHook, LockPubScreen, ModifyIDCMP, NewObject, OpenScreen, OpenScreenTagList, OpenWindow, OpenWindowTagList, ReportMouse, SetDefaultPubScreen, SetMouseQueue, SetPubScreenModes, SetWindowPointerA, SetWindowTitles, SizeWindow, UnlockPubScreen, WindowLimits, ZipWindow]
libraries: [exec.library, intuition.library, layers.library, utility.library]
---

# intuition.library/OpenWindow

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	OpenWindow -- [Open](autodocs-3.5/dos-library-open-2.md) an Intuition window.

    SYNOPSIS
   	[Window](autodocs-3.5/include-intuition-intuition-h.md) = OpenWindow( [NewWindow](autodocs-3.5/include-intuition-intuition-h.md) )
	D0                   A0

	struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *OpenWindow( struct [NewWindow](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	Opens an Intuition window of the given dimensions and position,
	with the properties specified in the [NewWindow](autodocs-3.5/include-intuition-intuition-h.md) structure.
	Allocates everything you need to get going.

	New for V36: there is an extensive discussion of public Screens
	and visitor windows at the end of this section.  Also,
	you can provide extensions to the [NewWindow](autodocs-3.5/include-intuition-intuition-h.md) parameters using
	and array of [TagItem](autodocs-3.5/include-utility-tagitem-h.md) structures.  See the discussion below,
	and the documentation for the function [OpenScreenTagList()](autodocs-3.5/intuition-library-openscreentaglist-2.md).

	Before you call OpenWindow(), you must initialize an instance of
	a [NewWindow](autodocs-3.5/include-intuition-intuition-h.md) structure.  [NewWindow](autodocs-3.5/include-intuition-intuition-h.md) is a structure that contains
	all of the arguments needed to open a window.  The [NewWindow](autodocs-3.5/include-intuition-intuition-h.md)
	structure may be discarded immediately after it is used to open
	the window.

	If Type == CUSTOMSCREEN, you must have opened your own screen
	already via a call to [OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md).  Then Intuition uses your screen
	argument for the pertinent information needed to get your window
	going.  On the other hand, if type == one of the Intuition's standard
	screens, your screen argument is ignored.  Instead,
	Intuition will check to see whether or not that screen
	already exists:  if it doesn't, it will be opened first before
	Intuition opens your window in the standard screen.

	New for V36: If you specify Type == WBENCHSCREEN, then your
	window will appear on the Workbench screen, unless the global
	public screen mode SHANGHAI is set, in which case your window
	will be "hijacked" to the default public screen.  See also
	[SetPubScreenModes()](autodocs-3.5/intuition-library-setpubscreenmodes-2.md).

	New for V36: If the WFLG_NW_EXTENDED flag is set, it means that the
	field 'ExtNewWindow->Extension' points to an array of TagItems, as
	defined in intuition/tagitem.h.  This provides an extensible means
	of providing extra parameters to OpenWindow.  For compatibility
	reasons, we could not add the 'Extension' field to the [NewWindow](autodocs-3.5/include-intuition-intuition-h.md)
	structure, so we have define a new structure [ExtNewWindow](autodocs-3.5/include-intuition-intuition-h.md), which
	is identical to [NewWindow](autodocs-3.5/include-intuition-intuition-h.md) with the addition of the Extension field.

	We recommend that rather than using ExtNewWindow.Extension, you
	use the new Intuition function [OpenWindowTagList()](autodocs-3.5/intuition-library-openwindowtaglist-2.md) and its
	varargs equivalent OpenWindowTags().  We document the window
	attribute tag ID's (ti_Tag values) here, rather than in
	[OpenWindowTagList()](autodocs-3.5/intuition-library-openwindowtaglist-2.md), so that you can find all the parameters
	for a new window defined in one place.

	If the WFLG_SUPER_BITMAP flag is set, the bitmap variable must point
	to your own bitmap.

	The DetailPen and the BlockPen are used for system rendering; for
	instance, the title bar is first filled using the BlockPen, and then
	the gadgets and text are rendered using DetailPen.  You can either
	choose to supply special pens for your window, or, by setting either
	of these arguments to -1, the screen's pens will be used instead.

	Note for V36: The DetailPen and BlockPen no longer determine
	what colors will be used for window borders, if your window
	opens on a "full-blown new look screen."

    INPUTS
	[NewWindow](autodocs-3.5/include-intuition-intuition-h.md) = pointer to an instance of a [NewWindow](autodocs-3.5/include-intuition-intuition-h.md) structure.  That
               structure is initialized with the following data:
   -------------------------------------------------------------------------
	Left = the initial x-position for your window
	Top = the initial y-position for your window
	Width = the initial width of this window
	Height = the initial height of this window

	DetailPen = pen number (or -1) for the rendering of window details
```c
         (like gadgets or text in title bar)
```
	BlockPen = pen number (or -1) for window block fills (like title bar)
	[For V36: Title bar colors are determined otherwise.]

	Flags = specifiers for your requirements of this window, including:
	     which system gadgets you want attached to your window:

	    - WFLG_DRAGBAR allows this window to be dragged
	    - WFLG_DEPTHGADGET lets the user depth-arrange this window
	    - WFLG_CLOSEGADGET attaches the standard close gadget
	    - WFLG_SIZEGADGET allows this window to be sized.

	    If you ask for the WFLG_SIZEGADGET gadget, you must specify one or
	    both of the flags WFLG_SIZEBRIGHT and WFLG_SIZEBBOTTOM below; if
	    you don't, the default is WFLG_SIZEBRIGHT.  See the following items
	    WFLG_SIZEBRIGHT and WFLG_SIZEBBOTTOM for more details.

	    - WFLG_SIZEBRIGHT is a special system gadget flag that
	      you set to specify whether or not you want the
	      RIGHT border adjusted to account for the physical size
	      of the sizing gadget.  The sizing gadget must, after
	      all, take up room in either the right or bottom border
	      (or both, if you like) of the window.  Setting either
	      this or the WFLG_SIZEBBOTTOM flag selects which edge
	      will take up the slack.  This will be particularly
	      useful to applications that want to use the extra space
	      for other gadgets (like a proportional gadget and two
	      Booleans done up to look like scroll bars) or, for
	      for instance, applications that want every possible
	      horizontal bit and are willing to lose lines vertically.
	      NOTE:  if you select WFLG_SIZEGADGET, you must select
	      either WFLG_SIZEBRIGHT or WFLG_SIZEBBOTTOM or both.  If
	      you select neither, the default is WFLG_SIZEBRIGHT.
	    - WFLG_SIZEBBOTTOM is a special system gadget flag that
	      you set to specify whether or not you want the
	      BOTTOM border adjusted to account for the physical size
	      of the sizing gadget.  For details, refer to
	      WFLG_SIZEBRIGHT above.

	    - WFLG_GIMMEZEROZERO for easy but expensive output

	    what type of window layer you want, either:
	    - WFLG_SIMPLE_REFRESH
	    - WFLG_SMART_REFRESH
	    - WFLG_SUPER_BITMAP

	    - WFLG_BACKDROP for whether or not you want this window to be one
	      of Intuition's special backdrop windows.  See WFLG_BORDERLESS
	      as well.

	    - WFLG_REPORTMOUSE for whether or not you want to "listen" to
	      mouse movement events whenever your window is the active
	      one.  After you've opened your window, if you want to change
	      you can later change the status of this via a call to
	      [ReportMouse()](autodocs-3.5/intuition-library-reportmouse-2.md).  Whether or not your window is listening to
	      mouse is affected by gadgets too, since they can cause you
	      to start getting reports too if you like.  The mouse move
	      reports (either InputEvents or messages on the IDCMP) that
	      you get will have the x/y coordinates of the current mouse
	      position, relative to the upper-left corner of your window
	      (WFLG_GIMMEZEROZERO notwithstanding).  This flag can work in
	      conjunction with the IDCMP Flag called IDCMP_MOUSEMOVE, which
	      allows you to listen via the IDCMP.

	    - WFLG_BORDERLESS should be set if you want a window with no
	      border padding.  Your window may have the border variables
	      set anyway, depending on what gadgetry you've requested for
	      the window, but you won't get the standard border lines and
	      spacing that comes with typical windows.

	      This is a good way to take over the entire screen, since you
	      can have a window cover the entire width of the screen using
	      this flag.  This will work particularly well in conjunction
	      with the WFLG_BACKDROP flag (see above), since it allows you
	      to open a window that fills the ENTIRE screen.  NOTE:  this is
	      not a flag that you want to set casually, since it may cause
	      visual confusion on the screen.  The window borders are the
	      only dependable visual division between various windows and
	      the background screen.  Taking away that border takes away
	      that visual cue, so make sure that your design doesn't need
	      it at all before you proceed.

	    - WFLG_ACTIVATE is the flag you set if you want this window to
	      automatically become the active window.  The active
	      window is the one that receives input from the keyboard and
	      mouse.  It's usually a good idea to to have the window you
	      open when your application first starts up be an ACTIVATED
	      one, but all others opened later not be ACTIVATED (if the
	      user is off doing something with another screen, for
	      instance, your new window will change where the input is
	      going, which would have the effect of yanking the input rug
	      from under the user).  Please use this flag thoughtfully and
	      carefully.

	      Some notes: First, your window may or may not be active
	      by the time this function returns.  Use the IDCMP_ACTIVEWINDOW
	      IDCMP message to know when your window has become active.
	      Also, be very careful not to mistakenly specify the
	      obsolete flag names WINDOWACTIVE or ACTIVEWINDOW.  These are
	      used in other contexts, and their values unintentionally added
	      to your flags can cause most unfortunate results.  To avoid
	      confusion, they are now know as WFLG_WINDOWACTIVE and
	      IDCMP_ACTIVEWINDOW.

	    - WFLG_RMBTRAP, when set, causes the right mouse button events
	      to be trapped and broadcast as events.  You can receive
	      these events through either the IDCMP or the console.

	    - WFLG_NOCAREREFRESH indicates that you do not wish to
	      be responsible for calling [BeginRefresh()](autodocs-3.5/intuition-library-beginrefresh-2.md) and [EndRefresh()](autodocs-3.5/intuition-library-endrefresh-2.md)
	      when your window has exposed regions (i.e., when the
	      IDCMP_REFRESHWINDOW message would be generated).  See also
	      the descriptions of these two functions.

	    - WFLG_NW_EXTENDED (V36) indicates that [NewWindow](autodocs-3.5/include-intuition-intuition-h.md) in fact points
	      to an [ExtNewWindow](autodocs-3.5/include-intuition-intuition-h.md) structure, and that the 'Extension'
	      field points to an array of [TagItem](autodocs-3.5/include-utility-tagitem-h.md) structures, with
	      meaning described below.

	    - WFLG_NEWLOOKMENUS (V39) Requests new-look menu treatment.
	      [Menu](autodocs-3.5/include-intuition-intuition-h.md) colors are derived from the screen [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) BARDETAILPEN,
	      BARBLOCKPEN, and BARTRIMPEN, instead of window detail and
	      block pens.  Also requests that a suitably scaled and colored
	      Amiga-key symbol and checkmark symbol be used in the menus.
	      Applications using WFLG_NEWLOOKMENUS need to use the new screen
	      [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) pens to color their [MenuItem](autodocs-3.5/include-intuition-intuition-h.md) and SubItem imagery.
	      If your application uses GadTools, the {GTMN_NewLookMenus,TRUE}
	      tag-item should be passed to the menu layout calls.

	      (NB: For the menus to actually appear with improved colors,
	      the screen's opener must supply suitable values for the
	      new menu pens in the [DrawInfo](autodocs-3.5/include-intuition-screens-h.md).  If this is not the case,
	      then an application requesting NewLookMenus will get the
	      scaled Amiga-key and checkmark but in V37-compatible colors.
	      Note that the screen's [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) will always contain valid
	      values for the new pens;  they just may correspond to the
	      "old look").

	IDCMPFlags = IDCMP is the acronym for Intuition Direct Communications
	    [Message](autodocs-3.5/include-exec-ports-h.md) Port.  (It's Intuition's sole acronym.) If any of the
	    IDCMP Flags is selected, Intuition will create a pair of
	    message ports and use them for direct communications with the
	    task opening this window (as compared with broadcasting
	    information via the Console device).  See the "Input and
	    [Output](autodocs-3.5/dos-library-output-2.md) Methods" chapter of the Intuition Reference Manual for
	    complete details.

	    You request an IDCMP by setting any of these flags.  Except
	    for the special VERIFY flags, every other flag you set tells
	    Intuition that if a given event occurs which your program
	    wants to know about, it is to broadcast the details of that
	    event through the IDCMP rather than via the Console device.
	    This allows a program to interface with Intuition directly,
	    rather than going through the Console device.

	    Many programs have elected to use IDCMP communication
	    exclusively, and not to associate a console with their
	    windows at all.  Some operations, such as IDCMP_MENUVERIFY,
	    can ONLY be achieved using IDCMP.

           The IDCMP flags you can set are described in the
	    [ModifyIDCMP()](autodocs-3.5/intuition-library-modifyidcmp-2.md) autodoc.

	Gadgets = the pointer to the first of a linked list of the your own
	      Gadgets which you want attached to this [Window](autodocs-3.5/include-intuition-intuition-h.md).  Can be NULL
	      if you have no Gadgets of your own

```c
       CheckMark = a pointer to an instance of the struct [Image](autodocs-3.5/include-intuition-intuition-h.md) where can
```
	      be found the imagery you want used when any of your
	      menu items is to be checkmarked.  If you don't want to
	      supply your own imagery and you want to just use
	      Intuition's own checkmark, set this argument to NULL

```c
       [Text](autodocs-3.5/graphics-library-text-2.md) = a null-terminated line of text to appear on the title bar of
```
	      your window (may be null if you want no text)

```c
       Type = the screen type for this window.  If this equal CUSTOMSCREEN,
```
	      you must have already opened a CUSTOMSCREEN (see text above).
	      Types available include:
		  - WBENCHSCREEN
		  - CUSTOMSCREEN
		  - PUBLICSCREEN (new for V36, see text below)

```c
       [Screen](autodocs-3.5/include-intuition-screens-h.md) = if your type is one of Intuition's standard screens, then
```
	      this argument is ignored.  However, if Type == CUSTOMSCREEN,
	      this must point to the structure of your own screen

```c
       [BitMap](autodocs-3.5/include-graphics-gfx-h.md) = if you have specified WFLG_SUPER_BITMAP as the type of
```
	       refreshing you want for this window, then this value points to a
	       instance of the struct bitmap.  However, if the refresh type
	       is NOT WFLG_SUPER_BITMAP, this pointer is ignored.

```c
       MinWidth, MinHeight, MaxWidth, MaxHeight = the size limits for this
```
	      window.  These must be reasonable values, which is to say that
	      the minimums cannot be greater than the current size, nor can
	      the maximums be smaller than the current size.  If they are,
	      they're ignored.  Any one of these can be initialized to zero,
	      which means that that limit will be set to the current
	      dimension of that axis.  The limits can be changed after the
	      [Window](autodocs-3.5/include-intuition-intuition-h.md) is opened by calling the [WindowLimits()](autodocs-3.5/intuition-library-windowlimits-2.md) routine.

	      NOTE: ORIGINALLY, we stated that:

	      "If you haven't requested the WFLG_SIZEGADGET option, these
	      variables are ignored so you don't have to initialize them."

	      It is now clear that a variety of programs take it upon
	      themselves to call [SizeWindow()](autodocs-3.5/intuition-library-sizewindow-2.md) (or [ChangeWindowBox()](autodocs-3.5/intuition-library-changewindowbox-2.md)) without
	      your program's consent or consulting your WFLG_SIZEGADGE
	      option.  To protect yourself against the results, we strongly
	      urge that if you supply suitable values for these fields even
	      if you do not specify WFLG_SIZEGADGET.

	      The maximums may be LARGER than the current size, or even
	      larger than the current screen.  The maximums should be set to
	      the highest value your application can handle.  This allows
	      users with larger display devices to take full advantage of
	      your software.  If there is no good reason to limit the size,
	      then don't.  -1 or ~0 indicates that the maximum size is only
	      limited by the size of the window's screen.

	      See also the docs on the function [WindowLimits()](autodocs-3.5/intuition-library-windowlimits-2.md) for more
	      information.

```c
       Extension (New for V36) = a pointer to an array (or chain of arrays)
```
	    of TagItems to specify additional parameters to OpenWindow().
	    TagItems in general are described in [utility/tagitem.h](autodocs-3.5/include-utility-tagitem-h.md),
	    and the OpenWindow tags are defined in [intuition/intuition.h](autodocs-3.5/include-intuition-intuition-h.md)
	    and described here.  For items pertaining to Public Screens
	    and visitor windows, please see below.

	Here are the TagItem.ti_Tag values that are defined for OpenWindow
	(and [OpenWindowTagList()](autodocs-3.5/intuition-library-openwindowtaglist-2.md)).

	Certain tags simply override equivalent values in [NewWindow](autodocs-3.5/include-intuition-intuition-h.md),
	and allow you to open a window using [OpenWindowTagList()](autodocs-3.5/intuition-library-openwindowtaglist-2.md) without
	having a [NewWindow](autodocs-3.5/include-intuition-intuition-h.md) structure at all.  In each case, cast
	the corresponding data to ULONG and put it in ti_Data.

	The compatible tag items include:

	WA_Left
	WA_Top
	WA_Width
	WA_Height
	WA_DetailPen	- NOTE: only overrides NewWindow.DetailPen of -1!
	WA_BlockPen	- NOTE: only overrides NewWindow.BlockPen of -1!
	WA_IDCMP
	WA_Flags	- initial values for Flags before looking at other
			  Boolean component [Tag](autodocs-3.5/include-utility-tagitem-h.md) values
	WA_Gadgets
	WA_Title
	WA_CustomScreen	- also implies CUSTOMSCREEN property
	WA_SuperBitMap	- also implies WFLG_SUPER_BITMAP refresh mode.
	WA_MinWidth
	WA_MinHeight
	WA_MaxWidth
	WA_MaxHeight

	These Boolean tag items are alternatives to the NewWindow.Flags
	Boolean attributes with similar names.

	WA_SizeGadget		- equivalent to WFLG_SIZEGADGET
	WA_DragBar		- equivalent to WFLG_DRAGBAR
	WA_DepthGadget		- equivalent to WFLG_DEPTHGADGET
	WA_CloseGadget		- equivalent to WFLG_CLOSEGADGET
	WA_Backdrop		- equivalent to WFLG_BACKDROP
	WA_ReportMouse		- equivalent to WFLG_REPORTMOUSE
	WA_NoCareRefresh	- equivalent to WFLG_NOCAREREFRESH
	WA_Borderless		- equivalent to WFLG_BORDERLESS
	WA_Activate		- equivalent to WFLG_ACTIVATE
	WA_RMBTrap		- equivalent to WFLG_RMBTRAP
	WA_WBenchWindow		- equivalent to WFLG_WBENCHWINDOW
				  (system PRIVATE)
	WA_SimpleRefresh 	- only specify if TRUE
	WA_SmartRefresh 	- only specify if TRUE
	WA_SizeBRight		- equivalent to WFLG_SIZEBRIGHT
	WA_SizeBBottom		- equivalent to WFLG_SIZEBBOTTOM
	WA_GimmeZeroZero 	- equivalent to WFLG_GIMMEZEROZERO
	WA_NewLookMenus		- equivalent to WFLG_NEWLOOKMENUS

	The following tag items specify new attributes of a window.

	WA_ScreenTitle - You can specify the screen title associated
	    with your window this way, and avoid a call to [SetWindowTitles()](autodocs-3.5/intuition-library-setwindowtitles-2.md)
	    when your window opens.

	WA_AutoAdjust - a Boolean attribute which says that it's OK
	    to move or even shrink the dimensions of this window
	    to fit it on the screen, within the dimension
	    limits specified by MinWidth and MinHeight.
	    Someday, this processing might be sensitive to the
	    currently visible portion of the screen the window
	    will be opening on, so don't draw too many conclusions
	    about the auto-adjust algorithms.
	    (Normally, this attribute defaults to FALSE.  However,
	    if you call OpenWindowTags() or [OpenWindowTagList()](autodocs-3.5/intuition-library-openwindowtaglist-2.md)
	    with a NULL [NewWindow](autodocs-3.5/include-intuition-intuition-h.md) pointer, this attribute defaults
	    to TRUE).

	WA_InnerWidth
	WA_InnerHeight - You can specify the dimensions of the interior
	    region of your window, independent of what the border
	    thicknesses will be.  You probably want to specify
	    WA_AutoAdjust to allow Intuition to move your window
	    or even shrink it so that it is completely on screen.

	    Note: using these tags puts some reasonable restrictions
	    on the gadgets you can specify as "border" gadgets when
	    you open your window.  Since border gadgets determine
	    the border dimensions and hence the overall dimensions of
	    your window, those dimensions cannot be used calculating
	    the position or dimensions of border gadgets.

	    Here's the complete list of restrictions:
	    - GACT_LEFTBORDER gadgets cannot be GFLG_RELWIDTH if
	      WA_InnerWidth is used.
	    - GACT_RIGHTBORDER gadgets MUST be GFLG_RELRIGHT if
	      WA_InnerWidth is used.
	    - GACT_TOPBORDER gadgets cannot be GFLG_RELHEIGHT if
	      WA_InnerHeight is used.
	    - GACT_BOTTOMBORDER gadgets MUST be GFLG_RELBOTTOM if
	      WA_InnerHeight is used.

	WA_PubScreenName - This tag item declares that you want your window
	    to open as a visitor window on the public screen whose name
	    is pointed to by (UBYTE *) ti_Data.

	WA_PubScreen - [Open](autodocs-3.5/dos-library-open-2.md) as a visitor window on the public screen
	    whose address if provided as (struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *) ti_Data.
	    To ensure that this screen remains open long enough, you
	    must either:
		1) Be the screen's owner
		2) have another window already open on the screen
		3) use [LockPubScreen()](autodocs-3.5/intuition-library-lockpubscreen-2.md)
	    Using [exec.library/Forbid()](autodocs-3.5/exec-library-forbid-2.md) is not sufficient.

	    You can provide ti_Data to be NULL (zero), without any
	    of the above precautions, to specify the default public screen.

	WA_PubScreenFallBack - This Boolean attribute specifies that a
	    visitor window should "fall back" to opening on the default
	    public screen if the explicitly specify public screen is not
	    available.

	WA_WindowName - this visionary specification of a window
	    rendezvous name string is not yet implemented.

	WA_Colors - this equally great idea about associating a palette
	    specification with the active window may not ever be implemented.

	WA_Zoom - ti_Data points to an array of four WORD's to be used
	    as the initial Left/Top/Width/Height of the "alternate
	    Zoom position and dimensions."  The presence of this tag
	    item implies that you want a Zoom gadget, even though you
	    might not have a sizing gadget.
	    New for V39: if the initial zoom-box left and top are
	    both set to ~0, then Intuition will give your window
	    "size-only" zooming, meaning that zooming the window
	    will not affect the left/top unless the window needs
	    to be moved on-screen.

	WA_MouseQueue - This tag specifies a limit for the number
	    of outstanding IDCMP_MOUSEMOVE IntuiMessages that Intuition
	    will send to your window.  You can change the value of this
	    limit after the window is open using [SetMouseQueue()](autodocs-3.5/intuition-library-setmousequeue-2.md).

	WA_RptQueue - This tag specifies a limit for the number of
	    outstanding repeated-IDCMP_RAWKEY, repeated-IDCMP_VANILLAKEY,
	    and repeated-IDCMP_IDCMPUPDATE IntuiMessages that Intuition will
	    send to your window.  Currently, there is no function to adjust
	    the repeat-key queue.

	WA_BackFill - ti_Data is a pointer to a [Hook](autodocs-3.5/include-utility-hooks-h.md) structure that
	    the Layers library will call when your window needs
	    "backfilling."  See [layers.library/InstallLayerHook()](autodocs-3.5/layers-library-installlayerhook-2.md).

 	WA_MenuHelp - ti_Data is a boolean.  If true, enables the MenuHelp
	    feature for this window.  See IDCMP_MENUHELP above.  (V37)

	WA_NotifyDepth - ti_Data is a boolean.  Set to true if you
	    would also like IDCMP_CHANGEWINDOW events sent to your window
	    when it is depth-arranged.  Normally, such events are only
	    sent for movement or resizing of the window.
	    IDCMP_CHANGEWINDOW events originating from
	    depth-arrangement have a Code equal to CWCODE_DEPTH, as
	    opposed to CWCODE_MOVESIZE.  (V39)

	WA_Checkmark - (ti_Data is struct [Image](autodocs-3.5/include-intuition-intuition-h.md) *) [Image](autodocs-3.5/include-intuition-intuition-h.md) to use as a
	    checkmark in menus.  Prior to V39, or if WA_NewLookMenus
	    is not specified, the default will be the traditional
	    checkmark in the original colors.  Under V39 and higher,
	    if you have requested WA_NewLookMenus then the default will
	    be an appropriately colored checkmark scaled to the screen's
	    font.  Alternately, you can provide a custom one, which you
	    can design yourself or get from sysiclass (use this if
	    your menu-font is different from the screen's font).

	WA_AmigaKey - (ti_Data is struct [Image](autodocs-3.5/include-intuition-intuition-h.md) *) [Image](autodocs-3.5/include-intuition-intuition-h.md) to use as
	    the Amiga-key symbol in menus.  If WA_NewLookMenus is not
	    specified, the default will be the traditional Amiga-key
	    symbol in the original colors.  If you've requested
	    WA_NewLookMenus, then the default will be an appropriately
	    colored Amiga-key scaled to the screen's font.
	    Alternately, you can provide a custom one, which you can
	    design yourself or get from sysiclass (use this if your
	    menu-font is different from the screen's font).  (V39)

	WA_Pointer - (APTR) The pointer you wish to associate with
	    your window.  If NULL, you are requesting the [Preferences](autodocs-3.5/include-intuition-preferences-h.md)
	    default pointer.  [Custom](autodocs-3.5/include-hardware-custom-h.md) pointers should be allocated by
	    performing a [NewObject()](autodocs-3.5/intuition-library-newobject-2.md) on "pointerclass".  (See
	    <intuition/pointerclass.h>).  Defaults to NULL.  This tag is
	    also recognized by [SetWindowPointerA()](autodocs-3.5/intuition-library-setwindowpointera.md).  (V39)

	WA_BusyPointer (BOOL) - Set to TRUE to request the [Preferences](autodocs-3.5/include-intuition-preferences-h.md)
	    busy-pointer.  If FALSE, your pointer will be as requested
	    by WA_Pointer.  Defaults to FALSE.  This tag is also
	    recognized by [SetWindowPointerA()](autodocs-3.5/intuition-library-setwindowpointera.md).  (V39)

	WA_PointerDelay - (BOOL) Set to TRUE to defer changing your
	    pointer for a brief instant.  This is typically used along
	    with setting the busy pointer, especially when the
	    application knows it may be busy for a very short while.  If
	    the application clears the pointer or sets another pointer
	    before the delay expires, the pending pointer change is
	    cancelled.  This reduces short flashes of the busy pointer.
	    This tag is also recognized by [SetWindowPointerA()](autodocs-3.5/intuition-library-setwindowpointera.md).  (V39)

	WA_HelpGroup - (ULONG) Normally, only the active window can
	    receive IDCMP_GADGETHELP messages.  However, an application
	    with multiple windows will want all its windows to be able
	    to receive help when any of them are active.  First obtain a
	    unique help ID with [utility.library/GetUniqueID()](autodocs-3.5/utility-library-getuniqueid.md), then
	    pass it as ti_Data of this tag to all your windows.  See
	    [HelpControl()](autodocs-3.5/intuition-library-helpcontrol.md).  (V39)

	WA_HelpGroupWindow - (struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *) Instead of using
	    WA_HelpGroup, you can pass a pointer to another window
	    whose HelpGroup you wish this window to belong to.  (V39)

	WA_TabletMessages - (BOOL) Set to TRUE to request extended
	    IntuiMessages for your window.  If a tablet driver is
	    generating IESUBCLASS_NEWTABLET input events, you will be
	    able to receive extended tablet information with most
	    IntuiMessages.  See the eim_TabletData field of the
	    [ExtIntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) structure.  Defaults to FALSE.  (V39)

   NOTES
	Regarding Public Screens, you can specify a window to be a
	"visitor window" on a public screen in one of several ways.
	In each case, you must be sure not to specify a [NewWindow](autodocs-3.5/include-intuition-intuition-h.md)
	type of CUSTOMSCREEN.  You should use the value PUBLICSCREEN.

	There are actually several ways you can specify which screen
	you want a visitor window to be opened on:

	    1) Specify the name of the public screen WA_PubScreenName,
	    or a NULL pointer, in ti_Data.  The name might have been
	    provided by the user.  A NULL pointer means to use the
	    default public screen.

	    If the named screen cannot be found, the default public screen
	    will be used if the Boolean attribute WA_PubScreenFallBack
	    is TRUE.

	    2) Specify a pointer to a public screen using the
	    WA_PubScreen tag item.  The WA_PubScreenFallBack
	    attribute has no effect.  You can specify the default
	    public screen by providing a NULL pointer.

	    You can also specify the pointer by setting NewWindow.Type
	    to PUBLICSCREEN, and specifying the public screen pointer
	    in NewWindow.Screen.  The WA_PubScreen tag item has precedent
	    over this technique.

	    Unless NULL, the screen pointer provided MUST be a valid
	    public screen.  You may ensure this several ways:

	    - Be the owner of the screen.
	    - Have a window already open on the screen.
	    - Use [LockPubScreen()](autodocs-3.5/intuition-library-lockpubscreen-2.md) to prevent the screen from closing.
	    - specifying the WFLG_VISITOR bit in NewWindow.Flags is not
	      supported.

	    It is anticipated that the last will be the most common method
	    of opening public screens because you often want to examine
	    properties of the screen your window will be using in order
	    to compensate for differences in dimension, depth, and font.

	    The standard sequence for this method is as follows:
	    [LockPubScreen()](autodocs-3.5/intuition-library-lockpubscreen-2.md)	- obtain a pointer and a promise
	    layout window	- adapt your window to the screen you will use
	    OpenWindow()	- using the pointer you specify
	    [UnlockPubScreen()](autodocs-3.5/intuition-library-unlockpubscreen-2.md)	- once your window is open, you can let go
				  of the lock on the public screen
	    ... normal window even processing ...
	    [CloseWindow()](autodocs-3.5/intuition-library-closewindow-2.md).

	Regarding "service" windows, such as those opened for a system
	requester or file requester associated with a given "client"window.
	These windows should NOT be "visitor" windows.  [Open](autodocs-3.5/dos-library-open-2.md) them
	using NewWindow.Type = CUSTOMSCREEN and NewWindow.Screen
	equal to the screen of the client window (window->WScreen).
	You can also use WA_CustomScreen, which has precedence.

	This ensures that the requester service window will be allowed to
	open on the same screen as the client window, even if that
	screen is not a public screen, or has private status.

	This has an implication for service/client protocol: when you
	pass a window pointer to any system requester routine or
	to a routine which creates some other other service window,
	you MUST keep your window open until the client window
	is closed.

	If a requester service will allow a NULL client window, this
	should indicate to open the service window on the default public
	screen (probably Workbench).  The correct way to get a pointer
	to this screen is to call LockPubScreen( NULL ).  In this
	case, you want to open as a visitor window, which means you
	should use either PUBLICSCREEN or WA_PubScreen, described above.
	You should call [UnlockPubScreen()](autodocs-3.5/intuition-library-unlockpubscreen-2.md) after your visitor window is open.

	As of V36, gadgets in the right and bottom border
	(specified with GACT_RIGHTBORDER and GACT_BOTTOMBORDER) only
	contribute to the dimensions of the borders if they are also
	GFLG_RELRIGHT and GFLG_RELBOTTOM, respectively.

    RESULT
	If all is well, returns the pointer to your new [Window](autodocs-3.5/include-intuition-intuition-h.md)
	If anything goes wrong, returns NULL

    BUGS
	When you open a window, Intuition will set the font of
	the window's [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to the font of the window's screen.
	This does not work right for GimmeZeroZero windows: the
	BorderRPort [RastPort](autodocs-3.5/include-graphics-rastport-h.md) has the font set correctly, but
	Window.RPort is set up with the system default font.
	For compatibility reasons, we won't be fixing this problem.

	Also, there is a compatibility trick going on with the
	default font of your window's [RastPort](autodocs-3.5/include-graphics-rastport-h.md) if the screen's
	font is "fancy."  See the SA_SysFont attribute described
	under [OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md).

	Unless you arrange otherwise, each window you open will allocate
	a signal for your task from the 16 "user signals."
	If no signal is available, your window will not be able
	to be opened.  In early V36 versions and before, Intuition didn't
	check this condition, but just left you with an unusable port.

```c
    SEE ALSO
       [OpenWindowTagList()](autodocs-3.5/intuition-library-openwindowtaglist-2.md), [OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md), [ModifyIDCMP()](autodocs-3.5/intuition-library-modifyidcmp-2.md), [SetWindowTitles()](autodocs-3.5/intuition-library-setwindowtitles-2.md),
```
	[LockPubScreen()](autodocs-3.5/intuition-library-lockpubscreen-2.md), [SetDefaultPubScreen()](autodocs-3.5/intuition-library-setdefaultpubscreen-2.md), [ZipWindow()](autodocs-3.5/intuition-library-zipwindow-2.md),
	[layers.library/InstallLayerHook()](autodocs-3.5/layers-library-installlayerhook-2.md), [SetPubScreenModes()](autodocs-3.5/intuition-library-setpubscreenmodes-2.md)

---

## See Also

- [BeginRefresh — intuition.library](../autodocs/intuition.library.md#beginrefresh)
- [ChangeWindowBox — intuition.library](../autodocs/intuition.library.md#changewindowbox)
- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [EndRefresh — intuition.library](../autodocs/intuition.library.md#endrefresh)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [GetUniqueID — utility.library](../autodocs/utility.library.md#getuniqueid)
- [HelpControl — intuition.library](../autodocs/intuition.library.md#helpcontrol)
- [InstallLayerHook — layers.library](../autodocs/layers.library.md#installlayerhook)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [ModifyIDCMP — intuition.library](../autodocs/intuition.library.md#modifyidcmp)
- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenScreenTagList — intuition.library](../autodocs/intuition.library.md#openscreentaglist)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
- [ReportMouse — intuition.library](../autodocs/intuition.library.md#reportmouse)
- [SetDefaultPubScreen — intuition.library](../autodocs/intuition.library.md#setdefaultpubscreen)
- [SetMouseQueue — intuition.library](../autodocs/intuition.library.md#setmousequeue)
- [SetPubScreenModes — intuition.library](../autodocs/intuition.library.md#setpubscreenmodes)
- [SetWindowPointerA — intuition.library](../autodocs/intuition.library.md#setwindowpointera)
- [SetWindowTitles — intuition.library](../autodocs/intuition.library.md#setwindowtitles)
- [SizeWindow — intuition.library](../autodocs/intuition.library.md#sizewindow)
- [UnlockPubScreen — intuition.library](../autodocs/intuition.library.md#unlockpubscreen)
- [WindowLimits — intuition.library](../autodocs/intuition.library.md#windowlimits)
- [ZipWindow — intuition.library](../autodocs/intuition.library.md#zipwindow)
