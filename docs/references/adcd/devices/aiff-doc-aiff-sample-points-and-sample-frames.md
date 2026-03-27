---
title: AIFF.doc / AIFF / Sample Points and Sample Frames
manual: devices
chapter: devices
section: aiff-doc-aiff-sample-points-and-sample-frames
functions: []
libraries: []
---

# AIFF.doc / AIFF / Sample Points and Sample Frames

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A large part of interpreting Audio IFF files revolves around the two
concepts of sample points and sample frames.

A sample point is a value representing a sample of a sound at a given
point in time.  Each sample point is stored as a linear, 2's-complement
value which may be from 1 to 32 bits wide, as determined by sampleSize in
the Common Chunk.

Sample points are stored in an integral number of contiguous bytes.  One-
to eight-bit wide sample points are stored in one byte, 9- to 16-bit wide
sample points are stored in two bytes, 17- to 24-bit wide sample points
are stored in three bytes, and 25- to 32-bit wide sample points are stored
in four bytes (most significant byte first).  When the width of a sample
point is not a multiple of eight bits, the sample point data is left
justified, with the remaining bits zeroed.  An example case is illustrated
in Figure 4.  A 12-bit sample point, binary 101000010111, is stored left
justified in two bytes. The remaining bits are set to zero.


     ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___
    |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
    | 1   0   1   0   0   0   0   1 | 0   1   1   1   0   0   0   0 |
    |___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|
     <---------------------------------------------> <------------->
          12 bit sample point is left justified         rightmost
                                                        4 bits are
                                                        zero padded
                      Figure 4: 12-Bit Sample Point
For multichannel sounds, single sample points from each channel are
interleaved.  A set of interleaved sample points is called a sample frame.
Single sample points from each channel are interleaved such that each
sample frame is a sample point from the same moment in time for each
channel available.  This is illustrated in Figure 5 for the stereo (two
channel) case.


```c
                   sample      sample              sample
                   frame 0     frame 1             frame N
                 _____ _____ _____ _____         _____ _____
                | ch1 | ch2 | ch1 | ch2 | . . . | ch1 | ch2 |
                |_____|_____|_____|_____|       |_____|_____|
                             _____
                            |     | = one sample point
                            |_____|

                Figure 5: Sample Frames for Multichannel Sound
```
For monophonic sound, a sample frame is a single sample point.  For
multichannel sounds, you should follow the conventions in Figure 6.

                                       channel
               1          2          3          4          5          6
             _________ _________ _________ _________ _________ _________
            | left    | right   |         |         |         |         |
  stereo    |         |         |         |         |         |         |
            |_________|_________|_________|_________|_________|_________|
            | left    | right   | center  |         |         |         |
  3 channel |         |         |         |         |         |         |
            |_________|_________|_________|_________|_________|_________|
            | front   | front   | rear    | rear    |         |         |
  quad      | left    | right   | left    | right   |         |         |
            |_________|_________|_________|_________|_________|_________|
            | left    | center  | right   | surround|         |         |
  4 channel |         |         |         |         |         |         |
            |_________|_________|_________|_________|_________|_________|
            | left    | left    | center  | right   | right   |surround |
  6 channel |         | center  |         |         | center  |         |

            |_________|_________|_________|_________|_________|_________|

             Figure 6: Sample Frame Conventions for Multichannel Sound
Sample frames are stored contiguously in order of increasing time.  The
sample points within a sample frame are packed together; there are no
unused bytes between them.  Likewise, the sample frames are packed
together with no pad bytes.

