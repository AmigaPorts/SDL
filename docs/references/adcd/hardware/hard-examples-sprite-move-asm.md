---
title: Hard_examples/sprite_move.asm
manual: hardware
chapter: hardware
section: hard-examples-sprite-move-asm
functions: []
libraries: []
---

# Hard_examples/sprite_move.asm

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;
; sprite_move.asm
;
; In this example of moving a sprite, the spaceship is bounced around
; on the screen, changing  direction whenever it reaches an edge.
;
; The sprite position data, containing VSTART and HSTART, lives in
; memory at $25000. VSTOP is located at $25002. You write to these
; locations to move the sprite. Once during each frame, VSTART is
; incremented (or decremented) by 1 and HSTART by 2. Then a new VSTOP
; is calculated, which will be the new VSTART + 6.
;
```c
        MOVE.B  #151,d0         ;Initialize horizontal count
        MOVE.B  #194,d1         ;Initialize vertical count
        MOVE.B  #64,d2          ;Initialize horizontal position
        MOVE.B  #44,d3          ;Initialize vertical position
        MOVE.B  #1,d4           ;Initialize horizontal increment value
        MOVE.B  #1,d5           ;Initialize vertical increment value
```
;
;Here we wait for the start of the screen updating.
;This ensures a glitch-free display.
;
```c
        LEA     CUSTOM,a0       ;Set custom chip base pointer
```
VLOOP:
```c
        MOVE.B  VHPOSR(a0),d6   ;Read Vertical beam position.
```
;Only insert the following line if you are using a PAL machine.
;       CMP.B   #$20,d6         ;Compare with end of PAL screen.
```c
        BNE.S   VLOOP           ;Loop if not end of screen.
```
;Alternatively you can use the following code:
;VLOOP:
;       MOVE.W  INTREQR(a0),d6          ;Read interrupt request word
;       AND.W   #$0020,d6               ;Mask off all but vertical blank bit
;       BEQ     VLOOP                   ;Loop until bit is a 1
;       MOVE.W  #$0020,INTREQ(a0)       ;Vertical bit is on, so reset it
;
;Please note that this will only work if you have turned OFF the Vertical
;blanking interrupt enable (not recommended for long periods).

```c
        ADD.B   d4,d2           ;Increment horizontal value
        SUBQ.B  #1,d0           ;Decrement horizontal counter
        BNE     L1
        MOVE.B  #151,d0         ;Count exhausted, reset to 151
        EOR.B   #$FE,d4         ;Negate the increment value
```
L1:     MOVE.B  d2,$25001       ;Write new HSTART value to sprite
```c
        ADD.B   d5,d3           ;Increment vertical value
        SUBQ.B  #1,d1           ;Decrement vertical counter
        BNE     L2
        MOVE.B  #194,d1         ;Count exhausted, reset to 194
        EOR.B   #$FE,d5         ;Negate the increment value
```
L2:     MOVE.B  d3,$25000       ;Write new VSTART value to sprite

```c
        MOVE.B  d3,d6           ;Must now calculate new VSTOP
        ADD.B   #6,d6           ;VSTOP always VSTART+6 for spaceship
        MOVE.B  d6,$25002       ;Write new VSTOP to sprite
        BRA     VLOOP           ;Loop forever
```
