---
title: intuition.library/EasyRequestArgs
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-easyrequestargs-2
functions: [AutoRequest, BuildEasyRequestArgs, BuildSysRequest, EasyRequestArgs, RawDoFmt, SysReqHandler]
libraries: [exec.library, intuition.library]
---

# intuition.library/EasyRequestArgs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	EasyRequestArgs -- Easy alternative to [AutoRequest()](autodocs-3.5/intuition-library-autorequest-2.md). (V36)
	EasyRequest -- Varargs stub for EasyRequestArgs(). (V36)

    SYNOPSIS
	num = EasyRequestArgs( [Window](autodocs-3.5/include-intuition-intuition-h.md), easyStruct, IDCMP_ptr, ArgList )
	D0                     A0      A1          A2         A3

	[LONG](autodocs-3.5/include-exec-types-h.md) EasyRequestArgs( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, struct [EasyStruct](autodocs-3.5/include-intuition-intuition-h.md) *,
		ULONG *, [APTR](autodocs-3.5/include-exec-types-h.md) );

	num = EasyRequest( [Window](autodocs-3.5/include-intuition-intuition-h.md), easyStruct, IDCMP_ptr, Arg1, Arg2, ... )

	[LONG](autodocs-3.5/include-exec-types-h.md) EasyRequest( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, struct [EasyStruct](autodocs-3.5/include-intuition-intuition-h.md) *,
		ULONG *, [APTR](autodocs-3.5/include-exec-types-h.md), ... );

	( from intuition.h )
	struct [EasyStruct](autodocs-3.5/include-intuition-intuition-h.md) {
	    ULONG	es_StructSize;
	    ULONG	es_Flags;
	    [UBYTE](autodocs-3.5/include-exec-types-h.md)	*es_Title;
	    [UBYTE](autodocs-3.5/include-exec-types-h.md)	*es_TextFormat;
	    [UBYTE](autodocs-3.5/include-exec-types-h.md)	*es_GadgetFormat;
	};

    FUNCTION
	This function provides a simpler method of using a 'System
	Requester' than provided by [AutoRequest()](autodocs-3.5/intuition-library-autorequest-2.md).  It performs layout
	and size calculations sensitive to the current font and screen
	resolution.

	It provides for the descriptive 'body' text and the gadget
	text to be constructed from 'printf' style format strings.

	It also provides a general way for the requester to be
	sensitive to particular IDCMP messages.

	The first function listed is the actual Intuition library
	function.  It is passed the arguments for the formatting
	operations as a pointer to the first argument.

	The second function uses a C-style variable number of argument
	(varargs) calling convention.  It should be implemented as
	a call to the first function, and might be supplied by your
	compiler vendor, in amiga.lib, or using the first example below,
	for most C compilers.

	NOTE: The formatting is done by [exec.library/RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md), so
	be aware that to display a 32-bit integer argument, for
	example, you must say "%ld", not "%d", since [RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md) is
	"word-oriented."

	NOTE: This function switches the processor stack to ensure
	sufficient stack space for the function to complete.

    EXAMPLES
	/* varargs interface works for most C compilers */
	EasyRequest( w, es, ip, arg1 )
	struct [Window](autodocs-3.5/include-intuition-intuition-h.md)	*w;
	struct [EasyStruct](autodocs-3.5/include-intuition-intuition-h.md) *es;
	ULONG		  *ip;
	int		  arg1;
	{
	    return ( EasyRequestArgs( w, es, ip, &arg1 ) );
	}

	/*********************************************/

	/* typical use */
	struct [EasyStruct](autodocs-3.5/include-intuition-intuition-h.md) volumeES = {
	    sizeof (struct EasyStruct),
	    0,
	    "Volume Request",
	    "Please insert volume %s in any drive.",
	    "Retry|Cancel",
	};
	#define CANCEL	(0)

	Volume	*
	getVolume( volname )
	[UBYTE](autodocs-3.5/include-exec-types-h.md)	*volname;
	{
	    Volume	*vptr;
	    Volume	*findVolume();
	    [UWORD](autodocs-3.5/include-exec-types-h.md)	reply;
	    ULONG	iflags;

	    iflags = IDCMP_DISKINSERTED;

	while ( ((vptr = findVolume( volname )) == NULL) &&
	 (EasyRequest( w, &volumeES, &iflags, volname ) != CANCEL) )
		/* loop */ ;

	    /* note that in some circumstances, you will have to
	       re-initialize the value of 'iflags'.  Here, it
	       is either unchanged, or returned as the single
	       IDCMPFlag value IDCMP_DISKINSERTED.  If you combine
	       multiple  IDCMPFlag values in 'iflags,' only
	       one will be returned, so you must reinitialize
	       'iflags' to be the combination.
	      */
	    return ( vptr );
	}

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = Reference window pointer, determines the screen and
	    title of the requester window.  This can be NULL, which
	    means the requester is to appear on the Workbench screen,
	    or default public screen, if defined.
	IDCMP_ptr = Pointer to IDCMP flags that you want to terminate
		the requester.  This pointer may be NULL.
	easyStruct = Pointer to [EasyStruct](autodocs-3.5/include-intuition-intuition-h.md) structure with fields
		interpreted as follows:

	es_StructSize = sizeof (struct EasyStruct), for future extension.
	es_Flags = 0 for now, in the future may specify other options.
	es_Title = Title of system requester window.  If this is NULL,
	    the title will be taken to be the same as the title of 'Window',
	    if provided, or else "System Request."
	es_TextFormat = [Format](autodocs-3.5/dos-library-format-2.md) string, a la [RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md), for message in
	    requester body.  Lines are separated by the newline character.
	    This character is represented in C by 'n', in the Amiga Shell
	    by "*N", etc.  Formatting '%' functions are supported exactly
	    as in [RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md).
	es_GadgetFormat = [Format](autodocs-3.5/dos-library-format-2.md) string for gadgets.  [Text](autodocs-3.5/graphics-library-text-2.md) for separate
	    gadgets is separated by '|'.  [Format](autodocs-3.5/dos-library-format-2.md) functions are supported.
	    You MUST specify at least one gadget.

	ArgList = Arguments for format commands.   Arguments for
	    GadFmt follow arguments for TextFmt.

    RESULT
	0, 1, ..., N = Successive GadgetID values, for the gadgets
	    you specify for the requester.  NOTE: The numbering
	    from left to right is actually: 1, 2, ..., N, 0.
	    This is for compatibility with [AutoRequest()](autodocs-3.5/intuition-library-autorequest-2.md), which has
	    FALSE for the rightmost gadget.

	-1 = Means that one of the caller-supplied IDCMPFlags occurred.
	    The IDCMPFlag value is in the longword pointed to by IDCMP_ptr.

    NOTES
	When DOS brings up EasyRequests() on your process (eg.
	"Please insert volume XXX in any drive", they normally come
	up on the default public screen, which is usually the Workbench
	screen.  If you set your [Process](autodocs-3.5/include-dos-dosextens-h.md) pr_WindowPtr field to point to
	one of your windows, then DOS will bring its requesters up on the
	same screen as that window.  A pr_WindowPtr of -1 prevents
	requesters from coming up at all.
	(Some FileSystem requesters cannot be redirected or supressed).

    BUGS
	Does not fall back to a recoverable alert if the requester
	 cannot be created.

	Does not handle case when gadgets don't fit or window title
	is too long, although it does trim trailing spaces from the
	title for calculating dimensions.

    PLANS
	Possible enhancements include: centering of text, size-sensitive
	layout,  window-relative requester, vertical gadget layout,
	window placement, more keyboard shortcuts.

	We also reserve the use of the newline character ('n') in
	gadget format strings for future use as a line separator.

    SEE ALSO
	[exec.library/RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md), [BuildEasyRequestArgs()](autodocs-3.5/intuition-library-buildeasyrequestargs-2.md), [SysReqHandler()](autodocs-3.5/intuition-library-sysreqhandler-2.md),
	[AutoRequest()](autodocs-3.5/intuition-library-autorequest-2.md), [BuildSysRequest()](autodocs-3.5/intuition-library-buildsysrequest-2.md)

---

## See Also

- [AutoRequest — intuition.library](../autodocs/intuition.library.md#autorequest)
- [BuildEasyRequestArgs — intuition.library](../autodocs/intuition.library.md#buildeasyrequestargs)
- [BuildSysRequest — intuition.library](../autodocs/intuition.library.md#buildsysrequest)
- [EasyRequestArgs — intuition.library](../autodocs/intuition.library.md#easyrequestargs)
- [RawDoFmt — exec.library](../autodocs/exec.library.md#rawdofmt)
- [SysReqHandler — intuition.library](../autodocs/intuition.library.md#sysreqhandler)
