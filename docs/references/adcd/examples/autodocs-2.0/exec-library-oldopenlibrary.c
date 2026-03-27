/* Source: ADCD 2.1
 * Section: exec-library-oldopenlibrary
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-oldopenlibrary.md
 */

    The 1.0 release of the Amiga system had an incorrect version of
    [OpenLibrary](../Includes_and_Autodocs_2._guide/node0367.html) that did not check the version number during the
    library open.  This obsolete function is provided so that object
    code compiled using a 1.0 system will still run.

    This exactly the same as "OpenLibrary(libName,0L);"
