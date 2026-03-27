---
title: workbench.library/AddAppIconA
manual: autodocs-3.5
chapter: autodocs-3.5
section: workbench-library-addappicona-2
functions: [AddAppIconA]
libraries: [workbench.library]
---

# workbench.library/AddAppIconA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddAppIconA - add an icon to Workbench's list of AppIcons.       (V36)

   SYNOPSIS
	[AppIcon](autodocs-3.5/include-workbench-workbench-h.md) = AddAppIconA(id, userdata, text, msgport,
	   D0                 D0     D1      A0     A1

	                      lock, diskobj, taglist)
	                      A2      A3      A4

	struct [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) *AddAppIconA(ULONG, ULONG, char *,
	        struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *, [BPTR](autodocs-3.5/include-dos-dos-h.md), struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *,
	        struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	Alternate, varargs version:
	struct [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) *AddAppIcon(ULONG, ULONG, char *,
	                           struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *, [BPTR](autodocs-3.5/include-dos-dos-h.md),
	                           struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *,
	                           tag1, data1,
	                           tag2, data2,
	                           ...
	                           TAG_END );

   FUNCTION
	Attempt to add an icon to Workbench's list of AppIcons.  If
	successful, the icon is displayed on the Workbench backdrop (the
	same place disk icons are displayed).

	This call is provided to allow applications to be notified when
	a graphical object (not neccessarely associated with a file)
	gets 'manipulated'.

	The notification consists of an [AppMessage](autodocs-3.5/include-workbench-workbench-h.md) (found in workbench.h/i)
	of type 'MTYPE_APPICON' arriving at the message port you specified.

	The types of 'manipulation' that can occur are:

	1. Double-clicking on the icon.  am_NumArgs will be zero and
	   am_ArgList will be NULL.
	2. Dropping an icon or icons on your [AppIcon](autodocs-3.5/include-workbench-workbench-h.md).  am_NumArgs will
	   be the number of icons dropped on your [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) plus one.
	   am_ArgList will be an array of pointers to [WBArg](autodocs-3.5/include-workbench-startup-h.md) structures.
	   Refer to the 'WBStartup Message' section of the RKM for more info.
	3. Dropping your [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) on another icon.  NOT SUPPORTED.
	4. Invoking an "Icons" menu item with your icon selected. (V44)
	   You have to tell Workbench which menu items your icon
	   responds to using the tag item list you provide to AddAppIconA().
	   When one of the supported menu items is invoked, you
	   will receive an [AppMessage](autodocs-3.5/include-workbench-workbench-h.md) with the am_Class entry set to
	   a value out of AMCLASSICON_Open..AMCLASSICON_EmptyTrash,
	   corresponding to the menu item used.

   INPUTS
	id - this variable is strictly for your own use and is ignored by
	     Workbench.  Typical uses in C are in switch and case statements,
	     and in assembly language table lookup.
	userdata - this variable is strictly for your own use and is ignored
	           by Workbench.
	text - name of icon (char *)
	lock - NULL    (Currently unused)
	msgport - pointer to message port Workbench will use to send you an
	          [AppMessage](autodocs-3.5/include-workbench-workbench-h.md) message of type 'MTYPE_APPICON' when your icon
	          gets 'manipulated' (explained above).
	diskobj - pointer to a [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) structure filled in as follows:
	    do_Magic - NULL
	    do_Version - NULL
	    do_Gadget - a gadget structure filled in as follows:
	        NextGadget - NULL
	        LeftEdge - NULL
	        TopEdge - NULL
	        Width - width of icon hit-box
	        Height - height of icon hit-box
	        Flags - NULL or GADGHIMAGE
	        Activation - NULL
	        GadgetType - NULL
	        GadgetRender - pointer to [Image](autodocs-3.5/include-intuition-intuition-h.md) structure filled in as follows:
	            LeftEdge - NULL
	            TopEdge - NULL
	            Width - width of image (must be <= Width of hit box)
	            Height - height of image (must be <= Height of hit box)
	            Depth - # of bit-planes in image
	            ImageData - pointer to actual word aligned bits (CHIP MEM)
	            PlanePick - Plane mask ((1 << depth) - 1)
	            PlaneOnOff - 0
	            NextImage - NULL
	        SelectRender - pointer to alternate [Image](autodocs-3.5/include-intuition-intuition-h.md) struct or NULL
	        GadgetText - NULL
	        MutualExclude - NULL
	        SpecialInfo - NULL
	        GadgetID - NULL
	        UserData - NULL
	    do_Type - NULL
	    do_DefaultTool - NULL
	    do_ToolTypes - NULL
	    do_CurrentX - NO_ICON_POSITION (recommended)
	    do_CurrentY - NO_ICON_POSITION (recommended)
	    do_DrawerData - NULL
	    do_ToolWindow - NULL
	    do_StackSize - NULL

	(an easy way to create one of these (a DiskObject) is to create an icon
	 with the V2.0 icon editor and save it out.  Your application can then
	 call [GetDiskObject](autodocs-3.5/icon-library-getdiskobject-2.md) on it and pass that to AddAppIcon.)

	taglist - ptr to a list of tag items.  Must be NULL for V2.0.

   TAGS
	WBAPPICONA_SupportsOpen (BOOL) -- Set this to TRUE if your
	    [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) should respond to the "Open" menu, to FALSE
	    otherwise. Note that with this attribute set to FALSE,
	    users will still be able to double-click on your [AppIcon](autodocs-3.5/include-workbench-workbench-h.md)
	    and drop icons on it. This attribute solely controls
	    whether the "Open" menu item will be available.

	    This tag defaults to TRUE. (V44)

	WBAPPICONA_SupportsCopy (BOOL) -- Set this to TRUE if your
	    [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) should respond to the "Copy" menu, to FALSE
	    otherwise.

	    This tag defaults to FALSE. (V44)

	WBAPPICONA_SupportsRename (BOOL) -- Set this to TRUE if your
	    [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) should respond to the "Rename" menu, to FALSE
	    otherwise.

	    This tag defaults to FALSE. (V44)

	WBAPPICONA_SupportsInformation (BOOL) -- Set this to TRUE if your
	    [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) should respond to the "Information" menu, to FALSE
	    otherwise.

	    This tag defaults to FALSE. (V44)

	WBAPPICONA_SupportsSnapshot (BOOL) -- Set this to TRUE if your
	    [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) should respond to the "Snapshot" menu, to FALSE
	    otherwise.

	    This tag defaults to FALSE. (V44)

	WBAPPICONA_SupportsUnSnapshot (BOOL) -- Set this to TRUE if your
	    [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) should respond to the "UnSnapshot" menu, to FALSE
	    otherwise.

	    This tag defaults to FALSE. (V44)

	WBAPPICONA_SupportsLeaveOut (BOOL) -- Set this to TRUE if your
	    [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) should respond to the "Leave Out" menu, to FALSE
	    otherwise.

	    This tag defaults to FALSE. (V44)

	WBAPPICONA_SupportsPutAway (BOOL) -- Set this to TRUE if your
	    [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) should respond to the "Put Away" menu, to FALSE
	    otherwise.

	    This tag defaults to FALSE. (V44)

	WBAPPICONA_SupportsDelete (BOOL) -- Set this to TRUE if your
	    [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) should respond to the "Delete" menu, to FALSE
	    otherwise.

	    This tag defaults to FALSE. (V44)

	WBAPPICONA_SupportsFormatDisk (BOOL) -- Set this to TRUE if your
	    [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) should respond to the "[Format](autodocs-3.5/dos-library-format-2.md) Disk" menu, to FALSE
	    otherwise.

	    This tag defaults to FALSE. (V44)

	WBAPPICONA_SupportsEmptyTrash (BOOL) -- Set this to TRUE if your
	    [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) should respond to the "Empty Trash" menu, to FALSE
	    otherwise.

	    This tag defaults to FALSE. (V44)

	WBAPPICONA_PropagatePosition (BOOL) -- Set this to TRUE if you
	    want the AppIcon's position to be propagated back to the
	    original [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) you passed to this function. By
	    default, Workbench will make a copy of that DiskObject's
	    icon imagery, allowing you to free the [DiskObject](autodocs-3.5/include-workbench-workbench-h.md).
	    But if you specify "WBAPPICONA_PropagatePosition,TRUE,"
	    Workbench will assume that you will not free it and
	    that the AppIcon's current position should be stored
	    in its do_CurrentX/do_CurrentY members.

	    This tag defaults to FALSE. (V44)

	WBAPPICONA_RenderHook (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *) -- Pointer to a hook that
	    will be invoked when rendering your [AppIcon](autodocs-3.5/include-workbench-workbench-h.md). With this hook
	    and [WorkbenchControlA()](autodocs-3.5/workbench-library-workbenchcontrola.md) you can create dynamic or animated
	    AppIcons. Your hook will be called with the following
	    parameters and has to return a result value:

	    result = hookFunc(hook,reserved,arm)
	      D0               A0     A2     A1

	    [LONG](autodocs-3.5/include-exec-types-h.md) hookFunc(struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *hook,[APTR](autodocs-3.5/include-exec-types-h.md) reserved,
	                  struct [AppIconRenderMsg](autodocs-3.5/include-workbench-workbench-h.md) *arm);

	    The reserved parameter will be set to NULL (V44).

	    If your hook code returns TRUE, the AppIcon's regular image
	    will be drawn. If your code returns FALSE, the regular image
	    will not be drawn; this allows you to do all the icon's on-screen
	    rendering with the exception of the icon image used when dragging
	    the icon on the screen.

	    The render message contents are as follows:

	        arm_RastPort
	            A pointer to the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to render into.

	        arm_Icon
	            A pointer to the Icon to be rendered.

	        arm_Label
	            A pointer to the label text to be printed
	            below the icon.

	        arm_Tags
	            Further control tags which you should pass on
	            to [icon.library/DrawIconStateA](autodocs-3.5/icon-library-drawiconstatea.md), should you
	            call this routine.

	        arm_Left
	        arm_Top
	            Rendering origin; note that these coordinates
	            DO NOT take the embossing border sizes into
	            account.

	        arm_Width
	        arm_Height
	            Size of the Icon's image area; you should limit
	            your drawing to this area.

	        arm_State
	            An icon drawing state, such as used by
	            [icon.library/DrawIconStateA](autodocs-3.5/icon-library-drawiconstatea.md).

	    Note that all the data in the render message is read-only.


	    This tag defaults to NULL. (V44)

	WBAPPICONA_NotifySelectState (BOOL) -- Set this tag to TRUE
	    if you want to be be notified whenever the [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) becomes
	    selected or unselected. You will hear only state transitions,
	    i.e. changes from selected to unselected state and the other
	    way round. On a state transition you will receive AppMessages
	    with the AppMessage->am_Class member set to AMCLASSICON_Selected
	    or AMCLASSICON_Unselected, respectively.

	    This tag defaults to FALSE. (V44)

   RESULTS
	[AppIcon](autodocs-3.5/include-workbench-workbench-h.md) - a pointer to an [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) structure which you pass to
	          [RemoveAppIcon](autodocs-3.5/workbench-library-removeappicon-2.md) when you want to remove the icon
	          from Workbench's list of AppIcons.  NULL
	          if Workbench was unable to add your icon; typically
	          happens when Workbench is not running or under low
	          memory conditions.

   EXAMPLE
	You could design a print-spooler icon and add it to the Workbench.
	Any file dropped on the print spooler would be printed.  If the
	user double-clicked (opened) your printer-spooler icon, you could
	open a window showing the status of the print spool, allow changes
	to print priorities, allow deletions, etc.  If you registered this
	window as an 'AppWindow' (explained in workbench.library/AddAppWindow)
	files could also be dropped in the window and added to the spool.

   NOTES
	For this function call to succeed, Workbench must be open. This
	means that the LoadWB command was executed and the Workbench
	screen has been opened.

   SEE ALSO
	[workbench.library/RemoveAppIcon](autodocs-3.5/workbench-library-removeappicon-2.md)
	[workbench.library/WorkbenchControlA](autodocs-3.5/workbench-library-workbenchcontrola.md)
	[icon.library/DrawIconStateA](autodocs-3.5/icon-library-drawiconstatea.md)

   BUGS
	In workbench.library versions 36 through 40 [Info](autodocs-3.5/dos-library-info-2.md) cannot be obtained
	on appicons.

---

## See Also

- [AddAppIconA — workbench.library](../autodocs/workbench.library.md#addappicona)
