<!-- Converted from Motorola M68000 Family Programmer's Reference Manual (1992) -->
# Section 4: Integer Instructions (E-N)

Instructions EORI through NOT.

---

## EORI — Exclusive-OR Immediate

**Processors:** M68000 Family

**Operation:** Immediate Data ⊕ Destination → Destination

**Syntax:**
```
EORI #<data>,<ea>
```

**Attributes:** Size = (Byte, Word, Long)

**Description:** Performs an exclusive-OR operation on the destination operand using the immediate data and the destination operand and stores the result in the destination location. The size of the operation may be specified as byte, word, or long. The size of the immediate data matches the operation size.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| — | * | * | 0 | 0 |

- X — Not affected.
- N — Set if the most significant bit of the result is set; cleared otherwise.
- Z — Set if the result is zero; cleared otherwise.
- V — Always cleared.
- C — Always cleared.

**Instruction Fields:**

- Size field — Specifies the size of the operation.
  - 00 — Byte operation
  - 01 — Word operation
  - 10 — Long operation
- Effective Address field — Specifies the destination operand. Only data alterable addressing modes can be used.
- Immediate field — Data immediately following the instruction.
  - If size = 00, the data is the low-order byte of the immediate word.
  - If size = 01, the data is the entire immediate word.
  - If size = 10, the data is next two immediate words.

---

## EORI to CCR — Exclusive-OR Immediate to Condition Code Register

**Processors:** M68000 Family

**Operation:** Source ⊕ CCR → CCR

**Syntax:**
```
EORI #<data>,CCR
```

**Attributes:** Size = (Byte)

**Description:** Performs an exclusive-OR operation on the condition code register using the immediate operand and stores the result in the condition code register (low-order byte of the status register). All implemented bits of the condition code register are affected.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | * | * | * | * |

- X — Changed if bit 4 of immediate operand is one; unchanged otherwise.
- N — Changed if bit 3 of immediate operand is one; unchanged otherwise.
- Z — Changed if bit 2 of immediate operand is one; unchanged otherwise.
- V — Changed if bit 1 of immediate operand is one; unchanged otherwise.
- C — Changed if bit 0 of immediate operand is one; unchanged otherwise.

---

## EXG — Exchange Registers

**Processors:** M68000 Family

**Operation:** Rx <-> Ry

**Syntax:**
```
EXG Dx,Dy
EXG Ax,Ay
EXG Dx,Ay
```

**Attributes:** Size = (Long)

**Description:** Exchanges the contents of two 32-bit registers. The instruction performs three types of exchanges:
1. Exchange data registers.
2. Exchange address registers.
3. Exchange a data register and an address register.

**Condition Codes:** Not affected.

**Instruction Fields:**

- Register Rx field — Specifies either a data register or an address register depending on the mode. If the exchange is between data and address registers, this field always specifies the data register.
- Opmode field — Specifies the type of exchange.
  - 01000 — Data registers
  - 01001 — Address registers
  - 10001 — Data register and address register
- Register Ry field — Specifies either a data register or an address register depending on the mode. If the exchange is between data and address registers, this field always specifies the address register.

---

## EXT, EXTB — Sign-Extend

**Processors:** M68000 Family

**Operation:** Destination Sign-Extended → Destination

**Syntax:**
```
EXT.W Dn          extend byte to word
EXT.L Dn          extend word to long word
EXTB.L Dn         extend byte to long word (MC68020, MC68030, MC68040, CPU32)
```

**Attributes:** Size = (Word, Long)

**Description:** Extends a byte in a data register to a word or a long word, or a word in a data register to a long word, by replicating the sign bit to the left. If the operation extends a byte to a word, bit 7 of the designated data register is copied to bits 15-8 of that data register. If the operation extends a word to a long word, bit 15 of the designated data register is copied to bits 31-16 of the data register. The EXTB form copies bit 7 of the designated register to bits 31-8 of the data register.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| — | * | * | 0 | 0 |

- X — Not affected.
- N — Set if the result is negative; cleared otherwise.
- Z — Set if the result is zero; cleared otherwise.
- V — Always cleared.
- C — Always cleared.

**Instruction Fields:**

- Opmode field — Specifies the size of the sign-extension operation.
  - 010 — Sign-extend low-order byte of data register to word.
  - 011 — Sign-extend low-order word of data register to long.
  - 111 — Sign-extend low-order byte of data register to long.
- Register field — Specifies the data register to be sign-extended.

