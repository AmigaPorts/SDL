---
title: Devices/other/cycvb.c
manual: devices
chapter: devices
section: devices-other-cycvb-c
functions: []
libraries: []
---

# Devices/other/cycvb.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 * cycvb.c --- Dan Silva's DPaint color cycling interrupt code
 *
 *    Use this fragment as an example for interrupt driven color cycling
 *    If compiled with SAS, include flags -v -y on LC2
 */

#include <exec/types.h>
#include <exec/interrupts.h>
#include <graphics/view.h>
#include <iff/compiler.h>

#define MAXNCYCS 4
#define NO  FALSE
#define YES TRUE
#define LOCAL static

typedef struct {

```c
    SHORT count;
    SHORT rate;
    SHORT flags;
    UBYTE low, high;  /* bounds of range */
    } Range;
```
/* Range flags values */
#define RNG_ACTIVE  1
#define RNG_REVERSE 2
#define RNG_NORATE 36  /* if rate == NORATE, don't cycle */

/* cycling frame rates */
#define OnePerTick   16384
#define OnePerSec    OnePerTick/60

extern Range  cycles[];
extern BOOL   cycling[];
extern WORD   cycols[];
extern struct ViewPort *vport;
extern SHORT  nColors;


MyVBlank()  {
   int i,j;
   LOCAL  Range *cyc;
   LOCAL  WORD  temp;
   LOCAL  BOOL  anyChange;

#ifdef IS_AZTEC
#asm
```c
       movem.l  a2-a7/d2-d7,-(sp)
       move.l   a1,a4
```
#endasm
#endif

   if (cycling)  {

```c
      anyChange = NO;
      for (i=0; i<MAXNCYCS; i++)  {
         cyc = &cycles[i];
         if ( (cyc->low == cyc->high) ||
              ((cyc->flags&RNG_ACTIVE) == 0) ||
              (cyc->rate == RNG_NORATE) )
                 continue;

         cyc->count += cyc->rate;
         if (cyc->count >= OnePerTick)  {
            anyChange = YES;
            cyc->count -= OnePerTick;

            if (cyc->flags&RNG_REVERSE)  {
               temp = cycols[cyc->low];
               for (j=cyc->low; j < cyc->high; j++)
                  cycols[j] = cycols[j+1];
               cycols[cyc->low] = temp;
               }
            else  {
               temp = cycols[cyc->high];
               for (j=cyc->high; j > cyc->low; j--)
                  cycols[j] = cycols[j-1];
               cycols[cyc->low] = temp;
               }
            }
         }
      if (anyChange) LoadRGB4(vport,cycols,nColors);
      }
```
#ifdef IS_AZTEC
```c
      ;   /* this is necessary */
```
#asm
```c
      movem.l  (sp)+,a2-a7/d2-d7
```
#endasm
#endif

   return(0);  /* interrupt routines have to do this */
   }


/*
 *  Code to install/remove cycling interrupt handler
 */

LOCAL char myname[] = "MyVB";  /* Name of interrupt handler */
LOCAL struct Interrupt intServ;

typedef void (*VoidFunc)();

StartVBlank()  {
#ifdef IS_AZTEC
   intServ.is_Data = GETAZTEC();  /* returns contents of register a4 */
#else
   intServ.is_Data = NULL;
#endif
   intServ.is_Code = (VoidFunc)&MyVBlank;
   intServ.is_Node.ln_Succ = NULL;
   intServ.is_Node.ln_Pred = NULL;
   intServ.is_Node.ln_Type = NT_INTERRUPT;
   intServ.is_Node.ln_Pri  = 0;
   intServ.is_Node.ln_Name = myname;
   AddIntServer(5,&intServ);
   }

StopVBlank() { RemIntServer(5,&intServ); }

/**/

