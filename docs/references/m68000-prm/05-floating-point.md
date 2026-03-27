# Section 5: Floating-Point Instructions

Complete FPU instruction reference for MC68881/MC68882/MC68040 FPSP.

> Source: Motorola M68000 Family Programmer's Reference Manual, Section 5.
> Covers all floating-point instructions for the MC68881, MC68882, and MC68040.
> MC68040 references exclude the MC68LC040 and MC68EC040 variants.
> For all MC68040 floating-point instructions, the coprocessor ID field must be 001.

## Instruction Support Summary

### Directly Supported by MC68040

| Mnemonic | Description |
|----------|-------------|
| FABS | Floating-Point Absolute Value |
| FADD | Floating-Point Add |
| FBcc | Floating-Point Branch Conditionally |
| FCMP | Floating-Point Compare |
| FDBcc | Floating-Point Test Condition, Decrement, and Branch |
| FDIV | Floating-Point Divide |
| FMOVE | Move Floating-Point Data Register |
| FMOVE | Move Floating-Point System Control Register |
| FMOVEM | Move Multiple Floating-Point Data Registers |
| FMOVEM | Move Multiple Floating-Point Control Registers |
| FMUL | Floating-Point Multiply |
| FNEG | Floating-Point Negate |
| FNOP | No Operation |
| FRESTORE\* | Restore Internal Floating-Point State |
| FSAVE\* | Save Internal Floating-Point State |
| FScc | Set According to Floating-Point Condition |
| FSQRT | Floating-Point Square Root |
| FSUB | Floating-Point Subtract |
| FSGLDIV | Floating-Point Single-Precision Divide |
| FSGLMUL | Floating-Point Single-Precision Multiply |
| FTRAPcc | Trap on Floating-Point Condition |
| FTST | Test Floating-Point Operand |

\* Privileged instructions; refer to Section 6 Supervisor (Privileged) Instructions.

### Indirectly Supported (MC68040 FPSP Software Emulation)

| Mnemonic | Description |
|----------|-------------|
| FACOS | Arc Cosine |
| FASIN | Arc Sine |
| FATAN | Arc Tangent |
| FATANH | Hyperbolic Arc Tangent |
| FCOS | Cosine |
| FCOSH | Hyperbolic Cosine |
| FETOX | e^x |
| FETOXM1 | e^x - 1 |
| FGETEXP | Get Exponent |
| FGETMAN | Get Mantissa |
| FINT | Integer Part |
| FINTRZ | Integer Part, Round-to-Zero |
| FLOG10 | Log10 |
| FLOG2 | Log2 |
| FLOGN | Loge |
| FLOGNP1 | Loge(x + 1) |
| FMOD | Modulo Remainder |
| FMOVECR | Move Constant ROM |
| FREM | IEEE Remainder |
| FSCALE | Scale Exponent |
| FSIN | Sine |
| FSINCOS | Simultaneous Sine and Cosine |
| FSINH | Hyperbolic Sine |
| FTAN | Tangent |
| FTANH | Hyperbolic Tangent |
| FTENTOX | 10^x |
| FTWOTOX | 2^x |

## Common Encoding Reference

### Source Specifier Encoding

When R/M = 1, the source specifier field encodes the data format:

| Code | Format |
|------|--------|
| 000 | Long-Word Integer (L) |
| 001 | Single-Precision Real (S) |
| 010 | Extended-Precision Real (X) |
| 011 | Packed-Decimal Real (P) |
| 100 | Word Integer (W) |
| 101 | Double-Precision Real (D) |
| 110 | Byte Integer (B) |

Note: Packed-Decimal (011) causes an unimplemented data type exception on the MC68040.

### Standard Data Addressing Modes

| Addressing Mode | Mode | Register |
|-----------------|------|----------|
| Dn\* | 000 | reg. number:Dn |
| An | -- | -- |
| (An) | 010 | reg. number:An |
| (An)+ | 011 | reg. number:An |
| -(An) | 100 | reg. number:An |
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
| #\<data\> | 111 | 100 |

\* Only if format is byte, word, long, or single.

### Standard Instruction Format (Monadic/Dyadic)

```
15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
 1   1   1   1 | COPROCESSOR ID| 0   0   0 |  EFFECTIVE ADDRESS  |
               |               |           |   MODE  | REGISTER  |
 0  R/M |SOURCE SPECIFIER|DEST REG|         OPMODE              |
```

- R/M = 0: register to register
- R/M = 1: \<ea\> to register
- Coprocessor ID: Motorola assemblers default to 1 for the FPU

---

## FABS

**Floating-Point Absolute Value**

*(MC6888X, MC68040)*

### Assembler Syntax

```asm
FABS. <fmt> <ea> ,FPn
FABS.X
FPm,FPn
FABS.X
FPn
*FrABS. <fmt> <ea> ,FPn
*FrABS.X
FPm,FPn
*FrABS.X Pn
where r is rounding precision, S or D
*Supported by MC68040 only.
```

### Attributes

