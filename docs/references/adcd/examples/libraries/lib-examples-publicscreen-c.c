/* Source: ADCD 2.1
 * Section: lib-examples-publicscreen-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-publicscreen-c.md
 */

    {
    /* Check the version number; Release 2 is */
    /* required for public screen functions   */
    if (IntuitionBase->lib_Version >= 37)
        {
        usePubScreenPens();
        }
    CloseLibrary(IntuitionBase);
    }
