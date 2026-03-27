<!-- Converted from Motorola M68000 Family Programmer's Reference Manual (1992) -->
# Section 4: Integer Instructions (A-B)

Instructions ABCD through BFTST.

---

## ABCD -- Add Decimal with Extend

**Processors:** M68000 Family

**Operation:** Source10 + Destination10 + X -> Destination

**Syntax:**
```
ABCD Dy,Dx
ABCD -(Ay),-(Ax)
```

**Attributes:** Size = Byte

**Description:** Adds the source operand to the destination operand along with the extend bit, and stores the result in the destination location. The addition is performed using binary-coded decimal arithmetic. The operands, which are packed binary-coded decimal numbers, can be addressed in two different ways:

1. Data Register to Data Register: The operands are contained in the data registers specified in the instruction.
2. Memory to Memory: The operands are addressed with the predecrement addressing mode using the address registers specified in the instruction.

This operation is a byte operation only.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | U | * | U | * |

- X -- Set the same as the carry bit.
- N -- Undefined.
- Z -- Cleared if the result is nonzero; unchanged otherwise.
- V -- Undefined.
- C -- Set if a decimal carry was generated; cleared otherwise.

NOTE: Normally, the Z condition code bit is set via programming before the start of an operation. This allows successful tests for zero results upon completion of multiple-precision operations.

**Instruction Fields:**

- Register Rx field -- Specifies the destination register.
  - If R/M = 0, specifies a data register.
  - If R/M = 1, specifies an address register for the predecrement addressing mode.
- R/M field -- Specifies the operand addressing mode.
  - 0 -- The operation is data register to data register.
  - 1 -- The operation is memory to memory.
- Register Ry field -- Specifies the source register.
  - If R/M = 0, specifies a data register.
  - If R/M = 1, specifies an address register for the predecrement addressing mode.

---

## ADD -- Add

**Processors:** M68000 Family

**Operation:** Source + Destination -> Destination

**Syntax:**
```
ADD <ea>,Dn
ADD Dn,<ea>
```

**Attributes:** Size = Byte, Word, Long

**Description:** Adds the source operand to the destination operand using binary addition and stores the result in the destination location. The size of the operation may be specified as byte, word, or long. The mode of the instruction indicates which operand is the source and which is the destination, as well as the operand size.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | * | * | * | * |

- X -- Set the same as the carry bit.
- N -- Set if the result is negative; cleared otherwise.
- Z -- Set if the result is zero; cleared otherwise.
- V -- Set if an overflow is generated; cleared otherwise.
- C -- Set if a carry is generated; cleared otherwise.

**Instruction Fields:**

- Register field -- Specifies any of the eight data registers.
- Opmode field:

| Byte | Word | Long | Operation |
|------|------|------|-----------|
| 000  | 001  | 010  | \<ea\> + Dn -> Dn |
| 100  | 101  | 110  | Dn + \<ea\> -> \<ea\> |

- Effective Address field -- Determines addressing mode.
  - a. If the location specified is a source operand, all addressing modes can be used as listed in the following table:

    | Addressing Mode | Mode | Register |
    |-----------------|------|----------|
    | Dn | 000 | reg. number:Dn |
    | An* | 001 | reg. number:An |
    | (An) | 010 | reg. number:An |
    | (An)+ | 011 | reg. number:An |
    | -(An) | 100 | reg. number:An |
    | (d16,An) | 101 | reg. number:An |
    | (d8,An,Xn) | 110 | reg. number:An |
    | (xxx).W | 111 | 000 |
    | (xxx).L | 111 | 001 |
    | #\<data\> | 111 | 100 |
    | (d16,PC) | 111 | 010 |
    | (d8,PC,Xn) | 111 | 011 |

    *Word and long only.

    MC68020, MC68030, and MC68040 only: (bd,An,Xn), (bd,PC,Xn), ([bd,An,Xn],od), ([bd,PC,Xn],od), ([bd,An],Xn,od), ([bd,PC],Xn,od). Can be used with CPU32.

  - b. If the location specified is a destination operand, only memory alterable addressing modes can be used as listed in the following table:

    | Addressing Mode | Mode | Register |
    |-----------------|------|----------|
    | (An) | 010 | reg. number:An |
    | (An)+ | 011 | reg. number:An |
    | -(An) | 100 | reg. number:An |
    | (d16,An) | 101 | reg. number:An |
    | (d8,An,Xn) | 110 | reg. number:An |
    | (xxx).W | 111 | 000 |
    | (xxx).L | 111 | 001 |

    MC68020, MC68030, and MC68040 only: (bd,An,Xn), ([bd,An,Xn],od), ([bd,An],Xn,od). Can be used with CPU32.

NOTE: The Dn mode is used when the destination is a data register; the destination \<ea\> mode is invalid for a data register. ADDA is used when the destination is an address register. ADDI and ADDQ are used when the source is immediate data. Most assemblers automatically make this distinction.

---

## ADDA -- Add Address

**Processors:** M68000 Family

**Operation:** Source + Destination -> Destination

**Syntax:**
```
ADDA <ea>,An
```

**Attributes:** Size = Word, Long

**Description:** Adds the source operand to the destination address register and stores the result in the address register. The size of the operation may be specified as word or long. The entire destination address register is used regardless of the operation size.

**Condition Codes:** Not affected.

**Instruction Fields:**

- Register field -- Specifies any of the eight address registers. This is always the destination.
- Opmode field -- Specifies the size of the operation.
  - 011 -- Word operation; the source operand is sign-extended to a long operand and the operation is performed on the address register using all 32 bits.
  - 111 -- Long operation.
