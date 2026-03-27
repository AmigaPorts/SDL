---
title: 5 / / Joining Tones / Audio DMA Example
manual: hardware
chapter: hardware
section: 5-joining-tones-audio-dma-example
functions: []
libraries: []
---

# 5 / / Joining Tones / Audio DMA Example

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This example details the system audio DMA action in a step-by-step
fashion.

Suppose you wanted to join together a sine and a triangle waveform,
end-to-end, for a special audio effect, alternating between them. The
following sequence shows the action of your program as well as its
interaction with the audio DMA system. The example assumes that the
 [period](hardware/5-forming-and-playing-a-sound-selecting-the-data-output-rate.md) ,  [volume](hardware/5-forming-and-playing-a-sound-selecting-the-volume.md) , and  [length](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md)  of the data set remains the same for the
sine wave and the triangle wave.


                         Interrupt Program
                         -----------------
If (wave = triangle)

```c
               write  [AUD0LCL](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md)  with address of sine wave data.
```
Else if (wave = sine)

```c
               write  [AUD0LCL](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md)  with address of triangle wave data.


                          Main Program
                          ------------
```
1. Set up  [volume](hardware/5-forming-and-playing-a-sound-selecting-the-volume.md) ,  [period](hardware/5-forming-and-playing-a-sound-selecting-the-data-output-rate.md) , and  [length](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md) .
2. Write  [AUD0LCL](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md)  with address of sine wave data.
3. Start DMA.
4. Continue with something else.



                         System Response
                         ---------------
As soon as DMA starts,

   a. Copy to "back-up" length register from  [AUD0LEN](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md) .
   b. Copy to "back-up" location register from  [AUD0LCL](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md)  (will be used
```c
      as a pointer showing current data word to fetch).
```
   c. Create an  [interrupt](hardware/7-setting-and-clearing-bits-audio-interrupts.md)  for the 680x0 saying that it has completed
```c
      retrieving working copies of  [length](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md)  and  [location registers](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md) .
```
   d. Start retrieving audio data each allocated DMA time slot.

