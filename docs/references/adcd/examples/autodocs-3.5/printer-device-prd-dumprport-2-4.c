/* Source: ADCD 2.1
 * Section: printer-device-prd-dumprport-2
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/printer-device-prd-dumprport-2.md
 */

    242x120(color)(3).
    Selecting a density of 2 or higher really doesn't give you true 242 dpi
    resolution since the printer only has 121 x dots per inch.
    Instead this mode tells the printer to go into it's double pass mode.
    Here, it outputs a line of dots at 121 dpi; and outputs the line again
    (shifted to the right by 1/242 of an inch).  This produces much more
    vibrate colors and gives the illusion of more resolution.  One drawback
    is that large areas of solid colors (red, green, and blue specifically)
    tend to over-saturate the paper with ink.  Density1 outputs all colors
    in one pass.  Density 2 does a double pass on black.  Density 3 does a
    double pass on all colors.  Density 1 to 3 correspond to the printer's
    graphics printing modes 1 to 3 (respectively).
