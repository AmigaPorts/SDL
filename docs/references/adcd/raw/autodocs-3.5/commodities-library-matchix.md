# commodities.library/MatchIX



   NAME
	MatchIX -- see if an input event matches an initialized input
		   expression. (V38)

   SYNOPSIS
	match = MatchIX(event,ix);
	D0		A0    A1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) MatchIX(struct [InputEvent](../Includes_and_Autodocs_3._guide/node061A.html#line256) *,IX *);

   FUNCTION
	This function determines whether an input event matches an
	initialized input expression. Applications generally do not
	need to call this function as filter objects will normally provide
	all the event filtering needed. Nevertheless, MatchIX()
	can come in handy as it is the same function used to match an
	event to the various filter objects when an event makes its way
	through the input network.

   INPUTS
	event - the input event to match against the input expression
	ix - the input expression for the comparison

   RESULTS
	match - TRUE if the input event matches the input expression, or
		FALSE if not

   SEE ALSO
	[<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html), [ParseIX()](../Includes_and_Autodocs_3._guide/node00F3.html)

