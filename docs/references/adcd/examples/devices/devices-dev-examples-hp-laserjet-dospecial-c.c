/* Source: ADCD 2.1
 * Section: devices-dev-examples-hp-laserjet-dospecial-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-hp-laserjet-dospecial-c.md
 */

        extern struct PrinterData *PD;
        extern struct PrinterExtendedData *PED;

        static UWORD textlength, topmargin;
        int x, y, j;
        static char initThisPrinter[INIT_LEN] =
                "\033&d@\033&l6D\033(s0b10h1q0p0s3t0u12V";
        static char initForm[FORM_LEN] = "\033&l002e000F";
        static char initMarg[MARG_LEN] = "\033&a000l000M\015";
        static char initTMarg[] = "\033&l000e000F";

        x = y = j = 0;

        if (*command == aRIN) {
                while(x < INIT_LEN) {
                        outputBuffer[x] = initThisPrinter[x];
                        x++;
                }
                outputBuffer[x++] = '\015';

                if (PD->pd_Preferences.PrintSpacing == EIGHT_LPI) {
                        outputBuffer[LPI] = '8';
                }

                if (PD->pd_Preferences.PrintPitch == ELITE) {
                        outputBuffer[CPI] = '2';
                }
                else if (PD->pd_Preferences.PrintPitch == FINE) {
                        outputBuffer[CPI] = '5';
                }

                if (PD->pd_Preferences.PrintQuality == LETTER) {
                        outputBuffer[QUALITY] = '2';
                }

                j = x; /* set the formlength = textlength, top margin = 2 */
                textlength = PD->pd_Preferences.PaperLength;
                topmargin = 2;

                while (y < FORM_LEN) {
                        outputBuffer[x++] = initForm[y++];
                }
                numberString(textlength, j + LPP, outputBuffer);

                Parms[0] = PD->pd_Preferences.PrintLeftMargin;
                Parms[1] = PD->pd_Preferences.PrintRightMargin;
                *command = aSLRM;
        }

        if (*command == aSLRM) {
                j = x;
                y = 0;
                while(y < MARG_LEN) {
                        outputBuffer[x++] = initMarg[y++];
                }
                numberString(Parms[0] - 1, j + LEFT_MARG, outputBuffer);
                numberString(Parms[1] - 1, j + RIGHT_MARG, outputBuffer);
                return(x);
        }

        if ((*command == aSUS2) && (*vline == 0)) {
                *command = aPLU;
                *vline = 1;
                return(0);
        }

        if ((*command == aSUS2) && (*vline < 0)) {
                *command = aRI;
                *vline = 1;
                return(0);
        }

        if ((*command == aSUS1) && (*vline > 0)) {
                *command = aPLD;
                *vline = 0;
                return(0);
        }

        if ((*command == aSUS4) && (*vline == 0)) {
                *command = aPLD;
                *vline = -1;
                return(0);
        }

        if ((*command == aSUS4) && (*vline > 0)) {
                *command = aIND;
                *vline = -1;
                return(0);
        }

        if ((*command == aSUS3) && (*vline < 0)) {
                *command = aPLU;
                *vline = 0;
                return(0);
        }

        if(*command == aSUS0) {
                if (*vline > 0) {
                        *command = aPLD;
                }
                if (*vline < 0) {
                        *command = aPLU;
                }
                *vline = 0;
                return(0);
        }

        if (*command == aPLU) {
                (*vline)++;
                return(0);
        }

        if (*command == aPLD){
                (*vline)--;
                return(0);
        }

        if (*command == aSTBM) {
                if (Parms[0] == 0) {
                        Parms[0] = topmargin;
                }
                else {
                        topmargin = --Parms[0];
                }

                if (Parms[1] == 0) {
                        Parms[1] = textlength;
                }
                else {
                        textlength=Parms[1];
                }
                while (x < 11) {
                        outputBuffer[x] = initTMarg[x];
                        x++;
                }
                numberString(Parms[0], 3, outputBuffer);
                numberString(Parms[1] - Parms[0], 7, outputBuffer);
                return(x);
        }

        if (*command == aSLPP) {
                while(x < 11) {
                        outputBuffer[x] = initForm[x];
                        x++;
                }
                /*restore textlength, margin*/
                numberString(topmargin, 3, outputBuffer);
                numberString(textlength, 7, outputBuffer);
                return(x);
        }

        if (*command == aRIS) {
                PD->pd_PWaitEnabled = 253;
        }

        return(0);
