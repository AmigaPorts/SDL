---
title: The Object Chunks / GRUP
manual: devices
chapter: devices
section: the-object-chunks-grup
functions: []
libraries: []
---

# The Object Chunks / GRUP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

GRUP (0x47525550)   	/* Group */

The GRUP chunk combines several DR2D objects into one.  This chunk is only
valid inside nested DR2D FORMs, and must be the first chunk in the FORM.


```c
    struct GROUPstruct {
        ULONG       ID;
        ULONG       Size;
        USHORT      NumObjs;
    };
```
The NumObjs field contains the number of objects contained in this group.
Note that the layer of the GRUP FORM overrides the layer of objects within
the GRUP.  The following example illustrates the layout of the GRUP (and
FILL) chunk.


```c
    FORM { DR2D              /* Top-level drawing... */
             DRHD { ... }    /* Confirmed by presence of DRHD chunk */
             CMAP { ... }    /* Various other things... */
             FONS { ... }
             FORM { DR2D             /* A nested form... */
                     FILL { 1 }      /* Ah!  The fill-pattern table */
                     CPLY { ... }    /* with only 1 object */
             }
             FORM { DR2D             /* Yet another nested form */
                     GRUP { ..., 3 } /* Ah! A group of 3 objects */
                     TEXT { ... }
                     CPLY { ... }
                     OPLY { ... }
             }
             FORM { DR2D             /* Still another nested form */
                     GRUP { ..., 2 } /* A GRUP with 2 objects */
                     OPLY { ... }
                     TEXT { ... }
             }
     }
```
