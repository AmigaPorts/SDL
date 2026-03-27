/* Source: ADCD 2.1
 * Section: devices-dev-examples-epsonx-render-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-epsonx-render-c.md
 */

        extern void *AllocMem(), FreeMem();

        extern struct PrinterData *PD;
        extern struct PrinterExtendedData *PED;

        UBYTE *CompactBuf();
        static ULONG BufSize, TotalBufSize, dataoffset;
        static UWORD spacing, colors[MAXCOLORBUFS];
        /*
                00-01   \003P           set pitch (10 or 12 cpi)
                02-02   \022            set condensed fine (on or off)
                03-05   \033W\000       enlarge off
                06-08   \033ln          set left margin to n
                09-11   \033Qn          set right margin to n
                12-12   \015            carriage return
                13-15   \033U1          set uni-directional mode
                16-18   \033t\000       see kludge note below
                Kludge to get this to work on a CBM_MPS-1250  which interprets
                'ESCr' as go into reverse print mode.  The 'ESCt' tells it to
                get out of reverse print mode.  The 'NULL' is ignored by the
                CBM_MPS-1250 and required by all Epson printers as the
                terminator for the 'ESCtNULL' command which means select
                normal char set (which has no effect).
        */

        static UBYTE StartBuf[STARTLEN+1] =
                "\033P\022\033W\000\033ln\033Qn\015\033U1\033t\000";

        UBYTE *ptr, *ptrstart;
        int err;

        switch(status) {
                case 0 : /* Master Initialization */
                        /*
                                ct      - pointer to IODRPReq structure.
                                x       - width of printed picture in pixels.
                                y       - height of printed picture in pixels.
                        */
                        RowSize = x;
                        ColorSize = RowSize + NUMTOTALCMD;
                        if (PD->pd_Preferences.PrintShade == SHADE_COLOR) {
                                NumColorBufs = MAXCOLORBUFS;
                                colors[0] = ColorSize * 3; /* Black */
                                colors[1] = ColorSize * 0; /* Yellow */
                                colors[2] = ColorSize * 1; /* Magenta */
                                colors[3] = ColorSize * 2; /* Cyan */
                                colorcodes[0] = 4; /* Yellow */
                                colorcodes[1] = 1; /* Magenta */
                                colorcodes[2] = 2; /* Cyan */
                                colorcodes[3] = 0; /* Black */
                        }
                        else { /* grey-scale or black&white */
                                NumColorBufs = 1;
                                colors[0] = ColorSize * 0; /* Black */
                                colorcodes[0] = 0; /* Black */
                        }
                        BufSize = ColorSize * NumColorBufs + NUMLFCMD;
                        if (PED->ped_YDotsInch == 216) {
                                TwoBufSize = BufSize * 3;
                                TotalBufSize = BufSize * 6;
                        }
                        else if (PED->ped_YDotsInch == 144) {
                                TwoBufSize = BufSize * 2;
                                TotalBufSize = BufSize * 4;
                        }
                        else {
                                TwoBufSize = BufSize * 1;
                                TotalBufSize = BufSize * 2;
                        }
                        PD->pd_PrintBuf = AllocMem(TotalBufSize, MEMF_PUBLIC);
                        if (PD->pd_PrintBuf == NULL) {
                                err = PDERR_BUFFERMEMORY;
                        }
                        else {
                                dataoffset = NUMSTARTCMD;
                                /*
                                        This printer prints graphics within its
                                        text margins.  This code makes sure the
                                        printer is in 10 cpi and then sets the
                                        left and right margins to their minimum
                                        and maximum values (respectively).  A
                                        carriage return is sent so that the
                                        print head is at the leftmost position
                                        as this printer starts printing from
                                        the print head's position.  The printer
                                        is put into unidirectional mode to
                                        reduce wavy vertical lines.
                                */
                                StartBuf[PITCH] = 'P'; /* 10 cpi */
                                StartBuf[CONDENSED] = '\022'; /* off */
                                /* left margin of 1 */
                                StartBuf[LMARG] = 0;
                                /* right margin of 80 or 136 */
                                StartBuf[RMARG] = PD->pd_Preferences.
                                        PaperSize == W_TRACTOR ? 136 : 80;
                                /* uni-directional mode */
                                StartBuf[DIREC] = '1';
                                err = (*(PD->pd_PWrite))(StartBuf, STARTLEN);
                        }
                        break;

                case 1 : /* Scale, Dither and Render */
                        /*
                                ct      - pointer to PrtInfo structure.
                                x       - 0.
                                y       - row # (0 to Height - 1).
                        */
                        Transfer(ct, y, &PD->pd_PrintBuf[dataoffset], colors,
                                BufSize);
                        err = PDERR_NOERR; /* all ok */
                        break;

                case 2 : /* Dump Buffer to Printer */
                        /*
                                ct      - 0.
                                x       - 0.
                                y       - # of rows sent (1 to NumRows).

                        */
                        /* white-space strip */
                        ptrstart = &PD->pd_PrintBuf[dataoffset - NUMSTARTCMD];
                        if (PED->ped_YDotsInch == 72) {
                                /* y range : 1 to 8 */
                                y = y * 3 - spacing;
                                ptr = CompactBuf(ptrstart + NUMSTARTCMD,
                                        ptrstart, y, 1);
                        }
                        else if (PED->ped_YDotsInch == 144) {
                                /* y range : 1 to 16 */
                                ptr = CompactBuf(ptrstart + NUMSTARTCMD,
                                        ptrstart, 2, 1);
                                if (y > 1) {
                                        ptr = CompactBuf(&PD->pd_PrintBuf[
                                                dataoffset + BufSize],
                                                ptr, y * 3 / 2 - 2, 0);
                                }
                        }
                        else if (PED->ped_YDotsInch == 216) {
                                /* y range : 1 to 24 */
                                ptr = CompactBuf(ptrstart + NUMSTARTCMD,
                                        ptrstart, 1, 1);
                                if (y > 1) {
                                        ptr = CompactBuf(&PD->pd_PrintBuf[
                                                dataoffset + BufSize],
                                                ptr, 1, 0);
                                }
                                if (y > 2) {
                                        ptr = CompactBuf(&PD->pd_PrintBuf[
                                                dataoffset + BufSize * 2],
                                                ptr, y - 2, 0);
                                }
                        }
                        err = (*(PD->pd_PWrite))(ptrstart, ptr - ptrstart);
                        if (err == PDERR_NOERR) {
                                dataoffset = (dataoffset == NUMSTARTCMD ?
                                        TwoBufSize : 0) + NUMSTARTCMD;
                        }
                        break;

                case 3 : /* Clear and Init Buffer */
                        /*
                                ct      - 0.
                                x       - 0.
                                y       - 0.
                        */
                        ClearAndInit(&PD->pd_PrintBuf[dataoffset]);
                        err = PDERR_NOERR;
                        break;

                case 4 : /* Close Down */
                        /*
                                ct      - error code.
                                x       - io_Special flag from IODRPReq.
                                y       - 0.
                        */
                        err = PDERR_NOERR; /* assume all ok */
                        /* if user did not cancel print */
                        if (ct != PDERR_CANCEL) {
                                /* restore preferences pitch and margins */
                                if (PD->pd_Preferences.PrintPitch == ELITE) {
                                        StartBuf[PITCH] = 'M'; /* 12 cpi */
                                }
                                else if (PD->pd_Preferences.PrintPitch == FINE) {
                                        StartBuf[CONDENSED] = '\017'; /* on */
                                }
                                StartBuf[LMARG] =
                                        PD->pd_Preferences.PrintLeftMargin - 1;
                                StartBuf[RMARG] =
                                        PD->pd_Preferences.PrintRightMargin;
                                StartBuf[DIREC] = '0'; /* bi-directional */
                                err = (*(PD->pd_PWrite))(StartBuf, STARTLEN);
                        }
                        (*(PD->pd_PBothReady))();
                        if (PD->pd_PrintBuf != NULL) {
                                FreeMem(PD->pd_PrintBuf, TotalBufSize);
                        }
                        break;

                case 5 :  /* Pre-Master Initialization */
                        /*
                                ct      - 0 or pointer to IODRPReq structure.
                                x       - io_Special flag from IODRPReq.
                                y       - 0.
                        */
                        /* kludge for sloppy tractor mechanism */
                        spacing = PD->pd_Preferences.PaperType == SINGLE ?
                                1 : 0;
                        dpi_code = SetDensity(x & SPECIAL_DENSITYMASK);
                        err = PDERR_NOERR;
                        break;
        }
        return(err);
