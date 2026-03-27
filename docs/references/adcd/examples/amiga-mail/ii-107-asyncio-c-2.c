/* Source: ADCD 2.1
 * Section: ii-107-asyncio-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-107-asyncio-c.md
 */

    handle = NULL;
    file   = NULL;
    lock   = NULL;

    if (accessMode == MODE_READ)
    {
        if (handle = Open(fileName,MODE_OLDFILE))
            lock = DupLockFromFH(handle);
    }
    else
    {
        if (accessMode == MODE_WRITE)
        {
            handle = Open(fileName,MODE_NEWFILE);
        }
        else if (accessMode == MODE_APPEND)
        {
            /* in append mode, we open for writing, and then seek to the
             * end of the file. That way, the initial write will happen at
             * the end of the file, thus extending it
             */

            if (handle = Open(fileName,MODE_READWRITE))
            {
                if (Seek(handle,0,OFFSET_END) < 0)
                {
                    Close(handle);
                    handle = NULL;
                }
            }
        }

        /* we want a lock on the same device as where the file is. We can't
         * use DupLockFromFH() for a write-mode file though. So we get sneaky
         * and get a lock on the parent of the file
         */
        if (handle)
            lock = ParentOfFH(handle);
    }

    if (handle)
    {
        /* if it was possible to obtain a lock on the same device as the
         * file we're working on, get the block size of that device and
         * round up our buffer size to be a multiple of the block size.
         * This maximizes DMA efficiency.
         */

        blockSize = 512;
        if (lock)
        {
            if (Info(lock,infoData))
            {
                blockSize = infoData->id_BytesPerBlock;
                bufferSize =
                    (((bufferSize + blockSize - 1) / blockSize) * blockSize) * 2;
            }
            UnLock(lock);
        }

        /* now allocate the ASyncFile structure, as well as the read buffers.
         * Add 15 bytes to the total size in order to allow for later
         * quad-longword alignement of the buffers
         */

        if (file = AllocVec(sizeof(struct AsyncFile) + bufferSize + 15,MEMF_ANY))
        {
            file->af_File      = handle;
            file->af_ReadMode  = (accessMode == MODE_READ);
            file->af_BlockSize = blockSize;

            /* initialize the ASyncFile structure. We do as much as we can here,
             * in order to avoid doing it in more critical sections
             *
             * Note how the two buffers used are quad-longword aligned. This
             * helps performance on 68040 systems with copyback cache. Aligning
             * the data avoids a nasty side-effect of the 040 caches on DMA.
             * Not aligning the data causes the device driver to have to do
             * some magic to avoid the cache problem. This magic will generally
             * involve flushing the CPU caches. This is very costly on an 040.
             * Aligning things avoids the need for magic, at the cost of at
             * most 15 bytes of ram.
             */

            fh                     = BADDR(file->af_File);
            file->af_Handler       = fh->fh_Type;
            file->af_BufferSize    = bufferSize / 2;
            file->af_Buffers[0]
                = (APTR)(((ULONG)file + sizeof(struct AsyncFile) + 15) & 0xfffffff0);
            file->af_Buffers[1]
                = (APTR)((ULONG)file->af_Buffers[0] + file->af_BufferSize);
            file->af_Offset        = file->af_Buffers[0];
            file->af_CurrentBuf    = 0;
            file->af_SeekOffset    = 0;
            file->af_PacketPending = FALSE;

            /* this is the port used to get the packets we send out back.
             * It is initialized to PA_IGNORE, which means that no signal is
             * generated when a message comes in to the port. The signal bit
             * number is initialized to SIGB_SINGLE, which is the special bit
             * that can be used for one-shot signalling. The signal will never
             * be set, since the port is of type PA_IGNORE. We'll change the
             * type of the port later on to PA_SIGNAL whenever we need to wait
             * for a message to come in.
             *
             * The trick used here avoids the need to allocate an extra signal
             * bit for the port. It is quite efficient.
             */

            file->af_PacketPort.mp_MsgList.lh_Head
                = (struct Node *)&file->af_PacketPort.mp_MsgList.lh_Tail;
            file->af_PacketPort.mp_MsgList.lh_Tail     = NULL;
            file->af_PacketPort.mp_MsgList.lh_TailPred
                = (struct Node *)&file->af_PacketPort.mp_MsgList.lh_Head;
            file->af_PacketPort.mp_Node.ln_Type        = NT_MSGPORT;
            file->af_PacketPort.mp_Flags               = PA_IGNORE;
            file->af_PacketPort.mp_SigBit              = SIGB_SINGLE;
            file->af_PacketPort.mp_SigTask             = FindTask(NULL);

            file->af_Packet.sp_Pkt.dp_Link          = &file->af_Packet.sp_Msg;
            file->af_Packet.sp_Pkt.dp_Arg1          = fh->fh_Arg1;
            file->af_Packet.sp_Pkt.dp_Arg3          = file->af_BufferSize;
            file->af_Packet.sp_Pkt.dp_Res1          = 0;
            file->af_Packet.sp_Pkt.dp_Res2          = 0;
            file->af_Packet.sp_Msg.mn_Node.ln_Name  = (STRPTR)&file->af_Packet.sp_Pkt;
            file->af_Packet.sp_Msg.mn_Node.ln_Type  = NT_MESSAGE;
            file->af_Packet.sp_Msg.mn_Length        = sizeof(struct StandardPacket);

            if (accessMode == MODE_READ)
            {
                /* if we are in read mode, send out the first read packet to
                 * the file system. While the application is getting ready to
                 * read data, the file system will happily fill in this buffer
                 * with DMA transfers, so that by the time the application
                 * needs the data, it will be in the buffer waiting
                 */

                file->af_Packet.sp_Pkt.dp_Type = ACTION_READ;
                file->af_BytesLeft             = 0;
                if (file->af_Handler)
                    SendPacket(file,file->af_Buffers[0]);
            }
            else
            {
                file->af_Packet.sp_Pkt.dp_Type = ACTION_WRITE;
                file->af_BytesLeft             = file->af_BufferSize;
            }
        }
        else
        {
            Close(handle);
        }
    }

    return(file);
