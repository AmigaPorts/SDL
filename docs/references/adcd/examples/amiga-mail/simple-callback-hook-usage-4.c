/* Source: ADCD 2.1
 * Section: simple-callback-hook-usage
 * Library: amiga-mail
 * ADCD reference: amiga-mail/simple-callback-hook-usage.md
 */

    /* This simple function is used to initialize a Hook */
    VOID InitHook (struct Hook *h, ULONG (*func)(), VOID *data)
    {
        /* Make sure a pointer was passed */
        if (h)
        {
            /* Fill in the hook fields */
            h->h_Entry = (ULONG (*)()) hookEntry;
            h->h_SubEntry = func;
            h->h_Data = data;
        }
    }
