/* Source: ADCD 2.1
 * Section: ii-107-asyncio-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-107-asyncio-c.md
 */

    if (file->af_PacketPending)
    {
        /* mark packet as no longer pending since we are going to get it */
        file->af_PacketPending = FALSE;

        while (TRUE)
        {
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

            bytes = file->af_Packet.sp_Pkt.dp_Res1;
            if (bytes >= 0)
            {
                /* packet didn't report an error, so bye... */
                return(bytes);
            }

            /* see if the user wants to try again... */
            if (ErrorReport(file->af_Packet.sp_Pkt.dp_Res2,
                            REPORT_STREAM,
                            file->af_File,NULL))
                return(-1);

            /* user wants to try again, resend the packet */
            SendPacket(file,file->af_Buffers[file->af_CurrentBuf]);
        }
    }

    /* last packet's error code, or 0 if packet was never sent */
    SetIoErr(file->af_Packet.sp_Pkt.dp_Res2);

    return(file->af_Packet.sp_Pkt.dp_Res1);
