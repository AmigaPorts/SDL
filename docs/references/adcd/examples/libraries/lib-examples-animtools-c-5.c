/* Source: ADCD 2.1
 * Section: lib-examples-animtools-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-animtools-c.md
 */

        {
        nAnimComp.nac_Xt        = *(nAnimSeq->nas_Xt + seq);
        nAnimComp.nac_Yt        = *(nAnimSeq->nas_Yt + seq);
        nAnimComp.nac_Time      = *(nAnimSeq->nas_Times + seq);
        nAnimComp.nac_Routine   = nAnimSeq->nas_Routines[seq];
        nAnimComp.nac_CFlags    = nAnimSeq->nas_CFlags;
        if ((seqComp = makeComp(nBob, &nAnimComp)) == NULL)
            {
            if (firstCompInSeq != NULL)
                freeSeq(firstCompInSeq, (LONG)nBob->nb_RasDepth);
            return(NULL);
            }
        seqComp->HeadOb = nAnimSeq->nas_HeadOb;
        /* Make a note of where the first component is. */
        if (firstCompInSeq == NULL) firstCompInSeq = seqComp;
        /* link the component into the list */
        if (lastCompMade != NULL) lastCompMade->NextSeq = seqComp;
        seqComp->NextSeq = NULL;
        seqComp->PrevSeq = lastCompMade;
        lastCompMade = seqComp;
        /* If nAnimSeq->nas_SingleImage is zero, the image array has nAnimSeq->nas_Count images. */
        if (!nAnimSeq->nas_SingleImage)
            nBob->nb_Image += image_size;
        }
