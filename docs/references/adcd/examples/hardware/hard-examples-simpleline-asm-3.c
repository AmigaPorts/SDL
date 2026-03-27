/* Source: ADCD 2.1
 * Section: hard-examples-simpleline-asm
 * Library: hardware
 * ADCD reference: hardware/hard-examples-simpleline-asm.md
 */

        btst    #DMAB_BLTDONE-8,DMACONR(a1)     ; wait for blitter
        bne     waitblit
        move.w  d3,BLTBMOD(a1)  ; B mod = 4 * Y
        sub.w   d2,d3
        ext.l   d3
        move.l  d3,BLTAPT(a1)   ; A ptr = 4 * Y - 2 * X
        bpl     lineover        ; if negative,
        or.w    #SIGNFLAG,d5    ; set sign bit in con1