- Effective Address field -- Specifies the source operand. All addressing modes can be used as listed in the following table:

  | Addressing Mode | Mode | Register |
  |-----------------|------|----------|
  | Dn | 000 | reg. number:Dn |
  | An | 001 | reg. number:An |
  | (An) | 010 | reg. number:An |
  | (An)+ | 011 | reg. number:An |
  | -(An) | 100 | reg. number:An |
  | (d16,An) | 101 | reg. number:An |
  | (d8,An,Xn) | 110 | reg. number:An |
  | (xxx).W | 111 | 000 |
  | (xxx).L | 111 | 001 |
  | #\<data\> | 111 | 100 |
  | (d16,PC) | 111 | 010 |
  | (d8,PC,Xn) | 111 | 011 |

  MC68020, MC68030, and MC68040 only: (bd,An,Xn), (bd,PC,Xn), ([bd,An,Xn],od), ([bd,PC,Xn],od), ([bd,An],Xn,od), ([bd,PC],Xn,od). Can be used with CPU32.

---

## ADDI -- Add Immediate

**Processors:** M68000 Family

**Operation:** Immediate Data + Destination -> Destination

**Syntax:**
```
ADDI #<data>,<ea>
```

**Attributes:** Size = Byte, Word, Long

**Description:** Adds the immediate data to the destination operand and stores the result in the destination location. The size of the operation may be specified as byte, word, or long. The size of the immediate data matches the operation size.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | * | * | * | * |

- X -- Set the same as the carry bit.
- N -- Set if the result is negative; cleared otherwise.
- Z -- Set if the result is zero; cleared otherwise.
- V -- Set if an overflow is generated; cleared otherwise.
- C -- Set if a carry is generated; cleared otherwise.

**Instruction Fields:**

- Size field -- Specifies the size of the operation.
  - 00 -- Byte operation
  - 01 -- Word operation
  - 10 -- Long operation
- Effective Address field -- Specifies the destination operand. Only data alterable addressing modes can be used as listed in the following table:

  | Addressing Mode | Mode | Register |
  |-----------------|------|----------|
  | Dn | 000 | reg. number:Dn |
  | (An) | 010 | reg. number:An |
  | (An)+ | 011 | reg. number:An |
  | -(An) | 100 | reg. number:An |
  | (d16,An) | 101 | reg. number:An |
  | (d8,An,Xn) | 110 | reg. number:An |
  | (xxx).W | 111 | 000 |
  | (xxx).L | 111 | 001 |

  MC68020, MC68030, and MC68040 only: (bd,An,Xn), ([bd,An,Xn],od), ([bd,An],Xn,od). Can be used with CPU32.

- Immediate field -- Data immediately following the instruction.
  - If size = 00, the data is the low-order byte of the immediate word.
  - If size = 01, the data is the entire immediate word.
  - If size = 10, the data is the next two immediate words.

---

## ADDQ -- Add Quick

**Processors:** M68000 Family

**Operation:** Immediate Data + Destination -> Destination

**Syntax:**
```
ADDQ #<data>,<ea>
```

**Attributes:** Size = Byte, Word, Long

**Description:** Adds an immediate value of one to eight to the operand at the destination location. The size of the operation may be specified as byte, word, or long. Word and long operations are also allowed on the address registers. When adding to address registers, the condition codes are not altered, and the entire destination address register is used regardless of the operation size.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | * | * | * | * |

- X -- Set the same as the carry bit.
- N -- Set if the result is negative; cleared otherwise.
- Z -- Set if the result is zero; cleared otherwise.
- V -- Set if an overflow occurs; cleared otherwise.
- C -- Set if a carry occurs; cleared otherwise.

The condition codes are not affected when the destination is an address register.

**Instruction Fields:**

- Data field -- Three bits of immediate data representing eight values (0-7), with the immediate value zero representing a value of eight.
- Size field -- Specifies the size of the operation.
  - 00 -- Byte operation
  - 01 -- Word operation
  - 10 -- Long operation
- Effective Address field -- Specifies the destination location. Only alterable addressing modes can be used as listed in the following table:

  | Addressing Mode | Mode | Register |
  |-----------------|------|----------|
  | Dn | 000 | reg. number:Dn |
  | An* | 001 | reg. number:An |
  | (An) | 010 | reg. number:An |
  | (An)+ | 011 | reg. number:An |
  | -(An) | 100 | reg. number:An |
  | (d16,An) | 101 | reg. number:An |
  | (d8,An,Xn) | 110 | reg. number:An |
  | (xxx).W | 111 | 000 |
  | (xxx).L | 111 | 001 |

  *Word and long only.

  MC68020, MC68030, and MC68040 only: (bd,An,Xn), ([bd,An,Xn],od), ([bd,An],Xn,od). Can be used with CPU32.

---

## ADDX -- Add Extended

**Processors:** M68000 Family

**Operation:** Source + Destination + X -> Destination

**Syntax:**
```
ADDX Dy,Dx
ADDX -(Ay),-(Ax)
```

**Attributes:** Size = Byte, Word, Long

**Description:** Adds the source operand and the extend bit to the destination operand and stores the result in the destination location. The operands can be addressed in two different ways:

1. Data register to data register -- The data registers specified in the instruction contain the operands.
2. Memory to memory -- The address registers specified in the instruction address the operands using the predecrement addressing mode.

The size of the operation can be specified as byte, word, or long.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | * | * | * | * |

- X -- Set the same as the carry bit.
- N -- Set if the result is negative; cleared otherwise.
- Z -- Cleared if the result is nonzero; unchanged otherwise.
- V -- Set if an overflow occurs; cleared otherwise.
- C -- Set if a carry is generated; cleared otherwise.

NOTE: Normally, the Z condition code bit is set via programming before the start of an operation. This allows successful tests for zero results upon completion of multiple-precision operations.

**Instruction Fields:**

- Register Rx field -- Specifies the destination register.
  - If R/M = 0, specifies a data register.
  - If R/M = 1, specifies an address register for the predecrement addressing mode.
- Size field -- Specifies the size of the operation.
  - 00 -- Byte operation
  - 01 -- Word operation
  - 10 -- Long operation
- R/M field -- Specifies the operand address mode.
  - 0 -- The operation is data register to data register.
  - 1 -- The operation is memory to memory.
- Register Ry field -- Specifies the source register.
  - If R/M = 0, specifies a data register.
  - If R/M = 1, specifies an address register for the predecrement addressing mode.

---

## AND -- AND Logical

