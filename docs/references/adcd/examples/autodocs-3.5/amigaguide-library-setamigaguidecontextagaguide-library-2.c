/* Source: ADCD 2.1
 * Section: amigaguide-library-setamigaguidecontextagaguide-library
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/amigaguide-library-setamigaguidecontextagaguide-library.md
 */

        /* sample context table */
        [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) ContextArray[] =
        {
            "MAIN",
            "FILEREQ",
            "PRINT",
            "ABOUT",
            NULL
        };

        /* quickie defines */
        #define HELP_MAIN      0
        #define HELP_FILEREQ   1
        #define HELP_PRINT     2
        #define HELP_ABOUT     3

        ...

        struct [NewAmigaGuide](../Includes_and_Autodocs_3._guide/node05D2.html#line102) nag = {NULL};

        /* initialize the context table */
        nag.nag_Context = ContextArray;

        ...

        /* bring up help on a particular subject */
        SetAmigaGuideContext(handle, HELP_ABOUT, NULL);
