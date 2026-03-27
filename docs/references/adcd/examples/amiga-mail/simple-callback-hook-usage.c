/* Source: ADCD 2.1
 * Section: simple-callback-hook-usage
 * Library: amiga-mail
 * ADCD reference: amiga-mail/simple-callback-hook-usage.md
 */

    INCLUDE 'exec/types.i'
    INCLUDE 'utility/hooks.i'

    xdef        _hookEntry

    _hookEntry:
        move.l  a1,-(sp)                ; push message packet pointer
        move.l  a2,-(sp)                ; push object pointer
        move.l  a0,-(sp)                ; push hook pointer
        move.l  h_SubEntry(a0),a0       ; fetch actual Hook entry point ...
        jsr     (a0)                    ; and call it
        lea     12(sp),sp               ; fix stack
        rts
