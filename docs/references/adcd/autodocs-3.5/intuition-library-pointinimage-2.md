---
title: intuition.library/PointInImage
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-pointinimage-2
functions: []
libraries: []
---

# intuition.library/PointInImage

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME	
	PointInImage -- Tests whether an image "contains" a point. (V36)

   SYNOPSIS
	DoesContain = PointInImage( Point, [Image](autodocs-3.5/include-intuition-intuition-h.md) )
	D0	  		    D0     A0

	[BOOL](autodocs-3.5/include-exec-types-h.md) PointInImage( struct Point, struct [Image](autodocs-3.5/include-intuition-intuition-h.md) * );

   FUNCTION
	Tests whether a point is properly contained in an image.
	The intention of this is to provide custom gadgets a means
	to delegate "image mask" processing to the [Image](autodocs-3.5/include-intuition-intuition-h.md), where
	it belongs (superseding things like BOOLMASK).  After all,
	a rounded rect image with a drop shadow knows more about
	what points are inside it than anybody else should.

	For traditional Intuition Images, this routine checks if
	the point is in the [Image](autodocs-3.5/include-intuition-intuition-h.md) box (LeftEdge/RightEdge/Width/Height).

   INPUTS
 	Point	- Two words, X/Y packed into a [LONG](autodocs-3.5/include-exec-types-h.md), with high word
		containing 'X'.  This is what you get if you pass
		a Point structure (not a pointer!) using common
		C language parameter conventions.
	[Image](autodocs-3.5/include-intuition-intuition-h.md) - a pointer to a standard or custom [Image](autodocs-3.5/include-intuition-intuition-h.md) data object.
	    NOTE: If 'Image' is NULL, this function returns TRUE.

   RESULT
 	DoesContain - Boolean result of the test.

   EXAMPLE


   NOTES


   BUGS
	Only applies to the first image, does not follow NextImage
	linked list.  This might be preferred.

   SEE ALSO

