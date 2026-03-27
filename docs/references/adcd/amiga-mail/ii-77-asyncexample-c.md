---
title: II-77/ASyncExample.c
manual: amiga-mail
chapter: amiga-mail
section: ii-77-asyncexample-c
functions: []
libraries: []
---

# II-77/ASyncExample.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* ASyncExample.c - Execute me to compile me with SAS/C 6.56
sc NMINC STRMERGE STREQ NOSTKCHK SAVEDS IGNORE=73 ASyncExample.c
slink FROM LIB:c.o,ASyncExample.o TO ASyncExample LIBRARY LIB:sc.lib,LIB:amiga.lib,asyncio.o
quit ;*/

/*
(c)  Copyright 1992-1999 Amiga, Inc.   All rights reserved.
The information contained herein is subject to change without notice,
and is provided "as is" without warranty of any kind, either expressed
or implied.  The entire risk as to the use of this information is
assumed by the user.
*/

#include <exec/types.h>
#include <exec/exec.h>
#include <dos/dos.h>
#include <dos/dosextens.h>
#include <stdio.h>

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>

#include "asyncio.h"

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }
#endif

VOID main(VOID)
{
struct AsyncFile *in;
LONG              num;
struct AsyncFile *out;

```c
    if (in = OpenAsync("s:Startup-Sequence", MODE_READ, 8192))
    {
        if (out = OpenAsync("t:test_sync", MODE_WRITE, 8192))
        {
            while ((num = ReadCharAsync(in)) >= 0)
            {
                WriteCharAsync(out,num);
            }
            CloseAsync(out);
        }
        CloseAsync(in);
    }
```
}

