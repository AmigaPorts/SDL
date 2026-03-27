/* Source: ADCD 2.1
 * Section: ii-107-asyncio-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-107-asyncio-c.md
 */

    totalBytes = 0;

    /* if we need more bytes than there are in the current buffer, enter the
     * read loop
     */

    while (numBytes > file->af_BytesLeft)
    {
        /* drain buffer */
        CopyMem(file->af_Offset,buffer,file->af_BytesLeft);

        numBytes           -= file->af_BytesLeft;
        buffer              = (APTR)((ULONG)buffer + file->af_BytesLeft);
        totalBytes         += file->af_BytesLeft;
        file->af_BytesLeft  = 0;

        bytesArrived = WaitPacket(file);
        if (bytesArrived <= 0)
        {
            if (bytesArrived == 0)
                return(totalBytes);

            return(-1);
        }

        /* ask that the buffer be filled */
        SendPacket(file,file->af_Buffers[1-file->af_CurrentBuf]);

        if (file->af_SeekOffset > bytesArrived)
            file->af_SeekOffset = bytesArrived;

        file->af_Offset      = (APTR)((ULONG)file->af_Buffers[file->af_CurrentBuf]
                                   + file->af_SeekOffset);
        file->af_CurrentBuf  = 1 - file->af_CurrentBuf;
        file->af_BytesLeft   = bytesArrived - file->af_SeekOffset;
        file->af_SeekOffset  = 0;
    }

    CopyMem(file->af_Offset,buffer,numBytes);
    file->af_BytesLeft -= numBytes;
    file->af_Offset     = (APTR)((ULONG)file->af_Offset + numBytes);

    return (totalBytes + numBytes);
