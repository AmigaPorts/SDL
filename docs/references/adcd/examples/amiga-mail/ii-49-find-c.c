/* Source: ADCD 2.1
 * Section: ii-49-find-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-49-find-c.md
 */

    UtilityBase = DOSBase->dl_UtilityBase;

    rargs[0] = 0L;
    rargs[1] = 0L;
    rargs[2] = 0L;
    rargs[3] = 0L;
    rargs[4] = 0L;
    rargs[5] = 0L;

    if (readargs =
        ReadArgs("PATTERN/A,DIRECTORY/A/M,FILES/S,DIRS/S,ALL/S,BUFFER/K/N",
                 rargs,
                 NULL))
    {

      if (fc = AllocMem(sizeof(struct FindControl), MEMF_CLEAR))
      {
