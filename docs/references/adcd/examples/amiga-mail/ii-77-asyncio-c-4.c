/* Source: ADCD 2.1
 * Section: ii-77-asyncio-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-77-asyncio-c.md
 */

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
