/* Source: ADCD 2.1
 * Section: samp-doc-midi-velocity-vs-amiga-channel-volume
 * Library: devices
 * ADCD reference: devices/samp-doc-midi-velocity-vs-amiga-channel-volume.md
 */

    If ( ReceivedVelocity != 0 && ReceivedVelocity < 128 )
    {   /* the velocity byte of a midi message */
        If (velStart != 0)
        {
            tableEntry = ReceivedVelocity / 8;
            If (velStart == 64)
            {    /* Is it POSITIVE */
                 startOfWave = SamplePtr + velTable[tableEntry];
                             /* ^where to find the sample start point */
            }
            If (velStart == 128)
            {    /* Is it NEGATIVE */
                 startOfWave = SamplePtr + velTable[15 - tableEntry];
            }
            volume = (receivedVelocity/2 + 1;  /* playback volume */
            /* Now playback the wave */
        }
    }
