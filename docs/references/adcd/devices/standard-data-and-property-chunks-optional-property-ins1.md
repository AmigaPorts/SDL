---
title: Standard Data and Property Chunks / Optional Property INS1
manual: devices
chapter: devices
section: standard-data-and-property-chunks-optional-property-ins1
functions: []
libraries: []
---

# Standard Data and Property Chunks / Optional Property INS1

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The "INS1" chunks in a FORM [SMUS](devices/smus-iff-simple-musical-score-introduction.md) identify the instruments to use for this
score.  A program can ignore INS1 chunks and stick with its built-in
default instrument assignments.  Or it can use them to locate instrument
data.  [See "[Instrument Registers](devices/background-instrument-registers.md)" in section 2, above.]

```c
    #define ID_INS1 MakeID('I', 'N', 'S', '1')

    /* Values for the RefInstrument field "type".	*/
    #define INS1_Name  0    /* just use the name; ignore data1, data2  */
    #define INS1_MIDI  1    /* <data1, data2> = MIDI <channel, preset> */

    typedef struct {
```
	UBYTE register;	    /* set this instrument register number */
	UBYTE type;	    /* instrument reference type */
	UBYTE data1, data2; /* depends on the "type" field */
	CHAR  name[];	    /* instrument name */
	} RefInstrument;

An INS1 chunk names the instrument for instrument register number
register. The register field can range from 0 through 255.  In practice,
most scores will need only a few [instrument registers](devices/background-instrument-registers.md).

The name field gives a text name for the instrument.  The string length
can be determined from the ckSize of the INS1 chunk.  The string is simply
an array of 8-bit ASCII characters in the range " " (SP, hex 20) through
"~" (tilde, hex 7F).

Besides the instrument name, an INS1 chunk has two data numbers to help
locate an instrument.  The use of these data numbers is controlled by the
type field. A value type = INS1_Name means just find an instrument by
name.  In this case, data1 and data2 should just be set to 0.  A value
type = INS1_MIDI means look for an instrument on MIDI channel # data1,
preset # data2.  Programs and computers without MIDI outputs will just
ignore the MIDI data.  They'll always look for the named instrument.
Other values of the type field are reserved for future standardization.

See section 2, above, for the algorithm for locating instrument data by
name.

