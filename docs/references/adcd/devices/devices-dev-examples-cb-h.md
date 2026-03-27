---
title: Devices/Dev_examples/cb.h
manual: devices
chapter: devices
section: devices-dev-examples-cb-h
functions: []
libraries: []
---

# Devices/Dev_examples/cb.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/***********************************************************************
 *
 * cb.h - Include file used by clipdemo.c, changehook_test.c and cbio.c
 *
 ***********************************************************************/

struct cbbuf {

```c
        ULONG size;     /* size of memory allocation            */
        ULONG count;    /* number of characters after stripping */
        UBYTE *mem;     /* pointer to memory containing data    */
```
};

#define MAKE_ID(a,b,c,d) ((a<<24L) | (b<<16L) | (c<<8L) | d)

#define ID_FORM MAKE_ID('F','O','R','M')
#define ID_FTXT MAKE_ID('F','T','X','T')
#define ID_CHRS MAKE_ID('C','H','R','S')

#ifdef CBIO

/* prototypes */

struct IOClipReq        *CBOpen         ( ULONG );
void                    CBClose         (struct IOClipReq *);
int                     CBWriteFTXT     (struct IOClipReq *, char *);
int                     CBQueryFTXT     (struct IOClipReq *);
struct cbbuf            *CBReadCHRS     (struct IOClipReq *);
void                    CBReadDone      (struct IOClipReq *);
void                    CBFreeBuf       (struct cbbuf *);


/* routines which are meant to be used internally by routines in cbio */

int                     WriteLong       (struct IOClipReq *, long *);
int                     ReadLong        (struct IOClipReq *, ULONG *);
struct cbbuf            *FillCBData     (struct IOClipReq *, ULONG);

#else

/* prototypes */

extern struct IOClipReq *CBOpen         ( ULONG );
extern void             CBClose         (struct IOClipReq *);
extern int              CBWriteFTXT     (struct IOClipReq *, char *);
extern int              CBQueryFTXT     (struct IOClipReq *);
extern struct cbbuf     *CBReadCHRS     (struct IOClipReq *);
extern void             CBReadDone      (struct IOClipReq *);
extern void             CBFreeBuf       (struct cbbuf *);

#endif

