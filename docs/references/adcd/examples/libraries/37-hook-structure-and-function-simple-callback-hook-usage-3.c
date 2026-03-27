/* Source: ADCD 2.1
 * Section: 37-hook-structure-and-function-simple-callback-hook-usage
 * Library: libraries
 * ADCD reference: libraries/37-hook-structure-and-function-simple-callback-hook-usage.md
 */

    ULONG MyFunction (struct Hook *h, VOID *o, VOID *msg)
    {
        /* A SASC and Manx function that obtains access to the global
           data segment */
        geta4();

        /* Debugging function to send a string to the serial port */
        KPrintF("Inside MyFunction()\n");

        return (1);
    }