**Processors:** M68000 Family

**Operation:** Source AND Destination -> Destination

**Syntax:**
```
AND <ea>,Dn
AND Dn,<ea>
```

**Attributes:** Size = Byte, Word, Long

**Description:** Performs an AND operation of the source operand with the destination operand and stores the result in the destination location. The size of the operation can be specified as byte, word, or long. The contents of an address register may not be used as an operand.

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

| Byte | Word | Long | Operation |
|------|------|------|-----------|
| 000  | 001  | 010  | \<ea\> AND Dn -> Dn |
| 100  | 101  | 110  | Dn AND \<ea\> -> \<ea\> |

- Effective Address field -- Determines addressing mode.
  - a. If the location specified is a source operand, only data addressing modes can be used as listed in the following table:

    | Addressing Mode | Mode | Register |
    |-----------------|------|----------|
    | Dn | 000 | reg. number:Dn |
    | (An) | 010 | reg. number:An |
    | (An)+ | 011 | reg. number:An |
    | -(An) | 100 | reg. number:An |
    | (d16,An) | 101 | reg. number:An |
    | (d8,An,Xn) | 110 | reg. number:An |
    | (xxx).W | 111 | 000 |
    | (xxx).L | 111 | 001 |
    | #\<data\> | 111 | 100 |
    | (d16,PC) | 111 | 010 |
    | (d8,PC,Xn) | 111 | 011 |

    MC68020, MC68030, and MC68040 only: (bd,An,Xn), (bd,PC,Xn), ([bd,An,Xn],od), ([bd,PC,Xn],od), ([bd,An],Xn,od), ([bd,PC],Xn,od). Can be used with CPU32.

  - b. If the location specified is a destination operand, only memory alterable addressing modes can be used as listed in the following table:

    | Addressing Mode | Mode | Register |
    |-----------------|------|----------|
    | (An) | 010 | reg. number:An |
    | (An)+ | 011 | reg. number:An |
    | -(An) | 100 | reg. number:An |
    | (d16,An) | 101 | reg. number:An |
    | (d8,An,Xn) | 110 | reg. number:An |
    | (xxx).W | 111 | 000 |
    | (xxx).L | 111 | 001 |

    MC68020, MC68030, and MC68040 only: (bd,An,Xn), ([bd,An,Xn],od), ([bd,An],Xn,od). Can be used with CPU32.

NOTE: The Dn mode is used when the destination is a data register; the destination \<ea\> mode is invalid for a data register. Most assemblers use ANDI when the source is immediate data.

---

## ANDI -- AND Immediate

**Processors:** M68000 Family

**Operation:** Immediate Data AND Destination -> Destination

**Syntax:**
```
ANDI #<data>,<ea>
```

**Attributes:** Size = Byte, Word, Long

**Description:** Performs an AND operation of the immediate data with the destination operand and stores the result in the destination location. The size of the operation can be specified as byte, word, or long. The size of the immediate data matches the operation size.

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

- Size field -- Specifies the size of the operation.
  - 00 -- Byte operation
  - 01 -- Word operation
  - 10 -- Long operation
- Effective Address field -- Specifies the destination operand. Only data alterable addressing modes can be used as listed in the following table:

  | Addressing Mode | Mode | Register |
  |-----------------|------|----------|
  | Dn | 000 | reg. number:Dn |
  | (An) | 010 | reg. number:An |
  | (An)+ | 011 | reg. number:An |
  | -(An) | 100 | reg. number:An |
  | (d16,An) | 101 | reg. number:An |
  | (d8,An,Xn) | 110 | reg. number:An |
  | (xxx).W | 111 | 000 |
  | (xxx).L | 111 | 001 |

  MC68020, MC68030, and MC68040 only: (bd,An,Xn), ([bd,An,Xn],od), ([bd,An],Xn,od). Can be used with CPU32.

- Immediate field -- Data immediately following the instruction.
  - If size = 00, the data is the low-order byte of the immediate word.
  - If size = 01, the data is the entire immediate word.
  - If size = 10, the data is the next two immediate words.

---

## ANDI to CCR -- AND Immediate to Condition Codes

**Processors:** M68000 Family

**Operation:** Source AND CCR -> CCR

**Syntax:**
```
ANDI #<data>,CCR
```

**Attributes:** Size = Byte

**Description:** Performs an AND operation of the immediate operand with the condition codes and stores the result in the low-order byte of the status register.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | * | * | * | * |

- X -- Cleared if bit 4 of immediate operand is zero; unchanged otherwise.
- N -- Cleared if bit 3 of immediate operand is zero; unchanged otherwise.
- Z -- Cleared if bit 2 of immediate operand is zero; unchanged otherwise.
- V -- Cleared if bit 1 of immediate operand is zero; unchanged otherwise.
- C -- Cleared if bit 0 of immediate operand is zero; unchanged otherwise.

**Instruction Fields:** None; the instruction is fully specified by the opcode word and the following immediate byte.

---

## ASL, ASR -- Arithmetic Shift

**Processors:** M68000 Family

**Operation:** Destination Shifted By Count -> Destination

**Syntax:**
```
ASd Dx,Dy
ASd #<data>,Dy
ASd <ea>
```
where d is direction, L or R

**Attributes:** Size = Byte, Word, Long

**Description:** Arithmetically shifts the bits of the operand in the direction (L or R) specified. The carry bit receives the last bit shifted out of the operand. The shift count for the shifting of a register may be specified in two different ways:

1. Immediate -- The shift count is specified in the instruction (shift range, 1-8).
2. Register -- The shift count is the value in the data register specified in instruction modulo 64.

The size of the operation can be specified as byte, word, or long. An operand in memory can be shifted one bit only, and the operand size is restricted to a word.

For ASL, the operand is shifted left; the number of positions shifted is the shift count. Bits shifted out of the high-order bit go to both the carry and the extend bits; zeros are shifted into the low-order bit. The overflow bit indicates if any sign changes occur during the shift.

For ASR, the operand is shifted right; the number of positions shifted is the shift count. Bits shifted out of the low-order bit go to both the carry and the extend bits; the sign bit (MSB) is shifted into the high-order bit.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| * | * | * | * | * |

