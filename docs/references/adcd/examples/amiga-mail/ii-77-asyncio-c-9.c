/* Source: ADCD 2.1
 * Section: ii-77-asyncio-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-77-asyncio-c.md
 */

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
