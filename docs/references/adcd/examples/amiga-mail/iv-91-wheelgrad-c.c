/* Source: ADCD 2.1
 * Section: iv-91-wheelgrad-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-91-wheelgrad-c.md
 */

        if (Myscreen)
        {
            /* Get colors and set up gradient slider as color 0. */

            /* get the RGB components of color 0 */
            GetRGB32(Myscreen->ViewPort.ColorMap,0L,32L,colortable);
            rgb.cw_Red   = colortable[0];
            rgb.cw_Green = colortable[1];
            rgb.cw_Blue  = colortable[2];

            /* now convert the RGB values to HSB, and max out B component */
            ConvertRGBToHSB(&rgb,&hsb);
            hsb.cw_Brightness = 0xffffffff;

            numPens = 0;
            while (numPens < GRADCOLORS)
            {
                hsb.cw_Brightness = 0xffffffff - ((0xffffffff / GRADCOLORS) * numPens);
                ConvertHSBToRGB(&hsb,&rgb);

                penns[numPens] = ObtainPen(Myscreen->ViewPort.ColorMap,-1,
                                 rgb.cw_Red,rgb.cw_Green,rgb.cw_Blue,PEN_EXCLUSIVE);
                if (penns[numPens] == -1)
                    break;

                /* Set up LoadRGB32() structure for this pen */
