---
title: lib_examples/animtools.h
manual: libraries
chapter: libraries
section: lib-examples-animtools-h
functions: []
libraries: []
---

# lib_examples/animtools.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* animtools.h */
#ifndef GELTOOLS_H
#define GELTOOLS_H

/*
** These data structures are used by the functions in animtools.c to
** allow for an easier interface to the animation system.
*/

/* Data structure to hold information for a new VSprite.                */
typedef struct newVSprite {

```c
        WORD           *nvs_Image;      /* image data for the vsprite   */
        WORD           *nvs_ColorSet;   /* color array for the vsprite  */
        SHORT           nvs_WordWidth;  /* width in words               */
        SHORT           nvs_LineHeight; /* height in lines              */
        SHORT           nvs_ImageDepth; /* depth of the image           */
        SHORT           nvs_X;          /* initial x position           */
        SHORT           nvs_Y;          /* initial y position           */
        SHORT           nvs_Flags;      /* vsprite flags                */
        USHORT          nvs_HitMask;    /* Hit mask.                    */
        USHORT          nvs_MeMask;     /* Me mask.                     */
        } NEWVSPRITE;
```
/* Data structure to hold information for a new Bob.                */
typedef struct newBob {

```c
        WORD       *nb_Image;       /* image data for the bob       */
        SHORT       nb_WordWidth;   /* width in words               */
        SHORT       nb_LineHeight;  /* height in lines              */
        SHORT       nb_ImageDepth;  /* depth of the image           */
        SHORT       nb_PlanePick;   /* planes that get image data   */
        SHORT       nb_PlaneOnOff;  /* unused planes to turn on     */
        SHORT       nb_BFlags;      /* bob flags                    */
        SHORT       nb_DBuf;        /* 1=double buf, 0=not          */
        SHORT       nb_RasDepth;    /* depth of the raster          */
        SHORT       nb_X;           /* initial x position           */
        SHORT       nb_Y;           /* initial y position           */
        USHORT      nb_HitMask;     /* Hit mask.                    */
        USHORT      nb_MeMask;      /* Me mask.                     */
        } NEWBOB ;
```
/* Data structure to hold information for a new animation component.       */
typedef struct newAnimComp {

```c
        WORD  (*nac_Routine)(); /* routine called when Comp is displayed.   */
        SHORT   nac_Xt;         /* initial delta offset position.           */
        SHORT   nac_Yt;         /* initial delta offset position.           */
        SHORT   nac_Time;       /* Initial Timer value.                     */
        SHORT   nac_CFlags;     /* Flags for the Component.                 */
        } NEWANIMCOMP;
```
/* Data structure to hold information for a new animation sequence.         */
typedef struct newAnimSeq {

```c
        struct AnimOb  *nas_HeadOb; /* common Head of Object.               */
        WORD   *nas_Images;         /* array of Comp image data             */
        SHORT  *nas_Xt;             /* arrays of initial offsets.           */
        SHORT  *nas_Yt;             /* arrays of initial offsets.           */
        SHORT  *nas_Times;          /* array of Initial Timer value.        */
        WORD (**nas_Routines)();    /* Array of fns called when comp drawn  */
        SHORT   nas_CFlags;         /* Flags for the Component.             */
        SHORT   nas_Count;          /* Num Comps in seq (= arrays size)     */
        SHORT   nas_SingleImage;    /* one (or count) images.               */
        } NEWANIMSEQ;
```
#define INTUITIONNAME "intuition.library" /* intuitionbase.h does not define a library name. */

#include "animtools_proto.h"              /* Include Prototyping. */
#endif


/* animtools_proto.h */
#include        <clib/dos_protos.h>
#include        <clib/exec_protos.h>
#include        <clib/graphics_protos.h>
#include        <clib/intuition_protos.h>

struct GelsInfo *setupGelSys(struct RastPort *rPort, BYTE reserved);
VOID            cleanupGelSys(struct GelsInfo *gInfo, struct RastPort *rPort);
struct VSprite  *makeVSprite(NEWVSPRITE *nVSprite);
struct Bob      *makeBob(NEWBOB *nBob);
struct AnimComp *makeComp(NEWBOB *nBob, NEWANIMCOMP *nAnimComp);
struct AnimComp *makeSeq(NEWBOB *nBob, NEWANIMSEQ *nAnimSeq);
VOID            freeVSprite(struct VSprite *vsprite);
VOID            freeBob(struct Bob *bob, LONG rasdepth);
VOID            freeComp(struct AnimComp *myComp, LONG rasdepth);
VOID            freeSeq(struct AnimComp *headComp, LONG rasdepth);
VOID            freeOb(struct AnimOb *headOb, LONG rasdepth);

