/* Source: ADCD 2.1
 * Section: iv-91-color-wheel-and-gradient-slider-boopsi-classes
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-91-color-wheel-and-gradient-slider-boopsi-classes.md
 */

     case IDCMP_MOUSEMOVE:

        /*
         * Change gradient slider color each time
         * colorwheel knob is moved.  This is one
         * method you can use.
         */

        /* Query the colorwheel */
        GetAttr(WHEEL_HSB,colwheel,(ULONG *)&hsb);

        i = 0;

        while (i < numPens)
        {
            hsb.cw_Brightness = 0xffffffff - ((0xffffffff / numPens) * i);
            ConvertHSBToRGB(&hsb,&rgb);

            color_list[i].l32_red = rgb.cw_Red;
            color_list[i].l32_grn = rgb.cw_Green;
            color_list[i].l32_blu = rgb.cw_Blue;
            i++;
        }
        LoadRGB32(&Myscreen->ViewPort,(ULONG *)color_list);
        break;
