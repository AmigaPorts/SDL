/* Source: ADCD 2.1
 * Section: xi-21-loadkeymap-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/xi-21-loadkeymap-c.md
 */

    node = list->lh_Head;
    while (node->ln_Succ)
    {
        result = Stricmp(name,node->ln_Name);
        if (result == 0)
            return(node);

        node = node->ln_Succ;
    }

    return(NULL);
