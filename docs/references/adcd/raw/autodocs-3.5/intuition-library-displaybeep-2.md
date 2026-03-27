# intuition.library/DisplayBeep



    NAME
	DisplayBeep -- Flash the video display.

    SYNOPSIS
	DisplayBeep( [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) )
		     A0

	VOID DisplayBeep( struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) * );

    FUNCTION
	"Beeps" the video display by flashing the background color of the
	specified screen.  If the screen argument is NULL, every screen
	in the display will be beeped.  Flashing everyone's screen is not
	a polite thing to do, so this should be reserved for dire
	circumstances.

	The reason such a routine is supported is because the Amiga has
	no internal bell or speaker.  When the user needs to know of
	an event that is not serious enough to require the use of a requester,
	the DisplayBeep() function may be called.

	New for V36:  Intuition now calls DisplayBeep through the
	external library vector.  This means that if you call [SetFunction()](../Includes_and_Autodocs_3._guide/node0238.html)
	to replace DisplayBeep with an audible beep, for example, then
	your change will affect even Intuition's calls to DisplayBeep.

    INPUTS
	[Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) = pointer to a screen.  If NULL, every screen in the display
           will be flashed

    RESULT
	None

    NOTES
	Since this function changes color zero of the affected screen(s),
	surprising results could occur if the screen's owner reading
	colors or perhaps cycling them.


    BUGS

    SEE ALSO
