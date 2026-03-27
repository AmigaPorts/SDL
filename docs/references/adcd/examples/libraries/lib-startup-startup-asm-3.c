/* Source: ADCD 2.1
 * Section: lib-startup-startup-asm
 * Library: libraries
 * ADCD reference: libraries/lib-startup-startup-asm.md
 */

        IFEQ    QARG
        ;------ find command name
                lsl.l   #2,d0           ; pr_CLI bcpl pointer conversion
                move.l  d0,a0
                move.l  cli_CommandName(a0),d0
                lsl.l   #2,d0           ; bcpl pointer conversion

                ;-- start argv array
                move.l	sv_ArgvBufPtr(a5),a1
                lea     sv_ArgvArray(a5),a3

                ;-- copy command name
                move.l  d0,a0
                moveq.l #0,d0
                move.b  (a0)+,d0        ; size of command name
                clr.b   0(a0,d0.l)      ; terminate the command name
                move.l  a0,(a3)+
                moveq   #1,d3           ; start counting arguments

        IFEQ    NARGS
        ;------ null terminate the arguments, eat trailing control characters
                lea     0(a2,d2.l),a0
