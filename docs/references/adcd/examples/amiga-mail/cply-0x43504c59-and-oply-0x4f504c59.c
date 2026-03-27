/* Source: ADCD 2.1
 * Section: cply-0x43504c59-and-oply-0x4f504c59
 * Library: amiga-mail
 * ADCD reference: amiga-mail/cply-0x43504c59-and-oply-0x4f504c59.md
 */

    typedef union {
        IEEE num;
        LONG bits;
    } Coord;

    #define INDICATOR       0xFFFFFFFF
    #define IND_SPLINE      0x00000001
    #define IND_MOVETO      0x00000002

    /* A common pitfall in attempts to support DR2D has
            been to fail to recognize the case when an
            INDICATOR point indicates the following
            coordinate to be the first point of BOTH a
            Bezier cubic and a sub-polygon, ie. the
            value of the flag = (IND_CURVE | IND_MOVETO) */

    Coord   Temp0, Temp1;
    int     FirstPoint, i, Increment;

    /* Initialize the path */
    NewPath();
    FirstPoint = 1;

    /* Draw the path */
    i = 0;
    while( i < NumPoints ) {
        Temp0.num = PolyPoints[2*i];    Temp1.num = PolyPoints[2*i + 1];
        if( Temp0.bits == INDICATOR ) {
            /* Increment past the indicator */
            Increment = 1;
            if( Temp1.bits & IND_MOVETO ) {
                /* Close and fill, if appropriate */
                if( ID == CPLY ) {
                    FillPath();
                }
                else {
                    StrokePath();
                }

                /* Set up the new path */
                NewPath();
                FirstPoint = 1;
            }
            if( Temp1.bits & IND_CURVE ) {
                /* The next 4 points are Bezier cubic control points */
                if( FirstPoint )
                    MoveTo( PolyPoints[2*i + 2], PolyPoints[2*i + 3] );
                else
                    LineTo( PolyPoints[2*i + 2], PolyPoints[2*i + 3] );
                CurveTo(    PolyPoints[2*i + 4], PolyPoints[2*i + 5],
                            PolyPoints[2*i + 6], PolyPoints[2*i + 7],
                            PolyPoints[2*i + 8], PolyPoints[2*i + 9] );
                FirstPoint = 0;
                /* Increment past the control points */
                Increment += 4;
            }
        }
        else {
            if( FirstPoint )
                MoveTo(     PolyPoints[2*i], PolyPoints[2*i + 1] );
            else
                LineTo(     PolyPoints[2*i], PolyPoints[2*i + 1] );
            FirstPoint = 0;

            /* Increment past the last endpoint */
            Increment = 1;
        }

        /* Add the increment */
        i += Increment;
    }

    /* Close the last path */
    if( ID == CPLY ) {
        FillPath();
    }
    else {
        StrokePath();
    }
