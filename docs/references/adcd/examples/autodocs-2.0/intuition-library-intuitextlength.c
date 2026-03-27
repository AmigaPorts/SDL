/* Source: ADCD 2.1
 * Section: intuition-library-intuitextlength
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-intuitextlength.md
 */

    This routine accepts a pointer to an instance of an [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572)
    structure, and returns the length (the pixel-width) of the string
    which that instance of the structure represents.

    NOTE: if the Font pointer of your [IntuiText](../Includes_and_Autodocs_2._guide/node00D4.html#line572) structure is set to NULL,
    you'll get the pixel-width of your text in terms of the current system
    default font.  You may wish to be sure that the field IText->ITextFont
    for 'default font' text is equal to the Font field of the screen it is
    being measured for.
