---
title: Devices/Dev_examples/Set_Prefs.c
manual: devices
chapter: devices
section: devices-dev-examples-set-prefs-c
functions: [OpenDevice]
libraries: [exec.library]
---

# Devices/Dev_examples/Set_Prefs.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 * Set_Prefs.c
 *
 * This example changes the printer device's COPY of preferences (as obtained
 * when the printer device was opened by a task via OpenDevice()).  Note that
 * it only changes the printer device's copy of preferences, not the preferences
 * as set by the user via the preference editor(s).
 *
 * Compile with SAS C 5.10: LC -b1 -cfistq -v -y -L
 *
 * Run from CLI only
 */

#include <exec/types.h>
#include <devices/printer.h>
#include <devices/prtbase.h>
#include <intuition/intuition.h>
#include <intuition/screens.h>
#include <intuition/preferences.h>

#include <clib/exec_protos.h>
#include <clib/alib_protos.h>
#include <clib/alib_stdio_protos.h>
#include <clib/graphics_protos.h>
#include <clib/intuition_protos.h>

struct Library *IntuitionBase;
struct Library *GfxBase;

union printerIO
{
```c
    struct IOStdReq    ios;
    struct IODRPReq    iodrp;
    struct IOPrtCmdReq iopc;
```
};

struct MsgPort *PrintMP;
union printerIO *pio;

char message[] = "\
This is a test message to see how this looks when printed\n\
using various printer settings.\n\n";

VOID main(VOID);
VOID DoPrinter(VOID);
int DoTest(VOID);

VOID main(VOID)
{

if (IntuitionBase = OpenLibrary("intuition.library",0L))
```c
    {
    if (GfxBase = OpenLibrary("graphics.library",0L))
        {
        DoPrinter();
        CloseLibrary(GfxBase);
        }

    CloseLibrary(IntuitionBase);
    }
```
}

VOID DoPrinter(VOID)
{

if (PrintMP = CreatePort(0L,0L))
```c
    {
    if (pio = (union printerIO *)CreateExtIO(PrintMP,sizeof(union printerIO)))
        {
        if (!(OpenDevice("printer.device",0L,(struct IORequest *)pio,0L)))
            {
            DoTest();
            CloseDevice((struct IORequest *)pio);
            }
        DeleteExtIO((struct IORequest *)pio);
        }
    DeletePort(PrintMP);
    }
```
}

DoTest(VOID)
{
struct PrinterData *PD;
struct Preferences *prefs;
UWORD newpitch;
UWORD newspacing;

/* Send INIT sequence - make sure printer is inited - some      */
/* printers may eject the current page if necessary when inited */

pio->ios.io_Command = CMD_WRITE;
pio->ios.io_Data = "\033#1";
pio->ios.io_Length = -1L;

if (DoIO((struct IORequest *)pio))

```c
    return(FALSE);
```
/* Print some text using the default settings from Preferences */

pio->ios.io_Command = CMD_WRITE;
pio->ios.io_Data = message;
pio->ios.io_Length = -1L;

if(DoIO((struct IORequest *)pio))
   return(FALSE);

/* Now try changing some settings
 * Note that we could just as well send the printer.device escape
 * sequences to change these settings, but this is an example program.
 */

/* Get pointer to printer data  */
PD = (struct PrinterData *) pio->ios.io_Device;

/* Get pointer to printer's copy of preferences
 * Note that the printer.device makes a copy of preferences when
 * the printer.device is successfully opened via OpenDevice(),
 * so we are only going to change the COPY of preferences
 */

prefs = &PD->pd_Preferences;


/* Change a couple of settings                          */

if (prefs->PrintSpacing == SIX_LPI)
```c
    newspacing = EIGHT_LPI;
```
if (prefs->PrintSpacing == EIGHT_LPI)

```c
    newspacing = SIX_LPI;
```
if (prefs->PrintPitch == PICA)
```c
    newpitch = ELITE;
```
if (prefs->PrintPitch == ELITE)
```c
    newpitch = FINE;
```
if (prefs->PrintPitch == FINE)

```c
    newpitch = PICA;
```
/* And let's change the margins too for this example */

prefs->PrintLeftMargin = 20;
prefs->PrintRightMargin = 40;

prefs->PrintPitch = newpitch;
prefs->PrintSpacing = newspacing;

/* Send INIT sequence so that these settings are used */

pio->ios.io_Command = CMD_WRITE;
pio->ios.io_Data = "\033#1";
pio->ios.io_Length = -1L;

if(DoIO((struct IORequest *)pio))
   return(FALSE);

pio->ios.io_Command = CMD_WRITE;
pio->ios.io_Data = message;
pio->ios.io_Length = -1L;

if(DoIO((struct IORequest *)pio))
   return(FALSE);

/* Send FormFeed so page is ejected  */

pio->ios.io_Command = CMD_WRITE;
pio->ios.io_Data = "\014";
pio->ios.io_Length = -1L;

if(DoIO((struct IORequest *)pio))
   return(FALSE);

return(TRUE);
}

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
