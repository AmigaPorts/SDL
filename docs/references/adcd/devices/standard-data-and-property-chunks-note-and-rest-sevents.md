---
title: Standard Data and Property Chunks / Note and Rest SEvents
manual: devices
chapter: devices
section: standard-data-and-property-chunks-note-and-rest-sevents
functions: []
libraries: []
---

# Standard Data and Property Chunks / Note and Rest SEvents

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The note and rest [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md)s SID_FirstNote through SID_Rest have the
following structure overlaid onto the SEvent structure:

  typedef struct {

```c
      UBYTE    tone;          /* MIDI tone number 0 to 127; 128 = rest */
      unsigned chord    :1,   /* 1 = a chorded note                    */
               tieOut   :1,   /* 1 = tied to the next note or chord    */
               nTuplet  :2,   /* 0 = none, 1 = triplet, 2 = quintuplet,
                               * 3 = septuplet                         */
               dot      :1,   /* dotted note; multiply duration by 3/2 */
               division :3;   /* basic note duration is 2^-division: 0 =
                               * whole note, 1 = half note, 2 = quarter
                               * note, .... 7 = 128th note             */
      } SNote;
```
[Implementation details.  Unsigned ":n" fields are packed into n bits in
the order shown, most significant bit to least significant bit.  An SNote
fits into 16 bits like any other [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md).  Warning: Some compilers don't
implement bit-packed fields properly.  E.g., Lattice 68000 C pads a group
of bit fields out to a LONG, which would make SNote take 5-bytes!  In that
situation, use the bit-field constants defined below.] 

The SNote structure describes one "note" or "rest" in a track.  The field
SNote.tone, which is overlaid with the SEvent.sID field, indicates the
MIDI tone number (pitch) in the range 0 through 127.  A value of 128
indicates a rest.

The fields nTuplet, dot, and division together give the duration of the
note or rest.   The division gives the basic duration: whole note, half
note, etc. The dot indicates if the note or rest is dotted.  A dotted note
is 3/2 as long as an undotted note.  The value nTuplet (0 through 3) tells
if this note or rest is part of an N-tuplet of order 1 (normal), 3, 5, or
7; an N-tuplet of order (2 * nTuplet + 1).  A triplet note is 2/3 as long
as a normal note, while a quintuplet is 4/5 as long and a septuplet is 6/7
as long.

Putting these three fields together, the duration of the note or rest is

	2^(-division) * {1, 3/2} * {1, 2/3, 4/5, 6/7}

These three fields are contiguous so you can easily convert to your local
duration encoding by using the combined 6 bits as an index into a mapping
table.

The field chord indicates if the note is chorded with the following note
(which is supposed to have the same duration).  A group of notes may be
chorded together by setting the chord bit of all but the last one.  (In
the terminology of [SSSP reference](devices/smus-iff-simple-musical-score-introduction-references.md) and GSCR, setting the chord bit to 1
makes the "entry delay" 0.)  A monophonic-track player can simply ignore
any SNote event whose chord bit is set, either by discarding it when
reading the track or by skipping it when playing the track.

Programs that create polyphonic tracks are expected to store the most
important note of each chord last, which is the note with the 0 chord bit.
This way, monophonic programs will play the most important note of the
chord. The most important note might be the chord's root note or its
melody note.

If the field tieOut is set, the note is tied to the following note in the
track if the following note has the same pitch.  A group of tied notes is
played as a single note whose duration is the sum of the component
durations. Actually, the tie mechanism ties a group of one or more chorded
notes to another group of one or more chorded notes.  Every note in a tied
chord should have its tieOut bit set.

Of course, the chord and tieOut fields don't apply to SID_Rest [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md)s.

Programs should be robust enough to ignore an unresolved tie, i.e., a note
whose tieOut bit is set but isn't followed by a note of the same pitch. If
that's true, monophonic-track programs can simply ignore chorded notes
even in the presense of ties.  That is, tied chords pose no extra
problems.

The following diagram shows some combinations of notes and chords tied to
notes and chords.  The text below the staff has a column for each SNote
[SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md) to show the pitch, chord bit, and tieOut bit.

A treble staff with chords and ties:

         |`      |`       |`      |`       |`      |`      |`      |`
         |       |        |       |        |       |       |       |
+--------|-____--|--------|-------|--------|-____--|-------|-____--|----+
|-------0|/____\0|-------0|-------|-------0|/    \0'------0'/    \0|----|
|-------0|/____\0|-------0|-____--|-------0|----------------------0|----|
|-------0'/    \0'-------0'/    \0'-------0'----------------------0'----|
+-----------------------------------------------------------------------+

Corresponding SNote values in the [TRAK](devices/standard-data-and-property-chunks-data-chunk-trak.md) chunk:

Pitch:  D B G   D B G    D B G   G        D B G   B       B       D B G
chord:  c c -   c c -    c c -   -        c c -   -       -       c c -
tieOut: t t t   - - -    t t t   -        t t t   -       t       - - -


If you read the above track into a monophonic-track program, it'll strip
out the chorded notes and ignore unresolved ties.  You'll end up with:

                                                   |`      |`
                                                   |       |
+--------|`------|`-------|`------|`-------|`------|-------|-------|`---+
|--------|-------|--------|-------|--------|------0'------0'-------|----|
|--------|-____--|--------|-____--|--------|-----------------------|----|
|-------0'/    \0'-------0'/    \0'-------0'----------------------0'----|
+-----------------------------------------------------------------------+

Pitch:  G       G        G       G        G        B       B      G
chord:  -       -        -       -        -        -       -      -
tieOut: t       -        t       -       (t)       -      (t)     -


A rest event (sID = SID_Rest) has the same SEvent.data field as a note.
It tells the duration of the rest.  The chord and tieOut fields of rest
events are ignored.

Within a [TRAK](devices/standard-data-and-property-chunks-data-chunk-trak.md) chunk, note and rest events appear in time order.

Instead of the bit-packed structure SNote, it might be easier to assemble
data values by or-ing constants and to disassemble them by masking and
shifting. In that case, use the following definitions.

  #define noteChord  (1<<7)          /* note is chorded to next note   */
  #define noteTieOut (1<<6)          /* tied to next note/chord        */

  #define noteNShift 4               /* shift count for nTuplet field  */
  #define noteN3     (1<<noteNShift) /* note is a triplet              */
  #define noteN5     (2<<noteNShift) /* note is a quintuplet           */
  #define noteN7     (3<<noteNShift) /* note is a septuplet            */
  #define noteNMask  noteN7          /* bit mask for the nTuplet field */

  #define noteDot    (1<<3)          /* note is dotted                 */

  #define noteD1     0               /* whole note division             */
  #define noteD2     1               /* half note division              */
  #define noteD4     2               /* quarter note division           */
  #define noteD8     3               /* eighth note division            */
  #define noteD16    4               /* sixteenth note division         */
  #define noteD32    5               /* thirty-second'th note division  */
  #define noteD64    6               /* sixty-fourth note division      */
  #define noteD128   7               /* 1/128 note division             */
  #define noteDMask  noteD128        /* bit mask for the division field */

  #define noteDurMask 0x3F           /* mask for combined duration fields*/

Note: The remaining [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md) types are optional.  A writer program doesn't
have to generate them.  A reader program can safely ignore them.

