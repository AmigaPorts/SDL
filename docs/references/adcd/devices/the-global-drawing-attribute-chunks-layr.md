---
title: The Global Drawing Attribute Chunks / LAYR
manual: devices
chapter: devices
section: the-global-drawing-attribute-chunks-layr
functions: []
libraries: []
---

# The Global Drawing Attribute Chunks / LAYR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

LAYR (0x4C415952)   	/* Define a layer */

A DR2D project is broken up into one or more layers.  Each DR2D object is
in one of these layers.  Layers provide several useful features. Any
particular layer can be ``turned off'', so that the objects in the layer
are not displayed.  This eliminates the unnecessary display of objects not
currently needed on the screen.  Also, the user can lock a layer to
protect the layer's objects from accidental changes.

	struct LAYRstruct {
	    ULONG    ID;
	    ULONG    Size;
	    USHORT   LayerID;		   /* ID of the layer */
	    char     LayerName[16];	   /* Null terminated and padded */
	    UBYTE    Flags;		   /* Flags, from LF_*, below */
	    UBYTE    Pad0;		   /* Always 0 */
	};

LayerID is the number assigned to this layer.  As the field's name
indicates, LayerName[] is the NULL terminated name of the layer. Flags is
a bit field who's bits are set according to the #defines below:

	#define LF_ACTIVE     	0x01  	/* Active for editing */
	#define LF_DISPLAYED  	0x02  	/* Displayed on the screen */

If the LF_ACTIVE bit is set, this layer is unlocked.  A set LF_DISPLAYED
bit indicates that this layer is currently visible on the screen.  A
cleared LF_DISPLAYED bit implies that LF_ACTIVE is not set. The reason for
this is to keep the user from accidentally editing layers that are
invisible.

