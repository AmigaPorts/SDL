---
title: XI-25/AppMap_demo.c
manual: amiga-mail
chapter: amiga-mail
section: xi-25-appmap-demo-c
functions: []
libraries: []
---

# XI-25/AppMap_demo.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* appmap_demo.c - Execute me to compile me with SAS/C 6.56
sc data=far nominc strmer streq nostkchk saveds ign=73 appmap_demo.c
slink FROM LIB:c.o,appmap_demo.o,appkeymap.o TO appmap_demo LIB LIB:SC.lib,LIB:Amiga.lib
quit
*/

/* Appmap_demo uses the routines in appkeymap.o to clone the current  */
/* task's console keymap.  Appmap_demo then modifies the keymap clone */
/* by redefining some of the keypad keys.  It installs a string key,  */
/* a "normal" key, and a NO OP key, which are acceptable replacements */
/* for keypad keys on a console-based application.                    */
/*                                                                    */
/* This example also installs a dead/deadable key pair and a double   */
/* dead/deadable key pair.  These are provided only as a means for    */
/* understanding how dead-class keys work.  Do not use them as part   */
/* of anything for public consumption.                                */

#include       <exec/types.h>
#include       <exec/memory.h>
#include       <exec/io.h>
#include       <dos/dos.h>
#include       <devices/console.h>
#include       <devices/keymap.h>

#include       <clib/exec_protos.h>
#include       <clib/dos_protos.h>

#include       <stdio.h>
#include       <stdlib.h>

#ifdef  __SASC
void __regargs __chkabort(void);
void __regargs __chkabort(void){}
#endif

#include "appkeymap.h"

#define MYKEYCOUNT 7

far UBYTE deadmap[] =           /* The data for the dead key (the introducer) */
{
  0, '4',                       /* maps to '4' when keypad 4 is pressed alone */
  DPF_DEAD, 1                   /* maps to a dead key when shift is down      */
};

far UBYTE deadablemap[] =
{
  0, '5',                       /* maps to '5' when keypad 5 is pressed alone */
  DPF_MOD, 4,                   /* maps to a deadable key when shift is down  */
  '5', 0xC2, '5', '5', '5'      /* Entry 1 in this table maps to 0xC2, the    */
};                              /* others map to '5'.                         */

far UBYTE doubledeadmap[] =
{
  0, '6',                              /* maps to '6' when keypad 6 is pressed alone */
  DPF_DEAD, 1 | (2 << DP_2DFACSHIFT)   /* maps to a dead key when shift is down      */
};

far UBYTE doubledeadablemap[] =
{
  0, '7',                       /* maps to '7' when keypad 7 is pressed alone */
  DPF_MOD, 4,                   /* maps to a deadable key when shift is down  */
  '7', '7', 0xA5, 0xA9, '7'     /* Entry 2 in this table maps to $A5, entry 3 */
};                              /* to $A9, the others to '7'.                 */


UBYTE strings[] =
{
        5,16,
        5,21,
        3,26,
        9,29,
        4,38,
        10,42,
        8,52,
        14,60,
        'p','l','a','i','n',
        's','h','i','f','t',
        'a','l','t',
        's','h','i','f','t','+','a','l','t',
        'c','t','r','l',
        'c','t','r','l','+','s','h','i','f','t',
        'c','t','r','l','+','a','l','t',
        'c','t','r','l','+','a','l','t','+','s','h','i','f','t'
};


struct MyKey mykeys[MYKEYCOUNT] =
{
  { N1_KEY,                    /* The '1' from the numeric key pad                 */
```c
    KCF_STRING | KC_VANILLA,   /* This is a string key that accepts all qualifiers */
    1, 1,                      /* Capsable and Repeatable                          */
    (ULONG) strings            /* This points to the key's string data table       */
```
  },


  { N2_KEY,     /* The '2' from the numeric key pad                           */
```c
    KC_VANILLA, /* VANILLA key generating shift-alted, alted, shifted, plain  */
    0, 0,       /* Non-Capsable, Non-Repeatable                               */
    0x26252423  /* This long word is four ANSI codes: $26=& $25=% $24=$ $23=# */
```
  },


  { N3_KEY,     /* The '3' from the numeric key pad */
    KCF_NOP,    /* This key is a NO OPeration key   */
    0, 0,       /* Non-Capsable, Non-Repeatable     */
    0L
  },


  { N4_KEY,                /* The '4' from the numeric key pad */
```c
    KCF_DEAD | KCF_SHIFT,  /* A shiftable Dead-class key       */
    0, 0,                  /* Non-Capsable, Non-Repeatable     */
    (ULONG) deadmap        /* pointer to dead-class key data   */
```
  },


  { N5_KEY,                /* The '5' from the numeric key pad */
```c
    KCF_DEAD | KCF_SHIFT,  /* A shiftable Dead-class key       */
    0, 0,                  /* Non-Capsable, Non-Repeatable     */
    (ULONG) deadablemap    /* pointer to dead-class key data   */
```
  },


  { N6_KEY,                /* The '6' from the numeric key pad */
```c
    KCF_DEAD | KCF_SHIFT,  /* A shiftable Dead-class key       */
    0, 0,                  /* Non-Capsable, Non-Repeatable     */
    (ULONG) doubledeadmap  /* pointer to dead-class key data   */
```
  },


