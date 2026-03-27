---
title: I-7/FontReq.c
manual: amiga-mail
chapter: amiga-mail
section: i-7-fontreq-c
functions: []
libraries: []
---

# I-7/FontReq.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* fontreq.c - Execute me to compile me with SAS/C 6.56
sc DATA=NEAR NMINC STRMERGE STREQ NOSTKCHK SAVEDS IGNORE=73 fontreq.c
slink FROM LIB:c.o,fontreq.o TO fontreq LIBRARY LIB:sc.lib,LIB:amiga.lib
quit
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


#include <clib/asl_protos.h>
#include <clib/exec_protos.h>
#include <clib/alib_stdio_protos.h>
#include <exec/libraries.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif


UBYTE *vers = "\0$VER: fontreq 1.0";

void main(void);
struct Library *AslBase, *UtilityBase;

/* The replacement strings for the "mode" cycle gadget.  The
** first string is the cycle gadget's label.  The other strings
** are the actual strings that will appear on the cycle gadget.
*/
UBYTE *modelist[] =
{
    "RKM Modes",
    "Mode 0",
    "Mode 1",
    "Mode 2",
    "Mode 3",
    "Mode 4",
    "Mode 5",
    "Mode 6",
    "Mode 7",
    "Mode 8",
    "Mode 9",
    NULL
};


void main()
{

```c
    struct FontRequester *fr;

    if (AslBase = OpenLibrary("asl.library", 36L))
    {

        if (fr = (struct FontRequester *)
            AllocAslRequestTags(ASL_FontRequest,
                /* tell the requester to use my custom mode names */
                ASL_ModeList, modelist,

                /* Supply initial values for requester */
                ASL_FontName, (ULONG)"topaz.font",
                ASL_FontHeight, 11L,
                ASL_FontStyles, FSF_BOLD | FSF_ITALIC,
                ASL_FrontPen,  0x00L,
                ASL_BackPen,   0x01L,

                /* Only display font sizes between 8 and
                ** 14, inclusive. */
                ASL_MinHeight, 8L,
                ASL_MaxHeight, 14L,

                /* Give us all the gadgetry, but only display
                ** fixed width fonts */
                ASL_FuncFlags, FONF_FRONTCOLOR | FONF_BACKCOLOR |
                    FONF_DRAWMODE | FONF_STYLES | FONF_FIXEDWIDTH,
                TAG_DONE))
        {
            /* application code here... */


            /* Pop up the requester */
            if (AslRequest(fr, 0L))
            {
                /* The user selected something,  report their choice */
                printf("%s\n  YSize = %d  Style = 0x%x   Flags = 0x%x\n"
                       "  FPen = 0x%x   BPen = 0x%x   DrawMode = 0x%x\n",
                               fr->fo_Attr.ta_Name,
                               fr->fo_Attr.ta_YSize,
                               fr->fo_Attr.ta_Style,
                               fr->fo_Attr.ta_Flags,
                               fr->fo_FrontPen,
                               fr->fo_BackPen,
                               fr->fo_DrawMode);
            }
            else
                /* The user cancelled the requester, or
                ** some kind of error occured preventing
                ** the requester from opening. */
                printf("Request Cancelled\n");

            /* more application code here ...*/

            FreeAslRequest(fr);
        }
        CloseLibrary(AslBase);
    }
```
}

