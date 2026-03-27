# graphics.library/CMOVE



   NAME
	CMOVE -- append copper move instruction to user copper list.

   SYNOPSIS
	CMOVE( c , a , v )

	CMove( c , a , v )
	      a1  d0  d1
	CBump( c )
	      a1

	void CMove( struct [UCopList](../Includes_and_Autodocs_3._guide/node05F3.html#line88) *, void *, WORD );

   FUNCTION
	Add instruction to move value v to hardware register a.

   INPUTS
	c - pointer to [UCopList](../Includes_and_Autodocs_3._guide/node05F3.html#line88) structure
	a - hardware register
	v - 16 bit value to be written

   RESULTS
	This is actually a macro that calls CMove(c,&a,v)
	and then calls CBump(c) to bump the local pointer
	to the next instruction. Watch out for macro side affects.

   BUGS

   SEE ALSO
	CINIT() CWAIT() CEND() [graphics/copper.h](../Includes_and_Autodocs_3._guide/node05F3.html)