---

## ILLEGAL — Take Illegal Instruction Trap

**Processors:** M68000 Family

**Operation:** SSP - 2 → SSP; Vector Offset → (SSP); SSP - 4 → SSP; PC → (SSP); SSP - 2 → SSP; SR → (SSP); Illegal Instruction Vector Address → PC

> Note: The MC68000 and MC68008 cannot write the vector offset and format code to the system stack.

**Syntax:**
```
ILLEGAL
```

**Attributes:** Unsized

**Description:** Forces an illegal instruction exception, vector number 4. All other illegal instruction bit patterns are reserved for future extension of the instruction set and should not be used to force an exception.

**Condition Codes:** Not affected.

---

## JMP — Jump

**Processors:** M68000 Family

**Operation:** Destination Address → PC

**Syntax:**
```
JMP <ea>
```

**Attributes:** Unsized

**Description:** Program execution continues at the effective address specified by the instruction. The addressing mode for the effective address must be a control addressing mode.

**Condition Codes:** Not affected.

**Instruction Fields:**

- Effective Address field — Specifies the address of the next instruction. Only control addressing modes can be used: (An), (d16,An), (d8,An,Xn), (xxx).W, (xxx).L, (d16,PC), (d8,PC,Xn). MC68020/030/040 also support (bd,An,Xn), (bd,PC,Xn), ([bd,An,Xn],od), ([bd,PC,Xn],od), ([bd,An],Xn,od), ([bd,PC],Xn,od).

---

## JSR — Jump to Subroutine

**Processors:** M68000 Family

**Operation:** SP - 4 → SP; PC → (SP); Destination Address → PC

**Syntax:**
```
JSR <ea>
```

**Attributes:** Unsized

**Description:** Pushes the long-word address of the instruction immediately following the JSR instruction onto the system stack. Program execution then continues at the address specified in the instruction.

**Condition Codes:** Not affected.

**Instruction Fields:**

- Effective Address field — Specifies the address of the next instruction. Only control addressing modes can be used: (An), (d16,An), (d8,An,Xn), (xxx).W, (xxx).L, (d16,PC), (d8,PC,Xn). MC68020/030/040 also support (bd,An,Xn), (bd,PC,Xn), ([bd,An,Xn],od), ([bd,PC,Xn],od), ([bd,An],Xn,od), ([bd,PC],Xn,od).

---

## LEA — Load Effective Address

**Processors:** M68000 Family

**Operation:** \<ea\> → An

**Syntax:**
```
LEA <ea>,An
```

**Attributes:** Size = (Long)

**Description:** Loads the effective address into the specified address register. All 32 bits of the address register are affected by this instruction.

**Condition Codes:** Not affected.

**Instruction Fields:**

- Register field — Specifies the address register to be updated with the effective address.
- Effective Address field — Specifies the address to be loaded into the address register. Only control addressing modes can be used: (An), (d16,An), (d8,An,Xn), (xxx).W, (xxx).L, (d16,PC), (d8,PC,Xn). MC68020/030/040 also support (bd,An,Xn), (bd,PC,Xn), ([bd,An,Xn],od), ([bd,PC,Xn],od), ([bd,An],Xn,od), ([bd,PC],Xn,od).

---

## LINK — Link and Allocate

**Processors:** M68000 Family

**Operation:** SP - 4 → SP; An → (SP); SP → An; SP + dn → SP

**Syntax:**
```
LINK An,#<displacement>
```

**Attributes:** Size = (Word, Long*)

> *Long form available on MC68020, MC68030, MC68040, and CPU32 only.

**Description:** Pushes the contents of the specified address register onto the stack. Then loads the updated stack pointer into the address register. Finally, adds the displacement value to the stack pointer. For word-size operation, the displacement is the sign-extended word following the operation word. For long size operation, the displacement is the long word following the operation word. The address register occupies one long word on the stack. The user should specify a negative displacement in order to allocate stack area.

**Condition Codes:** Not affected.

**Instruction Fields:**

- Register field — Specifies the address register for the link.
- Displacement field — Specifies the twos complement integer to be added to the stack pointer.

> Note: LINK and UNLK can be used to maintain a linked list of local data and parameter areas on the stack for nested subroutine calls.

---

## LSL, LSR — Logical Shift

**Processors:** M68000 Family

**Operation:** Destination Shifted By Count → Destination

**Syntax:**
```
LSd Dx,Dy
LSd #<data>,Dy
LSd <ea>
```
where d is direction, L or R

