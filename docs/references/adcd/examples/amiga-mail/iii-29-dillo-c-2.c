/* Source: ADCD 2.1
 * Section: iii-29-dillo-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iii-29-dillo-c.md
 */

    /* This routine is ``safe'' in that it can handle being given a NULL
    ** pointer (in which case it does nothing).
    */

    if ( dillo )
    {
        /* We do indeed appear to have an armadillo on our hands
        ** so we decrement the overall count and deallocate the
        ** memory it uses.
        */

        TotalDillos--;

        FreeMem( dillo, sizeof( struct Armadillo ));
    }

    return;
