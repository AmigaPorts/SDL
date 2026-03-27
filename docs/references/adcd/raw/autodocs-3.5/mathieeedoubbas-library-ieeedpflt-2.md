# mathieeedoubbas.library/IEEEDPFlt



   NAME
	IEEEDPFlt -- convert integer to IEEE double precision number

   SYNOPSIS
	  x   = IEEEDPFlt(  y  );
	d0/d1		   d0

	double	x;
	long	y;

   FUNCTION
	Convert a signed 32 bit value to a double precision IEEE value
	and return it in d0/d1. No exceptions can occur with this
	function.

   INPUTS
	y -- 32 bit integer in d0

   RESULT
	x is a 64 bit double precision IEEE value

   BUGS

   SEE ALSO
	[IEEEDPFix()](../Includes_and_Autodocs_3._guide/node0483.html)

