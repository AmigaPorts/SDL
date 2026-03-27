<!-- Converted from Motorola M68000 Family Programmer's Reference Manual (1992) -->
# Section 4: Integer Instructions (B-E)

Instructions BKPT through EOR.

---

## BKPT -- Breakpoint

**Processors:** MC68EC000, MC68010, MC68020, MC68030, MC68040, CPU32

**Operation:** Run Breakpoint Acknowledge Cycle; TRAP As Illegal Instruction

**Syntax:**
```
BKPT #<data>
```

**Attributes:** Unsized

**Description:**

For the MC68010, a breakpoint acknowledge bus cycle is run with function codes driven high and zeros on all address lines. Whether the breakpoint acknowledge bus cycle is terminated with DTACK, BERR, or VPA, the processor always takes an illegal instruction exception. During exception processing, a debug monitor can distinguish different software breakpoints by decoding the field in the BKPT instruction. For the MC68000 and MC68008, the breakpoint cycle is not run, but an illegal instruction exception is taken.

For the MC68020, MC68030, and CPU32, a breakpoint acknowledge bus cycle is executed with the immediate data (value 0-7) on bits 2-4 of the address bus and zeros on bits 0 and 1 of the address bus. The breakpoint acknowledge bus cycle accesses the CPU space, addressing type 0, and provides the breakpoint number specified by the instruction on address lines A2-A4. If the external hardware terminates the cycle with DSACKx or STERM, the data on the bus (an instruction word) is inserted into the instruction pipe and is executed after the breakpoint instruction. The breakpoint instruction requires a word to be transferred so, if the first bus cycle accesses an 8-bit port, a second bus cycle is required. If the external logic terminates the breakpoint acknowledge bus cycle with BERR (i.e., no instruction word available), the processor takes an illegal instruction exception.

For the MC68040, this instruction executes a breakpoint acknowledge bus cycle. Regardless of the cycle termination, the MC68040 takes an illegal instruction exception.

For more information on the breakpoint instruction refer to the appropriate user's manual on bus operation. This instruction supports breakpoints for debug monitors and real-time hardware emulators.

**Condition Codes:**

Not affected.

**Instruction Fields:**

- **Vector field** -- Contains the immediate data, a value in the range of 0-7. This is the breakpoint number.

---

## BRA -- Branch Always

**Processors:** M68000 Family

**Operation:** PC + dn -> PC

**Syntax:**
```
BRA <label>
```

**Attributes:** Size = (Byte, Word, Long*)

*Long form is MC68020, MC68030, MC68040 only.

**Description:**

Program execution continues at location (PC) + displacement. The program counter contains the address of the instruction word of the BRA instruction plus two. The displacement is a twos complement integer that represents the relative distance in bytes from the current program counter to the destination program counter. If the 8-bit displacement field in the instruction word is zero, a 16-bit displacement (the word immediately following the instruction) is used. If the 8-bit displacement field in the instruction word is all ones ($FF), the 32-bit displacement (long word immediately following the instruction) is used.

**Condition Codes:**

Not affected.

**Instruction Fields:**

- **8-Bit Displacement field** -- Twos complement integer specifying the number of bytes between the branch instruction and the next instruction to be executed.
- **16-Bit Displacement field** -- Used for a larger displacement when the 8-bit displacement is equal to $00.
- **32-Bit Displacement field** -- Used for a larger displacement when the 8-bit displacement is equal to $FF.

> **Note:** A branch to the immediately following instruction automatically uses the 16-bit displacement format because the 8-bit displacement field contains $00 (zero offset).

---

## BSET -- Test a Bit and Set

**Processors:** M68000 Family

**Operation:** TEST (<bit number> of Destination) -> Z; 1 -> <bit number> of Destination

**Syntax:**
```
BSET Dn,<ea>
BSET #<data>,<ea>
```

**Attributes:** Size = (Byte, Long)

**Description:**

Tests a bit in the destination operand and sets the Z condition code appropriately, then sets the specified bit in the destination operand. When a data register is the destination, any of the 32 bits can be specified by a modulo 32-bit number. When a memory location is the destination, the operation is a byte operation, and the bit number is modulo 8. In all cases, bit zero refers to the least significant bit. The bit number for this operation can be specified in either of two ways:

1. **Immediate** -- The bit number is specified in the second word of the instruction.
2. **Register** -- The specified data register contains the bit number.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | -- | * | -- | -- |

- X -- Not affected.
- N -- Not affected.
- Z -- Set if the bit tested is zero; cleared otherwise.
- V -- Not affected.
- C -- Not affected.

**Instruction Fields:**

