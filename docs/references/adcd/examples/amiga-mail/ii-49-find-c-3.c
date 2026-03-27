/* Source: ADCD 2.1
 * Section: ii-49-find-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-49-find-c.md
 */

    /* Get a lock on the start directory and make it the current directory */
    if (sourcelock = Lock(source, SHARED_LOCK))
    {
      olddirlock = CurrentDir(sourcelock);

      if (excontrol = AllocDosObject(DOS_EXALLCONTROL, NULL))
      {

        do
        {
          /* Get both file name and type to support FILES/DIRS kewords */
          exmore = ExAll(sourcelock, buffer, BUFFERSIZE, ED_TYPE, excontrol);
          error = IoErr();
          if ((exmore == NULL && (error != ERROR_NO_MORE_ENTRIES)))
          {
            PrintFault(error, source);
            break;
          }
          if (excontrol->eac_Entries == 0)
            continue;

          ead = buffer;
          do
          {

            /* Check for CTRL-C */
            if (SetSignal(0L, SIGBREAKF_CTRL_C) & SIGBREAKF_CTRL_C)
            {
              error = ERROR_BREAK;
              PrintFault(error, NULL);
              exmore = FALSE;
              break;
            }

            /*
             * Check if this one matches. If it does see if it is of the right type.
             */
            if (MatchPatternNoCase(fc->fc_Parsebuffer, ead->ed_Name))
            {
              if ((ead->ed_Type < 0 && fc->fc_Dirs == FALSE)
                  || (ead->ed_Type > 0 && fc->fc_Files == FALSE))
              {
                /* It is. Lock it and get the fully qualified file name */
                if (namelock = Lock(ead->ed_Name, SHARED_LOCK))
                {
                  if ((NameFromLock(namelock,
                                    fc->fc_Namebuffer,
                                    fc->fc_Namelength)) == DOSTRUE)
                  {
                    vargs[0] = (LONG) fc->fc_Namebuffer;
                    VFPrintf(Output(), "%s\n", vargs);
                  }
                  else
                  {
                    error = IoErr();
                    PrintFault(error, ead->ed_Name);
                  }
                  UnLock(namelock);
                }
                else
                {
                  error = IoErr();
                  PrintFault(error, ead->ed_Name);
                }
              }
            }

            /*
             * If the ALL keyword is used and this is a directory, step in it by
             * calling this function recursively.
             */
            if (ead->ed_Type > 0 && fc->fc_All)
            {
              error = ScanDirectory(fc, ead->ed_Name);
              if (error != 0)
              {
                exmore = FALSE;
                break;
              }
            }
            ead = ead->ed_Next;
          } while (ead);
        } while (exmore);

        FreeDosObject(DOS_EXALLCONTROL, excontrol);

      }
      else
        error = ERROR_NO_FREE_STORE;

      CurrentDir(olddirlock);
      UnLock(sourcelock);
    }
    else
    {
      error = IoErr();
      PrintFault(error, source);
    }
    FreeMem(buffer, BUFFERSIZE);
