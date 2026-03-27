# dos.library/UnLoadSeg



    NAME
	UnLoadSeg -- Unload a seglist previously loaded by [LoadSeg()](../Includes_and_Autodocs_3._guide/node0185.html)

    SYNOPSIS
	success = UnLoadSeg( seglist )
	D0		       D1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) UnLoadSeg(BPTR)

    FUNCTION
	Unload a seglist loaded by [LoadSeg()](../Includes_and_Autodocs_3._guide/node0185.html).  'seglist' may be zero.
	Overlaid segments will have all needed cleanup done, including
	closing files.

    INPUTS
	seglist - BCPL pointer to a segment identifier

    RESULTS
	success - returns 0 if a NULL seglist was passed or if it failed
		  to close an overlay file.  NOTE: this function returned
		  a random value before V36!

    SEE ALSO
	[LoadSeg()](../Includes_and_Autodocs_3._guide/node0185.html), [InternalLoadSeg()](../Includes_and_Autodocs_3._guide/node0180.html), [InternalUnLoadSeg()](../Includes_and_Autodocs_3._guide/node0181.html)

