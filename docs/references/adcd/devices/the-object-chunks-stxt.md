---
title: The Object Chunks / STXT
manual: devices
chapter: devices
section: the-object-chunks-stxt
functions: []
libraries: []
---

# The Object Chunks / STXT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

STXT (0x53545854)   		/* Simple text */

The STXT chunk contains a text string along with some information on how
and where to render the text.


```c
    struct STXTstruct {
        ULONG       ID;
        ULONG       Size;
        UBYTE       Pad0;           /* Always 0 (for future expansion) */
        UBYTE       WhichFont;      /* Which font to use */
        IEEE        CharW, CharH,   /* W/H of an individual char */
                    BaseX, BaseY,   /* Start of baseline */
                    Rotation;       /* Angle of text (in degrees) */
        USHORT      NumChars;
        char        TextChars[NumChars];
    };
```
The text string is in the character array, TextChars[].  The ID of the
font used to render the text is WhichFont.  The font's ID is set in a FONS
chunk.  The starting point of the baseline of the text is (BaseX, BaseY).
This is the point around which the text is rotated.  If the Rotation field
is zero (degrees), the text's baseline will originate at (BaseX, BaseY)
and move to the right.  CharW and CharH are used to scale the text after
rotation.  CharW is the average character width and CharH is the average
character height.  The CharW/H fields are comparable to an X and Y font
size.

