/* Source: ADCD 2.1
 * Section: iffparse-library-stoponexit
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/iffparse-library-stoponexit.md
 */

    Installs an exit handler for the specified chunk which will cause the
    [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html) function to return control to the caller when this chunk
    is exhausted.  [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html) will return IFFERR_EOC when the declared
    chunk is about to be popped.  This is only of value when [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html)
    is called with the IFFPARSE_SCAN control code.
