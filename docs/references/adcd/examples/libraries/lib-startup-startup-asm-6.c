/* Source: ADCD 2.1
 * Section: lib-startup-startup-asm
 * Library: libraries
 * ADCD reference: libraries/lib-startup-startup-asm.md
 */

        ;------ process quoted strings
                move.b  (a2)+,d1
                beq.s   parmExit
                cmp.b   #'"',d1
                beq.s   endarg

                ;-- '*' is the BCPL escape character
                cmp.b   #'*',d1
                bne.s   addquotechar

                move.b  (a2)+,d1
                move.b  d1,d2
                and.b   #$df,d2         ;d2 is temp toupper'd d1

                cmp.b   #'N',d2         ;check for dos newline char
                bne.s   checkEscape

                ;--     got a *N -- turn into a newline
                moveq   #10,d1
                bra.s   addquotechar
