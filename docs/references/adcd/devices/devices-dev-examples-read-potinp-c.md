---
title: Devices/Dev_examples/Read_Potinp.c
manual: devices
chapter: devices
section: devices-dev-examples-read-potinp-c
functions: []
libraries: []
---

# Devices/Dev_examples/Read_Potinp.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 * Read_Potinp.c
 *
 * An example of using the potgo.resource to read pins 9 and 5 of
 * port 1 (the non-mouse port).  This bypasses the gameport.device.
 * When the right or middle button on a mouse plugged into port 1 is pressed,
 * the read value will change.
 *
 * Use of port 0 (mouse) is unaffected.
 *
 * Compile with SAS C 5.10  lc -b1 -cfistq -v -y -L
 *
 * Run from CLI only
 */

#include <exec/types.h>
#include <exec/memory.h>
#include <dos/dos.h>
#include <resources/potgo.h>
#include <hardware/custom.h>

#include <clib/exec_protos.h>
#include <clib/potgo_protos.h>

#include <stdio.h>

#ifdef LATTICE
int CXBRK(void) {return(0);}  /* Disable SAS Ctrl-C checking */
int chkabort(void) { return(0); }  /* really */
#endif

struct PotgoBase *PotgoBase;
ULONG potbits;
UWORD value;

#define UNLESS(x) if(!(x))
#define UNTIL(x)  while(!(x))

#define OUTRY 1L<<15
#define DATRY 1L<<14
#define OUTRX 1L<<13
#define DATRX 1L<<12

extern struct Custom far custom;

void main(int argc,char **argv)
{
UNLESS (PotgoBase=(struct PotgoBase *)OpenResource("potgo.resource"))

```c
        return;
```
potbits=AllocPotBits(OUTRY|DATRY|OUTRX|DATRX);

/* Get the bits for the right and middle mouse buttons on the alternate mouse port. */

if (potbits != (OUTRY|DATRY|OUTRX|DATRX))

```c
    {
    printf("Pot bits are already allocated! %lx\n",potbits);
    FreePotBits(potbits);
    return;
    }
```
/* Set all ones in the register (masked by potbits) */
WritePotgo(0xFFFFFFFFL,potbits);

printf("\nPlug a mouse into the second port.  This program will indicate when\n");
printf("the right or middle button (if the mouse is so equipped) is pressed.\n");
printf("Stop the program with Control-C. Press return now to begin.\n");

getchar();

UNTIL (SIGBREAKF_CTRL_C & SetSignal(0L,0L))

```c
      /* until CTRL-C is pressed */
      {
      /* Read word at $DFF016 */
        value = custom.potinp;

      /* Show what was read (restricted to our allocated bits) */
      printf("POTINP = $%lx\n",value & potbits);
      }
```
FreePotBits(potbits);
}

