/* Source: ADCD 2.1
 * Section: i-43-hooks1-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/i-43-hooks1-c.md
 */

    /* Make sure a pointer was passed */
    if (h)
    {
        /* Fill in the Hook fields */
        h->h_Entry = (ULONG (*)()) hookEntry;
        h->h_SubEntry = func;
        h->h_Data = data;
    }
