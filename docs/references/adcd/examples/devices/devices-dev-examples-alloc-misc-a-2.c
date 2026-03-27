/* Source: ADCD 2.1
 * Section: devices-dev-examples-alloc-misc-a
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-alloc-misc-a.md
 */

                move.l  #MR_SERIALBITS,d0       ;We want these bits
                lea.l   MyName(pc),a1           ;This is our name
                jsr     MR_ALLOCMISCRESOURCE(a6)
                tst.l   d0
                bne.s   no_bits                 ;Someone else has it...
                move.l  #MR_SERIALPORT,d0
                lea.l   MyName(pc),a1
                jsr     MR_ALLOCMISCRESOURCE(a6)
                tst.l   d0
                bne.s   no_port                 ;Someone else has it...
