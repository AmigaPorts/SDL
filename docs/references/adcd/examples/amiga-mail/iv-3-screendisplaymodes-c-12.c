/* Source: ADCD 2.1
 * Section: iv-3-screendisplaymodes-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-3-screendisplaymodes-c.md
 */

                    } while (ABORT == FALSE);
                    FreeMenus(menu);
                } else
                    EasyRequest(NULL, &failedES, NULL, "Can't create menus");
                FreeMem(textattr->ta_Name, 48);
            } else
                EasyRequest(NULL, &failedES, NULL, "Out of memory");
            FreeMem(textattr, sizeof(struct TextAttr));
        } else
            EasyRequest(NULL, &failedES, NULL, "Out of memory");
        FreeMem(ng, sizeof(struct NewGadget));
    } else
        EasyRequest(NULL, &failedES, NULL, "Out of memory");
