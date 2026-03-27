---
title: Background / Instrument Registers
manual: devices
chapter: devices
section: background-instrument-registers
functions: []
libraries: []
---

# Background / Instrument Registers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Instrument reference.  In [SSSP](devices/smus-iff-simple-musical-score-introduction-references.md), each note event points to a "timbre
object" which supplies the "instrument" (the sound driver data) for that
note.  FORM [SMUS](devices/smus-iff-simple-musical-score-introduction.md) stores these pointers as a "current instrument setting"
for each track. It's just a run encoded version of the same information.
[SSSP reference](devices/smus-iff-simple-musical-score-introduction-references.md) uses a symbol table to hold all the pointers to "timbre
object". [SMUS](devices/smus-iff-simple-musical-score-introduction.md) uses INS1 chunks for the same purpose.  They name the
score's instruments.

The actual instrument data to use depends on the playback environment, but
we want the score to be independent of environment.  Different playback
environments have different audio output hardware and different sound
driver software.  And there are channel allocation issues like how many
output channels there are, which ones are polyphonic, and which I/O ports
they're connected to.  If you use MIDI to control the instruments, you get
into issues of what kind of device is listening to each MIDI channel and
what each of its presets sounds like.  If you use computer-based
instruments, you need driver- specific data like waveform tables and
oscillator parameters.

We just want some orchestration.  If the score wants a "piano", we let the
playback program find a "piano".

Instrument reference by name.  A reference from a [SMUS](devices/smus-iff-simple-musical-score-introduction.md) score to actual
instrument data is normally by name.  The score simply names the
instrument, for instance "tubular bells".  It's up to the player program
to find suitable instrument data for its output devices.  (More on
locating instruments below.)

Instrument reference by MIDI channel and preset.  A [SMUS](devices/smus-iff-simple-musical-score-introduction.md) score can also
ask for a specific MIDI channel number and preset number.  MIDI programs
may honor these specific requests.  But these channel allocations can
become obsolete or the score may be played without MIDI hardware.  In such
cases, the player program should fall back to instrument reference by name.

Instrument reference via instrument register.  Each reference from a [SMUS](devices/smus-iff-simple-musical-score-introduction.md)
track to an instrument is via an "instrument register".  Each track
selects an instrument register which in turn points to the specific
instrument data.

Each score has an array of [instrument registers](devices/background-instrument-registers.md).  Each track has a
"current instrument setting", which is simply an index number into this
array.  This is like setting a raster image's pixel to a specific color
number (a reference to a color value through a "color register") or
setting a text character to a specific font number (a reference to a font
through a "font register"). This is diagramed below:

         +------------+--------+--------+------------+--------+-----------+
Track 1  | Set Inst 2 |  Note  |  Note  | Set Inst 1 |  Note  |  Note...  |
     .---+------------+--------+--------+------------+--------+-----------+
    /   ______________________________________/
   /   /
  /   /
  \   \       +------------------+       +--------------------------------+
   \   `----->| "piano"          |-----> |   (internal piano data)        |
```c
    \         +------------------+       +--------------------------------+
     `------->| "guitar"         |-----> |   (internal guitar data)       |
```
Instrument    +------------------+       +--------------------------------+
 Registers    | "Spanish guitar" |-----> | (internal Spanish guitar data) |
```c
              +------------------+       +--------------------------------+
       .----->| "bass drum"      |-----> |  (internal bass drum data)     |
      /       +------------------+       +--------------------------------+
     /
     \
      \
       `-+------------+--------+--------+--------+--------+-----------+
```
Track 2  | Set Inst 4 |  Note  |  Note  |  Note  |  Note  |  Note...  |


         +------------+--------+--------+--------+--------+-----------+
Locating instrument data by name.  "INS1" chunks in a [SMUS](devices/smus-iff-simple-musical-score-introduction.md) score name the
instruments to use for that score.  The player program uses these names to
locate instrument data.

To locate instrument data, the player performs these steps:

For each instrument register, check for a suitable instrument with the
right name?


```c
    {"Suitable" means usable with an available output device and driver.}
    {Use case independent name comparisons.}
```
  1.Initialize the instrument register to point to a built-in default

```c
    instrument.

    {Every player program must have default instruments.  Simple programs
    stop here.  For fancier programs, the default instruments are a
    backstop in case the search fails.}
```
  2.Check any instrument [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)s embedded in the FORM [SMUS](devices/smus-iff-simple-musical-score-introduction.md).  (This is an

```c
    "instrument cache".)
```
  3.Else check the default instruments.

  4.Else search the local "instrument library".  (The library might simply

```c
    be a disk directory.)
```
  5.If all else fails, display the desired instrument name and ask the


    user to pick an available one.
This algorithm can be implemented to varying degrees of fanciness.  It's
OK to stop searching after step 1, 2, 3, or 4.  If exact instrument name
matches fail, it's OK to try approximate matches.  E.g., search for any
kind of "guitar" if you can't find a "Spanish guitar".  In any case, a
player only has to search for instruments while loading a score.

When the embedded instruments are suitable, they save the program from
asking the user to insert the "right" disk in a drive and searching that
disk for the "right" instrument.  But it's just a cache.  In practice, we
rarely move scores between environments so the cache often works.  When
the score is moved, embedded instruments must be discarded (a cache miss)
and other instrument data used.

Be careful to distinguish an instrument's name from its filename--the
contents name vs. container name.  A musical instrument [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) should
contain a NAME chunk that says what instrument it really is.  Its
filename, on the other hand, is a handle used to locate the FORM.
Filenames are affected by external factors like drives, directories, and
filename character and length limits.  Instrument names are not.

Issue: Consider instrument naming conventions for consistency.  Consider a
naming convention that aids approximate matches.  E.g., we could accept
"guitar, bass1" if we didn't find "guitar, bass".  Failing that, we could
accept "guitar" or any name starting with "guitar".

Set instrument events.  If the player implements the set-instrument score
event, each track can change instrument numbers while playing.  That is,
it can switch between the loaded instruments.

Initial instrument settings.  Each time a score is played, every track's
running state information must be initialized.  Specifically, each track's
instrument number should be initialized to its track number.  Track 1 to
instrument 1, etc.  It's as if each track began with a set-instrument
event.

In this way, programs that don't implement the set-instrument event still
assign an instrument to each track.  The INS1 chunks imply these initial
instrument settings.

