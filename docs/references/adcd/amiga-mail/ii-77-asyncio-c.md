---
title: II-77/ASyncIO.c
manual: amiga-mail
chapter: amiga-mail
section: ii-77-asyncio-c
functions: [GetMsg, IoErr, Remove]
libraries: [dos.library, exec.library]
---

# II-77/ASyncIO.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* ASyncIO.c - Execute me to compile with SAS/C 6.56
sc NMINC STRMERGE NOSTKCHK IGNORE=73 asyncio.c
quit
*/

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

/*****************************************************************************/

static VOID SendAsync(struct AsyncFile *file, APTR arg2)
{
```c
    /* send out an async packet to the file system. */

    file->af_Packet.sp_Pkt.dp_Port = &file->af_PacketPort;
    file->af_Packet.sp_Pkt.dp_Arg2 = (LONG)arg2;
    PutMsg(file->af_Handler, &file->af_Packet.sp_Msg);
    file->af_PacketPending = TRUE;
```
}

/*****************************************************************************/


static VOID WaitPacket(struct AsyncFile *file)
{
```c
    /* This enables signalling when a packet comes back to the port */
    file->af_PacketPort.mp_Flags = PA_SIGNAL;

    /* Wait for the packet to come back, and remove it from the message
     * list. Since we know no other packets can come in to the port, we can
     * safely use Remove() instead of GetMsg(). If other packets could come in,
     * we would have to use GetMsg(), which correctly arbitrates access in such
     * a case
     */
    Remove((struct Node *)WaitPort(&file->af_PacketPort));

    /* set the port type back to PA_IGNORE so we won't be bothered with
     * spurious signals
     */
    file->af_PacketPort.mp_Flags = PA_IGNORE;

    /* packet is no longer pending, we got it */
    file->af_PacketPending = FALSE;
```
}

/*****************************************************************************/

struct AsyncFile *OpenAsync(STRPTR fileName, UBYTE mode, LONG bufferSize)
{
struct AsyncFile  *file;
struct FileHandle *fh;

```c
    /* The buffer size is rounded to a multiple of 32 bytes. This will make
     * DMA as fast as can be
     */

    bufferSize = (bufferSize + 31) & 0xffffffe0;

    /* now allocate the ASyncFile structure, as well as the read buffer. Add
     * 15 bytes to the total size in order to allow for later quad-longword
     * alignement of the buffers
     */

    if (file = AllocVec(sizeof(struct AsyncFile) + bufferSize + 15,
                        MEMF_ANY|MEMF_CLEAR))
    {
        if (mode == MODE_READ)
        {
            file->af_File     = Open(fileName,MODE_OLDFILE);
            file->af_ReadMode = TRUE;
        }
        else if (mode == MODE_WRITE)
        {
            file->af_File = Open(fileName,MODE_NEWFILE);
        }
        else if (mode == MODE_APPEND)
        {
            /* in append mode, we open for writing, and then seek to the
             * end of the file. That way, the initial write will happen at
             * the end of the file, thus extending it
             */

            if (file->af_File = Open(fileName,MODE_READWRITE))
            {
                if (Seek(file->af_File,0,OFFSET_END) < 0)
                {
                    Close(file->af_File);
                    file->af_File = NULL;
                }
            }
        }

        if (!file->af_File)
        {
            /* file didn't open, free stuff and leave */
            FreeVec(file);
            return(NULL);
        }

        /* initialize the ASyncFile structure. We do as much as we can here,
         * in order to avoid doing it in more critical sections
         *
         * Note how the two buffers used are quad-longword aligned. This helps
         * performance on 68040 systems with copyback cache. Aligning the data
         * avoids a nasty side-effect of the 040 caches on DMA. Not aligning
         * the data causes the device driver to have to do some magic to avoid
         * the cache problem. This magic will generally involve flushing the
         * CPU caches. This is very costly on an 040. Aligning things avoids
         * the need for magic, at the cost of at most 15 bytes of ram.
         */

        fh                  = BADDR(file->af_File);
        file->af_Handler    = fh->fh_Type;
        file->af_BufferSize = bufferSize / 2;
        file->af_Buffers[0] =
                (APTR)(((ULONG)file + sizeof(struct AsyncFile) + 15) & 0xfffffff0);
        file->af_Buffers[1] =
                (APTR)((ULONG)file->af_Buffers[0] + file->af_BufferSize);
        file->af_Offset     = file->af_Buffers[0];

        /* this is the port used to get the packets we send out back.
         * It is initialized to PA_IGNORE, which means that no signal is
         * generated when a message comes in to the port. The signal bit number
         * is initialized to SIGB_SINGLE, which is the special bit that can
         * be used for one-shot signalling. The signal will never be set,
         * since the port is of type PA_IGNORE. We'll change the type of the
         * port later on to PA_SIGNAL whenever we need to wait for a message
         * to come in.
         *
         * The trick used here avoids the need to allocate an extra signal bit
         * for the port. It is quite efficient.
         */

        file->af_PacketPort.mp_MsgList.lh_Head     =
                (struct Node *)&file->af_PacketPort.mp_MsgList.lh_Tail;
        file->af_PacketPort.mp_MsgList.lh_TailPred =
                (struct Node *)&file->af_PacketPort.mp_MsgList.lh_Head;
        file->af_PacketPort.mp_Node.ln_Type        = NT_MSGPORT;
        file->af_PacketPort.mp_Flags               = PA_IGNORE;
        file->af_PacketPort.mp_SigBit              = SIGB_SINGLE;
        file->af_PacketPort.mp_SigTask             = FindTask(NULL);

        file->af_Packet.sp_Pkt.dp_Link          = &file->af_Packet.sp_Msg;
        file->af_Packet.sp_Pkt.dp_Arg1          = fh->fh_Arg1;
        file->af_Packet.sp_Pkt.dp_Arg3          = file->af_BufferSize;
        file->af_Packet.sp_Msg.mn_Node.ln_Name  = (STRPTR)&file->af_Packet.sp_Pkt;
        file->af_Packet.sp_Msg.mn_Node.ln_Type  = NT_MESSAGE;
        file->af_Packet.sp_Msg.mn_Length        = sizeof(struct StandardPacket);

        if (mode == MODE_READ)
        {
            /* if we are in read mode, send out the first read packet to the
             * file system. While the application is getting ready to read
             * data, the file system will happily fill in this buffer with
             * DMA transfer, so that by the time the application needs the data,
             * it will be in the buffer waiting
             */

            file->af_Packet.sp_Pkt.dp_Type = ACTION_READ;
            if (file->af_Handler)
                SendAsync(file,file->af_Buffers[0]);
        }
        else
        {
            file->af_Packet.sp_Pkt.dp_Type = ACTION_WRITE;
            file->af_BytesLeft             = file->af_BufferSize;
        }
    }

    return(file);
```
}

