/* Source: ADCD 2.1
 * Section: ii-77-asyncio-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-77-asyncio-c.md
 */

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
