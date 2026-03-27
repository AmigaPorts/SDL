---
title: The Global Drawing Attribute Chunks / DRHD
manual: devices
chapter: devices
section: the-global-drawing-attribute-chunks-drhd
functions: []
libraries: []
---

# The Global Drawing Attribute Chunks / DRHD

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

DRHD (0x44524844) 	/* Drawing header */

The DRHD chunk contains the upper left and lower right extremes of the
document in (X, Y) coordinates.  This chunk is required and should only
appear once in a document in the outermost layer of the DR2D file (DR2Ds
can be nested).

	struct DRHDstruct {
	    ULONG	ID;
	    ULONG	Size;    		/* Always 16 */
	    IEEE	XLeft, YTop,
			XRight, YBot;
	};

The point (XLeft,YTop) is the upper left corner of the project and the
point (XRight,YBot) is its lower right corner.  These coordinates not only
supply the size and position of the document in a coordinate system, they
also supply the project's orientation.  If XLeft < XRight, the X-axis
increases toward the right.  If YTop < YBot, the Y-axis increases toward
the bottom.  Other combinations are possible; for example in Cartesian
coordinates, XLeft would be less than XRight but YTop would be greater
than YBot.

