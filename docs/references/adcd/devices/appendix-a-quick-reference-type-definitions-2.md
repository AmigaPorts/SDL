---
title: Appendix A. Quick Reference / Type Definitions
manual: devices
chapter: devices
section: appendix-a-quick-reference-type-definitions-2
functions: []
libraries: []
---

# Appendix A. Quick Reference / Type Definitions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#define ID_8SVX MakeID('8', 'S', 'V', 'X')
#define ID_VHDR MakeID('V', 'H', 'D', 'R')

typedef LONG Fixed;    /* A fixed-point value, 16 bits to the left of  *
                          the point and 16 to the right. A Fixed is a  *
                          number of 2^16ths, i.e., 65536ths.           */
#define Unity 0x10000L /* Unity = Fixed 1.0 = maximum volume           */


/* sCompression: Choice of compression algorithm.                    */
#define sCmpNone       0    /* not compressed                        */
#define sCmpFibDelta   1    /* Fibonacci-delta encoding (Appendix C) */

                            /* Can be more kinds in the future.      */
typedef struct {

```c
    ULONG oneShotHiSamples, /* # samples in the high octave 1-shot part */
          repeatHiSamples,  /* # samples in the high octave repeat part */
          samplesPerHiCycle;/* # samples/cycle in high octave, else 0   */
    UWORD samplesPerSec;    /* data sampling rate                       */
    UBYTE ctOctave,         /* # octaves of waveforms                   */
          sCompression;     /* data compression technique used          */
    Fixed volume;           /* playback volume from 0 to Unity (full    *
                             * volume). Map this value into the output  *
                             * hardware's dynamic range.                */
    } Voice8Header;
```
#define ID_NAME MakeID('N', 'A', 'M', 'E')
/* NAME chunk contains a CHAR[], the voice's name.                     */

#define ID_Copyright MakeID('(', 'c', ')', ' ')
/* "(c) " chunk contains a CHAR[], the FORM's copyright notice.        */

#define ID_AUTH MakeID('A', 'U', 'T', 'H')
/* AUTH chunk contains a CHAR[], the author's name.                    */

#define ID_ANNO MakeID('A', 'N', 'N', 'O')
/* ANNO chunk contains a CHAR[], author's text annotations.            */

#define ID_ATAK MakeID('A', 'T', 'A', 'K')
#define ID_RLSE MakeID('R', 'L', 'S', 'E')

typedef struct {


```c
    UWORD duration; /* segment duration in milliseconds, > 0           */
    Fixed dest;     /* destination volume factor                       */
    } EGPoint;
```
/* ATAK and RLSE chunks contain an EGPoint[],piecewise-linear envelope. */
/* The envelope defines a function of time returning Fixed values. It's *
 * used to scale the nominal volume specified in the Voice8Header.      */

#define ID_BODY MakeID('B', 'O', 'D', 'Y')
typedef character BYTE;     /* 8 bit signed number, -128 through 127.   */
/* BODY chunk contains a BYTE[], array of audio data samples.           */

