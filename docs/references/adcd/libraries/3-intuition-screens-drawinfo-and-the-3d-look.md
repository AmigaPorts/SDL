---
title: 3 Intuition Screens / DrawInfo and the 3D Look
manual: libraries
chapter: libraries
section: 3-intuition-screens-drawinfo-and-the-3d-look
functions: []
libraries: []
---

# 3 Intuition Screens / DrawInfo and the 3D Look

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In Release 2, whenever a new screen is created, Intuition also creates an
auxiliary data structure called a [DrawInfo](autodocs-2.0/includes-intuition-screens-h.md).  The DrawInfo structure
provides information Intuition uses to support the new 3D look of Release
2 and  specifies graphical information for applications that use the
screen.  The information includes such items as aspect ratio (resolution),
font, number of colors and drawing pens.


struct DrawInfo
{
```c
    UWORD       dri_Version;    /* will be  DRI_VERSION                 */
    UWORD       dri_NumPens;    /* guaranteed to be >= numDrIPens       */
    UWORD       *dri_Pens;      /* pointer to pen array	                */

    struct TextFont     *dri_Font;  /* screen default font              */
    UWORD       dri_Depth;          /* (initial) depth of screen bitmap */

    struct {    /* from DisplayInfo database for initial display mode   */
```
	UWORD   X;
	UWORD   Y;
```c
    }           dri_Resolution;

    ULONG       dri_Flags;              /* defined below                */
    ULONG       dri_Reserved[7];        /* avoid recompilation ;^)      */
```
};


Before an application uses fields in the [DrawInfo](autodocs-2.0/includes-intuition-screens-h.md) structure, it should
check the version of the structure to ensure that all fields are
available.  If the field dri_Version is greater than or equal to the
constant DRI_VERSION that the application was compiled with, it can be
assured that all fields in DrawInfo that it knows about are being
supported by Intuition.

 [The Pen Specification in DrawInfo](libraries/3-drawinfo-and-the-3d-look-the-pen-specification-in-drawinfo.md) 
 [The Font Specification in DrawInfo](libraries/3-drawinfo-and-the-3d-look-the-font-specification-in.md) 
 [Cloning a Public Screen (Workbench)](libraries/3-drawinfo-and-the-3d-look-cloning-a-public-screen-workbench.md) 

