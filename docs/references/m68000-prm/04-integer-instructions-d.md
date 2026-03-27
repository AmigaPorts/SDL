<!-- Converted from Motorola M68000 Family Programmer's Reference Manual (1992) -->
# Section 4: Integer Instructions (O-U)

Instructions OR through UNLK.

---

## OR — Inclusive-OR Logical

**Processors:** M68000 Family

**Operation:** Source V Destination -> Destination

**Syntax:**
```
OR <ea>,Dn
OR Dn,<ea>
```

**Attributes:** Size = (Byte, Word, Long)

**Description:** Performs an inclusive-OR operation on the source operand and the destination operand and stores the result in the destination location. The size of the operation is specified as byte, word, or long. The contents of an address register may not be used as an operand.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | 0 | 0 |

- X -- Not affected.
- N -- Set if the most significant bit of the result is set; cleared otherwise.
- Z -- Set if the result is zero; cleared otherwise.
- V -- Always cleared.
- C -- Always cleared.

**Instruction Fields:**

- Register field -- Specifies any of the eight data registers.
- Opmode field:

| Size | `<ea>` V Dn -> Dn | Dn V `<ea>` -> `<ea>` |
|------|--------------------|-----------------------|
| Byte | 000 | 100 |
| Word | 001 | 101 |
| Long | 010 | 110 |

- Effective Address field -- If the location specified is a source operand, only data addressing modes can be used. If the location specified is a destination operand, only memory alterable addressing modes can be used.

**Note:** If the destination is a data register, it must be specified using the destination Dn mode, not the destination `<ea>` mode. Most assemblers use ORI when the source is immediate data.

---

## ORI — Inclusive-OR Immediate

**Processors:** M68000 Family

**Operation:** Immediate Data V Destination -> Destination

**Syntax:**
```
ORI #<data>,<ea>
```

**Attributes:** Size = (Byte, Word, Long)

**Description:** Performs an inclusive-OR operation on the immediate data and the destination operand and stores the result in the destination location. The size of the operation is specified as byte, word, or long. The size of the immediate data matches the operation size.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | 0 | 0 |

- X -- Not affected.
- N -- Set if the most significant bit of the result is set; cleared otherwise.
- Z -- Set if the result is zero; cleared otherwise.
- V -- Always cleared.
- C -- Always cleared.

**Instruction Fields:**

- Size field -- Specifies the size of the operation:
  - 00 -- Byte operation
  - 01 -- Word operation
  - 10 -- Long operation
- Effective Address field -- Specifies the destination operand. Only data alterable addressing modes can be used.
- Immediate field -- Data immediately following the instruction.
  - If size = 00, the data is the low-order byte of the immediate word.
  - If size = 01, the data is the entire immediate word.
  - If size = 10, the data is the next two immediate words.

---

## ORI to CCR — Inclusive-OR Immediate to Condition Codes

**Processors:** M68000 Family

**Operation:** Source V CCR -> CCR

**Syntax:**
```
ORI #<data>,CCR
```

**Attributes:** Size = (Byte)

**Description:** Performs an inclusive-OR operation on the immediate operand and the condition codes and stores the result in the condition code register (low-order byte of the status register). All implemented bits of the condition code register are affected.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | * | * | * | * |

- X -- Set if bit 4 of immediate operand is one; unchanged otherwise.
- N -- Set if bit 3 of immediate operand is one; unchanged otherwise.
- Z -- Set if bit 2 of immediate operand is one; unchanged otherwise.
- V -- Set if bit 1 of immediate operand is one; unchanged otherwise.
- C -- Set if bit 0 of immediate operand is one; unchanged otherwise.

---

## ORI to SR — Inclusive-OR Immediate to the Status Register

**Processors:** M68000 Family

**Operation:** If supervisor state then Source V SR -> SR; else TRAP

**Syntax:**
```
ORI #<data>,SR
```

**Attributes:** Size = (Word)

