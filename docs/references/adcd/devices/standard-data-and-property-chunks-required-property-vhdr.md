---
title: Standard Data and Property Chunks / Required Property VHDR
manual: devices
chapter: devices
section: standard-data-and-property-chunks-required-property-vhdr
functions: []
libraries: []
---

# Standard Data and Property Chunks / Required Property VHDR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The required property "VHDR" holds a Voice8Header structure as defined in
these C declarations and following documentation.  This structure holds
the playback parameters for the sampled waveforms in the [BODY](devices/standard-data-and-property-chunks-data-chunk-body.md) chunk.  (See
"Data Chunk BODY", below, for the storage layout of these waveforms.)


#define ID_8SVX MakeID('8', 'S', 'V', 'X')
#define ID_VHDR MakeID('V', 'H', 'D', 'R')

typedef LONG Fixed;    /* A fixed-point value, 16 bits to the left of the
                          point and 16 to the right.  A Fixed is a number
                          of 2^16ths, i.e., 65536ths.                    */
#define Unity 0x10000L /* Unity = Fixed 1.0 = maximum volume             */

/* sCompression: Choice of compression algorithm applied to the samples. */
#define sCmpNone       0    /* not compressed                            */
#define sCmpFibDelta   1    /* Fibonacci-delta encoding (Appendix C)     */


                            /* Can be more kinds in the future.          */
