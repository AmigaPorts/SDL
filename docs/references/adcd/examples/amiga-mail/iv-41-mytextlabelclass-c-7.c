/* Source: ADCD 2.1
 * Section: iv-41-mytextlabelclass-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-41-mytextlabelclass-c.md
 */

    WORD retval = FALSE;
    STRPTR buffer;
    LONG i;

    /* Allocate a temporary buffer */
    if (buffer = AllocVec ((count + 1), MEMF_CLEAR))
    {
