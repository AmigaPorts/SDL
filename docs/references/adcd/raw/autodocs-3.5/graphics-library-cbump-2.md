# graphics.library/CBump


   NAME
	CBump -  increment user copper list pointer (bump to next position in list).

   SYNOPSIS
	CBump( c )
	      a1

	void CBump( struct [UCopList](../Includes_and_Autodocs_3._guide/node05F3.html#line88) * );

   FUNCTION
	Increment pointer to space for next instruction in user copper list.

   INPUTS
	c - pointer to [UCopList](../Includes_and_Autodocs_3._guide/node05F3.html#line88) structure

   RESULTS
	User copper list pointer is incremented to next position.
	Pointer is repositioned to next user copperlist instruction block
	if the current block is full.

	    Note: CBump is usually invoked for the programmer as part of the
	          macro definitions [CWAIT](../Includes_and_Autodocs_3._guide/node02C9.html) or [CMOVE](../Includes_and_Autodocs_3._guide/node02C6.html).

   BUGS

   SEE ALSO
	CINIT() CWAIT() CMOVE() CEND() [graphics/copper.h](../Includes_and_Autodocs_3._guide/node05F3.html)