- X -- Set according to the last bit shifted out of the operand; unaffected for a shift count of zero.
- N -- Set if the most significant bit of the result is set; cleared otherwise.
- Z -- Set if the result is zero; cleared otherwise.
- V -- Set if the most significant bit is changed at any time during the shift operation; cleared otherwise.
- C -- Set according to the last bit shifted out of the operand; cleared for a shift count of zero.

**Instruction Fields (Register Shifts):**

- Count/Register field -- Specifies shift count or register that contains the shift count:
  - If i/r = 0, this field contains the shift count. The values 1-7 represent counts of 1-7; a value of zero represents a count of eight.
  - If i/r = 1, this field specifies the data register that contains the shift count (modulo 64).
- dr field -- Specifies the direction of the shift.
  - 0 -- Shift right
  - 1 -- Shift left
- Size field -- Specifies the size of the operation.
  - 00 -- Byte operation
  - 01 -- Word operation
  - 10 -- Long operation
- i/r field:
  - If i/r = 0, specifies immediate shift count.
  - If i/r = 1, specifies register shift count.
- Register field -- Specifies a data register to be shifted.

**Instruction Fields (Memory Shifts):**

- dr field -- Specifies the direction of the shift.
  - 0 -- Shift right
  - 1 -- Shift left
- Effective Address field -- Specifies the operand to be shifted. Only memory alterable addressing modes can be used as listed in the following table:

  | Addressing Mode | Mode | Register |
  |-----------------|------|----------|
  | (An) | 010 | reg. number:An |
  | (An)+ | 011 | reg. number:An |
  | -(An) | 100 | reg. number:An |
  | (d16,An) | 101 | reg. number:An |
  | (d8,An,Xn) | 110 | reg. number:An |
  | (xxx).W | 111 | 000 |
  | (xxx).L | 111 | 001 |

  MC68020, MC68030, and MC68040 only: (bd,An,Xn), ([bd,An,Xn],od), ([bd,An],Xn,od). Can be used with CPU32.

---

## Bcc -- Branch Conditionally

**Processors:** M68000 Family

**Operation:** If Condition True Then PC + dn -> PC

**Syntax:**
```
Bcc <label>
```

**Attributes:** Size = Byte, Word, Long*

*MC68020, MC68030, and MC68040 only for Long.

**Description:** If the specified condition is true, program execution continues at location (PC) + displacement. The program counter contains the address of the instruction word for the Bcc instruction plus two. The displacement is a twos-complement integer that represents the relative distance in bytes from the current program counter to the destination program counter. If the 8-bit displacement field in the instruction word is zero, a 16-bit displacement (the word immediately following the instruction) is used. If the 8-bit displacement field in the instruction word is all ones ($FF), the 32-bit displacement (long word immediately following the instruction) is used.

Condition code cc specifies one of the following conditional tests:

| Mnemonic | Condition |
|----------|-----------|
| CC(HI) | Carry Clear |
| CS(LO) | Carry Set |
| EQ | Equal |
| GE | Greater or Equal |
| GT | Greater Than |
| HI | High |
| LE | Less or Equal |
| LS | Low or Same |
| LT | Less Than |
| MI | Minus |
| NE | Not Equal |
| PL | Plus |
| VC | Overflow Clear |
| VS | Overflow Set |

**Condition Codes:** Not affected.

**Instruction Fields:**

- Condition field -- The binary code for one of the conditions listed in the table.
- 8-Bit Displacement field -- Twos complement integer specifying the number of bytes between the branch instruction and the next instruction to be executed if the condition is met.
- 16-Bit Displacement field -- Used for the displacement when the 8-bit displacement field contains $00.
- 32-Bit Displacement field -- Used for the displacement when the 8-bit displacement field contains $FF.

NOTE: A branch to the immediately following instruction automatically uses the 16-bit displacement format because the 8-bit displacement field contains $00 (zero offset).

---

## BCHG -- Test a Bit and Change

**Processors:** M68000 Family

**Operation:** TEST (\<bit number\> of Destination) -> Z; ~(\<bit number\> of Destination) -> \<bit number\> of Destination

**Syntax:**
```
BCHG Dn,<ea>
BCHG #<data>,<ea>
```

**Attributes:** Size = Byte, Long

**Description:** Tests a bit in the destination operand and sets the Z condition code appropriately, then inverts the specified bit in the destination. When the destination is a data register, any of the 32 bits can be specified by the modulo 32-bit number. When the destination is a memory location, the operation is a byte operation, and the bit number is modulo 8. In all cases, bit zero refers to the least significant bit. The bit number for this operation may be specified in either of two ways:

1. Immediate -- The bit number is specified in a second word of the instruction.
2. Register -- The specified data register contains the bit number.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | -- | * | -- | -- |

- X -- Not affected.
- N -- Not affected.
- Z -- Set if the bit tested is zero; cleared otherwise.
- V -- Not affected.
- C -- Not affected.

**Instruction Fields (Bit Number Dynamic, Specified in a Register):**

- Register field -- Specifies the data register that contains the bit number.
- Effective Address field -- Specifies the destination location. Only data alterable addressing modes can be used as listed in the following table:

  | Addressing Mode | Mode | Register |
  |-----------------|------|----------|
  | Dn* | 000 | reg. number:Dn |
  | (An) | 010 | reg. number:An |
  | (An)+ | 011 | reg. number:An |
  | -(An) | 100 | reg. number:An |
  | (d16,An) | 101 | reg. number:An |
  | (d8,An,Xn) | 110 | reg. number:An |
  | (xxx).W | 111 | 000 |
  | (xxx).L | 111 | 001 |

  *Long only; all others are byte only.

  MC68020, MC68030, and MC68040 only: (bd,An,Xn), ([bd,An,Xn],od), ([bd,An],Xn,od). Can be used with CPU32.

**Instruction Fields (Bit Number Static, Specified as Immediate Data):**

