/* Source: ADCD 2.1
 * Section: samp-doc-the-body-chunk
 * Library: devices
 * ADCD reference: devices/samp-doc-the-body-chunk.md
 */

    typedef struct {
      ULONG  WaveSize;    /* total # of BYTES in the wave (MUST be even) */
      UWORD  MidiSampNum; /* ONLY USED for Midi Dumps */
      UBYTE  LoopType,    /* ONLY USED for Midi Dumps */
      InsType;            /* Used for searching for a certain instrument */
      ULONG  Period,      /* in nanoseconds at original pitch */
      Rate,               /* # of samples per second at original pitch */
      LoopStart,          /* an offset in BYTES (from the beginning of the
                             of the wave) where the looping portion of the
                               wave begins. Set to WaveSize if no loop. */
      LoopEnd;            /* an offset in BYTES (from the beginning of the
                             of the wave) where the looping portion of the
                             wave ends. Set to WaveSize if no loop. */
      UBYTE  RootNote,    /* the Midi Note # that plays back orig. pitch */
      VelStart;           /* 0 = NO velocity effect, 128 =
                                  negative direction, 64 = positive
                                  direction (it must be one of these 3) */
      UWORD VelTable[16]; /* contains 16 successive offset values
                                 in BYTES from the beginning of the wave */

     /* The ATAK and RLSE segments contain an EGPoint[] piece-wise
        linear envelope just like 8SVX. The structure of an EGPoint[]
        is the same as 8SVX. See that document for details. */

      ULONG  ATAKsize,    /* # of BYTES in subsequent ATAK envelope.
                                If 0, then no ATAK data for this wave. */
      RLSEsize,           /* # of BYTES in subsequent RLSE envelope
                                If 0, then no RLSE envelope follows */

     /* The FATK and FRLS segments contain an EGPoint[] piece-wise
        linear envelope for filtering purposes. This is included in
        the hope that future Amiga audio will incorporate a VCF
        (Voltage Controlled Filter). Until then, if you are doing any
        non-realtime digital filtering, you could store info here. */

     sizeOfFATK,          /* # of BYTES in FATK segment */
     sizeOfFRLS,          /* # of BYTES in FRLS segment */

     USERsize;            /*   # of BYTES in the following data
                                 segment (not including USERtype).
                                 If zero, then no user data */
     UWORD  USERtype;     /* See explanation below. If USERsize
                                = 0, then ignore this. */

    /* End of the waveHeader. */

    /* The data for any ATAK, RLSE, FATK, FRLS, USER, and the actual wave
       data for wave #1 follows in this order:
       Now list each EGPoint[] (if any) for the VCA's
       (Voltage Controlled Amp) attack portion.
       Now list each EGPoint[] for the VCA's (Voltage Controlled Amp)
       release portion.
       List EGPoints[] (if any) for FATK.
       List EGPoints[] if any for FRLS */
