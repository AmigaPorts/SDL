# amiga.lib/FastRand



   NAME
	FastRand - quickly generate a somewhat random integer

   SYNOPSIS
	number = FastRand(seed);

	ULONG FastRand(ULONG);

   FUNCTION
	Seed value is taken from stack, shifted left one position,
	exclusive-or'ed with hex value $1D872B41 and returned.

   INPUTS
	seed - a 32-bit integer

   RESULT
	number - new random seed, a 32-bit value

   SEE ALSO
	[RangeRand()](../Includes_and_Autodocs_3._guide/node0049.html)