*Register form:*
- **Register field** -- Specifies the data register that contains the bit number.
- **Effective Address field** -- Specifies the destination location. Only data alterable addressing modes can be used. Long only for Dn; all others are byte only.

*Immediate form:*
- **Effective Address field** -- Specifies the destination location. Only data alterable addressing modes can be used. Long only for Dn; all others are byte only.
- **Bit Number field** -- Specifies the bit number.

---

## BSR -- Branch to Subroutine

**Processors:** M68000 Family

**Operation:** SP - 4 -> SP; PC -> (SP); PC + dn -> PC

**Syntax:**
```
BSR <label>
```

**Attributes:** Size = (Byte, Word, Long*)

*Long form is MC68020, MC68030, MC68040 only.

**Description:**

Pushes the long-word address of the instruction immediately following the BSR instruction onto the system stack. The program counter contains the address of the instruction word plus two. Program execution then continues at location (PC) + displacement. The displacement is a twos complement integer that represents the relative distance in bytes from the current program counter to the destination program counter. If the 8-bit displacement field in the instruction word is zero, a 16-bit displacement (the word immediately following the instruction) is used. If the 8-bit displacement field in the instruction word is all ones ($FF), the 32-bit displacement (long word immediately following the instruction) is used.

**Condition Codes:**

Not affected.

**Instruction Fields:**

- **8-Bit Displacement field** -- Twos complement integer specifying the number of bytes between the branch instruction and the next instruction to be executed.
- **16-Bit Displacement field** -- Used for a larger displacement when the 8-bit displacement is equal to $00.
- **32-Bit Displacement field** -- Used for a larger displacement when the 8-bit displacement is equal to $FF.

> **Note:** A branch to the immediately following instruction automatically uses the 16-bit displacement format because the 8-bit displacement field contains $00 (zero offset).

---

## BTST -- Test a Bit

**Processors:** M68000 Family

**Operation:** TEST (<bit number> of Destination) -> Z

**Syntax:**
```
BTST Dn,<ea>
BTST #<data>,<ea>
```

**Attributes:** Size = (Byte, Long)

**Description:**

Tests a bit in the destination operand and sets the Z condition code appropriately. When a data register is the destination, any of the 32 bits can be specified by a modulo 32-bit number. When a memory location is the destination, the operation is a byte operation, and the bit number is modulo 8. In all cases, bit zero refers to the least significant bit. The bit number for this operation can be specified in either of two ways:

1. **Immediate** -- The bit number is specified in a second word of the instruction.
2. **Register** -- The specified data register contains the bit number.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | -- | * | -- | -- |

- X -- Not affected.
- N -- Not affected.
- Z -- Set if the bit tested is zero; cleared otherwise.
- V -- Not affected.
- C -- Not affected.

**Instruction Fields:**

*Register form:*
- **Register field** -- Specifies the data register that contains the bit number.
- **Effective Address field** -- Specifies the destination location. Only data addressing modes can be used. Long only for Dn; all others are byte only.

*Immediate form:*
- **Effective Address field** -- Specifies the destination location. Only data addressing modes can be used.
- **Bit Number field** -- Specifies the bit number.

---

## CALLM -- Call Module

**Processors:** MC68020

**Operation:** Save Current Module State on Stack; Load New Module State from Destination

**Syntax:**
```
CALLM #<data>,<ea>
```

**Attributes:** Unsized

**Description:**

The effective address of the instruction is the location of an external module descriptor. A module frame is created on the top of the stack, and the current module state is saved in the frame. The immediate operand specifies the number of bytes of arguments to be passed to the called module. A new module state is loaded from the descriptor addressed by the effective address.

**Condition Codes:**

Not affected.

**Instruction Fields:**

- **Effective Address field** -- Specifies the address of the module descriptor. Only control addressing modes can be used: (An), (d16,An), (d8,An,Xn), (bd,An,Xn), ([bd,An,Xn],od), ([bd,An],Xn,od), (xxx).W, (xxx).L, (d16,PC), (d8,PC,Xn), (bd,PC,Xn), ([bd,PC,Xn],od), ([bd,PC],Xn,od).
- **Argument Count field** -- Specifies the number of bytes of arguments to be passed to the called module. The 8-bit field can specify from 0 to 255 bytes of arguments. The same number of bytes is removed from the stack by the RTM instruction.

---

## CAS/CAS2 -- Compare and Swap with Operand

**Processors:** MC68020, MC68030, MC68040

**Operation:**

CAS: Destination - Compare Operand -> cc; if Z, Update Operand -> Destination; else Destination -> Compare Operand

