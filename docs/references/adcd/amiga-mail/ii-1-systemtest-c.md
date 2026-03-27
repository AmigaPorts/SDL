---
title: II-1/SystemTest.c
manual: amiga-mail
chapter: amiga-mail
section: ii-1-systemtest-c
functions: [Input, Output]
libraries: [dos.library]
---

# II-1/SystemTest.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* SystemTest.c - Execute me to compile me with SAS/C 6.56
;   Demonstration of System(), AUTO CON, and custom screen CON
sc DATA=NEAR NMINC STRMERGE STREQ NOSTKCHK SAVEDS IGNORE=73 SystemTest.c
slink FROM LIB:c.o,SystemTest.o TO SystemTest LIBRARY LIB:sc.lib,LIB:amiga.lib
quit
*/
/*
Copyright (c) 1990-1999 Amiga, Inc.

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
#include <exec/libraries.h>
#include <dos/dos.h>
#include <dos/dostags.h>
#include <intuition/intuition.h>
#include <graphics/displayinfo.h>

#ifdef LATTICE
#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/intuition_protos.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

/* our function error codes */
#define SYSTEMFAIL      (-1L)
#define WINDOWFAIL      (-2L)

/* function prototypes */
LONG beginCommand(UBYTE *command);
LONG doCommand(UBYTE *command, BPTR other);
VOID checkResult(UBYTE *command, LONG result);


/* Formatted version string for the 2.0 VERSION command */
UBYTE *vers = "\0$VER: SystemTest 36.10";

struct Library *IntuitionBase;


struct Screen *OpenScreenTags(struct NewScreen *,ULONG tags, ...);
struct Window *OpenWindowTags(struct NewWindow *,ULONG tags, ...);


void main(int argc, char **argv)

```c
    {
    extern struct Library *DOSBase;
    struct Screen *scr = NULL;
    struct Window *win = NULL;
    ULONG penspecterm = ~0;
    LONG result;
    BPTR file;
    UBYTE *command;
    UBYTE buf[128];

    if(DOSBase->lib_Version < 36)
        {
        printf("This example requires dos.library V36 or higher\n");
        exit(RETURN_FAIL);
        }
    if(!(IntuitionBase = OpenLibrary("intuition.library",36)))
        {
        printf("This example requires intuition.library V36 or higher\n");
        exit(RETURN_FAIL);
        }

    /* SYNCHRONOUS SYSTEM() WITH OUR INPUT/OUTPUT
     */
    printf("\n*** SystemTest: Synchronous System call 'dir libs:':\n");
    command = "dir libs:";
    result = doCommand(command,NULL);
    checkResult(command,result);
    printf("\n*** SystemTest: Synchronous System call of nonexistant command:\n");
    command = "badcommand";
    result = doCommand(command,NULL);
    checkResult(command,result);

    printf("\n*** SystemTest: Synchronous System call 'ask \"...Answer y now\"':\n");
    command =
        "ask \"Ready for CON: on a Custom Screen? Answer y now (should return 5):\"";
    result = doCommand(command,NULL);
    checkResult(command,result);
```
   /* SYNCHRONOUS SYSTEM() WITH CON: IN A CUSTOM SCREEN AND WINDOW





```c
     */
    if(scr = OpenScreenTags(NULL,
                SA_Width, 640,
                SA_Height, 200,
                SA_Depth, 3,
                SA_DisplayID, HIRES_KEY,
                SA_Pens, &penspecterm,  /* Give us New Look */
                TAG_DONE))
        {
        if(win = OpenWindowTags(NULL,
                WA_CustomScreen, scr,
                WA_Flags, WINDOWDRAG|WINDOWCLOSE|ACTIVATE,
                WA_IDCMP, CLOSEWINDOW,
                WA_Top, 20,
                WA_Height, scr->Height - 20,
                WA_Title, "Custom Window",
                WA_ScreenTitle, "Custom Screen",
                TAG_DONE))
            {
            sprintf(buf,"CON://///WINDOW0x%lx", win); /* adds window pointer */
            if(file = Open(buf, MODE_OLDFILE))
                {
                command = "echo \"CLI commands on a custom screen!\"";
                result = doCommand(command,file);
                command = "dir libs:";
                result = doCommand(command,file);
                command = "echo \"( Click CLOSE gadget, or type CTRL-C )\"";
                result = doCommand(command,file);
                Wait(1 << win->UserPort->mp_SigBit | SIGBREAKF_CTRL_C);
                Close(file);    /* Closes the window too */
                }
            else CloseWindow(win);
            }
        CloseScreen(scr);
        }

    printf("\n*** SystemTest: Synchronous System call 'ask \"...Answer y now\"':\n");
    command = "ask \"Ready for Asynchronous demo? Answer y now (should return 5):\"";
    result = doCommand(command,NULL);
    checkResult(command,result);


    /* ASYNCHRONOUS SYSTEM() WITH ON-DEMAND AUTO/WAIT CON:
     */
    printf("\n*** SystemTest: Asynchronous startup of 'Sys:Utilities/Clock':\n");
    command = "SYS:Utilities/Clock";
    result = beginCommand(command);
    checkResult(command,result);

    printf("\n*** SystemTest: Asynchronous startup of 'avail':\n");
    command = "avail";
    result = beginCommand(command);
    checkResult(command,result);

    printf("\nSystemTest exiting. Close Clock and Autocon window when you wish.\n");

    CloseLibrary(IntuitionBase);
    exit(RETURN_OK);
    }
