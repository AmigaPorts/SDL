/* Source: ADCD 2.1
 * Section: lib-startup-startup-asm
 * Library: libraries
 * ADCD reference: libraries/lib-startup-startup-asm.md
 */

        ;------ get the startup message that workbench will send to us.
        ;       must get this message before doing any DOS calls
                bsr.s   getWbMsg

        ;------ save the message so we can return it later
                move.l  d0,(sp)
        IFGT    ASTART
                move.l  d0,_WBenchMsg
        ENDC    ASTART

        ;------ push the message on the stack for wbmain (as argv)
                move.l  d0,-(sp)
                clr.l   -(sp)           ; indicate run from Workbench (argc=0)

        IFNE    (1-QARG)+WBOUT
        ;------ put DOSBase in a6 for next few calls
                move.l  _DOSBase,a6
        ENDC    (1-QARG)+WBOUT

        IFEQ    QARG
        ;------ get the first argument
                move.l  d0,a2
                move.l  sm_ArgList(a2),d0
                beq.s   doCons

        ;------ and set the current directory to the same directory
                move.l  d0,a0
                move.l  wa_Lock(a0),d1
                ;should be a  beq.s doCons  here
                callsys CurrentDir
