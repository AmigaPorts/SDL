/* Source: ADCD 2.1
 * Section: ii-49-dircomp-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-49-dircomp-c.md
 */

    rargs[0] = 0L;
    rargs[1] = 0L;
    rargs[2] = 0L;
    rargs[3] = 0L;
    rargs[4] = 0L;

    if (readargs = ReadArgs("SOURCE/A,TARGET/A,DATE/S,ALL/S,BUFFER/K/N", rargs, NULL))
    {

      source = (UBYTE *) rargs[0];
      target = (UBYTE *) rargs[1];
      checkdatestamp = (BOOL) rargs[2];
      all = (BOOL) rargs[3];

      if (!(sourcedir = AllocMem(StrLen(source) + 129, MEMF_CLEAR)))
        error = ERROR_NO_FREE_STORE;
      else
      {
        /* 128 bytes to print informative text */
        textbuffer = sourcedir + StrLen(source) + 1;

        /* use user specified buffersize if indicated */
        if (rargs[4])
          buffersize = *((LONG *) rargs[4]);
        if (buffersize < BUFFERSIZE || buffersize > 4096)
          buffersize = BUFFERSIZE;

        if (!(targetdir = AllocMem(buffersize, MEMF_CLEAR)))
          error = ERROR_NO_FREE_STORE;
        else
        {
          if (!(targetfib = AllocDosObject(DOS_FIB, NULL)))
            error = ERROR_NO_FREE_STORE;
          else
          {

            /*
             * Check if source and target are valid.
             *
             * Separate source path from pattern (if any). Use the source path figure
             * out what to append to the target.
             */

            /* No requesters */
            process = (struct Process *) FindTask(NULL);
            wptr = process->pr_WindowPtr;
            process->pr_WindowPtr = (APTR) - 1L;

            if ((error = GetPath(source, sourcedir, StrLen(source) + 1) == 0))
            {
              if (!(dirlock = Lock(sourcedir, SHARED_LOCK)))
                error = IoErr();
              else
              {
                UnLock(dirlock);
                if (!(dirlock = Lock(target, SHARED_LOCK)))
                  error = IoErr();
                else
                {
                  UnLock(dirlock);

                  if (anchorpath = AllocMem(sizeof(struct AnchorPath) + buffersize,
                                            MEMF_CLEAR))
                  {
                    anchorpath->ap_Strlen = buffersize;

                    /* Allow to break on CTRL-C */
                    anchorpath->ap_BreakBits = SIGBREAKF_CTRL_C;

                    if ((error = MatchFirst(source, anchorpath)) == 0)
                    {

                      do
                      {
                        fib = &(anchorpath->ap_Info);

                        /*
                         * APF_DIDDIR indicates that we used returned from a
                         * directory. In that case we clear both APF_DIDDIR and
                         * APF_DODIR, so we can start afresh with the next one.
                         */


                        if (anchorpath->ap_Flags & APF_DIDDIR)
                          anchorpath->ap_Flags &= ~(APF_DODIR | APF_DIDDIR);
                        else
                        {

                          /*
                           * Make a filename for the target directory. First copy
                           * targetname into buffer.
                           */
                          targetdir[0] = '\0';
                          tmp = targetdir;
                          tmp1 = target;
                          while (*tmp++ = *tmp1++);

                          /* Skip sourcename in ap_Buf */
                          tmp1 = sourcedir;
                          tmp2 = anchorpath->ap_Buf;
                          while (*tmp1++ == *tmp2++);
                          /* Skip back 1 if not after a separator */
                          if (*(tmp2 - 1) != '/')
                            tmp2--;

                          /*
                           * We hit the source itself, don't compare it, but enter
                           * it.
                           */
                          if (*tmp2 == 0)
                          {
                            anchorpath->ap_Flags |= APF_DODIR;
                            continue;
                          }

                          /* Build it */
                          if (AddPart(targetdir, tmp2, buffersize - 1))
                            vargs[0] = (LONG) targetdir;
                          else
                          {
                            PrintFault(ERROR_NO_FREE_STORE, NULL);
                            break;
                          }

                          /* Lock it and check it out */
                          if (filelock = Lock(targetdir, SHARED_LOCK))
                          {
                            if ((Examine(filelock, targetfib)) == DOSTRUE)
                            {
                              textbuffer[0] = '\0';

                              /*
                               * To get nice output without work I use AddPart() to
                               * add differences to the textbuffer.
                               */
                              if (targetfib->fib_DirEntryType
                                  != fib->fib_DirEntryType)
                                AddPart(textbuffer, "of different type", 128);
                              else
                              {
                                if (targetfib->fib_Size < fib->fib_Size)
                                  AddPart(textbuffer, "smaller", 128);
                                else if (targetfib->fib_Size > fib->fib_Size)
                                  AddPart(textbuffer, "larger", 128);

                                if (checkdatestamp)
                                {
                                  date = CompareDates((struct DateStamp *)
                                        & (fib->fib_Date),
                                      (struct DateStamp *) & (targetfib->fib_Date));
                                  if (date < 0)
                                    AddPart(textbuffer, "older", 128);
                                  else if (date > 0)
                                    AddPart(textbuffer, "newer", 128);
                                }
                              }


                              if (*textbuffer != NULL)
                              {
                                vargs[1] = (LONG) textbuffer;
                                VFPrintf(Output(), "%s: object %s\n", vargs);
                              }
                            }
                            else
                              PrintFault(IoErr(), targetdir);
                            UnLock(filelock);
                          }
                          else
                          {
                            PrintFault(IoErr(), targetdir);

                            /*
                             * If and error occured on a directory name, don't enter
                             * it.
                             */
                            if (fib->fib_DirEntryType > 0)
                              continue;

                          }

                          /*
                           * If the ALL keyword has been used and this is a directory
                           * enter it by setting the APF_DODIR flag.
                           */

                          if (fib->fib_DirEntryType > 0 && all != FALSE)
                            anchorpath->ap_Flags |= APF_DODIR;

                        }

                      } while ((error = MatchNext(anchorpath)) == 0);
                    }

                    MatchEnd(anchorpath);

                    if (error == ERROR_NO_MORE_ENTRIES)
                      error = 0;

                    FreeMem(anchorpath, sizeof(struct AnchorPath) + buffersize);
                  }
                }
              }
              /* Reset windowpointer */
              process->pr_WindowPtr = wptr;
            }
            else
              PrintFault(error, NULL);
            FreeDosObject(DOS_FIB, targetfib);
          }
          FreeMem(targetdir, buffersize);
        }
        FreeMem(sourcedir, StrLen(sourcedir) + 129);
      }
      FreeArgs(readargs);
    }
    else
      error = IoErr();

    SetIoErr(error);
    if (error)
    {
      PrintFault(error, NULL);
      if (error = ERROR_BREAK)
        rc = RETURN_WARN;
      else
        error = RETURN_FAIL;
    }
    CloseLibrary((struct Library *) DOSBase);
