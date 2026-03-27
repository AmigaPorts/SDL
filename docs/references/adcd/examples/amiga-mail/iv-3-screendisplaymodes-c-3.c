/* Source: ADCD 2.1
 * Section: iv-3-screendisplaymodes-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-3-screendisplaymodes-c.md
 */

                                        /* Force modeID to INVALID to break */
                                        modeID = INVALID_ID;
                                    }
                                }
                            }
                        }
                    }
                    ShowDisplayModes(dlist);

                    wnode = (struct DisplayNode *) dlist->lh_Head;
                    while (nnode = (struct DisplayNode *)
