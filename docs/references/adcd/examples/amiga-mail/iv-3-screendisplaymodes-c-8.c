/* Source: ADCD 2.1
 * Section: iv-3-screendisplaymodes-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-3-screendisplaymodes-c.md
 */

                                do {
                                    WaitPort(window->UserPort);
                                    while (imsg = GT_GetIMsg(window->UserPort)) {
                                        iclass = imsg->Class;
                                        icode = imsg->Code;
                                        hitgadget =
