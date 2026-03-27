---
title: 5 Audio Hardware / The Audio State Machine
manual: hardware
chapter: hardware
section: 5-audio-hardware-the-audio-state-machine
functions: []
libraries: []
---

# 5 Audio Hardware / The Audio State Machine

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For an explanation of the various states, refer to Figure 5-8. There is
one audio state machine for each channel. The machine has eight states and
is clocked at the clock constant rate (3.58 MHz NTSC). Three of the states
are basically unused and just transfer back to the idle (000) state. One
of the paths out of the idle state is designed for interrupt-driven
operation (processor provides the data), and the other path is designed
for DMA-driven operation (the "Agnus" special chip provides the data).

In interrupt-driven operation, transfer to the main loop (states 010 and
011) occurs immediately after data is written by the processor. In the 010
state the upper byte is output, and in the 011 state the lower byte is
output. Transitions such as 010->011->010 occur whenever the period
counter counts down to one. The period counter is reloaded at these
transitions. As long as the  [interrupt](hardware/7-setting-and-clearing-bits-audio-interrupts.md)  is cleared by the processor in
time, the machine remains in the main loop. Otherwise, it enters the idle
state.  [Interrupts](hardware/7-setting-and-clearing-bits-audio-interrupts.md)  are generated on every word transition (011->010).

In DMA-driven operation, transition to the 001 state occurs and DMA
requests are sent to Agnus as soon as DMA is turned on. Because of
pipelining in Agnus, the first data word must be thrown away. State 101 is
entered as soon as this word arrives; a request for the next data word has
already gone out. When the data arrives, state 010 is entered and the main
loop continues until the DMA is turned off. The length counter counts down
once with each word that comes in. When it finishes, a DMA restart request
goes to Agnus along with the regular DMA request. This tells Agnus to
reset the pointer to the beginning of the table of data. Also, the length
counter is reloaded and an  [interrupt](hardware/7-setting-and-clearing-bits-audio-interrupts.md)  request goes out soon after the
length counter finishes (counts to one). The request goes out just as the
last word of the waveform starts its output.

DMA requests and restart requests are transferred to Agnus once each
horizontal line, and the data comes back about 14 clock cycles later (the
duration of a clock cycle is 280 ns).

In attach mode, things run a little differently. In attach volume,
requests occur as they do in normal operation (on the 011->010
transition). In attach period, a set of requests occurs on the 010->011
transition. When both attach period and attach volume are high, requests
occur on both transitions.

If the sampling rate is set much higher than the normal maximum sampling
rate (approximately 29 KHz), the two samples in the buffer register will
be repeated. If the  [filter](hardware/5-producing-high-quality-sound-low-pass-filter.md)  on the Amiga is bypassed and the  [volume](hardware/5-forming-and-playing-a-sound-selecting-the-volume.md)  is
set to the maximum ($40), this feature can be used to make modulated
carriers up to 1.79 MHz. The modulation is placed in the memory map, with
plus values in the even bytes and minus values in the odd bytes.

The symbols used in the state diagram are explained in the following list.
Upper-case names indicate external signals; lower-case names indicate
local signals.

   AUDxON      DMA on "x" indicates channel number (signal from  [DMACON](hardware/7-system-control-hardware-dma-control.md) ).

   AUDxIP       [Audio interrupt](hardware/7-setting-and-clearing-bits-audio-interrupts.md)  pending (input to channel from interrupt

```c
               circuitry).
```
   AUDxIR       [Audio interrupt](hardware/7-setting-and-clearing-bits-audio-interrupts.md)  request (output from channel to interrupt

```c
               circuitry)
```
   intreq1     Interrupt request that combines with intreq2 to form

               AUDxIR..
   intreq2     Prepare for interrupt request. Request comes out after the

               next 011->010 transition in normal operation.
   [AUDxDAT](hardware/a-register-summary-audxdat.md)     Audio data load signal. Loads 16 bits of data to audio

               channel.
   AUDxDR      Audio DMA request to Agnus for one word of data.

   AUDxDSR     Audio DMA request to Agnus to reset pointer to start of

               block.
   dmasen      Restart request enable.

   percntrld   Reload period counter from back-up latch typically written

```c
               by processor with  [AUDxPER](hardware/5-selecting-the-data-output-rate-specifying-the-period-value.md)  (can also be written by attach
               mode).
```
   percount    Count period counter down one latch.

   perfin      Period counter finished (value = 1).

   lencntrld   Reload length counter from back-up latch.

   lencount    Count length counter down one notch.

   lenfin      Length counter finished (value = 1).

   volcntrld   Reload volume counter from back-up latch.

   pbufld1     Load output buffer from holding latch written to by AUDxDAT.

   pbufld2     Like pbufld1, but only during 010->011 with attach period.

   AUDxAV      Attach volume. Send data to volume latch of next channel

               instead of to D->A converter.
   AUDxAP      Attach period. Send data to period latch of next channel

               instead of to the D->A converter.
   penhi       Enable the high 8 bits of data to go to the D->A converter.

   napnav      /AUDxAV * /AUDxAP + AUDxAV -- no attach stuff or else attach

               volume. Condition for normal DMA and interrupt requests.
   sq2,1,0     The name of the state flip-flops, MSB to LSB.




```c
     [Figure 5-8: Audio State Diagram](hardware/hard-pics-5-8-pic.md) 
```
   ECS Audio.
   ----------
   For information on the audio hardware in the Enhanced Chip Set,
   see the  [ECS register map](hardware/c-enhanced-chip-set-ecs-hardware-and-the-graphics-library.md)  in Appendix C.

