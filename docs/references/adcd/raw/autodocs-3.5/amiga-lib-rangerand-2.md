# amiga.lib/RangeRand



   NAME
	RangeRand - generate a random number within a specific integer range

   SYNOPSIS
	number = RangeRand(maxValue);

	[UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) RangeRand(UWORD);

   FUNCTION
	RangeRand() accepts a value from 0 to 65535, and returns a value
	within that range.

	maxValue is passed on stack as a 32-bit integer but used as though
	it is only a 16-bit integer. Variable named RangeSeed is available
	beginning with V33 that contains the global seed value passed from
	call to call and thus can be changed in a program by declaring:

	  extern ULONG RangeSeed;

   INPUTS
	maxValue - the returned random number will be in the range
	           [0..maxValue-1]

   RESULT
	number - pseudo random number in the range of [0..maxValue-1].

   SEE ALSO
	[FastRand()](../Includes_and_Autodocs_3._guide/node003C.html)