CAS2: Destination 1 - Compare 1 -> cc; if Z, Destination 2 - Compare 2 -> cc; if Z, Update 1 -> Destination 1, Update 2 -> Destination 2; else Destination 1 -> Compare 1, Destination 2 -> Compare 2

**Syntax:**
```
CAS Dc,Du,<ea>
CAS2 Dc1:Dc2,Du1:Du2,(Rn1):(Rn2)
```

**Attributes:** Size = (Byte*, Word, Long)

*CAS2 cannot use byte operands.

**Description:**

CAS compares the effective address operand to the compare operand (Dc). If the operands are equal, the instruction writes the update operand (Du) to the effective address operand; otherwise, the instruction writes the effective address operand to the compare operand (Dc).

CAS2 compares memory operand 1 (Rn1) to compare operand 1 (Dc1). If the operands are equal, the instruction compares memory operand 2 (Rn2) to compare operand 2 (Dc2). If these operands are also equal, the instruction writes the update operands (Du1 and Du2) to the memory operands (Rn1 and Rn2). If either comparison fails, the instruction writes the memory operands (Rn1 and Rn2) to the compare operands (Dc1 and Dc2).

Both operations access memory using locked or read-modify-write transfer sequences, providing a means of synchronizing several processors.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | * | * |

- X -- Not affected.
- N -- Set if the result is negative; cleared otherwise.
- Z -- Set if the result is zero; cleared otherwise.
- V -- Set if an overflow is generated; cleared otherwise.
- C -- Set if a borrow is generated; cleared otherwise.

**Instruction Fields:**

*CAS form:*
- **Size field** -- Specifies the size of the operation: 01 = Byte, 10 = Word, 11 = Long.
- **Effective Address field** -- Specifies the location of the memory operand. Only memory alterable addressing modes can be used.
- **Du field** -- Specifies the data register that contains the update value to be written to the memory operand location if the comparison is successful.
- **Dc field** -- Specifies the data register that contains the value to be compared to the memory operand.

*CAS2 form:*
- **Size field** -- Specifies the size of the operation: 10 = Word, 11 = Long.
- **D/A1, D/A2 fields** -- Specify whether Rn1 and Rn2 reference data or address registers, respectively. 0 = data register, 1 = address register.
- **Rn1, Rn2 fields** -- Specify the numbers of the registers that contain the addresses of the first and second memory operands, respectively. If the operands overlap in memory, the results of any memory update are undefined.
- **Du1, Du2 fields** -- Specify the data registers that contain the update values to be written to the first and second memory operand locations if the comparison is successful.
- **Dc1, Dc2 fields** -- Specify the data registers that contain the test values to be compared to the first and second memory operands, respectively. If Dc1 and Dc2 specify the same data register and the comparison fails, memory operand 1 is stored in the data register.

> **Note:** The CAS and CAS2 instructions can be used to perform secure update operations on system control data structures in a multiprocessing environment. In the MC68040, if the operands are not equal, the destination or destination 1 operand is written back to memory to complete the locked access for CAS or CAS2, respectively.

---

## CHK -- Check Register Against Bounds

**Processors:** M68000 Family

**Operation:** If Dn < 0 or Dn > Source Then TRAP

**Syntax:**
```
CHK <ea>,Dn
```

**Attributes:** Size = (Word, Long*)

*Long form is MC68020, MC68030, MC68040 only.

**Description:**

Compares the value in the data register specified in the instruction to zero and to the upper bound (effective address operand). The upper bound is a twos complement integer. If the register value is less than zero or greater than the upper bound, a CHK instruction exception (vector number 6) occurs.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | U | U | U |

- X -- Not affected.
- N -- Set if Dn < 0; cleared if Dn > effective address operand; undefined otherwise.
- Z -- Undefined.
- V -- Undefined.
- C -- Undefined.

**Instruction Fields:**

- **Register field** -- Specifies the data register that contains the value to be checked.
- **Size field** -- Specifies the size of the operation: 11 = Word, 10 = Long.
- **Effective Address field** -- Specifies the upper bound operand. Only data addressing modes can be used.

---

## CHK2 -- Check Register Against Bounds

**Processors:** MC68020, MC68030, MC68040, CPU32

**Operation:** If Rn < LB or Rn > UB Then TRAP

**Syntax:**
```
CHK2 <ea>,Rn
```

**Attributes:** Size = (Byte, Word, Long)

**Description:**

Compares the value in Rn to each bound. The effective address contains the bounds pair: the upper bound following the lower bound. For signed comparisons, the arithmetically smaller value should be used as the lower bound. For unsigned comparisons, the logically smaller value should be the lower bound.

