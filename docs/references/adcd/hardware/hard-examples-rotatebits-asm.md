---
title: Hard_examples/rotatebits.asm
manual: hardware
chapter: hardware
section: hard-examples-rotatebits-asm
functions: []
libraries: []
---

# Hard_examples/rotatebits.asm

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;
; rotatebits.asm
;
;   Here we rotate bits.  This code takes a single raster row of a
;   bitplane, and `rotates' it into an array of 16-bit words, setting
;   the specified bit of each word in the array according to the
;   corresponding bit in the raster row.  We use the line mode in
;   conjunction with patterns to do this magic. Link this code with amiga.lib.
;
;   Input:  d0 contains the number of words in the raster row.  d1
;   contains the number of the bit to set (0..15).  a0 contains a
;   pointer to the raster data, and a1 contains a pointer to the
;   array we are filling; the array must be at least (d0)*16 words
;   (or (d0)*32 bytes) long.
;
;
        include 'exec/types.i'
        include 'hardware/custom.i'
        include 'hardware/blit.i'
        include 'hardware/dmabits.i'

        include 'hardware/hw_examples.i'
;
        xref    _custom
;
        xdef    rotatebits
;
;
;   Our entry point.
;
rotatebits:
```c
        lea     _custom,a2      ; We need to access the custom registers
        tst     d0              ; if no words, just return
        beq     gone
        lea     DMACONR(a2),a3  ; get the address of dmaconr
        moveq.l #DMAB_BLTDONE-8,d2      ; get the bit number BLTDONE
        btst    d2,(a3)         ; check to see if we're done
```
wait1:
```c
        btst    d2,(a3)         ; check again.
        bne     wait1           ; not done?  Keep waiting
        moveq.l #-30,d3         ; Line mode:  aptr = 4Y-2X, Y=0; X=15
        move.l  d3,BLTAPT(a2)
        move.w  #-60,BLTAMOD(a2)        ; amod = 4Y-4X
        clr.w   BLTBMOD(a2)     ; bmod = 4Y
        move.w  #2,BLTCMOD(a2)  ; cmod = width of bitmap (2)
        move.w  #2,BLTDMOD(a2)  ; ditto
        ror.w   #4,d1           ; grab the four bits of the bit number
        and.w   #$f000,d1       ; mask them out
        or.w    #$bca,d1        ; USEA, USEC, USED, F=AB+~AC
        move.w  d1,BLTCON0(a2)  ; stuff it
        move.w  #$f049,BLTCON1(a2)      ; BSH=15, SGN, LINE
        move.w  #$8000,BLTADAT(a2)      ; Initialize A dat for line
        move.w  #$ffff,BLTAFWM(a2)      ; Initialize masks
        move.w  #$ffff,BLTALWM(a2)
        move.l  a1,BLTCPT(a2)   ; Initialize pointer
        move.l  a1,BLTDPT(a2)
        lea     BLTBDAT(a2),a4  ; For quick access, we grab these two
        lea     BLTSIZE(a2),a5  ; addresses
        move.w  #$402,d1        ; Stuff bltsize; width=2, height=16
        move.w  (a0)+,d3        ; Get next word
        bra     inloop          ; Go into the loop
```
again:
```c
        move.w  (a0)+,d3        ; Grab another word
        btst    d2,(a3)         ; Check blit done
```
wait2:
```c
        btst    d2,(a3)         ; Check again
        bne     wait2           ; oops, not ready, loop around
```
inloop:
```c
        move.w  d3,(a4)         ; stuff new word to make vertical
        move.w  d1,(a5)         ; start the blit
        subq.w  #1,d0           ; is that the last word?
        bne     again           ; keep going if not
```
gone:

        rts
        end
