# intuition.library/EasyRequestArgs



    NAME
	EasyRequestArgs -- Easy alternative to [AutoRequest()](../Includes_and_Autodocs_3._guide/node0396.html). (V36)
	EasyRequest -- Varargs stub for EasyRequestArgs(). (V36)

    SYNOPSIS
	num = EasyRequestArgs( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), easyStruct, IDCMP_ptr, ArgList )
	D0                     A0      A1          A2         A3

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) EasyRequestArgs( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, struct [EasyStruct](../Includes_and_Autodocs_3._guide/node05E0.html#line1456) *,
		ULONG *, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) );

	num = EasyRequest( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), easyStruct, IDCMP_ptr, Arg1, Arg2, ... )

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) EasyRequest( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, struct [EasyStruct](../Includes_and_Autodocs_3._guide/node05E0.html#line1456) *,
		ULONG *, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37), ... );

	( from intuition.h )
	struct [EasyStruct](../Includes_and_Autodocs_3._guide/node05E0.html#line1456) {
	    ULONG	es_StructSize;
	    ULONG	es_Flags;
	    [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)	*es_Title;
	    [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)	*es_TextFormat;
	    [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)	*es_GadgetFormat;
	};

    FUNCTION
	This function provides a simpler method of using a 'System
	Requester' than provided by [AutoRequest()](../Includes_and_Autodocs_3._guide/node0396.html).  It performs layout
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

	NOTE: The formatting is done by [exec.library/RawDoFmt()](../Includes_and_Autodocs_3._guide/node0227.html), so
	be aware that to display a 32-bit integer argument, for
	example, you must say "%ld", not "%d", since [RawDoFmt()](../Includes_and_Autodocs_3._guide/node0227.html) is
	"word-oriented."

	NOTE: This function switches the processor stack to ensure
	sufficient stack space for the function to complete.

    EXAMPLES
	/* varargs interface works for most C compilers */
	EasyRequest( w, es, ip, arg1 )
	struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908)	*w;
	struct [EasyStruct](../Includes_and_Autodocs_3._guide/node05E0.html#line1456) *es;
	ULONG		  *ip;
	int		  arg1;
	{
	    return ( EasyRequestArgs( w, es, ip, &arg1 ) );
	}

	/*********************************************/

	/* typical use */
	struct [EasyStruct](../Includes_and_Autodocs_3._guide/node05E0.html#line1456) volumeES = {
	    sizeof (struct EasyStruct),
	    0,
	    "Volume Request",
	    "Please insert volume %s in any drive.",
	    "Retry|Cancel",
	};
	#define CANCEL	(0)

	Volume	*
	getVolume( volname )
	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)	*volname;
	{
	    Volume	*vptr;
	    Volume	*findVolume();
	    [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43)	reply;
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
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = Reference window pointer, determines the screen and
	    title of the requester window.  This can be NULL, which
	    means the requester is to appear on the Workbench screen,
	    or default public screen, if defined.
	IDCMP_ptr = Pointer to IDCMP flags that you want to terminate
		the requester.  This pointer may be NULL.
	easyStruct = Pointer to [EasyStruct](../Includes_and_Autodocs_3._guide/node05E0.html#line1456) structure with fields
		interpreted as follows:

	es_StructSize = sizeof (struct EasyStruct), for future extension.
	es_Flags = 0 for now, in the future may specify other options.
	es_Title = Title of system requester window.  If this is NULL,
	    the title will be taken to be the same as the title of 'Window',
	    if provided, or else "System Request."
	es_TextFormat = [Format](../Includes_and_Autodocs_3._guide/node016B.html) string, a la [RawDoFmt()](../Includes_and_Autodocs_3._guide/node0227.html), for message in
	    requester body.  Lines are separated by the newline character.
	    This character is represented in C by 'n', in the Amiga Shell
	    by "*N", etc.  Formatting '%' functions are supported exactly
	    as in [RawDoFmt()](../Includes_and_Autodocs_3._guide/node0227.html).
	es_GadgetFormat = [Format](../Includes_and_Autodocs_3._guide/node016B.html) string for gadgets.  [Text](../Includes_and_Autodocs_3._guide/node0332.html) for separate
	    gadgets is separated by '|'.  [Format](../Includes_and_Autodocs_3._guide/node016B.html) functions are supported.
	    You MUST specify at least one gadget.

	ArgList = Arguments for format commands.   Arguments for
	    GadFmt follow arguments for TextFmt.

    RESULT
	0, 1, ..., N = Successive GadgetID values, for the gadgets
	    you specify for the requester.  NOTE: The numbering
	    from left to right is actually: 1, 2, ..., N, 0.
	    This is for compatibility with [AutoRequest()](../Includes_and_Autodocs_3._guide/node0396.html), which has
	    FALSE for the rightmost gadget.

	-1 = Means that one of the caller-supplied IDCMPFlags occurred.
	    The IDCMPFlag value is in the longword pointed to by IDCMP_ptr.

    NOTES
	When DOS brings up EasyRequests() on your process (eg.
	"Please insert volume XXX in any drive", they normally come
	up on the default public screen, which is usually the Workbench
	screen.  If you set your [Process](../Includes_and_Autodocs_3._guide/node05D9.html#line36) pr_WindowPtr field to point to
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
	[exec.library/RawDoFmt()](../Includes_and_Autodocs_3._guide/node0227.html), [BuildEasyRequestArgs()](../Includes_and_Autodocs_3._guide/node0398.html), [SysReqHandler()](../Includes_and_Autodocs_3._guide/node03FB.html),
	[AutoRequest()](../Includes_and_Autodocs_3._guide/node0396.html), [BuildSysRequest()](../Includes_and_Autodocs_3._guide/node0399.html)

