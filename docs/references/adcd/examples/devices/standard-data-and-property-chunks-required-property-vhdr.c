/* Source: ADCD 2.1
 * Section: standard-data-and-property-chunks-required-property-vhdr
 * Library: devices
 * ADCD reference: devices/standard-data-and-property-chunks-required-property-vhdr.md
 */

    ULONG oneShotHiSamples, /* # samples in the high octave 1-shot part */
          repeatHiSamples,  /* # samples in the high octave repeat part */
          samplesPerHiCycle;/* # samples/cycle in high octave, else 0   */
    UWORD samplesPerSec;    /* data sampling rate                       */
    UBYTE ctOctave,         /* # octaves of waveforms                   */
          sCompression;     /* data compression technique used          */
    Fixed volume;           /* playback volume from 0 to Unity (full
                             * volume). Map this value into the output
                             * hardware's dynamic range.                */
    } Voice8Header;
