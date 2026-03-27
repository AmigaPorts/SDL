/* Source: ADCD 2.1
 * Section: ii-95-compareio-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-95-compareio-c.md
 */

    if (SetSignal(0L, SIGBREAKF_CTRL_C) & SIGBREAKF_CTRL_C)
    {
      done = TRUE;
      ok = FALSE;
    }
    else
    {
      SendPkt(sp_read, in->fh_Type, myport);
      WaitPort(myport);
      while (GetMsg(myport));

      if (sp_read->dp_Res1 > 0)
      {
        sp_write->dp_Arg3 = sp_read->dp_Res1;
        SendPkt(sp_write, out->fh_Type, myport);
        WaitPort(myport);
        while (GetMsg(myport));
        if (sp_write->dp_Res1 != sp_write->dp_Arg3)
        {
          done = TRUE;
          ok   = FALSE;
        }
      }
      else
      {
        done = TRUE;
        if (sp_read->dp_Res1 < 0) ok = FALSE;
      }
    }
