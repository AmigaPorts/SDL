/* Source: ADCD 2.1
 * Section: 3-clipboard-device-monitoring-clipboard-changes
 * Library: devices
 * ADCD reference: devices/3-clipboard-device-monitoring-clipboard-changes.md
 */

    ; entry interface for C code
    _HookEntry:
            move.l  a1,-(sp)            ; push message packet pointer
            move.l  a2,-(sp)            ; push object pointer
            move.l  a0,-(sp)            ; push hook pointer
            move.l  h_SubEntry(a0),a0   ; fetch C entry point ...
            jsr     (a0)                ; ... and call it
            lea     12(sp),sp           ; fix stack
            rts
