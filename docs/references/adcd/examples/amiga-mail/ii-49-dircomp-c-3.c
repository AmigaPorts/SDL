/* Source: ADCD 2.1
 * Section: ii-49-dircomp-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-49-dircomp-c.md
 */

    /*
     * If pathpart equals filepart (pointer wise) then there is only one component
     * (possible preceeded by a volume name).
     */
    if (pathpart == filepart)
    {
      if (!(ItsWild(pathpart)))
        pathpart = NULL;
    }
    else
    {
      /* Try to lock it to determine if the last component is a directory. */
      if (lock = Lock(path, SHARED_LOCK))
      {
        if (fib = AllocMem(sizeof(struct FileInfoBlock), MEMF_CLEAR))
        {
          if ((Examine(lock, fib)) == DOSTRUE)
          {
            /* Hey it's a directory after all */
            if (fib->fib_DirEntryType > 0)
              pathpart = NULL;
          }
          FreeMem(fib, sizeof(struct FileInfoBlock));
        }
        UnLock(lock);
      }                                          /* else treat it as a filename */
    }

    /* Copy the pathpart in the buffer */
    tmp1 = buffer;
    tmp2 = path;
    while ((*tmp1++ = *tmp2++) && (tmp2 != pathpart))
    {
      if (tmp1 == (buffer + buffersize))
      {
        error = ERROR_NO_FREE_STORE;
        break;
      }
    }
    *tmp1 = '\0';                                /* NULL terminate. */
