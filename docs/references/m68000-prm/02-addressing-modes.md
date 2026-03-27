# Section 2: Addressing Modes

All M68000 family addressing modes with effective address encoding.

Source: Motorola M68000 Family Programmer's Reference Manual, Section 2.

---

Most operations take a source operand and destination operand, compute them, and store the result in the destination location. Single-operand operations take a destination operand, compute it, and store the result in the destination location. External microprocessor references to memory are either program references that refer to program space or data references that refer to data space. They access either instruction words or operands (data items) for an instruction. Program space is the section of memory that contains the program instructions and any immediate data operands residing in the instruction stream. Data space is the section of memory that contains the program data. Data items in the instruction stream can be accessed with the program counter relative addressing modes; these accesses classify as program references.

## 2.1 Instruction Format

M68000 family instructions consist of at least one word; some have as many as 11 words. The first word of the instruction, called the simple effective address operation word, specifies the length of the instruction, the effective addressing mode, and the operation to be performed. The remaining words, called brief and full extension words, further specify the instruction and operands. These words can be floating-point command words, conditional predicates, immediate operands, extensions to the effective addressing mode specified in the simple effective address operation word, branch displacements, bit number or bit field specifications, special register specifications, trap operands, pack/unpack constants, or argument counts.

### Instruction Word General Format

```
 15                                                    0
+-------------------------------------------------------+
| SINGLE EFFECTIVE ADDRESS OPERATION WORD                |
| (ONE WORD, SPECIFIES OPERATION AND MODES)              |
+-------------------------------------------------------+
| SPECIAL OPERAND SPECIFIERS                             |
| (IF ANY, ONE OR TWO WORDS)                             |
+-------------------------------------------------------+
| IMMEDIATE OPERAND OR SOURCE EFFECTIVE ADDRESS EXTENSION|
| (IF ANY, ONE TO SIX WORDS)                             |
+-------------------------------------------------------+
| DESTINATION EFFECTIVE ADDRESS EXTENSION                |
| (IF ANY, ONE TO SIX WORDS)                             |
+-------------------------------------------------------+
```

