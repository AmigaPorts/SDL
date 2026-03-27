/* Source: ADCD 2.1
 * Section: lib-examples-easy-asm
 * Library: libraries
 * ADCD reference: libraries/lib-examples-easy-asm.md
 */

        suba.l  a0,a0                 ;Load zero into a0
        jsr     _LVODisplayBeep(a6)   ;Call Intuition's DisplayBeep()

        move.l  a6,a1                 ;Put IntuitionBase into a1
        move.l  _AbsExecBase,a6
        jsr     _LVOCloseLibrary(a6)  ;Call Exec's CloseLibrary()
        moveq   #0,d0                 ;Set return code
        rts