**Attributes:** Size = (Byte, Word, Long)

**Description:** Shifts the bits of the operand in the direction specified (L or R). The carry bit receives the last bit shifted out of the operand. The shift count for the shifting of a register is specified in two different ways:
1. Immediate — The shift count (1-8) is specified in the instruction.
2. Register — The shift count is the value in the data register specified in the instruction modulo 64.

The size of the operation for register destinations may be specified as byte, word, or long. The contents of memory, \<ea\>, can be shifted one bit only, and the operand size is restricted to a word.

The LSL instruction shifts the operand to the left the number of positions specified as the shift count. Bits shifted out of the high-order bit go to both the carry and the extend bits; zeros are shifted into the low-order bit.

```
LSL:  C <-- [OPERAND] <-- 0    X
```

The LSR instruction shifts the operand to the right the number of positions specified as the shift count. Bits shifted out of the low-order bit go to both the carry and the extend bits; zeros are shifted into the high-order bit.

```
LSR:  0 --> [OPERAND] --> C    X
```

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | * | * | 0 | * |

- X — Set according to the last bit shifted out of the operand; unaffected for a shift count of zero.
- N — Set if the result is negative; cleared otherwise.
- Z — Set if the result is zero; cleared otherwise.
- V — Always cleared.
- C — Set according to the last bit shifted out of the operand; cleared for a shift count of zero.

**Instruction Fields (Register Shifts):**

- Count/Register field
  - If i/r = 0, this field contains the shift count. The values 1-7 represent shifts of 1-7; value of zero specifies a shift count of eight.
  - If i/r = 1, the data register specified in this field contains the shift count (modulo 64).
- dr field — Specifies the direction of the shift.
  - 0 — Shift right
  - 1 — Shift left
- Size field — Specifies the size of the operation.
  - 00 — Byte operation
  - 01 — Word operation
  - 10 — Long operation
- i/r field
  - If i/r = 0, specifies immediate shift count.
  - If i/r = 1, specifies register shift count.
- Register field — Specifies a data register to be shifted.

**Instruction Fields (Memory Shifts):**

- dr field — Specifies the direction of the shift.
  - 0 — Shift right
  - 1 — Shift left
- Effective Address field — Specifies the operand to be shifted. Only memory alterable addressing modes can be used.

---

## MOVE — Move Data from Source to Destination

**Processors:** M68000 Family

**Operation:** Source → Destination

**Syntax:**
```
MOVE <ea>,<ea>
```

**Attributes:** Size = (Byte, Word, Long)

**Description:** Moves the data at the source to the destination location and sets the condition codes according to the data. The size of the operation may be specified as byte, word, or long.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| — | * | * | 0 | 0 |

- X — Not affected.
- N — Set if the result is negative; cleared otherwise.
- Z — Set if the result is zero; cleared otherwise.
- V — Always cleared.
- C — Always cleared.

**Instruction Fields:**

- Size field — Specifies the size of the operand to be moved.
  - 01 — Byte operation
  - 11 — Word operation
  - 10 — Long operation
- Destination Effective Address field — Specifies the destination location. Only data alterable addressing modes can be used: Dn, (An), (An)+, -(An), (d16,An), (d8,An,Xn), (xxx).W, (xxx).L. MC68020/030/040 also support (bd,An,Xn), ([bd,An,Xn],od), ([bd,An],Xn,od).
- Source Effective Address field — Specifies the source operand. All addressing modes can be used: Dn, An (not for byte size), (An), (An)+, -(An), (d16,An), (d8,An,Xn), (xxx).W, (xxx).L, #\<data\>, (d16,PC), (d8,PC,Xn). MC68020/030/040 also support (bd,An,Xn), (bd,PC,Xn), ([bd,An,Xn],od), ([bd,PC,Xn],od), ([bd,An],Xn,od), ([bd,PC],Xn,od).

> Note: Most assemblers use MOVEA when the destination is an address register. MOVEQ can be used to move an immediate 8-bit value to a data register.

---

## MOVEA — Move Address

**Processors:** M68000 Family

**Operation:** Source → Destination

**Syntax:**
```
MOVEA <ea>,An
```

**Attributes:** Size = (Word, Long)

**Description:** Moves the contents of the source to the destination address register. The size of the operation is specified as word or long. Word-size source operands are sign-extended to 32-bit quantities.

**Condition Codes:** Not affected.

**Instruction Fields:**

