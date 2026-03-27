/* Source: ADCD 2.1
 * Section: 8svx-chan-pan-doc-optional-data-chunk-pan
 * Library: devices
 * ADCD reference: devices/8svx-chan-pan-doc-optional-data-chunk-pan.md
 */

    #define ID_PAN MakeID('P','A','N',' ')

    typedef sposition Fixed; /* 0 <= sposition <= Unity */

    /* Unity is elsewhere #defined as 10000L, and
     * refers to the maximum possible volume.
     * /

    /* Please note that "Fixed" (elsewhere #defined as LONG) is used to
     * allow for compatabilty between audio hardware of different
     * resolutions.
     * /