- Effective Address field -- Specifies the destination location. Only data alterable addressing modes can be used (same table as above).
- Bit Number field -- Specifies the bit number.

---

## BCLR -- Test a Bit and Clear

**Processors:** M68000 Family

**Operation:** TEST (\<bit number\> of Destination) -> Z; 0 -> \<bit number\> of Destination

**Syntax:**
```
BCLR Dn,<ea>
BCLR #<data>,<ea>
```

**Attributes:** Size = Byte, Long

**Description:** Tests a bit in the destination operand and sets the Z condition code appropriately, then clears the specified bit in the destination. When a data register is the destination, any of the 32 bits can be specified by a modulo 32-bit number. When a memory location is the destination, the operation is a byte operation, and the bit number is modulo 8. In all cases, bit zero refers to the least significant bit. The bit number for this operation can be specified in either of two ways:

1. Immediate -- The bit number is specified in a second word of the instruction.
2. Register -- The specified data register contains the bit number.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | -- | * | -- | -- |

- X -- Not affected.
- N -- Not affected.
- Z -- Set if the bit tested is zero; cleared otherwise.
- V -- Not affected.
- C -- Not affected.

**Instruction Fields (Bit Number Dynamic, Specified in a Register):**

- Register field -- Specifies the data register that contains the bit number.
- Effective Address field -- Specifies the destination location. Only data alterable addressing modes can be used as listed in the following table:

  | Addressing Mode | Mode | Register |
  |-----------------|------|----------|
  | Dn* | 000 | reg. number:Dn |
  | (An) | 010 | reg. number:An |
  | (An)+ | 011 | reg. number:An |
  | -(An) | 100 | reg. number:An |
  | (d16,An) | 101 | reg. number:An |
  | (d8,An,Xn) | 110 | reg. number:An |
  | (xxx).W | 111 | 000 |
  | (xxx).L | 111 | 001 |

  *Long only; all others are byte only.

  MC68020, MC68030, and MC68040 only: (bd,An,Xn), ([bd,An,Xn],od), ([bd,An],Xn,od). Can be used with CPU32.

**Instruction Fields (Bit Number Static, Specified as Immediate Data):**

- Effective Address field -- Specifies the destination location. Only data alterable addressing modes can be used (same table as above).
- Bit Number field -- Specifies the bit number.

---

## BFCHG -- Test Bit Field and Change

**Processors:** MC68020, MC68030, MC68040

**Operation:** TEST (\<bit field\> of Destination); ~(\<bit field\>) -> \<bit field\> of Destination

**Syntax:**
```
BFCHG <ea>{offset:width}
```

**Attributes:** Unsized

**Description:** Sets the condition codes according to the value in a bit field at the specified effective address, then complements the field. A field offset and a field width select the field. The field offset specifies the starting bit of the field. The field width determines the number of bits in the field.

NOTE: All bit field instructions access only those bytes in memory that contain some portion of the bit field. The possible accesses are byte, word, 3-byte, long word, and long word with byte (for a 5-byte access).

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | 0 | 0 |

- X -- Not affected.
- N -- Set if the most significant bit of the field is set; cleared otherwise.
- Z -- Set if all bits of the field are zero; cleared otherwise.
- V -- Always cleared.
- C -- Always cleared.

**Instruction Fields:**

- Effective Address field -- Specifies the base location for the bit field. Only data register direct or control alterable addressing modes can be used as listed in the following table:

  | Addressing Mode | Mode | Register |
  |-----------------|------|----------|
  | Dn | 000 | reg. number:Dn |
  | (An) | 010 | reg. number:An |
  | (d16,An) | 101 | reg. number:An |
  | (d8,An,Xn) | 110 | reg. number:An |
  | (bd,An,Xn) | 110 | reg. number:An |
  | ([bd,An,Xn],od) | 110 | reg. number:An |
  | ([bd,An],Xn,od) | 110 | reg. number:An |
  | (xxx).W | 111 | 000 |
  | (xxx).L | 111 | 001 |

- Do field -- Determines how the field offset is specified.
  - 0 -- The offset field contains the bit field offset.
  - 1 -- Bits 8-6 of the extension word specify a data register that contains the offset; bits 10-9 are zero.
- Offset field -- Specifies the field offset, depending on Do.
  - If Do = 0, the offset field is an immediate operand; the operand value is in the range 0-31.
  - If Do = 1, the offset field specifies a data register that contains the offset. The value is in the range of -2^31 to 2^31 - 1.
- Dw field -- Determines how the field width is specified.
  - 0 -- The width field contains the bit field width.
  - 1 -- Bits 2-0 of the extension word specify a data register that contains the width; bits 3-4 are zero.
- Width field -- Specifies the field width, depending on Dw.
  - If Dw = 0, the width field is an immediate operand; operand values in the range 1-31 specify a field width of 1-31, and a value of zero specifies a width of 32.
  - If Dw = 1, the width field specifies a data register that contains the width. The value is modulo 32; values of 1-31 specify field widths of 1-31, and a value of zero specifies a width of 32.

---

## BFCLR -- Test Bit Field and Clear

**Processors:** MC68020, MC68030, MC68040

**Operation:** TEST (\<bit field\> of Destination); 0 -> \<bit field\> of Destination

**Syntax:**
```
BFCLR <ea>{offset:width}
```

**Attributes:** Unsized

**Description:** Sets condition codes according to the value in a bit field at the specified effective address and clears the field. The field offset and field width select the field. The field offset specifies the starting bit of the field. The field width determines the number of bits in the field.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | 0 | 0 |

- X -- Not affected.
- N -- Set if the most significant bit of the field is set; cleared otherwise.
- Z -- Set if all bits of the field are zero; cleared otherwise.
- V -- Always cleared.
- C -- Always cleared.

**Instruction Fields:**

