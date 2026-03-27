/* Source: ADCD 2.1
 * Section: xi-21-loadkeymap-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/xi-21-loadkeymap-c.md
 */

    kn      = NULL;
    segment = NULL;

    /* open the keymap resource, in order to gain access to the keymap list */
    if (kr = (struct KeyMapResource *)OpenResource("keymap.resource"))
    {
        segment = NULL;
        base = FilePart(name);

        /* must access the list under Forbid() */
        Forbid();

        /* is the keymap we want already on the keymap list? */
        if (!(kn = (struct KeyMapNode *)FindNameNC(&kr->kr_List,base)))
        {
            /* if not on the keymap list, try loading it */
            if (segment = LoadSeg(name))
            {
                /* see if someone added it to the keymap list while we were
                 * doing a LoadSeg() (which broke Forbid() )
                 */
                if (!(kn = (struct KeyMapNode *)FindNameNC(&kr->kr_List,base)))
                {
                    kn = (struct KeyMapNode *)((segment << 2) + sizeof(BPTR));

                    /* we've loaded a keymap file. Do a few sanity checks
                     * to make sure it is a keymap, and not some bogus
                     * load file
                     */
                    if (TypeOfMem(kn->kn_Node.ln_Name)
                    &&  Stricmp(name,kn->kn_Node.ln_Name))
                    {
                        /* add to the system's keymap list */
                        AddHead(&(kr->kr_List),(struct Node *)kn);
                    }
                    else
                    {
                        /* bogus load file! Get rid of it and fail */
                        UnLoadSeg(segment);
                        kn = NULL;
                    }
                }
                else
                {
                    /* the keymap was added to the list behind our back!
                     * Free what was loaded and return happily
                     */
                    UnLoadSeg(segment);
                }
            }
        }

        /* get out of forbidden state */
        Permit();
    }

    if (kn)
        return(&kn->kn_KeyMap);

    return(NULL);
