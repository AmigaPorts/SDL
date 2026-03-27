---
title: The Object Attribute Chunks / XTRN
manual: devices
chapter: devices
section: the-object-attribute-chunks-xtrn
functions: []
libraries: []
---

# The Object Attribute Chunks / XTRN

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

XTRN (0x5854524E)   	/* Externally controlled object */

The XTRN chunk was created primarily to allow ProVector to link DR2D
objects to ARexx functions.


```c
    struct XTRNstruct {
        ULONG   ID;
        ULONG   Size;
        short   ApplCallBacks;            /* From #defines, below */
        short   ApplNameLength;
        char    ApplName[ApplNameLength]; /* Name of ARexx func to call */
    };
```
ApplName[] contains the name of the ARexx script ProVector calls when the
user manipulates the object in some way.  The ApplCallBacks field
specifies the particular action that triggers calling the ARexx script
according to the #defines listed below.


```c
    /* Flags for ARexx script callbacks */
    #define    X_CLONE     0x0001    /* The object has been cloned */
    #define    X_MOVE      0x0002    /* The object has been moved */
    #define    X_ROTATE    0x0004    /* The object has been rotated */
    #define    X_RESIZE    0x0008    /* The object has been resized */
    #define    X_CHANGE    0x0010    /* An attribute (see ATTR) of the
                                        object has changed */
    #define    X_DELETE    0x0020    /* The object has been deleted */
    #define    X_CUT       0x0040    /* The object has been deleted, but
                                        stored in the clipboard */
    #define    X_COPY      0x0080    /* The object has been copied to the
                                        clipboard */
    #define    X_UNGROUP   0x0100    /* The object has been ungrouped */
```
For example, given the XTRN object:


```c
    FORM xxxx DR2D {
            XTRN xxxx { X_RESIZE | X_MOVE, 10, "Dimension" }
            ATTR xxxx { 0, 0, 1, 0, 0, 0, 0.0 }
            FORM xxxx DR2D {
                    GRUP xxxx { 2 }
                    STXT xxxx { 0, 0.5, 1.0, 6.0, 5.0, 0.0, 4, "3.0" }
                    OPLY xxxx { 2, { 5.5, 5.5, 8.5, 5.5 } }
            }
    }
```
ProVector would call the ARexx script named Dimension if the user resized
or moved this object.  What exactly ProVector sends depends upon what the
user does to the object.  The following list shows what string(s)
ProVector sends according to which flag(s) are set.  The parameters are
described below.


    X_CLONE     ``appl CLONE objID dx dy''
    X_MOVE      ``appl MOVE objID dx dy''
    X_ROTATE    ``appl ROTATE objID cx cy angle''
    X_RESIZE    ``appl RESIZE objID cx cy sx sy''
    X_CHANGE    ``appl CHANGE objID et ev ft fv ew jt fn''
    X_DELETE    ``appl DELETE objID''
    X_CUT       ``appl CUT objID''
    X_COPY      ``appl COPY objID''
    X_UNGROUP   ``appl UNGROUP objID''
 where:

```c
    appl is the name of the ARexx script
    CLONE, MOVE, ROTATE, RESIZE, etc. are literal strings
    objID is the object ID that ProVector assigns to this object
    (dx, dy) is the position offset of the CLONE or MOVE
    (cx, cy) is the point around which the object is rotated or resized
    angle is the angle (in degrees) the object is rotated
    sx and sy are the scaling factors in the horizontal and
      vertical directions, respectively.
    et is the edge type (the dash pattern index)
    ev is the edge value (the edge color index)
    ft is the fill type
    fv is the fill index
    ew is the edge weight
    jt is the join type
    fn is the font name
```
The X_CHANGE message reflects changes to the attributes found in the ATTR
chunk.

If the user resized the XTRN object shown above by factor of 2, ProVector
would call the ARexx script Dimension like this:


    Dimension RESIZE 1985427 7.0 4.75 2.0 2.0
