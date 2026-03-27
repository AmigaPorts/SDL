/* Source: ADCD 2.1
 * Section: iii-29-dillo-lib-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iii-29-dillo-lib-c.md
 */

    int retval = 1;

    SysBase = (*((void **)4));

    /* Here we attempt to open Utility library.  Not a particularly good
    ** example, but it gets the point across.  If exec.library could not
    ** be opened (say for a second it couldn't), then __UserLibInit would
    ** return 1 indicating failure (where a return of 0 means success).
    */

    if (UtilityBase = OpenLibrary( "utility.library", 0L ))
        retval = 0;

    return( retval );
