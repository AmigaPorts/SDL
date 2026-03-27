---
title: 4 / / Building the Data Structure / End-of-data Words
manual: hardware
chapter: hardware
section: 4-building-the-data-structure-end-of-data-words
functions: []
libraries: []
---

# 4 / / Building the Data Structure / End-of-data Words

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When the vertical position of the  [beam counter](hardware/7-system-control-hardware-beam-position-detection.md)  is equal to the VSTOP
value in the sprite  [control words](hardware/4-building-the-data-structure-sprite-control-word-2-sprxctl.md) , the next two words fetched from the
sprite data structure are written into the sprite  [control registers](hardware/4-summary-of-sprite-registers-control-registers.md) 
instead of being sent to the  [color registers](hardware/4-sprite-hardware-summary-of-sprite-color-registers.md) . These two words are
interpreted by the hardware in the same manner as the original words that
were first loaded into the  [control registers](hardware/4-summary-of-sprite-registers-control-registers.md) . If the VSTART value
contained in these words is lower than the current beam position, this
sprite will not be reused in this display field. For consistency, the
value 0 should be used for both words when ending the usage of a sprite.
 [Sprite reuse](hardware/4-sprite-hardware-reusing-sprite-dma-channels.md)  is discussed later.

The following data structure is for the spaceship sprite. It will be
located at V = 65 and H = 128 on the normally visible part of the
screen.

SPRITE:

```c
        DC.W    $6D60,$7200     ;VSTART, HSTART, VSTOP
        DC.W    $0990,$07E0     ;First pair of descriptor words
        DC.W    $13C8,$0FF0
        DC.W    $23C4,$1FF8
        DC.W    $13C8,$0FF0
        DC.W    $0990,$07E0
        DC.W    $0000,$0000     ;End of sprite data
```