/*****************************************************************************/

LONG CloseAsync(struct AsyncFile *file)
{
LONG result;
LONG result2;

```c
    result = 0;
    if (file)
    {
        if (file->af_PacketPending)
            WaitPacket(file);

        result  = file->af_Packet.sp_Pkt.dp_Res1;
        result2 = file->af_Packet.sp_Pkt.dp_Res2;
        if (result >= 0)
        {
            if (!file->af_ReadMode)
            {
                /* this will flush out any pending data in the write buffer */
                result  = Write(file->af_File,
                          file->af_Buffers[file->af_CurrentBuf],
                          file->af_BufferSize - file->af_BytesLeft);
                result2 = IoErr();
            }
        }

        Close(file->af_File);
        FreeVec(file);

        SetIoErr(result2);
    }

    return(result);
```
}

/*****************************************************************************/

LONG ReadAsync(struct AsyncFile *file, APTR buf, LONG numBytes)
{
LONG totalBytes;
LONG bytesArrived;

```c
    totalBytes = 0;

    /* if we need more bytes than there are in the current buffer, enter the
     * read loop
     */

    while (numBytes > file->af_BytesLeft)
    {
        /* this takes care of NIL: */
        if (!file->af_Handler)
            return(0);

        WaitPacket(file);

        bytesArrived = file->af_Packet.sp_Pkt.dp_Res1;
        if (bytesArrived <= 0)
        {
            /* error, get out of here */
            SetIoErr(file->af_Packet.sp_Pkt.dp_Res2);
            return(-1);
        }

        /* enable this section of code if you want special processing for
         * reads bigger than the buffer size
         */
```
#ifdef OPTIMIZE_BIG_READS
```c
        if (numBytes > file->af_BytesLeft + bytesArrived + file->af_BufferSize)
        {
            if (file->af_BytesLeft)
            {
                CopyMem(file->af_Offset,buf,file->af_BytesLeft);

                numBytes   -= file->af_BytesLeft;
                buf         = (APTR)((ULONG)buf + file->af_BytesLeft);
                totalBytes += file->af_BytesLeft;
                file->af_BytesLeft = 0;
            }

            if (bytesArrived)
            {
                CopyMem(file->af_Buffers[file->af_CurrentBuf],buf,bytesArrived);

                numBytes   -= bytesArrived;
                buf         = (APTR)((ULONG)buf + bytesArrived);
                totalBytes += bytesArrived;
            }

            bytesArrived = Read(file->af_File,buf,numBytes);

            if (bytesArrived <= 0)
                return(-1);

            SendAsync(file,file->af_Buffers[0]);
            file->af_CurrentBuf = 0;
            file->af_BytesLeft  = 0;

            return(totalBytes + bytesArrived);
        }
```
#endif

```c
        if (file->af_BytesLeft)
        {
            CopyMem(file->af_Offset,buf,file->af_BytesLeft);

            numBytes   -= file->af_BytesLeft;
            buf         = (APTR)((ULONG)buf + file->af_BytesLeft);
            totalBytes += file->af_BytesLeft;
        }

        /* ask that the buffer be filled */
        SendAsync(file,file->af_Buffers[1-file->af_CurrentBuf]);

        file->af_Offset     = file->af_Buffers[file->af_CurrentBuf];
        file->af_CurrentBuf = 1 - file->af_CurrentBuf;
        file->af_BytesLeft  = bytesArrived;
    }

    if (numBytes)
    {
        CopyMem(file->af_Offset,buf,numBytes);
        file->af_BytesLeft -= numBytes;
        file->af_Offset     = (APTR)((ULONG)file->af_Offset + numBytes);
    }

    return (totalBytes + numBytes);
```
}

