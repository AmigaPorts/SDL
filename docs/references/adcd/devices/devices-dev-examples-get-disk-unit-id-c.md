---
title: Devices/Dev_examples/Get_Disk_Unit_ID.c
manual: devices
chapter: devices
section: devices-dev-examples-get-disk-unit-id-c
functions: []
libraries: []
---

# Devices/Dev_examples/Get_Disk_Unit_ID.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   /*

    * Get_Disk_Unit_ID.c
    *
    * Example of getting the UnitID of a disk
    *
    * Compile with SAS C 5.10  lc -b1 -cfistq -v -y -L
    *
    * Run from CLI only
    */
   #include <exec/types.h>
   #include <exec/memory.h>
   #include <dos/dos.h>
   #include <resources/disk.h>

   #include <clib/exec_protos.h>

   #include <stdio.h>

   #ifdef LATTICE
   int CXBRK(void) { return(0); }  /* Disable SAS CTRL/C handling */
   int chkabort(void) { return(0); }  /* really */

   /* There is no amiga.lib stub for this function so a pragma is required
    * This is a pragma for SAS C
    * Your compiler may require a different format
    */
   #pragma libcall DiskBase GetUnitID 1e 1
   #endif

   struct Library *DiskBase = NULL;

   LONG GetUnitID(long);

   void main(int argc, char **argv)
   {
   LONG ids= 0;
   LONG type;

   if (!(DiskBase= (struct Library *)OpenResource(DISKNAME)))
```c
       printf("Cannot open %s\n,DISKNAME");
```
   else
```c
      {
       printf("Defined drive types are:\n");
       printf("  AMIGA  $00000000\n");
       printf("  5.25'' $55555555\n");
       printf("  AMIGA  $00000000 (high density)\n");
       printf("  None   $FFFFFFFF\n\n");

       /* What are the UnitIDs? */
        for (ids = 0; ids < 4; ids++)
           {
            type = GetUnitID(ids);
            printf("The UnitID for unit %d is $%08lx\n",ids,type);
           }
      }
```
   }