- Size field — Specifies the size of the operand to be moved.
  - 11 — Word operation; the source operand is sign-extended to a long operand and all 32 bits are loaded into the address register.
  - 10 — Long operation.
- Destination Register field — Specifies the destination address register.
- Effective Address field — Specifies the location of the source operand. All addressing modes can be used: Dn, An, (An), (An)+, -(An), (d16,An), (d8,An,Xn), (xxx).W, (xxx).L, #\<data\>, (d16,PC), (d8,PC,Xn). MC68020/030/040 also support (bd,An,Xn), (bd,PC,Xn), ([bd,An,Xn],od), ([bd,PC,Xn],od), ([bd,An],Xn,od), ([bd,PC],Xn,od).

---

## MOVE from CCR — Move from the Condition Code Register

**Processors:** MC68010, MC68020, MC68030, MC68040, CPU32

**Operation:** CCR → Destination

**Syntax:**
```
MOVE CCR,<ea>
```

**Attributes:** Size = (Word)

**Description:** Moves the condition code bits (zero-extended to word size) to the destination location. The operand size is a word. Unimplemented bits are read as zeros.

**Condition Codes:** Not affected.

**Instruction Fields:**

- Effective Address field — Specifies the destination location. Only data alterable addressing modes can be used: Dn, (An), (An)+, -(An), (d16,An), (d8,An,Xn), (xxx).W, (xxx).L. MC68020/030/040 also support (bd,An,Xn), ([bd,An,Xn],od), ([bd,An],Xn,od).

> Note: MOVE from CCR is a word operation. ANDI, ORI, and EORI to CCR are byte operations.

---

## MOVE to CCR — Move to Condition Code Register

**Processors:** M68000 Family

**Operation:** Source → CCR

**Syntax:**
```
MOVE <ea>,CCR
```

**Attributes:** Size = (Word)

**Description:** Moves the low-order byte of the source operand to the condition code register. The upper byte of the source operand is ignored; the upper byte of the status register is not altered.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | * | * | * | * |

- X — Set to the value of bit 4 of the source operand.
- N — Set to the value of bit 3 of the source operand.
- Z — Set to the value of bit 2 of the source operand.
- V — Set to the value of bit 1 of the source operand.
- C — Set to the value of bit 0 of the source operand.

**Instruction Fields:**

- Effective Address field — Specifies the location of the source operand. Only data addressing modes can be used: Dn, (An), (An)+, -(An), (d16,An), (d8,An,Xn), (xxx).W, (xxx).L, #\<data\>, (d16,PC), (d8,PC,Xn). MC68020/030/040 also support (bd,An,Xn), (bd,PC,Xn), ([bd,An,Xn],od), ([bd,PC,Xn],od), ([bd,An],Xn,od), ([bd,PC],Xn,od).

> Note: MOVE to CCR is a word operation. ANDI, ORI, and EORI to CCR are byte operations.

---

## MOVE from SR — Move from the Status Register

**Processors:** MC68000, MC68008

> Note: On MC68010, MC68020, MC68030, MC68040, and CPU32 this is a privileged instruction. Use MOVE from CCR to access only the condition codes on those processors.

**Operation:** SR → Destination

**Syntax:**
```
MOVE SR,<ea>
```

**Attributes:** Size = (Word)

**Description:** Moves the data in the status register to the destination location. The destination is word length. Unimplemented bits are read as zeros.

**Condition Codes:** Not affected.

**Instruction Fields:**

- Effective Address field — Specifies the destination location. Only data alterable addressing modes can be used: Dn, (An), (An)+, -(An), (d16,An), (d8,An,Xn), (xxx).W, (xxx).L.

> Note: Use the MOVE from CCR instruction to access only the condition codes. Memory destination is read before it is written to.

---

## MOVE16 — Move 16-Byte Block

**Processors:** MC68040

**Operation:** Source Block → Destination Block

**Syntax:**
```
MOVE16 (Ax)+,(Ay)+
MOVE16 (xxx).L,(An)
MOVE16 (xxx).L,(An)+
MOVE16 (An),(xxx).L
MOVE16 (An)+,(xxx).L
```

**Attributes:** Size = (Line)

**Description:** Moves the source line to the destination line. The lines are aligned to 16-byte boundaries. Applications for this instruction include coprocessor communications, memory initialization, and fast block copy operations.

MOVE16 has two formats. The postincrement format uses the postincrement addressing mode for both source and destination; whereas, the absolute format specifies an absolute long address for either the source or destination.

