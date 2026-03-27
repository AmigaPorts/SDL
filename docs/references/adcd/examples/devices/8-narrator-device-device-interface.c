/* Source: ADCD 2.1
 * Section: 8-narrator-device-device-interface
 * Library: devices
 * ADCD reference: devices/8-narrator-device-device-interface.md
 */

    struct narrator_rb
    {
       struct IOStdReq  message; /* Standard IORequest Block       */
       UWORD   rate;             /* Speaking rate (words/minute)   */
       UWORD   pitch;            /* Baseline pitch in Hertz        */
       UWORD   mode;             /* Pitch mode                     */
       UWORD   sex;              /* Sex of voice                   */
       UBYTE   *ch_masks;        /* Pointer to audio allocation maps  */
       UWORD   nm_masks;         /* Number of audio allocation maps   */
       UWORD   volume;           /* Volume. 0 (off) thru 64        */
       UWORD   sampfreq;         /* Audio sampling frequency       */
       UBYTE   mouths;           /* If non-zero, generate mouths   */
       UBYTE   chanmask; /* Which ch mask used (internal - do not modify)*/
       UBYTE   numchan;  /* Num ch masks used (internal- do not modify) */
       UBYTE   flags;            /* New feature flags              */
       UBYTE   F0enthusiasm;     /* F0 excursion factor            */
       UBYTE   F0perturb;        /* Amount of F0 perturbation      */
       BYTE    F1adj;            /* F1 adjustment in +- 5% steps   */
       BYTE    F2adj;            /* F2 adjustment in +- 5% steps   */
       BYTE    F3adj;            /* F3 adjustment in +- 5% steps   */
       BYTE    A1adj;            /* A1 adjustment in decibels      */
       BYTE    A2adj;            /* A2 adjustment in decibels      */
       BYTE    A3adj;            /* A3 adjustment in decibels      */
       UBYTE   articulate;       /* Transition time multiplier     */
       UBYTE   centralize;       /* Degree of vowel centralization */
       char    *centphon;        /* Pointer to central ASCII phon  */
       BYTE    AVbias;           /* Amplitude of voicing bias      */
       BYTE    AFbias;           /* Amplitude of frication bias    */
       BYTE    priority;         /* Priority while speaking        */
       BYTE    pad1;             /* For alignment                  */
    };

    struct mouth_rb
    {
       struct  narrator_rb voice;/* Speech IORequest Block         */
       UBYTE   width;            /* Mouth width (returned value)   */
       UBYTE   height;           /* Mouth height (returned value)  */
       UBYTE   shape;            /* Internal use, do not modify    */
       UBYTE   sync;             /* Returned sync events           */
    };
