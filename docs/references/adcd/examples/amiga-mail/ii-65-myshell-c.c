/* Source: ADCD 2.1
 * Section: ii-65-myshell-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-65-myshell-c.md
 */

    /* First, get the packet that the newshell segment sends. */
    globals.mypacket = WaitPkt();
    globals.myprocess = (struct Process *) FindTask(NULL);

    /*
     * Some arcane magic here for the UserShell.  We have to look at this
     * process' array of Segment pointers.  If entry 4 in the array is NULL, we
     * have to move entry 3 to entry 4 and NULL entry 4.  This is because entry
     * 3 will be used to store the seglist pointer for each program this shell
     * runs.
     */
    segment = (BPTR *) BADDR(globals.myprocess->pr_SegList);
    if (!segment[4])
    {
      segment[4] = segment[3];
      segment[3] = NULL;
    }
    /*
     * The packet that newshell sends tells us how the shell was invoked. The
     * dp_Res1 and dp_Res2 fields of the packet structure represent,
     * respectively, the high order bit and low order bit of a two-bit
     * bitfield.  The following line of code will turn these values into a
     * value from 0 to 3:
     */
    shelltype = (globals.mypacket->dp_Res1 == 0 ? 0 : 2) |
      (globals.mypacket->dp_Res2 == 0 ? 0 : 1);

    /*
     * at the moment, only the values 0 and 2 are defined.  Type 0 is for Run,
     * Execute(), and System().  Type 2 is for NewShell and NewCli.
     */
    if ((shelltype == 2) || (shelltype == 0))
    {

      /*
       * These two functions CliInitNewcli() and CliInitRun() take care setting
       * up the shell's CommandLineInterface structure (current directories,
       * paths, input streams...) using the secret startup packet we got
       * earlier.  They differ slightly in their setup based on the shell type.
       * The exact workings of these functions is private and personal to DOS,
       * and is subject to change. If you are wondering what exactly these
       * functions do, don't worry about it.  That would also be bad.
       */
      if (shelltype == 0)
        globals.fn = CliInitRun(globals.mypacket);
      else

        /*
         * CliInitNewCli() handles the shell startup file (default is
         * s:Shell-startup) and stuffs a filehandle to it into
         * globals.mycli->cli_CurrentInput.
         */
        globals.fn = CliInitNewcli(globals.mypacket);

      /*
       * Definitions for the values of globals.fn:
       *     Bit 31     Set to indicate flags are valid
       *     Bit  3     Set to indicate asynch system call
       *     Bit  2     Set if this is a System() call
       *     Bit  1     Set if user provided input stream
       *     Bit  0     Set if RUN provided output stream
       */

      /*
       * If the high bit of globals.fn is clear, check IoErr() to see if it
       * points to this process.  If it does, there was an error with the
       * CliInitXxx... function.  On an error, clean up and exit.  You won't
       * have to return the packet if there was an error because the
       * CliInitXxxx function will take care of that.
       */
      if ((globals.fn & 0x80000000) == 0)       /* Is high bit clear? */
        if ((struct Process *) IoErr() == globals.myprocess)   /* is there an error? */
          error = RETURN_FAIL;
        else if (shelltype == 0)
        {
          ReplyPkt(globals.mypacket,
                   globals.mypacket->dp_Res1,
                   globals.mypacket->dp_Res2);
          globals.mypacket = NULL;
        }
      if (error != RETURN_FAIL)
      {

        /*
         * OK, no error.  If this shell was invoked via NewShell or NewCLI
         * (shelltype == 2), or if this is an asynchronous System() initiated
         * shell, return the startup message.   Although this example doesn't
         * do it, if shelltype == 0, you can wait to reply the packet until you
         * try to LoadSeg() your first command (to avoid disk gronking). When
         * you use ReplyPkt() to reply the packet, use it like it appears below
         * to avoid losing error codes set up by CliInitXxx.
         */
        if (((globals.fn & 0x8000000C) == 0x8000000C) || (shelltype == 2))
        {
          ReplyPkt(globals.mypacket,
                   globals.mypacket->dp_Res1,
                   globals.mypacket->dp_Res2);
          globals.mypacket = NULL;
        }

        if (globals.mycli = Cli())
        {
          /* Set up local shell variables and any custom set up here */
          globals.mycli->cli_ReturnCode = 0;
          globals.mycli->cli_Result2 = 0;
          globals.myprocess->pr_HomeDir = NULL;

          /* Ready to start processing commands */
          error = mainshellloop(ml);
          if (globals.fn < 0)          /* if we got valid flags from
                                        * CliInitXxxx (High bit of fn is set). */
          {
            Flush(Output());
            /* if user DID NOT provide input stream, close standardinput */
            if ((globals.fn & 2) == 0)
              Close(globals.mycli->cli_StandardInput);

            /* if RUN provided output stream, close it */
            if ((globals.fn & 1) == 1)
            {
              Flush(globals.mycli->cli_StandardOutput);
              Close(globals.mycli->cli_StandardOutput);
            }

            /* If we didn't send the packet back yet, send it back */
            if (globals.mypacket)
              ReplyPkt(globals.mypacket, error, globals.mypacket->dp_Res2);
          }
          else
            /*
             * the flags weren't valid so close the Standard I/O handles if
             * they still exist.
             */
          {
            if (globals.mycli->cli_StandardOutput)
            {
              Flush(globals.mycli->cli_StandardOutput);
              Close(globals.mycli->cli_StandardOutput);
            }
            if (globals.mycli->cli_StandardInput)
            {
              Flush(globals.mycli->cli_StandardInput);
              Close(globals.mycli->cli_StandardInput);
            }
          }
          /* release the process' lock on the current directory */
          UnLock(globals.myprocess->pr_CurrentDir);
        }
        else
          error = RETURN_FAIL;         /* I have a NULL CLI! */
      }
    }
    else
      /* shelltype != 0 or 2 */
    {
      error = RETURN_FAIL;
      ReplyPkt(globals.mypacket,
               globals.mypacket->dp_Res1,
               globals.mypacket->dp_Res2);
    }
    CloseLibrary(DOSBase);
