---
title: 5 / Forming and Playing a Sound / Telling the System About the Data
manual: hardware
chapter: hardware
section: 5-forming-and-playing-a-sound-telling-the-system-about-the
functions: []
libraries: []
---

# 5 / Forming and Playing a Sound / Telling the System About the Data

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In order to retrieve the sound data for the audio channel, the system needs
to know where the data is located and how long (in words) the data is.

The location registers  [AUDxLCH and AUDxLCL](hardware/5-forming-and-playing-a-sound-creating-the-waveform-data.md)  contain the high three bits
and the low fifteen bits, respectively, of the starting address of the
audio data. Since these two register addresses are contiguous, writing a
long word into AUDxLCH moves the audio data address into both locations.
The "x" in the register names stands for the number of the audio channel
where the output will occur. The channels are numbered 0, 1, 2, and 3.

These registers are location registers, as distinguished from pointer
registers. You need to specify the contents of these registers only once;
no resetting is necessary when you wish the audio channel to keep on
repeating the same waveform. Each time the system retrieves the last audio
word from the data area, it uses the contents of these location registers
to again find the start of the data. Assuming the first word of data
starts at location "audiodata" and you are using channel 0, here is how to
set the location registers:

WHERE0DATA:

```c
        LEA     CUSTOM,a0       ; Base chip address...
        LEA     AUDIODATA,a1
        MOVE.L  a1,AUD0LCH(a0)  ;Put address (32 bits)
                                ;  into location register.
```
The length of the data is the number of samples in your waveform divided
by 2, or the number of words in the data set. Using the sample data set
above, the length of the data is 16 words. You write this length into the
audio data length register for this channel. The length register is called
AUDxLEN, where "x" refers to the channel number. You set the length
register AUD0LEN to 16 as shown below.

SETAUD0LENGTH:

```c
        LEA     CUSTOM,a0       ; Base chip address
        MOVE.W  #16,AUD0LEN(a0) ; Store the length...
```
