/* Source: ADCD 2.1
 * Section: samp-doc-the-mhdr-chunk
 * Library: devices
 * ADCD reference: devices/samp-doc-the-mhdr-chunk.md
 */

    #define ID_MHDR MakeID('M','H','D','R')

      /* MHDR size is dependant on the size of the imbedded PlayMap. */

       typedef struct{
        UBYTE NumOfWaves, /* The number of waves in this file */
          Format,         /* # of ORIGINAL significant bits from 8-28 */
          Flags,          /* Various bits indicate various functions */
          PlayMode,       /* determines play MODE of the PlayMap */
          NumOfChans,
          Pad,
          PlayMap[128*4], /* a map of which wave numbers to use for
                           each of 128 possible Midi Notes. Default to 4 */
        } MHDRChunk;
