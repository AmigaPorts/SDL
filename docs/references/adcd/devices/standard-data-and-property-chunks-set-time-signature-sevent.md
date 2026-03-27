---
title: Standard Data and Property Chunks / Set Time Signature SEvent
manual: devices
chapter: devices
section: standard-data-and-property-chunks-set-time-signature-sevent
functions: []
libraries: []
---

# Standard Data and Property Chunks / Set Time Signature SEvent

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md) SID_TimeSig sets the time signature for the track.  A "time
signature" SEvent has the following structure overlaid on the [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md)
structure:

```c
    typedef struct {
```
	UBYTE    type;		/* = SID_TimeSig */
	unsigned timeNSig :5,	/* time sig. "numerator" is timeNSig + 1 */
		 timeDSig :3;	/* time sig. "denominator" is 2^timeDSig:*
				 * 0 = whole note, 1 = half note, 2 =    *
				 * quarter note,....7 = 128th note 	 */
	} STimeSig;


[Implementation details.  Unsigned ":n" fields are packed into n bits in
the order shown, most significant bit to least significant bit.  An
STimeSig fits into 16 bits like any other [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md).  Warning: Some compilers
don't implement bit-packed fields properly.  E.g., Lattice C pads a group
of bit fields out to a LONG, which would make an STimeSig take 5-bytes!
In that situation, use the bit-field constants defined below.]

The field type contains the value SID_TimeSig, indicating that this [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md)
is a "time signature" event.  The field timeNSig indicates the time
signature "numerator" is timeNSig + 1, that is, 1 through 32 beats per
measure.  The field timeDSig indicates the time signature "denominator" is
2^(timeDSig), that is each "beat" is a 2^(-timeDSig) note (see SNote
division, above).  So 4/4 time is expressed as timeNSig = 3, timeDSig = 2.

The default time signature is 4/4 time.  Be aware that the time signature
has no effect on the score's playback.  Tempo is uniformly expressed in
quarter notes per minute, independent of time signature.  (Quarter notes
per minute would equal beats per minute only if timeDSig = 2, n/4 time).
Nonetheless, any program that has time signatures should put them at the
beginning of each [TRAK](devices/standard-data-and-property-chunks-data-chunk-trak.md) when creating a FORM [SMUS](devices/smus-iff-simple-musical-score-introduction.md) because music editors
need them.

Instead of the bit-packed structure STimeSig, it might be easier to
assemble data values by or-ing constants and to disassemble them by
masking and shifting.  In that case, use the following definitions.

	#define timeNMask  0xF8	/* bit mask for the timeNSig field	*/
	#define timeNShift 3	/* shift count for  timeNSig field	*/
	#define timeDMask  0x07	/* bit mask for the timeDSig field	*/