Line transfers are performed using burst reads and writes, which begin with the long word pointed to by the effective address of the source and destination, respectively. An address register used in the postincrement addressing mode is incremented by 16 after the transfer.

**Example:**

`MOVE16 (A0)+,$FE802` with A0 = $1400F

The line at address $14000 is read into a temporary holding register by a burst read transfer starting with long-word $14000. Address values in A0 of $14000-$1400F cause the same line to be read, starting at different long words. The line is then written to the line at address $FE800 beginning with long-word $FE800. After the instruction, A0 contains $1401F.

**Condition Codes:** Not affected.

**Instruction Fields (Postincrement Source and Destination):**

- Register Ax — Specifies a source address register for the postincrement addressing mode.
- Register Ay — Specifies a destination address register for the postincrement addressing mode.

**Instruction Fields (Absolute Long Address Source or Destination):**

- Opmode field — Specifies the addressing modes used for source and destination:

  | Opmode | Source | Destination | Assembler Syntax |
  |--------|--------|-------------|------------------|
  | 00 | (Ay)+ | (xxx).L | MOVE16 (Ay)+,(xxx).L |
  | 01 | (xxx).L | (Ay)+ | MOVE16 (xxx).L,(Ay)+ |
  | 10 | (Ay) | (xxx).L | MOVE16 (Ay),(xxx).L |
  | 11 | (xxx).L | (Ay) | MOVE16 (xxx).L,(Ay) |

- Register Ay — Specifies an address register for the indirect and postincrement addressing mode used as a source or destination.
- 32-Bit Address field — Specifies the absolute address used as a source or destination.

---

## MOVEM — Move Multiple Registers

**Processors:** M68000 Family

**Operation:** Registers → Destination; Source → Registers

**Syntax:**
```
MOVEM <list>,<ea>
MOVEM <ea>,<list>
```

**Attributes:** Size = (Word, Long)

**Description:** Moves the contents of selected registers to or from consecutive memory locations starting at the location specified by the effective address. A register is selected if the bit in the mask field corresponding to that register is set. The instruction size determines whether 16 or 32 bits of each register are transferred. In the case of a word transfer to either address or data registers, each word is sign-extended to 32 bits, and the resulting long word is loaded into the associated register.

Selecting the addressing mode also selects the mode of operation of the MOVEM instruction, and only the control modes, the predecrement mode, and the postincrement mode are valid. If the effective address is specified by one of the control modes, the registers are transferred starting at the specified address, and the address is incremented by the operand length (2 or 4) following each transfer. The order of the registers is from D0 to D7, then from A0 to A7.

If the effective address is specified by the predecrement mode, only a register-to-memory operation is allowed. The registers are stored starting at the specified address minus the operand length (2 or 4), and the address is decremented by the operand length following each transfer. The order of storing is from A7 to A0, then from D7 to D0. When the instruction has completed, the decremented address register contains the address of the last operand stored. For the MC68020, MC68030, MC68040, and CPU32, if the addressing register is also moved to memory, the value written is the initial register value decremented by the size of the operation. The MC68000 and MC68010 write the initial register value (not decremented).

If the effective address is specified by the postincrement mode, only a memory-to-register operation is allowed. The registers are loaded starting at the specified address; the address is incremented by the operand length (2 or 4) following each transfer. The order of loading is the same as that of control mode addressing. When the instruction has completed, the incremented address register contains the address of the last operand loaded plus the operand length. If the addressing register is also loaded from memory, the memory value is ignored and the register is written with the postincremented effective address.

**Condition Codes:** Not affected.

**Instruction Fields:**

- dr field — Specifies the direction of the transfer.
  - 0 — Register to memory.
  - 1 — Memory to register.
- Size field — Specifies the size of the registers being transferred.
  - 0 — Word transfer
  - 1 — Long transfer
- Effective Address field — Specifies the memory address for the operation.
  - For register-to-memory transfers, only control alterable addressing modes or the predecrement addressing mode can be used.
  - For memory-to-register transfers, only control addressing modes or the postincrement addressing mode can be used.
