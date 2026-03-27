---
title: IV-101/dt.c
manual: amiga-mail
chapter: amiga-mail
section: iv-101-dt-c
functions: []
libraries: []
---

# IV-101/dt.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

; /* Compiled with SAS/C 6.56.  Run from CLI only.
sc DATA=NEAR NMINC STRMERGE NOSTKCHK IGNORE=73 dt.c
slink from lib:c.o dt.o TO dt LIBRARY lib:sc.lib lib:amiga.lib
quit ; */

#include <exec/types.h>
#include <datatypes/datatypesclass.h>  /* This includes other files we need */
#include <stdio.h>

#include <clib/exec_protos.h>          /* Prototypes for system functions */
#include <clib/intuition_protos.h>
#include <clib/datatypes_protos.h>

#ifdef LATTICE                         /* Disable SAS/C CTRL-C handling */
int CXBRK(void)    { return(0); }
int chkabort(void) { return(0); }
#endif




struct Library *IntuitionBase=NULL;    /* System library bases */
struct Library *DataTypesBase=NULL;

VOID main(int argc, char **argv)
{
APTR dtobject=NULL;        /* Pointer to a datatypes object */
struct dtTrigger mydtt;    /* A trigger structure for the DTM_TRIGGER method */
ULONG dores;               /* Variable for return values    */

if (IntuitionBase=OpenLibrary("intuition.library",39L))
   {
   if(DataTypesBase=OpenLibrary("datatypes.library",39L) )
```c
      {
      if(argc > 1 ) /* CLI only, at least one argument please. */
         {
         /* Attempt to make an 8svx sound object from the file name the user */
         /* specified in the command line.  For a list of possible error     */
         /* returns, see the Autodocs for NewDTObjectA().  The group ID tag  */
         /* will allow only sound datatype files to be accepted for the call.*/
         if (dtobject = NewDTObject(argv[1], DTA_GroupID, GID_SOUND,
                                             TAG_END) )
            {
            mydtt.MethodID     = DTM_TRIGGER; /* Fill in the dtTrigger struct */
            mydtt.dtt_GInfo    = NULL;
            mydtt.dtt_Function = STM_PLAY;
            mydtt.dtt_Data     = NULL;

            /* The return value of the DTM_TRIGGER method used with the 8svx */
            /* sound datatype is undefined in V39.  This is likely to change */
            /* in future versions of the Amiga operating system.             */
            dores = DoDTMethodA(dtobject, NULL, NULL, &mydtt);

            /* Let the 8svx sound finish playing.  Currently (V39) there is  */
            /* no programmatic way to find out when it is finished playing.  */
            Wait(SIGBREAKF_CTRL_C);

            DisposeDTObject(dtobject);
            }
         else printf("Couldn't create new object or not a sound data file\n");

         }
      else printf("Give a file name too.\n");

      CloseLibrary(DataTypesBase);
      }
```
   else printf("Can't open datatypes library\n");

   CloseLibrary(IntuitionBase);
   }
else printf("Can't open V39 Intuition\n");
}

