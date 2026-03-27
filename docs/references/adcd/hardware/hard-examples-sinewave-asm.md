---
title: Hard_examples/sinewave.asm
manual: hardware
chapter: hardware
section: hard-examples-sinewave-asm
functions: []
libraries: []
---

# Hard_examples/sinewave.asm

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;
; sinewave.asm
;
; In this example, which gathers together all of the program segments
; from the Audio Hardware sections, a sine wave is played through
; channel 0. The example assumes exclusive access to the Audio
; hardware, and will not work directly in a multitasking environment.
;
MAIN:

```c
        LEA     CUSTOM,a0       ; Custom chip base address
        LEA     SINEDATA(pc),a1 ;Address of data to
                                ;  audio location register 0
```
WHERE0DATA:

```c
        MOVE.L  a1,AUD0LCH(a0)  ;The 680x0 writes this as though it were a
                                ;  32-bit register at the low-bits location
                                ;  (common to all locations and pointer
                                ;  registers in the system).
```
SETAUD0LENGTH:

```c
        MOVE.W  #4,AUD0LEN(a0)  ;Set length in words
```
SETAUD0VOLUME:

```c
        MOVE.W  #64,AUD0VOL(a0) ;Use maximum volume
```
SETAUD0PERIOD:

```c
        MOVE.W  #447,AUD0PER(a0)
```
BEGINCHAN0:

```c
        MOVE.W  #(DMAF_SETCLR!DMAF_AUD0!DMAF_MASTER),DMACON(a0)

        RTS                     ; Return to main code...

        DS.W    0               ; Be sure word-aligned
```
SINEDATA:                       ; Audio data must be in Chip memory

        DC.B    0, 90, 127, 90, 0, -90, -127, -90
        END
