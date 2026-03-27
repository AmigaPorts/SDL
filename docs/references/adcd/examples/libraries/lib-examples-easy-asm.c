/* Source: ADCD 2.1
 * Section: lib-examples-easy-asm
 * Library: libraries
 * ADCD reference: libraries/lib-examples-easy-asm.md
 */

        XREF    _LVOOpenLibrary       ;Offset from Exec base for OpenLibrary()
        XREF    _LVOCloseLibrary      ;Offset from Exec base for CloseLibrary()
        XREF    _LVODisplayBeep       ;Offset from Intuition base for DisplayBeep()

        move.l  _AbsExecBase,a6       ;Move exec.library base to a6
        lea.l   IntuiName(pc),a1      ;Pointer to "intuition.library" string
        moveq   #33,d0                ;Version of library needed
        jsr     _LVOOpenLibrary(a6)   ;Call Exec's OpenLibrary() and
        tst.l   d0                    ;check to see if it succeeded
        bne.s   open_ok
        moveq   #20,d0                ;Set failure code
        rts                           ;Failed exit
