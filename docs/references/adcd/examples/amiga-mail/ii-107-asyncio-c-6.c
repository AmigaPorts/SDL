/* Source: ADCD 2.1
 * Section: ii-107-asyncio-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-107-asyncio-c.md
 */

    totalBytes = 0;

    while (numBytes > file->af_BytesLeft)
    {
        /* this takes care of NIL: */
        if (!file->af_Handler)
        {
            file->af_Offset    = file->af_Buffers[0];
            file->af_BytesLeft = file->af_BufferSize;
            return(numBytes);
        }

        if (file->af_BytesLeft)
        {
            CopyMem(buffer,file->af_Offset,file->af_BytesLeft);

            numBytes   -= file->af_BytesLeft;
            buffer      = (APTR)((ULONG)buffer + file->af_BytesLeft);
            totalBytes += file->af_BytesLeft;
        }

        if (WaitPacket(file) < 0)
            return(-1);

        /* send the current buffer out to disk */
        SendPacket(file,file->af_Buffers[file->af_CurrentBuf]);

        file->af_CurrentBuf = 1 - file->af_CurrentBuf;
        file->af_Offset     = file->af_Buffers[file->af_CurrentBuf];
        file->af_BytesLeft  = file->af_BufferSize;
    }

    CopyMem(buffer,file->af_Offset,numBytes);
    file->af_BytesLeft -= numBytes;
    file->af_Offset     = (APTR)((ULONG)file->af_Offset + numBytes);

    return (totalBytes + numBytes);