Format = (Byte, Word, Long, Single, Quad, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and stores the absolute value of that number in the destination floating-point data register. FABS will round the result to the precision selected in the floating-point control register. FSABS and FDABS will round the result to single or double precision, respectively, regardless of the rounding precision selected in the floating-point control register.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers |
| OPERR | Cleared |
| OVFL | Cleared |
| UNFL | If the source is an extended-precision denormalized number, refer to exception processing in the appropriate user’s manual; cleared otherwise. |
| DZ | Cleared |
| INEX2 | Cleared |
| INEX1 | If <fmt> is packed, refer to exception processing in the appropriate user’s manual; cleared otherwise. |

### Opmode

```
0011000 FABS
1011000 FSABS
1011100 FDABS  -- Rounding precision specified by the floating-point control
```

### Applicable Processors

MC6888X, MC68040 (directly supported in hardware)

---

## FACOS

**Arc Cosine**

*(MC6888X, M68040FPSP)*

### Operation

`Arc Cosine of Source → FPn`

### Assembler Syntax

```asm
FACOS. <fmt>
FACOS.X
FACOS.X
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and calculates the arc cosine of that number. Stores the result in the destination floating-point data register. This function is not defined for source operands outside of the range [ – 1... + 1]; if the source is not in the correct range, a NAN is returned as the result and the OPERR bit is set in the floating-point status register. If the source is in the correct range, the result is in the range of [0...π].

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN |  |
| SNAN |  |
| OPERR |  |
| OVFL |  |
| UNFL |  |
| DZ |  |
| INEX2 |  |
| INEX1 |  |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FADD

**Floating-Point Add**

*(MC6888X, MC68040)*

### Operation

`Source + FPn → FPn`

### Assembler Syntax

```asm
FADD. <fmt> <ea> ,FPn
FADD.X
FPm,FPn
*FrADD. <fmt> <ea> ,FPn
*FrADD.X
FPm,FPn
where r is rounding precision, S or D
*Supported by MC68040 only.
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and adds that number to the number contained in the destination floating-point data register. Stores the result in the destination floating-point data register. FADD will round the result to the precision selected in the floating-point control register. FSADD and FDADD will round the result to single or double-precision, respectively, regardless of the rounding precision selected in the floating-point control register.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers. |
| OPERR | Set if the source and the destination are opposite-signed infinities; cleared otherwise. |
| OVFL | Refer to exception processing in the appropriate user’s manual. |
| UNFL | Refer to exception processing in the appropriate user’s manual. |
| DZ | Cleared |
| INEX2 | Refer to exception processing in the appropriate user’s manual. |
| INEX1 | If <fmt> is packed, refer to exception processing in the appropriate user’s manual; cleared otherwise. |

### Opmode

```
0100010 FADD
1100010 FSADD
1100110 FDADD  -- Rounding precision specified by the floating-point control
```

### Applicable Processors

MC6888X, MC68040 (directly supported in hardware)

---

## FASIN

**Arc Sine**

*(MC6888X, M68040FPSP)*

### Operation

`Arc Sine of the Source → FPn`

### Assembler Syntax

```asm
FASIN. <fmt>
FASIN.X
FASIN.X
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and calculates the arc sine of the number. Stores the result in the destination floating-point data register. This function is not defined for source operands outside of the range [ – 1... + 1]; if the source is not in the correct range, a NAN is returned as the result and the OPERR bit is set in the floating-point status register. If the source is in the correct range, the result is in the range of [ – π/2... + π/2].

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers. |
| OPERR | Set if the source is infinity, > + 1 or < – 1; cleared otherwise |
| OVFL | Cleared |
| UNFL | Can be set for an underflow condition. |
| DZ | Cleared |
| INEX2 | Refer to inexact result in the appropriate user’s manual. |
| INEX1 | If <fmt> is packed, refer to inexact result on decimal input in the appropriate user’s manual; cleared otherwise. |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FATAN

**Arc Tangent**

*(MC6888X, M68040FPSP)*

### Operation

`Arc Tangent of Source → FPn`

### Assembler Syntax

```asm
FATAN. <fmt>
FATAN.X
FATAN.X
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and calculates the arc tangent of that number. Stores the result in the destination floating-point data register. The result is in the range of [ – π/2... + π/2].

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN |  |
| SNAN |  |
| OPERR |  |
| OVFL |  |
| UNFL |  |
| DZ |  |
| INEX2 |  |
| INEX1 |  |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FATANH

**Hyperbolic Arc Tangent**

*(MC6888X, M68040FPSP)*

### Operation

`Hyperbolic Arc Tangent of Source → FPn`

### Assembler Syntax

```asm
FATANH. <fmt> <ea> ,FPn
FATANH.X
FPm,FPn
FATANH.X
FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and calculates the hyperbolic arc tangent of that value. Stores the result in the destination floating-point data register. This function is not defined for source operands outside of the range ( – 1... + 1); and the result is equal to – infinity or + infinity if the source is equal to + 1 or – 1, respectively. If the source is outside of the range [ – 1... + 1], a NAN is returned as the result, and the OPERR bit is set in the floating-point status register.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected. M68000 FAMILY PROGRAMMER’S REFERENCE MANUAL FATANH FATANH Hyperbolic Arc Tangent (MC6888X, M68040FPSP)

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers. |
| OPERR | Set if the source is > + 1 or < – 1; cleared otherwise. |
| OVFL | Cleared |
| UNFL | Refer to underflow in the appropriate user’s manual. |
| DZ | Set if the source is equal to + 1 or – 1; cleared otherwise. |
| INEX2 | Refer to inexact result in the appropriate user’s manual. |
| INEX1 | If <fmt> is packed, refer to inexact result on decimal input in the appropriate user’s manual; cleared otherwise. |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FBcc

**Floating-Point Branch Conditionally**

*(MC6888X, MC68040)*

### Operation

`If Condition True Then PC + dn -> PC`

### Assembler Syntax

```asm
FBcc.<size> <label>
```

### Attributes

Size = (Word, Long)

### Description

If the specified floating-point condition is met, program execution continues at the location (PC) + displacement. The displacement is a twos-complement integer that counts the relative distance in bytes. The value of the program counter used to calculate the destination address is the address of the branch instruction plus two. If the displacement size is word, then a 16-bit displacement is stored in the word immediately following the instruction operation word. If the displacement size is long word, then a 32-bit displacement is stored in the two words immediately following the instruction operation word. The conditional specifier cc selects any one of the 32 floating-point conditional tests as described in 3.6.2 Conditional Testing.

### Condition Codes

Not affected.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Set if the NAN condition code is set and the condition selected is an IEEE nonaware test. |
| SNAN | Not affected. |
| OPERR | Not affected. |
| OVFL | Not affected. |
| UNFL | Not affected. |
| DZ | Not affected. |
| INEX2 | Not affected. |
| INEX1 | Not affected. |

### Applicable Processors

MC6888X, MC68040 (directly supported in hardware)

---

## FCMP

**Floating-Point Compare**

*(MC6888X, MC68040)*

### Operation

`FPn – Source`

### Assembler Syntax

```asm
FCMP. <fmt> <ea> ,FPn
FCMP.X FPm,FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and subtracts the operand from the destination floating-point data register. The result of the subtraction is not retained, but it is used to set the floating-point condition codes as described in 3.6.2 Conditional Testing.

### Condition Codes

Affected as described in the preceding operation table.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN |  |
| SNAN |  |
| OPERR |  |
| OVFL |  |
| UNFL |  |
| DZ |  |
| INEX2 |  |
| INEX1 |  |

### Applicable Processors

MC6888X, MC68040 (directly supported in hardware)

---

## FCOS

**Cosine**

*(MC6888X, M68040FPSP)*

### Operation

`Cosine of Source → FPn`

### Assembler Syntax

```asm
FCOS. <fmt> <ea> ,FPn
FCOS.X FPm,FPn FCOS.X FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and calculates the cosine of that number. Stores the result in the destination floating-point data register. This function is not defined for source operands of ± infinity. If the source operand is not in the range of [ – 2π... + 2π], then the argument is reduced to within that range before the cosine is calculated. However, large arguments may lose accuracy during reduction, and very large arguments (greater than approximately 1020) lose all accuracy. The result is in the range of [ – 1... + 1].

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers. |
| OPERR | Set if the source operand is ± infinity; cleared otherwise. |
| OVFL | Cleared |
| UNFL | Cleared |
| DZ | Cleared |
| INEX2 | Refer to inexact result in the appropriate user’s manual. |
| INEX1 | If <fmt> is packed, refer to inexact result on decimal input in the appropriate user’s manual; cleared otherwise. |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FCOSH

**Hyperbolic Cosine**

*(MC6888X, M68040FPSP)*

### Operation

`Hyperbolic Cosine of Source → FPn`

### Assembler Syntax

```asm
FCOSH. <fmt> <ea> ,FPn
FCOSH.X FPm,FPn FCOSH.X FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and calculates the hyperbolic cosine of that number. Stores the result in the destination floating-point data register.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN |  |
| SNAN |  |
| OPERR |  |
| OVFL |  |
| UNFL |  |
| DZ |  |
| INEX2 |  |
| INEX1 |  |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FDBcc

**Floating-Point Test Condition, Decrement, and Branch**

*(MC6888X, MC68040)*

### Operation

`If Condition True Then No Operation Else Dn – 1 → Dn If Dn ≠ – 1 Then PC + dn → PC Else Execute Next Instruction`

### Assembler Syntax

```asm
FDBcc Dn, <label>
```

### Attributes

Unsized

### Description

This instruction is a looping primitive of three parameters: a floating-point condition, a counter (data register), and a 16-bit displacement. The instruction first tests the condition to determine if the termination condition for the loop has been met, and if so, execution continues with the next instruction in the instruction stream. If the termination condition is not true, the low-order 16 bits of the counter register are decremented by one. If the result is – 1, the count is exhausted, and execution continues with the next instruction. If the result is not equal to – 1, execution continues at the location specified by the current value of the program counter plus the signextended 16-bit displacement. The value of the program counter used in the branch address calculation is the address of the displacement word. The conditional specifier cc selects any one of the 32 floating-point conditional tests as described in 3.6.2 Conditional Testing.

### Condition Codes

Not affected.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Set if the NAN condition code is set and the condition selected is an IEEE nonaware test. |
| SNAN | Not affected. |
| OPERR | Not affected. |
| OVFL | Not affected. |
| UNFL | Not affected. |
| DZ | Not affected. |
| INEX2 | Not affected. |
| INEX1 | Not affected. |

### Applicable Processors

MC6888X, MC68040 (directly supported in hardware)

---

## FDIV

**Floating-Point Divide**

*(MC6888X, MC68040)*

### Operation

`FPn ÷ Source → FPn`

### Assembler Syntax

```asm
FDIV. <fmt> <ea> ,FPn
FDIV.X FPm,FPn
*FrDIV. <fmt> <ea> ,FPn
*FrDIV.X FPm,FPn
where r is rounding precision, S or D
*Supported by MC68040 only
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and divides that number into the number in the destination floating-point data register. Stores the result in the destination floating-point data register. FDIV will round the result to the precision selected in the floating-point control register. FSDIV and FDDIV will round the result to single or double precision, respectively, regardless of the rounding precision selected in the floating-point control register.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers. Set for 0 ÷ 0 or infinity ÷ infinity; cleared otherwise. |
| OPERR | Refer to exception processing in the appropriate user’s manual. |
| OVFL | Refer to exception processing in the appropriate user’s manual. |
| UNFL | Set if the source is zero and the destination is in range; cleared otherwise. |
| DZ | Refer to exception processing in the appropriate user’s manual. |
| INEX2 | If <fmt> is packed, refer to exception processing in the appropriate user’s manual; cleared otherwise. |
| INEX1 |  |

### Opmode

```
0100000 FDIV
1100000 FSDIV
1100100 FDDIV  -- Rounding precision specified by the floating-point
```

### Applicable Processors

MC6888X, MC68040 (directly supported in hardware)

---

## FETOX

**ex**

*(MC6888X, M68040FPSP)*

### Operation

`eSource → FPn`

### Assembler Syntax

```asm
FETOX. <fmt> <ea> ,FPn
FETOX.X FPm,FPn
FETOX.X FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and calculates e to the power of that number. Stores the result in the destination floating-point data register.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN |  |
| SNAN |  |
| OPERR |  |
| OVFL |  |
| UNFL |  |
| DZ |  |
| INEX2 |  |
| INEX1 |  |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FETOXM1

**ex – 1**

*(MC6888X, M68040FPSP)*

### Operation

`eSource – 1 → FPn`

### Assembler Syntax

```asm
FETOXM1. <fmt> <ea> ,FPn
FETOXM1.X FPm,FPn
FETOXM1.X FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and calculates e to the power of that number. Subtracts one from the value and stores the result in the destination floating-point data register.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Not affected. |
| SNAN | Cleared |
| OPERR | Refer to 1.6.5 Not-A-Numbers. |
| OVFL | Cleared |
| UNFL | Refer to overflow in the appropriate user’s manual. |
| DZ | Refer to underflow in the appropriate user’s manual. |
| INEX2 | Cleared |
| INEX1 | Refer to inexact result in the appropriate user’s manual. |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FGETEXP

**Get Exponent**

*(MC6888X, M68040FPSP)*

### Operation

`Exponent of Source → FPn`

### Assembler Syntax

```asm
FGETEXP. <fmt> <ea> ,FPn
FGETEXP.X FPm,FPn
FGETEXP.X FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and extracts the binary exponent. Removes the exponent bias, converts the exponent to an extended-precision floating-point number, and stores the result in the destination floating-point data register.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN |  |
| SNAN |  |
| OPERR |  |
| OVFL |  |
| UNFL |  |
| DZ |  |
| INEX2 |  |
| INEX1 |  |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FGETMAN

**Get Mantissa**

*(MC6888X, M68040FPSP)*

### Operation

`Mantissa of Source → FPn`

### Assembler Syntax

```asm
FGETMAN. <fmt> <ea> ,FPn
FGETMAN.X FPm,FPn
FGETMAN.X FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and extracts the mantissa. Converts the mantissa to an extended-precision value and stores the result in the destination floating-point data register. The result is in the range [1.0...2.0] with the sign of the source mantissa, zero, or a NAN.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN |  |
| SNAN |  |
| OPERR |  |
| OVFL |  |
| UNFL |  |
| DZ |  |
| INEX2 |  |
| INEX1 |  |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FINT

**Integer Part**

*(MC6888X, M68040FPSP)*

### Operation

`Integer Part of Source → FPn`

### Assembler Syntax

```asm
FINT. <fmt> <ea> ,FPn
FINT.X FPm,FPn
FINT.X FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary), extracts the integer part, and converts it to an extended-precision floating-point number. Stores the result in the destination floating-point data register. The integer part is extracted by rounding the extended-precision number to an integer using the current rounding mode selected in the floating-point control register mode control byte. Thus, the integer part returned is the number that is to the left of the radix point when the exponent is zero, after rounding. For example, the integer part of 137.57 is 137.0 for the round-to-zero and round-to- negative infinity modes and 138.0 for the round-to-nearest and round-topositive infinity modes. Note that the result of this operation is a floating-point number.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers. |
| OPERR | Cleared |
| OVFL | Cleared |
| UNFL | Cleared |
| DZ | Cleared |
| INEX2 | Refer to inexact result in the appropriate user’s manual. |
| INEX1 | If <fmt> is packed, refer to inexact result on decimal input in the appropriate user’s manual; cleared otherwise. |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FINTRZ

