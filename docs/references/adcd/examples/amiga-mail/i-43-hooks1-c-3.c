/* Source: ADCD 2.1
 * Section: i-43-hooks1-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/i-43-hooks1-c.md
 */

    struct Hook h;

    /* Open the utility library */
    if (UtilityBase = OpenLibrary ("utility.library", 36))
    {
        /* Initialize the callback Hook */
        InitHook (&h, MyFunction, NULL);

        /* Use the utility library function to invoke the Hook */
        CallHookPkt (&h, NULL, NULL);

        /* Close utility library now that we're done with it */
        CloseLibrary (UtilityBase);
    }
    else
    {
        /* Display an error message */
        printf ("Couldn't open utility.library\n");
    }
