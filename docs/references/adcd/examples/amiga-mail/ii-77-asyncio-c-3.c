/* Source: ADCD 2.1
 * Section: ii-77-asyncio-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-77-asyncio-c.md
 */

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