- Effective Address field -- Specifies the base location for the bit field. Only data register direct or control alterable addressing modes can be used as listed in the following table:

  | Addressing Mode | Mode | Register |
  |-----------------|------|----------|
  | Dn | 000 | reg. number:Dn |
  | (An) | 010 | reg. number:An |
  | (d16,An) | 101 | reg. number:An |
  | (d8,An,Xn) | 110 | reg. number:An |
  | (bd,An,Xn) | 110 | reg. number:An |
  | ([bd,An,Xn],od) | 110 | reg. number:An |
  | ([bd,An],Xn,od) | 110 | reg. number:An |
  | (xxx).W | 111 | 000 |
  | (xxx).L | 111 | 001 |

- Do field -- Determines how the field offset is specified.
  - 0 -- The offset field contains the bit field offset.
  - 1 -- Bits 8-6 of the extension word specify a data register that contains the offset; bits 10-9 are zero.
- Offset field -- Specifies the field offset, depending on Do.
  - If Do = 0, the offset field is an immediate operand; the operand value is in the range of 0-31.
  - If Do = 1, the offset field specifies a data register that contains the offset. The value is in the range of -2^31 to 2^31 - 1.
- Dw field -- Determines how the field width is specified.
  - 0 -- The width field contains the bit field width.
  - 1 -- Bits 2-0 of the extension word specify a data register that contains the width; bits 3-4 are zero.
- Width field -- Specifies the field width, depending on Dw.
  - If Dw = 0, the width field is an immediate operand; operand values in the range of 1-31 specify a field width of 1-31, and a value of zero specifies a width of 32.
  - If Dw = 1, the width field specifies a data register that contains the width. The value is modulo 32; values of 1-31 specify field widths of 1-31, and a value of zero specifies a width of 32.

---

## BFEXTS -- Extract Bit Field Signed

**Processors:** MC68020, MC68030, MC68040

**Operation:** \<bit field\> of Source -> Dn (sign-extended)

**Syntax:**
```
BFEXTS <ea>{offset:width},Dn
```

**Attributes:** Unsized

**Description:** Extracts a bit field from the specified effective address location, sign extends to 32 bits, and loads the result into the destination data register. The field offset and field width select the bit field. The field offset specifies the starting bit of the field. The field width determines the number of bits in the field.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | 0 | 0 |

- X -- Not affected.
- N -- Set if the most significant bit of the field is set; cleared otherwise.
- Z -- Set if all bits of the field are zero; cleared otherwise.
- V -- Always cleared.
- C -- Always cleared.

**Instruction Fields:**

- Effective Address field -- Specifies the base location for the bit field. Only data register direct or control addressing modes can be used as listed in the following table:

  | Addressing Mode | Mode | Register |
  |-----------------|------|----------|
  | Dn | 000 | reg. number:Dn |
  | (An) | 010 | reg. number:An |
  | (d16,An) | 101 | reg. number:An |
  | (d8,An,Xn) | 110 | reg. number:An |
  | (bd,An,Xn) | 110 | reg. number:An |
  | ([bd,An,Xn],od) | 110 | reg. number:An |
  | ([bd,An],Xn,od) | 110 | reg. number:An |
  | (xxx).W | 111 | 000 |
  | (xxx).L | 111 | 001 |
  | (d16,PC) | 111 | 010 |
  | (d8,PC,Xn) | 111 | 011 |
  | (bd,PC,Xn) | 111 | 011 |
  | ([bd,PC,Xn],od) | 111 | 011 |
  | ([bd,PC],Xn,od) | 111 | 011 |

- Register field -- Specifies the destination register.
- Do field -- Determines how the field offset is specified.
  - 0 -- The offset field contains the bit field offset.
  - 1 -- Bits 8-6 of the extension word specify a data register that contains the offset; bits 10-9 are zero.
- Offset field -- Specifies the field offset, depending on Do.
  - If Do = 0, the offset field is an immediate operand; the operand value is in the range of 0-31.
  - If Do = 1, the offset field specifies a data register that contains the offset. The value is in the range of -2^31 to 2^31 - 1.
- Dw field -- Determines how the field width is specified.
  - 0 -- The width field contains the bit field width.
  - 1 -- Bits 2-0 of the extension word specify a data register that contains the width; bits 4-3 are zero.
- Width field -- Specifies the field width, depending on Dw.
  - If Dw = 0, the width field is an immediate operand; operand values in the range of 1-31 specify a field width of 1-31, and a value of zero specifies a width of 32.
  - If Dw = 1, the width field specifies a data register that contains the width. The value is modulo 32; values of 1-31 specify field widths of 1-31, and a value of zero specifies a width of 32.

---

## BFEXTU -- Extract Bit Field Unsigned

**Processors:** MC68020, MC68030, MC68040

**Operation:** \<bit field\> of Source -> Dn (zero-extended)

**Syntax:**
```
BFEXTU <ea>{offset:width},Dn
```

**Attributes:** Unsized

**Description:** Extracts a bit field from the specified effective address location, zero extends to 32 bits, and loads the results into the destination data register. The field offset and field width select the field. The field offset specifies the starting bit of the field. The field width determines the number of bits in the field.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | 0 | 0 |

- X -- Not affected.
- N -- Set if the most significant bit of the source field is set; cleared otherwise.
- Z -- Set if all bits of the field are zero; cleared otherwise.
- V -- Always cleared.
- C -- Always cleared.

**Instruction Fields:**

- Effective Address field -- Specifies the base location for the bit field. Only data register direct or control addressing modes can be used as listed in the following table:

  | Addressing Mode | Mode | Register |
  |-----------------|------|----------|
  | Dn | 000 | reg. number:Dn |
  | (An) | 010 | reg. number:An |
  | (d16,An) | 101 | reg. number:An |
  | (d8,An,Xn) | 110 | reg. number:An |
  | (bd,An,Xn) | 110 | reg. number:An |
  | ([bd,An,Xn],od) | 110 | reg. number:An |
  | ([bd,An],Xn,od) | 110 | reg. number:An |
  | (xxx).W | 111 | 000 |
  | (xxx).L | 111 | 001 |
  | (d16,PC) | 111 | 010 |
  | (d8,PC,Xn) | 111 | 011 |
  | (bd,PC,Xn) | 111 | 011 |
  | ([bd,PC,Xn],od) | 111 | 011 |
  | ([bd,PC],Xn,od) | 111 | 011 |

