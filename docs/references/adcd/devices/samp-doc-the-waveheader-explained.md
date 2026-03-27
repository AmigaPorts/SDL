---
title: SAMP.doc / The Waveheader Explained
manual: devices
chapter: devices
section: samp-doc-the-waveheader-explained
functions: []
libraries: []
---

# SAMP.doc / The Waveheader Explained

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The WaveSize is, as stated, the number of BYTES in the wave's sample
table. If your sample data consisted of the following 8 bit samples:

   BYTE  100,-90,80,-60,30,35,40,-30,-35,-40,00,12,12,10

then WaveSize = 14. (PAD THE DATA OUT TO AN EVEN NUMBER OF BYTES!)

The MidiSampNum is ONLY used to hold the sample number received from a
MIDI Sample Dump. It has no bearing on where the wave should be placed in
a SAMP file. Also, the wave numbers in the PlayMap are between 1 to 255,
with 1 being the number of the first wave in the file. Remember that a
wave number of 0 is reserved to mean "no wave to play back". Likewise, the
LoopType is only used to hold info from a MIDI sample dump.

The InsType is explained at the end of this document. Often it will be set
to 0.

The RootNote is the Midi Note number that will play the wave back at it's
original, recorded pitch. For example, consider the following excerpt of a
PlayMap:

   PlayMap  {2,0,0,4       /* Midi Note #0 channel assignment */

```c
             4,100,1,0     /* Midi Note #1    "        "  */
             1,4,0,0       /* Midi Note #2    "        "  */
             60,2,1,1...}  /* Midi Note #3    "        "  */
```
Notice that Midi Notes 0, 1, and 2 are all set to play wave number 4 (on
Amiga channels 3, 0, and 1 respectively). If we set wave 4's RootNote = 1,
then receiving Midi Note number 1 would play back wave 4 (on Amiga channel
0) at it's original pitch. If we receive a Midi Note number 0, then wave 4
would be played back on channel 3) a half step lower than it's original
pitch. If we receive Midi Note number 2, then wave 4 would be played (on
channel 1) a half step higher than it's original pitch. If we receive Midi
Note number 3, then wave 4 would not be played at all because it isn't
specified in the PlayMap bytes for Midi Note number 3.

The Rate is the number of samples per second of the original pitch. For
example, if Rate = 20000, then to play the wave at it's original pitch,
the sampling period would be:

   (1/20000)/.279365 = .000178977

   #define AUDIO_HARDWARE_FUDGE .279365

where .279365 is the Amiga Fudge Factor (a hardware limitation). Since the
Amiga needs to see the period in terms of microseconds, move the decimal
place to the right 6 places and our sampling period = 179 (rounded to an
integer).

In order to play the wave at higher or lower pitches, one would need to
"transpose" this period value. By specifying a higher period value, the
Amiga will play back the samples slower, and a lower pitch will be
achieved. By specifying a lower period value, the amiga will play back the
sample faster, and a higher pitch will be achieved. By specifying this
exact period, the wave will be played back exactly "as it was recorded
(sampled)". ("This period is JUST RIGHT!", exclaimed GoldiLocks.) Later, a
method of transposing pitch will be shown using a "look up" table of
periods. This should prove to be the fastest way to transpose pitch,
though there is nothing in the SAMP format that compels you to do it this
way.

The LoopStart is a BYTE offset from the beginning of the wave to where the
looping portion of the wave begins.  For example, if SampleData points to
the start of the wave, then SampleData + LoopStart is the start address of
the looping portion.  In 8SVX, the looping portion was referred to as
repeatHiSamples.  The data from the start of the wave up to the start of
the looping portion is the oneShot portion of the wave.  LoopEnd is a BYTE
offset from the beginning of the wave to where the looping portion ends.
This might be the very end of the wave in memory, or perhaps there might
be still more data after this point.  You can choose to ignore this
"trailing" data and play back the two other portions of the wave just like
an 8SVX file (except that there are no other interpolated octaves of this
wave).

VelTable contains 16 BYTE offsets from the beginning of the wave.  Each
successive value should be greater (or equal to) the preceding value.  If
VelStart = POSITIVE (64), then for each 8 increments in Midi Velocity
above 0, you move UP in the table, add this offset to the wave's beginning
address (start of oneShot), and start playback at that address. Here is a
table relating received midi note-on velocity vs. start playback address
for POSITIVE VelStart.  SamplePtr points to the beginning of the sample.