**Description:** Performs an inclusive-OR operation on the immediate operand and the status register and stores the result in the status register. All bits of the status register are affected. This is a privileged instruction.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | * | * | * | * |

- X -- Set if bit 4 of immediate operand is one; unchanged otherwise.
- N -- Set if bit 3 of immediate operand is one; unchanged otherwise.
- Z -- Set if bit 2 of immediate operand is one; unchanged otherwise.
- V -- Set if bit 1 of immediate operand is one; unchanged otherwise.
- C -- Set if bit 0 of immediate operand is one; unchanged otherwise.

---

## PACK — Pack BCD

**Processors:** MC68020, MC68030, MC68040

**Operation:** Source (Unpacked BCD) + Adjustment -> Destination (Packed BCD)

**Syntax:**
```
PACK -(Ax),-(Ay),#<adjustment>
PACK Dx,Dy,#<adjustment>
```

**Attributes:** Unsized

**Description:** Adjusts and packs the lower four bits of each of two bytes into a single byte.

When both operands are data registers, the adjustment is added to the value contained in the source register. Bits 11-8 and 3-0 of the intermediate result are concatenated and placed in bits 7-0 of the destination register. The remainder of the destination register is unaffected.

When the predecrement addressing mode is specified, two bytes from the source are fetched and concatenated. The adjustment word is added to the concatenated bytes. Bits 3-0 of each byte are extracted. These eight bits are concatenated to form a new byte which is then written to the destination.

**Condition Codes:** Not affected.

**Instruction Fields:**

- Register Dy/Ay field -- Specifies the destination register.
  - If R/M = 0, specifies a data register.
  - If R/M = 1, specifies an address register in the predecrement addressing mode.
- R/M field -- Specifies the operand addressing mode.
  - 0 -- The operation is data register to data register.
  - 1 -- The operation is memory to memory.
- Register Dx/Ax field -- Specifies the source register.
  - If R/M = 0, specifies a data register.
  - If R/M = 1, specifies an address register in the predecrement addressing mode.
- Adjustment field -- Immediate data word that is added to the source operand. This word is zero to pack ASCII or EBCDIC codes. Other values can be used for other codes.

---

## PEA — Push Effective Address

**Processors:** M68000 Family

**Operation:** SP - 4 -> SP; `<ea>` -> (SP)

**Syntax:**
```
PEA <ea>
```

**Attributes:** Size = (Long)

**Description:** Computes the effective address and pushes it onto the stack. The effective address is a long address.

**Condition Codes:** Not affected.

**Instruction Fields:**

- Effective Address field -- Specifies the address to be pushed onto the stack. Only control addressing modes can be used.

---

## RESET — Reset External Devices

**Processors:** M68000 Family

**Operation:** If supervisor state then Assert RESET Line; else TRAP

**Syntax:**
```
RESET
```

**Attributes:** Unsized

**Description:** Asserts the RESET signal for 124 clock periods, resetting all external devices. The processor state, other than the program counter, is not affected, and execution continues with the next instruction. This is a privileged instruction.

**Condition Codes:** Not affected.

---

## ROL, ROR — Rotate (Without Extend)

**Processors:** M68000 Family

**Operation:** Destination Rotated By `<count>` -> Destination

**Syntax:**
```
ROd Dx,Dy
ROd #<data>,Dy
ROd <ea>
```
where d is direction, L or R

**Attributes:** Size = (Byte, Word, Long)

**Description:** Rotates the bits of the operand in the direction specified (L or R). The extend bit is not included in the rotation. The rotate count for the rotation of a register is specified in either of two ways:

1. Immediate -- The rotate count (1-8) is specified in the instruction.
2. Register -- The rotate count is the value in the data register specified in the instruction, modulo 64.

The size of the operation for register destinations is specified as byte, word, or long. The contents of memory can be rotated one bit only, and operand size is restricted to a word.

The ROL instruction rotates the bits of the operand to the left; the rotate count determines the number of bit positions rotated. Bits rotated out of the high-order bit go to the carry bit and also back into the low-order bit.

