/* Source: ADCD 2.1
 * Section: iv-3-lockpub-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-3-lockpub-c.md
 */

                                                               /* to signal the task */

                if (psnode->psn_Node.ln_Name)
                    FreeMem(psnode->psn_Node.ln_Name, strlen(psnode->psn_Node.ln_Name) + 1);
                Remove((struct Node *)psnode);
                FreeMem(psnode, sizeof(struct PubScreenNode));
                psnode = copy_psnode;
           }
           FreeMem(copy_publist, sizeof(struct List));
        }
        CloseLibrary(IntuitionBase);
    }
