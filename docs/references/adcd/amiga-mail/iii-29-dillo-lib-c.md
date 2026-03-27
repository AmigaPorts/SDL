---
title: III-29/dillo_lib.c
manual: amiga-mail
chapter: amiga-mail
section: iii-29-dillo-lib-c
functions: []
libraries: []
---

# III-29/dillo_lib.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
**  dillo_lib.c
**
**  Contains the __UserLibInit() and __UserLibCleanup() routines for
**  the armadillo.library example shared library.
**
**  © Copyright 1993-1999, Amiga, Inc. All Rights Reserved.
**  Written by John Wiederhirn
**
*/

#include    <exec/types.h>
#include    <clib/exec_protos.h>
#include    <pragmas/exec_pragmas.h>

/* These prototypes are just to keep the compiler happy since we don't
** want them in the distributable proto file.
*/

int __saveds __UserLibInit(void);
void __saveds __UserLibCleanup(void);

/* Following global item (UtilityBase) is created so our library can make
** utility.library calls.  Technically putting it in the near section is a waste
** of memory, but for this example, it serves its purpose.  Note also that we
** don't actually MAKE any Utility calls, but we COULD.
*/

struct Library *UtilityBase = NULL;
struct Library *SysBase = NULL;

/*
*/

int __saveds
__UserLibInit( void )
{
```c
    int retval = 1;

    SysBase = (*((void **)4));

    /* Here we attempt to open Utility library.  Not a particularly good
    ** example, but it gets the point across.  If exec.library could not
    ** be opened (say for a second it couldn't), then __UserLibInit would
    ** return 1 indicating failure (where a return of 0 means success).
    */

    if (UtilityBase = OpenLibrary( "utility.library", 0L ))
        retval = 0;

    return( retval );
```
}


/* About as basic a routine as you can get, this routine cleans up the library
** by providing a matching CloseLibrary of the Utility library base we opened
** in the __UserLibInit() routine.
*/

void __saveds
__UserLibCleanup( void )
{
```c
    CloseLibrary( UtilityBase );
```
}