The size of the data and the bounds can be specified as byte, word, or long. If Rn is a data register and the operation size is byte or word, only the appropriate low-order part of Rn is checked. If Rn is an address register and the operation size is byte or word, the bounds operands are sign-extended to 32 bits, and the resultant operands are compared to the full 32 bits of An.

If the upper bound equals the lower bound, the valid range is a single value. If the register value is less than the lower bound or greater than the upper bound, a CHK instruction exception (vector number 6) occurs.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | U | * | U | * |

- X -- Not affected.
- N -- Undefined.
- Z -- Set if Rn is equal to either bound; cleared otherwise.
- V -- Undefined.
- C -- Set if Rn is out of bounds; cleared otherwise.

**Instruction Fields:**

- **Size field** -- Specifies the size of the operation: 00 = Byte, 01 = Word, 10 = Long.
- **Effective Address field** -- Specifies the location of the bounds operands. Only control addressing modes can be used.
- **D/A field** -- Specifies whether an address register or data register is to be checked. 0 = data register, 1 = address register.
- **Register field** -- Specifies the address or data register that contains the value to be checked.

---

## CLR -- Clear an Operand

**Processors:** M68000 Family

**Operation:** 0 -> Destination

**Syntax:**
```
CLR <ea>
```

**Attributes:** Size = (Byte, Word, Long)

**Description:**

Clears the destination operand to zero. The size of the operation may be specified as byte, word, or long.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | 0 | 1 | 0 | 0 |

- X -- Not affected.
- N -- Always cleared.
- Z -- Always set.
- V -- Always cleared.
- C -- Always cleared.

**Instruction Fields:**

- **Size field** -- Specifies the size of the operation: 00 = Byte, 01 = Word, 10 = Long.
- **Effective Address field** -- Specifies the destination location. Only data alterable addressing modes can be used.

> **Note:** In the MC68000 and MC68008 a memory location is read before it is cleared.

---

## CMP -- Compare

**Processors:** M68000 Family

**Operation:** Destination - Source -> cc

**Syntax:**
```
CMP <ea>,Dn
```

**Attributes:** Size = (Byte, Word, Long)

**Description:**

Subtracts the source operand from the destination data register and sets the condition codes according to the result; the data register is not changed. The size of the operation can be byte, word, or long.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | * | * |

- X -- Not affected.
- N -- Set if the result is negative; cleared otherwise.
- Z -- Set if the result is zero; cleared otherwise.
- V -- Set if an overflow occurs; cleared otherwise.
- C -- Set if a borrow occurs; cleared otherwise.

**Instruction Fields:**

- **Register field** -- Specifies the destination data register.
- **Opmode field** -- 000 = Byte (Dn - <ea>), 001 = Word (Dn - <ea>), 010 = Long (Dn - <ea>).
- **Effective Address field** -- Specifies the source operand. All addressing modes can be used. Address register direct (An) is word and long only.

> **Note:** CMPA is used when the destination is an address register. CMPI is used when the source is immediate data. CMPM is used for memory-to-memory compares. Most assemblers automatically make the distinction.

---

## CMPA -- Compare Address

**Processors:** M68000 Family

**Operation:** Destination - Source -> cc

**Syntax:**
```
CMPA <ea>,An
```

**Attributes:** Size = (Word, Long)

**Description:**

Subtracts the source operand from the destination address register and sets the condition codes according to the result; the address register is not changed. The size of the operation can be specified as word or long. Word length source operands are sign-extended to 32 bits for comparison.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | * | * |

- X -- Not affected.
- N -- Set if the result is negative; cleared otherwise.
- Z -- Set if the result is zero; cleared otherwise.
- V -- Set if an overflow is generated; cleared otherwise.
- C -- Set if a borrow is generated; cleared otherwise.

**Instruction Fields:**

- **Register field** -- Specifies the destination address register.
- **Opmode field** -- 011 = Word operation (source operand is sign-extended to a long operand, and the operation is performed on the address register using all 32 bits), 111 = Long operation.
- **Effective Address field** -- Specifies the source operand. All addressing modes can be used.

---

## CMPI -- Compare Immediate

**Processors:** M68000 Family

**Operation:** Destination - Immediate Data -> cc

**Syntax:**
```
CMPI #<data>,<ea>
```

**Attributes:** Size = (Byte, Word, Long)

**Description:**

Subtracts the immediate data from the destination operand and sets the condition codes according to the result; the destination location is not changed. The size of the operation may be specified as byte, word, or long. The size of the immediate data matches the operation size.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | * | * |

- X -- Not affected.
- N -- Set if the result is negative; cleared otherwise.
- Z -- Set if the result is zero; cleared otherwise.
- V -- Set if an overflow occurs; cleared otherwise.
- C -- Set if a borrow occurs; cleared otherwise.

