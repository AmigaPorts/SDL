/* Source: ADCD 2.1
 * Section: v-39-namemode-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/v-39-namemode-c.md
 */

    if (!dispInfo.NotAvailable)
    {
      if (GetDisplayInfoData (dh, (APTR) & dimInfo, sizeof (struct DimensionInfo),
                              DTAG_DIMS, INVALID_ID))
      {
