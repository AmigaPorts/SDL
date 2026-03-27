---
title: 8 Narrator Device / Writing to the Narrator Device
manual: devices
chapter: devices
section: 8-narrator-device-writing-to-the-narrator-device
functions: []
libraries: []
---

# 8 Narrator Device / Writing to the Narrator Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You write to the narrator device by passing a [narrator_rb](devices/8-narrator-device-device-interface.md) I/O request to
the device with [CMD_WRITE](autodocs-2.0/narrator-device-cmd-write.md) set in io_Command, the number of bytes to be
written set in io_Length and the address of the write buffer set in
io_Data.


```c
    VoiceIO->message.io_Command = CMD_WRITE;
    VoiceIO->message.io_Offset  = 0;
    VoiceIO->message.io_Data    = PhonBuffer;
    VoiceIO->message.io_Length  = strlen(PhonBuffer);
    DoIO((struct IORequest *)VoiceIO);
```
You can control several characteristics of the speech, as indicated in the
[narrator_rb](devices/8-narrator-device-device-interface.md) struct shown in the [Device Interface](devices/8-narrator-device-device-interface.md) section.

Generally, the narrator device attempts to speak in a non-regional dialect
of American English.  With pre-V37 versions of the device, the user could
change only a few of the more basic aspects of the speaking voice such as
pitch, male/female, speaking rate, etc.  With the V37 and later versions
of the narrator device, the user can now change many more aspects of the
speaking voice.  In addition, in the pre-V37 device, only mouth shape
changes could be queried by the user.  With the V37 device, the user can
also receive start of word and start of syllable synchronization events.
These events can be generated independently, giving the user much greater
flexibility in synchronizing voice to animation or other effects.

The following describes the fields of the [narrator_rb](devices/8-narrator-device-device-interface.md) structure:

message.io_Data

```c
    Points to a NULL-terminated ASCII phonetic input string.  For
    backwards compatibility issues, the string may also be terminated
    with a "#" symbol.  See the [How to Write Phonetically for Narrator](devices/8-narrator-device-how-to-write-phonetically-for-narrator.md)
    section of this chapter for details.
```
message.io_Length

    Length of the input string.  The narrator device  will parse the
    input string until either a NULL or a "#" is encountered, or until
    io_Length characters have been processed.
rate

    The speaking rate in words/minute.  Range is from 40 to 400 wpm.
pitch

    The baseline pitch of the speaking voice.  Range is 65 to 320 Hertz.
mode

```c
    The F0 (pitch) mode.  ROBOTICF0 produces a monotone pitch, NATURALF0
    produces a normal pitch contour, and MANUALF0 (new for V37 and later)
    gives the user more explicit control over the pitch contour by
    creative use of accent numbers.  In MANUALF0 mode, a given accent
    number will have the same effect on the pitch regardless of its
    position in the sentence and its relation to other accented
    syllables. In NATURALF0 mode, accent numbers have a reduced effect
    towards the end of sentences (especially long ones).  In addition,
    the proximity of other accented syllables, the number of syllables in
    the word, and the number of phrases and words in the sentence all
    affect the pitch contour.  In MANUALF0 mode these things are ignored
    and it's up to the user to do the controlling.  This has the
    advantage of being able to have the pitch be more expressive.  The
    F0enthusiasm field will scale the effect.
```
sex

```c
    Controls the sex of  the speaking voice (MALE or FEMALE).  In
    actuality, only the formant targets are changed.  The user must still
    change the pitch and speaking rate of the voice to get the correct
    sounding sex.  See the include files for default pitch and rate
    settings.
```
ch_masks

```c
    Pointer to a set of audio allocation maps.  See the "[Audio Device](devices/2-allocation-and-arbitration-commands-adcmd-allocate.md)"
    chapter for details.
```
nm_masks

```c
    Number of audio allocation maps.  See the "[Audio Device](devices/2-allocation-and-arbitration-commands-adcmd-allocate.md)" chapter
    for details.
```
volume

    Sets the volume of the speaking voice.  Range 0 - 64.
sampfreq

    The synthesizer is ``tuned" to a sampling frequency of 22,200 Hz.
    Changing sampfreq affects pitch and formant tunings and can be used
    to create unusual vocal effects.  For V37 and later, it is
    recommended that F1, F2, and F3adj be used instead to achieve this
    effect.
mouths

```c
    If set to a non-zero value will direct the narrator device  to
    generate mouth shape changes and send this data to the user in
    response to read requests.  See the [Reading from the Narrator Device](devices/8-narrator-device-reading-from-the-narrator-device.md)
    section for more details.
```
chanmask

    Used internally by the narrator device. The user should not modify
    this field.
numchan

    Used internally by the narrator device.  The user should not modify
    this field.
flags (V37)

```c
    Used to specify V37 features of the device.  Possible bit settings
    are: NDB_NEWIORB - I/O request block  uses V37 features. NDB_WORDSYNC
    - Device should generate start of word sync events. NDB_SYLSYNC -
    Device should generate start of syllable sync events. These bit
    definitions and their corresponding field definitions (NDF_NEWIORB,
    NDF_WORDSYNC, and NDF_SYLSYNC) can be found in the include files.
```
F0enthusiasm (V37)

