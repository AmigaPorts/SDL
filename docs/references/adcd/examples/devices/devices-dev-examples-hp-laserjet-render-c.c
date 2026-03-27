/* Source: ADCD 2.1
 * Section: devices-dev-examples-hp-laserjet-render-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-hp-laserjet-render-c.md
 */

        extern void *AllocMem(), FreeMem();

        extern struct PrinterData *PD;
        extern struct PrinterExtendedData *PED;

        static UWORD RowSize, BufSize, TotalBufSize, dataoffset;
        static UWORD huns, tens, ones; /* used to program buffer size */
        UBYTE *ptr, *ptrstart;
        int i, err;

        err=PDERR_NOERR;
        switch(status) {
                case 0 : /* Master Initialization */
                        /*
                                ct      - pointer to IODRPReq structure.
                                x       - width of printed picture in pixels.
                                y       - height of printed picture in pixels.
                        */
                        RowSize = (x + 7) / 8;
                        BufSize = RowSize + NUMTOTALCMD;
                        TotalBufSize = BufSize * 2;
                        PD->pd_PrintBuf = AllocMem(TotalBufSize, MEMF_PUBLIC);
                        if (PD->pd_PrintBuf == NULL) {
                                err = PDERR_BUFFERMEMORY; /* no mem */
                        }
                        else {
                                ptr = PD->pd_PrintBuf;
                                *ptr++ = 27;
                                *ptr++ = '*';
                                *ptr++ = 'b';   /* transfer raster graphics */
                                *ptr++ = huns | '0';
                                *ptr++ = tens | '0';
                                *ptr++ = ones | '0';    /* printout width */
                                *ptr = 'W';             /* terminator */
                                ptr = &PD->pd_PrintBuf[BufSize];
                                *ptr++ = 27;
                                *ptr++ = '*';
                                *ptr++ = 'b';   /* transfer raster graphics */
                                *ptr++ = huns | '0';
                                *ptr++ = tens | '0';
                                *ptr++ = ones | '0';    /* printout width */
                                *ptr = 'W';             /* terminator */
                                dataoffset = NUMSTARTCMD;
                        /* perf skip mode off, set dpi, start raster gfx */
                                err = (*(PD->pd_PWrite))(StartCmd, 17);
                        }
                        break;

                case 1 : /* Scale, Dither and Render */
                        /*
                                ct      - pointer to PrtInfo structure.
                                x       - 0.
                                y       - row # (0 to Height - 1).
                        */
                        Transfer(ct, y, &PD->pd_PrintBuf[dataoffset]);
                        err = PDERR_NOERR; /* all ok */
                        break;

                case 2 : /* Dump Buffer to Printer */
                        /*
                                ct      - 0.
                                x       - 0.
                                y       - # of rows sent (1 to NumRows).
                                White-space strip.
                        */
                        i = RowSize;
                        ptrstart = &PD->pd_PrintBuf[dataoffset - NUMSTARTCMD];
                        ptr = ptrstart + NUMSTARTCMD + i - 1;
                        while (i > 0 && *ptr == 0) {
                                i--;
                                ptr--;
                        }
                        ptr = ptrstart + 3; /* get ptr to density info */
                        *ptr++ = (huns = i / 100) | '0';
                        *ptr++ = (i - huns * 100) / 10 | '0';
                        *ptr = i % 10 | '0'; /* set printout width */
                        err = (*(PD->pd_PWrite))(ptrstart, i + NUMTOTALCMD);
                        if (err == PDERR_NOERR) {
                                dataoffset = (dataoffset == NUMSTARTCMD ?
                                        BufSize : 0) + NUMSTARTCMD;
                        }
                        break;

                case 3 : /* Clear and Init Buffer */
                        /*
                                ct      - 0.
                                x       - 0.
                                y       - 0.
                        */
                        ptr = &PD->pd_PrintBuf[dataoffset];
                        i = RowSize;
                        do {
                                *ptr++ = 0;
                        } while (--i);
                        break;

                case 4 : /* Close Down */
                        /*
                                ct      - error code.
                                x       - io_Special flag from IODRPReq struct
                                y       - 0.
                        */
                        err = PDERR_NOERR; /* assume all ok */
                        /* if user did not cancel the print */
                        if (ct != PDERR_CANCEL) {
                                /* end raster graphics, perf skip mode on */
                                if ((err = (*(PD->pd_PWrite))
                                        ("\033*rB\033&l1L", 9)) == PDERR_NOERR) {
                                        /* if want to unload paper */
                                        if (!(x & SPECIAL_NOFORMFEED)) {
                                                /* eject paper */
                                                err = (*(PD->pd_PWrite))
                                                        ("\014", 1);
                                        }
                                }
                        }
                        /*
                                flag that there is no alpha data waiting that
                                needs a formfeed (since we just did one)
                        */
                        PED->ped_PrintMode = 0;
                         /* wait for both buffers to empty */
                        (*(PD->pd_PBothReady))();
                        if (PD->pd_PrintBuf != NULL) {
                                FreeMem(PD->pd_PrintBuf, TotalBufSize);
                        }
                        break;

                case 5 : /* Pre-Master Initialization */
                        /*
                                ct      - 0 or pointer to IODRPReq structure.
                                x       - io_Special flag from IODRPReq struct
                                y       - 0.
                        */
                        /* select density */
                        SetDensity(x & SPECIAL_DENSITYMASK);
                        break;
        }
        return(err);
