/* Source: ADCD 2.1
 * Section: vi-1-interplay-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/vi-1-interplay-c.md
 */

    {
    /* Next, read the first 12 bytes to check the type */
    rdcount =Read( filehandle, iobuffer, 12L );
    if(rdcount==12L)
        {
        /* Make sure it is an IFF FORM type */
        pGH = (GroupHeader *)iobuffer;
        if(pGH->ckID == FORM)
            {
            /* Make sure it is an 8SVX sub-type */
            if(pGH->grpSubID != ID_8SVX)
                    error="Not an 8SVX file\n";
            }
        else
            error="Not an IFF FORM\n";
        }
    else
        error="Read error or file too short1\n";
    }
