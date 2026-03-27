---
title: graphics.library/ScalerDiv
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-scalerdiv-2
functions: []
libraries: []
---

# graphics.library/ScalerDiv

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ScalerDiv -- Get the scaling result that [BitMapScale](autodocs-3.5/graphics-library-bitmapscale-2.md) would. (V36)

   SYNOPSIS
	result = ScalerDiv(factor, numerator, denominator)
	D0                 D0      D1         D2

	[UWORD](autodocs-3.5/include-exec-types-h.md) ScalerDiv(UWORD, [UWORD](autodocs-3.5/include-exec-types-h.md), UWORD);

   FUNCTION
	Calculate the expression (factor*numerator/denominator) such
	that the result is the same as the width of the destination
	result of [BitMapScale](autodocs-3.5/graphics-library-bitmapscale-2.md) when the factor here is the width of
	the source, and the numerator and denominator are the
	XDestFactor and XSrcFactor for [BitMapScale](autodocs-3.5/graphics-library-bitmapscale-2.md).

   INPUTS
	factor                 - a number in the range 0..16383
	numerator, denominator - numbers in the range 1..16383

   RESULT
	this returns factor*numerator/denominator