```c
    If midi velocity = 0, then don't play a sample, this is a note off
    If midi velocity = 1 to 7, then start play at SamplePtr + VelTable[0]
    If midi velocity = 8 to 15, then start at SamplePtr + VelTable[1]
    If midi velocity = 16 to 23, then start at SamplePtr + VelTable[2]
    If midi velocity = 24 to 31, then start at SamplePtr + VelTable[3]
    If midi velocity = 32 to 39, then start at SamplePtr + VelTable[4]
    If midi velocity = 40 to 47, then start at SamplePtr + VelTable[5]
    If midi velocity = 48 to 55, then start at SamplePtr + VelTable[6]
    If midi velocity = 56 to 63, then start at SamplePtr + VelTable[7]
    If midi velocity = 64 to 71, then start at SamplePtr + VelTable[8]
    If midi velocity = 72 to 79, then start at SamplePtr + VelTable[9]
    If midi velocity = 80 to 87, then start at SamplePtr + VelTable[10]
    If midi velocity = 88 to 95, then start at SamplePtr + VelTable[11]
    If midi velocity = 96 to 103, then start at SamplePtr + VelTable[12]
    If midi velocity = 104 to 111, then start at SamplePtr + VelTable[13]
    If midi velocity = 112 to 119, then start at SamplePtr + VelTable[14]
    If midi velocity = 120 to 127, then start at SamplePtr + VelTable[15]
```
We don't want to specify a scale factor and use integer division to find
the sample start.  This would not only be slow, but also, it could never
be certain that the resulting sample would be a zero crossing if the start
point is calcu- lated "on the fly".  The reason for having a table is so
that the offsets can be be initially set on zero crossings via an editor.
This way, no audio "clicks" is guaranteed.  This table should provide
enough resolution.

If VelStart = NEGATIVE (128), then for each 8 increments in midi velocity,
you start from the END of VelTable, and work backwards.  Here is a table
for NEGATIVE velocity start.


```c
    If midi velocity = 0, then don't play a sample, this is a note off
    If midi velocity = 1 to 7, then start play at SamplePtr + VelTable[15]
    If midi velocity = 8 to 15, then start at SamplePtr + VelTable[14]
    If midi velocity = 16 to 23, then start at SamplePtr + VelTable[13]
    If midi velocity = 24 to 31, then start at SamplePtr + VelTable[12]
    If midi velocity = 32 to 39, then start at SamplePtr + VelTable[11]
    If midi velocity = 40 to 47, then start at SamplePtr + VelTable[10]
    If midi velocity = 48 to 55, then start at SamplePtr + VelTable[9]
    If midi velocity = 56 to 63, then start at SamplePtr + VelTable[8]
    If midi velocity = 64 to 71, then start at SamplePtr + VelTable[7]
    If midi velocity = 72 to 81, then start at SamplePtr + VelTable[6]
    If midi velocity = 80 to 87, then start at SamplePtr + VelTable[5]
    If midi velocity = 88 to 95, then start at SamplePtr + VelTable[4]
    If midi velocity = 96 to 103, then start at SamplePtr + VelTable[3]
    If midi velocity = 104 to 111, then start at SamplePtr + VelTable[2]
    If midi velocity = 112 to 119, then start at SamplePtr + VelTable[1]
    If midi velocity = 120 to 127, then start at SamplePtr + VelTable[0]
```
In essence, increasing midi velocity starts playback "farther into" the
wave for POSITIVE VelStart. Increasing midi velocity "brings the start
point back" toward the beginning of the wave for NEGATIVE VelStart.

If VelStart is set to NONE (0), then the wave's playback start should not
be affected by the table of offsets.

What is the use of this feature?  As an example, when a snare drum is hit
with a soft volume, its initial attack is less pronounced than when it is
struck hard.  You might record a snare being hit hard. By setting VelStart
to a NEGATIVE value and setting up the offsets in the Table, a lower midi
velocity will "skip" the beginning samples and thereby tend to soften the
initial attack.  In this way, one wave yields a true representation of its
instrument throughout its volume range. Furthermore, stringed and plucked
instruments (violins, guitars, pianos, etc) exhibit different attacks at
different volumes. VelStart makes these kinds of waves more realistic via
a software implementation.  Also, an application program can allow the
user to enable/ disable this feature. See the section "Making the Velocity
Table" for info on how to best choose the 16 table values.