- Register field -- Specifies the destination data register.
- Do field -- Determines how the field offset is specified.
  - 0 -- The offset field contains the bit field offset.
  - 1 -- Bits 8-6 of the extension word specify a data register that contains the offset; bits 10-9 are zero.
- Offset field -- Specifies the field offset, depending on Do.
  - If Do = 0, the offset field is an immediate operand; the operand value is in the range of 0-31.
  - If Do = 1, the offset field specifies a data register that contains the offset. The value is in the range of -2^31 to 2^31 - 1.
- Dw field -- Determines how the field width is specified.
  - 0 -- The width field contains the bit field width.
  - 1 -- Bits 2-0 of the extension word specify a data register that contains the width; bits 4-3 are zero.
- Width field -- Specifies the field width, depending on Dw.
  - If Dw = 0, the width field is an immediate operand; operand values in the range of 1-31 specify a field width of 1-31, and a value of zero specifies a width of 32.
  - If Dw = 1, the width field specifies a data register that contains the width. The value is modulo 32; values of 1-31 specify field widths of 1-31, and a value of zero specifies a width of 32.

---

## BFFFO -- Find First One in Bit Field

**Processors:** MC68020, MC68030, MC68040

**Operation:** \<bit offset\> of Source Bit Scan -> Dn

**Syntax:**
```
BFFFO <ea>{offset:width},Dn
```

**Attributes:** Unsized

**Description:** Searches the source operand for the most significant bit that is set to a value of one. The bit offset of that bit (the bit offset in the instruction plus the offset of the first one bit) is placed in Dn. If no bit in the bit field is set to one, the value in Dn is the field offset plus the field width. The instruction sets the condition codes according to the bit field value. The field offset and field width select the field. The field offset specifies the starting bit of the field. The field width determines the number of bits in the field.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | 0 | 0 |

- X -- Not affected.
- N -- Set if the most significant bit of the field is set; cleared otherwise.
- Z -- Set if all bits of the field are zero; cleared otherwise.
- V -- Always cleared.
- C -- Always cleared.

**Instruction Fields:**

- Effective Address field -- Specifies the base location for the bit field. Only data register direct or control addressing modes can be used as listed in the following table:

  | Addressing Mode | Mode | Register |
  |-----------------|------|----------|
  | Dn | 000 | reg. number:Dn |
  | (An) | 010 | reg. number:An |
  | (d16,An) | 101 | reg. number:An |
  | (d8,An,Xn) | 110 | reg. number:An |
  | (bd,An,Xn) | 110 | reg. number:An |
  | ([bd,An,Xn],od) | 110 | reg. number:An |
  | ([bd,An],Xn,od) | 110 | reg. number:An |
  | (xxx).W | 111 | 000 |
  | (xxx).L | 111 | 001 |
  | (d16,PC) | 111 | 010 |
  | (d8,PC,Xn) | 111 | 011 |
  | (bd,PC,Xn) | 111 | 011 |
  | ([bd,PC,Xn],od) | 111 | 011 |
  | ([bd,PC],Xn,od) | 111 | 011 |

- Register field -- Specifies the destination data register operand.
- Do field -- Determines how the field offset is specified.
  - 0 -- The offset field contains the bit field offset.
  - 1 -- Bits 8-6 of the extension word specify a data register that contains the offset; bits 10-9 are zero.
- Offset field -- Specifies the field offset, depending on Do.
  - If Do = 0, the offset field is an immediate operand; the operand value is in the range of 0-31.
  - If Do = 1, the offset field specifies a data register that contains the offset. The value is in the range of -2^31 to 2^31 - 1.
- Dw field -- Determines how the field width is specified.
  - 0 -- The width field contains the bit field width.
  - 1 -- Bits 2-0 of the extension word specify a data register that contains the width; bits 4-3 are zero.
- Width field -- Specifies the field width, depending on Dw.
  - If Dw = 0, the width field is an immediate operand; operand values in the range of 1-31 specify a field width of 1-31, and a value of zero specifies a width of 32.
  - If Dw = 1, the width field specifies a data register that contains the width. The value is modulo 32; values of 1-31 specify field widths of 1-31, and a value of zero specifies a width of 32.

---

## BFINS -- Insert Bit Field

**Processors:** MC68020, MC68030, MC68040

**Operation:** Dn -> \<bit field\> of Destination

**Syntax:**
```
BFINS Dn,<ea>{offset:width}
```

**Attributes:** Unsized

**Description:** Inserts a bit field taken from the low-order bits of the specified data register into a bit field at the effective address location. The instruction sets the condition codes according to the inserted value. The field offset and field width select the field. The field offset specifies the starting bit of the field. The field width determines the number of bits in the field.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | 0 | 0 |

- X -- Not affected.
- N -- Set if the most significant bit of the field is set; cleared otherwise.
- Z -- Set if all bits of the field are zero; cleared otherwise.
- V -- Always cleared.
- C -- Always cleared.

**Instruction Fields:**

- Effective Address field -- Specifies the base location for the bit field. Only data register direct or control alterable addressing modes can be used as listed in the following table:

  | Addressing Mode | Mode | Register |
  |-----------------|------|----------|
  | Dn | 000 | reg. number:Dn |
  | (An) | 010 | reg. number:An |
  | (d16,An) | 101 | reg. number:An |
  | (d8,An,Xn) | 110 | reg. number:An |
  | (bd,An,Xn) | 110 | reg. number:An |
  | ([bd,An,Xn],od) | 110 | reg. number:An |
  | ([bd,An],Xn,od) | 110 | reg. number:An |
  | (xxx).W | 111 | 000 |
  | (xxx).L | 111 | 001 |

- Register field -- Specifies the source data register operand.
- Do field -- Determines how the field offset is specified.
  - 0 -- The offset field contains the bit field offset.
  - 1 -- Bits 8-6 of the extension word specify a data register that contains the offset; bits 10-9 are zero.
