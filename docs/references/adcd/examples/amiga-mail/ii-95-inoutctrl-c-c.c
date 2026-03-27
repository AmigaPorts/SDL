/* Source: ADCD 2.1
 * Section: ii-95-inoutctrl-c-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-95-inoutctrl-c-c.md
 */

    if (myport = CreateMsgPort())
    {
      if (in = (struct FileHandle *)BADDR(Input()))        /* Need file handle to    */
      {                                                    /* get to Handler process */
        if (out = (struct FileHandle *)BADDR(Output()))
        {
          if (sp_read = AllocDosObject(DOS_STDPKT, NULL))    /* Allocate two         */
          {                                                  /* StandardPackets: one */
            if (sp_write = AllocDosObject(DOS_STDPKT, NULL)) /* for reading, and one */
            {                                                /* for writing. */

              sp_read->dp_Type = ACTION_READ;    /* Fill out the ACTION_READ packet. */
              sp_read->dp_Arg1 = in->fh_Arg1;
              sp_read->dp_Arg2 = (LONG)buf1;     /* The buffer to fill in.           */
              sp_read->dp_Arg3 = BUFSIZE;        /* The size of the Arg2 buffer.     */

                       /* When AllocDosObject() allocates a StandardPacket, it takes */
                       /* care of linking together the Message and DosPacket.        */
                       /* AllocDosObject() points the DosPacket's dp_Link field at   */
                       /* the StandardPacket's Message structure.  It also points    */
                       /* the Message's mn_Node.ln_Name field at the DosPacket:      */
                       /*                 sp_read->dp_Link = sp_Msg;                 */
                       /*                 sp_Msg->mn_Node.ln_Name = (STRPTR)sp_read; */


              if (!((out->fh_Arg1) && (in->fh_Arg1)))     /* Don't bother if in or   */
                return;                                   /*          out uses NIL:  */

              SendPkt(sp_read, in->fh_Type, myport);   /* Send initial read request. */

              portsignal = 1L<<myport->mp_SigBit;          /* Record the signal bits */
              sigmask    = SIGBREAKF_CTRL_C | portsignal;  /*         for later use. */

              sp_write->dp_Type = ACTION_WRITE; /* Fill out the ACTION_WRITE packet. */
              sp_write->dp_Arg1 = out->fh_Arg1;
              sp_write->dp_Arg2 = (LONG)buf2;  /* Arg2 points to the buffer to write */
              sp_write->dp_Arg3 = 0L;          /* out.  At first glance, it might    */
              sp_write->dp_Res1 = 0L;          /* seem odd to bother setting Arg2    */
                                      /* when the program hasn't read anything yet.  */
                                      /* This is to set up for the main loop.  The   */
                                      /* main loop swaps the ACTION_READ buffer with */
                                      /* the ACTION_WRITE buffer when it receives    */
                                      /* a completed read.  Likewise, dp_Arg3 and    */
                                      /* dp_Res1 are set to make the ACTION_READ     */
                                      /* look like it has a valid return value so    */
                                      /* main loop won't fail the first time through */
                                      /* the loop.                                   */
              MainLoop();
              FreeDosObject(DOS_STDPKT, sp_write);
            }
            FreeDosObject(DOS_STDPKT, sp_read);
          }
        }
      }
      DeleteMsgPort(myport);
    }