```c
    The value of this field controls the scaling of pitch (F0) excursions
    used on accented syllables and has the effect of making the narrator
    device sound more or less "enthusiastic" about what it is saying.
    It is calibrated in 1/32s with unity (32) being the default value.
    Higher values cause more F0 variation, lesser values cause less.
    This feature is most useful in manual F0 mode.
```
F0perturb (V37)

```c
    Non-zero values in this field cause varying amounts of random
    low-frequency modulation of the pitch (F0).  In other words, the
    pitch shakes in much the same way as an elderly person's voice does.
    Range is 0 to 255.
```
F1adj, F2adj, F3adj (V37)

    Changes the tuning of the formant frequencies. A formant is a major
    vocal tract resonance, and the frequencies of these formants move
    continuously as we speak.  Traditionally, they have been given the
    abbreviations of F1, F2, F3... with F1 being the one lowest in
    frequency.  Moving these formants away from their normal positions
    causes drastic changes in the sound of the voice and is a very
    powerful tool in the creation of character voices.  This adjustment
    is in ±5% steps.  Positive values raise the formant frequencies and
    vice versa. The default is zero.  Use these adjustments instead of
    changing sampfreq.
A1adj, A2adj, A3adj (V37)

```c
    In a parallel formant synthesizer, the amplitudes of the formants
    need to be specified along with their frequencies.  These fields bias
    the amplitudes computed by the narrator device.  This is useful for
    creating different tonal balances (bass or treble), and listening to
    formants in isolation for educational purposes.  The adjustments are
    calibrated directly in ±1db (decibel) steps.  Using negative values
    will cause no problems; use of positive numbers can cause clipping.
    If you want to raise an amplitude, try cutting the others the same
    relative amount, then bring them all up equally until clipping is
    heard, then back them off.  This should produce an optimum setting.
    This field has a +31 to -32 db range and the value -32db is
    equivalent to -infinity, shutting that formant off completely.
```
articulate (V37)

```c
    According to the popular theories of speech production, we move our
    articulators (jaw, tongue, lips, etc.) smoothly from one "target"
    position to the next.  These articulatory targets correspond to
    acoustic targets specified by the narrator device for each phoneme.
    The device calculates the time it should take to get from one target
    to the next and this field allows you to intervene in that process.
    Values larger than the default will cause the transitions to be
    proportionately longer and vice versa.  This field is calibrated in
    percent with 100 being the default.  For example, a value of 50 will
    cause the transitions to take half the normal time, with the result
    being "sharper", more deliberate sounding speech (not necessarily
    more natural).  A value of 200  will cause the transitions to be
    twice as long, slurring the speech.  Zero is a special value in the
    narrator device will take special measures to create no transitions
    at all and each phoneme will simply be abutted to the next.
```
centralize (V37)

```c
    This field together with centphon can be used to create regional
    accent effects by modifying vowel sounds.  centralize specifies the
    degree (in percent) to which vowel targets are "pulled" towards the
    targets of the vowel specified by centphon.   The default value of 0%
    indicates that each vowel in the utterance retains its own target
    values.  The maximum value of 100% indicates that each vowel's
    targets are replaced by the targets of the specified vowel.
    Intermediate values control the degree of interpolation between the
    utterance vowel's targets and the targets of the vowel specified by
    centphon.
```
centphon (V37)

    Pointer to an ASCII string specifying the vowel whose targets are
    used in the interpolation specified by centralize.  The vowels which
    can be specified are: IY, IH, EH, AE, AA, AH, AO, OW, UH, ER, UW.
    Specifying other than these will result in an error code being
    returned.
AVbias, AFbias (V37)

```c
    Controls the relative amplitudes of the voiced and unvoiced speech
    sounds.  Voiced sounds are those made with the vocal cords vibrating,
    such as vowels and some consonants like y, r, w, and m.  Unvoiced
    sounds are made without the vocal cords vibrating and use the sound
    of turbulent air, such as s, t, sh, and f.  Some sounds are
    combinations of both such as z and v.  AVbias and AFbias change the
    default amplitude of the voiced and unvoiced components of the sounds
    respectively.  (AV stands for Amplitude of Voicing and AF stands for
    Amplitude of Frication).  These fields are calibrated in ±1db steps
    and have the same range as the other amplitude biases, namely +31 to
    -32 db.  Again, positive values may cause clipping.  Negative values
    are the most useful.
```
priority (V37)

```c
    Task priority while speaking.  When the narrator device begins to
    synthesize a sentence, the task priority remains unchanged while it
    is calculating acoustic parameters.  However, when speech begins at
    the end of this process, the priority is bumped to 100 (the default
    value). If you wish, you may change this to anything you want.
    Higher values will tend to lock out most anything while speech is
    going on, and lower values may cause audible breaks in the speech
    output. The following example shows how to issue a write request to
    the narrator device.  The first write is done with the default
    parameter settings.  The second write is done after modifying the
    first and third formant loudness and using the centralization feature.
```
The following example shows how to issue a write request to the narrator
device.  The first write is done with the default parameter settings.  The
second write is done after modifying the first and third formant loudness
and using the centralization feature.


```c
     [Speak_Narrator.c](devices/devices-dev-examples-speak-narrator-c.md) 
```