**Integer Part, Round-to-Zero**

*(MC6888X, M68040FPSP)*

### Operation

`Integer Part of Source → FPn`

### Assembler Syntax

```asm
FINTRZ. <fmt> <ea> ,FPn
FINTRZ.X FPm,FPn
FINTRZ.X FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and extracts the integer part and converts it to an extended-precision floating-point number. Stores the result in the destination floating-point data register. The integer part is extracted by rounding the extended-precision number to an integer using the round-tozero mode, regardless of the rounding mode selected in the floating-point control register mode control byte (making it useful for FORTRAN assignments). Thus, the integer part returned is the number that is to the left of the radix point when the exponent is zero. For example, the integer part of 137.57 is 137.0; the integer part of 0.1245 x 102 is 12.0. Note that the result of this operation is a floating-point number.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers. |
| OPERR | Cleared |
| OVFL | Cleared |
| UNFL | Cleared |
| DZ | Cleared |
| INEX2 | Refer to inexact result in the appropriate user’s manual. |
| INEX1 | If <fmt> is packed, refer to inexact result on decimal input in the appropriate user’s manual; cleared otherwise. |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FLOG10

**Log10**

*(MC6888X, M68040FPSP)*

### Operation

`Log10 of Source → FPn`

### Assembler Syntax

```asm
FLOG10. <fmt> <ea> ,FPn
FLOG10.X FPm,FPn
FLOG10.X FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Convert the source operand to extended precision (if necessary) and calculates the logarithm of that number using base 10 arithmetic. Stores the result in the destination floating-point data register. This function is not defined for input values less than zero.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN |  |
| SNAN |  |
| OPERR |  |
| OVFL |  |
| UNFL |  |
| DZ |  |
| INEX2 |  |
| INEX1 |  |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FLOG2

