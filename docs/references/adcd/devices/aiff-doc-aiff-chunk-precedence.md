---
title: AIFF.doc / AIFF / Chunk Precedence
manual: devices
chapter: devices
section: aiff-doc-aiff-chunk-precedence
functions: []
libraries: []
---

# AIFF.doc / AIFF / Chunk Precedence

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Several of the local chunks for FORM AIFF may contain duplicate
information. For example, the Instrument Chunk defines loop points and
MIDI System Exclusive data in the MIDI Data Chunk may also define loop
points.  What happens if these loop points are different?  How is an
application supposed to loop the sound?  Such conflicts are resolved by
defining a precedence for chunks.  This precedence is illustrated in
Figure 10.


                       Common Chunk           Highest Precedence
                            |
                     Sound Data Chunk
                            |
                       Marker Chunk
                            |
                     Instrument Chunk
                            |
                       Comment Chunk
                            |
                        Name Chunk
                            |
                       Author Chunk
                            |
                      Copyright Chunk
                            |
                      Annotation Chunk
                            |
                   Audio Recording Chunk
                            |
                      MIDI Data Chunk
                            |
                 Application Specific Chunk   Lowest Precedence

                Figure 10: Chunk Precedence
The Common Chunk has the highest precedence, while the Application
Specific Chunk has the lowest.  Information in the Common Chunk always
takes precedence over conflicting information in any other chunk.  The
Application Specific Chunk always loses in conflicts with other chunks.
By looking at the chunk hierarchy, for example, one sees that the loop
points in the Instrument Chunk take precedence over conflicting loop
points found in the MIDI Data Chunk.

It is the responsibility of applications that write data into the lower
precedence chunks to make sure that the higher precedence chunks are
updated accordingly.

Figure 11 illustrates an example of a FORM AIFF.  An Audio IFF file is
simple a file containing a single FORM AIFF.  The FORM AIFF is stored in
the data fork of Macintosh file systems that can handle resource forks.


     _____________________________________________________________________
    | FORM AIFF                                                           |
    |                          _____________                              |
    |                    ckID |_ 'FORM' ____|                             |
    |                  ckSize |_ 176516 ____|                             |
    |  _____________ formType |_ 'AIFF' ____| __________________________  |
    | | Common           ckID |_ 'COMM' ____|                           | |
    | | Chunk          ckSize |_ 18 ________|                           | |
    | |           numChannels |_ 2 ___|_____                            | |
    | |       numSampleFrames |_ 88200 _____|                           | |
    | |            sampleSize |_ 16 __|_______________________________  | |
    | |___________ sampleRate |_ 44100.00 ____________________________| | |
    | | Marker           ckID |_ 'MARK' _____|                          | |
    | | Chunk          ckSize |_ 34 _________|                          | |
    | |            numMarkers |_ 2 ___|                                 | |
    | |                    id |_ 1 ___|_______                          | |
    | |              position |_ 44100 ___ ___|___ ___ ___ ___ ___ ___  | |
    | |            markerName | 8 |'b'|'e'|'g'|' '|'l'|'o'|'o'|'p'| 0 | | |
    | |                    id |_ 2 ___|_______                          | |
    | |              position |_ 88200 _______|___ ___ ___ ___ ___ ___  | |
    | |___________ markerName | 8 |'e'|'n'|'d'|' '|'l'|'o'|'o'|'p'| 0 | | |
    | | Instrument       ckID |_ 'INST' ______|                         | |
    | | Chunk          ckSize |_ 20 __________|                         | |
    | |              baseNote | 60|                                     | |
    | |                detune | -3|                                     | |
    | |               lowNote | 57|                                     | |
    | |              highNote | 63|                                     | |
    | |           lowVelocity | 1 |                                     | |
    | |          highVelocity |127|__                                   | |
    | |                  gain |_ 6 __|                                  | |
    | |  sustainLoop.playMode |_ 1 __|                                  | |
    | | sustainLoop.beginLoop |_ 1 __|                                  | |
    | |   sustainLoop.endLoop |_ 2 __|                                  | |
    | |  releaseLoop.playMode |_ 0 __|                                  | |
    | | releaseLoop.beginLoop |_ - __|                                  | |
    | |__ releaseLoop.endLoop |_ - __|__________________________________| |
    | | Sound            ckID |_ 'SSND' ______|                         | |
    | | Data           ckSize |_ 176408 ______|                         | |
    | | Chunk          offset |_ 0 ___________|                         | |
    | |             blockSize |_ 0 ___________|        _______ _______  | |
    | |             soundData |_ch 1 _|_ch 2 _| . . . |_ch 1 _|_ch 2 _| | |
    | |                       first sample frame   88200th sample frame | |
    | |_________________________________________________________________| |
    |_____________________________________________________________________|

                         Figure 11: Sample FORM AIFF
