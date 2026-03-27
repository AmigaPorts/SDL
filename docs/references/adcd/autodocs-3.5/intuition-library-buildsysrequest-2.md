---
title: intuition.library/BuildSysRequest
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-buildsysrequest-2
functions: [AutoRequest, BuildEasyRequestArgs, DisplayAlert, EasyRequestArgs, FreeSysRequest, ModifyIDCMP, Request, SysReqHandler, Wait]
libraries: [exec.library, intuition.library]
---

# intuition.library/BuildSysRequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	BuildSysRequest -- Build and display a system requester.

    SYNOPSIS
	ReqWindow = BuildSysRequest( [Window](autodocs-3.5/include-intuition-intuition-h.md), BodyText, PosText, NegText,
	D0                           A0      A1        A2       A3
		           IDCMPFlags, Width, Height )
			   D0          D1     D2

	struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *BuildSysRequest( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, struct [IntuiText](autodocs-3.5/include-intuition-intuition-h.md) *,
		struct [IntuiText](autodocs-3.5/include-intuition-intuition-h.md) *, struct [IntuiText](autodocs-3.5/include-intuition-intuition-h.md) *, ULONG, WORD, WORD );

    FUNCTION
	This procedure builds a system requester based on the supplied
	information.  If all goes well and the requester is constructed,
	this procedure returns a pointer to the window in which the requester
	appears.  That window will have its IDCMP initialized to reflect the
	flags found in the IDCMPFlags argument.  You may then wait on those
	ports to detect the user's response to your requester, which response
	may include either selecting one of the gadgets or causing some other
	event to be noticed by Intuition (like IDCMP_DISKINSERTED, for
	instance).  After the requester is satisfied, you should call the
	[FreeSysRequest()](autodocs-3.5/intuition-library-freesysrequest-2.md) procedure to remove the requester and free up
	any allocated memory.

	See the autodoc for [SysReqHandler()](autodocs-3.5/intuition-library-sysreqhandler-2.md) for more information on the
	how to handle the IntuiMessages this window will receive.

	The requester used by this function has the NOISYREQ flag bit set,
	which means that the set of IDCMPFlags that may be used here
	include IDCMP_RAWKEY, IDCMP_MOUSEBUTTONS, and others.

	In release previous to V36, if the requester could not be built,
	this function would try to call [DisplayAlert()](autodocs-3.5/intuition-library-displayalert-2.md) with the same
	information, with more or less favorable results.  In V36,
	the requesters themselves require less memory (SIMPLEREQ), but
	there is no alert attempt.

	The function may return TRUE (1) or FALSE if it cannot post
	the requester.  (V36 will always return FALSE, but be sure to
	test for TRUE in case somebody reinstates the fallback alert.)

	If the window argument you supply is equal to NULL, a new window will
	be created for you in the Workbench screen, or the default
	public screen, for V36.  If you want the requester
	created by this routine to be bound to a particular window (i.e.,
	to appear in the same screen as the window), you should
	not supply a window argument of NULL.

	New for V36: if you pass a NULL window pointer, the system requester
	will appear on the default public screen, which is not always
	the Workbench.

	The text arguments are used to construct the display.  Each is a
	pointer to an instance of the structure [IntuiText](autodocs-3.5/include-intuition-intuition-h.md).

	The BodyText argument should be used to describe the nature of
	the requester.  As usual with [IntuiText](autodocs-3.5/include-intuition-intuition-h.md) data, you may link several
	lines of text together, and the text may be placed in various
	locations in the requester.  This [IntuiText](autodocs-3.5/include-intuition-intuition-h.md) pointer will be stored
	in the ReqText variable of the new requester.

	The PosText argument describes the text that you want associated
	with the user choice of "Yes,  TRUE,  Retry,  Good."  If the requester
	is successfully opened, this text will be rendered in a gadget in
	the lower-left of the requester, which gadget will have the
	GadgetID field set to TRUE.  If the requester cannot be opened and
	the [DisplayAlert()](autodocs-3.5/intuition-library-displayalert-2.md) mechanism is used, this text will be rendered in
	the lower-left corner of the alert display with additional text
	specifying that the left mouse button will select this choice.  This
	pointer can be set to NULL, which specifies that there is no TRUE
	choice that can be made.

	The NegText argument describes the text that you want associated
	with the user choice of "No,  FALSE,  Cancel,  Bad."  If the requester
	is successfully opened, this text will be rendered in a gadget in
	the lower-right of the requester, which gadget will have the
	GadgetID field set to FALSE.  If the requester cannot be opened and
	the [DisplayAlert()](autodocs-3.5/intuition-library-displayalert-2.md) mechanism is used, this text will be rendered in
	the lower-right corner of the alert display with additional text
	specifying that the right mouse button will select this choice.  This
	pointer cannot be set to NULL.  There must always be a way for the
	user to cancel this requester.

	The Positive and Negative Gadgets created by this routine have
	the following features:

          - GTYP_BOOLGADGET
          - GACT_RELVERIFY
          - GTYP_REQGADGET
          - GACT_TOGGLESELECT
	When defining the text for your gadgets, you may find it convenient
	to use the special constants used by Intuition for the construction
	of the gadgets.  These include defines like AUTODRAWMODE, AUTOLEFTEDGE,
	AUTOTOPEDGE and AUTOFRONTPEN.  You can find these in your local
	intuition.h (or intuition.i) file.

	These hard-coded constants are not very resolution or font
	sensitive, but V36 will override them to provide more modern
	layout.

	New for V36, linked lists of [IntuiText](autodocs-3.5/include-intuition-intuition-h.md) are not correctly supported
	for gadget labels.

	The width and height values describe the size of the requester.  All
	of your BodyText must fit within the width and height of your
	requester.  The gadgets will be created to conform to your sizes.

	VERY IMPORTANT NOTE:  for this release of this procedure, a new window
	is opened in the same screen as the one containing your window.
	Future alternatives may be provided as a function distinct from this
	one.

	NOTE: This function will pop the screen the requester and its
	window appears in to the front of all screens.  New for V36,
	if the user doesn't perform any other screen arrangement before
	finishing with the requester, a popped screen will be pushed
	back behind.

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to a [Window](autodocs-3.5/include-intuition-intuition-h.md) structure
	BodyText = pointer to an [IntuiText](autodocs-3.5/include-intuition-intuition-h.md) structure
	PosText = pointer to an [IntuiText](autodocs-3.5/include-intuition-intuition-h.md) structure
	NegText = pointer to an [IntuiText](autodocs-3.5/include-intuition-intuition-h.md) structure
	IDCMPFlags = the IDCMP flags you want used for the initialization of the
           IDCMP of the window containing this requester
	Width, Height = the size required to render your requester

	NOTE for V36: the width and height you pass are ignored, as
	are some of the parameters of your [IntuiText](autodocs-3.5/include-intuition-intuition-h.md), so that Intuition
	can make the Requesters real nice for the new look.

    RESULT
	If the requester was successfully created, the value
	returned by this procedure is a pointer to the window in which the
	requester is rendered.  If the requester could not be created,
	this routine might have called [DisplayAlert()](autodocs-3.5/intuition-library-displayalert-2.md) before returning
	(it depends on the version) and will pass back TRUE if the user
	pressed the left mouse button and FALSE if the user pressed the
	right mouse button.   If the version of Intuition doesn't
	call [DisplayAlert()](autodocs-3.5/intuition-library-displayalert-2.md), or if it does, and there's not enough
	memory for the alert, the value of FALSE is returned.

    BUGS
	This procedure currently opens a window in the [Screen](autodocs-3.5/include-intuition-screens-h.md) which
	contains the window which is passed as a parameter, or the
	default public screen, if that parameter is NULL.  Although
	not as originally envisioned, this will probably always be the
	behavior of this function.

	[DisplayAlert()](autodocs-3.5/intuition-library-displayalert-2.md) is not called in version V36.

	It's almost impossible to make complete, correct account
	of different system fonts, window border dimensions, and
	screen resolution to get the layout of a System [Requester](autodocs-3.5/include-intuition-intuition-h.md)
	just right using this routine.  For V36, we recommend the
	automatic layout implemented in [BuildEasyRequestArgs()](autodocs-3.5/intuition-library-buildeasyrequestargs-2.md) and
	[EasyRequestArgs()](autodocs-3.5/intuition-library-easyrequestargs-2.md).

    SEE ALSO
	[FreeSysRequest()](autodocs-3.5/intuition-library-freesysrequest-2.md), [DisplayAlert()](autodocs-3.5/intuition-library-displayalert-2.md), [ModifyIDCMP()](autodocs-3.5/intuition-library-modifyidcmp-2.md), [exec.library/Wait()](autodocs-3.5/exec-library-wait-2.md),
	[Request()](autodocs-3.5/intuition-library-request-2.md), [AutoRequest()](autodocs-3.5/intuition-library-autorequest-2.md), [EasyRequestArgs()](autodocs-3.5/intuition-library-easyrequestargs-2.md), [BuildEasyRequestArgs()](autodocs-3.5/intuition-library-buildeasyrequestargs-2.md)

---

## See Also

- [AutoRequest — intuition.library](../autodocs/intuition.library.md#autorequest)
- [BuildEasyRequestArgs — intuition.library](../autodocs/intuition.library.md#buildeasyrequestargs)
- [DisplayAlert — intuition.library](../autodocs/intuition.library.md#displayalert)
- [EasyRequestArgs — intuition.library](../autodocs/intuition.library.md#easyrequestargs)
- [FreeSysRequest — intuition.library](../autodocs/intuition.library.md#freesysrequest)
- [ModifyIDCMP — intuition.library](../autodocs/intuition.library.md#modifyidcmp)
- [Request — intuition.library](../autodocs/intuition.library.md#request)
- [SysReqHandler — intuition.library](../autodocs/intuition.library.md#sysreqhandler)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