**Log2**

*(MC6888X, M68040FPSP)*

### Operation

`Log2 of Source → FPn`

### Assembler Syntax

```asm
FLOG2. <fmt> <ea> ,FPn
FLOG2.X FPm,FPn
FLOG2.X FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and calculates the logarithm of that number using base two arithmetic. Stores the result in the destination floating-point data register. This function is not defined for input values less than zero.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN |  |
| SNAN |  |
| OPERR |  |
| OVFL |  |
| UNFL |  |
| DZ |  |
| INEX2 |  |
| INEX1 |  |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FLOGN

**Loge**

*(MC6888X, M68040FPSP)*

### Operation

`Loge of Source → FPn`

### Assembler Syntax

```asm
FLOGN. <fmt> <ea> ,FPn
FLOGN.X FPm,FPn
FLOGN.X FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and calculates the natural logarithm of that number. Stores the result in the destination floating-point data register. This function is not defined for input values less than zero.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN |  |
| SNAN |  |
| OPERR |  |
| OVFL |  |
| UNFL |  |
| DZ |  |
| INEX2 |  |
| INEX1 |  |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FLOGNP1

**Loge (x + 1)**

*(MC6888X, M68040FPSP)*

### Operation

`Loge of (Source + 1) → FPn`

### Assembler Syntax

```asm
FLOGNP1. <fmt> <ea> ,FPn
FLOGNP1.X FPm,FPn
FLOGNP1.X FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary), adds one to that value, and calculates the natural logarithm of that intermediate result. Stores the result in the destination floating-point data register. This function is not defined for input values less than – 1.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected. M68000 FAMILY PROGRAMMER’S REFERENCE MANUAL FLOGNP1 FLOGNP1 Loge (x + 1) (MC6888X, M68040FPSP)

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers. |
| OPERR | Set if the source operand is < – 1; cleared otherwise. |
| OVFL | Cleared |
| UNFL | Refer to underflow in the appropriate user’s manual. |
| DZ | Set if the source operand is – 1; cleared otherwise |
| INEX2 | Refer to inexact result in the appropriate user’s manual. |
| INEX1 | If <fmt> is packed, refer to inexact result on decimal input in the appropriate user’s manual; cleared otherwise. |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FMOD

**Modulo Remainder**

*(MC6888X, M68040FPSP)*

### Operation

`Modulo Remainder of (FPn ÷ Source) → FPn`

### Assembler Syntax

```asm
FMOD. <fmt> <ea> ,FPn
FMOD.X FPm,FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and calculates the modulo remainder of the number in the destination floating-point data register, using the source operand as the modulus. Stores the result in the destination floating-point data register and stores the sign and seven least significant bits of the quotient in the floating-point status register quotient byte (the quotient is the result of FPn ÷ Source). The modulo remainder function is defined as: FPn – (Source x N) where N = INT(FPn ÷ Source) in the round-to-zero mode. The FMOD function is not defined for a source operand equal to zero or for a destination operand equal to infinity. Note that this function is not the same as the FREM instruction, which uses the round-to-nearest mode and thus returns the remainder that is required by the IEEE Specification for Binary Floating-Point Arithmetic.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Loaded with the sign and least significant seven bits of the quotient (FPn ÷ Source). The sign of the quotient is the exclusive-OR of the sign bits of the source and destination operands.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers. |
| OPERR | Set if the source is zero or the destination is infinity; cleared otherwise. |
| OVFL | Cleared |
| UNFL | Refer to underflow in the appropriate user’s manual. |
| DZ | Cleared |
| INEX2 | Refer to inexact result in the appropriate user’s manual. |
| INEX1 | If <fmt> is packed, in the appropriate user’s manual for inexact result on decimal input; cleared otherwise. |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FMOVE

**0 — The operation is register to register. 1 — The operation is <ea> to register. Source Specifier field—Specifies the source register or data format. If R/M = 0, specifies the source floating-point data register. If R/M = 1, specifies the source data format: 000 — Long-Word Integer (L) 001 — Single-Precision Real (S) 010 — Extended-Precision Real (X) 011 — Packed-Decimal Real (P) 100 — Word Integer (W) 101 — Double-Precision Real (D) 110 — Byte Integer (B) Destination Register field—Specifies the destination floating-point data register. M68000 FAMILY PROGRAMMER’S REFERENCE MANUAL Move Floating-Point Data Register**

*(MC6888X, MC68040)*

### Operation

`Source → Destination`

### Assembler Syntax