The ROR instruction rotates the bits of the operand to the right; the rotate count determines the number of bit positions rotated. Bits rotated out of the low-order bit go to the carry bit and also back into the high-order bit.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | 0 | * |

- X -- Not affected.
- N -- Set if the most significant bit of the result is set; cleared otherwise.
- Z -- Set if the result is zero; cleared otherwise.
- V -- Always cleared.
- C -- Set according to the last bit rotated out of the operand; cleared when the rotate count is zero.

**Instruction Fields (Register Rotate):**

- Count/Register field:
  - If i/r = 0, this field contains the rotate count. The values 1-7 represent counts of 1-7, and zero specifies a count of eight.
  - If i/r = 1, this field specifies a data register that contains the rotate count (modulo 64).
- dr field -- Specifies the direction of the rotate.
  - 0 -- Rotate right
  - 1 -- Rotate left
- Size field -- Specifies the size of the operation:
  - 00 -- Byte operation
  - 01 -- Word operation
  - 10 -- Long operation
- i/r field -- Specifies the rotate count location.
  - If i/r = 0, immediate rotate count.
  - If i/r = 1, register rotate count.
- Register field -- Specifies a data register to be rotated.

**Instruction Fields (Memory Rotate):**

- dr field -- Specifies the direction of the rotate.
  - 0 -- Rotate right
  - 1 -- Rotate left
- Effective Address field -- Specifies the operand to be rotated. Only memory alterable addressing modes can be used.

---

## ROXL, ROXR — Rotate with Extend

**Processors:** M68000 Family

**Operation:** Destination Rotated With X By Count -> Destination

**Syntax:**
```
ROXd Dx,Dy
ROXd #<data>,Dy
ROXd <ea>
```
where d is direction, L or R

**Attributes:** Size = (Byte, Word, Long)

**Description:** Rotates the bits of the operand in the direction specified (L or R). The extend bit is included in the rotation. The rotate count for the rotation of a register is specified in either of two ways:

1. Immediate -- The rotate count (1-8) is specified in the instruction.
2. Register -- The rotate count is the value in the data register specified in the instruction, modulo 64.

The size of the operation for register destinations is specified as byte, word, or long. The contents of memory can be rotated one bit only, and operand size is restricted to a word.

The ROXL instruction rotates the bits of the operand to the left; the rotate count determines the number of bit positions rotated. Bits rotated out of the high-order bit go to the carry bit and the extend bit; the previous value of the extend bit rotates into the low-order bit.

The ROXR instruction rotates the bits of the operand to the right; the rotate count determines the number of bit positions rotated. Bits rotated out of the low-order bit go to the carry bit and the extend bit; the previous value of the extend bit rotates into the high-order bit.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | * | * | 0 | * |

- X -- Set to the value of the last bit rotated out of the operand; unaffected when the rotate count is zero.
- N -- Set if the most significant bit of the result is set; cleared otherwise.
- Z -- Set if the result is zero; cleared otherwise.
- V -- Always cleared.
- C -- Set according to the last bit rotated out of the operand; when the rotate count is zero, set to the value of the extend bit.

**Instruction Fields (Register Rotate):**

- Count/Register field:
  - If i/r = 0, this field contains the rotate count. The values 1-7 represent counts of 1-7, and zero specifies a count of eight.
  - If i/r = 1, this field specifies a data register that contains the rotate count (modulo 64).
- dr field -- Specifies the direction of the rotate.
  - 0 -- Rotate right
  - 1 -- Rotate left
- Size field -- Specifies the size of the operation:
  - 00 -- Byte operation
  - 01 -- Word operation
  - 10 -- Long operation
- i/r field -- Specifies the rotate count location.
  - If i/r = 0, immediate rotate count.
  - If i/r = 1, register rotate count.
- Register field -- Specifies a data register to be rotated.

**Instruction Fields (Memory Rotate):**

- dr field -- Specifies the direction of the rotate.
  - 0 -- Rotate right
  - 1 -- Rotate left
