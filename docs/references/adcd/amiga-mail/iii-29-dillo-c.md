---
title: III-29/dillo.c
manual: amiga-mail
chapter: amiga-mail
section: iii-29-dillo-c
functions: [Forbid, Permit]
libraries: [exec.library]
---

# III-29/dillo.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
**  dillo.c
**
**  A code module of armadillo.library, which implements the main library
**  functions.  Strictly do-nothing code for example.
**
**  © Copyright 1993-1999, Amiga, Inc. All Rights Reserved.
**  Written by John Wiederhirn
**
*/

#include    <exec/types.h>
#include    <exec/memory.h>
#include    <clib/exec_protos.h>
#include    <pragmas/exec_pragmas.h>

extern struct ExecBase *SysBase;	/* olsen 30-Jan-96 */

#include    "dillo.h"
#include    "dillo_protos.h"

/* The next prototype is for a static function which is only available
** to code inside the library itself.
*/

static void ClearDilloName(struct Armadillo * );


/* The following global data item becomes part of the near data section
** for each library client.  Since this library is designed to give a
** different library base to each client, this data item is unique per
** client.
**
** It holds the number of armadillos a given client has open at once.
*/

ULONG TotalDillos = 0L;

/* In contrast to the previous global data item, the following goes in
** the far data section and is global to all library clients.  Read access
** doesn't need arbitration, but write access needs a semaphor or use of
** a Forbid()/Permit() pair (see CreateDillo() below).
**
** It holds the number of times CreateDillo has been called overall.
*/

ULONG __far TotalDillosCreated = 0L;

/* This routine just allocates a `struct Armadillo', and increments
** the number of armadillos this client has by one.  If the allocation
** cannot be done, this routine returns NULL.
*/

struct Armadillo * __saveds __asm
LIBCreateArmadillo( register __a6 struct Library *DilloBase )
{
```c
    struct Armadillo *newdillo = NULL;

    if ( newdillo = AllocMem( sizeof(struct Armadillo), MEMF_CLEAR ))
    {
        /* Armadillo allocated, so increment number of dillos.
        ** Note that to reference the client-unique data takes no
        ** special coding.
        */

        TotalDillos++;

        /* Since we've also added to the overall number created, we
        ** need to also update the TotalDillosCreated variable in
        ** the far data section.  That means a Forbid() and Permit()
        ** around the action (which MUST complete).
        */

        Forbid();
        TotalDillosCreated++;
        Permit();

    }

    /* And return either the address of the new armadillo, or else
    ** return NULL if the allocation failed.
    */

    return( newdillo );
```
}


/* This function wipes an existing Armadillo structure out of existance
** and decrements the number of Armadillos for this client.  Note that the
** number of Armadillos created overall does not go down.
*/