- Register List Mask field — Specifies the registers to be transferred. The low-order bit corresponds to the first register to be transferred; the high-order bit corresponds to the last register to be transferred.

  For control modes and postincrement mode, the mask correspondence is:

  | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
  |----|----|----|----|----|----|----|---|---|---|---|---|---|---|---|---|
  | A7 | A6 | A5 | A4 | A3 | A2 | A1 | A0 | D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |

  For predecrement mode, the mask correspondence is reversed:

  | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
  |----|----|----|----|----|----|----|---|---|---|---|---|---|---|---|---|
  | D0 | D1 | D2 | D3 | D4 | D5 | D6 | D7 | A0 | A1 | A2 | A3 | A4 | A5 | A6 | A7 |

---

## MOVEP — Move Peripheral Data

**Processors:** M68000 Family

**Operation:** Source → Destination

**Syntax:**
```
MOVEP Dx,(d16,Ay)
MOVEP (d16,Ay),Dx
```

**Attributes:** Size = (Word, Long)

**Description:** Moves data between a data register and alternate bytes within the address space starting at the location specified and incrementing by two. The high-order byte of the data register is transferred first, and the low-order byte is transferred last. The memory address is specified in the address register indirect plus 16-bit displacement addressing mode.

This instruction was originally designed for interfacing 8-bit peripherals on a 16-bit data bus, such as the MC68000 bus. Although supported by the MC68020, MC68030, and MC68040, this instruction is not useful for those processors with an external 32-bit bus.

For a long transfer, bytes are mapped as follows:

| Register Bits | Memory (16-bit bus) |
|---------------|---------------------|
| 31-24 (High Order) | Address + 0 |
| 23-16 (Mid Upper) | Address + 2 |
| 15-8 (Mid Lower) | Address + 4 |
| 7-0 (Low Order) | Address + 6 |

For a word transfer, bytes are mapped as:

| Register Bits | Memory (16-bit bus) |
|---------------|---------------------|
| 15-8 (High Order) | Address + 0 |
| 7-0 (Low Order) | Address + 2 |

**Condition Codes:** Not affected.

**Instruction Fields:**

- Data Register field — Specifies the data register for the instruction.
- Opmode field — Specifies the direction and size of the operation.
  - 100 — Transfer word from memory to register.
  - 101 — Transfer long from memory to register.
  - 110 — Transfer word from register to memory.
  - 111 — Transfer long from register to memory.
- Address Register field — Specifies the address register which is used in the address register indirect plus displacement addressing mode.
- Displacement field — Specifies the displacement used in the operand address.

---

## MOVEQ — Move Quick

**Processors:** M68000 Family

**Operation:** Immediate Data → Destination

**Syntax:**
```
MOVEQ #<data>,Dn
```

**Attributes:** Size = (Long)

**Description:** Moves a byte of immediate data to a 32-bit data register. The data in an 8-bit field within the operation word is sign-extended to a long operand in the data register as it is transferred.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| — | * | * | 0 | 0 |

- X — Not affected.
- N — Set if the result is negative; cleared otherwise.
- Z — Set if the result is zero; cleared otherwise.
- V — Always cleared.
- C — Always cleared.

**Instruction Fields:**

- Register field — Specifies the data register to be loaded.
- Data field — Eight bits of data, which are sign-extended to a long operand.

---

## MULS — Signed Multiply

**Processors:** M68000 Family

**Operation:** Source x Destination → Destination

**Syntax:**
```
MULS.W <ea>,Dn           16 x 16 → 32
MULS.L <ea>,Dl            32 x 32 → 32    (MC68020, MC68030, MC68040, CPU32)
MULS.L <ea>,Dh:Dl         32 x 32 → 64    (MC68020, MC68030, MC68040, CPU32)
```

**Attributes:** Size = (Word, Long)

**Description:** Multiplies two signed operands yielding a signed result. This instruction has a word operand form and a long operand form.

In the word form, the multiplier and multiplicand are both word operands, and the result is a long-word operand. A register operand is the low-order word; the upper word of the register is ignored. All 32 bits of the product are saved in the destination data register.

In the long form, the multiplier and multiplicand are both long-word operands, and the result is either a long word or a quad word. The long-word result is the low-order 32 bits of the quad-word result; the high-order 32 bits of the product are discarded.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| — | * | * | * | 0 |

- X — Not affected.
- N — Set if the result is negative; cleared otherwise.
- Z — Set if the result is zero; cleared otherwise.
- V — Set if overflow; cleared otherwise.
- C — Always cleared.

> Note: Overflow (V = 1) can occur only when multiplying 32-bit operands to yield a 32-bit result. Overflow occurs if the high-order 32 bits of the quad-word product are not the sign extension of the low-order 32 bits.

**Instruction Fields (Word):**

