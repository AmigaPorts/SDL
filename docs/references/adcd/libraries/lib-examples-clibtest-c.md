---
title: lib_examples/clibtest.c
manual: libraries
chapter: libraries
section: lib-examples-clibtest-c
functions: []
libraries: []
---

# lib_examples/clibtest.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* clibtest.c--Calls the Sample.library functions (execute to compile with Lattice 5.10a)
LC -b1 -cfistq -v -y -j73 clibtest.c
Blink FROM LIB:c.o,clibtest.o TO clibtest LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit
; note - you must also link with sample.lib if not using sample_pragmas.h
*/

#include <exec/types.h>
#include <exec/libraries.h>
#include <libraries/dos.h>

#include <clib/exec_protos.h>

#include <stdlib.h>
#include <stdio.h>

#include "sampleinclude/samplebase.h"
#include "sampleinclude/sample_protos.h"
#include "sampleinclude/sample_pragmas.h"

#ifdef LATTICE
int CXBRK(void)     { return(0); }      /* Disable Lattice CTRL/C handling */
void chkabort(void) { return; }         /* really */
#endif

struct Library *SampleBase = NULL;

void main(int argc, char **argv)
   {
   LONG n;

   /* Open sample.library */
   if(!(SampleBase=OpenLibrary("sample.library",0)))
```c
      {
      printf("Can't open sample.library\n");
      exit(RETURN_FAIL);
      }
```
   /* Print library name, ID string, version, revision */
   printf("%s  Version=%ld   Revision=%ld  IdString: %s\n",

```c
             SampleBase->lib_Node.ln_Name, SampleBase->lib_Version,
             SampleBase->lib_Revision, SampleBase->lib_IdString);
```
   /* Call the two functions */
   n = Double(-7);
   printf("Function Double(-7) returned %ld\n", n);
   n = AddThese(21,4);
   printf("Function AddThese(21,4) returned %ld\n", n);

   CloseLibrary(SampleBase);
   exit(RETURN_OK);
   }