```
/*
 * Synchronous external command (wait for return)
 * Uses your Input/Output unless you supply other handle
 * Result will be return code of the command, unless the System() call
 * itself fails, in which case the result will be -1
 */
LONG doCommand(UBYTE *command, BPTR other)




```c
    {
    struct TagItem stags[4];

    stags[0].ti_Tag = SYS_Input;
    stags[0].ti_Data = other ? other : Input();
    stags[1].ti_Tag = SYS_Output;
    stags[1].ti_Data = other ? NULL: Output();
    stags[3].ti_Tag = TAG_DONE;
    return(System(command, stags));
    }
```
/*
 * Asynchronous external command started with its own autocon Input/Output
 * This routine shows use of the SYS_UserShell tag as well.
 * Result will only reflect whether System() call itself succeeded.
 * If System() call fails, result will be -1L
 * We are using -2L as result if our Open of CON: fails
 */
UBYTE *autocon="CON:0/40/640/150/Auto CON Window Opens if Needed/auto/close/wait";
LONG beginCommand(UBYTE *command)





```c
    {
    struct TagItem stags[5];
    BPTR file;

    if(file = Open(autocon, MODE_OLDFILE))
        {
        stags[0].ti_Tag = SYS_Input;
        stags[0].ti_Data = file;
        stags[1].ti_Tag = SYS_Output;
        stags[1].ti_Data = NULL;
        stags[2].ti_Tag = SYS_Asynch;
        stags[2].ti_Data = TRUE;
        stags[3].ti_Tag = SYS_UserShell;
        stags[3].ti_Data = TRUE;
        stags[4].ti_Tag = TAG_DONE;
        return(System(command, stags));
        }
    else return(WINDOWFAIL);
    }
```
/*
 * Demo routine outputs result of System
 */
VOID checkResult(UBYTE *command, LONG result)






```c
    {
    if(result == SYSTEMFAIL)
        printf("*** SystemTest: could not start process for command\n");
    else if(result == WINDOWFAIL)
        printf("*** SystemTest: can't open con: for command\n");
    else
        printf("*** SystemTest: command (if synchronous) returned %ld\n",result);
    }
```
/*
 * Stack based stubs for opening screen, window
 */
struct Screen *OpenScreenTags(ns, tags)
struct NewScreen *ns;
ULONG tags;

```c
    {
    return (OpenScreenTagList(ns, (struct TagItem *)&tags));
    }
```
struct Window *OpenWindowTags(nw, tags)
struct NewWindow *nw;
ULONG tags;

```c
    {
    return (OpenWindowTagList(nw, (struct TagItem *)&tags));
    }
```

---

## See Also

- [Input — dos.library](../autodocs/dos.library.md#input)
- [Output — dos.library](../autodocs/dos.library.md#output)