- Register field — Specifies a data register as the destination.
- Effective Address field — Specifies the source operand. Only data addressing modes can be used: Dn, (An), (An)+, -(An), (d16,An), (d8,An,Xn), (xxx).W, (xxx).L, #\<data\>, (d16,PC), (d8,PC,Xn). MC68020/030/040 also support (bd,An,Xn), (bd,PC,Xn), ([bd,An,Xn],od), ([bd,PC,Xn],od), ([bd,An],Xn,od), ([bd,PC],Xn,od).

**Instruction Fields (Long):**

- Effective Address field — Specifies the source operand. Only data addressing modes can be used (same as word form).
- Register Dl field — Specifies a data register for the destination operand. The 32-bit multiplicand comes from this register, and the low-order 32 bits of the product are loaded into this register.
- Size field — Selects a 32- or 64-bit product.
  - 0 — 32-bit product to be returned to register Dl.
  - 1 — 64-bit product to be returned to Dh:Dl.
- Register Dh field — If size is one, specifies the data register into which the high-order 32 bits of the product are loaded. If Dh = Dl and size is one, the results of the operation are undefined. Otherwise, this field is unused.

---

## MULU — Unsigned Multiply

**Processors:** M68000 Family

**Operation:** Source x Destination → Destination

**Syntax:**
```
MULU.W <ea>,Dn           16 x 16 → 32
MULU.L <ea>,Dl            32 x 32 → 32    (MC68020, MC68030, MC68040, CPU32)
MULU.L <ea>,Dh:Dl         32 x 32 → 64    (MC68020, MC68030, MC68040, CPU32)
```

**Attributes:** Size = (Word, Long)

**Description:** Multiplies two unsigned operands yielding an unsigned result. This instruction has a word operand form and a long operand form.

In the word form, the multiplier and multiplicand are both word operands, and the result is a long-word operand. A register operand is the low-order word; the upper word of the register is ignored. All 32 bits of the product are saved in the destination data register.

In the long form, the multiplier and multiplicand are both long-word operands, and the result is either a long word or a quad word. The long-word result is the low-order 32 bits of the quad-word result; the high-order 32 bits of the product are discarded.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| — | * | * | * | 0 |

- X — Not affected.
- N — Set if the result is negative; cleared otherwise.
- Z — Set if the result is zero; cleared otherwise.
- V — Set if overflow; cleared otherwise.
- C — Always cleared.

> Note: Overflow (V = 1) can occur only when multiplying 32-bit operands to yield a 32-bit result. Overflow occurs if any of the high-order 32 bits of the quad-word product are not equal to zero.

**Instruction Fields (Word):**

- Register field — Specifies a data register as the destination.
- Effective Address field — Specifies the source operand. Only data addressing modes can be used: Dn, (An), (An)+, -(An), (d16,An), (d8,An,Xn), (xxx).W, (xxx).L, #\<data\>, (d16,PC), (d8,PC,Xn). MC68020/030/040 also support (bd,An,Xn), (bd,PC,Xn), ([bd,An,Xn],od), ([bd,PC,Xn],od), ([bd,An],Xn,od), ([bd,PC],Xn,od).

**Instruction Fields (Long):**

- Effective Address field — Specifies the source operand. Only data addressing modes can be used (same as word form).
- Register Dl field — Specifies a data register for the destination operand. The 32-bit multiplicand comes from this register, and the low-order 32 bits of the product are loaded into this register.
- Size field — Selects a 32- or 64-bit product.
  - 0 — 32-bit product to be returned to register Dl.
  - 1 — 64-bit product to be returned to Dh:Dl.
- Register Dh field — If size is one, specifies the data register into which the high-order 32 bits of the product are loaded. If Dh = Dl and size is one, the results of the operation are undefined. Otherwise, this field is unused.

---

## NBCD — Negate Decimal with Extend

**Processors:** M68000 Family

**Operation:** 0 - Destination10 - X → Destination

**Syntax:**
```
NBCD <ea>
```

**Attributes:** Size = (Byte)

**Description:** Subtracts the destination operand and the extend bit from zero. The operation is performed using binary-coded decimal arithmetic. The packed binary-coded decimal result is saved in the destination location. This instruction produces the tens complement of the destination if the extend bit is zero or the nines complement if the extend bit is one. This is a byte operation only.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | U | * | U | * |

- X — Set the same as the carry bit.
- N — Undefined.
- Z — Cleared if the result is nonzero; unchanged otherwise.
- V — Undefined.
- C — Set if a decimal borrow occurs; cleared otherwise.

