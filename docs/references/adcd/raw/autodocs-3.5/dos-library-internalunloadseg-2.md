# dos.library/InternalUnLoadSeg



   NAME
	InternalUnLoadSeg -- Unloads a seglist loaded with [InternalLoadSeg()](../Includes_and_Autodocs_3._guide/node0180.html) (V36)

   SYNOPSIS
	success = InternalUnLoadSeg(seglist,FreeFunc)
	  D0			      D1       A1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) InternalUnLoadSeg(BPTR,void (*)(STRPTR,ULONG))

   FUNCTION
	Unloads a seglist using freefunc to free segments.  Freefunc is called
	as for [InternalLoadSeg](../Includes_and_Autodocs_3._guide/node0180.html).  NOTE: will call [Close()](../Includes_and_Autodocs_3._guide/node0149.html) for overlaid
	seglists.

   INPUTS
	seglist  - Seglist to be unloaded
	FreeFunc - Function called to free memory

   RESULT
	success - returns whether everything went OK (since this may close
		  files).  Also returns FALSE if seglist was NULL.

   BUGS
	Really should use tags

   SEE ALSO
	[LoadSeg()](../Includes_and_Autodocs_3._guide/node0185.html), [UnLoadSeg()](../Includes_and_Autodocs_3._guide/node01C7.html), [InternalLoadSeg()](../Includes_and_Autodocs_3._guide/node0180.html), NewUnLoadSeg(), [Close()](../Includes_and_Autodocs_3._guide/node0149.html)