**Instruction Fields:**

- **Size field** -- Specifies the size of the operation: 00 = Byte, 01 = Word, 10 = Long.
- **Effective Address field** -- Specifies the destination operand. Only data addressing modes can be used. PC relative addressing modes are available on MC68020, MC68030, MC68040 only.
- **Immediate field** -- Data immediately following the instruction. If size = 00, the data is the low-order byte of the immediate word. If size = 01, the data is the entire immediate word. If size = 10, the data is the next two immediate words.

---

## CMPM -- Compare Memory

**Processors:** M68000 Family

**Operation:** Destination - Source -> cc

**Syntax:**
```
CMPM (Ay)+,(Ax)+
```

**Attributes:** Size = (Byte, Word, Long)

**Description:**

Subtracts the source operand from the destination operand and sets the condition codes according to the results; the destination location is not changed. The operands are always addressed with the postincrement addressing mode, using the address registers specified in the instruction. The size of the operation may be specified as byte, word, or long.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | * | * |

- X -- Not affected.
- N -- Set if the result is negative; cleared otherwise.
- Z -- Set if the result is zero; cleared otherwise.
- V -- Set if an overflow is generated; cleared otherwise.
- C -- Set if a borrow is generated; cleared otherwise.

**Instruction Fields:**

- **Register Ax field** -- (always the destination) Specifies an address register in the postincrement addressing mode.
- **Size field** -- Specifies the size of the operation: 00 = Byte, 01 = Word, 10 = Long.
- **Register Ay field** -- (always the source) Specifies an address register in the postincrement addressing mode.

---

## CMP2 -- Compare Register Against Bounds

**Processors:** MC68020, MC68030, MC68040, CPU32

**Operation:** Compare Rn < LB or Rn > UB and Set Condition Codes

**Syntax:**
```
CMP2 <ea>,Rn
```

**Attributes:** Size = (Byte, Word, Long)

**Description:**

Compares the value in Rn to each bound. The effective address contains the bounds pair: upper bound following the lower bound. For signed comparisons, the arithmetically smaller value should be used as the lower bound. For unsigned comparisons, the logically smaller value should be the lower bound.

The size of the data and the bounds can be specified as byte, word, or long. If Rn is a data register and the operation size is byte or word, only the appropriate low-order part of Rn is checked. If Rn is an address register and the operation size is byte or word, the bounds operands are sign-extended to 32 bits, and the resultant operands are compared to the full 32 bits of An.

If the upper bound equals the lower bound, the valid range is a single value.

> **Note:** This instruction is identical to CHK2 except that it sets condition codes rather than taking an exception when the value in Rn is out of bounds.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | U | * | U | * |

- X -- Not affected.
- N -- Undefined.
- Z -- Set if Rn is equal to either bound; cleared otherwise.
- V -- Undefined.
- C -- Set if Rn is out of bounds; cleared otherwise.

**Instruction Fields:**

- **Size field** -- Specifies the size of the operation: 00 = Byte, 01 = Word, 10 = Long.
- **Effective Address field** -- Specifies the location of the bounds pair. Only control addressing modes can be used.
- **D/A field** -- Specifies whether an address register or data register is compared. 0 = data register, 1 = address register.
- **Register field** -- Specifies the address or data register that contains the value to be checked.

---

## cpBcc -- Branch on Coprocessor Condition

**Processors:** MC68020, MC68030

**Operation:** If cpcc True Then Scan PC + dn -> PC

**Syntax:**
```
cpBcc <label>
```

**Attributes:** Size = (Word, Long)

**Description:**

If the specified coprocessor condition is true, program execution continues at location scan PC + displacement. The value of the scan PC is the address of the first displacement word. The displacement is a twos complement integer that represents the relative distance in bytes from the scan PC to the destination program counter. The displacement can be either 16 or 32 bits. The coprocessor determines the specific condition from the condition field in the operation word.

**Condition Codes:**

Not affected.

**Instruction Fields:**

- **Coprocessor ID field** -- Identifies the coprocessor for this operation. Coprocessor ID of 000 results in an F-line exception for the MC68030.
- **Size field** -- 0 = 16-bit displacement, 1 = 32-bit displacement.
- **Coprocessor Condition field** -- Specifies the coprocessor condition to be tested. This field is passed to the coprocessor, which provides directives to the main processor for processing this instruction.

---

## cpDBcc -- Test Coprocessor Condition, Decrement and Branch

**Processors:** MC68020, MC68030

**Operation:** If cpcc False Then (Dn - 1 -> Dn; If Dn != -1 Then Scan PC + dn -> PC)

