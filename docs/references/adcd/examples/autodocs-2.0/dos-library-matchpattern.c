/* Source: ADCD 2.1
 * Section: dos-library-matchpattern
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-matchpattern.md
 */

    Checks for a pattern match with a string.  The pattern must be a
    tokenized string output by [ParsePattern()](../Includes_and_Autodocs_2._guide/node02DB.html).  This routine is
    case-sensitive.

    NOTE: this routine is highly recursive.  You must have at least
    1500 free bytes of stack to call this (it will cut off it's
    recursion before going any deeper than that and return failure).
    That's _currently_ enough for about 100 levels deep of #, (, ~, etc.