- Effective Address field -- Specifies the operand to be rotated. Only memory alterable addressing modes can be used.

---

## RTD — Return and Deallocate

**Processors:** MC68010, MC68020, MC68030, MC68040, CPU32

**Operation:** (SP) -> PC; SP + 4 + dn -> SP

**Syntax:**
```
RTD #<displacement>
```

**Attributes:** Unsized

**Description:** Pulls the program counter value from the stack and adds the sign-extended 16-bit displacement value to the stack pointer. The previous program counter value is lost.

**Condition Codes:** Not affected.

**Instruction Fields:**

- Displacement field -- Specifies the twos complement integer to be sign-extended and added to the stack pointer.

---

## RTM — Return from Module

**Processors:** MC68020

**Operation:** Reload Saved Module State from Stack

**Syntax:**
```
RTM Rn
```

**Attributes:** Unsized

**Description:** A previously saved module state is reloaded from the top of stack. After the module state is retrieved from the top of the stack, the caller's stack pointer is incremented by the argument count value in the module state.

**Condition Codes:** Set according to the content of the word on the stack.

**Instruction Fields:**

- D/A field -- Specifies whether the module data pointer is in a data or an address register.
  - 0 -- The register is a data register.
  - 1 -- The register is an address register.
- Register field -- Specifies the register number for the module data area pointer to be restored from the saved module state. If the register specified is A7 (SP), the updated value of the register reflects the stack pointer operations, and the saved module data area pointer is lost.

---

## RTR — Return and Restore Condition Codes

**Processors:** M68000 Family

**Operation:** (SP) -> CCR; SP + 2 -> SP; (SP) -> PC; SP + 4 -> SP

**Syntax:**
```
RTR
```

**Attributes:** Unsized

**Description:** Pulls the condition code and program counter values from the stack. The previous condition code and program counter values are lost. The supervisor portion of the status register is unaffected.

**Condition Codes:** Set to the condition codes from the stack.

---

## RTS — Return from Subroutine

**Processors:** M68000 Family

**Operation:** (SP) -> PC; SP + 4 -> SP

**Syntax:**
```
RTS
```

**Attributes:** Unsized

**Description:** Pulls the program counter value from the stack. The previous program counter value is lost.

**Condition Codes:** Not affected.

---

## SBCD — Subtract Decimal with Extend

**Processors:** M68000 Family

**Operation:** Destination10 - Source10 - X -> Destination

**Syntax:**
```
SBCD Dx,Dy
SBCD -(Ax),-(Ay)
```

**Attributes:** Size = (Byte)

**Description:** Subtracts the source operand and the extend bit from the destination operand and stores the result in the destination location. The subtraction is performed using binary-coded decimal arithmetic; the operands are packed binary-coded decimal numbers. The instruction has two modes:

1. Data register to data register -- The data registers specified in the instruction contain the operands.
2. Memory to memory -- The address registers specified in the instruction access the operands from memory using the predecrement addressing mode.

This operation is a byte operation only.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | U | * | U | * |

- X -- Set the same as the carry bit.
- N -- Undefined.
- Z -- Cleared if the result is nonzero; unchanged otherwise.
- V -- Undefined.
- C -- Set if a borrow (decimal) is generated; cleared otherwise.

**Note:** Normally the Z condition code bit is set via programming before the start of an operation. This allows successful tests for zero results upon completion of multiple-precision operations.

**Instruction Fields:**

- Register Dy/Ay field -- Specifies the destination register.
  - If R/M = 0, specifies a data register.
  - If R/M = 1, specifies an address register for the predecrement addressing mode.
- R/M field -- Specifies the operand addressing mode.
  - 0 -- The operation is data register to data register.
  - 1 -- The operation is memory to memory.
- Register Dx/Ax field -- Specifies the source register.
  - If R/M = 0, specifies a data register.
  - If R/M = 1, specifies an address register for the predecrement addressing mode.

---

## Scc — Set According to Condition

**Processors:** M68000 Family

**Operation:** If Condition True Then 1s -> Destination; Else 0s -> Destination

