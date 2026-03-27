/* Source: ADCD 2.1
 * Section: iii-29-dillo-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iii-29-dillo-c.md
 */

    struct Armadillo *newdillo = NULL;

    if ( newdillo = AllocMem( sizeof(struct Armadillo), MEMF_CLEAR ))
    {
        /* Armadillo allocated, so increment number of dillos.
        ** Note that to reference the client-unique data takes no
        ** special coding.
        */

        TotalDillos++;

        /* Since we've also added to the overall number created, we
        ** need to also update the TotalDillosCreated variable in
        ** the far data section.  That means a Forbid() and Permit()
        ** around the action (which MUST complete).
        */

        Forbid();
        TotalDillosCreated++;
        Permit();

    }

    /* And return either the address of the new armadillo, or else
    ** return NULL if the allocation failed.
    */

    return( newdillo );
