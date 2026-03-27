# asl.library/AllocAslRequest



   NAME
	AllocAslRequest -- allocate an ASL requester. (V36)
	AllocAslRequestTags -- varargs stub for AllocAslRequest(). (V36)

   SYNOPSIS
	requester = AllocAslRequest(reqType,tagList);
	D0                          D0      A0

	[APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) AllocAslRequest(ULONG,struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	requester = AllocAslRequestTags(reqType,firstTag, ...);

	[APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) AllocAslRequestTags(ULONG,[Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29),...);

   FUNCTION
	Allocates an ASL requester data structure of the specified type.

   INPUTS
	type - type of requester to allocate. Currently defined types
	       are ASL_FileRequest, ASL_FontRequest and ASL_ScreenModeRequest.
	       ASL_ScreenModeRequest is available starting with asl.library
	       V38 only.
	tags - pointer to an optional tag list specifying how to initialize the
	       data structure returned by this function. See the
	       documentation for [AslRequest()](../Includes_and_Autodocs_3._guide/node005B.html) for an explanation of
	       how to use the currently defined tags.

   RESULT
	requester - an initialized requester data structure, or NULL on
	            failure. The data structure returned corresponds to the
		    requested type;
			ASL_FileRequest       -> (struct [FileRequester](../Includes_and_Autodocs_3._guide/node0601.html#line66) *)
			ASL_FontRequest       -> (struct [FontRequester](../Includes_and_Autodocs_3._guide/node0601.html#line186) *)
			ASL_ScreenModeRequest -> (struct [ScreenModeRequester](../Includes_and_Autodocs_3._guide/node0601.html#line286) *)

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
	create and maintain its user interface. Every [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) the library
	passes through the functions specified with ASLSM_IntuiMsgFunc and
	ASLSM_HookFunc will have been filtered through the
	[gadtools.library/GT_GetIMsg()](../Includes_and_Autodocs_3._guide/node0280.html) routine.

   SEE ALSO
	[AslRequest()](../Includes_and_Autodocs_3._guide/node005B.html), [FreeAslRequest()](../Includes_and_Autodocs_3._guide/node005C.html)