**Syntax:**
```
Scc <ea>
```

**Attributes:** Size = (Byte)

**Description:** Tests the specified condition code; if the condition is true, sets the byte specified by the effective address to TRUE (all ones, $FF). Otherwise, sets that byte to FALSE (all zeros, $00).

The condition code `cc` specifies one of the following conditional tests:

| Mnemonic | Condition | Mnemonic | Condition |
|----------|-----------|----------|-----------|
| CC(HI) | Carry Clear | LS | Low or Same |
| CS(LO) | Carry Set | LT | Less Than |
| EQ | Equal | MI | Minus |
| F | False | NE | Not Equal |
| GE | Greater or Equal | PL | Plus |
| GT | Greater Than | T | True |
| HI | High | VC | Overflow Clear |
| LE | Less or Equal | VS | Overflow Set |

**Condition Codes:** Not affected.

**Instruction Fields:**

- Condition field -- The binary code for one of the conditions listed in the table.
- Effective Address field -- Specifies the location in which the TRUE/FALSE byte is to be stored. Only data alterable addressing modes can be used.

**Note:** A subsequent `NEG.B` instruction with the same effective address can be used to change the Scc result from TRUE or FALSE to the equivalent arithmetic value (TRUE = 1, FALSE = 0). In the MC68000 and MC68008, a memory destination is read before it is written.

---

## STOP — Load Status Register and Stop

**Processors:** M68000 Family

**Operation:** If supervisor state then Immediate Data -> SR; STOP; else TRAP

**Syntax:**
```
STOP #<data>
```

**Attributes:** Unsized

**Description:** Moves the immediate operand into the entire status register (both user and supervisor portions), then suspends all processing and halts. This is a privileged instruction. Processing resumes when a trace, interrupt, or reset exception occurs. A trace exception will occur if the trace state is on when the STOP instruction begins execution. If an interrupt request is asserted with a priority higher than the level set by the new status register value, an interrupt exception occurs; otherwise the interrupt request has no effect. External reset always initiates reset exception processing.

**Condition Codes:** Set according to the immediate operand.

---

## SUB — Subtract

**Processors:** M68000 Family

**Operation:** Destination - Source -> Destination

**Syntax:**
```
SUB <ea>,Dn
SUB Dn,<ea>
```

**Attributes:** Size = (Byte, Word, Long)

**Description:** Subtracts the source operand from the destination operand and stores the result in the destination. The size of the operation is specified as byte, word, or long. The mode of the instruction indicates which operand is the source, which is the destination, and which is the operand size.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | * | * | * | * |

- X -- Set to the value of the carry bit.
- N -- Set if the result is negative; cleared otherwise.
- Z -- Set if the result is zero; cleared otherwise.
- V -- Set if an overflow is generated; cleared otherwise.
- C -- Set if a borrow is generated; cleared otherwise.

**Instruction Fields:**

- Register field -- Specifies any of the eight data registers.
- Opmode field:

| Size | Dn - `<ea>` -> Dn | `<ea>` - Dn -> `<ea>` |
|------|--------------------|-----------------------|
| Byte | 000 | 100 |
| Word | 001 | 101 |
| Long | 010 | 110 |

- Effective Address field -- If the location specified is a source operand, all addressing modes can be used (for byte-sized operation, address register direct is not allowed). If the location specified is a destination operand, only memory alterable addressing modes can be used.

**Note:** If the destination is a data register, it must be specified as a destination Dn address, not as a destination `<ea>` address. Most assemblers use SUBA when the destination is an address register and SUBI or SUBQ when the source is immediate data.

---

## SUBA — Subtract Address

**Processors:** M68000 Family

**Operation:** Destination - Source -> Destination

**Syntax:**
```
SUBA <ea>,An
```

**Attributes:** Size = (Word, Long)

**Description:** Subtracts the source operand from the destination address register and stores the result in the address register. The size of the operation is specified as word or long. Word-sized source operands are sign-extended to 32-bit quantities prior to the subtraction.

