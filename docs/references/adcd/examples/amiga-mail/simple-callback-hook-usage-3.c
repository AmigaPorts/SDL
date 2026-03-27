/* Source: ADCD 2.1
 * Section: simple-callback-hook-usage
 * Library: amiga-mail
 * ADCD reference: amiga-mail/simple-callback-hook-usage.md
 */

    ULONG MyFunction (struct Hook *h, VOID *o, VOID *msg)
    {
        /* A SASC and Manx function that obtains access to the global data segment */
        geta4();

        /* Debugging function to send a string to the serial port */
        KPrintF("Inside MyFunction()n");

        return (1);
    }
