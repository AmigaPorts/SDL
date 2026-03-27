/* Source: ADCD 2.1
 * Section: amigaguide-class-getagstring
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/amigaguide-class-getagstring.md
 */

    NAME
        GetAGString - Obtain localized AmigaGuide text  (V34)

    SYNOPSIS
        string = GetAGString (id);
        d0                      d0

        [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) GetAGString (LONG);

    FUNCTION
        This function is used to obtain a pointer to the string
        associated with the given ID.

    INPUTS
        id        - [Catalog](../Includes_and_Autodocs_3._guide/node05E3.html#line245) entry to obtain.

    RETURNS
        Returns a pointer to the NULL terminated string. NULL on
        failure.

    SEE ALSO
