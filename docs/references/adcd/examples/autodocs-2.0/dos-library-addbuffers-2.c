/* Source: ADCD 2.1
 * Section: dos-library-addbuffers
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-addbuffers.md
 */

    The V36 ROM filesystem (FFS/OFS) doesn't return the right number of
    buffers unless preceded by an AddBuffers(fs,-1) (in-use buffers aren't
    counted).  This is fixed in V37.

    The V37 and before ROM filesystem doesn't return success, it returns
    the number of buffers.  The best way to test for this is to consider
    0 (FALSE) failure, -1 (DOSTRUE) to mean that [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html) will have the
    number of buffers, and any other positive value to be the number of
    buffers.  It may be fixed in some future ROM revision.
