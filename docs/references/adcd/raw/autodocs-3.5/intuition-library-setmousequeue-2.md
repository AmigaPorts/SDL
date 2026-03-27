# intuition.library/SetMouseQueue



    NAME
	SetMouseQueue -- Change limit on pending mouse messages. (V36)

    SYNOPSIS
	oldQueueLength = SetMouseQueue( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), QueueLength )
	D0                              A0      D0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) SetMouseQueue( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) );

    FUNCTION
	Changes the number of mouse messages that Intuition will allow
	to be outstanding for your window.

    INPUTS
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = your window
	QueueLength = the new value of outstanding mouse movement messages
	  you wish to allow.

    RESULT
	-1 if 'Window' is not known
	Otherwise the previous value of the queue limit.
	The corresponding function for changing the repeat key
	queue limit is not yet implemented.

    BUGS

    SEE ALSO
	[OpenWindow()](../Includes_and_Autodocs_3._guide/node03D5.html)

