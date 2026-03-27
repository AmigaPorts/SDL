# graphics.library/Animate



   NAME
	Animate  --  Processes every [AnimOb](../Includes_and_Autodocs_3._guide/node05D4.html#line203) in the current animation list.

   SYNOPSIS
	Animate(anKey, rp)
	        A0     A1

	void Animate(struct [AnimOb](../Includes_and_Autodocs_3._guide/node05D4.html#line203) **, struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *);

   FUNCTION
	For every [AnimOb](../Includes_and_Autodocs_3._guide/node05D4.html#line203) in the list
	    - update its location and velocities
	    - call the AnimOb's special routine if one is supplied
	    - for each component of the [AnimOb](../Includes_and_Autodocs_3._guide/node05D4.html#line203)
	        - if this sequence times out, switch to the new one
	        - call this component's special routine if one is supplied
	        - set the sequence's VSprite's y,x coordinates based
	          on whatever these routines cause

   INPUTS
	ankey = address of the variable that points to the head [AnimOb](../Includes_and_Autodocs_3._guide/node05D4.html#line203)
	rp    = pointer to the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure

   RESULT

   BUGS

   SEE ALSO
	[AddAnimOb()](../Includes_and_Autodocs_3._guide/node029C.html) [graphics/gels.h](../Includes_and_Autodocs_3._guide/node05D4.html) [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

