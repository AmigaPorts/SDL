# gadtools.library/FreeVisualInfo



   NAME
	FreeVisualInfo -- return any resources taken by GetVisualInfo. (V36)

   SYNOPSIS
	FreeVisualInfo(vi)
	               A0

	VOID FreeVisualInfo(APTR);

   FUNCTION
	FreeVisualInfo() returns any memory or other resources that
	were allocated by [GetVisualInfoA()](../Includes_and_Autodocs_3._guide/node027B.html).  You should only call this function
	once you are done with using the gadgets (i.e. after [CloseWindow()](../Includes_and_Autodocs_3._guide/node03A0.html)),
	but while the screen is still valid (i.e. before [CloseScreen()](../Includes_and_Autodocs_3._guide/node039F.html) or
	[UnlockPubScreen()](../Includes_and_Autodocs_3._guide/node03FE.html)).

   INPUTS
	vi - pointer that was obtained by calling [GetVisualInfoA()](../Includes_and_Autodocs_3._guide/node027B.html). This
	     value may be NULL.

   SEE ALSO
	[GetVisualInfoA()](../Includes_and_Autodocs_3._guide/node027B.html)

