/* Source: ADCD 2.1
 * Section: ii-49-find-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-49-find-c.md
 */

    /* Hmmm. */
    if (name[position] == '\0')
    {

      /*
       * I guess it does. Lets see if we can find it in the assign list. Keep the
       * DoSList locked as briefly as possible. This shouldn't take long.
       */
      if (doslist = AttemptLockDosList(LDF_ASSIGNS | LDF_READ))
      {
        while (doslist = NextDosEntry(doslist, LDF_ASSIGNS))
        {

          /* It's a BPTR */
          assignname = (UBYTE *) BADDR(doslist->dol_Name);
          assignlength = assignname[0];

          if ((Strnicmp(assignname + 1, fc->fc_Namebuffer, assignlength)) == 0)
          {
            /* Yup, it is. */
            result = TRUE;
            break;
          }
        }
        UnLockDosList(LDF_ASSIGNS | LDF_READ);
      }    /* Can't lock DosList, don't bother */
    }
