/* Source: ADCD 2.1
 * Section: hard-examples-simpleline-asm
 * Library: hardware
 * ADCD reference: hardware/hard-examples-simpleline-asm.md
 */

        move.w  d0,BLTCON0(a1)  ; write control registers
        move.w  d5,BLTCON1(a1)
        move.w  d4,BLTCMOD(a1)  ; C mod = bitplane width
        move.w  d4,BLTDMOD(a1)  ; D mod = bitplane width
        sub.w   d2,d3
        move.w  d3,BLTAMOD(a1)  ; A mod = 4 * Y - 4 * X
        move.w  #$8000,BLTADAT(a1)      ; A data = 0x8000
        moveq.l #-1,d5          ; Set masks to all ones
        move.l  d5,BLTAFWM(a1)  ; we can hit both masks at once
        move.l  a0,BLTCPT(a1)   ; Pointer to first pixel to set
        move.l  a0,BLTDPT(a1)
        move.w  d1,BLTSIZE(a1)  ; Start blit
        rts                     ; and return, blit still in progress.
        end
