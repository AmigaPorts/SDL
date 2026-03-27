/* Source: ADCD 2.1
 * Section: ii-49-find-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-49-find-c.md
 */

    /* Find handler */
    if (cproc = GetDeviceProc(source, cproc))
    {
      SetFileSysTask(cproc->dvp_Port);
      if ((NameFromLock(cproc->dvp_Lock,
           fc->fc_Namebuffer,
           fc->fc_Namelength)) == DOSTRUE)
      {
        error = ScanDirectory(fc, fc->fc_Namebuffer);
      }
      else
      {
        error = IoErr();
        PrintFault(error, source);
      }

      if (error != 0)
        break;
    }
    else
    {
      error = IoErr();
      PrintFault(error, source);
    }

    /* Handle multi-assign */
