/* Source: ADCD 2.1
 * Section: iii-29-dillo-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iii-29-dillo-c.md
 */

    ULONG retval = 0L;

    /* This routine is ``safe'' in that it can handle being given a NULL
    ** pointer (in which case it returns 0L).
    */

    if ( dillo )
    {
        retval = dillo->weight;
    }

    return( retval );
