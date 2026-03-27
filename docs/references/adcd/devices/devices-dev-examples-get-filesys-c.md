---
title: Devices/Dev_examples/Get_Filesys.c
manual: devices
chapter: devices
section: devices-dev-examples-get-filesys-c
functions: []
libraries: []
---

# Devices/Dev_examples/Get_Filesys.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   /*

    * Get_Filesys.c
    *
    * Example of examining the FileSysRes list
    *
    * Compile with SAS C 5.10  lc -b1 -cfistq -v -y -L
    *
    * Run from CLI only
    */
   #include <exec/types.h>
   #include <exec/memory.h>
   #include <dos/dos.h>
   #include <resources/filesysres.h>

   #include <clib/exec_protos.h>

   #include <stdio.h>

   #ifdef LATTICE
   int CXBRK(void) { return(0); }  /* Disable SAS CTRL/C handling */
   int chkabort(void) { return(0); }  /* really */
   #endif

   struct FileSysResource *FileSysResBase = NULL;

   void main(int argc, char **argv)
   {

   struct FileSysEntry *fse;
   int x;

   /* NOTE - you should actually be in a Forbid while accessing any
```c
    * system list for which no other method of arbitration is available.
    * However, for this example we will be printing the information
    * (which would break a Forbid anyway) so we won't Forbid.
    * In real life, you should Forbid, copy the information you need,
    * Permit, then print the info.
    */
```
   if (!(FileSysResBase = (struct FileSysResource *)OpenResource(FSRNAME)))
```c
       printf("Cannot open %s\n",FSRNAME);
```
   else
```c
       {
       for ( fse = (struct FileSysEntry *)FileSysResBase->fsr_FileSysEntries.lh_Head;
             fse->fse_Node.ln_Succ;
             fse = (struct FileSysEntry *)fse->fse_Node.ln_Succ)
            {
            printf("Found filesystem creator: %s\n",fse->fse_Node.ln_Name);

            printf("                 DosType: ");
            for (x=24; x>=8; x-=8)
                 putchar((fse->fse_DosType >> x) & 0xFF);

            putchar((fse->fse_DosType & 0xFF) + 0x30);

            printf("\n                 Version: %d",(fse->fse_Version >> 16));
            printf(".%ld\n\n",(fse->fse_Version & 0xFFFF));
            }
        }
```
   }

