# graphics.library/AddAnimOb



   NAME
	AddAnimOb  --  Add an [AnimOb](../Includes_and_Autodocs_3._guide/node05D4.html#line203) to the linked list of AnimObs.

   SYNOPSIS
	AddAnimOb(anOb, anKey, rp)
	          A0    A1     A2

	void AddAnimOb(struct [AnimOb](../Includes_and_Autodocs_3._guide/node05D4.html#line203) *,struct [AnimOb](../Includes_and_Autodocs_3._guide/node05D4.html#line203) **, struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *);

   FUNCTION
	Links this [AnimOb](../Includes_and_Autodocs_3._guide/node05D4.html#line203) into the current list pointed to by animKey.
	Initializes all the Timers of the AnimOb's components.
	Calls [AddBob](../Includes_and_Autodocs_3._guide/node029D.html) with each component's [Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138).
	rp->GelsInfo must point to an initialized [GelsInfo](../Includes_and_Autodocs_3._guide/node05D7.html#line38) structure.

   INPUTS
	anOb  = pointer to the [AnimOb](../Includes_and_Autodocs_3._guide/node05D4.html#line203) structure to be added to the list
	anKey = address of a pointer to the first [AnimOb](../Includes_and_Autodocs_3._guide/node05D4.html#line203) in the list
	        (anKey = NULL if there are no AnimObs in the list so far)
	rp    = pointer to a valid [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)

   RESULT

   BUGS

   SEE ALSO
	[Animate()](../Includes_and_Autodocs_3._guide/node02A6.html) [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html) [graphics/gels.h](../Includes_and_Autodocs_3._guide/node05D4.html)

