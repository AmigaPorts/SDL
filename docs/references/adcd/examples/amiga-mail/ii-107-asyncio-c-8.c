/* Source: ADCD 2.1
 * Section: ii-107-asyncio-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-107-asyncio-c.md
 */

    bytesArrived = WaitPacket(file);

    if (bytesArrived < 0)
        return(-1);

    if (file->af_ReadMode)
    {
        /* figure out what the actual file position is */
        filePos = Seek(file->af_File,OFFSET_CURRENT,0);
        if (filePos < 0)
        {
            RecordSyncFailure(file);
            return(-1);
        }

        /* figure out what the caller's file position is */
        current = filePos - (file->af_BytesLeft+bytesArrived);

        /* figure out the absolute offset within the file where we must seek to */
        if (mode == MODE_CURRENT)
        {
            target = current + position;
        }
        else if (mode == MODE_START)
        {
            target = position;
        }
        else /* if (mode == MODE_END) */
        {
            if (!ExamineFH(file->af_File,fib))
            {
                RecordSyncFailure(file);
                return(-1);
            }

            target = fib->fib_Size + position;
        }

        /* figure out what range of the file is currently in our buffers */
        minBuf = current - (LONG)((ULONG)file->af_Offset -
                     (ULONG)file->af_Buffers[1 - file->af_CurrentBuf]);
        maxBuf = current + file->af_BytesLeft
                     + bytesArrived;  /* WARNING: this is one too big */

        diff = target - current;

        if ((target < minBuf) || (target >= maxBuf))
        {
            /* the target seek location isn't currently in our buffers, so
             * move the actual file pointer to the desired location, and then
             * restart the async read thing...
             */

            /* this is to keep our file reading block-aligned on the device.
             * block-aligned reads are generally quite a bit faster, so it is
             * worth the trouble to keep things aligned
             */
            roundTarget = (target / file->af_BlockSize) * file->af_BlockSize;

            if (Seek(file->af_File,roundTarget-filePos,OFFSET_CURRENT) < 0)
            {
                RecordSyncFailure(file);
                return(-1);
            }

            SendPacket(file,file->af_Buffers[0]);

            file->af_SeekOffset = target-roundTarget;
            file->af_BytesLeft  = 0;
            file->af_CurrentBuf = 0;
        }
        else if ((target < current) || (diff <= file->af_BytesLeft))
        {
            /* one of the two following things is true:
             *
             * 1. The target seek location is within the current read buffer,
             * but before the current location within the buffer. Move back
             * within the buffer and pretend we never got the pending packet,
             * just to make life easier, and faster, in the read routine.
             *
             * 2. The target seek location is ahead within the current
             * read buffer. Advance to that location. As above, pretend to
             * have never received the pending packet.
             */

            RequeuePacket(file);

            file->af_BytesLeft -= diff;
            file->af_Offset     = (APTR)((ULONG)file->af_Offset + diff);
        }
        else
        {
            /* at this point, we know the target seek location is within
             * the buffer filled in by the packet that we just received
             * at the start of this function. Throw away all the bytes in the
             * current buffer, send a packet out to get the async thing going
             * again, readjust buffer pointers to the seek location, and return
             * with a grin on your face... :-)
             */

            diff -= file->af_BytesLeft;

            SendPacket(file,file->af_Buffers[1-file->af_CurrentBuf]);

            file->af_Offset
                = (APTR)((ULONG)file->af_Buffers[file->af_CurrentBuf] + diff);
            file->af_CurrentBuf = 1 - file->af_CurrentBuf;
            file->af_BytesLeft  = bytesArrived - diff;
        }
    }
    else
    {
        if (Write(file->af_File,
                  file->af_Buffers[file->af_CurrentBuf],
                  file->af_BufferSize - file->af_BytesLeft) < 0)
        {
            RecordSyncFailure(file);
            return(-1);
        }

        /* this will unfortunately generally result in non block-aligned file
         * access. We could be sneaky and try to resync our file pos at a
         * later time, but we won't bother. Seeking in write-only files is
         * relatively rare (except when writing IFF files with unknown chunk
         * sizes, where the chunk size has to be written after the chunk data)
         */

        current = Seek(file->af_File,position,mode);

        if (current < 0)
        {
            RecordSyncFailure(file);
            return(-1);
        }

        file->af_BytesLeft  = file->af_BufferSize;
        file->af_CurrentBuf = 0;
    }

    return(current);
