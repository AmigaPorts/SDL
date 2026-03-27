# intuition.library/GetDefaultPubScreen



    NAME
	GetDefaultPubScreen -- Get name of default public screen. (V36)

    SYNOPSIS
	GetDefaultPubScreen( Namebuff )
			     A0

	VOID GetDefaultPubScreen( [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) * );

    FUNCTION
	Provides the name of the current default public screen.
	Only anticipated use is for Public [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) Manager utilities,
	since it is easy to open a visitor window on the default
	public screen without specifying the name.

    INPUTS
	Namebuff = a buffer of MAXPUBSCREENNAME.  This can be NULL.

    RESULT
	None.  Will provide the string "Workbench" in Namebuff if there
	is no current default public screen.

    NOTES
	This function actually "returns" in register D0 a pointer
	to the public screen.  Unfortunately, the lifespan of
	this pointer is not ensured; the screen could be closed
	at any time.  The *ONLY* legitimate use we can see for
	this return value is to compare for identity with the pointer
	to a public screen you either have a window open in, or
	a lock on using [LockPubScreen()](../Includes_and_Autodocs_3._guide/node03C1.html), to determine if that
	screen is in fact the default screen.

	Also note that if there no default public screen has been set,
	the return value of this function will be zero, and not a pointer
	to the Workbench screen.

    BUGS
	The function prototype does not reflect the return value.

    SEE ALSO
	[SetDefaultPubScreen()](../Includes_and_Autodocs_3._guide/node03EE.html), [OpenWindow()](../Includes_and_Autodocs_3._guide/node03D5.html)