**Condition Codes:** Not affected.

**Instruction Fields:**

- Register field -- Specifies the destination, any of the eight address registers.
- Opmode field -- Specifies the size of the operation:
  - 011 -- Word operation. The source operand is sign-extended to a long operand and the operation is performed on the address register using all 32 bits.
  - 111 -- Long operation.
- Effective Address field -- Specifies the source operand. All addressing modes can be used.

---

## SUBI — Subtract Immediate

**Processors:** M68000 Family

**Operation:** Destination - Immediate Data -> Destination

**Syntax:**
```
SUBI #<data>,<ea>
```

**Attributes:** Size = (Byte, Word, Long)

**Description:** Subtracts the immediate data from the destination operand and stores the result in the destination location. The size of the operation is specified as byte, word, or long. The size of the immediate data matches the operation size.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | * | * | * | * |

- X -- Set to the value of the carry bit.
- N -- Set if the result is negative; cleared otherwise.
- Z -- Set if the result is zero; cleared otherwise.
- V -- Set if an overflow occurs; cleared otherwise.
- C -- Set if a borrow occurs; cleared otherwise.

**Instruction Fields:**

- Size field -- Specifies the size of the operation:
  - 00 -- Byte operation
  - 01 -- Word operation
  - 10 -- Long operation
- Effective Address field -- Specifies the destination operand. Only data alterable addressing modes can be used.
- Immediate field -- Data immediately following the instruction.
  - If size = 00, the data is the low-order byte of the immediate word.
  - If size = 01, the data is the entire immediate word.
  - If size = 10, the data is the next two immediate words.

---

## SUBQ — Subtract Quick

**Processors:** M68000 Family

**Operation:** Destination - Immediate Data -> Destination

**Syntax:**
```
SUBQ #<data>,<ea>
```

**Attributes:** Size = (Byte, Word, Long)

**Description:** Subtracts the immediate data (1-8) from the destination operand. The size of the operation is specified as byte, word, or long. Only word and long operations can be used with address registers, and the condition codes are not affected when subtracting from address registers. When subtracting from address registers, the entire destination address register is used, despite the operation size.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | * | * | * | * |

- X -- Set to the value of the carry bit.
- N -- Set if the result is negative; cleared otherwise.
- Z -- Set if the result is zero; cleared otherwise.
- V -- Set if an overflow occurs; cleared otherwise.
- C -- Set if a borrow occurs; cleared otherwise.

**Instruction Fields:**

- Data field -- Three bits of immediate data; 1-7 represent immediate values of 1-7, and zero represents eight.
- Size field -- Specifies the size of the operation:
  - 00 -- Byte operation
  - 01 -- Word operation
  - 10 -- Long operation
- Effective Address field -- Specifies the destination location. Only alterable addressing modes can be used. Address register direct is word and long only.

---

## SUBX — Subtract with Extend

**Processors:** M68000 Family

**Operation:** Destination - Source - X -> Destination

**Syntax:**
```
SUBX Dx,Dy
SUBX -(Ax),-(Ay)
```

**Attributes:** Size = (Byte, Word, Long)

**Description:** Subtracts the source operand and the extend bit from the destination operand and stores the result in the destination location. The instruction has two modes:

1. Data register to data register -- The data registers specified in the instruction contain the operands.
2. Memory to memory -- The address registers specified in the instruction access the operands from memory using the predecrement addressing mode.

The size of the operand is specified as byte, word, or long.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | * | * | * | * |

- X -- Set to the value of the carry bit.
- N -- Set if the result is negative; cleared otherwise.
- Z -- Cleared if the result is nonzero; unchanged otherwise.
- V -- Set if an overflow occurs; cleared otherwise.
- C -- Set if a borrow occurs; cleared otherwise.

**Note:** Normally the Z condition code bit is set via programming before the start of an operation. This allows successful tests for zero results upon completion of multiple-precision operations.

**Instruction Fields:**

