/* Source: ADCD 2.1
 * Section: ii-77-asyncio-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-77-asyncio-c.md
 */

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
