---
title: Standard Data and Property Chunks / Data Chunk TRAK
manual: devices
chapter: devices
section: standard-data-and-property-chunks-data-chunk-trak
functions: []
libraries: []
---

# Standard Data and Property Chunks / Data Chunk TRAK

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The main contents of a score is stored in one or more TRAK chunks
representing parallel "tracks".  One TRAK chunk per track.

The contents of a TRAK chunk is an array of 16-bit "events" such as
"note", "rest", and "set instrument".  Events are really commands to a
simple scheduler, stored in time order.  The tracks can be polyphonic,
that is, they can contain chorded "note" events.

Each event is stored as an "SEvent" record.  ("SEvent" means "simple
musical event".)  Each SEvent has an 8-bit type field called an "sID" and
8 bits of type-dependent data.  This is like a machine language
instruction with an 8-bit opcode and an 8-bit operand.

This format is extensible since new event types can be defined in the
future. The "note" and "rest" events are the only ones that every program
must understand.  We will carefully design any new event types so that
programs can safely skip over unrecognized events in a score.

Caution: ID codes must be allocated by a central clearinghouse  to avoid
conflicts.  Commodore Applications and Technical Support provides this
clearinghouse service.

Here are the C type definitions for TRAK and "SEvent" and the currently
defined sID values.  Afterward are details on each SEvent.

  #define ID_TRAK MakeID('T', 'R', 'A', 'K')
  /* TRAK chunk contains an SEvent[].       */

  /* SEvent: Simple musical event.          */
  typedef struct {

```c
      UBYTE sID;      /* SEvent type code   */
      UBYTE data;     /* sID-dependent data */
      } SEvent;
```
  /* SEvent type codes "sID".                                            */
  #define SID_FirstNote     0
  #define SID_LastNote    127 /* sIDs in the range SID_FirstNote through

```c
                               * SID_LastNote (sign bit = 0) are notes.
                               * The sID is the MIDI tone number (pitch).*/
```
  #define SID_Rest        128 /* a rest (same data format as a note).    */

  #define SID_Instrument  129 /* set instrument number for this track.   */
  #define SID_TimeSig     130 /* set time signature for this track.      */
  #define SID_KeySig      131 /* set key signature for this track.       */
  #define SID_Dynamic     132 /* set volume for this track.              */
  #define SID_MIDI_Chnl   133 /* set MIDI channel number (sequencers)    */
  #define SID_MIDI_Preset 134 /* set MIDI preset number (sequencers)     */
  #define SID_Clef        135 /* inline clef change.
```c
                               * 0=Treble, 1=Bass, 2=Alto, 3=Tenor.(new) */
```
  #define SID_Tempo       136 /* Inline tempo in beats per minute.(new)  */

  /* SID values 144 through 159: reserved for Instant Music SEvents.     */

  /* Remaining sID values up through 254: reserved for future
   * standardization.         */

  #define SID_Mark        255 /* sID reserved for an end-mark in RAM.    */

