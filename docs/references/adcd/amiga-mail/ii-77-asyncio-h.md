---
title: II-77/ASyncIO.h
manual: amiga-mail
chapter: amiga-mail
section: ii-77-asyncio-h
functions: []
libraries: []
---

# II-77/ASyncIO.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* ASyncIO.h - Header File for ASyncIO.c */

#ifndef ASYNCIO_H
#define ASYNCIO_H


/*****************************************************************************/


#include <exec/types.h>
#include <exec/ports.h>
#include <dos/dos.h>


/*****************************************************************************/


struct AsyncFile
{
```c
    BPTR                  af_File;
    struct MsgPort       *af_Handler;
    APTR                  af_Offset;
    LONG                  af_BytesLeft;
    ULONG                 af_BufferSize;
    APTR                  af_Buffers[2];
    struct StandardPacket af_Packet;
    struct MsgPort        af_PacketPort;
    ULONG                 af_CurrentBuf;
    UBYTE                 af_PacketPending;
    UBYTE                 af_ReadMode;
```
};


/*****************************************************************************/


#define MODE_READ   0  /* read an existing file                             */
#define MODE_WRITE  1  /* create a new file, delete existing file if needed */
#define MODE_APPEND 2  /* append to end of existing file, or create new     */


/*****************************************************************************/


struct AsyncFile *OpenAsync(STRPTR fileName, UBYTE mode, LONG bufferSize);
LONG CloseAsync(struct AsyncFile *file);
LONG ReadAsync(struct AsyncFile *file, APTR buf, LONG numBytes);
LONG ReadCharAsync(struct AsyncFile *file);
LONG WriteAsync(struct AsyncFile *file, APTR buf, LONG numBytes);
LONG WriteCharAsync(struct AsyncFile *file, char ch);


/*****************************************************************************/


#endif /* ASYNCIO_H */

