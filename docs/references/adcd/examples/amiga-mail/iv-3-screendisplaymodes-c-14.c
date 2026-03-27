/* Source: ADCD 2.1
 * Section: iv-3-screendisplaymodes-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-3-screendisplaymodes-c.md
 */

    return (OpenWindowTags(NULL,
                           WA_Top, screen->BarHeight + 1,
                           WA_Height, screen->Height - (screen->BarHeight + 1),
                           WA_CustomScreen, screen,
                           WA_IDCMP, CLOSEWINDOW | LISTVIEWIDCMP | MENUPICK,
                           WA_Flags, WINDOWCLOSE | ACTIVATE,
                           WA_Title, OScanDescr[overscantype],
                           TAG_END));