- Offset field -- Specifies the field offset, depending on Do.
  - If Do = 0, the offset field is an immediate operand; the operand value is in the range of 0-31.
  - If Do = 1, the offset field specifies a data register that contains the offset. The value is in the range of -2^31 to 2^31 - 1.
- Dw field -- Determines how the field width is specified.
  - 0 -- The width field contains the bit field width.
  - 1 -- Bits 2-0 of the extension word specify a data register that contains the width; bits 4-3 are zero.
- Width field -- Specifies the field width, depending on Dw.
  - If Dw = 0, the width field is an immediate operand; operand values in the range of 1-31 specify a field width of 1-31, and a value of zero specifies a width of 32.
  - If Dw = 1, the width field specifies a data register that contains the width. The value is modulo 32; values of 1-31 specify field widths of 1-31, and a value of zero specifies a width of 32.

---

## BFSET -- Test Bit Field and Set

**Processors:** MC68020, MC68030, MC68040

**Operation:** TEST (\<bit field\> of Destination); 1s -> \<bit field\> of Destination

**Syntax:**
```
BFSET <ea>{offset:width}
```

**Attributes:** Unsized

**Description:** Sets the condition codes according to the value in a bit field at the specified effective address, then sets each bit in the field. The field offset and the field width select the field. The field offset specifies the starting bit of the field. The field width determines the number of bits in the field.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | 0 | 0 |

- X -- Not affected.
- N -- Set if the most significant bit of the field is set; cleared otherwise.
- Z -- Set if all bits of the field are zero; cleared otherwise.
- V -- Always cleared.
- C -- Always cleared.

**Instruction Fields:**

- Effective Address field -- Specifies the base location for the bit field. Only data register direct or control alterable addressing modes can be used as listed in the following table:

  | Addressing Mode | Mode | Register |
  |-----------------|------|----------|
  | Dn | 000 | reg. number:Dn |
  | (An) | 010 | reg. number:An |
  | (d16,An) | 101 | reg. number:An |
  | (d8,An,Xn) | 110 | reg. number:An |
  | (bd,An,Xn) | 110 | reg. number:An |
  | ([bd,An,Xn],od) | 110 | reg. number:An |
  | ([bd,An],Xn,od) | 110 | reg. number:An |
  | (xxx).W | 111 | 000 |
  | (xxx).L | 111 | 001 |

- Do field -- Determines how the field offset is specified.
  - 0 -- The offset field contains the bit field offset.
  - 1 -- Bits 8-6 of the extension word specify a data register that contains the offset; bits 10-9 are zero.
- Offset field -- Specifies the field offset, depending on Do.
  - If Do = 0, the offset field is an immediate operand; the operand value is in the range of 0-31.
  - If Do = 1, the offset field specifies a data register that contains the offset. The value is in the range of -2^31 to 2^31 - 1.
- Dw field -- Determines how the field width is specified.
  - 0 -- The width field contains the bit field width.
  - 1 -- Bits 2-0 of the extension word specify a data register that contains the width; bits 3-4 are zero.
- Width field -- Specifies the field width, depending on Dw.
  - If Dw = 0, the width field is an immediate operand; operand values in the range of 1-31 specify a field width of 1-31, and a value of zero specifies a width of 32.
  - If Dw = 1, the width field specifies a data register that contains the width. The value is modulo 32; values of 1-31 specify field widths of 1-31, and a value of zero specifies a width of 32.

---

## BFTST -- Test Bit Field

**Processors:** MC68020, MC68030, MC68040

**Operation:** \<bit field\> of Destination (tested, not modified)

**Syntax:**
```
BFTST <ea>{offset:width}
```

**Attributes:** Unsized

**Description:** Sets the condition codes according to the value in a bit field at the specified effective address location. The field offset and field width select the field. The field offset specifies the starting bit of the field. The field width determines the number of bits in the field.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | 0 | 0 |

- X -- Not affected.
- N -- Set if the most significant bit of the field is set; cleared otherwise.
- Z -- Set if all bits of the field are zero; cleared otherwise.
- V -- Always cleared.
- C -- Always cleared.

**Instruction Fields:**

- Effective Address field -- Specifies the base location for the bit field. Only data register direct or control addressing modes can be used as listed in the following table:

  | Addressing Mode | Mode | Register |
  |-----------------|------|----------|
  | Dn | 000 | reg. number:Dn |
  | (An) | 010 | reg. number:An |
  | (d16,An) | 101 | reg. number:An |
  | (d8,An,Xn) | 110 | reg. number:An |
  | (bd,An,Xn) | 110 | reg. number:An |
  | ([bd,An,Xn],od) | 110 | reg. number:An |
  | ([bd,An],Xn,od) | 110 | reg. number:An |
  | (xxx).W | 111 | 000 |
  | (xxx).L | 111 | 001 |
  | (d16,PC) | 111 | 010 |
  | (d8,PC,Xn) | 111 | 011 |
  | (bd,PC,Xn) | 111 | 011 |
  | ([bd,PC,Xn],od) | 111 | 011 |
  | ([bd,PC],Xn,od) | 111 | 011 |

- Do field -- Determines how the field offset is specified.
  - 0 -- The offset field contains the bit field offset.
  - 1 -- Bits 8-6 of the extension word specify a data register that contains the offset; bits 10-9 are zero.
- Offset field -- Specifies the field offset, depending on Do.
  - If Do = 0, the offset field is an immediate operand; the operand value is in the range of 0-31.
  - If Do = 1, the offset field specifies a data register that contains the offset. The value is in the range of -2^31 to 2^31 - 1.
- Dw field -- Determines how the field width is specified.
  - 0 -- The width field contains the bit field width.
  - 1 -- Bits 2-0 of the extension word specify a data register that contains the width; bits 4-3 are zero.
- Width field -- Specifies the field width, depending on Dw.
  - If Dw = 0, the width field is an immediate operand; operand values in the range of 1-31 specify a field width of 1-31, and a value of zero specifies a width of 32.
  - If Dw = 1, the width field specifies a data register that contains the width. The value is modulo 32; values of 1-31 specify field widths of 1-31, and a value of zero specifies a width of 32.
