/* Source: ADCD 2.1
 * Section: nonstandard-data-chunks-ccrt
 * Library: devices
 * ADCD reference: devices/nonstandard-data-chunks-ccrt.md
 */

    typedef struct {
        WORD  direction;    /* 0 = don't cycle.  1 = cycle forwards      */
                            /* (1, 2, 3). -1 = cycle backwards (3, 2, 1) */
        UBYTE start, end;   /* lower and upper color registers selected  */
        LONG  seconds;      /* # seconds between changing colors plus... */
        LONG  microseconds; /* # microseconds between changing colors    */
        WORD  pad;          /* reserved for future use; store 0 here     */
        } CycleInfo;