```asm
FMOVE. <fmt> <ea> ,FPn
FMOVE. <fmt> FPm, <ea>
FMOVE.P FPm, <ea> {Dn}
FMOVE.P FPm, <ea> {k}
*FrMOVE. <fmt> <ea> ,FPn
where r is rounding precision, S or D
FMOVE
*Supported by MC68040 only
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Moves the contents of the source operand to the destination operand. Although the primary function of this instruction is data movement, it is also considered an arithmetic instruction since conversions from the source operand format to the destination operand format are performed implicitly during the move operation. Also, the source operand is rounded according to the selected rounding precision and mode. Unlike the MOVE instruction, the FMOVE instruction does not support a memory-to-memory format. For such transfers, it is much faster to utilize the MOVE instruction to transfer the floating-point data than to use the FMOVE instruction. The FMOVE instruction only supports memory-to-register, register-to- register, and register-tomemory operations (in this context, memory may refer to an integer data register if the data format is byte, word, long, or single). The memory-to-register and register-to-register operation uses a command word encoding distinctly different from that used by the register-to-memory operation; these two operation classes are described separately. Memory-to-Register and Register-to-Register Operation: Converts the source operand to an extended-precision floating-point number (if necessary) and stores it in the destination floating-point data register. MOVE will round the result to the precision selected in the floating-point control register. FSMOVE and FDMOVE will round the result to single or double precision, respectively, regardless of the rounding precision selected in the floating-point control register. Depending on the source data format and the rounding precision, some operations may produce an inexact result. In the following table, combinations that can produce an inexact result are marked with a dot (⋅), but all other combinations produce an exact result. M68000 FAMILY PROGRAMMER’S REFERENCE MANUAL FMOVE FMOVE Move Floating-Point Data Register (MC6888X, MC68040)

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN |  |
| SNAN |  |
| OPERR |  |
| OVFL |  |
| UNFL |  |
| DZ |  |
| INEX2 |  |
| INEX1 |  |

### Opmode

```
0000000 FMOVE  -- Rounding precision specified by the floating-point
```

### Applicable Processors

MC6888X, MC68040 (directly supported in hardware)

---

## FMOVE

**Move Floating-Point System Control Register**

*(MC6888X, MC68040)*

### Operation

`Source → Destination`

### Assembler Syntax

```asm
FMOVE.L <ea> ,FPCR
FMOVE.L FPCR, <ea>
```

### Attributes

Size = (Long)

### Description

Moves the contents of a floating-point system control register (floating-point control register, floating-point status register, or floating-point instruction address register) to or from an effective address. A 32-bit transfer is always performed, even though the system control register may not have 32 implemented bits. Unimplemented bits of a control register are read as zeros and are ignored during writes (must be zero for compatibility with future devices). For the MC68881, this instruction does not cause pending exceptions (other than protocol violations) to be reported. Furthermore, a write to the floating-point control register exception enable byte or the floating-point status register exception status byte cannot generate a new exception, regardless of the value written.

### Applicable Processors

MC6888X, MC68040 (directly supported in hardware)

---

## FMOVECR

**Move Constant ROM**

*(MC6888X, M68040FPSP)*

### Operation

`ROM Constant → FPn`

### Assembler Syntax

```asm
FMOVECR.X
```

### Attributes

Format = (Extended)

### Description

Fetches an extended-precision constant from the floating-point coprocessor on-chip ROM, rounds the mantissa to the precision specified in the floating-point control register mode control byte, and stores it in the destination floating-point data register. The constant is specified by a predefined offset into the constant ROM. The values of the constants contained in the ROM are shown in the offset table at the end of this description.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Cleared |
| OPERR | Cleared |
| OVFL | Cleared |
| UNFL | Cleared |
| DZ | Cleared |
| INEX2 | Refer to inexact result in the appropriate user’s manual. |
| INEX1 | Cleared |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FMOVEM

**Move Multiple Floating-Point Data Registers**

*(MC6888X, MC68040)*

### Operation

`Register List → Destination Source → Register List`

### Assembler Syntax

```asm
FMOVEM.X <list> , <ea>
FMOVEM.X Dn, <ea>
FMOVEM.X <ea> , <list> FMOVEM.X <ea> ,Dn
```

### Attributes

Format = (Extended)

### Description

Moves one or more extended-precision numbers to or from a list of floating-point data registers. No conversion or rounding is performed during this operation, and the floating-point status register is not affected by the instruction. For the MC68881, this instruction does not cause pending exceptions (other than protocol violations) to be reported. Furthermore, a write to the floating-point control register exception enable byte or the floating-point status register exception status byte connot generate a new exception, despite the value written. Any combination of the eight floating-point data registers can be transferred, with the selected registers specified by a user- supplied mask. This mask is an 8-bit number, where each bit corresponds to one register; if a bit is set in the mask, that register is moved. The register select mask may be specified as a static value contained in the instruction or a dynamic value in the least significant eight bits of an integer data register (the remaining bits of the register are ignored). FMOVEM allows three types of addressing modes: the control modes, the predecrement mode, or the postincrement mode. If the effective address is one of the control addressing modes, the registers are transferred between the processor and memory starting at the specified address and up through higher addresses. The order of the transfer is from FP0 – FP7. M68000 FAMILY PROGRAMMER’S REFERENCE MANUAL FMOVEM FMOVEM Move Multiple Floating-Point Data Registers (MC6888X, MC68040) If the effective address is the predecrement mode, only a register-to-memory operation is allowed. The registers are stored starting at the address contained in the address register and down through lower addresses. Before each register is stored, the address register is decremented by 12 (the size of an extended-precision number in memory) and the floating-point data register is then stored at the resultant address. When the operation is complete, the address register points to the image of the last floating-point data register stored. The order of the transfer is from FP7 – FP0. If the effective address is the postincrement mode, only a memory-to-register operation is allowed. The registers are loaded starting at the specified address and up through higher addresses. After each register is stored, the address register is incremented by 12 (the size of an extended-precision number in memory). When the operation is complete, the address register points to the byte immediately following the image of the last floating-point data register loaded. The order of the transfer is the same as for the control addressing modes: FP0 – FP7.

### Applicable Processors

MC6888X, MC68040 (directly supported in hardware)

---

## FMOVEM

**Move Multiple Floating-Point Control Registers**

*(MC6888X, MC68040)*

### Operation

`Register List → Destination Source → Register List`

### Assembler Syntax

```asm
FMOVEM.L <list> , <ea>
FMOVEM.L <ea> , <list>
```

### Attributes

Size = (Long)

### Description

Moves one or more 32-bit values into or out of the specified system control registers. Any combination of the three system control registers may be specified. The registers are always moved in the same order, regardless of the addressing mode used; the floating-point control register is moved first, followed by the floating-point status register, and the floating-point instruction address register is moved last. If a register is not selected for the transfer, the relative order of the transfer of the other registers is the same. The first register is transferred between the floating-point unit and the specified address, with successive registers located up through higher addresses. For the MC68881, this instruction does not cause pending exceptions (other than protocol violations) to be reported. Furthermore, a write to the floating-point control register exception enable byte or the floating-point status register exception status byte connot generate a new exception, despite the value written. When more than one register is moved, the memory or memory- alterable addressing modes can be used as shown in the addressing mode tables. If the addressing mode is predecrement, the address register is first decremented by the total size of the register images to be moved (i.e., four times the number of registers), and then the registers are transferred starting at the resultant address. For the postincrement addressing mode, the selected registers are transferred to or from the specified address, and then the address register is incremented by the total size of the register images transferred. If a single system control register is selected, the data register direct addressing mode may be used; if the only register selected is the floating-point instruction address register, then the address register direct addressing mode is allowed. Note that if a single register is selected, the opcode generated is the same as for the FMOVE single system control register instruction. M68000 FAMILY PROGRAMMER’S REFERENCE MANUAL FMOVEM FMOVEM Move Multiple Floating-Point Control Registers (MC6888X, MC68040)

### Applicable Processors

MC6888X, MC68040 (directly supported in hardware)

---

## FMUL

**Floating-Point Multiply**

*(MC6888X, MC68040)*

### Operation

`Source x FPn → FPn`

### Assembler Syntax

```asm
FMUL. <fmt> <ea> ,FPn
FMUL.X FPm,FPn
*FrMUL <fmt> <ea> ,FPn
*FrMUL.X FPm,FPn
where r is rounding precision, S or D
*Supported by MC68040 only
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and multiplies that number by the number in the destination floating-point data register. Stores the result in the destination floating-point data register. FMUL will round the result to the precision selected in the floating-point control register. FSMUL and FDMUL will round the result to single or double precision, respectively, regardless of the rounding precision selected in the floating-point control register.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers. Set for 0 x infinity; cleared otherwise. |
| OPERR | Refer to exception processing in the appropriate user’s manual. |
| OVFL | Refer to exception processing in the appropriate user’s manual. |
| UNFL | Cleared |
| DZ | Refer to exception processing in the appropriate user’s manual. |
| INEX2 | If <fmt> is packed, refer to exception processing in the appropriate user’s manual; cleared otherwise. |
| INEX1 |  |

### Opmode

```
0100011 FMUL
```

### Applicable Processors

MC6888X, MC68040 (directly supported in hardware)

---

## FNEG

**Floating-Point Negate**

*(MC6888X, MC68040)*

### Operation

`– (Source) → FPn`

### Assembler Syntax

