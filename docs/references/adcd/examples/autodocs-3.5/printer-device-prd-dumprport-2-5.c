/* Source: ADCD 2.1
 * Section: printer-device-prd-dumprport-2
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/printer-device-prd-dumprport-2.md
 */

    Selecting a density of 2 or higher really doesn't give you true 240 dpi
    resolution since the Xerox_4020 only has 121 x dots per inch.
    Instead this mode tells the printer to go into it's pseudo 240 dpi mode.
    Here, it outputs a line of dots at 121 dpi; moves the paper up 1/240 of
    an inch and outputs the line again (shifted to the right by 1/240 of an
    inch).  This produces much more vibrate colors and gives the illusion
    of more resolution.  One drawback is that large areas of solid colors
    (red, green, and blue specifically) tend to over-saturate the paper with
    ink.
