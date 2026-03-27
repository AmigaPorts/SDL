---
title: V-15/FTA.c
manual: amiga-mail
chapter: amiga-mail
section: v-15-fta-c
functions: []
libraries: []
---

# V-15/FTA.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* FTA.c - Execute me to compile me with SAS/C 6.56
sc NMINC STRMERGE STREQ NOSTKCHK SAVEDS IGNORE=73 FTA.c
slink FROM LIB:c.o,FTA.o TO FTA LIBRARY LIB:sc.lib,LIB:amiga.lib
quit

Sept. 17 1991 by John Orr

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
#include <intuition/intuition.h>
#include <graphics/text.h>
#include <graphics/gfx.h>
#include <libraries/diskfont.h>
#include <utility/tagitem.h>
#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/alib_stdio_protos.h>
#include <clib/intuition_protos.h>
#include <clib/graphics_protos.h>
#include <clib/diskfont_protos.h>
#include <clib/utility_protos.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }
#endif

#define MYXDPI (75L << 16)
#define MYYDPI (50L)

struct TTextAttr mytta = {
    "topaz.font",
    9,
    FSF_TAGGED,
    0L,
    NULL
};

struct TagItem tagitem[2];
struct TextFont *myfont;
ULONG dpivalue;

struct Library *UtilityBase, *DiskfontBase, *GfxBase;

void main(void)
{
```c
    tagitem[0].ti_Tag = TA_DeviceDPI;
    tagitem[0].ti_Data = MYXDPI | MYYDPI;
    tagitem[1].ti_Tag = TAG_END;


    if (DiskfontBase = OpenLibrary("diskfont.library", 36L))
    {
        if (UtilityBase = OpenLibrary("utility.library", 36L))
        {
            if (GfxBase = OpenLibrary("graphics.library", 36L))
            {
            	if (myfont = OpenDiskFont(&mytta))
                {
                    dpivalue = GetTagData(TA_DeviceDPI,
                                     0L,
                                     ((struct TextFontExtension *)(myfont->tf_Extension))->tfe_Tags);
                    if (dpivalue) printf("XDPI = %d    YDPI = %d\n",
                                    ((dpivalue & 0xFFFF0000)>>16),
                                    (dpivalue & 0x0000FFFF));
                    CloseFont(myfont);
                }
```
				CloseLibrary(GfxBase);
			}
```c
            CloseLibrary(UtilityBase);
        }
        CloseLibrary(DiskfontBase);
    }
```
}

