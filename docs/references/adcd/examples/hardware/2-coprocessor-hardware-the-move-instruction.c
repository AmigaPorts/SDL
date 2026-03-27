/* Source: ADCD 2.1
 * Section: 2-coprocessor-hardware-the-move-instruction
 * Library: hardware
 * ADCD reference: hardware/2-coprocessor-hardware-the-move-instruction.md
 */

        INCLUDE "hardware/custom.i"

        DC.W    bplpt+$00,$0002 ;Move $0002 into register $0E0 (BPL1PTH)
        DC.W    bplpt+$02,$1000 ;Move $1000 into register $0E2 (BPL1PTL)
        DC.W    bplpt+$04,$0002 ;Move $0002 into register $0E4 (BPL2PTH)
        DC.W    bplpt+$06,$5000 ;Move $5000 into register $0E6 (BPL2PTL)
