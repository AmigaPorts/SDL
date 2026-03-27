/* Source: ADCD 2.1
 * Section: lib-examples-sample-stubs-asm
 * Library: libraries
 * ADCD reference: libraries/lib-examples-sample-stubs-asm.md
 */

            MOVE.L      A6,-(SP)           ;Save register(s)
            MOVEM.L     8(SP),D0/D1        ;Copy params to registers
                                           ;8(SP)  goes into D0
                                           ;12(SP) goes into D1
            MOVE.L      _SampleBase,A6     ;Library base to A6
            JSR         _LVOAddThese(A6)   ;Go to real routine
            MOVE.L      (SP)+,A6           ;Restore register(s)
            RTS

          END