> Note: Normally the Z condition code bit is set via programming before the start of the operation. This allows successful tests for zero results upon completion of multiple-precision operations.

**Instruction Fields:**

- Effective Address field — Specifies the destination operand. Only data alterable addressing modes can be used: Dn, (An), (An)+, -(An), (d16,An), (d8,An,Xn), (xxx).W, (xxx).L. MC68020/030/040 also support (bd,An,Xn), ([bd,An,Xn],od), ([bd,An],Xn,od).

---

## NEG — Negate

**Processors:** M68000 Family

**Operation:** 0 - Destination → Destination

**Syntax:**
```
NEG <ea>
```

**Attributes:** Size = (Byte, Word, Long)

**Description:** Subtracts the destination operand from zero and stores the result in the destination location. The size of the operation is specified as byte, word, or long.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | * | * | * | * |

- X — Set the same as the carry bit.
- N — Set if the result is negative; cleared otherwise.
- Z — Set if the result is zero; cleared otherwise.
- V — Set if an overflow occurs; cleared otherwise.
- C — Cleared if the result is zero; set otherwise.

**Instruction Fields:**

- Size field — Specifies the size of the operation.
  - 00 — Byte operation
  - 01 — Word operation
  - 10 — Long operation
- Effective Address field — Specifies the destination operand. Only data alterable addressing modes can be used: Dn, (An), (An)+, -(An), (d16,An), (d8,An,Xn), (xxx).W, (xxx).L. MC68020/030/040 also support (bd,An,Xn), ([bd,An,Xn],od), ([bd,An],Xn,od).

---

## NEGX — Negate with Extend

**Processors:** M68000 Family

**Operation:** 0 - Destination - X → Destination

**Syntax:**
```
NEGX <ea>
```

**Attributes:** Size = (Byte, Word, Long)

**Description:** Subtracts the destination operand and the extend bit from zero. Stores the result in the destination location. The size of the operation is specified as byte, word, or long.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | * | * | * | * |

- X — Set the same as the carry bit.
- N — Set if the result is negative; cleared otherwise.
- Z — Cleared if the result is nonzero; unchanged otherwise.
- V — Set if an overflow occurs; cleared otherwise.
- C — Set if a borrow occurs; cleared otherwise.

> Note: Normally the Z condition code bit is set via programming before the start of the operation. This allows successful tests for zero results upon completion of multiple-precision operations.

**Instruction Fields:**

- Size field — Specifies the size of the operation.
  - 00 — Byte operation
  - 01 — Word operation
  - 10 — Long operation
- Effective Address field — Specifies the destination operand. Only data alterable addressing modes can be used: Dn, (An), (An)+, -(An), (d16,An), (d8,An,Xn), (xxx).W, (xxx).L. MC68020/030/040 also support (bd,An,Xn), ([bd,An,Xn],od), ([bd,An],Xn,od).

---

## NOP — No Operation

**Processors:** M68000 Family

**Operation:** None

**Syntax:**
```
NOP
```

**Attributes:** Unsized

**Description:** Performs no operation. The processor state, other than the program counter, is unaffected. Execution continues with the instruction following the NOP instruction. The NOP instruction does not begin execution until all pending bus cycles have completed. This synchronizes the pipeline and prevents instruction overlap.

**Condition Codes:** Not affected.

---

## NOT — Logical Complement

**Processors:** M68000 Family

**Operation:** ~Destination → Destination

**Syntax:**
```
NOT <ea>
```

**Attributes:** Size = (Byte, Word, Long)

**Description:** Calculates the ones complement of the destination operand and stores the result in the destination location. The size of the operation is specified as byte, word, or long.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| — | * | * | 0 | 0 |

- X — Not affected.
- N — Set if the result is negative; cleared otherwise.
- Z — Set if the result is zero; cleared otherwise.
- V — Always cleared.
- C — Always cleared.

**Instruction Fields:**

- Size field — Specifies the size of the operation.
  - 00 — Byte operation
  - 01 — Word operation
  - 10 — Long operation
- Effective Address field — Specifies the destination operand. Only data alterable addressing modes can be used: Dn, (An), (An)+, -(An), (d16,An), (d8,An,Xn), (xxx).W, (xxx).L. MC68020/030/040 also support (bd,An,Xn), ([bd,An,Xn],od), ([bd,An],Xn,od).
