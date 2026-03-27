/* Source: ADCD 2.1
 * Section: iv-3-screendisplaymodes-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-3-screendisplaymodes-c.md
 */

                        Remove((struct Node *) wnode);
                        FreeMem(wnode, sizeof(struct DisplayNode));
                        wnode = nnode;
                    }
                    FreeMem(dlist, sizeof(struct List));
                } else
                    EasyRequest(NULL, &failedES, NULL, "Out of memory");
                CloseLibrary(GadToolsBase);
            }
            CloseLibrary(GfxBase);
        }
        CloseLibrary(IntuitionBase);
    }
