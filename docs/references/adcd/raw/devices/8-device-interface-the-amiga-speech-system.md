# 8 / Device Interface / The Amiga Speech System


The speech system on the Amiga is divided into two subsystems:

   *  The translator library,  consisting of a single function:

```c
      [Translate()](../Includes_and_Autodocs_2._guide/node03AC.html), which converts an English string into its phonetic
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
commands (see the  [Narrator Device Commands and Functions](../Devices_Manual_guide/node0114.html) section), two of
these commands do most of the work in the device.  They are:

   *  [CMD_WRITE](../Includes_and_Autodocs_2._guide/node04C7.html) - This command is used to send a phonetic string to the

```c
      device to be spoken.  The [narrator_rb](../Devices_Manual_guide/node0115.html#line17) I/O request block also contains
      several parameters which can be set to control  various aspects of
      the speech, such as pitch, speaking rate, male/female voice, and so
      on. Some of the options are rather arcane.  See the
      [Writing to the Narrator Device](../Devices_Manual_guide/node0119.html) section for a complete list
      of options and their descriptions.
```
   *  [CMD_READ](../Includes_and_Autodocs_2._guide/node04C3.html) - The narrator device can be told to generate various

```c
      synchronization events which the user can query.  These events are:
      mouth shape changes, word sync, and/or syllable sync.  The events can
      be generated singly or in any combination, as requested by the user.
      Word and syllable synchronization events are new to system 2.0 and
      later (V37 and later of the narrator device).  See the
      [Reading from the Narrator Device](../Devices_Manual_guide/node011A.html) section for more details.
```
