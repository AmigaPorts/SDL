/* Source: ADCD 2.1
 * Section: appendix-a-quick-reference-type-definitions
 * Library: devices
 * ADCD reference: devices/appendix-a-quick-reference-type-definitions.md
 */

    #define noteChord  (1<<7)   /* note is chorded to next note          */

    #define noteTieOut (1<<6)   /* tied to next note/chord               */

    #define noteNShift 4        /* shift count for nTuplet field         */

    #define noteN3     (1<<noteNShift)  /* note is a triplet             */
    #define noteN5     (2<<noteNShift)  /* note is a quintuplet          */
    #define noteN7     (3<<noteNShift)  /* note is a septuplet           */

    #define noteNMask  noteN7   /* bit mask for the nTuplet field        */

    #define noteDot    (1<<3)   /* note is dotted                        */



    #define noteD1     0        /* whole note division                   */
    #define noteD2     1        /* half note division                    */
    #define noteD4     2        /* quarter note division                 */
    #define noteD8     3        /* eighth note division                  */
    #define noteD16    4        /* sixteenth note division               */
    #define noteD32    5        /* thirty-secondth note division         */
    #define noteD64    6        /* sixty-fourth note division            */
    #define noteD128   7        /* 1/128 note division                   */
    #define noteDMask  noteD128 /* bit mask for the division field       */


    #define noteDurMask 0x3F    /* mask for combined duration fields     */


    /* SID_Instrument SEvent                                             */
    /* "data" value is an instrument register number 0 through 255.      */

    /* SID_TimeSig SEvent                                                */
    typedef struct {
        UBYTE    type;          /* = SID_TimeSig                         */
        unsigned timeNSig :5,   /* time sig. "numerator" is timeNSig + 1 */
                 timeDSig :3;   /* time sig. "denominator" is 2^timeDSig: *
                                 * 0 = whole note, 1 = half note, 2 =     *
                                 * quarter note,.... 7 = 128th note      */
        } STimeSig;

    #define timeNMask  0xF8     /* bit mask for the timeNSig field       */
    #define timeNShift 3        /* shift count for  timeNSig field       */

    #define timeDMask  0x07     /* bit mask for the timeDSig field       */

    /* SID_KeySig SEvent                                                 */
    /* "data" value 0 = Cmaj; 1 through 7 = G,D,A,E,B,F#,C#;             *
     * 8 through 14 = F,Bb,Eb,Ab,Db,Gb,Cb.                               */

    /* SID_Dynamic SEvent                                                */
    /* "data" value is a MIDI key velocity 0..127.                       */