```asm
FNEG. <fmt> <ea> ,FPn
FNEG.X FPm,FPn
FNEG.X FPn
*FrNEG. <fmt> <ea> ,FPn
*FrNEG.X FPm,FPn
*FrNEG.X FPn
where r is rounding precision, S or D
*Supported by MC68040 only
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and inverts the sign of the mantissa. Stores the result in the destination floating-point data register. FNEG will round the result to the precision selected in the floating-point control register. FSNEG and FDNEG will round the result to single or double precision, respectively, regardless of the rounding precision selected in the floating-point control register.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers. |
| OPERR | Cleared |
| OVFL | Cleared If source is an extended-precision denormalized number, refer to exception processing in the appropriate user’s manual; cleared otherwise. |
| UNFL | Cleared |
| DZ | Cleared |
| INEX2 | If <fmt> is packed, refer to exception processing in the appropriate user’s manual; cleared otherwise. |
| INEX1 |  |

### Opmode

```
0011010 FNEG
1011010 FSNEG
1011110 FDNEG  -- Rounding precision specified by the floating-point
```

### Applicable Processors

MC6888X, MC68040 (directly supported in hardware)

---

## FNOP

**M = 0 and the source and destination fields are equal, then the input operand is taken from the specified floating-point data register and the result is written into the same register. If the single register syntax is used, Motorola assemblers set the source and destination fields to the same value. Opmode field—Specifies the instruction and rounding precision. 0011010 FNEG 1011010 FSNEG 1011110 FDNEG Rounding precision specified by the floating-point control register. Single-precision rounding specified. Double-precision rounding specified. M68000 FAMILY PROGRAMMER’S REFERENCE MANUAL No Operation**

*(MC6888X, MC68040)*

### Operation

`None`

### Assembler Syntax

```asm
FNOP
```

### Attributes

Unsized

### Description

This instruction does not perform any explicit operation. However, it is useful to force synchronization of the floating-point unit with an integer unit or to force processing of pending exceptions. For most floating-point instructions, the integer unit is allowed to continue with the execution of the next instruction once the floating-point unit has any operands needed for an operation, thus supporting concurrent execution of floating-point and integer instructions. The FNOP instruction synchronizes the floating-point unit and the integer unit by causing the integer unit to wait until all previous floating-point instructions have completed. Execution of FNOP also forces any exceptions pending from the execution of a previous floating-point instruction to be processed as a preinstruction exception. The MC68882 may not wait to begin execution of another floating-point instruction until it has completed execution of the current instruction. The FNOP instruction synchronizes the coprocessor and microprocessor unit by causing the microprocessor unit to wait until the current instruction (or both instructions) have completed. The FNOP instruction also forces the processing of exceptions pending from the execution of previous instructions. This is also inherent in the way that the floating-point coprocessor utilizes the M68000 family coprocessor interface. Once the floating-point coprocessor has received the input operand for an arithmetic instruction, it always releases the main processor to execute the next instruction (regardless of whether or not concurrent execution is prevented for the instruction due to tracing) without reporting the exception during the execution of that instruction. Then, when the main processor attempts to initiate the execution of the next floating-point coprocessor instruction, a preinstruction exception may be reported to initiate exception processing for an exception that occurred during a previous instruction. By using the FNOP instruction, the user can force any pending exceptions to be processed without performing any other operations.

### Applicable Processors

MC6888X, MC68040 (directly supported in hardware)

---

## FREM

**IEEE Remainder**

*(MC6888X, M68040FPSP)*

### Operation

`IEEE Remainder of (FPn ÷ Source) → FPn`

### Assembler Syntax

```asm
FREM. <fmt> <ea> ,FPn
FREM.X FPm,FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and calculates the modulo remainder of the number in the destination floating-point data register, using the source operand as the modulus. Stores the result in the destination floating-point data register and stores the sign and seven least significant bits of the quotient in the floating-point status register quotient byte (the quotient is the result of FPn ÷ Source). The IEEE remainder function is defined as: FPn – (Source x N) where N = INT (FPn ÷ Source) in the round-to-nearest mode. The FREM function is not defined for a source operand equal to zero or for a destination operand equal to infinity. Note that this function is not the same as the FMOD instruction, which uses the round-to-zero mode and thus returns a remainder that is different from the remainder required by the IEEE Specification for Binary Floating-Point Arithmetic.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Loaded with the sign and least significant seven bits of the qotient (FPn ÷ Source). The sign of the quotient is the exclusive-OR of the sign bits of the source and destination operands.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers. |
| OPERR | Set if the source is zero or the destination is infinity; cleared otherwise. |
| OVFL | Cleared |
| UNFL | Refer to underflow in the appropriate user’s manual. |
| DZ | Cleared |
| INEX2 | Cleared |
| INEX1 | If <fmt> is packed, refer to inexact result on decimal input in the appropriate user’s manual; cleared otherwise. |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FSCALE

**Scale Exponent**

*(MC6888X, M68040FPSP)*

### Operation

`FPn x INT(2Source) → FPn`

### Assembler Syntax

```asm
FSCALE. <fmt> <ea> ,FPn
FSCALE.X FPm,FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to an integer (if necessary) and adds that integer to the destination exponent. Stores the result in the destination floating-point data register. This function has the effect of multiplying the destination by 2Source, but is much faster than a multiply operation when the source is an integer value. The floating-point coprocessor assumes that the scale factor is an integer value before the operation is executed. If not, the value is chopped (i.e., rounded using the roundto-zero mode) to an integer before it is added to the exponent. When the absolute value of the source operand is ≥ 214, an overflow or underflow always results.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers. |
| OPERR | Set if the source operand is ± infinity; cleared otherwise. |
| OVFL | Refer to overflow in the appropriate user’s manual. |
| UNFL | Refer to underflow in the appropriate user’s manual. |
| DZ | Cleared |
| INEX2 | Cleared |
| INEX1 | If <fmt> is packed, refer to inexact result on decimal input in the appropriate user’s manual; cleared otherwise. |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FScc

**R/M field—Specifies the source operand address mode. 0 — The operation is register to register. 1 — The operation is <ea> to register. Source Specifier field—Specifies the source register or data format. If R/M = 0, specifies the source floating-point data register. If R/M = 1, specifies the source data format: 000 — Long-Word Integer (L) 001 — Single-Precision Real (S) 010 — Extended-Precision Real (X) 011 — Packed-Decimal Real (P) 100 — Word Integer (W) 101 — Double-Precision Real (D) 110 — Byte Integer (B) Destination Register field—Specifies the destination floating-point data register. M68000 FAMILY PROGRAMMER’S REFERENCE MANUAL**

### Operation

`(MC6888X, MC68040) FScc If (Condition True) Then 1s → Destination Else 0s → Destination`

### Assembler Syntax

```asm
FScc. <size> <ea>
```

### Attributes

Size = (Byte)

### Description

If the specified floating-point condition is true, sets the byte integer operand at the destination to TRUE (all ones); otherwise, sets the byte to FALSE (all zeros). The conditional specifier cc may select any one of the 32 floating-point conditional tests as described in Table 3-23 Floating-Point Conditional Tests.

### Condition Codes

Not affected.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN |  |
| SNAN |  |
| OPERR |  |
| OVFL |  |
| UNFL |  |
| DZ |  |
| INEX2 |  |
| INEX1 |  |

### Applicable Processors

MC6888X

---

## FSGLDIV

**Single-Precision Divide**

*(MC6888X, MC68040)*

### Operation

`FPn ÷ Source → FPn`

### Assembler Syntax

```asm
FSGLDIV. <fmt> <ea> ,FPn
FSGLDIV.X
FPm,FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and divides that number into the number in the destination floating-point data register. Stores the result in the destination floating-point data register, rounded to single precision (despite the current rounding precision). This function is undefined for 0 ÷ 0 and infinity ÷ infinity. Both the source and destination operands are assumed to be representable in the single-precision format. If either operand requires more than 24 bits of mantissa to be accurately represented, the extraneous mantissa bits are trancated prior to the division, hence the accuracy of the result is not guaranteed. Furthermore, the result exponent may exceed the range of single precision, regardless of the rounding precision selected in the floating-point control register mode control byte. Refer to 3.6.1 Underflow, Round, Overflow for more information. The accuracy of the result is not affected by the number of mantissa bits required to represent each input operand since the input operands just change to extended precision. The result mantissa is rounded to single precision, and the result exponent is rounded to extended precision, despite the rounding precision selected in the floating-point control register.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers. Set for 0 ÷ 0 or infinity ÷ infinity. |
| OPERR | Refer to overflow in the appropriate user’s manual. |
| OVFL | Refer to underflow in the appropriate user’s manual. |
| UNFL | Set if the source is zero and the destination is in range; cleared otherwise. |
| DZ | Refer to inexact result in the appropriate user’s manual. |
| INEX2 | If <fmt> is packed, refer to the appropriate user’s manual for inexact result on decimal input; cleared otherwise. |
| INEX1 |  |

