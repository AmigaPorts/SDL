/* Source: ADCD 2.1
 * Section: samp-doc-midi-velocity-vs-amiga-channel-volume
 * Library: devices
 * ADCD reference: devices/samp-doc-midi-velocity-vs-amiga-channel-volume.md
 */

    ;---Negative velocity offset
    move.l   d0,d1                ;duplicate velocity
    lsr.b    #3,d1                ;divide by 8
    add.b    d1,d1                ;x 2 because we need to fetch a word
    lea      VelTable+30,a1  ;start at table's END
    suba.l   d1,a1                ;go backwards
    move.w   (a1),d1              ;get the velocity offset
    adda.l   d1,a0          ;where to start actual playback

    ;---Convert Midi velocity to an Amiga volume
