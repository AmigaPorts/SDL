/* Source: ADCD 2.1
 * Section: lib-examples-animtools-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-animtools-c.md
 */

        {
        if ((compBob = makeBob(nBob)) != NULL)
            {
            compBob->After   = compBob->Before  = NULL;
            compBob->BobComp = aComp;   /* Link 'em up. */
            aComp->AnimBob      = compBob;
            aComp->TimeSet      = nAnimComp->nac_Time; /* Num ticks active. */
            aComp->YTrans       = nAnimComp->nac_Yt; /* Offset rel to HeadOb */
            aComp->XTrans       = nAnimComp->nac_Xt;
            aComp->AnimCRoutine = nAnimComp->nac_Routine;
            aComp->Flags        = nAnimComp->nac_CFlags;
            aComp->Timer        = 0;
            aComp->NextSeq      = aComp->PrevSeq  = NULL;
            aComp->NextComp     = aComp->PrevComp = NULL;
            aComp->HeadOb       = NULL;
            return(aComp);
            }
        FreeMem(aComp, (LONG)sizeof(struct AnimComp));
        }
