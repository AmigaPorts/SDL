/* Source: ADCD 2.1
 * Section: iv-125-newgadgets-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-125-newgadgets-c.md
 */

    switch (itemnum)
    {
    case 0:                     /* left justify string */
      GT_SetGadgetAttrs (textgad, win, NULL,
                         GTTX_Justification, GTJ_LEFT,
                         GTTX_Text, "Left", TAG_END);
      break;
    case 2:                     /* center justify string */
      GT_SetGadgetAttrs (textgad, win, NULL,
                         GTTX_Justification, GTJ_CENTER,
                         GTTX_Text, "Center", TAG_END);
      break;
    case 4:                     /* right justify string */
      GT_SetGadgetAttrs (textgad, win, NULL,
                         GTTX_Justification, GTJ_RIGHT,
                         GTTX_Text, "Right", TAG_END);
    }