/*****************************************************************************/

LONG ReadCharAsync(struct AsyncFile *file)
{
char ch;

```c
    if (file->af_BytesLeft)
    {
        /* if there is at least a byte left in the current buffer, get it
         * directly. Also update all counters
         */

        ch = *(char *)file->af_Offset;
        file->af_BytesLeft--;
        file->af_Offset = (APTR)((ULONG)file->af_Offset + 1);

        return((LONG)ch);
    }

    /* there were no characters in the current buffer, so call the main read
     * routine. This has the effect of sending a request to the file system to
     * have the current buffer refilled. After that request is done, the
     * character is extracted for the alternate buffer, which at that point
     * becomes the "current" buffer
     */

    if (ReadAsync(file,&ch,1) > 0)
        return((LONG)ch);

    /* We couldn't read above, so fail */

    return(-1);
```
}

/*****************************************************************************/

LONG WriteAsync(struct AsyncFile *file, APTR buf, LONG numBytes)
{
LONG totalBytes;

```c
    totalBytes = 0;

    while (numBytes > file->af_BytesLeft)
    {
        /* this takes care of NIL: */
        if (!file->af_Handler)
        {
            file->af_Offset    = file->af_Buffers[file->af_CurrentBuf];
            file->af_BytesLeft = file->af_BufferSize;
            return(numBytes + totalBytes);
        }

        if (file->af_BytesLeft)
        {
            CopyMem(buf,file->af_Offset,numBytes);

            numBytes   -= file->af_BytesLeft;
            buf         = (APTR)((ULONG)buf + file->af_BytesLeft);
            totalBytes += file->af_BytesLeft;
        }

        if (file->af_PacketPending)
        {
            WaitPacket(file);

            if (file->af_Packet.sp_Pkt.dp_Res1 <= 0)
            {
                /* an error occurred, leave */
                SetIoErr(file->af_Packet.sp_Pkt.dp_Res2);
                return(-1);
            }
        }

        /* send the current buffer out to disk */
        SendAsync(file,file->af_Buffers[file->af_CurrentBuf]);

        file->af_CurrentBuf   = 1 - file->af_CurrentBuf;
        file->af_Offset       = file->af_Buffers[file->af_CurrentBuf];
        file->af_BytesLeft    = file->af_BufferSize;
    }

    if (numBytes)
    {
        CopyMem(buf,file->af_Offset,numBytes);
        file->af_BytesLeft -= numBytes;
        file->af_Offset     = (APTR)((ULONG)file->af_Offset + numBytes);
    }

    return (totalBytes + numBytes);
```
}

/*****************************************************************************/

LONG WriteCharAsync(struct AsyncFile *file, char ch)
{
```c
    if (file->af_BytesLeft)
    {
        /* if there's any room left in the current buffer, directly write
         * the byte into it, updating counters and stuff.
         */

        *(char *)file->af_Offset = ch;
        file->af_BytesLeft--;
        file->af_Offset = (APTR)((ULONG)file->af_Offset + 1);

        /* one byte written */
        return(1);
    }

    /* there was no room in the current buffer, so call the main write
     * routine. This will effectively send the current buffer out to disk,
     * wait for the other buffer to come back, and then put the byte into
     * it.
     */

    return(WriteAsync(file,&ch,1));
```
}

---

## See Also

- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [Remove — exec.library](../autodocs/exec.library.md#remove)