  { N7_KEY,                   /* The '7' from the numeric key pad */
```c
    KCF_DEAD | KCF_SHIFT,     /* A shiftable Dead-class key       */
    0, 0,                     /* Non-Capsable, Non-Repeatable     */
    (ULONG) doubledeadablemap /* pointer to dead-class key data   */
```
  }
};


extern struct Library *SysBase;

struct KeyMap *appkeymap, defkeymap;

struct IOStdReq *conio = NULL;
struct MsgPort *replyport = NULL;

/* prototypes for our program functions */

void closeall (void);
void closeout (UBYTE * errstring, LONG rc);
struct IOStdReq *makeio (void);
void freeio (struct IOStdReq *ior);


void
main (int argc, char **argv)
{
  LONG rc = 0;

/* This example is shell-only. It modifies a shell's keymap while running. */
/* Alternately, you could modify this demo code to change the keymap       */
/* of the console.device of another CON: window OR a console.device        */
/* unit you've attached to your own Intuition window.  You need the        */
/* device and unit pointers for the console unit you wish to affect.       */

  if (!argc)

```c
    exit (RETURN_FAIL);
```
  if (SysBase->lib_Version < 37)

```c
    closeout ("Kickstart 2.0 required", RETURN_FAIL);
```
  conio = makeio ();
  if (conio == NULL)


```c
    closeout ("Can't create IORequest", RETURN_FAIL);
```
  conio->io_Command = CD_ASKKEYMAP;          /* Obtain a copy of the    */
  conio->io_Data = (APTR) & defkeymap;       /* shell console's KeyMap. */
  conio->io_Length = sizeof (struct KeyMap);
  DoIO (conio);

  appkeymap = CreateAppKeyMap (&defkeymap);

  if (appkeymap == NULL)

```c
    closeout ("Can't create keymap", RETURN_FAIL);
```
/* If we get here, all went OK.  We now have appkeymap and defkeymap, and  */
/* conio IOStdRequest is init'd to talk to our shell's console device unit */

  AlterAppKeyMap (appkeymap, mykeys, MYKEYCOUNT);

  conio->io_Command = CD_SETKEYMAP;      /* Set the keymap for the console */
  conio->io_Data = (APTR) appkeymap;     /* to be the modified clone.      */
  conio->io_Length = sizeof (struct KeyMap);
  DoIO (conio);

  printf ("Appkeymap installed for this console.\n");
  printf ("Changes for our keymap were specified in an array in appmap_demo.c\n\n");
  printf ("Numeric pad 1 is now a repeatable and capsable string key.  It\n");
  printf ("    also prints a different string for all qualifier combos.\n");
  printf ("Numeric pad 2 is different chars if normal, shifted, alted, shift-alted.\n");
  printf ("Numeric pad 3 is disabled.\n");
  printf ("Shift-Numeric pad 4 is a dead-key.  Shift-Numeric pad 5 is a deadable key.\n");
  printf ("    When you hit Shift-Numeric pad 4 then Shift-Numeric pad 5, this\n");
  printf ("    example prints '\302'\n");
  printf ("Shift-Numeric pad 6 is a double dead-key.  Shift-Numeric pad 7 is a deadable\n");
  printf ("    key.  When you hit Shift-Numeric pad 6 once then Shift-Numeric pad 7,\n");
  printf ("    this example prints '\245'.  When you hit Shift-Numeric pad 6 twice then\n");
  printf ("    Shift-Numeric pad 7, this example prints '\251'.\n");
  printf ("\nHit return to exit when done\n");
  getchar ();
  printf ("Setting this console back to default keymap\n");

  conio->io_Command = CD_SETKEYMAP;          /* Restore the shell's original keymap */
  conio->io_Data = (APTR) & defkeymap;
  conio->io_Length = sizeof (struct KeyMap);
  DoIO (conio);

  closeall ();
  exit (rc);
}



struct IOStdReq *
makeio (void)
{
  struct MsgPort *conport;
  struct IOStdReq *ior = NULL;
  struct InfoData *id;
  struct Process *proc;

  proc = (struct Process *) FindTask (NULL);
  conport = (struct MsgPort *) proc->pr_ConsoleTask;
  if (!conport)

```c
    return (NULL);
```
  if (id = (struct InfoData *)
```c
      AllocMem (sizeof (struct InfoData), MEMF_PUBLIC | MEMF_CLEAR))
```
  {
```c
    if (DoPkt (conport, ACTION_DISK_INFO, ((ULONG) id) >> 2, 0L, 0L, 0L, 0L))
    {
      if (replyport = CreateMsgPort ())
      {
        if (ior = CreateIORequest (replyport, sizeof (struct IOStdReq)))
        {
          ior->io_Device = ((struct IOStdReq *) id->id_InUse)->io_Device;
          ior->io_Unit = ((struct IOStdReq *) id->id_InUse)->io_Unit;
        }
      }
    }
    FreeMem (id, sizeof (struct InfoData));
```
  }
  return (ior);
}

void
freeio (struct IOStdReq *ior)
{
  if (ior)
  {
```c
    if (ior->io_Message.mn_ReplyPort)
      DeleteMsgPort (ior->io_Message.mn_ReplyPort);
    DeleteIORequest (ior);
```
  }
}

void
closeall ()
{
  if (conio)
```c
    freeio (conio);
```
  if (appkeymap)
```c
    DeleteAppKeyMap (appkeymap);
```
}


void
closeout (UBYTE * errstring, LONG rc)
{
  if (*errstring)
```c
    printf ("%s\n", errstring);
```
  closeall ();
  exit (rc);
}