**Syntax:**
```
cpDBcc Dn,<label>
```

**Attributes:** Size = (Word)

**Description:**

If the specified coprocessor condition is true, execution continues with the next instruction. Otherwise, the low-order word in the specified data register is decremented by one. If the result is equal to -1, execution continues with the next instruction. If the result is not equal to -1, execution continues at the location indicated by the value of the scan PC plus the sign-extended 16-bit displacement. The value of the scan PC is the address of the displacement word. The displacement is a twos complement integer that represents the relative distance in bytes from the scan PC to the destination program counter. The coprocessor determines the specific condition from the condition word that follows the operation word.

**Condition Codes:**

Not affected.

**Instruction Fields:**

- **Coprocessor ID field** -- Identifies the coprocessor for this operation; coprocessor ID of 000 results in an F-line exception for the MC68030.
- **Register field** -- Specifies the data register used as the counter.
- **Coprocessor Condition field** -- Specifies the coprocessor condition to be tested. This field is passed to the coprocessor, which provides directives to the main processor for processing this instruction.
- **Displacement field** -- Specifies the distance of the branch (in bytes).

---

## cpGEN -- Coprocessor General Function

**Processors:** MC68020, MC68030

**Operation:** Pass Command Word to Coprocessor

**Syntax:**
```
cpGEN <parameters as defined by coprocessor>
```

**Attributes:** Unsized

**Description:**

Transfers the command word that follows the operation word to the specified coprocessor. The coprocessor determines the specific operation from the command word. Usually a coprocessor defines specific instances of this instruction to provide its instruction set.

**Condition Codes:**

May be modified by coprocessor; unchanged otherwise.

**Instruction Fields:**

- **Coprocessor ID field** -- Identifies the coprocessor for this operation; note that coprocessor ID of 000 is reserved for MMU instructions for the MC68030.
- **Effective Address field** -- Specifies the location of any operand not resident in the coprocessor. The allowable addressing modes are determined by the operation to be performed.
- **Coprocessor Command field** -- Specifies the coprocessor operation to be performed. This word is passed to the coprocessor, which in turn provides directives to the main processor for processing this instruction.

---

## cpScc -- Set on Coprocessor Condition

**Processors:** MC68020, MC68030

**Operation:** If cpcc True Then 1s -> Destination; Else 0s -> Destination

**Syntax:**
```
cpScc <ea>
```

**Attributes:** Size = (Byte)

**Description:**

Tests the specified coprocessor condition code. If the condition is true, the byte specified by the effective address is set to TRUE (all ones); otherwise, that byte is set to FALSE (all zeros). The coprocessor determines the specific condition from the condition word that follows the operation word.

**Condition Codes:**

Not affected.

**Instruction Fields:**

- **Coprocessor ID field** -- Identifies the coprocessor for this operation. Coprocessor ID of 000 results in an F-line exception for the MC68030.
- **Effective Address field** -- Specifies the destination location. Only data alterable addressing modes can be used.
- **Coprocessor Condition field** -- Specifies the coprocessor condition to be tested. This field is passed to the coprocessor, which in turn provides directives to the main processor for processing this instruction.

---

## cpTRAPcc -- Trap on Coprocessor Condition

**Processors:** MC68020, MC68030

**Operation:** If cpcc True Then TRAP

**Syntax:**
```
cpTRAPcc
cpTRAPcc #<data>
```

**Attributes:** Unsized or Size = (Word, Long)

**Description:**

Tests the specified coprocessor condition code; if the selected coprocessor condition is true, the processor initiates a cpTRAPcc exception, vector number 7. The program counter value placed on the stack is the address of the next instruction. If the selected condition is not true, no operation is performed, and execution continues with the next instruction. The coprocessor determines the specific condition from the condition word that follows the operation word. Following the condition word is a user-defined data operand specified as immediate data to be used by the trap handler.

**Condition Codes:**

Not affected.

**Instruction Fields:**

- **Coprocessor ID field** -- Identifies the coprocessor for this operation; coprocessor ID of 000 results in an F-line exception for the MC68030.
- **Opmode field** -- Selects the instruction form: 010 = followed by one operand word, 011 = followed by two operand words, 100 = no following operand words.
- **Coprocessor Condition field** -- Specifies the coprocessor condition to be tested. This field is passed to the coprocessor, which provides directives to the main processor for processing this instruction.

---

## DBcc -- Test Condition, Decrement, and Branch

**Processors:** M68000 Family

**Operation:** If Condition False Then (Dn - 1 -> Dn; If Dn != -1 Then PC + dn -> PC)