typedef struct {


```c
    ULONG oneShotHiSamples, /* # samples in the high octave 1-shot part */
          repeatHiSamples,  /* # samples in the high octave repeat part */
          samplesPerHiCycle;/* # samples/cycle in high octave, else 0   */
    UWORD samplesPerSec;    /* data sampling rate                       */
    UBYTE ctOctave,         /* # octaves of waveforms                   */
          sCompression;     /* data compression technique used          */
    Fixed volume;           /* playback volume from 0 to Unity (full
                             * volume). Map this value into the output
                             * hardware's dynamic range.                */
    } Voice8Header;
```
[Implementation details.  Fields are filed in the order shown.  The UBYTE
fields are byte-packed (2 per 16-bit word).  MakeID is a C macro defined
in the main IFF document and in the source file IFF.h.]

A [FORM 8SVX](devices/8svx-iff-8-bit-sampled-voice-introduction.md) holds waveform data for one or more octaves, each containing a
one-shot part and a repeat part.  The fields oneShotHiSamples and
repeatHiSamples tell the number of audio samples in the two parts of the
highest frequency octave.  Each successive (lower frequency) octave
contains twice as many data samples in both its one-shot and repeat parts.
One of these two parts can be empty across all octaves.

Note: Most audio output hardware and software has limitations.  For
example the Amiga computer has sound hardware that requires that all
one-shot and repeat parts have even numbers of samples.  Amiga sound
driver software should adjust an odd-sized waveform, ignore an odd-sized
lowest octave, or ignore odd 8SVX FORMs altogether.  Some other output
devices require all sample sizes to be powers of two.

The field samplesPerHiCycle tells the number of samples/cycle in the
highest frequency octave of data, or else 0 for "unknown".  Each
successive (lower frequency) octave contains twice as many samples/cycle.
The samplesPerHiCycle value is needed to compute the data rate for a
desired playback pitch.

Actually, samplesPerHiCycle is an average number of samples/cycle.  If the
one-shot part contains pitch bends, store the samples/cycle of the repeat
part in samplesPerHiCycle.  The division repeatHiSamples/samplesPerHiCycle
should yield an integer number of cycles.  (When the repeat waveform is
repeated, a partial cycle would come out as a higher-frequency cycle with
a "click".)

More limitations: some Amiga music drivers require samplesPerHiCycle to be
a power of two in order to play the [FORM 8SVX](devices/8svx-iff-8-bit-sampled-voice-introduction.md) as a musical instrument in
tune. They may even assume samplesPerHiCycle is a particular power of two
without checking.  (If samplesPerHiCycle is different by a factor of two,
the instrument will just be played an octave too low or high.)

The field samplesPerSec gives the sound sampling rate.  A program may
adjust this to achieve frequency shifts or vary it dynamically to achieve
pitch bends and vibrato.  A program that plays a [FORM 8SVX](devices/8svx-iff-8-bit-sampled-voice-introduction.md) as a musical
instrument would ignore samplesPerSec and select a playback rate for each
musical pitch.

The field ctOctave tells how many octaves of data are stored in the BODY
chunk.  See "Data Chunk [BODY](devices/standard-data-and-property-chunks-data-chunk-body.md)", below, for the layout of the octaves.

The field sCompression indicates the compression scheme, if any, that was
applied to the entire set of data samples stored in the [BODY](devices/standard-data-and-property-chunks-data-chunk-body.md) chunk.  This
field should contain one of the values defined above.  Of course, the
matching decompression algorithm must be applied to the BODY data before
the sound can be played.  (The Fibonacci-delta encoding scheme
sCmpFibDelta is described in [Appendix C](devices/8svx-iff-8-bit-sampled-voice-appendix-c-fibonacci-delta.md).)  Note that the whole series of
data samples is compressed as a unit.

The field volume gives an overall playback volume for the waveforms (all
octaves).  It lets the 8-bit data samples use the full range -128 through
127 for good signal-to-noise ratio.  The playback program should multiply
this value by a "volume control" and perhaps by a playback envelope (see
[ATAK](devices/standard-data-and-property-chunks-optional-data-chunks-atak.md) and [RLSE](devices/standard-data-and-property-chunks-optional-data-chunks-atak.md), below).

Recording a one-shot sound.  To store a one-shot sound in a [FORM 8SVX](devices/8svx-iff-8-bit-sampled-voice-introduction.md), set
oneShotHiSamples = number of samples, repeatHiSamples = 0 ,
samplesPerHiCycle = 0, samplesPerSec = sampling rate, and ctOctave = 1.
Scale the signal amplitude to the full sampling range -128 through 127.
Set volume so the sound will playback at the desired volume level.  If you
set the samplesPerHiCycle field properly, the data can also be used as a
musical instrument.

Experiment with data compression.  If the decompressed signal sounds OK,
store the compressed data in the [BODY](devices/standard-data-and-property-chunks-data-chunk-body.md) chunk and set sCompression to the
compression code number.

Recording a musical instrument.  To store a musical instrument in a FORM
8SVX, first record or synthesize as many octaves of data as you want to
make available for playback.  Set ctOctave to the count of octaves.  From
the recorded data, excerpt an integral number of steady state cycles for
the repeat part and set repeatHiSamples and samplesPerHiCycle.  Either
excerpt a startup transient waveform and set oneShotHiSamples, or else set
oneShotHiSamples to 0.  Remember, the one-shot and repeat parts of each
octave must be twice as long as those of the next higher octave.  Scale
the signal amplitude to the full sampling range and set volume to adjust
the instrument playback volume.  If you set the samplesPerSec field
properly, the data can also be used as a one-shot sound.

A distortion-introducing compressor like sCmpFibDelta is not recommended
for musical instruments, but you might try it anyway.

Typically, creators of [FORM 8SVX](devices/8svx-iff-8-bit-sampled-voice-introduction.md) record an acoustic instrument at just one
frequency.  Decimate (down-sample with filtering) to compute higher
octaves. Interpolate to compute lower octaves.

If you sample an acoustic instrument at different octaves, you may find it
hard to make the one-shot and repeat waveforms follow the factor-of-two
rule for octaves.  To compensate, lengthen an octave's one-shot part by
appending replications of the repeating cycle or prepending zeros.  (This
will have minimal impact on the sound's start time.)  You may be able to
equalize the ratio of one-shot-samples to repeat-samples across all
octaves.

Note that a "one-shot sound" may be played as a "musical instrument" and
vice-versa.  However, an instrument player depends on samplesPerHiCycle,
and a one-shot player depends on samplesPerSec.

Playing a one-shot sound.  To play any [FORM 8SVX](devices/8svx-iff-8-bit-sampled-voice-introduction.md) data as a one-shot sound,
first select an octave if ctOctave > 1.  (The lowest-frequency octave has
the greatest resolution.)  Play the one-shot samples then the repeat
samples, scaled by volume, at a data rate of samplesPerSec.  Of course,
you may adjust the playback rate and volume.  You can play out an
envelope, too.  (See [ATAK](devices/standard-data-and-property-chunks-optional-data-chunks-atak.md) and [RLSE](devices/standard-data-and-property-chunks-optional-data-chunks-atak.md), below.) 

Playing a musical note.  To play a musical note using any [FORM 8SVX](devices/8svx-iff-8-bit-sampled-voice-introduction.md), first
select the nearest octave of data from those available.  Play the one-shot
waveform then cycle on the repeat waveform as long as needed to sustain
the note.  Scale the signal by volume, perhaps also by an envelope, and by
a desired note volume.  Select a playback data rate s samples/second to
achieve the desired frequency (in Hz):

	frequency = s / samplesPerHiCycle

for the highest frequency octave.

The idea is to select an octave and one of 12 sampling rates (assuming a
12-tone scale).  If the [FORM 8SVX](devices/8svx-iff-8-bit-sampled-voice-introduction.md) doesn't have the right octave, you can
decimate or interpolate from the available data.

When it comes to musical instruments, [FORM 8SVX](devices/8svx-iff-8-bit-sampled-voice-introduction.md) is geared for a simple
sound driver.  Such a driver uses a single table of 12 data rates to reach
all notes in all octaves.  That's why 8SVX requires each octave of data to
have twice as many samples as the next higher octave.  If you restrict
samplesPerHiCycle to a power of two, you can use a predetermined table of
data rates.

