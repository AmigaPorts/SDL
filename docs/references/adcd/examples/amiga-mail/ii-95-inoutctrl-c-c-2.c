/* Source: ADCD 2.1
 * Section: ii-95-inoutctrl-c-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-95-inoutctrl-c-c.md
 */

    do                                   /*      Wait for the ACTION_READ to return. */
    {
      signals = Wait(sigmask);           /*          Wait for port signal or CTRL-C. */

      if (signals & portsignal)          /* If a message arrived at the port, ...    */
      {
        while (mysp = (struct StandardPacket *)GetMsg(myport)) /* ...empty the port. */
        {
                          /* If this message is the ACTION_READ packet, mark it as   */
                          /* no longer busy so we can use it to start another read.  */
          if (mysp->sp_Pkt.dp_Type == ACTION_READ)    sp_read_busy  = FALSE;

                          /* If this message is instead the ACTION_WRITE packet,     */
                          /* mark it as not busy.  We need to check for this because */
                          /* the WRITE_PACKET from the previous interation through   */
                          /* the loop might have come back before the ACTION_WRITE   */
                          /* from the previous interation.                           */
          else
            if (mysp->sp_Pkt.dp_Type == ACTION_WRITE) sp_write_busy = FALSE;
        }
      }

      if (signals & SIGBREAKF_CTRL_C) /* If someone hit CTRL-C, start to quit. */
      {
        done = TRUE;                      /* If the ACTION_READ is still out, try to */
        if (sp_read_busy)                 /* abort it.  As of V39, AbortPkt() does   */
          AbortPkt(in->fh_Type, sp_read); /* not do anything, so this function has   */
      }                                   /* no effect. Maybe a later release of the */
                                          /* OS will support packet aborting.        */


    } while (sp_read_busy);                   /* End of "wait for ACTION_READ" loop. */

                                          /* Get ready to send the next ACTION_READ. */
    buf = (UBYTE *)(sp_read->dp_Arg2);    /* Hold on to the important stuff from the */
    amount_read = sp_read->dp_Res1;       /* ACTION_READ we just got back so we can  */
                                          /* reuse the packet to start a new read    */
                                          /* while processing the last read's data.  */

    while (sp_write_busy)          /* Because this example only uses two buffers and */
    {                              /* the ACTION_WRITE might be using one of them,   */
                                   /* this example has to wait for an outstanding    */
                                   /* ACTION_WRITE to return before reusing the      */
                                   /* ACTION_WRITE packet's buffer.                  */
      signals = Wait(sigmask);

      if (signals & portsignal)           /*  If a message arrived at the port, ...  */
      {                                              /*          ... empty the port. */
        while (mysp = (struct StandardPacket *)GetMsg(myport))
          if (mysp->sp_Pkt.dp_Type == ACTION_WRITE) sp_write_busy = FALSE;
      }

      if (signals & SIGBREAKF_CTRL_C)     /*   If someone hit CTRL-C, start to quit. */
      {
        done = TRUE;                      /* If the ACTION_READ is still out, try to */
        if (sp_write_busy) AbortPkt(out->fh_Type, sp_write);            /* abort it. */
      }
    }

               /* Make sure the user didn't hit CTRL-C.  If the user hit CTRL-C dur- */
    if (!done) /* ing one of the "wait for packet" loops, done == TRUE.  Notice that */
    {          /* this example does not actually break for the CTRL-C until after it */
               /* gets back both packets.                                            */

               /* This tests the return values from the ACTION_READ and ACTION_WRITE */
               /* packets.  The ACTION_READ packet returns the number of bytes it    */
               /* read in dp_Res1, which was copied earlier into amount_read. If it  */
               /* is 0, the read packet found the EOF.  If it is negative, there was */
               /* an error.  In the case of ACTION_WRITE, an error occurs if the     */
               /* number of bytes that ACTION_WRITE was supposed to write (Arg3)     */
               /* does not match the actual number it wrote, which ACTION_WRITE re-  */
               /* turns in Res1.  This test is the reason dp_Res1 and dp_Arg3 were   */
               /* set to zero when the ACTION_WRITE packet was set up in main().     */
      if ((amount_read > 0) && (sp_write->dp_Res1 == sp_write->dp_Arg3))
      {
        sp_read->dp_Arg2 = sp_write->dp_Arg2;  /* ACTION_WRITE is finished with its  */
                                               /* buffer, use it in the next read.   */

        SendPkt(sp_read, in->fh_Type, myport); /* Send the next ACTION_READ and mark */
        sp_read_busy = TRUE;                   /* the ACTION_READ as busy.           */

        /* Process Buffer.  This example doesn't do anything with the data from the  */
        /* last ACTION_READ, it just passes it on to the STDOUT handler.             */


        sp_write->dp_Arg2 = (LONG)buf;         /*    Set up the ACTION_WRITE packet. */
        sp_write->dp_Arg3 = amount_read;
        SendPkt(sp_write, out->fh_Type, myport);   /* Send the next ACTION_WRITE and */
        sp_write_busy = TRUE;                      /* mark the ACTION_WRITE as busy. */
      }
      else                             /* A packet returned with a failure, so quit. */
        done = TRUE;
    }
