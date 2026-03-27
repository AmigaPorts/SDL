/* Source: ADCD 2.1
 * Section: 1-programming-in-the-amiga-environment-libraries-of
 * Library: libraries
 * ADCD reference: libraries/1-programming-in-the-amiga-environment-libraries-of.md
 */

    struct Library *LibBase;      /* Global: declare this above main() */

    main()
    {
    LibBase = OpenLibrary("library.name",version);

    if(!LibBase) { /* Library did not open, so exit        */ }
    else         { /* Library opened, so use its functions */ }
    }
