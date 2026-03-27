/* Source: ADCD 2.1
 * Section: dos-library-examine
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-examine.md
 */

    Examine() fills in information in the [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62) concerning the
    file or directory associated with the lock. This information
    includes the name, size, creation date and whether it is a file or
    directory.  [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62) must be longword aligned.  Examine() gives
    a return code of zero if it fails.

    You may make a local copy of the [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62), as long as it is
    never passed to [ExNext()](../Includes_and_Autodocs_2._guide/node02A0.html).
