/* Source: ADCD 2.1
 * Section: 36-translator-library-opening-the-translator-library
 * Library: libraries
 * ADCD reference: libraries/36-translator-library-opening-the-translator-library.md
 */

    struct Library *TranslatorBase;

    TranslatorBase = OpenLibrary("translator.library",REVISION);
    if(TranslatorBase != NULL)
        {
        /* use translator here -- library open */
        }


    LIBS: must contain translator.library.
    --------------------------------------
    Since translator is a disk-based library, the call to
    [OpenLibrary()](../Libraries_Manual_guide/node028E.html#line15) will work only if the LIBS: directory contains
    translator.library.
