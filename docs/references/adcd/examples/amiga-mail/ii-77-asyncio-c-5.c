/* Source: ADCD 2.1
 * Section: ii-77-asyncio-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-77-asyncio-c.md
 */

    totalBytes = 0;

    /* if we need more bytes than there are in the current buffer, enter the
     * read loop
     */

    while (numBytes > file->af_BytesLeft)
    {
        /* this takes care of NIL: */
        if (!file->af_Handler)
            return(0);

        WaitPacket(file);

        bytesArrived = file->af_Packet.sp_Pkt.dp_Res1;
        if (bytesArrived <= 0)
        {
            /* error, get out of here */
            SetIoErr(file->af_Packet.sp_Pkt.dp_Res2);
            return(-1);
        }

        /* enable this section of code if you want special processing for
         * reads bigger than the buffer size
         */
