/* Source: ADCD 2.1
 * Section: lib-startup-startup-asm
 * Library: libraries
 * ADCD reference: libraries/lib-startup-startup-asm.md
 */

        ;------ all done -- null terminate the arguments
                clr.b   (a1)
                clr.l   (a3)
        ENDC NARGS

                pea     sv_ArgvArray(a5) ; argv
                move.l  d3,-(sp)         ; argc
        ENDC    QARG

        IFGT    QARG
                pea     nullArgV(pc)    ; pointer to pointer to null string
                pea     1               ; only one pointer
        ENDC

        IFGT    ASTART
                movea.l _DOSBase,a6
        ;------ get standard input handle:
                callsys Input
                move.l  d0,_stdin

        ;------ get standard output handle:
                callsys Output
                move.l  d0,_stdout
                move.l  d0,_stderr
                movea.l ABSEXECBASE,a6
        ENDC ASTART

                bra     domain
