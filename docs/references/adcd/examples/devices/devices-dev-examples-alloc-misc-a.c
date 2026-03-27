/* Source: ADCD 2.1
 * Section: devices-dev-examples-alloc-misc-a
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-alloc-misc-a.md
 */

                move.l  _AbsExecBase,a6         ;Prepare to use exec
                lea.l   MiscName(pc),a1
                jsr     _LVOOpenResource(a6)    ;Open "misc.resource"
                move.l  d0,d7                   ;Stash resource base
                bne.s   resource_ok
                moveq   #RETURN_FAIL,d0
                rts
