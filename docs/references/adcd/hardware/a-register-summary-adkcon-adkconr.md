---
title: A Register Summary / ADKCON, ADKCONR
manual: hardware
chapter: hardware
section: a-register-summary-adkcon-adkconr
functions: []
libraries: []
---

# A Register Summary / ADKCON, ADKCONR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
ADKCON     09E      W       P      Audio, disk, control write
ADKCONR    010      R       P      Audio, disk, control read


```c
            BIT#   USE
            ----   ------------------------------------
            15     SET/CLR    Set/clear control bit. Determines if bits
                              written with a 1 get set or cleared. Bits
                              written with a zero are always unchanged.
            14-13  PRECOMP 1-0

                       CODE  PRECOMP VALUE
                       ----  -------------
                        00   none
                        01   140 ns
                        10   280 ns
                        11   560 ns

            12     MFMPREC       ( 1=MFM precomp 0=GCR precomp)
            11     UARTBRK        Forces a UART break (clears TXD) if true.
            10     WORDSYNC       Enables disk read synchronizing on a word
                              equal to DISK SYNC CODE, located in
                              address (3F)*2.
            09 MSBSYNC        Enables disk read synchronizing on the MSB
                              (most significant bit). Appl type GCR.
            08 FAST   Disk data clock rate control 1=fast(2us) 0=slow(4us).
                      (fast for MFM, slow for MFM or GCR)

            07 USE3PN Use audio channel 3 to modulate nothing.
            06 USE2P3 Use audio channel 2 to modulate period of channel 3.
            05 USE1P2 Use audio channel 1 to modulate period of channel 2.
            04 USE0P1 Use audio channel 0 to modulate period of channel 1.

            03 USE3VN Use audio channel 3 to modulate nothing.
            02 USE2V3 Use audio channel 2 to modulate volume of channel 3.
            01 USE1V2 Use audio channel 1 to modulate volume of channel 2.
            00 USE0V1 Use audio channel 0 to modulate volume of channel 1.

                NOTE:  If both period and volume are modulated on the
                same channel, the period and volume will be alternated.
                First word xxxxxxxx V6-V0 , Second word P15-P0 (etc)
```
