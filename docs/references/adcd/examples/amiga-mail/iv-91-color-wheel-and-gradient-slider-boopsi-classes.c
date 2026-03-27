/* Source: ADCD 2.1
 * Section: iv-91-color-wheel-and-gradient-slider-boopsi-classes
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-91-color-wheel-and-gradient-slider-boopsi-classes.md
 */

     struct ColorWheelRGB rgb;
     struct ColorWheelHSB hsb;

     /* set RGB values for color 0 in ColorWheelRGB structure */
     rgb.cw_Red   = colortable[0];
     rgb.cw_Green = colortable[1];
     rgb.cw_Blue  = colortable[2];

     /* now convert the RGB values to HSB */
     ConvertRGBToHSB(&rgb,&hsb);
