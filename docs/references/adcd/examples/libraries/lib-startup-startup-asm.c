/* Source: ADCD 2.1
 * Section: lib-startup-startup-asm
 * Library: libraries
 * ADCD reference: libraries/lib-startup-startup-asm.md
 */

        IFGT    DEBUG
                move.l  sp,initialSP
                move.l  d0,dosCmdLen
                move.l  a0,dosCmdBuf
        ENDC    DEBUG

        IFEQ    QARG
                move.l  d0,d2
                move.l  a0,a2
        ENDC    QARG

        ;------ get Exec library base pointer
                movea.l ABSEXECBASE,a6
                move.l  a6,_SysBase

        ;------ get the address of our task
                suba.l  a1,a1           ; clear a1
                callsys FindTask
                move.l  d0,a4           ; keep task address in a4

        ;------ get DOS library base pointer
                moveq   #0,d0
                lea     DOSName(pc),A1  ; dos.library
                callsys OpenLibrary

                tst.l   d0
                beq     alertDOS        ; fail on null with alert
                move.l  d0,_DOSBase     ; Else set the global


        IFEQ    QARG
        ;------ branch over argv calculations if not a CLI process
                move.l  pr_CLI(A4),d0
