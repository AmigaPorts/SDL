---
title: Lib_examples/maprawkey.c
manual: libraries
chapter: libraries
section: lib-examples-maprawkey-c
functions: [MapRawKey, Output]
libraries: [dos.library, keymap.library]
---

# Lib_examples/maprawkey.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* maprawkey.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfistq -v -y -j73 maprawkey.c
Blink FROM LIB:c.o,maprawkey.o TO maprawkey LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit
* maprawkey.c - Map Intuition RAWKEY events to ANSI with MapRawKey();
*/
#include <exec/types.h>
#include <exec/memory.h>
#include <dos/dos.h>
#include <intuition/intuition.h>
#include <devices/inputevent.h>

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/keymap_protos.h>
#include <clib/intuition_protos.h>

#include <stdio.h>
#include <stdlib.h>

#ifdef LATTICE
int CXBRK(void)  { return(0); }  /* Disable Lattice CTRL/C handling */
void chkabort(void) { return; }  /* really */
#endif

/* our function prototypes */
void openall(void);
void closeall(void);
void closeout(UBYTE *errstring, LONG rc);

struct Library    *IntuitionBase = NULL;
struct Library    *KeymapBase    = NULL;
struct Window     *window        = NULL;

void main(int argc, char **argv)
{
```c
    struct IntuiMessage *imsg;
    APTR                *eventptr;
    struct InputEvent   inputevent = {0};
    LONG                windowsignal;
    UBYTE               buffer[8];
    COUNT               i;
    BOOL                Done = FALSE;

    openall();

    window = OpenWindowTags(NULL,
                            WA_Width,  500,
                            WA_Height, 60,
                            WA_Title, "MapRawKey - Press Keys",
                            WA_Flags, WFLG_CLOSEGADGET | WFLG_ACTIVATE,
                            WA_IDCMP, IDCMP_RAWKEY | IDCMP_CLOSEWINDOW,
                            TAG_DONE);
    if(window == NULL)   closeout("Can't open window",RETURN_FAIL);

    windowsignal = 1L << window->UserPort->mp_SigBit;

    /* Initialize InputEvent structure (already cleared to 0) */
    inputevent.ie_Class = IECLASS_RAWKEY;

    while(!Done)
       {
       Wait(windowsignal);

       while (imsg = (struct IntuiMessage *)GetMsg(window->UserPort))
           {
           switch(imsg->Class)
               {
                case IDCMP_CLOSEWINDOW:
                    Done = TRUE;
                    break;

                case IDCMP_RAWKEY:
                    inputevent.ie_Code = imsg->Code;
                    inputevent.ie_Qualifier = imsg->Qualifier;

                    printf("RAWKEY: Code=$%04x  Qualifier=$%04lx\n",
                             imsg->Code, imsg->Qualifier);

                    /* Make sure deadkeys and qualifiers are taken
                     * into account.
                     */
                    eventptr = imsg->IAddress;
                    inputevent.ie_EventAddress = *eventptr;

                    /* Map RAWKEY to ANSI */
                    i = MapRawKey(&inputevent, buffer, 8, NULL);

                    if (i == -1) Write(Output(),"*Overflow*",10);
                    else if (i)
                        {
                        /* This key or key combination mapped to something */
                        printf("MAPS TO: ");
                        Write(Output(),buffer,i);
                        printf("\n");
                        }
                    break;
                }
            ReplyMsg((struct Message *)imsg);
            }
        }
    CloseWindow(window);
    closeall();
    exit(RETURN_OK);
```
}

void openall(void)
{

```c
    KeymapBase = OpenLibrary("keymap.library", 37);
    if (KeymapBase == NULL)    closeout("Kickstart 2.0 required",RETURN_FAIL);

    IntuitionBase = OpenLibrary("intuition.library", 37);
    if (IntuitionBase == NULL) closeout("Can't open intuition",RETURN_FAIL);
```
}

void closeall(void)
{
```c
    if (IntuitionBase)  CloseLibrary(IntuitionBase);
    if (KeymapBase)     CloseLibrary(KeymapBase);
```
}

void closeout(UBYTE *errstring, LONG rc)
{
```c
    if (*errstring)  printf("%s\n",errstring);
    closeall();
    exit(rc);
```
}

---

## See Also

- [MapRawKey — keymap.library](../autodocs/keymap.library.md#maprawkey)
- [Output — dos.library](../autodocs/dos.library.md#output)
