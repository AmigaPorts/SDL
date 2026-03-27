/* Source: ADCD 2.1
 * Section: iv-3-screendisplaymodes-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-3-screendisplaymodes-c.md
 */

                                                item = ItemAddress(menu, icode);

                                                code = (ULONG) MENU_USERDATA(item);
                                                if (code == QUIT)
                                                    ABORT = TRUE;
                                                else if
                                                    (code == SWITCH)
                                                    OK = TRUE;
                                                else
                                                    overscantype = (ULONG) code;
                                                icode = item->NextSelect;
                                            }
                                            break;
                                        case CLOSEWINDOW:
                                            ABORT = TRUE;
                                            break;
                                        }
                                    }
                                } while (ABORT == FALSE && OK == FALSE);
                                ClearMenuStrip(window);
                                CloseWindow(window);
                                FreeVisualInfo(vi);
                                FreeGadgets(glist);
                            } else
                                EasyRequest(NULL, &failedES, NULL,
