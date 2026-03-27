---
title: Devices/iffp/iff.h
manual: devices
chapter: devices
section: devices-iffp-iff-h
functions: []
libraries: []
---

# Devices/iffp/iff.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 *
 * iff.h:	General Definitions for IFFParse modules
 *
 * 6/27/91
 */

#ifndef IFFP_IFF_H
#define IFFP_IFF_H

#include "iffp/compiler.h"

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_MEMORY_H
#include <exec/memory.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif
#ifndef LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MYDEBUG_H
#include "iffp/debug.h"
#endif

#ifndef NO_PROTOS
#include <clib/exec_protos.h>
#include <clib/iffparse_protos.h>
#endif

#ifndef MAX
#define	MAX(a,b)	((a) > (b) ? (a) : (b))
#endif
#ifndef MIN
#define	MIN(a,b)	((a) < (b) ? (a) : (b))
#endif
#ifndef ABS
#define	ABS(x)		((x) < 0 ? -(x) : (x))
#endif


#define CkErr(expression)  {if (!error) error = (expression);}
#define ChunkMoreBytes(cn)	(cn->cn_Size - cn->cn_Scan)
#define IS_ODD(a)		(a & 1)

#define IFF_OKAY	0L
#define	CLIENT_ERROR	1L
#define NOFILE          5L

#define message printf

/* Generic Chunk ID's we may encounter */
#define	ID_ANNO		MAKE_ID('A','N','N','O')
#define	ID_AUTH		MAKE_ID('A','U','T','H')
#define	ID_CHRS		MAKE_ID('C','H','R','S')
#define	ID_Copyright	MAKE_ID('(','c',')',' ')
#define	ID_CSET		MAKE_ID('C','S','E','T')
#define	ID_FVER		MAKE_ID('F','V','E','R')
#define	ID_NAME		MAKE_ID('N','A','M','E')
#define ID_TEXT		MAKE_ID('T','E','X','T')
#define ID_BODY		MAKE_ID('B','O','D','Y')


/* Used to keep track of allocated IFFHandle, and whether file is
 * clipboard or not, filename, copied chunks, etc.
 * This structure is included in the beginning of every
 * form-specific info structure used by the example modules.
 */
struct ParseInfo {
	/* general parse.c related */
	struct  IFFHandle *iff;		/* to be alloc'd with AllocIFF */
	UBYTE	*filename;		/* current filename of this ui */
	LONG	*propchks;		/* properties to get */
	LONG	*collectchks;		/* properties to collect */
	LONG	*stopchks;		/* stop on these (like BODY) */
	BOOL    opened;			/* this iff has been opened */
	BOOL	clipboard;		/* file is clipboard */
	BOOL	hunt;			/* we are parsing a complex file */
	BOOL	Reserved1;		/* must be zero for now */

	/* for copychunks.c - for read/modify/write programs
	 * and programs that need to keep parsed chunk info
	 * around after closing file.
	 * Deallocated by freechunklist();
	 */
	struct Chunk *copiedchunks;

	/* application may hang its own list of new chunks here
	 * just to keep it with the frame.
	 */
	struct Chunk *newchunks;

	ULONG	Reserved[8];
	};


/*
 * Used by some modules to save or pass a singly linked list of chunks
 */
struct Chunk {
	struct  Chunk *ch_Next;
	long	ch_Type;
	long	ch_ID;
```c
        long    ch_Size;
        void    *ch_Data;
```
};


#ifndef NO_PROTOS
/* parse.c */
LONG openifile(struct ParseInfo *,UBYTE *,ULONG);
void closeifile(struct ParseInfo *);
LONG parseifile(struct ParseInfo *,
		LONG, LONG, LONG *, LONG *, LONG *);
LONG getcontext(struct IFFHandle *);
LONG nextcontext(struct IFFHandle *);
LONG currentchunkis(struct IFFHandle *, LONG type, LONG id);
LONG contextis(struct IFFHandle *, LONG type, LONG id);
UBYTE *findpropdata(struct IFFHandle *iff, LONG type, LONG id);
void initiffasstdio(struct IFFHandle *);
UBYTE *IFFerr(LONG);
LONG chkcnt(LONG *);
long PutCk(struct IFFHandle *iff, long id, long size, void *data);

/* copychunks.c */
struct Chunk *copychunks(struct IFFHandle *iff,
```c
                 LONG *propchks, LONG *collectchks, ULONG memtype);
```
void freechunklist(struct Chunk *first);
struct Chunk *findchunk(struct Chunk *first, long type, long id);
long writechunklist(struct IFFHandle *iff, struct Chunk *first);
#endif /* NO_PROTOS */

#endif /* IFFP_IFF_H */

