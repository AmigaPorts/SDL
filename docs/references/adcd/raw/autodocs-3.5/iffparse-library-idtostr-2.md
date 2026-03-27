# iffparse.library/IDtoStr



   NAME
	IDtoStr -- convert a longword identifier to a null-terminated string.
	           (V36)

   SYNOPSIS
	str = IDtoStr(id, buf);
	D0            D0  A0

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) IDtoStr(LONG, STRPTR);

   FUNCTION
	Writes the ASCII equivalent of the given longword ID into buf as a
	null-terminated string.

   INPUTS
	id - longword ID.
	buf - character buffer to accept string (at least 5 chars).

   RESULT
	str - the value of 'buf'.

