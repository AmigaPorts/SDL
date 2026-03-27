/* Source: ADCD 2.1
 * Section: lib-examples-easyintuition37-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-easyintuition37-c.md
 */

    /* Close things in the reverse order of opening */
    if (wind) CloseWindow( wind );      /* Close window if opened */
    if (scrn) CloseScreen( scrn );      /* Close screen if opened */

    /* Close the library, and then exit */
    if (IntuitionBase) CloseLibrary( IntuitionBase );
    exit(returnValue);
