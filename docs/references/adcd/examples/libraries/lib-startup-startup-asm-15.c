/* Source: ADCD 2.1
 * Section: lib-startup-startup-asm
 * Library: libraries
 * ADCD reference: libraries/lib-startup-startup-asm.md
 */

        ;------ restore initial stack ptr
                ;-- FindTask
                movea.l ABSEXECBASE,a6
                suba.l  a1,a1
                callsys FindTask
                ;-- get SP as it was prior to DOS's jsr to us
                move.l  d0,a4
                move.l  pr_ReturnAddr(a4),a5
                ;-- subtract 4 for return address, 4 for SVar, 4 for WBenchMsg
                suba.l  #12,a5

                ;-- restore sp
                move.l  a5,sp

                ;-- recover WBenchMsg
                move.l  (sp)+,a2
                ;-- recover SVar
                move.l  (sp)+,a5


        IFGT    WBOUT
        ;------ Close any WbOutput file before closing dos.library
                move.l  sv_WbOutput(a5),d1
                beq.s   noWbOut
                move.l  _DOSBase,a6
                callsys Close
