/* Source: ADCD 2.1
 * Section: 15-kinds-of-gadtools-gadgets-text-entry-and-number-entry
 * Library: libraries
 * ADCD reference: libraries/15-kinds-of-gadtools-gadgets-text-entry-and-number-entry.md
 */

    gad = CreateGadget( STRING_KIND, gad, &ng,
            /* string gadget tags go here */
            GTST_...,

            /* Add this tag for future GadTools releases */
            GA_Immediate, TRUE,
            ...
            TAG_DONE );

    if ( ( gad ) && ( GadToolsBase->lib_Version == 37) )
    {
            /* Under GadTools V37 only, set this attribute
             * directly.  Do not set this attribute under
             * future versions of GadTools, or for gadgets
             * other than STRING_KIND or INTEGER_KIND.
             */
            gad->Activation |= GACT_IMMEDIATE;
    }
