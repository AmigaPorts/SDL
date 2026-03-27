---
title: Hard_examples/lores_playfield.asm
manual: hardware
chapter: hardware
section: hard-examples-lores-playfield-asm
functions: []
libraries: []
---

# Hard_examples/lores_playfield.asm

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;
; lores_playfield.asm
;
; This example sets up a 320 x 200 playfield with one bitplane, which
; is located at $21000. Also, a Copper list is set up at $20000.
;
; This example relies on the include file hw_examples.i.
;
```c
        LEA     CUSTOM,a0               ; a0 points at custom chips
        MOVE.W  #$1200,BPLCON0(a0)      ; One bitplane, enable composite color
        MOVE.W  #0,BPLCON1(a0)          ; Set horizontal scroll value to 0
        MOVE.W  #0,BPL1MOD(a0)          ; Set modulo to 0 for all odd bitplanes
        MOVE.W  #$0038,DDFSTRT(a0)      ; Set data-fetch start to $38
        MOVE.W  #$00D0,DDFSTOP(a0)      ; Set data-fetch stop to $D0
        MOVE.W  #$2C81,DIWSTRT(a0)      ; Set DIWSTRT to $2C81
        MOVE.W  #$F4C1,DIWSTOP(a0)      ; Set DIWSTOP to $F4C1
        MOVE.W  #$0F00,COLOR00(a0)      ; Set background color to red
        MOVE.W  #$0FF0,COLOR01(a0)      ; Set color register 1 to yellow
```
;
;  Fill bitplane with $FF00FF00 to produce stripes
;
```c
        MOVE.L  #$21000,a1      ; Point at beginning of bitplane
        MOVE.L  #$FF00FF00,d0   ; We will write $FF00FF00 long words
        MOVE.W  #2000,d1        ; 2000 long words = 8000 bytes
```
;
LOOP:   MOVE.L  d0,(a1)+        ; Write a long word
```c
        DBRA    d1,LOOP         ; Decrement counter and loop until done...
```
;
;  Set up Copper list at $20000
;
```c
        MOVE.L  #$20000,a1      ; Point at Copper list destination
        LEA     COPPERL(pc),a2  ; Point a2 at Copper list data
```
CLOOP:  MOVE.L  (a2),(a1)+      ; Move a word
```c
        CMPI.L  #$FFFFFFFE,(a2)+        ; Check for last longword of Copper list
        BNE     CLOOP           ; Loop until entire copper list is moved
```
;
;  Point Copper at Copper list
;
```c
        MOVE.L  #$20000,COP1LCH(a0)     ; Write to Copper location register
        MOVE.W  COPJMP1(a0),d0  ; Force copper to $20000
```
;
;  Start DMA
;
```c
        MOVE.W  #(DMAF_SETCLR!DMAF_COPPER!DMAF_RASTER!DMAF_MASTER),DMACON(a0)
                        ; Enable bitplane and Copper DMA
        BRA     ....    ; Go do next task
```
;
;  This is the data for the Copper list.
;
COPPERL:
```c
        DC.W    BPL1PTH,$0002   ; Move $0002 to address $0E0    (BPL1PTH)
        DC.W    BPL1PTL,$1000   ; Move $1000 to address $0E2    (BPL1PTL)
        DC.W    $FFFF,$FFFE     ; End of Copper list
```
;

