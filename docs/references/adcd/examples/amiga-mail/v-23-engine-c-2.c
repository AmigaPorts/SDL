/* Source: ADCD 2.1
 * Section: v-23-engine-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/v-23-engine-c.md
 */

    ok = FALSE;
    if (SetInfo(ge,
                OT_OTagList, ti,
                OT_OTagPath, otagpath,
                TAG_END) == OTERR_Success)
    {
      if (SetInfo(ge,
                  OT_DeviceDPI, ((ULONG) 77) << 16 | 75,
                  TAG_END) == OTERR_Success)
      {
        ok = TRUE;
      }
    }
