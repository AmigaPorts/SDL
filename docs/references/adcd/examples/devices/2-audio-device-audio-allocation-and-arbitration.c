/* Source: ADCD 2.1
 * Section: 2-audio-device-audio-allocation-and-arbitration
 * Library: devices
 * ADCD reference: devices/2-audio-device-audio-allocation-and-arbitration.md
 */

     127          Unstoppable. Sounds first allocated at lower precedence,
                  then set to this to the highest level.

     90 - 100     Emergencies.  Alert, urgent situation
                  that requires immediate action.

     80 - 90      Annunciators.  Attention, bell (CTRL-G).

     75           Speech. Synthesized or recorded speech (narrator.device).

     50 - 70      Sonic cues.  Sounds thatprovide information that is not
                  provided by graphics. Only the beginning of each sound
                  (enough to recognize it) should be at this level;the rest
                  should be set to sound effects level.

    -50 - 50      Music program.  Musical notes in music-oriented program.
                  The higher levels should be used for the attack portions
                  of each note.

    -70 - -50     Sound effects.  Sounds used in conjunction with graphics.
                  More important sounds should use higher levels.

    -100 - -80    Background. Theme music and restartable background
                  sounds.

    -128          Silence. Lowest level (freeing the channel completely
                  is preferred).
