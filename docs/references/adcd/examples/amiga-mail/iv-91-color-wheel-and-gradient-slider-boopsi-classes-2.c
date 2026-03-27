/* Source: ADCD 2.1
 * Section: iv-91-color-wheel-and-gradient-slider-boopsi-classes
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-91-color-wheel-and-gradient-slider-boopsi-classes.md
 */

     #define GRADCOLORS   16       /* Set to 4 for ECS to ensure enough color wheel pens */
     struct load32 color_list[GRADCOLORS + 1];
     WORD penns[GRADCOLORS +1];
     WORD numPens;

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
         color_list[numPens].l32_len = 1;
         color_list[numPens].l32_pen = penns[numPens];
         numPens++;
     }
     penns[numPens] = ~0;
     color_list[numPens].l32_len = 0;
