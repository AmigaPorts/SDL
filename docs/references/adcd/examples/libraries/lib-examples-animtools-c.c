/* Source: ADCD 2.1
 * Section: lib-examples-animtools-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-animtools-c.md
 */

        {
        if (NULL != (gInfo->nextLine = (WORD *)AllocMem(sizeof(WORD) * 8, MEMF_CLEAR)))
            {
            if (NULL != (gInfo->lastColor = (WORD **)AllocMem(sizeof(LONG) * 8, MEMF_CLEAR)))
                {
                if (NULL != (gInfo->collHandler = (struct collTable *)
                        AllocMem(sizeof(struct collTable),MEMF_CLEAR)))
                    {
                    if (NULL != (vsHead = (struct VSprite *)
                            AllocMem((LONG)sizeof(struct VSprite), MEMF_CLEAR)))
                        {
                        if (NULL != (vsTail = (struct VSprite *)
                                AllocMem(sizeof(struct VSprite), MEMF_CLEAR)))
                            {
                            gInfo->sprRsrvd   = reserved;
                            /* Set left- and top-most to 1 to better keep items */
                            /* inside the display boundaries.                   */
                            gInfo->leftmost   = gInfo->topmost    = 1;
                            gInfo->rightmost  = (rPort->BitMap->BytesPerRow << 3) - 1;
                            gInfo->bottommost = rPort->BitMap->Rows - 1;
                            rPort->GelsInfo = gInfo;
                            InitGels(vsHead, vsTail, gInfo);
                            return(gInfo);
                            }
                        FreeMem(vsHead, (LONG)sizeof(*vsHead));
                        }
                    FreeMem(gInfo->collHandler, (LONG)sizeof(struct collTable));
                    }
                FreeMem(gInfo->lastColor, (LONG)sizeof(LONG) * 8);
                }
            FreeMem(gInfo->nextLine, (LONG)sizeof(WORD) * 8);
            }
        FreeMem(gInfo, (LONG)sizeof(*gInfo));
        }
