/* Source: ADCD 2.1
 * Section: devices-dev-examples-cbio-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-cbio-c.md
 */

        move.l  a1,-(sp)
        move.l  a2,-(sp)
        move.l  a0,-(sp)
        move.l  h_SubEntry(a0),a0       ; C entry point
        jsr     (a0)
        lea     12(sp),sp
