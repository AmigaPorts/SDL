/* Source: ADCD 2.1
 * Section: hard-examples-rotatebits-asm
 * Library: hardware
 * ADCD reference: hardware/hard-examples-rotatebits-asm.md
 */

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
