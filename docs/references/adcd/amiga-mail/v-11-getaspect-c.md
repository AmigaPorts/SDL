---
title: V-11/getaspect.c
manual: amiga-mail
chapter: amiga-mail
section: v-11-getaspect-c
functions: []
libraries: []
---

# V-11/getaspect.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* getaspect.c - Execute me to compile me with SAS/C 6.56
sc DATA=NEAR NMINC STRMERGE STREQ NOSTKCHK SAVEDS IGNORE=73 getaspect.c
slink FROM LIB:c.o,getaspect.o TO getaspect LIBRARY LIB:sc.lib,LIB:amiga.lib
quit

Gets X/Y pixel aspect of a screen's ViewPort
*/
/*
Copyright (c) 1991-1999 Amiga, Inc.

This example is provided in electronic form by Amiga, Inc.
for use with the Amiga Mail Volume II technical publication.
Amiga Mail Volume II contains additional information on the correct
usage of the techniques and operating system functions presented in
these examples.  The source and executable code of these examples may
only be distributed in free electronic form, via bulletin board or
as part of a fully non-commercial and freely redistributable
diskette.  Both the source and executable code (including comments)
must be included, without modification, in any copy.  This example
may not be published in printed form or distributed with any
commercial product. However, the programming techniques and support
routines set forth in these examples may be used in the development
of original executable software products for Amiga
computers.

All other rights reserved.

This example is provided "as-is" and is subject to change; no
warranties are made.  All use is at your own risk. No liability or
responsibility is assumed.
*/

#include <exec/types.h>
#include <exec/memory.h>
#include <libraries/dos.h>
#include <intuition/intuition.h>
#include <intuition/intuitionbase.h>
#include <graphics/displayinfo.h>
#include <graphics/gfxbase.h>

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/intuition_protos.h>
#include <clib/graphics_protos.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif


#define MINARGS 1

UBYTE *vers = "\0$VER: getaspect 37.1";
UBYTE *Copyright =
  "getaspect v37.1\nCopyright (c) 1990-1999 Amiga, Inc.  All Rights Reserved";
UBYTE *usage = "Usage: getaspect";

void bye(UBYTE *s, int e);
void cleanup(void);

struct Library *IntuitionBase;
struct Library *GfxBase;

void main(int argc, char **argv)


```c
    {
    struct Screen *first;
    struct ViewPort *vp;
    struct DisplayInfo DI;
    ULONG  modeid;
    UBYTE  xAspect, yAspect;

    if(((argc)&&(argc<MINARGS))||(argv[argc-1][0]=='?'))
    {
    printf("%s\n%s\n",Copyright,usage);
    bye("",RETURN_OK);
    }

    /* We will check later to see if we can call V36 functions */
    IntuitionBase = OpenLibrary("intuition.library",34);
    GfxBase = OpenLibrary("graphics.library",34);
    if((!IntuitionBase)||(!GfxBase))
    bye("Can't open intuition or graphics library",RETURN_FAIL);

    printf("Using front screen's ViewPort (for example purposes only):\n");

    first = ((struct IntuitionBase *)IntuitionBase)->FirstScreen;
    vp = &first->ViewPort;

    xAspect = 0;    /* So we can tell when we've got it */

    if(GfxBase->lib_Version >= 36)
    {
        modeid = GetVPModeID(vp);

        if(GetDisplayInfoData(NULL, (UBYTE *)&DI, sizeof(struct DisplayInfo),
        DTAG_DISP, modeid))
        {
        printf("Running 2.0,  ViewPort modeid is $%08lx\n",modeid);
        xAspect = DI.Resolution.x;
        yAspect = DI.Resolution.y;
        printf("Pixel  xAspect=%ld  yAspect=%ld\n",xAspect, yAspect);
        printf("PaletteRange is %ld\n",DI.PaletteRange);
        }
    }

    if(!xAspect)  /* pre-2.0 or GetDisplayInfoData failed */
    {
    modeid = vp->Modes;
    printf("Not running 2.0, ViewPort mode is $%04lx\n",modeid);
        /* default lores pixel ratio */
        xAspect = 44;
        yAspect = ((struct GfxBase *)GfxBase)->DisplayFlags & PAL  ? 44 : 52;
        if(modeid & HIRES)      xAspect = xAspect >> 1;
        if(modeid & LACE)       yAspect = yAspect >> 1;
    printf("Pixel  xAspect=%ld  yAspect=%ld\n",xAspect, yAspect);
        }

    bye("",RETURN_OK);
    }
```
void bye(UBYTE *s, int e)

```c
    {
    cleanup();
    exit(e);
    }
```
void cleanup()

```c
    {
    if(GfxBase) CloseLibrary(GfxBase);
    if(IntuitionBase)   CloseLibrary(IntuitionBase);
    }
```
