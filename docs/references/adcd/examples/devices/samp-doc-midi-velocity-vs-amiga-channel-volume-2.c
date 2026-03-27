/* Source: ADCD 2.1
 * Section: samp-doc-midi-velocity-vs-amiga-channel-volume
 * Library: devices
 * ADCD reference: devices/samp-doc-midi-velocity-vs-amiga-channel-volume.md
 */

    lea      SampleData,a0        ;the start addr of the sample data
    moveq    #0,d0
    move.b   ReceivedVelocity,d0  ;the velocity byte of a midi message
    beq      A_NoteOff            ;If zero, branch to a routine to
                                  ;process a note-off message.

    bmi      Illegal_Vol          ;exit if received velocity > 127
    ;---Check for velocity start feature ON, and direction
    move.b   VelStart,d1
    beq.s    Volume               ;skip the velocity offset routine if 0
    bmi.s    NegativeVel          ;is it NEGATIVE? (128)

    ;---Positive velocity offset
    move.l   d0,d1                ;duplicate velocity
    lsr.b    #3,d1                ;divide by 8
    add.b    d1,d1                ;x 2 because we need to fetch a word
    lea      VelTable,a1     ;start at table's HEAD
    adda.l   d1,a1                ;go forward
    move.w   (a1),d1              ;get the velocity offet
    adda.l   d1,a0          ;where to start actual playback
    bra.s    Volume
