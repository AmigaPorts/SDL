---
title: Standard Data and Property Chunks / Optional Data Chunks ATAK and RLSE
manual: devices
chapter: devices
section: standard-data-and-property-chunks-optional-data-chunks-atak
functions: []
libraries: []
---

# Standard Data and Property Chunks / Optional Data Chunks ATAK and RLSE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The optional data chunks ATAK and [RLSE](devices/standard-data-and-property-chunks-optional-data-chunks-atak.md) together give a piecewise-linear
"envelope" or "amplitude contour".  This contour may be used to modulate
the sound during playback.  It's especially useful for playing musical
notes of variable durations.  Playback programs may ignore the supplied
envelope or substitute another.


```c
    #define ID_ATAK MakeID('A', 'T', 'A', 'K')
    #define ID_RLSE MakeID('R', 'L', 'S', 'E')

    typedef struct {
        UWORD duration; /* segment duration in milliseconds, > 0 */
        Fixed dest;     /* destination volume factor             */
        } EGPoint;

    /* ATAK and RLSE chunks contain an EGPoint[],        *
     * piecewise-linear envelope.                        */
    /* The envelope defines a function of time returning *
     * Fixed values. It's used to scale the nominal      *
     * volume specified in the Voice8Header.             */
```
To explain the meaning of the ATAK and RLSE chunks, we'll overview the
envelope generation algorithm.  Start at 0 volume, step through the ATAK
contour, then hold at the sustain level (the last ATAK EGPoint's dest),
and then step through the RLSE contour.  Begin the release at the desired
note stop time minus the total duration of the release contour (the sum of
the RLSE EGPoints' durations).  The attack contour should be cut short if
the note is shorter than the release contour.

The envelope is a piecewise-linear function.  The envelope generator
interpolates between the EGPoints.

Remember to multiply the envelope function by the nominal voice header
volume and by any desired note volume.

Figure 1 shows an example envelope.  The attack period is described by 4
EGPoints in an ATAK chunk.  The release period is described by 4 EGPoints
in a RLSE chunk.  The sustain period in the middle just holds the final
ATAK level until it's time for the release.


        ^
(volume)|               |             |
	|       .       |             |
	|      / \      |             |
	|     /   \.__. |             |
	|    /         \|_____________|
	|   /           |             |\.__.
	|  /            |             |     \

```c
        | /             |             |      \
        |/              |             |       \
        +-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|---------> (time)

              ATAK        sustain         RLSE
```
	      Figure 1. Amplitude contour.


Note: The number of EGPoints in an ATAK or RLSE chunk is its ckSize /
sizeof(EGPoint).  In RAM, the playback program may terminate the array
with a 0 duration EGPoint.

Issue: Synthesizers also provide frequency contour (pitch bend), filtering
contour (wah-wah), amplitude oscillation (tremolo), frequency oscillation
(vibrato), and filtering oscillation (leslie).  In the future, we may
define optional chunks to encode these modulations.  The contours can be
encoded in linear segments.  The oscillations can be stored as segments
with rate and depth parameters.

