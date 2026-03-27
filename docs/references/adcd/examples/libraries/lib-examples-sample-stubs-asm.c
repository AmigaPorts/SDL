/* Source: ADCD 2.1
 * Section: lib-examples-sample-stubs-asm
 * Library: libraries
 * ADCD reference: libraries/lib-examples-sample-stubs-asm.md
 */

            MOVE.L      A6,-(SP)           ;Save register(s)
            MOVE.L      8(SP),D0           ;Copy param to register
            MOVE.L      _SampleBase,A6     ;Library base to A6
            JSR         _LVODouble(A6)     ;Go to real routine
            MOVE.L      (SP)+,A6           ;Restore register(s)
            RTS
