/* Source: ADCD 2.1
 * Section: iv-3-screendisplaymodes-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-3-screendisplaymodes-c.md
 */

                                        AddGList(window, glist, -1, -1, NULL);
                                        RefreshGList(glist, window, NULL, -1);
                                        GT_RefreshWindow(window, NULL);
                                        SetMenuStrip(window, menu);
                                        ABORT = FALSE;
                                    } else
                                        EasyRequest(window, &failedES, NULL,
