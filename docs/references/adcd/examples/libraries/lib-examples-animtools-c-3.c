/* Source: ADCD 2.1
 * Section: lib-examples-animtools-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-animtools-c.md
 */

        {
        if (NULL != (bob->SaveBuffer = (WORD *)AllocMem(rassize, MEMF_CHIP)))
            {
            nVSprite.nvs_WordWidth  = nBob->nb_WordWidth;
            nVSprite.nvs_LineHeight = nBob->nb_LineHeight;
            nVSprite.nvs_ImageDepth = nBob->nb_ImageDepth;
            nVSprite.nvs_Image      = nBob->nb_Image;
            nVSprite.nvs_X          = nBob->nb_X;
            nVSprite.nvs_Y          = nBob->nb_Y;
            nVSprite.nvs_ColorSet   = NULL;
            nVSprite.nvs_Flags      = nBob->nb_BFlags;
            /* Push the values into the NEWVSPRITE structure for use in makeVSprite(). */
            nVSprite.nvs_MeMask     = nBob->nb_MeMask;
            nVSprite.nvs_HitMask    = nBob->nb_HitMask;

            if ((vsprite = makeVSprite(&nVSprite)) != NULL)
                {
                vsprite->PlanePick = nBob->nb_PlanePick;
                vsprite->PlaneOnOff = nBob->nb_PlaneOnOff;
                vsprite->VSBob   = bob;
                bob->BobVSprite  = vsprite;
                bob->ImageShadow = vsprite->CollMask;
                bob->Flags       = 0;
                bob->Before      = NULL;
                bob->After       = NULL;
                bob->BobComp     = NULL;

                if (nBob->nb_DBuf)
                    {
                    if (NULL != (bob->DBuffer = (struct DBufPacket *)
                            AllocMem((LONG)sizeof(struct DBufPacket), MEMF_CLEAR)))
                        {
                        if (NULL != (bob->DBuffer->BufBuffer = (WORD *)AllocMem(rassize, MEMF_CHIP)))
                            return(bob);
                        FreeMem(bob->DBuffer, (LONG)sizeof(struct DBufPacket));
                        }
                    }
                else
                    {
                    bob->DBuffer = NULL;
                    return(bob);
                    }
                freeVSprite(vsprite);
                }
            FreeMem(bob->SaveBuffer, rassize);
            }
        FreeMem(bob, (LONG)sizeof(*bob));
        }
