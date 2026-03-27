/* Source: ADCD 2.1
 * Section: intuition-library-pointinimage
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-pointinimage.md
 */

    Point   - Two words, X/Y packed into a LONG, with high word
            containing 'X'.  This is what you get if you pass
            a Point structure (not a pointer!) using common
            C language parameter conventions.
    [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621) - a pointer to a standard or custom [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621) data object.
        NOTE: If 'Image' is NULL, this function returns TRUE.
