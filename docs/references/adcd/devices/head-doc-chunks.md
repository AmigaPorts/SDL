---
title: HEAD.doc / CHUNKS
manual: devices
chapter: devices
section: head-doc-chunks
functions: []
libraries: []
---

# HEAD.doc / CHUNKS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

CHUNK ID:  NEST

This chunk consists of only of a word (two byte) value that gives the new
current nesting level of the outline.  The initial nesting level
(outermost level) is zero.  It is necessary to include a NEST chunk only
when the nesting level changes.  Valid changes to the nesting level are
either to decrease the current value by any amount (with a minimum of 0)
or to increase it by one (and not more than one).

CHUNK ID:  TEXT

This chunk is the actual text of a heading.  Each heading has a TEXT chunk
(even if empty).  The text is not NULL terminated - the chunk size gives
the length of the heading text.

CHUNK ID: FSCC

This chunk gives the Font/Style/Color changes in the heading from the most
recent TEXT chunk.  It should occur immediately after the TEXT chunk it
modifies.  The format is identical to the FSCC chunk for the IFF form type
'WORD' (for compatibility), except that only the 'Location' and 'Style'
values are used (i.e., there can be currently only be style changes in an
outline heading).  The structure definition is:


```c
    typedef struct {
       UWORD   Location;   /* Char location of change */
       UBYTE   FontNum;    /* Ignored */
       UBYTE   Style;      /* Amiga style bits */
       UBYTE   MiscStyle;  /* Ignored */
       UBYTE   Color;      /* Ignored */
       UWORD   pad;        /* Ignored */
    } FSCChange;
```
The actual chunk consists of an array of these structures, one entry for
each Style change in the heading text.