**Syntax:**
```
DBcc Dn,<label>
```

**Attributes:** Size = (Word)

**Description:**

Controls a loop of instructions. The parameters are a condition code, a data register (counter), and a displacement value. The instruction first tests the condition for termination; if it is true, no operation is performed. If the termination condition is not true, the low-order 16 bits of the counter data register decrement by one. If the result is -1, execution continues with the next instruction. If the result is not equal to -1, execution continues at the location indicated by the current value of the program counter plus the sign-extended 16-bit displacement. The value in the program counter is the address of the instruction word of the DBcc instruction plus two. The displacement is a twos complement integer that represents the relative distance in bytes from the current program counter to the destination program counter.

**Condition Code Variants:**

| Mnemonic | Condition | Mnemonic | Condition |
|----------|-----------|----------|-----------|
| DBCC (DBHI) | Carry Clear | DBLS | Low or Same |
| DBCS (DBLO) | Carry Set | DBLT | Less Than |
| DBEQ | Equal | DBMI | Minus |
| DBF (DBRA) | False (Never True) | DBNE | Not Equal |
| DBGE | Greater or Equal | DBPL | Plus |
| DBGT | Greater Than | DBT | True |
| DBHI | High | DBVC | Overflow Clear |
| DBLE | Less or Equal | DBVS | Overflow Set |

**Condition Codes:**

Not affected.

**Instruction Fields:**

- **Condition field** -- The binary code for one of the conditions listed in the table.
- **Register field** -- Specifies the data register used as the counter.
- **Displacement field** -- Specifies the number of bytes to branch.

> **Notes:**
> - The terminating condition is similar to the UNTIL loop clauses of high-level languages. For example: DBMI can be stated as "decrement and branch until minus".
> - Most assemblers accept DBRA for DBF for use when only a count terminates the loop (no condition is tested).
> - A program can enter a loop at the beginning or by branching to the trailing DBcc instruction. Entering the loop at the beginning is useful for indexed addressing modes and dynamically specified bit operations. In this case, the control index count must be one less than the desired number of loop executions. However, when entering a loop by branching directly to the trailing DBcc instruction, the control count should equal the loop execution count. In this case, if a zero count occurs, the DBcc instruction does not branch, and the main loop is not executed.

---

## DIVS/DIVSL -- Signed Divide

**Processors:** M68000 Family (long forms: MC68020, MC68030, MC68040, CPU32 only)

**Operation:** Destination / Source -> Destination

**Syntax:**
```
DIVS.W <ea>,Dn                    32/16 -> 16r:16q
DIVS.L <ea>,Dq                    32/32 -> 32q         *
DIVS.L <ea>,Dr:Dq                 64/32 -> 32r:32q     *
DIVSL.L <ea>,Dr:Dq                32/32 -> 32r:32q     *
```

*MC68020, MC68030, MC68040, CPU32 only.

**Attributes:** Size = (Word, Long)

**Description:**

Divides the signed destination operand by the signed source operand and stores the signed result in the destination. The instruction uses one of four forms:

- **Word form:** Divides a long word by a word. The result is a quotient in the lower word (least significant 16 bits) and a remainder in the upper word (most significant 16 bits). The sign of the remainder is the same as the sign of the dividend.
- **First long form (DIVS.L <ea>,Dq):** Divides a long word by a long word. The result is a long quotient; the remainder is discarded.
- **Second long form (DIVS.L <ea>,Dr:Dq):** Divides a quad word (in any two data registers) by a long word. The result is a long-word quotient and a long-word remainder.
- **Third long form (DIVSL.L <ea>,Dr:Dq):** Divides a long word by a long word. The result is a long-word quotient and a long-word remainder.

Two special conditions may arise during the operation:

1. Division by zero causes a trap.
2. Overflow may be detected and set before the instruction completes. If the instruction detects an overflow, it sets the overflow condition code, and the operands are unaffected.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | * | 0 |

- X -- Not affected.
- N -- Set if the quotient is negative; cleared otherwise; undefined if overflow or divide by zero occurs.
- Z -- Set if the quotient is zero; cleared otherwise; undefined if overflow or divide by zero occurs.
- V -- Set if division overflow occurs; undefined if divide by zero occurs; cleared otherwise.
- C -- Always cleared.

**Instruction Fields:**

*Word form:*
- **Register field** -- Specifies any of the eight data registers. This field always specifies the destination operand.
- **Effective Address field** -- Specifies the source operand. Only data addressing modes can be used.

