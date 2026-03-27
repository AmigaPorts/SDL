/* Source: ADCD 2.1
 * Section: dos-library-matchpatternnocase
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-matchpatternnocase.md
 */

    Checks for a pattern match with a string.  The pattern must be a
    tokenized string output by [ParsePatternNoCase()](../Includes_and_Autodocs_2._guide/node02DC.html).  This routine is
    case-insensitive.

    NOTE: this routine is highly recursive.  You must have at least
    1500 free bytes of stack to call this (it will cut off it's
    recursion before going any deeper than that and return failure).
    That's _currently_ enough for about 100 levels deep of #, (, ~, etc.
