---
title: 33 / / Custom Stream Handlers / Installing a Custom Stream Handler
manual: libraries
chapter: libraries
section: 33-custom-stream-handlers-installing-a-custom-stream-handler
functions: [InitIFF]
libraries: [iffparse.library]
---

# 33 / / Custom Stream Handlers / Installing a Custom Stream Handler

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To initialize your [IFFHandle](libraries/33-basic-functions-and-structures-of-iffparse-library.md) to point to your custom stream and stream
handler, you must open your stream and place a pointer to the stream in
your IFFHandle's [iff_Stream](libraries/33-stream-management-initialization.md) field.  This pointer could be the return from
[fopen()](libraries/33-stream-management-custom-streams.md), or an Exec device I/O request, or any other type of pointer which
will provide your custom stream handler with a way to manage your stream.
For example:


```c
    iff->iff_Stream = (ULONG) fopen("foo");
```
Next, you must install your custom handler for this stream, and also tell
IFFParse the seek capabilities of your stream.  To install your custom
stream handler, you must first set up a [Hook](libraries/37-callback-hooks-callback-hook-structure-and-function.md) structure (<utility/[hooks.h](autodocs-2.0/includes-utility-hooks-h.md)>)
to point to your stream handling function.  Then use [InitIFF()](libraries/33-stream-management-initialization.md) to install
your stream handler and also tell IFFParse the seek capabilities of your
stream.  There is "some assembly required".

Release 2 hook function calling conventions specify a register interface.
For an IFFParse custom stream hook, at entry, A0 contains a pointer to the
hook, A2 is a pointer to your [IFFHandle](libraries/33-basic-functions-and-structures-of-iffparse-library.md), and A1 is a pointer to a command
packet, which tells you what to do.  A6 contains a pointer to
IFFParseBase.  You may trash A0, A1, D0, and D1.  All other registers must
be preserved.  You return your error code in D0.  A return of 0 indicates
success.  A non-zero return indicates an error.

If your compiler supports registered function parameters, you may use a
registerized C function entry as the [h_Entry](libraries/37-callback-hooks-callback-hook-structure-and-function.md) hook entry point:


/* mystreamhandler - SAS C custom stream handler with */
/* registerized arguments                             */
static LONG __saveds __asm
mystreamhandler (
```c
    register __a0 struct Hook               *hook,
    register __a2 struct IFFHandle          *iff,
    register __a1 struct IFFStreamCmd       *actionpkt
    )
```
{
/*
 * Code to handle the stream commands - see end this section
 * for a complete example custom stream handler function.
 *
 */
}

/* Initialization of Hook structure for registerized  */
/* handler function                                   */
struct Hook mystreamhook {

```c
    { NULL },
    (ULONG (*)()) mystreamhandler,
                  /* h_Entry, registerized function entry */
    NULL,
    NULL };
```
/* Open custom stream and InitIFF to custom stream handler */
if ( iff->iff_Stream = (ULONG) myopen("foo") )


```c
    {
    InitIFF (iff, IFFF_FSEEK | IFFF_RSEEK, &mystreamhook);
    }
```
Alternately, you could initialize your [Hook](libraries/37-callback-hooks-callback-hook-structure-and-function.md) structure's [h_Entry](libraries/37-callback-hooks-callback-hook-structure-and-function.md) to point
to a standard assembler stub which would push the register arguments on
the stack and then call a standard args C function.  In this case, you
must store the address of your C function in the [h_SubEntry](libraries/37-callback-hooks-callback-hook-structure-and-function.md) field of the
Hook structure so the assembler stub can find and call your C entry point.
A sample assembler hook entry stub follows.  This would be assembled as
hookentry.o and linked with your C code.


* HookEntry.asm for SAS C


        INCLUDE "exec/types.i"
        INCLUDE "utility/hooks.i"

        XDEF    _HookEntry

        section code
 _HookEntry:


```c
        move.l  a6,-(sp)
        move.l  a1,-(sp)                ; push message packet pointer
        move.l  a2,-(sp)                ; push object pointer
        move.l  a0,-(sp)                ; push hook pointer
        move.l  h_SubEntry(a0),a0       ; fetch C entry point ...
        jsr     (a0)                    ; ... and call it
        lea     12(sp),sp               ; fix stack
        move.l  (sp)+,a6
        rts

        end
```
When using an assembler HookEntry stub, your C program's custom stream
handler interface would be initialized as follows:


extern LONG HookEntry();        /* The assembler entry */

/* mystreamhandler - a standard args C function custom stream handler*/
static LONG mystreamhandler ( struct Hook *hook,
```c
                              struct IFFHandle *iff,
                              struct IFFStreamCmd *actionpkt )
```
{
/* Code to handle the stream commands - see end of this section
 * for a complete example custom stream handler function.
 */
}

/* Initialization of Hook for asm HookEntry and std args C function */
struct Hook mystreamhook {

```c
    { NULL },
    (ULONG (*)()) HookEntry,        /* h_Entry, assembler stub entry */
    (ULONG (*)()) mystreamhandler,
                              /* h_SubEntry, std args function entry */
    NULL };
```
/* Open custom stream and InitIFF to custom stream handler */
if ( iff->iff_Stream = (ULONG) myopen("foo") )

```c
        {
        InitIFF (iff, IFFF_FSEEK | IFFF_RSEEK, &mystreamhook);
        }
```

---

## See Also

- [InitIFF — iffparse.library](../autodocs/iffparse.library.md#initiff)
