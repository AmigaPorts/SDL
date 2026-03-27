/* Source: ADCD 2.1
 * Section: standard-data-and-property-chunks-optional-data-chunks-atak
 * Library: devices
 * ADCD reference: devices/standard-data-and-property-chunks-optional-data-chunks-atak.md
 */

    #define ID_ATAK MakeID('A', 'T', 'A', 'K')
    #define ID_RLSE MakeID('R', 'L', 'S', 'E')

    typedef struct {
        UWORD duration; /* segment duration in milliseconds, > 0 */
        Fixed dest;     /* destination volume factor             */
        } EGPoint;

    /* ATAK and RLSE chunks contain an EGPoint[],        *
     * piecewise-linear envelope.                        */
    /* The envelope defines a function of time returning *
     * Fixed values. It's used to scale the nominal      *
     * volume specified in the Voice8Header.             */
