/* Source: ADCD 2.1
 * Section: hard-examples-clearmem-asm
 * Library: hardware
 * ADCD reference: hardware/hard-examples-clearmem-asm.md
 */

        lea     _custom,a1      ; Get pointer to chip registers
        bsr     waitblit        ; Make sure previous blit is done
        move.l  a0,BLTDPT(a1)   ; Set up the D pointer to the region to clear
        clr.w   BLTDMOD(a1)     ; Clear the D modulo (don't skip no bytes)
        asr.l   #1,d0           ; Get number of words from number of bytes
        clr.w   BLTCON1(a1)     ; No special modes
        move.w  #DEST,BLTCON0(a1)       ; only enable destination
