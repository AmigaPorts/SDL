# iffparse.library/GoodType



   NAME
	GoodType -- test if a type follows the IFF 85 specification. (V36)

   SYNOPSIS
	isok = GoodType(type)
	D0              D0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) GoodType(LONG);

   FUNCTION
	Tests the given longword type identifier to see if it meets all the
	EA IFF 85 specifications for a FORM type (requirements for a FORM
	type are more stringent than those for a simple chunk ID). If it
	complies, GoodType() returns non-zero, otherwise 0.

   INPUTS
	type - potential 32 bit format type identifier.

   RESULT
	isok - non-zero if this is a valid type id, 0 otherwise.

   SEE ALSO
	[GoodID()](../Includes_and_Autodocs_3._guide/node0368.html)