*Long form:*
- **Effective Address field** -- Specifies the source operand. Only data addressing modes can be used.
- **Register Dq field** -- Specifies a data register for the destination operand. The low-order 32 bits of the dividend comes from this register, and the 32-bit quotient is loaded into this register.
- **Size field** -- Selects a 32- or 64-bit division operation: 0 = 32-bit dividend is in register Dq, 1 = 64-bit dividend is in Dr:Dq.
- **Register Dr field** -- After the division, this register contains the 32-bit remainder. If Dr and Dq are the same register, only the quotient is returned. If the size field is 1, this field also specifies the data register that contains the high-order 32 bits of the dividend.

> **Note:** Overflow occurs if the quotient is larger than a 16-bit signed integer (word form) or a 32-bit signed integer (long form).

---

## DIVU/DIVUL -- Unsigned Divide

**Processors:** M68000 Family (long forms: MC68020, MC68030, MC68040, CPU32 only)

**Operation:** Destination / Source -> Destination

**Syntax:**
```
DIVU.W <ea>,Dn                    32/16 -> 16r:16q
DIVU.L <ea>,Dq                    32/32 -> 32q         *
DIVU.L <ea>,Dr:Dq                 64/32 -> 32r:32q     *
DIVUL.L <ea>,Dr:Dq                32/32 -> 32r:32q     *
```

*MC68020, MC68030, MC68040, CPU32 only.

**Attributes:** Size = (Word, Long)

**Description:**

Divides the unsigned destination operand by the unsigned source operand and stores the unsigned result in the destination. The instruction uses one of four forms:

- **Word form:** Divides a long word by a word. The result is a quotient in the lower word (least significant 16 bits) and a remainder in the upper word (most significant 16 bits).
- **First long form (DIVU.L <ea>,Dq):** Divides a long word by a long word. The result is a long quotient; the remainder is discarded.
- **Second long form (DIVU.L <ea>,Dr:Dq):** Divides a quad word (in any two data registers) by a long word. The result is a long-word quotient and a long-word remainder.
- **Third long form (DIVUL.L <ea>,Dr:Dq):** Divides a long word by a long word. The result is a long-word quotient and a long-word remainder.

Two special conditions may arise during the operation:

1. Division by zero causes a trap.
2. Overflow may be detected and set before the instruction completes. If the instruction detects an overflow, it sets the overflow condition code, and the operands are unaffected.

**Condition Codes:**

| X | N | Z | V | C |
|---|---|---|---|---|
| -- | * | * | * | 0 |

- X -- Not affected.
- N -- Set if the quotient is negative; cleared otherwise; undefined if overflow or divide by zero occurs.
- Z -- Set if the quotient is zero; cleared otherwise; undefined if overflow or divide by zero occurs.
- V -- Set if division overflow occurs; cleared otherwise; undefined if divide by zero occurs.
- C -- Always cleared.

**Instruction Fields:**

*Word form:*
- **Register field** -- Specifies any of the eight data registers; this field always specifies the destination operand.
- **Effective Address field** -- Specifies the source operand. Only data addressing modes can be used.

*Long form:*
- **Effective Address field** -- Specifies the source operand. Only data addressing modes can be used.
- **Register Dq field** -- Specifies a data register for the destination operand. The low-order 32 bits of the dividend comes from this register, and the 32-bit quotient is loaded into this register.
- **Size field** -- Selects a 32- or 64-bit division operation: 0 = 32-bit dividend is in register Dq, 1 = 64-bit dividend is in Dr:Dq.
- **Register Dr field** -- After the division, this register contains the 32-bit remainder. If Dr and Dq are the same register, only the quotient is returned. If the size field is 1, this field also specifies the data register that contains the high-order 32 bits of the dividend.

> **Note:** Overflow occurs if the quotient is larger than a 16-bit unsigned integer (word form) or a 32-bit unsigned integer (long form).

---

## EOR -- Exclusive-OR Logical

**Processors:** M68000 Family

**Operation:** Source XOR Destination -> Destination

**Syntax:**
```
EOR Dn,<ea>
```

**Attributes:** Size = (Byte, Word, Long)

**Description:**

Performs an exclusive-OR operation on the destination operand using the source operand and stores the result in the destination location. The size of the operation may be specified to be byte, word, or long. The source operand must be a data register. The destination operand is specified in the effective address field.

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

- **Register field** -- Specifies any of the eight data registers.
- **Opmode field** -- 100 = Byte (<ea> XOR Dn -> <ea>), 101 = Word (<ea> XOR Dn -> <ea>), 110 = Long (<ea> XOR Dn -> <ea>).
- **Effective Address field** -- Specifies the destination operand. Only data alterable addressing modes can be used.

> **Note:** Memory-to-data-register operations are not allowed. Most assemblers use EORI when the source is immediate data.
