/* Source: ADCD 2.1
 * Section: hard-examples-simpleline-asm
 * Library: hardware
 * ADCD reference: hardware/hard-examples-simpleline-asm.md
 */

        mulu.w  d4,d1           ; Calculate y1 * width
        ror.l   #4,d0           ; move upper four bits into hi word
        add.w   d0,d0           ; multiply by 2
        add.l   d1,a0           ; ptr += (x1 >> 3)
        add.w   d0,a0           ; ptr += y1 * width
        swap    d0              ; get the four bits of x1
        or.w    #$BFA,d0        ; or with USEA, USEC, USED, F=A+C
        lsl.w   #2,d3           ; Y = 4 * Y
        add.w   d2,d2           ; X = 2 * X
        move.w  d2,d1           ; set up size word
        lsl.w   #5,d1           ; shift five left
        add.w   #$42,d1         ; and add 1 to height, 2 to width
        btst    #DMAB_BLTDONE-8,DMACONR(a1)     ; safety check
