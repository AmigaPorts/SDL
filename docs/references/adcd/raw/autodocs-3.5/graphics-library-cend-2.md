# graphics.library/CEND


   NAME
	CEND -- Terminate user copper list.

   SYNOPSIS
	CEND( c )

	struct [UCopList](../Includes_and_Autodocs_3._guide/node05F3.html#line88) *c;

   FUNCTION
	Add instruction to terminate user copper list.

   INPUTS
	c - pointer to [UCopList](../Includes_and_Autodocs_3._guide/node05F3.html#line88) structure

   RESULTS
	This is actually a macro that calls the macro CWAIT(c,10000,255)
	10000 is a magical number that the graphics.library uses.
	I hope display technology doesn't catch up too fast!

   BUGS

   SEE ALSO
	CINIT() CWAIT() CMOVE() [graphics/copper.h](../Includes_and_Autodocs_3._guide/node05F3.html)

