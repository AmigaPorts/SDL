/* Source: ADCD 2.1
 * Section: hard-examples-coldreboot-asm
 * Library: hardware
 * ADCD reference: hardware/hard-examples-coldreboot-asm.md
 */

                sub.l   MAGIC_SIZEOFFSET(a0),a0 ;(end of ROM)-(ROM size)=PC
                move.l  4(a0),a0                ;Get Initial Program Counter
                subq.l  #2,a0                   ;now points to second RESET
                reset                           ;first RESET instruction
                jmp     (a0)                    ;CPU Prefetch executes this
                ;NOTE: the RESET and JMP instructions must share a longword!