### Applicable Processors

MC6888X, MC68040 (directly supported in hardware)

---

## FSGLMUL

**Single-Precision Multiply**

*(MC6888X, MC68040)*

### Operation

`Source x FPn → FPn`

### Assembler Syntax

```asm
FSGLMUL. <fmt> <ea> ,FPn
FSGLMUL.X FPm,FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and multiplies that number by the number in the destination floating-point data register. Stores the result in the destination floating-point data register, rounded to single precision (regardless of the current rounding precision). Both the source and destination operands are assumed to be representable in the single-precision format. If either operand requires more than 24 bits of mantissa to be accurately represented, the extraneous mantissa bits are truncated prior to the multipliction; hence, the accuracy of the result is not guaranteed. Furthermore, the result exponent may exceed the range of single precision, regardless of the rounding precision selected in the floating-point control register mode control byte. Refer to 3.6.1 Underflow, Round, Overflow for more information.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers. |
| OPERR | Set if one operand is zero and the other is infinity; cleared otherwise. |
| OVFL | Refer to overflow in the appropriate user’s manual. |
| UNFL | Refer to underflow in the appropriate user’s manual. |
| DZ | Cleared |
| INEX2 | Refer to inexact result in the appropriate user’s manual. |
| INEX1 | If <fmt> is packed, refer to inexact result on decimal input in the appropriate user’s manual; cleared otherwise. |

### Applicable Processors

MC6888X, MC68040 (directly supported in hardware)

---

## FSIN

**Sine**

*(MC6888X, M68040FPSP)*

### Operation

`Sine of Source → FPn`

### Assembler Syntax

```asm
FSIN. <fmt> <ea> ,FPn
FSIN.X FPm,FPn
FSIN.X FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and calculates the sine of that number. Stores the result in the destination floating-point data register. This function is not defined for source operands of ± infinity. If the source operand is not in the range of [ – 2π... + 2π], the argument is reduced to within that range before the sine is calculated. However, large arguments may lose accuracy during reduction, and very large arguments (greater than approximately 1020) lose all accuracy. The result is in the range of [ – 1... + 1].

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected. M68000 FAMILY PROGRAMMER’S REFERENCE MANUAL FSIN FSIN Sine (MC6888X, M68040FPSP)

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers. |
| OPERR | Set if the source is ± infinity; cleared otherwise. |
| OVFL | Cleared |
| UNFL | Refer to underflow in the appropriate user’s manual. |
| DZ | Cleared |
| INEX2 | Refer to inexact result in the appropriate user’s manual. |
| INEX1 | If <fmt> is packed, refer to inexact result on decimal input in the appropriate user’s manual; cleared otherwise. |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FSINCOS

**Simultaneous Sine and Cosine**

*(MC6888X, M68040FPSP)*

### Operation

`Sine of Source → FPs Cosine of Source → FPc`

### Assembler Syntax

```asm
FSINCOS. <fmt> <ea> ,FPc,FPs
FSINCOS.X FPm,FPc,FPs
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and calculates both the sine and the cosine of that number. Calculates both functions simultaneously; thus, this instruction is significantly faster than performing separate FSIN and FCOS instructions. Loads the sine and cosine results into the destination floating-point data register. Sets the condition code bits according to the sine result. If FPs and FPc are specified to be the same register, the cosine result is first loaded into the register and then is overwritten with the sine result. This function is not defined for source operands of ± infinity. If the source operand is not in the range of [ – 2π... + 2π], the argument is reduced to within that range before the sine and cosine are calculated. However, large arguments may lose accuracy during reduction, and very large arguments (greater than approximately 1020) lose all accuracy. The results are in the range of [ – 1... + 1].

### Condition Codes

Affected as described in 3.6.2 Conditional Testing (for the sine result).

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers. |
| OPERR | Set if the source is ± infinity; cleared otherwise. |
| OVFL | Cleared |
| UNFL | Set if a sine underflow occurs, in which case the cosine result is 1. Cosine cannot underflow. Refer to underflow in the appropriate user’s manual. |
| DZ | Cleared |
| INEX2 | Refer to inexact result in the appropriate user’s manual. |
| INEX1 | If <fmt> is packed, refer to inexact result on decimal input in the appropriate user’s manual; cleared otherwise. |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FSINH

**Hyperbolic Sine**

*(MC6888X, M68040FPSP)*

### Operation

`Hyperbolic Sine of Source → FPn`

### Assembler Syntax

```asm
FSINH. <fmt> <ea> ,FPn
FSINH.X FPm,FPn
FSINH.X FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and calculates the hyperbolic sine of that number. Stores the result in the destination floating-point data register.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN |  |
| SNAN |  |
| OPERR |  |
| OVFL |  |
| UNFL |  |
| DZ |  |
| INEX2 |  |
| INEX1 |  |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FSQRT

**Floating-Point Square Root**

*(MC6888X, MC68040)*

### Operation

`Square Root of Source → FPn`

### Assembler Syntax

```asm
FSQRT. <fmt> <ea> ,FPn
FSQRT.X FPm,FPn
FSQRT.X FPn
*FrSQRT. <fmt> <ea> ,FPn
*FrSQRT FPm,FPn
*FrSQRT FPn
where r is rounding precision, S or D
*Supported by MC68040 only
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and calculates the square root of that number. Stores the result in the destination floating-point data register. This function is not defined for negative operands. FSQRT will round the result to the precision selected in the floating-point control register. FSFSQRT and FDFSQRT will round the result to single or double precision, respectively, regardless of the rounding precision selected in the floating-point control register.Operation Table:

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers. |
| OPERR | Set if the source operand is not zero and is negative; cleared otherwise. |
| OVFL | Cleared |
| UNFL | Cleared |
| DZ | Cleared |
| INEX2 | Refer to exception processing in the appropriate user’s manual. |
| INEX1 | If <fmt> is packed, refer to exception processing in the appropriate user’s manual; cleared otherwise. |

### Opmode

```
0000100 FSQRT  -- Rounding precision specified by the floating-point
```

### Applicable Processors

MC6888X, MC68040 (directly supported in hardware)

---

## FSUB

**Floating-Point Subtract**

*(MC6888X, MC68040)*

### Assembler Syntax

```asm
FSUB. <fmt> <ea> ,FPn
FSUB.X FPm,FPn
*FrSUB. <fmt> <ea> ,FPn
*FrSUB.X FPm,FPn
where r is rounding precision, S or D
*Supported by MC68040 only
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and subtracts that number from the number in the destination floating-point data register. Stores the result in the destination floating-point data register.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers. |
| OPERR | Set if both the source and destination are like-signed infinities; cleared otherwise. |
| OVFL | Refer to exception processing in the appropriate user’s manual. |
| UNFL | Refer to exception processing in the appropriate user’s manual. |
| DZ | Cleared |
| INEX2 | Refer to exception processing in the appropriate user’s manual. |
| INEX1 | If <fmt> is packed, refer to exception processing in the appropriate user’s manual; cleared otherwise. |

