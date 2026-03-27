---
title: I-7/FileHook.c
manual: amiga-mail
chapter: amiga-mail
section: i-7-filehook-c
functions: [AllocFileRequest, MatchPattern, ParsePattern]
libraries: [asl.library, dos.library]
---

# I-7/FileHook.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* filehook.c - Execute me to compile me with SAS/C 6.56
sc DATA=NEAR NMINC STRMERGE STREQ NOSTKCHK SAVEDS IGNORE=73 filehook.c
slink FROM LIB:c.o,filehook.o TO filehook LIBRARY LIB:sc.lib,LIB:amiga.lib
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
#include <clib/dos_protos.h>
#include <clib/intuition_protos.h>
#include <clib/alib_stdio_protos.h>
#include <dos/dosasl.h>
#include <intuition/intuition.h>
#include <exec/libraries.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

#define DESTPATLENGTH 20

UBYTE *vers = "\0$VER: filehook 1.0";

void main(void);

struct Library *AslBase;
struct IntuitionBase *IntuitionBase;
struct Window *window;

CPTR HookFunc();

/* this is the pattern matching string that the hook function uses */
UBYTE *sourcepattern = "(#?.info)";
UBYTE pat[DESTPATLENGTH];


void main()
{

```c
    struct FileRequester *fr;

    /* This is a dos.library function that turns a pattern matching
    ** string into something the DOS pattern matching functions
    ** can understand.
    */
    ParsePattern(sourcepattern, pat, DESTPATLENGTH);

    if (AslBase = OpenLibrary("asl.library", 36L))
    {
        if (IntuitionBase = (struct IntuitionBase *)
                    OpenLibrary("intuition.library", 36L))
        {
            /* open a window that gets ACTIVEWINDOW events */
            if (window = (struct Window *)OpenWindowTags(NULL,
                    WA_Title, "ASL Hook Function Example",
                    WA_IDCMP, IDCMP_ACTIVEWINDOW,
                    WA_Flags, WINDOWDEPTH,
                    TAG_END))
            {
                if (fr = AllocFileRequest())
                {
                    /* application body here... */


                    if (AslRequestTags(fr,
                        ASL_Window, window,
                        ASL_TopEdge, 0L,
                        ASL_Height, 200L,
                        ASL_Hail, (ULONG)"Pick an icon to save",
                        ASL_HookFunc, (ULONG)HookFunc,
                        ASL_FuncFlags, FILF_DOWILDFUNC | FILF_DOMSGFUNC | FILF_SAVE,
                        ASL_OKText, (ULONG)"Save",
                        TAG_DONE))
                    {
                        printf("You picked %s%s\n", fr->rf_Dir, fr->rf_File);
                    }

                    /* more application body here */

                    FreeFileRequest(fr);
                }
                CloseWindow(window);
            }
            CloseLibrary(IntuitionBase);
        }
        CloseLibrary(AslBase);
    }
```
}


CPTR HookFunc(LONG type, CPTR obj, struct FileRequester *fr)
{
```c
    static BOOL returnvalue;
    switch(type)
    {
        case FILF_DOMSGFUNC:
        /* We got a message meant for the window */
            printf("You activated the window\n");
            return(obj);
            break;
        case FILF_DOWILDFUNC:
        /* We got an AnchorPath structure, should
        ** the requester display this file? */

            /* MatchPattern() is a dos.library function that
            ** compares a matching pattern (parsed by the
            ** ParsePattern() DOS function) to a string and
            ** returns true if they match. */
            returnvalue = MatchPattern(pat,
                    ((struct AnchorPath *)obj)->ap_Info.fib_FileName);

            /* we have to negate MatchPattern()'s return value
            ** because the file requester expects a zero for
            ** a match not a TRUE value */
            return( (CPTR)(! returnvalue) );
            break;
    }
```
}

---

## See Also

- [AllocFileRequest — asl.library](../autodocs/asl.library.md#allocfilerequest)
- [MatchPattern — dos.library](../autodocs/dos.library.md#matchpattern)
- [ParsePattern — dos.library](../autodocs/dos.library.md#parsepattern)
