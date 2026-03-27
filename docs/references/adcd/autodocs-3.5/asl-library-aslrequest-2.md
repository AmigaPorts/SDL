---
title: asl.library/AslRequest
manual: autodocs-3.5
chapter: autodocs-3.5
section: asl-library-aslrequest-2
functions: [AllocAslRequest, AslRequest, FreeAslRequest, GT_GetIMsg, IoErr, OpenDiskFont, OpenFont, ParsePatternNoCase, SetSignal]
libraries: [asl.library, diskfont.library, dos.library, exec.library, gadtools.library, graphics.library]
---

# asl.library/AslRequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AslRequest -- get input from user using an ASL requester. (V36)
	AslRequestTags -- varargs stub for AslRequest(). (V36)

   SYNOPSIS
	result = AslRequest(requester,tags);
	D0                  A0        A1

	[BOOL](autodocs-3.5/include-exec-types-h.md) AslRequest(APTR,struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	result = AslRequestTags(requester,firstTag,...);

	[BOOL](autodocs-3.5/include-exec-types-h.md) AslRequestTags(APTR,[Tag](autodocs-3.5/include-utility-tagitem-h.md),...);

   FUNCTION
	Prompts the user for input, based on the specific type of
	requester and modifying tags. The actions and results
	are specific to the type of requester, but in general the action is
	to open a requesting window prompting the user for a specific input.
	If the user cancels or the system aborts the request, FALSE
	is returned, otherwise the requester's data structure reflects the
	user input.

	Note that tag values stay in effect for each use of the
	requester until they are cleared or modified by passing the
	same tag with a new value.

   INPUTS
	requester - requester structure allocated with [AllocAslRequest()](autodocs-3.5/asl-library-allocaslrequest-2.md). If
		    this parameter is NULL, this function will always return
		    FALSE with a [dos.library/IoErr()](autodocs-3.5/dos-library-ioerr-2.md) result of
		    ERROR_NO_FREE_STORE.
	tags - pointer to an optional tag list which may be used to
	       control features of the requester.

   TAGS
	Tags for use with the file requester:

	ASLFR_Window (struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *) - Parent window of requester. If no
			ASLFR_Screen tag is specified, the window structure
			is used to determine on which screen to open the
			requesting window. (V36)

	ASLFR_PubScreenName (STRPTR) - Name of a public screen to open on.
			This overrides the screen used by ASLFR_Window. (V38)

	ASLFR_Screen (struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *) - [Screen](autodocs-3.5/include-intuition-screens-h.md) on which to open the requester.
			This overrides the screen used by ASLFR_Window or by
			ASLFR_PubScreenName. (V38)

	ASLFR_PrivateIDCMP (BOOL) - When set to TRUE, this tells ASL to
			allocate a new IDCMP port for the requesting window.
			If not specified or set to FALSE, and if ASLFR_Window
			is provided, the requesting window will share
			ASLFR_Window's IDCMP port. (V38)

	ASLFR_IntuiMsgFunc (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *) - A function to call whenever an
			unknown Intuition message arrives at the message port
			being used by the requesting window. The function
			receives the following parameters:
				A0 - (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *)
				A1 - (struct [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) *)
				A2 - (struct [FileRequester](autodocs-3.5/include-libraries-asl-h.md) *)
			(V38)

	ASLFR_SleepWindow (BOOL) - When set to TRUE, this tag will cause the
			window specified by ASLFR_Window to be "put to
			sleep". That is, a busy pointer will be displayed in
			the parent window, and no gadget or menu activity will
			be allowed. This is done by opening an invisible
			Intuition [Requester](autodocs-3.5/include-intuition-intuition-h.md) in the parent window. (V38)

	ASLFR_UserData (APTR) - A 32-bit value that is simply copied in the
			fr_UserData field of the requester structure. (V38)

	ASLFR_TextAttr (struct [TextAttr](autodocs-3.5/include-graphics-text-h.md) *) - Font to be used for the requesting
			window's gadgets and menus. If this tag is not provided
			or its value is NULL, the default font of the screen
			on which the requesting window opens will be used.
			This font must already be in memory as ASL calls
			[OpenFont()](autodocs-3.5/graphics-library-openfont-2.md) and not [OpenDiskFont()](autodocs-3.5/diskfont-library-opendiskfont-2.md). As of V38, the font
			used in the file requester's file list must be
			monospaced. If the font provided with this tag is
			not monospaced, then the file list will use the current
			system default font as chosen in preferences. (V38)

	ASLFR_Locale (struct [Locale](autodocs-3.5/include-libraries-locale-h.md) *) - [Locale](autodocs-3.5/include-libraries-locale-h.md) to use for the requesting
			window. This determines the language used for the
			requester's gadgets and menus. If this tag is not
			provided or its value is NULL, the system's current
			default locale will be used. As of V38, items such as
			the date format always uses the system default locale.
			(V38)

	ASLFR_TitleText (STRPTR) - Title to use for the requesting window.
			Default is no title. (V36)

	ASLFR_PositiveText (STRPTR) - Label of the positive gadget in the
			requester. English default is "OK". Prior to V38, this
			string could not be longer than 6 characters. (V36)

	ASLFR_NegativeText (STRPTR) - Label of the negative gadget in the
			requester. English default is "Cancel". Prior to V38,
			this string could not be longer than 6 characters.
			(V36)

	ASLFR_InitialLeftEdge (WORD) - Suggested left edge of requesting
			window. (V36)

	ASLFR_InitialTopEdge (WORD) - Suggested top edge of requesting
			window. (V36)

	ASLFR_InitialWidth (WORD) - Suggested width of requesting window. (V36)

	ASLFR_InitialHeight (WORD) - Suggested height of requesting window.
			(V36)

	ASLFR_InitialFile (STRPTR) - Initial contents of the file requester's
			File text gadget. Default is empty. (V36)

	ASLFR_InitialDrawer (STRPTR) - Initial contents of the file
			requester's Drawer text gadget. Default is empty. (V36)

	ASLFR_InitialPattern (STRPTR) - Initial contents of the file
			requester's Pattern text gadget. Default is #?. (V36)

	ASLFR_InitialShowVolumes (BOOL) - When opening the file requester,
			read the list of active volumes, do not read the contents
			of the specified drawer. (V44)

	ASLFR_Flags1 (ULONG) - Bulk initialization of many of the requester's
			options. See [<libraries/asl.h>](autodocs-3.5/include-libraries-asl-h.md) for the possible
			flag values. Default is 0. (V36)

	ASLFR_Flags2 (ULONG) - Bulk initialization of many of the requester's
			options. See [<libraries/asl.h>](autodocs-3.5/include-libraries-asl-h.md) for the possible
			flag values. Default is 0. (V36)

	ASLFR_DoSaveMode (BOOL) - Set this tag to TRUE when the file requester
			is being used for saving. Default is FALSE. (V38)

	ASLFR_DoMultiSelect (BOOL) - Set this tag to TRUE to let the user
			select multiple files at once. This tag excludes
			save mode. Default is FALSE. (V38)

	ASLFR_DoPatterns (BOOL) - Set this tag to TRUE to cause a pattern
			gadget to be displayed. Default is FALSE. (V38)

	ASLFR_DrawersOnly (BOOL) - Set this tag to TRUE to cause the requester
			to only display drawers, and have no File gadget. This
			is useful to let the user choose a destination
			directory. Default is FALSE. (V38)

	ASLFR_FilterFunc (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *) - A function to call for each file
			encountered. If the function returns TRUE, the file is
			included in the file list, otherwise it is rejected
			and not displayed. The function receives the following
			parameters:
				A0 - (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *)
				A1 - (struct [AnchorPath](autodocs-3.5/include-dos-dosasl-h.md) *)
				A2 - (struct [FileRequester](autodocs-3.5/include-libraries-asl-h.md) *)
			(V38)

	ASLFR_RejectIcons (BOOL) - Set this tag to TRUE to cause the requester
			not to display Workbench icons. This flag should
			normally be set. Default is FALSE. (V38)

	ASLFR_RejectPattern (UBYTE *) - Specifies an AmigaDOS pattern that is
			used to reject files. That is, any files with names
			matching this pattern are not included in the file
			list. Note that the pattern must have been
			parsed by [dos.library/ParsePatternNoCase()](autodocs-3.5/dos-library-parsepatternnocase-2.md). Default
			is ~(#?) which matches nothing. (V38)

	ASLFR_AcceptPattern (UBYTE *) - Specifies an AmigaDOS pattern that is
			used to accept files. That is, only files with names
			matching this pattern are included in the file list.
			Note that the pattern must have been parsed by
			[dos.library/ParsePatternNoCase()](autodocs-3.5/dos-library-parsepatternnocase-2.md). Default is #? which
			matches everything. (V38)

	ASLFR_FilterDrawers (BOOL) - Set this tag to TRUE if you want the
			ASLFR_RejectPattern, ASLFR_AcceptPattern, and the
			Pattern text gadget to also apply to drawer names.
			Normally, drawers are always displayed. Default is
			FALSE. (V38)

	ASLFR_HookFunc (APTR) - A function that is called if the
			FRF_FILTERFUNC or FRF_INTUIFUNC flags are specified in
			the ASLFR_Flags1 tag. The function will be called like
			so, with the arguments on the stack using the standard
			C pushing order:

				ULONG function(ULONG mask, [APTR](autodocs-3.5/include-exec-types-h.md) object,
					       struct [FileRequester](autodocs-3.5/include-libraries-asl-h.md) *fr)

			The Mask value is a copy of the specific ASLFR_Flags1
			value the callback is for, either FRF_FILTERFUNC or
			FRF_INTUIFUNC; object is a pointer to a data object
			(a (struct [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) *) for FRF_INTUIFUNC, and a
			(struct [AnchorPath](autodocs-3.5/include-dos-dosasl-h.md) *) for FRF_FILTERFUNC).

			For FRF_FILTERFUNC, the function should return 0 if the
			file should be added to the list, non-zero if it
			shouldn't. For FRF_INTUIFUNC, the function should
			return the original (struct [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) *) it was
			passed.

	ASLFR_SetSortBy (ULONG) -- Criteria for sorting the file list.
	        this must be one of ASLFRSORTBY_Name (sort by name),
	        ASLFRSORTBY_Date (sort by date) or ASLFRSORTBY_Size
	        (sort by size).
	        Default is ASLFRSORTBY_Name. (V44)

	ASLFR_GetSortBy (ULONG *) -- Before leaving AslRequest(), the
	        file requester will store its current sort criteria
	        (ASLFRSORTBY_Name, ASLFRSORTBY_Date or ASLFRSORTBY_Size)
	        in the ULONG pointed to by this tag.
	        Default is NULL, i.e. no data is stored. (V44)

	ASLFR_SetSortDrawers (ULONG) -- Determines where drawers
	        are placed in the sorted list; this must be one of
	        ASLFRSORTDRAWERS_First (drawers appear before all
	        other files), ASLFRSORTDRAWERS_Mix (drawers are sorted
	        along with the the other files) or ASLFRSORTDRAWERS_Last
	        (drawers appear after all other files).
	        Default is ASLFRSORTDRAWERS_First. (V44)

	ASLFR_GetSortDrawers (ULONG *) -- Before leaving AslRequest(),
	        the file requester will store its current drawer list
	        placement (ASLFRSORTDRAWERS_First, ASLFRSORTDRAWERS_Mix
	        or ASLFRSORTDRAWERS_Last) in the ULONG pointed to by
	        this tag.
	        Default is NULL, i.e. no data is stored. (V44)

	ASLFR_SetSortOrder (ULONG) -- Selects the order in which
	        the list is sorted; this must be one of ASLFRSORTORDER_Ascend
	        (smallest/oldest files first, largest/newest files last)
	        or ASLFRSORTORDER_Descend (largest/newest files first,
	        smallest/oldest files last).
	        Default is ASLFRSORTORDER_Ascend. (V44)

	ASLFR_GetSortOrder (ULONG *) -- Before leaving AslRequest(),
	        the file requester will store its current sort order
	        (ASLFRSORTORDER_Ascend, ASLFRSORTORDER_Descend) in the
	        ULONG pointed to by this tag.
	        Default is NULL, i.e. no data is stored. (V44)

	ASLFR_PopToFront (BOOL) -- When set to TRUE, this tells ASL to
	        bring the screen to the front the requester has opened on.
	        The position of the screen will be adjusted, too, to bring
	        the area into view the window has opened in. The screen
	        brought to the front will be pushed into the background
	        again when the requester window closes.
	        Default is TRUE. (V44)

	Tags used for the font requester:

	ASLFO_Window (struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *) - Parent window of requester. If no
			ASLFO_Screen tag is specified, the window structure
			is used to determine on which screen to open the
			requesting window. (V36)

	ASLFO_PubScreenName (STRPTR) - Name of a public screen to open on.
			This overrides the screen used by ASLFO_Window. (V38)

	ASLFO_Screen (struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *) - [Screen](autodocs-3.5/include-intuition-screens-h.md) on which to open the requester.
			This overrides the screen used by ASLFO_Window or by
			ASLFO_PubScreenName. (V38)

	ASLFO_PrivateIDCMP (BOOL) - When set to TRUE, this tells ASL to
			allocate a new IDCMP port for the requesting window.
			If not specified or set to FALSE, and if ASLFO_Window
			is provided, the requesting window will share
			ASLFO_Window's IDCMP port. (V38)

	ASLFO_IntuiMsgFunc (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *) - A function to call whenever an
			unknown Intuition message arrives at the message port
			being used by the requesting window. The function
			receives the following parameters:
				A0 - (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *)
				A1 - (struct [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) *)
				A2 - (struct [FontRequester](autodocs-3.5/include-libraries-asl-h.md) *)
			(V38)

	ASLFO_SleepWindow (BOOL) - When set to TRUE, this tag will cause the
			window specified by ASLFO_Window to be "put to
			sleep". That is, a busy pointer will be displayed in
			the parent window, and no gadget or menu activity will
			be allowed. This is done by opening an invisible
			Intuition [Requester](autodocs-3.5/include-intuition-intuition-h.md) in the parent window. (V38)

	ASLFO_UserData (APTR) - A 32-bit value that is simply copied in the
			fo_UserData field of the requester structure. (V38)

	ASLFO_TextAttr (struct [TextAttr](autodocs-3.5/include-graphics-text-h.md) *) - Font to be used for the requesting
			window's gadgets and menus. If this tag is not provided
			or its value is NULL, the default font of the screen
			on which the requesting window opens will be used.
			This font must already be in memory as ASL calls
			[OpenFont()](autodocs-3.5/graphics-library-openfont-2.md) and not [OpenDiskFont()](autodocs-3.5/diskfont-library-opendiskfont-2.md).
			(V38)

	ASLFO_Locale (struct [Locale](autodocs-3.5/include-libraries-locale-h.md) *) - [Locale](autodocs-3.5/include-libraries-locale-h.md) to use for the requesting
			window. This determines the language used for the
			requester's gadgets and menus. If this tag is not
			provided or its value is NULL, the system's current
			default locale will be used. (V38)

	ASLFO_TitleText (STRPTR) - Title to use for the requesting window.
			Default is no title. (V36)

	ASLFO_PositiveText (STRPTR) - Label of the positive gadget in the
			requester. English default is "OK". Prior to V38, this
			string could not be longer than 6 characters. (V36)

	ASLFO_NegativeText (STRPTR) - Label of the negative gadget in the
			requester. English default is "Cancel". Prior to V38,
			this string could not be longer than 6 characters.
			(V36)

	ASLFO_InitialLeftEdge (WORD) - Suggested left edge of requesting
			window. (V36)

	ASLFO_InitialTopEdge (WORD) - Suggested top edge of requesting
			window. (V36)

	ASLFO_InitialWidth (WORD) - Suggested width of requesting window. (V38)

	ASLFO_InitialHeight (WORD) - Suggested height of requesting window.
			(V38)

	ASLFO_InitialName (STRPTR) - Initial contents of the font requester's
			Name text gadget. Default is none. (V36)

	ASLFO_InitialSize (UWORD) - Initial contents of the font requester's
			Size numeric gadget (fo_Attr.ta_YSize). Default is 8.
			(V36)

	ASLFO_InitialStyle (UBYTE) - Initial setting of the font requester's
			Style gadget (fo_Attr.ta_Style). Default is FS_NORMAL.
			(V36)

	ASLFO_InitialFlags (UBYTE) - Initial setting of the font requester's
			fo_Flags field (fo_Attr.ta_Flags). Default is
			FPF_ROMFONT. (V36)

	ASLFO_InitialFrontPen (UBYTE) - Initial setting of the font requester's
			Front Color gadget (fo_FrontPen). This value also
			determines the color used to render the text in the
			sample font area. Default is 1. (V36)

	ASLFO_InitialBackPen (UBYTE) - Initial setting of the font requester's
			Back Color gadget (fo_BackPen). This value also
			determines the color used to render the background of
			the sample font area. Default is 0. (V36)

	ASLFO_InitialDrawMode (UBYTE) - Initial setting of the font
			requester's Mode gadget (fo_DrawMode). Default is
			JAM1. (V38)

	ASLFO_Flags (ULONG) - Bulk initialization of many of the requester's
			options. See [<libraries/asl.h>](autodocs-3.5/include-libraries-asl-h.md) for the possible
			flag values. Default is 0. (V36)

	ASLFO_DoFrontPen (BOOL) - Set this tag to TRUE to cause the requester
			to display the Front Color selection gadget. Default is
			FALSE. (V38)

	ASLFO_DoBackPen (BOOL) - Set this tag to TRUE to cause the requester
			to display the Back Color selection gadget. Default
			is FALSE. (V38)

	ASLFO_DoStyle (BOOL) - Set this tag to TRUE to cause the requester
			to display the Style checkboxes. Default is FALSE.
			(V38)

	ASLFO_DoDrawMode (BOOL) - Set this tag to TRUE to cause the requester
			to display the Mode cycle gadget. Default is FALSE.
			(V38)

	ASLFO_FixedWidthOnly (BOOL) - Set this tag to TRUE to cause the
			requester to only display fixed-width fonts. Default
			is FALSE. (V38)

	ASLFO_MinHeight (UWORD) - The minimum font height to let the user
			select. Default is 5. (V36)

	ASLFO_MaxHeight (UWORD) - The maximum font height to let the user
			select. Default is 24. (V36)

	ASLFO_FilterFunc (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *) - A function to call for each font
			encountered. If the function returns TRUE, the font is
			included in the font list, otherwise it is rejected
			and not displayed. The function receives the following
			parameters:
				A0 - (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *)
				A1 - (struct [TextAttr](autodocs-3.5/include-graphics-text-h.md) *)
				A2 - (struct [FontRequester](autodocs-3.5/include-libraries-asl-h.md) *)
			(V38)

	ASLFO_HookFunc (APTR) - A function that is called if the
			FOF_FILTERFUNC or FOF_INTUIFUNC flags are specified in
			the ASLFO_Flags tag. The function will be called like
			so, with the arguments on the stack using the standard
			C pushing order:

				ULONG function(ULONG mask, [APTR](autodocs-3.5/include-exec-types-h.md) object,
					       struct [FontRequester](autodocs-3.5/include-libraries-asl-h.md) *fr)

			The Mask value is a copy of the specific ASLFO_Flags
			value the callback is for, either FOF_FILTERFUNC or
			FOF_INTUIFUNC; object is a pointer to a data object
			(a (struct [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) *) for FOF_INTUIFUNC, and a
			(struct [TextAttr](autodocs-3.5/include-graphics-text-h.md) *) for FOF_FILTERFUNC).

			For FOF_FILTERFUNC, the function should return 1 if the
			font should be added to the list, 0 if it
			shouldn't. For FOF_INTUIFUNC, the function should
			return the original (struct [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) *) it was
			passed.

	ASLFO_MaxFrontPen (UBYTE) - The maximum number of pens that are offered
			to the user when the ASLFO_DoFrontPen tag is specified.
			Default is 255. (V40)

	ASLFO_MaxBackPen (UBYTE) - The maximum number of pens that are offered
			to the user when the ASLFO_DoBackPen tag is specified.
			Default is 255. (V40)

	ASLFO_ModeList (STRPTR *) - Replacement list of modes to display in
			Mode cycle gadget. The first string pointer is used
			as the name of the gadgets, and following strings are
			used as the different labels of the cycle gadget,
			until a NULL string pointer which denotes the end of
			the string pointer array. The first string in this
			array corresponds to JAM1, the second is JAM2, the
			third to COMPLEMENT. The array can be early terminated
			by not providing all entries. English default for
			the array is "Text" "Text+Field" and "Complement".
			(V36)

	ASLFO_FrontPens (UBYTE *) - Pointer to a table of pen numbers
			indicating  which colors should be used and edited
			by the palette gadget when the ASLFO_DoFrontPen tag is
			specified. This array must contain as many entries as
			there are colors displayed in the palette gadget. The
			Default is NULL, which causes a 1-to-1 mapping of pen
			numbers. (V40)

	ASLFO_BackPens (UBYTE *) - Pointer to a table of pen numbers
			indicating  which colors should be used and edited
			by the palette gadget when the ASLFO_DoBackPen tag is
			specified. This array must contain as many entries as
			there are colors displayed in the palette gadget. The
			Default is NULL, which causes a 1-to-1 mapping of pen
			numbers. (V40)

	ASLFO_PopToFront (BOOL) -- When set to TRUE, this tells ASL to
	        bring the screen to the front the requester has opened on.
	        The position of the screen will be adjusted, too, to bring
	        the area into view the window has opened in. The screen
	        brought to the front will be pushed into the background
	        again when the requester window closes.
	        Default is TRUE. (V44)

	Tags used for the screen mode requester (V38):

	ASLSM_Window (struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *) - Parent window of requester. If no
			ASLSM_Screen tag is specified, the window structure
			is used to determine on which screen to open the
			requesting window. (V38)

	ASLSM_PubScreenName (STRPTR) - Name of a public screen to open on.
			This overrides the screen used by ASLSM_Window. (V38)

	ASLSM_Screen (struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *) - [Screen](autodocs-3.5/include-intuition-screens-h.md) on which to open the requester.
			This overrides the screen used by ASLSM_Window or by
			ASLSM_PubScreenName. (V38)

	ASLSM_PrivateIDCMP (BOOL) - When set to TRUE, this tells ASL to
			allocate a new IDCMP port for the requesting window.
			If not specified or set to FALSE, and if ASLSM_Window
			is provided, the requesting window will share
			ASLSM_Window's IDCMP port. (V38)

	ASLSM_IntuiMsgFunc (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *) - A function to call whenever an
			unknown Intuition message arrives at the message port
			being used by the requesting window. The function
			receives the following parameters:
				A0 - (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *)
				A1 - (struct [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) *)
				A2 - (struct [ScreenModeRequester](autodocs-3.5/include-libraries-asl-h.md) *)
			(V38)

	ASLSM_SleepWindow (BOOL) - When set to TRUE, this tag will cause the
			window specified by ASLSM_Window to be "put to
			sleep". That is, a busy pointer will be displayed in
			the parent window, and no gadget or menu activity will
			be allowed. This is done by opening an invisible
			Intuition [Requester](autodocs-3.5/include-intuition-intuition-h.md) in the parent window. (V38)

	ASLSM_UserData (APTR) - A 32-bit value that is simply copied in the
			sm_UserData field of the requester structure. (V38)

	ASLSM_TextAttr (struct [TextAttr](autodocs-3.5/include-graphics-text-h.md) *) - Font to be used for the requesting
			window's gadgets and menus. If this tag is not provided
			or its value is NULL, the default font of the screen
			on which the requesting window opens will be used.
			This font must already be in memory as ASL calls
			[OpenFont()](autodocs-3.5/graphics-library-openfont-2.md) and not [OpenDiskFont()](autodocs-3.5/diskfont-library-opendiskfont-2.md).
			(V38)

	ASLSM_Locale (struct [Locale](autodocs-3.5/include-libraries-locale-h.md) *) - [Locale](autodocs-3.5/include-libraries-locale-h.md) to use for the requesting
			window. This determines the language used for the
			requester's gadgets and menus. If this tag is not
			provided or its value is NULL, the system's current
			default locale will be used. (V38)

	ASLSM_TitleText (STRPTR) - Title to use for the requesting window.
			Default is no title. (V38)

	ASLSM_PositiveText (STRPTR) - Label of the positive gadget in the
			requester. English default is "OK". Prior to V38, this
			string could not be longer than 6 characters. (V36)

	ASLSM_NegativeText (STRPTR) - Label of the negative gadget in the
			requester. English default is "Cancel". Prior to V38,
			this string could not be longer than 6 characters.
			(V36)

	ASLSM_InitialLeftEdge (WORD) - Suggested left edge of requesting
			window. (V38)

	ASLSM_InitialTopEdge (WORD) - Suggested top edge of requesting
			window. (V38)

	ASLSM_InitialWidth (WORD) - Suggested width of requesting window. (V38)

	ASLSM_InitialHeight (WORD) - Suggested height of requesting window.
			(V38)

	ASLSM_InitialDisplayID (ULONG) - Initial setting of the Mode list view
			gadget (sm_DisplayID). Default is 0 (LORES_KEY). (V38)

	ASLSM_InitialDisplayWidth (ULONG) - Initial setting of the Width gadget
			(sm_DisplayWidth). Default is 640. (V38)

	ASLSM_InitialDisplayHeight (ULONG) - Initial setting of the Height
			gadget (sm_DisplayHeight). Default is 200. (V38)

	ASLSM_InitialDisplayDepth (UWORD) - Initial setting of the Colors
			gadget (sm_DisplayDepth). Default is 2. (V38)

	ASLSM_InitialOverscanType (UWORD) - Initial setting of the
			Overscan Type cycle gadget (sm_OverscanType).
			These values are the OSCAN_#? values from
			[<intuition/screens.h>](autodocs-3.5/include-intuition-screens-h.md).

			User-space naming of overscan types is different than
			programmer-space:

			Under V38:
			     0               -->  "Regular Size"
			     OSCAN_TEXT      -->  "Text Size"
			     OSCAN_STANDARD  -->  "Graphics Size"
			     OSCAN_MAXIMUM   -->  "Maximum Size"

			Under V39 and above:
			     OSCAN_TEXT      -->  "Text Size"
			     OSCAN_STANDARD  -->  "Graphics Size"
			     OSCAN_MAXIMUM   -->  "Extreme Size"
			     OSCAN_VIDEO     -->  "Maximum Size"

			OSCAN_VIDEO is not supported prior to V39. The value
			0 corresponds to "Regular Size" under V38. Since this
			value isn't supported by Intuition's SA_Overscan
			tag, it was removed from ASL in V39. Asking for 0
			under V39 will yield OSCAN_TEXT.

			Default is OSCAN_TEXT. (V38)

	ASLSM_InitialAutoScroll (BOOL) - Initial setting of the AutoScroll
			cycle gadget (sm_AutoScroll). Default is TRUE. (V38)

	ASLSM_InitialInfoOpened (BOOL) - Whether to open the property
			information window automatically. Default is FALSE.
			(V38)

	ASLSM_InitialInfoLeftEdge (WORD) - Initial left edge of information
			window. (V38)

	ASLSM_InitialInfoTopEdge (WORD) - Initial top edge of information
			window. (V38)

	ASLSM_DoWidth (BOOL) - Set this tag to TRUE to cause the requester
			to display the Width numeric gadget. Default is FALSE.
			(V38)

	ASLSM_DoHeight (BOOL) - Set this tag to TRUE to cause the requester
			to display the Height numeric gadget. Default is FALSE.
			(V38)

	ASLSM_DoDepth (BOOL) - Set this tag to TRUE to cause the requester to
			display the Colors slider gadget. Default is FALSE.
			(V38)

	ASLSM_DoOverscanType (BOOL) - Set this tag to TRUE to cause the
			requester to display the Overscan Type cycle gadget.
			Default is FALSE. (V38)

	ASLSM_DoAutoScroll (BOOL) - Set this tag to TRUE to cause the requester
			to display the AutoScroll checkbox gadget. Default is
			FALSE. (V38)

	ASLSM_PropertyFlags (ULONG) - A mode must have these property flags to
			appear in the list of modes. Only the bits set in
			ASLSM_PropertyMask are considered. See the description
			of ASLSM_PropertyMask for more info. Default is
			DIPF_IS_WB. (V38)

	ASLSM_PropertyMask (ULONG) - A mask to apply to ASLSM_PropertyFlags
			to determine which bits to consider. The use of these
			two values is identical in concept to how Exec uses
			the two flag paraneters in [exec.library/SetSignal()](autodocs-3.5/exec-library-setsignal-2.md).
			Default is DIPF_IS_WB. This is how this tag and the
			ASLSM_PropertyFlags tag interact:

			if ((displayInfo.PropertyFlags & propertyMask) ==
			   (propertyFlags & propertyMask))
			{
			    /* Mode accepted */
			}
			else
			{
			    /* Mode rejected */
			}

			where "displayInfo" is a filled in [DisplayInfo](autodocs-3.5/include-graphics-displayinfo-h.md)
			structure for a given mode. (V38)

	ASLSM_MinWidth (ULONG) - The minimum display width to let the user
			choose. Default is 16. (V38)

	ASLSM_MaxWidth (ULONG) - The maximum display width to let the user
			choose. Default is 16368. (V38)

	ASLSM_MinHeight (ULONG) - The minimum display height to let the user
			choose. Default is 16. (V38)

	ASLSM_MaxHeight (ULONG) - The maximum display height to let the user
			choose. Default is 16384. (V38)

	ASLSM_MinDepth (UWORD) - The minimum display depth to let the user
			choose. Default is 1. (V38)

	ASLSM_MaxDepth (UWORD) - The maximum display depth to let the user
			choose. Default is 24. (V38)

	ASLSM_FilterFunc (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *) - A function to call for each mode
			encountered. If the function returns TRUE, the mode is
			included in the file list, otherwise it is rejected
			and not displayed. The function receives the following
			parameters:
				A0 - (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *)
				A1 - (ULONG) mode id
				A2 - (struct [ScreenModeRequester](autodocs-3.5/include-libraries-asl-h.md) *)
			(V38)

	ASLSM_CustomSMList (struct [List](autodocs-3.5/include-exec-lists-h.md) *) - [Custom](autodocs-3.5/include-hardware-custom-h.md) list of modes to let
			the user choose from. This is a list of DisplayNode
			nodes, see [<libraries/asl.h>](autodocs-3.5/include-libraries-asl-h.md) for the definition. (V38)

	ASLSM_PopToFront (BOOL) -- When set to TRUE, this tells ASL to
	        bring the screen to the front the requester has opened on.
	        The position of the screen will be adjusted, too, to bring
	        the area into view the window has opened in. The screen
	        brought to the front will be pushed into the background
	        again when the requester window closes.
	        Default is TRUE. (V44)

   RESULT
	result - FALSE if the user cancelled the requester or if something
		 prevented the requester from opening. If TRUE, values in the
		 requester structure will be set depending on the particular
		 type of requester.

		 Under V38, If the return value is FALSE, you can look
		 at the result from the [dos.library/IoErr()](autodocs-3.5/dos-library-ioerr-2.md) function to
		 determine whether the requester was cancelled or simply
		 failed to open. If [dos.library/IoErr()](autodocs-3.5/dos-library-ioerr-2.md) returns 0, then the
		 requester was cancelled, any other value indicates a failure
		 to open. Current possible failure codes are
		 ERROR_NO_FREE_STORE which indicates there was not enough
		 memory, and ERROR_NO_MORE_ENTRIES which indicates no modes
		 were available for display in the screen mode requester
		 (usually because the application filter hook filtered them
		 all away)

   WARNING
	All ASL requester data structures are READ-ONLY and can only be
	modified by using tags!

	You must not specify requester options by using both pre-V38
	tags like ASLFR_Flags1 and V38 tags like ASLFR_DoSaveMode as
	this can lead to unexpected results.

	Take care when attaching an ASL requester to a simple refresh
	window or a window that already shares its IDCMP with other
	windows. In such cases you must ask for the ASL requester to
	allocate a private IDCMP (with the ASLFR_PrivateIDCMP,
	ASLFO_PrivateIDCMP and ASLSM_PrivateIDCMP tags) or your window
	will lose IDCMP_REFRESHWINDOW events and other messages.

   BUGS
	Under V38 and V39, the filtering functions for the file requester
	were only asked to filter drawer selections if the ASLFR_FilterDrawers
	tag was set to TRUE. The compatible behavior, reestablished in V40,
	is to always pass drawers for filtering.

   NOTES
	As of V38-V40 the ASL requester uses gadtools.library routines to
	create and maintain its user interface. Every [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) the library
	passes through the functions specified with ASLSM_IntuiMsgFunc and
	ASLSM_HookFunc will have been filtered through the
	[gadtools.library/GT_GetIMsg()](autodocs-3.5/gadtools-library-gt-getimsg-2.md) routine.

   SEE ALSO
	[AllocAslRequest()](autodocs-3.5/asl-library-allocaslrequest-2.md), [FreeAslRequest()](autodocs-3.5/asl-library-freeaslrequest-2.md)

---

## See Also

- [AllocAslRequest — asl.library](../autodocs/asl.library.md#allocaslrequest)
- [AslRequest — asl.library](../autodocs/asl.library.md#aslrequest)
- [FreeAslRequest — asl.library](../autodocs/asl.library.md#freeaslrequest)
- [GT_GetIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_getimsg)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [OpenDiskFont — diskfont.library](../autodocs/diskfont.library.md#opendiskfont)
- [OpenFont — graphics.library](../autodocs/graphics.library.md#openfont)
- [ParsePatternNoCase — dos.library](../autodocs/dos.library.md#parsepatternnocase)
- [SetSignal — exec.library](../autodocs/exec.library.md#setsignal)
