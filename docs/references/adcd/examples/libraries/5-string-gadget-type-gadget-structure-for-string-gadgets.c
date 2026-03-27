/* Source: ADCD 2.1
 * Section: 5-string-gadget-type-gadget-structure-for-string-gadgets
 * Library: libraries
 * ADCD reference: libraries/5-string-gadget-type-gadget-structure-for-string-gadgets.md
 */

    of [StringInfo.MaxChars](../Libraries_Manual_guide/node016B.html#line49) times the font width pixels of space will be
    cleared.  Thus, if MaxChars is 3 (two characters plus the trailing
    NULL) and the font width is 8, then a maximum of 3 * 8 = 24 pixels
    will be cleared.  If the font defaults to a proportional font, then
    the width returned by [FontExtent()](../Libraries_Manual_guide/node03DA.html#line15) will be used as the character
    width.