VOID __saveds __asm
LIBDeleteArmadillo( register __a0 struct Armadillo *dillo,
```c
                    register __a6 struct Library *DilloBase )
```
{
```c
    /* This routine is ``safe'' in that it can handle being given a NULL
    ** pointer (in which case it does nothing).
    */

    if ( dillo )
    {
        /* We do indeed appear to have an armadillo on our hands
        ** so we decrement the overall count and deallocate the
        ** memory it uses.
        */

        TotalDillos--;

        FreeMem( dillo, sizeof( struct Armadillo ));
    }

    return;
```
}

/* This transfers the contents of a string up to 32 characters long into
** the name buffer of an Armadillo.  Any attempt to transfer more than 32
** characters gets truncated to 32 characters.  Returns FALSE if dillo
** was a NULL pointer, the pointer to the string was NULL, or the length
** of the transfer was to be 0L.
*/

BOOL __saveds __asm
LIBNameArmadillo( register __a0 struct Armadillo *dillo,
```c
                  register __a1 STRPTR dname,
                  register __d0 ULONG len,
                  register __a6 struct Library *DilloBase )
```
{
```c
    BOOL retval = FALSE;

    /* This routine is ``safe'' in that it can handle being given a NULL
    ** pointer (in which case it does nothing).
    */

    if ( dillo && dname && len )
    {
        CopyMem( (APTR) dname, (APTR) &(dillo->name), ((len>31L)?32L:len) );
        retval = TRUE;
    }

    return( retval );
```
}


/* Assigns a value to the weight field of an Armadillo structure.  It
** returns NULL if a NULL pointer is passed in or amt was 0L.
*/

BOOL __saveds __asm
LIBFillArmadillo( register __a0 struct Armadillo *dillo,
```c
                  register __d0 ULONG amt,
                  register __a6 struct Library *DilloBase )
```
{
```c
    BOOL retval = FALSE;

    /* This routine is ``safe'' in that it can handle being given a NULL
    ** pointer (in which case it does nothing).
    */

    if ( dillo && amt )
    {
        dillo->weight = amt;
        retval = TRUE;
    }

    return( retval );
```
}


/* In homage to the Texas state animal, the roadkill armadillo, this function
** sets whether a given Armadillo is flattened or not.  Returns NULL if a
** NULL pointer was passed as the Armadillo structure.
*/

BOOL __saveds __asm
LIBFlattenArmadillo( register __a0 struct Armadillo *dillo,
```c
                     register __d0 BOOL flatd,
                     register __a6 struct Library *DilloBase )
```
{
```c
    BOOL retval = FALSE;

    /* This routine is ``safe'' in that it can handle being given a NULL
    ** pointer (in which case it does nothing).
    */

    if ( dillo )
    {
        dillo->flat = flatd;
        retval = TRUE;
    }

    return( retval );
```
}


/* Returns whether or not the Armadillo has been flattened.  If a NULL
** pointer is passed in, this function returns FALSE (not really distinct).
*/

BOOL __saveds __asm
LIBDilloFlat( register __a0 struct Armadillo *dillo,
```c
              register __a6 struct Library *DilloBase )
```
{
```c
    BOOL retval = FALSE;

    /* This routine is ``safe'' in that it can handle being given a NULL
    ** pointer (in which case it returns FALSE).
    */

    if ( dillo )
    {
        retval = dillo->flat;
    }

    return( retval );
```
}


/* Returns the weight of a given Armadillo or 0L if a NULL pointer
** is passed instead of an Armadillo (no pointer == no weight ).
*/

ULONG __saveds __asm
LIBDilloWeight( register __a0 struct Armadillo *dillo,
```c
                register __a6 struct Library *DilloBase )
```
{
```c
    ULONG retval = 0L;

    /* This routine is ``safe'' in that it can handle being given a NULL
    ** pointer (in which case it returns 0L).
    */

    if ( dillo )
    {
        retval = dillo->weight;
    }

    return( retval );
```
}


/* This function copies the name of an Armadillo into the caller-specified
** buffer (which MUST be at least 32 characters in length).  A NULL pointer
** for the Armadillo, buffer or len will get a FALSE return, otherwise a
** return of TRUE if the transfer occurred.
*/

BOOL __saveds __asm
LIBDilloName( register __a0 struct Armadillo *dillo,
```c
              register __a1 STRPTR buf,
              register __d0 ULONG len,
              register __a6 struct Library *DilloBase )
```
{
```c
    BOOL retval = FALSE;

    /* This routine is ``safe'' in that it can handle being given a NULL
    ** pointer (in which case it does nothing).
    */

    if ( dillo && buf && len)
    {
        CopyMem( (APTR) &(dillo->name), (APTR) buf, ((len>31L)?32L:len) );
        retval = TRUE;
    }

    return( retval );
```
}


/* Following are non-public but externally-accessible entry points. */

/* This routine clears out the contents of an Armadillo.  It also is an
** example of using a non-public non-ext.-accessible routine in a shared
** library.
*/

VOID __saveds __asm
LIBClearDillo( register __a0 struct Armadillo *dillo,
```c
               register __a6 struct Library *DilloBase )
```
{
```c
    /* This routine is ``safe'' in that it can handle being given a NULL
    ** pointer (in which case it does nothing).
    */

    if ( dillo )
    {
        dillo->flat = FALSE;
        dillo->weight = 0L;
        ClearDilloName( dillo );
    }
```
}


/* This routine does an "unprotected" query (legal, since the access is
** read-only) of the TotalDillosCreated variable in the far data section.
*/

ULONG __saveds __asm
LIBDilloBirths( register __a6 struct Library *DilloBase )
{
```c
    return( TotalDillosCreated );
```
}


/* Following call is a non-public non-externally-accessible function */

/* This function is callable ONLY from within this module.  It clears out
** the name buffer for a given Armadillo.
*/

static VOID
ClearDilloName( struct Armadillo *dillo )
{

```c
    int i;

    /* This routine is NOT 'safe'.  Params must be pre-checked. */

    for(i=0;i<31;i++)
        dillo->name[i] = '\0';
```
}

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