- Register Dy/Ay field -- Specifies the destination register.
  - If R/M = 0, specifies a data register.
  - If R/M = 1, specifies an address register for the predecrement addressing mode.
- Size field -- Specifies the size of the operation:
  - 00 -- Byte operation
  - 01 -- Word operation
  - 10 -- Long operation
- R/M field -- Specifies the operand addressing mode.
  - 0 -- The operation is data register to data register.
  - 1 -- The operation is memory to memory.
- Register Dx/Ax field -- Specifies the source register.
  - If R/M = 0, specifies a data register.
  - If R/M = 1, specifies an address register for the predecrement addressing mode.

---

## SWAP — Swap Register Halves

**Processors:** M68000 Family

**Operation:** Register [31:16] <-> Register [15:0]

**Syntax:**
```
SWAP Dn
```

**Attributes:** Size = (Word)

**Description:** Exchange the 16-bit words (halves) of a data register.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | 0 | 0 |

- X -- Not affected.
- N -- Set if the most significant bit of the 32-bit result is set; cleared otherwise.
- Z -- Set if the 32-bit result is zero; cleared otherwise.
- V -- Always cleared.
- C -- Always cleared.

**Instruction Fields:**

- Register field -- Specifies the data register to swap.

---

## TAS — Test and Set an Operand

**Processors:** M68000 Family

**Operation:** Destination Tested -> Condition Codes; 1 -> Bit 7 of Destination

**Syntax:**
```
TAS <ea>
```

**Attributes:** Size = (Byte)

**Description:** Tests and sets the byte operand addressed by the effective address field. The instruction tests the current value of the operand and sets the N and Z condition bits appropriately. TAS also sets the high-order bit of the operand. The operation uses a locked or read-modify-write transfer sequence. This instruction supports use of a flag or semaphore to coordinate several processors.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | 0 | 0 |

- X -- Not affected.
- N -- Set if the most significant bit of the operand is currently set; cleared otherwise.
- Z -- Set if the operand was zero; cleared otherwise.
- V -- Always cleared.
- C -- Always cleared.

**Instruction Fields:**

- Effective Address field -- Specifies the location of the tested operand. Only data alterable addressing modes can be used.

---

## TRAP — Trap

**Processors:** M68000 Family

**Operation:** 1 -> S-Bit of SR; SSP - 2 -> SSP; Format/Offset -> (SSP); SSP - 4 -> SSP; PC -> (SSP); SSP - 2 -> SSP; SR -> (SSP); Vector Address -> PC

**Syntax:**
```
TRAP #<vector>
```

**Attributes:** Unsized

**Description:** Causes a TRAP #`<vector>` exception. The instruction adds the immediate operand (vector) of the instruction to 32 to obtain the vector number. The range of vector values is 0-15, which provides 16 vectors.

**Note:** The MC68000 and MC68008 do not write vector offset or format code to the system stack.

**Condition Codes:** Not affected.

**Instruction Fields:**

- Vector field -- Specifies the trap vector to be taken (0-15).

---

## TRAPcc — Trap on Condition

**Processors:** MC68020, MC68030, MC68040, CPU32

**Operation:** If cc Then TRAP

**Syntax:**
```
TRAPcc
TRAPcc.W #<data>
TRAPcc.L #<data>
```

**Attributes:** Unsized or Size = (Word, Long)

**Description:** If the specified condition is true, causes a TRAPcc exception with a vector number 7. The processor pushes the address of the next instruction word (currently in the program counter) onto the stack. If the condition is not true, the processor performs no operation, and execution continues with the next instruction. The immediate data operand should be placed in the next word(s) following the operation word and is available to the trap handler.

The condition code `cc` specifies one of the following conditional tests:

| Mnemonic | Condition | Mnemonic | Condition |
|----------|-----------|----------|-----------|
| CC(HI) | Carry Clear | LS | Low or Same |
| CS(LO) | Carry Set | LT | Less Than |
| EQ | Equal | MI | Minus |
| F | False | NE | Not Equal |
| GE | Greater or Equal | PL | Plus |
| GT | Greater Than | T | True |
| HI | High | VC | Overflow Clear |
| LE | Less or Equal | VS | Overflow Set |

