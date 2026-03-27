/* Source: ADCD 2.1
 * Section: 29-graphics-library-and-text-what-fonts-are-available
 * Library: libraries
 * ADCD reference: libraries/29-graphics-library-and-text-what-fonts-are-available.md
 */

            These structures were created for Release 2 to allow
            [AvailFonts()](../Includes_and_Autodocs_2._guide/node01F3.html) to list tag values:

            struct TAvailFonts {
                UWORD   taf_Type;           /* MEMORY, DISK, or SCALED */
                struct TTextAttr taf_Attr;  /* text attributes for font */
            };
