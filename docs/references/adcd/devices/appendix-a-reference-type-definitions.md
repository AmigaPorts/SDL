---
title: Appendix A. Reference / Type Definitions
manual: devices
chapter: devices
section: appendix-a-reference-type-definitions
functions: []
libraries: []
---

# Appendix A. Reference / Type Definitions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following C typedefs describe standard IFF structures.  Declarations
to use in practice will vary with the CPU and compiler.  For example,
68000 Lattice C produces efficient comparison code if we define ID as a
"LONG".  A macro "MakeID" builds these IDs at compile time.


```c
    /* Standard IFF types, expressed in 68000 Lattice C.    */

    typedef unsigned char UBYTE;    /*  8 bits unsigned     */
    typedef short WORD;             /* 16 bits signed       */
    typedef unsigned short UWORD;   /* 16 bits unsigned     */
    typedef long LONG;              /* 32 bits signed       */

    typedef char ID[4];             /* 4 chars in " " through "~" */

    typedef struct {
      ID    ckID;
      LONG  ckSize;                 /* sizeof(ckData)       */
      UBYTE ckData[/* ckSize */];
      } Chunk;


    /* ID typedef and builder for 68000 Lattice C. */
    typedef LONG ID;                /* 4 chars in " " through "~"   */

    #define MakeID(a,b,c,d) ( (a)<<24 | (b)<<16 | (c)<<8 | (d) )

    /* Globally reserved IDs. */
    #define ID_FORM   MakeID('F','O','R','M')
    #define ID_LIST   MakeID('L','I','S','T')
    #define ID_PROP   MakeID('P','R','O','P')
    #define ID_CAT    MakeID('C','A','T',' ')
    #define ID_FILLER MakeID(' ',' ',' ',' ')
```
