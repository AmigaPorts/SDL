/* Source: ADCD 2.1
 * Section: iv-41-mytextlabelclass-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-41-mytextlabelclass-c.md
 */

    LONG            count = (label) ? strlen(label) : 0L;
    LONG            i;

    /* Search for an _ sign */
    for (i = 0; i < (count - 1); i++)
    {
        /* Did we find an _ sign? */
        if (label[i] == '_')
        {
            return ((UWORD) label[(i + 1)]);
        }
    }

    return (0);