**Condition Codes:** Not affected.

**Instruction Fields:**

- Condition field -- The binary code for one of the conditions listed in the table.
- Opmode field -- Selects the instruction form:
  - 010 -- Instruction is followed by word-sized operand.
  - 011 -- Instruction is followed by long-word-sized operand.
  - 100 -- Instruction has no operand.

---

## TRAPV — Trap on Overflow

**Processors:** M68000 Family

**Operation:** If V Then TRAP

**Syntax:**
```
TRAPV
```

**Attributes:** Unsized

**Description:** If the overflow condition is set, causes a TRAPV exception with a vector number 7. If the overflow condition is not set, the processor performs no operation and execution continues with the next instruction.

**Condition Codes:** Not affected.

---

## TST — Test an Operand

**Processors:** M68000 Family

**Operation:** Destination Tested -> Condition Codes

**Syntax:**
```
TST <ea>
```

**Attributes:** Size = (Byte, Word, Long)

**Description:** Compares the operand with zero and sets the condition codes according to the results of the test. The size of the operation is specified as byte, word, or long.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | 0 | 0 |

- X -- Not affected.
- N -- Set if the operand is negative; cleared otherwise.
- Z -- Set if the operand is zero; cleared otherwise.
- V -- Always cleared.
- C -- Always cleared.

**Instruction Fields:**

- Size field -- Specifies the size of the operation:
  - 00 -- Byte operation
  - 01 -- Word operation
  - 10 -- Long operation
- Effective Address field -- Specifies the destination operand. On MC68020, MC68030, MC68040, and CPU32, all addressing modes are available including address register direct (word and long only), PC relative, and immediate. On MC68000, MC68008, and MC68010, only data alterable addressing modes can be used.

---

## UNLK — Unlink

**Processors:** M68000 Family

**Operation:** An -> SP; (SP) -> An; SP + 4 -> SP

**Syntax:**
```
UNLK An
```

**Attributes:** Unsized

**Description:** Loads the stack pointer from the specified address register, then loads the address register with the long word pulled from the top of the stack.

**Condition Codes:** Not affected.

**Instruction Fields:**

- Register field -- Specifies the address register for the instruction.

---

## UNPK — Unpack BCD

**Processors:** MC68020, MC68030, MC68040

**Operation:** Source (Packed BCD) + Adjustment -> Destination (Unpacked BCD)

**Syntax:**
```
UNPK -(Ax),-(Ay),#<adjustment>
UNPK Dx,Dy,#<adjustment>
```

**Attributes:** Unsized

**Description:** Places the two binary-coded decimal digits in the source operand byte into the lower four bits of two bytes and places zero bits in the upper four bits of both bytes. Adds the adjustment value to this unpacked value. Condition codes are not altered.

When both operands are data registers, the instruction unpacks the source register contents, adds the extension word, and places the result in the destination register. The high word of the destination register is unaffected.

When the specified addressing mode is predecrement, the instruction extracts two binary-coded decimal digits from a byte at the source address. After unpacking the digits and adding the adjustment word, the instruction writes the two bytes to the destination address.

**Condition Codes:** Not affected.

**Instruction Fields:**

- Register Dy/Ay field -- Specifies the destination register.
  - If R/M = 0, specifies a data register.
  - If R/M = 1, specifies an address register in the predecrement addressing mode.
- R/M field -- Specifies the operand addressing mode.
  - 0 -- The operation is data register to data register.
  - 1 -- The operation is memory to memory.
- Register Dx/Ax field -- Specifies the source register.
  - If R/M = 0, specifies a data register.
  - If R/M = 1, specifies an address register in the predecrement addressing mode.
- Adjustment field -- Immediate data word that is added to the source operand. Appropriate constants can be used as the adjustment to translate from binary-coded decimal to the desired code. The constant used for ASCII is $3030; for EBCDIC, $F0F0.