### Opmode

```
0101000 FSUB
1101000 FSSUB
1101100 FDSUB  -- Rounding precision specified by the floating-point
```

### Applicable Processors

MC6888X, MC68040 (directly supported in hardware)

---

## FTAN

**Tangent**

*(MC6888X/004SW)*

### Operation

`Tangent of Source → FPn`

### Assembler Syntax

```asm
FTAN. <fmt> <ea> ,FPn
FTAN.X FPm,FPn
FTAN.X FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and calculates the tangent of that number. Stores the result in the destination floating-point data register. This function is not defined for source operands of ± infinity. If the source operand is not in the range of [ – π/2... + π/2], the argument is reduced to within that range before the tangent is calculated. However, large arguments may lose accuracy during reduction, and very large arguments (greater than approximately 1020) lose all accuracy.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN | Cleared |
| SNAN | Refer to 1.6.5 Not-A-Numbers. |
| OPERR | Set if the source is ± infinity; cleared otherwise. |
| OVFL | Refer to overflow in the appropriate user’s manual. |
| UNFL | Refer to underflow in the appropriate user’s manual. |
| DZ | Cleared |
| INEX2 | Refer to inexact result in the appropriate user’s manual. |
| INEX1 | If <fmt> is packed, refer to inexact result on decimal input in the appropriate user’s manual; cleared otherwise. |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FTANH

**Hyperbolic Tangent**

*(MC6888X, M68040FPSP)*

### Operation

`Hyperbolic Tangent of Source → FPn`

### Assembler Syntax

```asm
FTANH. <fmt> <ea> ,FPn
FTANH.X FPm,FPn
FTANH.X FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and calculates the hyperbolic tangent of that number. Stores the result in the destination floating-point data register.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN |  |
| SNAN |  |
| OPERR |  |
| OVFL |  |
| UNFL |  |
| DZ |  |
| INEX2 |  |
| INEX1 |  |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FTENTOX

**10x**

*(MC6888X, M68040FPSP)*

### Operation

`10Source → FPn`

### Assembler Syntax

```asm
FTENTOX. <fmt> <ea> ,FPn
FTENTOX.X FPm,FPn
FTENTOX.X FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and calculates 10 to the power of that number. Stores the result in the destination floating-point data register.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN |  |
| SNAN |  |
| OPERR |  |
| OVFL |  |
| UNFL |  |
| DZ |  |
| INEX2 |  |
| INEX1 |  |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FTRAPcc

**If R/M = 1, specifies the source data format: 000 — Long-Word Integer (L) 001 — Single-Precision Real (S) 010 — Extended-Precision Real (X) 011 — Packed-Decimal Real (P) 100 — Word Integer (W) 101 — Double-Precision Real (D) 110 — Byte Integer (B) Destination Register field—Specifies the destination floating-point data register. If R/ M = 0 and the source and destination fields are equal, the input operand is taken from the specified floating-point data register, and the result is written into the same register. If the single register syntax is used, Motorola assemblers set the source and destination fields to the same value. M68000 FAMILY PROGRAMMER’S REFERENCE MANUAL Trap on Floating-Point Condition**

*(MC6888X, MC68040)*

### Operation

`If Condition True Then TRAP`

### Assembler Syntax

```asm
FTRAPcc
FTRAPcc.W # <data>
FTRAPcc.L # <data>
```

### Attributes

Size = (Word, Long)

### Description

If the selected condition is true, the processor initiates exception processing. A vector number is generated to reference the TRAPcc exception vector. The stacked program counter points to the next instruction. If the selected condition is not true, there is no operation performed and execution continues with the next instruction in sequence. The immediate data operand is placed in the word(s) following the conditional predicate word and is available for user definition for use within the trap handler. The conditional specifier cc selects one of the 32 conditional tests defined in 3.6.2 Conditional Testing.

### Condition Codes

Not affected.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN |  |
| SNAN |  |
| OPERR |  |
| OVFL |  |
| UNFL |  |
| DZ |  |
| INEX2 |  |
| INEX1 |  |

### Applicable Processors

MC6888X, MC68040 (directly supported in hardware)

---

## FTST

**Test Floating-Point Operand**

*(MC6888X, MC68040)*

### Operation

`Condition Codes for Operand → FPCC`

### Assembler Syntax

```asm
FTST. <fmt> <ea>
FTST.X FPm
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and sets the condition code bits according to the data type of the result.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN |  |
| SNAN |  |
| OPERR |  |
| OVFL |  |
| UNFL |  |
| DZ |  |
| INEX2 |  |
| INEX1 |  |

### Applicable Processors

MC6888X, MC68040 (directly supported in hardware)

---

## FTWOTOX

**2x**

*(MC6888X, M68040FPSP)*

### Operation

`2Source → FPn`

### Assembler Syntax

```asm
FTWOTOX. <fmt> <ea> ,FPn
FTWOTOX.X FPm,FPn
FTWOTOX.X FPn
```

### Attributes

Format = (Byte, Word, Long, Single, Double, Extended, Packed)

### Description

Converts the source operand to extended precision (if necessary) and calculates two to the power of that number. Stores the result in the destination floating-point data register.

### Condition Codes

Affected as described in 3.6.2 Conditional Testing.

### Quotient Byte

Not affected.

### Exception Byte

| Exception | Description |
|-----------|-------------|
| BSUN |  |
| SNAN |  |
| OPERR |  |
| OVFL |  |
| UNFL |  |
| DZ |  |
| INEX2 |  |
| INEX1 |  |

### Applicable Processors

MC6888X (directly supported), MC68040 (software emulated via FPSP)

---

## FMOVECR ROM Constant Table

| Offset | Constant |
|--------|----------|
| $00 | pi |
| $0B | Log10(2) |
| $0C | e |
| $0D | Log2(e) |
| $0E | Log10(e) |
| $0F | 0.0 |
| $30 | ln(2) |
| $31 | ln(10) |
| $32 | 10^0 (1.0) |
| $33 | 10^1 |
| $34 | 10^2 |
| $35 | 10^4 |
| $36 | 10^8 |
| $37 | 10^16 |
| $38 | 10^32 |
| $39 | 10^64 |
| $3A | 10^128 |
| $3B | 10^256 |
| $3C | 10^512 |
| $3D | 10^1024 |
| $3E | 10^2048 |
| $3F | 10^4096 |

Offsets not listed above are reserved for Motorola internal use. Undefined offsets yield 0.0 in the MC68040 FPSP.
