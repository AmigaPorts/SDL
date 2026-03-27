/* Source: ADCD 2.1
 * Section: dos-library-readitem
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-readitem.md
 */

    Reads a "word" from either [Input()](../Includes_and_Autodocs_2._guide/node02BF.html) (buffered), or via [CSource](../Includes_and_Autodocs_2._guide/node0076.html#line62), if it
    is non-NULL (see [<dos/rdargs.h>](../Includes_and_Autodocs_2._guide/node0076.html) for more information).  Handles
    quoting and some '*' substitutions (*e and *n) inside quotes (only).
    See [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html) for a listing of values returned by ReadItem()
    (ITEM_XXXX).  A "word" is delimited by whitespace, quotes, or an EOF.

    ReadItem always unreads the last thing read (UnGetC(fh,-1)) so the
    caller can find out what the terminator was.
