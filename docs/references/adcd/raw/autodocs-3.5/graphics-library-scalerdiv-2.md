# graphics.library/ScalerDiv



   NAME
	ScalerDiv -- Get the scaling result that [BitMapScale](../Includes_and_Autodocs_3._guide/node02B1.html) would. (V36)

   SYNOPSIS
	result = ScalerDiv(factor, numerator, denominator)
	D0                 D0      D1         D2

	[UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) ScalerDiv(UWORD, [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), UWORD);

   FUNCTION
	Calculate the expression (factor*numerator/denominator) such
	that the result is the same as the width of the destination
	result of [BitMapScale](../Includes_and_Autodocs_3._guide/node02B1.html) when the factor here is the width of
	the source, and the numerator and denominator are the
	XDestFactor and XSrcFactor for [BitMapScale](../Includes_and_Autodocs_3._guide/node02B1.html).

   INPUTS
	factor                 - a number in the range 0..16383
	numerator, denominator - numbers in the range 1..16383

   RESULT
	this returns factor*numerator/denominator

