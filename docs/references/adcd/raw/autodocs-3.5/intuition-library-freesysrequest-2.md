# intuition.library/FreeSysRequest



    NAME
	FreeSysRequest -- Free resources gotten by a call to [BuildSysRequest()](../Includes_and_Autodocs_3._guide/node0399.html).

    SYNOPSIS
	FreeSysRequest( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) )
		        A0

	VOID FreeSysRequest( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) * );

    FUNCTION
	This routine frees up all memory allocated by a successful call to
	the [BuildSysRequest()](../Includes_and_Autodocs_3._guide/node0399.html) procedure.  If [BuildSysRequest()](../Includes_and_Autodocs_3._guide/node0399.html) returned a
	pointer to a window, then you are able to wait on the message port
	of that window to detect an event which satisfies the requester.
	When you want to remove the requester, you call this procedure.  It
	ends the requester and deallocates any memory used in the creation
	of the requester.  It also closes the special window that was opened
	for your system requester.

	For V36: It's OK if you pass a NULL or a TRUE (1) value to
	this function.  Also, this function properly disposes of
	requesters gotten using [BuildEasyRequestArgs()](../Includes_and_Autodocs_3._guide/node0398.html).

    INPUTS
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = value of the window pointer returned by a successful call to
```c
           the [BuildSysRequest()](../Includes_and_Autodocs_3._guide/node0399.html) procedure

    RESULT
```
	None

    BUGS

    SEE ALSO
	[BuildSysRequest()](../Includes_and_Autodocs_3._guide/node0399.html), [AutoRequest()](../Includes_and_Autodocs_3._guide/node0396.html), [CloseWindow()](../Includes_and_Autodocs_3._guide/node03A0.html)

