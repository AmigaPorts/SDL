/* Source: ADCD 2.1
 * Section: ii-49-find-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-49-find-c.md
 */

        pattern = (UBYTE *) rargs[0];

        fc->fc_Parselength = StrLen(pattern) * 3;
        if (fc->fc_Parsebuffer = AllocMem(fc->fc_Parselength, MEMF_CLEAR))
        {

          /* Make pattern uppercase for possible character classes */
          i = 0;
          while (pattern[i])
            pattern[i] = ToUpper(pattern[i++]);

          if ((ParsePatternNoCase(pattern,
                                  fc->fc_Parsebuffer,
                                  fc->fc_Parselength)) != -1)
          {

            directories = (UBYTE **) rargs[1];

            fc->fc_Files = (BOOL) rargs[2];
            fc->fc_Dirs = (BOOL) rargs[3];
            fc->fc_All = (BOOL) rargs[4];

            /*
             * Both set or cleared, clear both anyway. Easier checking later on.
             */
            if (fc->fc_Files == fc->fc_Dirs)
              fc->fc_Files = fc->fc_Dirs = FALSE;

            if (rargs[5])
              fc->fc_Namelength = *((LONG *) rargs[5]);

            if (fc->fc_Namelength < NAMEBUFFERSIZE || fc->fc_Namelength > 4096)
              fc->fc_Namelength = NAMEBUFFERSIZE;

            if (fc->fc_Namebuffer = AllocMem(fc->fc_Namelength, MEMF_CLEAR))
            {
              process = (struct Process *) FindTask(NULL);
              windowptr = process->pr_WindowPtr;
              process->pr_WindowPtr = (APTR) - 1L;

              while (*directories)
              {

                /*
                 * Check if this is a standalone assign which appears in the assign
                 * list?
                 */
                if (IsAssign(fc, *directories))
                  error = MultiScanDirectory(fc, *directories++);
                else
                  error = ScanDirectory(fc, *directories++);

                if (error != 0)
                  break;
              }

              process->pr_WindowPtr = windowptr;

              FreeMem(fc->fc_Namebuffer, fc->fc_Namelength);
            }
            else
              fatalerror = ERROR_NO_FREE_STORE;
          }
          else
            fatalerror = ERROR_BAD_TEMPLATE;

          FreeMem(fc->fc_Parsebuffer, fc->fc_Parselength);
        }
        else
          fatalerror = ERROR_NO_FREE_STORE;
        FreeMem(fc, sizeof(struct FindControl));
      }
      else
        fatalerror = ERROR_NO_FREE_STORE;

      FreeArgs(readargs);

    }
    else
      fatalerror = IoErr();

    /*
     * Error handling: To be informative, errors are shown while scanning, so the
     * file name which caused the error can be displayed. Other errors are shown
     * here. Errors which occured in the main loop are considered fatal, others
     * (except BREAK) just error.
     */

    if (fatalerror)
    {
      error = fatalerror;
      PrintFault(fatalerror, NULL);
    }

    SetIoErr(error);
    if (error != 0)
    {
      if (fatalerror)
        rc = RETURN_FAIL;
      else if (error == ERROR_BREAK)
        rc = RETURN_WARN;
      else
        rc = RETURN_ERROR;
    }

    CloseLibrary((struct Library *) DOSBase);
