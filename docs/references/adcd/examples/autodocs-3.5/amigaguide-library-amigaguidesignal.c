/* Source: ADCD 2.1
 * Section: amigaguide-library-amigaguidesignal
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/amigaguide-library-amigaguidesignal.md
 */

        ULONG sigw, sigh;
        [AMIGAGUIDECONTEXT](../Includes_and_Autodocs_3._guide/node05D2.html#line86) handle;

        /* get the signal bit to wait on for a AmigaGuide message */
        sigh = AmigaGuideSignal(handle);

        /* add the signal bit into the total signals to wait on */
        sigw |= sigh;
