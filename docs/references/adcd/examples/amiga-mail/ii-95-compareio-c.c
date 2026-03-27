/* Source: ADCD 2.1
 * Section: ii-95-compareio-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-95-compareio-c.md
 */

    if (results = Open("*", MODE_NEWFILE)) /* This is for printing the results.      */
    {                                      /* Since the example is already using the */
                                           /* standard I/O channels for its own      */
                                           /* purposes, there needs to be a separate */
                                           /* channel to output the results.         */
      if (!OpenDevice(TIMERNAME, UNIT_MICROHZ, &timer_io, 0L))
      {
        TimerBase = (struct Library *)timer_io.tr_node.io_Device;

        if (myport = CreateMsgPort())
        {
          in_start  = Input();  /* Need to hold on to input and output so no one can */
          out_start = Output(); /* change them while this example is using them.     */
          if (in = (struct FileHandle *)BADDR(in_start))
          {
            if (out = (struct FileHandle *)BADDR(out_start))
            {
              if (sp_read = AllocDosObject(DOS_STDPKT, NULL))
              {
                if (sp_write = AllocDosObject(DOS_STDPKT, NULL))
                {
                       /* When AllocDosObject() allocates a StandardPacket, it takes */
                       /* care of linking together the Message and DosPacket.        */
                       /* AllocDosObject() points the DosPacket's dp_Link field at   */
                       /* the StandardPacket's Message structure.  It also points    */
                       /* the Message's mn_Node.ln_Name field at the DosPacket:      */
                       /*                 sp_read->dp_Link = sp_Msg;                 */
                       /*                 sp_Msg->mn_Node.ln_Name = (STRPTR)sp_read; */

                  sp_read->dp_Type = ACTION_READ;   /* Fill out ACTION_READ packet.  */
                  sp_read->dp_Arg1 = in->fh_Arg1;

                  sp_write->dp_Type = ACTION_WRITE; /* Fill out ACTION_WRITE packet. */
                  sp_write->dp_Arg1 = out->fh_Arg1;

                  VFPrintf(results, "\n      Method     Seconds   Micros\n", NULL);
                  VFPrintf(results,   "   ------------  -------   ------\n", NULL);

                  GetSysTime(&time_start);
                  if (AsyncLoop())
                  {
                    GetSysTime(&time_finish);
                    SubTime(&time_finish, &time_start);
                    vfprintfargs[0] = time_finish.tv_secs;
                    vfprintfargs[1] = time_finish.tv_micro;
                    VFPrintf(results,
                             "   Asynchronous:  %3ld     %7ld\n", &vfprintfargs[0]);

                    GetSysTime(&time_start);
                    if (SyncLoop())
                    {
                      GetSysTime(&time_finish);
                      SubTime(&time_finish, &time_start);
                      vfprintfargs[0] = time_finish.tv_secs;
                      vfprintfargs[1] = time_finish.tv_micro;
                      VFPrintf(results,
                               "    Synchronous:  %3ld     %7ld\n", &vfprintfargs[0]);
                    }
                    else
                      VFPrintf(results, "         *******  Stop  ******\n", NULL);
                  }
                  else
                    VFPrintf(results, "         *******  Stop  ******\n", NULL);


                  FreeDosObject(DOS_STDPKT, sp_write);
                }
                FreeDosObject(DOS_STDPKT, sp_read);
              }
            }
          }
          DeleteMsgPort(myport);
        }
        CloseLibrary(TimerBase);
      }
      Close(results);
    }
