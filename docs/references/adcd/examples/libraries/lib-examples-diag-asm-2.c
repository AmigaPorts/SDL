/* Source: ADCD 2.1
 * Section: lib-examples-diag-asm
 * Library: libraries
 * ADCD reference: libraries/lib-examples-diag-asm.md
 */

            jsr     _LVOFindResident(a6)    ; find the DOS resident tag
            move.l  d0,a0                   ; in order to bootstrap
            move.l  RT_INIT(A0),a0          ; set vector to DOS INIT
            jsr     (a0)                    ; and initialize DOS
            rts
