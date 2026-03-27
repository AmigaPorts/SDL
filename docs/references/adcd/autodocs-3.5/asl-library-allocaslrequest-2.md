---
title: asl.library/AllocAslRequest
manual: autodocs-3.5
chapter: autodocs-3.5
section: asl-library-allocaslrequest-2
functions: [AllocAslRequest, AslRequest, FreeAslRequest, GT_GetIMsg]
libraries: [asl.library, gadtools.library]
---

# asl.library/AllocAslRequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AllocAslRequest -- allocate an ASL requester. (V36)
	AllocAslRequestTags -- varargs stub for AllocAslRequest(). (V36)

   SYNOPSIS
	requester = AllocAslRequest(reqType,tagList);
	D0                          D0      A0

	[APTR](autodocs-3.5/include-exec-types-h.md) AllocAslRequest(ULONG,struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	requester = AllocAslRequestTags(reqType,firstTag, ...);

	[APTR](autodocs-3.5/include-exec-types-h.md) AllocAslRequestTags(ULONG,[Tag](autodocs-3.5/include-utility-tagitem-h.md),...);

   FUNCTION
	Allocates an ASL requester data structure of the specified type.

   INPUTS
	type - type of requester to allocate. Currently defined types
	       are ASL_FileRequest, ASL_FontRequest and ASL_ScreenModeRequest.
	       ASL_ScreenModeRequest is available starting with asl.library
	       V38 only.
	tags - pointer to an optional tag list specifying how to initialize the
	       data structure returned by this function. See the
	       documentation for [AslRequest()](autodocs-3.5/asl-library-aslrequest-2.md) for an explanation of
	       how to use the currently defined tags.

   RESULT
	requester - an initialized requester data structure, or NULL on
	            failure. The data structure returned corresponds to the
		    requested type;
			ASL_FileRequest       -> (struct [FileRequester](autodocs-3.5/include-libraries-asl-h.md) *)
			ASL_FontRequest       -> (struct [FontRequester](autodocs-3.5/include-libraries-asl-h.md) *)
			ASL_ScreenModeRequest -> (struct [ScreenModeRequester](autodocs-3.5/include-libraries-asl-h.md) *)

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
	[AslRequest()](autodocs-3.5/asl-library-aslrequest-2.md), [FreeAslRequest()](autodocs-3.5/asl-library-freeaslrequest-2.md)

---

## See Also

- [AllocAslRequest — asl.library](../autodocs/asl.library.md#allocaslrequest)
- [AslRequest — asl.library](../autodocs/asl.library.md#aslrequest)
- [FreeAslRequest — asl.library](../autodocs/asl.library.md#freeaslrequest)
- [GT_GetIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_getimsg)
