---
title: Hard_examples/clearmem.asm
manual: hardware
chapter: hardware
section: hard-examples-clearmem-asm
functions: []
libraries: []
---

# Hard_examples/clearmem.asm

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;
; clearmem.asm
;
;   Blitter example---memory clear (link with amiga.lib)
;

        include 'exec/types.i'
        include 'hardware/custom.i'
        include 'hardware/dmabits.i'
        include 'hardware/blit.i'
        include 'hardware/hw_examples.i"

        xref    _custom
;
;   Wait for previous blit to complete.
;
waitblit:
```c
        btst.b  #DMAB_BLTDONE-8,DMACONR(a1)
```
waitblit2:
```c
        btst.b  #DMAB_BLTDONE-8,DMACONR(a1)
        bne     waitblit2
        rts
```
;
;   This routine uses a side effect in the blitter.  When each
;   of the blits is finished, the pointer in the blitter is pointing
;   to the next word to be blitted.
;
;   When this routine returns, the last blit is started and might
;   not be finished, so be sure to call waitblit above before
;   assuming the data is clear.
;
;   a0 = pointer to first word to clear
;   d0 = number of bytes to clear (must be even)
;
        xdef    clearmem
clearmem:
```c
        lea     _custom,a1      ; Get pointer to chip registers
        bsr     waitblit        ; Make sure previous blit is done
        move.l  a0,BLTDPT(a1)   ; Set up the D pointer to the region to clear
        clr.w   BLTDMOD(a1)     ; Clear the D modulo (don't skip no bytes)
        asr.l   #1,d0           ; Get number of words from number of bytes
        clr.w   BLTCON1(a1)     ; No special modes
        move.w  #DEST,BLTCON0(a1)       ; only enable destination
```
;
;   First we deal with the smaller blits
;
```c
        moveq   #$3f,d1         ; Mask out mod 64 words
        and.w   d0,d1
        beq     dorest          ; none?  good, do one blit
        sub.l   d1,d0           ; otherwise remove remainder
        or.l    #$40,d1         ; set the height to 1, width to n
        move.w  d1,BLTSIZE(a1)  ; trigger the blit
```
;
;   Here we do the rest of the words, as chunks of 128k
;
dorest:
```c
        move.w  #$ffc0,d1       ; look at some more upper bits
        and.w   d0,d1           ; extract 10 more bits
        beq     dorest2         ; any to do?
        sub.l   d1,d0           ; pull of the ones we're doing here
        bsr     waitblit        ; wait for prev blit to complete
        move.w  [d0](#footnote1),BLTSIZE(a1)  ; do another blit
```
dorest2:
```c
        swap    d0              ; more?
        beq     done            ; nope.
        clr.w   d1              ; do a 1024x64 word blit (128K)
```
keepon:
```c
        bsr     waitblit        ; finish up this blit
        move.w  d1,BLTSIZE(a1)  ; and again, blit
        subq.w  #1,d0           ; still more?
        bne     keepon          ; keep on going.
```
done:

```c
        rts                     ; finished.  Blit still in progress.
        end
```
