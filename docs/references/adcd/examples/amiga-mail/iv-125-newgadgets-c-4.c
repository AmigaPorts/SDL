/* Source: ADCD 2.1
 * Section: iv-125-newgadgets-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-125-newgadgets-c.md
 */

    Wait (1 << win->UserPort->mp_SigBit);

    while ((!Closeflag) && (msg = GT_GetIMsg (win->UserPort)))
    {
      msgclass = msg->Class;

      switch (msgclass)
      {
      case IDCMP_CLOSEWINDOW:
        Closeflag = TRUE;
        break;

      case IDCMP_GADGETDOWN:
        if (msg->IAddress == stringgad)
        {
          holdstring = ((struct StringInfo *) (stringgad->SpecialInfo))->Buffer;
          GT_SetGadgetAttrs (textgad, win, NULL,
                             GTTX_Text, holdstring, TAG_END);
        }
        break;

      case IDCMP_GADGETUP:
        if (msg->IAddress == intgad)
        {
          num = ((struct StringInfo *) (intgad->SpecialInfo))->LongInt;
          GT_SetGadgetAttrs (numgad, win, NULL, GTNM_Number, num,
                             GTNM_Justification, GTJ_RIGHT, TAG_END);
        }
        break;

      case IDCMP_MENUPICK:
        menunumber = msg->Code;
        while (menunumber != MENUNULL && !Closeflag)
        {
          Closeflag = ProcessDaMenu (menunumber, win, menustrip, vi);
          menunumber = (ItemAddress (menustrip, menunumber))->NextSelect;
        }
      }
      GT_ReplyIMsg (msg);
    }
