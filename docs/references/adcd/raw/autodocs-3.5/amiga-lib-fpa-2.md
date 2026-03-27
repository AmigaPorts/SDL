# amiga.lib/fpa



   NAME
	fpa - convert fast floating point into ASCII string equivalent

   SYNOPSIS
	exp = fpa(fnum, &string[0]);

   FUNCTION
	Accepts an FFP number and the address of the ASCII string where it's
	converted output is to be stored.  The number is converted to a NULL
	terminated ASCII string in and stored at the address provided.
	Additionally, the base ten (10) exponent in binary form is returned.

   INPUTS
	fnum	   - Motorola Fast Floating Point number
	&string[0] - address for output of converted ASCII character string
		     (16 bytes)

   RESULT
	&string[0] - converted ASCII character string
	exp	   - integer exponent value in binary form

   BUGS
	None

