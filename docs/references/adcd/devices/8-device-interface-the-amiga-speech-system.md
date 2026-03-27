---
title: 8 / Device Interface / The Amiga Speech System
manual: devices
chapter: devices
section: 8-device-interface-the-amiga-speech-system
functions: []
libraries: []
---

# 8 / Device Interface / The Amiga Speech System

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The speech system on the Amiga is divided into two subsystems:

   *  The translator library,  consisting of a single function:

```c
      [Translate()](autodocs-2.0/translator-library-translate.md), which converts an English string into its phonetic
      representation, and
```
   *  The narrator device, which uses the phonetic representation

```c
      (generated either manually or by the translator library) as input to
      generate human-like speech and play it out via the audio device.
```
The two subsystems can be used either together or individually. Generally,
hand coding phonetic text will produce better quality speech than using
the translator library, but this requires the programmer to "hard code"
the phonetic text in the program or otherwise restrict the input to
phonetic text only.  If the program must handle arbitrary English input,
the translator library should be used.

Below is an example of how you would use the translator library to
translate a string for the narrator device.


```c
    #define BUFLEN 500

    APTR EnglStr;                   /* pointer to sample input string */
    LONG EnglLen;                   /* input length */
    UBYTE PhonBuffer[BUFLEN];       /* place to put the translation */
    LONG rtnCode;                   /* return code from function */

    struct narrator_rb *VoiceIO;    /* speaking I/O request block */
    struct mouth_rb *MouthIO;       /* mouth movement I/O request block */

    EnglStr = "This is Amiga speaking.";    /* a test string */
    EnglLen = strlen(EnglStr);
    rtnCode = Translate(EnglStr, EnglLen, (APTR)&PhonBuffer[0], BUFLEN);

    voice_io->message.io_Command = CMD_WRITE;
    voice_io->message.io_Offset  = 0;
    voice_io->message.io_Data    = PhonBuffer;
    voice_io->message.io_Length  = strlen(PhonBuffer);
    DoIO((struct IORequest *)VoiceIO)
```
This chapter discusses only the narrator device; refer to the "Translator
Library" chapter of the Amiga ROM Kernel Reference Manual: Libraries for
more information on the translator library.

While the narrator device on the Amiga supports all of the major device
commands (see the  [Narrator Device Commands and Functions](devices/8-narrator-device-narrator-device-commands-and-functions.md) section), two of
these commands do most of the work in the device.  They are:

   *  [CMD_WRITE](autodocs-2.0/narrator-device-cmd-write.md) - This command is used to send a phonetic string to the

```c
      device to be spoken.  The [narrator_rb](devices/8-narrator-device-device-interface.md) I/O request block also contains
      several parameters which can be set to control  various aspects of
      the speech, such as pitch, speaking rate, male/female voice, and so
      on. Some of the options are rather arcane.  See the
      [Writing to the Narrator Device](devices/8-narrator-device-writing-to-the-narrator-device.md) section for a complete list
      of options and their descriptions.
```
   *  [CMD_READ](autodocs-2.0/narrator-device-cmd-read.md) - The narrator device can be told to generate various

```c
      synchronization events which the user can query.  These events are:
      mouth shape changes, word sync, and/or syllable sync.  The events can
      be generated singly or in any combination, as requested by the user.
      Word and syllable synchronization events are new to system 2.0 and
      later (V37 and later of the narrator device).  See the
      [Reading from the Narrator Device](devices/8-narrator-device-reading-from-the-narrator-device.md) section for more details.
```
