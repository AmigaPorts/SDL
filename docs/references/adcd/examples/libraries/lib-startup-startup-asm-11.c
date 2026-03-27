/* Source: ADCD 2.1
 * Section: lib-startup-startup-asm
 * Library: libraries
 * ADCD reference: libraries/lib-startup-startup-asm.md
 */

        IFGT ASTART
        ;------ set the C input and output descriptors
                move.l  d0,_stdin
                move.l  d0,_stdout
                move.l  d0,_stderr
        ENDC ASTART

        ;------ set the console task (so Open( "*", mode ) will work
        ;       task pointer still in A4
                move.l  d0,pr_CIS(A4)
                move.l  d0,pr_COS(A4)
                lsl.l   #2,d0
                move.l  d0,a0
                move.l  fh_Type(a0),d0
                beq.s   noConTask
                move.l  d0,pr_ConsoleTask(A4)
