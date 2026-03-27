/* Source: ADCD 2.1
 * Section: iii-29-dillo-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iii-29-dillo-c.md
 */

    BOOL retval = FALSE;

    /* This routine is ``safe'' in that it can handle being given a NULL
    ** pointer (in which case it does nothing).
    */

    if ( dillo && dname && len )
    {
        CopyMem( (APTR) dname, (APTR) &(dillo->name), ((len>31L)?32L:len) );
        retval = TRUE;
    }

    return( retval );
