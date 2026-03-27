/* Source: ADCD 2.1
 * Section: dr2d-doc-chdf
 * Library: devices
 * ADCD reference: devices/dr2d-doc-chdf.md
 */

    struct CHDFstruct {
        short   Ch;         /* The character we're defining (ASCII) */
        short   NumPoints;  /* The number of points in the definition */
        IEEE    XWidth,     /* Position for next char on baseline - X */
                YWidth;     /* Position for next char on baseline - Y */
     /* IEEE    Points[2*NumPoints]*/       /* The actual points */
    };

    #define INDICATOR   0xFFFFFFFF  /* If X == INDICATOR, Y is an action */
    #define IND_SPLINE  0x00000001  /* Next 4 pts are spline control pts */
    #define IND_MOVETO  0x00000002    /* Start new subpoly */
    #define IND_STROKE  0x00000004  /* Stroke previous path */
    #define IND_FILL    0x00000008  /* Fill previous path */