An instruction specifies the function to be performed with an operation code and defines the location of every operand. Instructions specify an operand location by register specification (the instruction's register field holds the register's number), by effective address (the instruction's effective address field contains addressing mode information), or by implicit reference (the definition of the instruction implies the use of specific registers).

### Single Effective Address Operation Word Format

```
 15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| X   X   X   X   X   X   X   X   X   X | MODE  | REGISTER      |
|          OPERATION WORD                 |       |               |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
                                          |<-5:3->|<----2:0----->|
```

The encoding of the mode field selects the addressing mode. The register field contains the general register number or a value that selects the addressing mode when the mode field contains opcode 111. Some indexed or indirect addressing modes use a combination of the simple effective address operation word followed by a brief extension word. Other indexed or indirect addressing modes consist of the simple effective address operation word and a full extension word.

### Brief Extension Word Format

```
 15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
|D/A| REGISTER  |W/L| SCALE | 0 |        DISPLACEMENT           |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
```

### Full Extension Word Format

```
 15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
|D/A| REGISTER  |W/L| SCALE | 1 | BS| IS|BD SIZE|  0  |  I/IS   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| BASE DISPLACEMENT (0, 1, OR 2 WORDS)                           |
+---------------------------------------------------------------+
| OUTER DISPLACEMENT (0, 1, OR 2 WORDS)                          |
+---------------------------------------------------------------+
```

### Extension Word Field Definitions

| Field | Definition |
|-------|-----------|
| Mode | Addressing Mode |
| Register | General Register Number |
| D/A | Index Register Type: 0 = Dn, 1 = An |
| W/L | Word/Long-Word Index Size: 0 = Sign-Extended Word, 1 = Long Word |
| Scale | Scale Factor: 00 = 1, 01 = 2, 10 = 4, 11 = 8 |
| BS | Base Register Suppress: 0 = Base Register Added, 1 = Base Register Suppressed |
| IS | Index Suppress: 0 = Evaluate and Add Index Operand, 1 = Suppress Index Operand |
| BD SIZE | Base Displacement Size: 00 = Reserved, 01 = Null, 10 = Word, 11 = Long |
| I/IS | Index/Indirect Selection: determined in conjunction with IS bit (see table below) |

### IS-I/IS Memory Indirect Action Encodings

For effective addresses that use a full extension word format, the index suppress (IS) bit and the index/indirect selection (I/IS) field determine the type of indexing and indirect action.

| IS | I/IS | Operation |
|----|------|-----------|
| 0 | 000 | No Memory Indirect Action |
| 0 | 001 | Indirect Preindexed with Null Outer Displacement |
| 0 | 010 | Indirect Preindexed with Word Outer Displacement |
| 0 | 011 | Indirect Preindexed with Long Outer Displacement |
| 0 | 100 | Reserved |
| 0 | 101 | Indirect Postindexed with Null Outer Displacement |
| 0 | 110 | Indirect Postindexed with Word Outer Displacement |
| 0 | 111 | Indirect Postindexed with Long Outer Displacement |
| 1 | 000 | No Memory Indirect Action |
| 1 | 001 | Memory Indirect with Null Outer Displacement |
| 1 | 010 | Memory Indirect with Word Outer Displacement |
| 1 | 011 | Memory Indirect with Long Outer Displacement |
| 1 | 100-111 | Reserved |

## 2.2 Effective Addressing Modes

Besides the operation code, which specifies the function to be performed, an instruction defines the location of every operand for the function. Instructions specify an operand location in one of three ways: a register field within an instruction can specify the register to be used; an instruction's effective address field can contain addressing mode information; or the instruction's definition can imply the use of a specific register.

An instruction's addressing mode specifies the value of an operand, a register that contains the operand, or how to derive the effective address of an operand in memory. Each addressing mode has an assembler syntax. Some instructions imply the addressing mode for an operand.

### 2.2.1 Data Register Direct

The effective address field specifies the data register containing the operand.

```
EA = Dn
```

| Property | Value |
|----------|-------|
| Assembler Syntax | `Dn` |
| EA Mode Field | 000 |
| EA Register Field | Register number |
| Extension Words | 0 |

### 2.2.2 Address Register Direct

The effective address field specifies the address register containing the operand.

```
EA = An
```

| Property | Value |
|----------|-------|
| Assembler Syntax | `An` |
| EA Mode Field | 001 |
| EA Register Field | Register number |
| Extension Words | 0 |

### 2.2.3 Address Register Indirect

The operand is in memory. The effective address field specifies the address register containing the address of the operand in memory.

```
EA = (An)
```

| Property | Value |
|----------|-------|
| Assembler Syntax | `(An)` |
| EA Mode Field | 010 |
| EA Register Field | Register number |
| Extension Words | 0 |

### 2.2.4 Address Register Indirect with Postincrement

The operand is in memory. The effective address field specifies the address register containing the address of the operand in memory. After the operand address is used, it is incremented by one, two, or four depending on the size of the operand: byte, word, or long word, respectively. Coprocessors may support incrementing for any operand size, up to 255 bytes. If the address register is the stack pointer and the operand size is byte, the address is incremented by two to keep the stack pointer aligned to a word boundary.

```
EA = (An), then An = An + SIZE
```

| Property | Value |
|----------|-------|
| Assembler Syntax | `(An)+` |
| EA Mode Field | 011 |
| EA Register Field | Register number |
| Extension Words | 0 |

SIZE is 1 for byte, 2 for word, 4 for long word.

### 2.2.5 Address Register Indirect with Predecrement

The operand is in memory. The effective address field specifies the address register containing the address of the operand in memory. Before the operand address is used, it is decremented by one, two, or four depending on the operand size: byte, word, or long word, respectively. Coprocessors may support decrementing for any operand size up to 255 bytes. If the address register is the stack pointer and the operand size is byte, the address is decremented by two to keep the stack pointer aligned to a word boundary.

```
An = An - SIZE, then EA = (An)
```

| Property | Value |
|----------|-------|
| Assembler Syntax | `-(An)` |
| EA Mode Field | 100 |
| EA Register Field | Register number |
| Extension Words | 0 |

### 2.2.6 Address Register Indirect with Displacement

The operand is in memory. The sum of the address in the address register, which the effective address specifies, plus the sign-extended 16-bit displacement integer in the extension word is the operand's address in memory. Displacements are always sign-extended to 32 bits prior to being used in effective address calculations.

```
EA = (An) + sign_extend(d16)
```

| Property | Value |
|----------|-------|
| Assembler Syntax | `(d16,An)` |
| EA Mode Field | 101 |
| EA Register Field | Register number |
| Extension Words | 1 |

### 2.2.7 Address Register Indirect with Index (8-Bit Displacement)

This addressing mode requires one extension word that contains an index register indicator and an 8-bit displacement. The index register indicator includes size and scale information. The operand is in memory. The operand's address is the sum of the address register's contents; the sign-extended displacement value in the extension word's low-order eight bits; and the index register's sign-extended contents (possibly scaled). The user must specify the address register, the displacement, and the index register in this mode.

```
EA = (An) + sign_extend(d8) + (Xn.SIZE * SCALE)
```

| Property | Value |
|----------|-------|
| Assembler Syntax | `(d8,An,Xn.SIZE*SCALE)` |
| EA Mode Field | 110 |
| EA Register Field | Register number |
| Extension Words | 1 |

### 2.2.8 Address Register Indirect with Index (Base Displacement)

This addressing mode requires an index register indicator and an optional 16- or 32-bit sign-extended base displacement. The index register indicator includes size and scaling information. The operand is in memory. The operand's address is the sum of the contents of the address register, the base displacement, and the scaled contents of the sign-extended index register.

In this mode, the address register, the index register, and the displacement are all optional. The effective address is zero if there is no specification. This mode provides a data register indirect address when there is no specific address register and the index register is a data register.

```
EA = (An) + sign_extend(bd) + (Xn.SIZE * SCALE)
```

| Property | Value |
|----------|-------|
| Assembler Syntax | `(bd,An,Xn.SIZE*SCALE)` |
| EA Mode Field | 110 |
| EA Register Field | Register number |
| Extension Words | 1, 2, or 3 |

### 2.2.9 Memory Indirect Postindexed

Both the operand and its address are in memory. The processor calculates an intermediate indirect memory address using a base address register and base displacement. The processor accesses a long word at this address and adds the index operand (Xn.SIZE\*SCALE) and the outer displacement to yield the effective address. Both displacements and the index register contents are sign-extended to 32 bits.

In the syntax for this mode, brackets enclose the values used to calculate the intermediate memory address. All four user-specified values are optional. Both the base and outer displacements may be null, word, or long word. When omitting a displacement or suppressing an element, its value is zero in the effective address calculation.

```
Intermediate = (An) + sign_extend(bd)
EA = [Intermediate] + (Xn.SIZE * SCALE) + sign_extend(od)
```

Where `[Intermediate]` denotes reading the long word at the intermediate address from memory.

| Property | Value |
|----------|-------|
| Assembler Syntax | `([bd,An],Xn.SIZE*SCALE,od)` |
| EA Mode Field | 110 |
| EA Register Field | Register number |
| Extension Words | 1, 2, 3, 4, or 5 |

### 2.2.10 Memory Indirect Preindexed

Both the operand and its address are in memory. The processor calculates an intermediate indirect memory address using a base address register, a base displacement, and the index operand (Xn.SIZE\*SCALE). The processor accesses a long word at this address and adds the outer displacement to yield the effective address. Both displacements and the index register contents are sign-extended to 32 bits.

In the syntax for this mode, brackets enclose the values used to calculate the intermediate memory address. All four user-specified values are optional. Both the base and outer displacements may be null, word, or long word. When omitting a displacement or suppressing an element, its value is zero in the effective address calculation.

```
Intermediate = (An) + sign_extend(bd) + (Xn.SIZE * SCALE)
EA = [Intermediate] + sign_extend(od)
```

Where `[Intermediate]` denotes reading the long word at the intermediate address from memory.

| Property | Value |
|----------|-------|
| Assembler Syntax | `([bd,An,Xn.SIZE*SCALE],od)` |
| EA Mode Field | 110 |
| EA Register Field | Register number |
| Extension Words | 1, 2, 3, 4, or 5 |

### 2.2.11 Program Counter Indirect with Displacement

The operand is in memory. The address of the operand is the sum of the address in the program counter (PC) and the sign-extended 16-bit displacement integer in the extension word. The value in the PC is the address of the extension word. This is a program reference allowed only for reads.

```
EA = (PC) + sign_extend(d16)
```

| Property | Value |
|----------|-------|
| Assembler Syntax | `(d16,PC)` |
| EA Mode Field | 111 |
| EA Register Field | 010 |
| Extension Words | 1 |

### 2.2.12 Program Counter Indirect with Index (8-Bit Displacement)

Similar to Address Register Indirect with Index (8-Bit Displacement) (2.2.7), except the PC is the base register. The operand is in memory. The operand's address is the sum of the address in the PC, the sign-extended displacement integer in the extension word's lower eight bits, and the sized, scaled, and sign-extended index operand. The value in the PC is the address of the extension word. This is a program reference allowed only for reads. The user must include the displacement, the PC, and the index register when specifying this addressing mode.

```
EA = (PC) + sign_extend(d8) + (Xn.SIZE * SCALE)
```

| Property | Value |
|----------|-------|
| Assembler Syntax | `(d8,PC,Xn.SIZE*SCALE)` |
| EA Mode Field | 111 |
| EA Register Field | 011 |
| Extension Words | 1 |

### 2.2.13 Program Counter Indirect with Index (Base Displacement)

Similar to Address Register Indirect with Index (Base Displacement) (2.2.8), except the PC is the base register. It requires an index register indicator and an optional 16- or 32-bit sign-extended base displacement. The operand is in memory. The operand's address is the sum of the contents of the PC, the base displacement, and the scaled contents of the sign-extended index register. The value of the PC is the address of the first extension word. This is a program reference allowed only for reads.

In this mode, the PC, the displacement, and the index register are optional. The user must supply the assembler notation ZPC (a zero value PC) to show that the PC is not used. This allows the user to access the program space without using the PC in calculating the effective address. The user can access the program space with a data register indirect access by placing ZPC in the instruction and specifying a data register as the index register.

```
EA = (PC) + sign_extend(bd) + (Xn.SIZE * SCALE)
```

| Property | Value |
|----------|-------|
| Assembler Syntax | `(bd,PC,Xn.SIZE*SCALE)` |
| EA Mode Field | 111 |
| EA Register Field | 011 |
| Extension Words | 1, 2, or 3 |

### 2.2.14 Program Counter Memory Indirect Postindexed

Similar to Memory Indirect Postindexed (2.2.9), but the PC is the base register. Both the operand and operand address are in memory. The processor calculates an intermediate indirect memory address by adding a base displacement to the PC contents. The processor accesses a long word at that address and adds the scaled contents of the index register and the optional outer displacement to yield the effective address. The value of the PC used in the calculation is the address of the first extension word. This is a program reference allowed only for reads.

In the syntax for this mode, brackets enclose the values used to calculate the intermediate memory address. All four user-specified values are optional. The user must supply the assembler notation ZPC (a zero value PC) to show the PC is not used. Both the base and outer displacements may be null, word, or long word. When omitting a displacement or suppressing an element, its value is zero in the effective address calculation.

```
Intermediate = (PC) + sign_extend(bd)
EA = [Intermediate] + (Xn.SIZE * SCALE) + sign_extend(od)
```

| Property | Value |
|----------|-------|
| Assembler Syntax | `([bd,PC],Xn.SIZE*SCALE,od)` |
| EA Mode Field | 111 |
| EA Register Field | 011 |
| Extension Words | 1, 2, 3, 4, or 5 |

### 2.2.15 Program Counter Memory Indirect Preindexed

Similar to Memory Indirect Preindexed (2.2.10), but the PC is the base register. Both the operand and operand address are in memory. The processor calculates an intermediate indirect memory address by adding the PC contents, a base displacement, and the scaled contents of an index register. The processor accesses a long word at the intermediate indirect memory address and adds the optional outer displacement to yield the effective address. The value of the PC is the address of the first extension word. This is a program reference allowed only for reads.

In the syntax for this mode, brackets enclose the values used to calculate the intermediate memory address. All four user-specified values are optional. The user must supply the assembler notation ZPC showing that the PC is not used. Both the base and outer displacements may be null, word, or long word. When omitting a displacement or suppressing an element, its value is zero in the effective address calculation.

```
Intermediate = (PC) + sign_extend(bd) + (Xn.SIZE * SCALE)
EA = [Intermediate] + sign_extend(od)
```

| Property | Value |
|----------|-------|
| Assembler Syntax | `([bd,PC,Xn.SIZE*SCALE],od)` |
| EA Mode Field | 111 |
| EA Register Field | 011 |
| Extension Words | 1, 2, 3, 4, or 5 |

### 2.2.16 Absolute Short Addressing

The operand is in memory, and the address of the operand is in the extension word. The 16-bit address is sign-extended to 32 bits before it is used.

```
EA = sign_extend(xxx.W)
```

| Property | Value |
|----------|-------|
| Assembler Syntax | `(xxx).W` |
| EA Mode Field | 111 |
| EA Register Field | 000 |
| Extension Words | 1 |

### 2.2.17 Absolute Long Addressing

The operand is in memory, and the operand's address occupies the two extension words following the instruction word in memory. The first extension word contains the high-order part of the address; the second contains the low-order part of the address.

```
EA = xxx.L   (32-bit address in two extension words)
```

| Property | Value |
|----------|-------|
| Assembler Syntax | `(xxx).L` |
| EA Mode Field | 111 |
| EA Register Field | 001 |
| Extension Words | 2 |

### 2.2.18 Immediate Data

The operand is in one or more extension words.

```
Operand = #<xxx>   (value encoded in extension words)
```

| Property | Value |
|----------|-------|
| Assembler Syntax | `#<xxx>` |
| EA Mode Field | 111 |
| EA Register Field | 100 |
| Extension Words | 1, 2, 4, or 6 (except packed decimal real) |

**Immediate Operand Location by Size:**

| Operation Size | Location |
|---------------|----------|
| Byte | Low-order byte of the extension word |
| Word | The entire extension word |
| Long Word | High-order word in first extension word; low-order word in second extension word |
| Single-Precision | In two extension words |
| Double-Precision | In four extension words |
| Extended-Precision | In six extension words |
| Packed-Decimal Real | In six extension words |

## 2.3 Effective Addressing Mode Summary

Effective addressing modes are grouped according to the use of the mode:

- **Data** addressing modes refer to data operands.
- **Memory** addressing modes refer to memory operands.
- **Control** addressing modes refer to memory operands without an associated size.
- **Alterable** addressing modes refer to alterable (writable) operands.

These categories sometimes combine to form more restrictive categories: **alterable memory** (modes that are both alterable and memory addresses) and **data alterable** (modes that are both alterable and data).

### Effective Addressing Modes and Categories

| Addressing Mode | Syntax | Mode Field | Reg. Field | Data | Memory | Control | Alterable |
|----------------|--------|-----------|-----------|------|--------|---------|-----------|
| **Register Direct** | | | | | | | |
| Data | `Dn` | 000 | reg. no. | X | -- | -- | X |
| Address | `An` | 001 | reg. no. | -- | -- | -- | X |
| **Register Indirect** | | | | | | | |
| Address | `(An)` | 010 | reg. no. | X | X | X | X |
| Address with Postincrement | `(An)+` | 011 | reg. no. | X | X | -- | X |
| Address with Predecrement | `-(An)` | 100 | reg. no. | X | X | -- | X |
| Address with Displacement | `(d16,An)` | 101 | reg. no. | X | X | X | X |
| **Address Register Indirect with Index** | | | | | | | |
| 8-Bit Displacement | `(d8,An,Xn)` | 110 | reg. no. | X | X | X | X |
| Base Displacement | `(bd,An,Xn)` | 110 | reg. no. | X | X | X | X |
| **Memory Indirect** | | | | | | | |
| Postindexed | `([bd,An],Xn,od)` | 110 | reg. no. | X | X | X | X |
| Preindexed | `([bd,An,Xn],od)` | 110 | reg. no. | X | X | X | X |
| **PC Indirect with Displacement** | `(d16,PC)` | 111 | 010 | X | X | X | -- |
| **PC Indirect with Index** | | | | | | | |
| 8-Bit Displacement | `(d8,PC,Xn)` | 111 | 011 | X | X | X | -- |
| Base Displacement | `(bd,PC,Xn)` | 111 | 011 | X | X | X | -- |
| **PC Memory Indirect** | | | | | | | |
| Postindexed | `([bd,PC],Xn,od)` | 111 | 011 | X | X | X | -- |
| Preindexed | `([bd,PC,Xn],od)` | 111 | 011 | X | X | X | -- |
| **Absolute Data Addressing** | | | | | | | |
| Short | `(xxx).W` | 111 | 000 | X | X | X | X |
| Long | `(xxx).L` | 111 | 001 | X | X | X | X |
| **Immediate** | `#<xxx>` | 111 | 100 | X | X | -- | -- |

## 2.4 Brief Extension Word Format Compatibility

Programs can be easily transported from one member of the M68000 family to another in an upward-compatible fashion. The user object code of each early member of the family, which is upward compatible with newer members, can be executed on the newer microprocessor without change.

### MC68000, MC68008, and MC68010 Brief Extension Word

```
 15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
|D/A| REGISTER  |W/L| 0 | 0 | 0 |      DISPLACEMENT INTEGER    |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
```

### CPU32, MC68020, MC68030, and MC68040 Brief Extension Word

```
 15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
|D/A| REGISTER  |W/L| SCALE | 0 |      DISPLACEMENT INTEGER    |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
```

The encoding for SCALE used by the CPU32, MC68020, MC68030, and MC68040 is a compatible extension of the M68000 family architecture. A value of zero for SCALE is the same encoding for both extension words. Software that uses this encoding is compatible with all processors in the M68000 family. Both brief extension word formats do not contain the other values of SCALE. Software can be easily migrated in an upward-compatible direction, with downward support only for nonscaled addressing. If the MC68000 were to execute an instruction that encoded a scaling factor, the scaling factor would be ignored and would not access the desired memory address. The earlier microprocessors do not recognize the brief extension word formats implemented by newer processors. Although they can detect illegal instructions, they do not decode invalid encodings of the brief extension word formats as exceptions.

## 2.5 Full Extension Addressing Modes

The full extension word format provides additional addressing modes for the MC68020, MC68030, and MC68040. There are four elements common to these full extension addressing modes:

- **BR** -- Base Register (An or PC)
- **Xn** -- Index Register
- **bd** -- Base Displacement
- **od** -- Outer Displacement

Each of these four elements can be suppressed independently of each other. However, at least one element must be active and not suppressed. When an element is suppressed, it has an effective value of zero.

BR can be suppressed through the BS field of the full extension word format. The encoding of bits 0-5 in the single effective address word format selects BR as either the PC when using program relative addressing modes, or An when using non-program relative addressing modes. The value of the PC is the address of the extension word. For the non-program relative addressing modes, BR is the contents of a selected An.

SIZE and SCALE can be used to modify Xn. The W/L field in the full extension format selects the size of Xn as a word or long word. The SCALE field selects the scaling factor, shifts the value of the Xn left multiplying the value by 1, 2, 4, or 8, respectively, without actually changing the value. Scaling can be used to calculate the address of arrayed structures.

The bd and od can be either word or long word. The size of od is selected through the encoding of the I/IS field in the full extension word format (refer to the IS-I/IS table in Section 2.1). There are two main modes of operation that use these four elements in different ways: no memory indirect action and memory indirect. The od is provided only for using memory indirect addressing modes of which there are three types: with preindex, with postindex, and with index suppressed.

### Scaling Example

```
Syntax: MOVE.B (A5, A6.L*SCALE),(A7)

Where:
  A5 = address of array structure
  A6 = index number of array item
  A7 = stack pointer

  SCALE=1: Simple byte array       (each element = 1 byte)
  SCALE=2: Record of 2 bytes       (each element = 2 bytes)
  SCALE=4: Record of 4 bytes       (each element = 4 bytes)
  SCALE=8: Record of 8 bytes       (each element = 8 bytes)
```

Regardless of array structure, software increments the index by the appropriate amount to point to the next record.

### 2.5.1 No Memory Indirect Action Mode

No memory indirect action mode uses BR, Xn with its modifiers, and bd to calculate the address of the required operand. Data register indirect (Dn) and absolute address with index (bd,Xn.SIZE\*SCALE) are examples of this mode.

```
EA = BR + bd + Xn.SIZE * SCALE
```

**Element combinations (S = Suppressed, A = Active):**

| BR | Xn | bd | Addressing Mode |
|----|----|----|----------------|
| S | S | S | Not Applicable |
| S | S | A | Absolute Addressing Mode |
| S | A | S | Register Indirect |
| S | A | A | Register Indirect with Constant Index |
| An | S | S | Address Register Indirect |
| An | S | A | Address Register Indirect with Constant Index |
| An | A | S | Address Register Indirect with Variable Index |
| An | A | A | Address Register Indirect with Constant and Variable Index |
| PC | S | S | PC Relative |
| PC | S | A | PC Relative with Constant Index |
| PC | A | S | PC Relative with Variable Index |
| PC | A | A | PC Relative with Constant and Variable Index |

### 2.5.2 Memory Indirect Modes

Memory indirect modes fetch two operands from memory. The BR and bd evaluate the address of the first operand, intermediate memory pointer (IMP). The value of IMP and the od evaluates the address of the second operand.

There are three types of memory indirect modes: pre-index, post-index, and index register suppressed. Xn and its modifiers can be allocated to determine either the address of the IMP (pre-index) or the address of the second operand (post-index).

#### 2.5.2.1 Memory Indirect with Preindex

The Xn is allocated to determine the address of the IMP.

```
IMP = BR + bd + Xn.SIZE * SCALE
EA  = [IMP] + od
```

**Element combinations (S = Suppressed, A = Active):**

| BR | Xn | bd | od | IMP Addressing Mode | Operand Addressing Mode |
|----|----|----|----|--------------------|------------------------|
| S | A | S | S | Register Indirect | Memory Pointer Directly to Data Operand |
| S | A | S | A | Register Indirect | Memory Pointer as Base with Displacement to Data Operand |
| S | A | A | S | Register Indirect with Constant Index | Memory Pointer Directly to Data Operand |
| S | A | A | A | Register Indirect with Constant Index | Memory Pointer as Base with Displacement to Data Operand |
| An | A | S | S | Address Register Indirect with Variable Index | Memory Pointer Directly to Data Operand |
| An | A | S | A | Address Register Indirect with Variable Index | Memory Pointer as Base with Displacement to Data Operand |
| An | A | A | S | Address Register Indirect with Constant and Variable Index | Memory Pointer Directly to Data Operand |
| An | A | A | A | Address Register Indirect with Constant and Variable Index | Memory Pointer as Base with Displacement to Data Operand |
| PC | A | S | S | PC Relative with Variable Index | Memory Pointer Directly to Data Operand |
| PC | A | S | A | PC Relative with Variable Index | Memory Pointer as Base with Displacement to Data Operand |
| PC | A | A | S | PC Relative with Constant and Variable Index | Memory Pointer Directly to Data Operand |
| PC | A | A | A | PC Relative with Constant and Variable Index | Memory Pointer as Base with Displacement to Data Operand |

#### 2.5.2.2 Memory Indirect with Postindex

The Xn is allocated to evaluate the address of the second operand.

```
IMP = BR + bd
EA  = [IMP] + Xn.SIZE * SCALE + od
```

**Element combinations (S = Suppressed, A = Active):**

| BR | Xn | bd | od | IMP Addressing Mode | Operand Addressing Mode |
|----|----|----|----|--------------------|------------------------|
| S | A | S | S | -- | -- |
| S | A | S | A | -- | -- |
| S | A | A | S | Absolute Addressing Mode | Memory Pointer with Variable Index to Data Operand |
| S | A | A | A | Absolute Addressing Mode | Memory Pointer with Constant and Variable Index to Data Operand |
| An | A | S | S | Address Register Indirect | Memory Pointer with Variable Index to Data Operand |
| An | A | S | A | Address Register Indirect | Memory Pointer with Constant and Variable Index to Data Operand |
| An | A | A | S | Address Register Indirect with Constant Index | Memory Pointer with Variable Index to Data Operand |
| An | A | A | A | Address Register Indirect with Constant Index | Memory Pointer with Constant and Variable Index to Data Operand |
| PC | A | S | S | PC Relative | Memory Pointer with Variable Index to Data Operand |
| PC | A | S | A | PC Relative | Memory Pointer with Constant and Variable Index to Data Operand |
| PC | A | A | S | PC Relative with Constant Index | Memory Pointer with Variable Index to Data Operand |
| PC | A | A | A | PC Relative with Constant Index | Memory Pointer with Constant and Variable Index to Data Operand |

#### 2.5.2.3 Memory Indirect with Index Suppressed

The Xn is suppressed.

```
IMP = BR + bd
EA  = [IMP] + od
```

**Element combinations (S = Suppressed, A = Active):**

| BR | Xn | bd | od | IMP Addressing Mode | Operand Addressing Mode |
|----|----|----|----|--------------------|------------------------|
| S | S | S | S | -- | -- |
| S | S | S | A | -- | -- |
| S | S | A | S | Absolute Addressing Mode | Memory Pointer Directly to Data Operand |
| S | S | A | A | Absolute Addressing Mode | Memory Pointer as Base with Displacement to Data Operand |
| An | S | S | S | Address Register Indirect | Memory Pointer Directly to Data Operand |
| An | S | S | A | Address Register Indirect | Memory Pointer as Base with Displacement to Data Operand |
| An | S | A | S | Address Register Indirect with Constant Index | Memory Pointer Directly to Data Operand |
| An | S | A | A | Address Register Indirect with Constant Index | Memory Pointer as Base with Displacement to Data Operand |
| PC | S | S | S | PC Relative | Memory Pointer Directly to Data Operand |
| PC | S | S | A | PC Relative | Memory Pointer as Base with Displacement to Data Operand |
| PC | S | A | S | PC Relative with Constant Index | Memory Pointer Directly to Data Operand |
| PC | S | A | A | PC Relative with Constant Index | Memory Pointer as Base with Displacement to Data Operand |

## 2.6 Other Data Structures

Stacks and queues are common data structures. The M68000 family implements a system stack and instructions that support user stacks and queues.

### 2.6.1 System Stack

Address register seven (A7) is the system stack pointer. Either the user stack pointer (USP), the interrupt stack pointer (ISP), or the master stack pointer (MSP) is active at any one time. To keep data on the system stack aligned for maximum efficiency, the active stack pointer is automatically decremented or incremented by two for all byte-size operands moved to or from the stack. In long-word-organized memory, aligning the stack pointer on a long-word address significantly increases the efficiency of stacking exception frames, subroutine calls and returns, and other stacking operations.

The user can implement stacks with the address register indirect with postincrement and predecrement addressing modes. With an address register, the user can implement a stack that fills either from high memory to low memory or from low memory to high memory. Important considerations are:

- Use the predecrement mode to decrement the register before using its contents as the pointer to the stack.
- Use the postincrement mode to increment the register after using its contents as the pointer to the stack.
- Maintain the stack pointer correctly when byte, word, and long-word items mix in these stacks.

**Stack growth from high memory to low memory:** Use `-(An)` to push data on the stack and `(An)+` to pull data from the stack. After either a push or pull operation, the address register points to the top item on the stack.

```
              LOW MEMORY
              (FREE)
  An ------> TOP OF STACK
              ...
              BOTTOM OF STACK
              HIGH MEMORY
```

**Stack growth from low memory to high memory:** Use `(An)+` to push data on the stack and `-(An)` to pull data from the stack. After either a push or pull operation, the address register points to the next available space on the stack.

```
              LOW MEMORY
              BOTTOM OF STACK
              ...
              TOP OF STACK
  An ------> (FREE)
              HIGH MEMORY
```

### 2.6.2 Queues

The user can implement queues with the address register indirect with postincrement or predecrement addressing modes. Using a pair of address registers, the user implements a queue that fills either from high memory to low memory or from low memory to high memory. Two registers are used because queues get pushed from one end and pulled from the other. One address register contains the put pointer; the other register the get pointer.

**Queue growth from low memory to high memory:** Use the put address register with `(An)+` to put data into the queue and the get address register with `(Am)+` to get data from the queue.

After a put operation, the put address register points to the next available space in the queue; the unchanged get address register points to the next item to be removed. After a get operation, the get address register points to the next item to be removed; the unchanged put address register points to the next available space.

```
              LOW MEMORY
  GET (Am)+ : LAST GET (FREE)
              NEXT GET
              ...
              LAST PUT
  PUT (An)+ : (FREE)
              HIGH MEMORY
```

**Queue growth from high memory to low memory:** Use `-(An)` to put data into the queue and `-(Am)` to get data from the queue.

After a put operation, the put address register points to the last item placed in the queue. After a get operation, the get address register points to the last item removed from the queue.

```
              LOW MEMORY
  PUT -(An) : (FREE)
              LAST PUT
              ...
              NEXT GET
  GET -(Am) : LAST GET (FREE)
              HIGH MEMORY
```

To implement either queue direction as a circular buffer, check and adjust the relevant address register before (low-to-high) or after (high-to-low) performing the put or get operation. Subtract (low-to-high) or add (high-to-low) the buffer length in bytes to wrap the address register.
