/* Source: ADCD 2.1
 * Section: lib-examples-dualplayfield-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-dualplayfield-c.md
 */

    {
    /* Get a rastport, and set it up for rendering into bmap2 */
    rport2 = (struct RastPort *) AllocMem(sizeof(struct RastPort), MEMF_PUBLIC );
    if (rport2 != NULL )
        {
        bmap2 = (struct BitMap *) AllocMem(sizeof(struct BitMap), MEMF_PUBLIC | MEMF_CLEAR);
        if (bmap2 != NULL )
            {
            InitBitMap(bmap2, 1, myscreen->Width, myscreen->Height);

            /* extra playfield will only use one bitplane here. */
            bmap2->Planes[0] = (PLANEPTR) AllocRaster(myscreen->Width, myscreen->Height);
            if (bmap2->Planes[0] != NULL )
                {
                InitRastPort(rport2);
                rport2->BitMap = rinfo2->BitMap = bmap2;

                SetRast(rport2, 0);

                if (installDualPF(myscreen,rinfo2))
                    {
                    /* Set foreground color; color 9 is color 1 for
                    ** second playfield of hi-res viewport
                    */
                    SetRGB4(&myscreen->ViewPort, 9, 0, 0xF, 0);

                    drawSomething(rport2);

                    handleIDCMP(win);

                    removeDualPF(myscreen);
                    }
                FreeRaster(bmap2->Planes[0], myscreen->Width, myscreen->Height);
                }
            FreeMem(bmap2, sizeof(struct BitMap));
            }
        FreeMem(rport2, sizeof(struct RastPort));
        }
    FreeMem(rinfo2, sizeof(struct RasInfo));
    }
