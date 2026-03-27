/* Source: ADCD 2.1
 * Section: 1-design-decisions-conditional-code
 * Library: libraries
 * ADCD reference: libraries/1-design-decisions-conditional-code.md
 */

    Examples of conditional library checking code:

    /* Checking for presence of a new Release 2 library */
    if( AslBase = OpenLibrary("asl.library", 37L) )
            { /* OK to use the ASL requester */ }
    else
            { /* Must use a different method */ }

    /* Check version of an existing library with new Release 2 features */
    if(GfxBase->lib_Version >= 37)   { /* then allow new genlock modes */}
