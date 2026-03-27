<!-- Converted from Motorola M68000 Family Programmer's Reference Manual (1992) -->

# Appendix A: Processor Instruction Summary

Instruction x processor matrix -- which instructions are available on which CPUs.

This appendix provides a quick reference of the M68000 family instructions. The organization is by processors and their addressing modes. All references to the MC68000, MC68020, and MC68030 include references to the corresponding embedded controllers, MC68EC000, MC68EC020, and MC68EC030. All references to the MC68040 include the MC68LC040 and MC68EC040. This referencing applies throughout this section unless otherwise specified.

## Table A-1: M68000 Family Instruction Set and Processor Cross-Reference

| Mnemonic | 68000 | 68008 | 68010 | 68020 | 68030 | 68040 | 68881/68882 | 68851 | CPU32 |
|----------|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----------:|:-----:|:-----:|
| ABCD | X | X | X | X | X | X | | | X |
| ADD | X | X | X | X | X | X | | | X |
| ADDA | X | X | X | X | X | X | | | X |
| ADDI | X | X | X | X | X | X | | | X |
| ADDQ | X | X | X | X | X | X | | | X |
| ADDX | X | X | X | X | X | X | | | X |
| AND | X | X | X | X | X | X | | | X |
| ANDI | X | X | X | X | X | X | | | X |
| ANDI to CCR | X | X | X | X | X | X | | | X |
| ANDI to SR^1 | X | X | X | X | X | X | | | X |
| ASL, ASR | X | X | X | X | X | X | | | X |
| Bcc | X | X | X | X | X | X | | | X |
| BCHG | X | X | X | X | X | X | | | X |
| BCLR | X | X | X | X | X | X | | | X |
| BFCHG | | | | X | X | X | | | |
| BFCLR | | | | X | X | X | | | |
| BFEXTS | | | | X | X | X | | | |
| BFEXTU | | | | X | X | X | | | |
| BFFFO | | | | X | X | X | | | |
| BFINS | | | | X | X | X | | | |
| BFSET | | | | X | X | X | | | |
| BFTST | | | | X | X | X | | | |
| BGND | | | | | | | | | X |
| BKPT | | | X | X | X | X | | | X |
| BRA | X | X | X | X | X | X | | | X |
| BSET | X | X | X | X | X | X | | | X |
| BSR | X | X | X | X | X | X | | | X |
| BTST | X | X | X | X | X | X | | | X |
| CALLM | | | | X | | | | | |
| CAS, CAS2 | | | | X | X | X | | | |
| CHK | X | X | X | X | X | X | | | X |
| CHK2 | | | | X | X | X | | | X |
| CINV^1 | | | | | | X | | | |
| CLR | X | X | X | X | X | X | | | X |
| CMP | X | X | X | X | X | X | | | X |
| CMPA | X | X | X | X | X | X | | | X |
| CMPI | X | X | X | X | X | X | | | X |
| CMPM | X | X | X | X | X | X | | | X |
| CMP2 | | | | X | X | X | | | X |
| cpBcc | | | | X | X | | | | |
| cpDBcc | | | | X | X | | | | |
| cpGEN | | | | X | X | | | | |
| cpRESTORE^1 | | | | X | X | | | | |
| cpSAVE^1 | | | | X | X | | | | |
| cpScc | | | | X | X | | | | |
| cpTRAPcc | | | | X | X | | | | |
| CPUSH^1 | | | | | | X | | | |
| DBcc | X | X | X | X | X | X | | | X |
| DIVS | X | X | X | X | X | X | | | X |
| DIVSL | | | | X | X | X | | | X |
| DIVU | X | X | X | X | X | X | | | X |
| DIVUL | | | | X | X | X | | | X |
| EOR | X | X | X | X | X | X | | | X |
| EORI | X | X | X | X | X | X | | | X |
| EORI to CCR | X | X | X | X | X | X | | | X |
| EORI to SR^1 | X | X | X | X | X | X | | | X |
| EXG | X | X | X | X | X | X | | | X |
| EXT | X | X | X | X | X | X | | | X |
| EXTB | | | | X | X | X | | | X |
| FABS | | | | | | X^2 | X | | |
| FSABS, FDABS | | | | | | X^2 | | | |
| FACOS | | | | | | X^(2,3) | X | | |
| FADD | | | | | | X^2 | X | | |
| FSADD, FDADD | | | | | | X^2 | | | |
| FASIN | | | | | | X^(2,3) | X | | |
| FATAN | | | | | | X^(2,3) | X | | |
| FATANH | | | | | | X^(2,3) | X | | |
| FBcc | | | | | | X^2 | X | | |
| FCMP | | | | | | X^2 | X | | |
| FCOS | | | | | | X^(2,3) | X | | |
| FCOSH | | | | | | X^(2,3) | X | | |
| FDBcc | | | | | | X^2 | X | | |
| FDIV | | | | | | X^2 | X | | |
| FSDIV, FDDIV | | | | | | X^2 | | | |
| FETOX | | | | | | X^(2,3) | X | | |
| FETOXM1 | | | | | | X^(2,3) | X | | |
| FGETEXP | | | | | | X^(2,3) | X | | |
| FGETMAN | | | | | | X^(2,3) | X | | |
| FINT | | | | | | X^(2,3) | X | | |
| FINTRZ | | | | | | X^(2,3) | X | | |
| FLOG10 | | | | | | X^(2,3) | X | | |
| FLOG2 | | | | | | X^(2,3) | X | | |
| FLOGN | | | | | | X^(2,3) | X | | |
| FLOGNP1 | | | | | | X^(2,3) | X | | |
| FMOD | | | | | | X^(2,3) | X | | |
| FMOVE | | | | | | X^2 | X | | |
| FSMOVE, FDMOVE | | | | | | X^2 | | | |
| FMOVECR | | | | | | X^(2,3) | X | | |
| FMOVEM | | | | | | X^2 | X | | |
| FMUL | | | | | | X^2 | X | | |
| FSMUL, FDMUL | | | | | | X^2 | | | |
| FNEG | | | | | | X^2 | X | | |
| FSNEG, FDNEG | | | | | | X^2 | | | |
| FNOP | | | | | | X^2 | X | | |
| FREM | | | | | | X^(2,3) | X | | |
| FRESTORE^1 | | | | | | X^2 | X | | |
| FSAVE^1 | | | | | | X^2 | X | | |
| FSCALE | | | | | | X^(2,3) | X | | |
| FScc | | | | | | X^2 | X | | |
| FSGLDIV | | | | | | X^(2,3) | X | | |
| FSGLMUL | | | | | | X^(2,3) | X | | |
| FSIN | | | | | | X^(2,3) | X | | |
| FSINCOS | | | | | | X^(2,3) | X | | |
| FSINH | | | | | | X^(2,3) | X | | |
| FSQRT | | | | | | X^2 | X | | |
| FSSQRT, FDSQRT | | | | | | X^2 | | | |
| FSUB | | | | | | X^2 | X | | |
| FSSUB, FDSUB | | | | | | X^2 | | | |
| FTAN | | | | | | X^(2,3) | X | | |
| FTANH | | | | | | X^(2,3) | X | | |
| FTENTOX | | | | | | X^(2,3) | X | | |
| FTRAPcc | | | | | | X^(2,3) | X | | |
| FTST | | | | | | X^2 | X | | |
| FTWOTOX | | | | | | X^(2,3) | X | | |
| ILLEGAL | X | X | X | X | X | X | | | X |
| JMP | X | X | X | X | X | X | | | X |
| JSR | X | X | X | X | X | X | | | X |
| LEA | X | X | X | X | X | X | | | X |
| LINK | X | X | X | X | X | X | | | X |
| LPSTOP | | | | | | | | | X |
| LSL, LSR | X | X | X | X | X | X | | | X |
| MOVE | X | X | X | X | X | X | | | X |
| MOVEA | X | X | X | X | X | X | | | X |
| MOVE from CCR | | | X | X | X | X | | | X |
| MOVE to CCR | X | X | X | X | X | X | | | X |
| MOVE from SR^(1,4) | X | X | X | X | X | X | | | X |
| MOVE to SR^1 | X | X | X | X | X | X | | | X |
| MOVE USP^1 | X | X | X | X | X | X | | | X |
| MOVE16 | | | | | | X | | | |
| MOVEC^1 | | | X | X | X | X | | | X |
| MOVEM | X | X | X | X | X | X | | | X |
| MOVEP | X | X | X | X | X | X | | | X |
| MOVEQ | X | X | X | X | X | X | | | X |
| MOVES^1 | | | X | X | X | X | | | X |
| MULS | X | X | X | X | X | X | | | X |
| MULU | X | X | X | X | X | X | | | X |
| NBCD | X | X | X | X | X | X | | | X |
| NEG | X | X | X | X | X | X | | | X |
| NEGX | X | X | X | X | X | X | | | X |
| NOP | X | X | X | X | X | X | | | X |
| NOT | X | X | X | X | X | X | | | X |
| OR | X | X | X | X | X | X | | | X |
| ORI | X | X | X | X | X | X | | | X |
| ORI to CCR | X | X | X | X | X | X | | | X |
| ORI to SR^1 | X | X | X | X | X | X | | | X |
| PACK | | | | X | X | X | | | |
| PBcc^1 | | | | | | | | X | |
| PDBcc^1 | | | | | | | | X | |
| PEA | X | X | X | X | X | X | | | X |
| PFLUSH^1 | | | | | X^5 | X | | X | |
| PFLUSHA^1 | | | | | X^5 | X | | X | |
| PFLUSHR^1 | | | | | | | | X | |
| PFLUSHS^1 | | | | | | | | X | |
| PLOAD^1 | | | | | X^5 | | | X | |
| PMOVE^1 | | | | | X | | | X | |
| PRESTORE^1 | | | | | | | | X | |
| PSAVE^1 | | | | | | | | X | |
| PScc^1 | | | | | | | | X | |
| PTEST^1 | | | | | X | X | | X | |
| PTRAPcc^1 | | | | | | | | X | |
| PVALID^1 | | | | | | | | X | |
| RESET^1 | X | X | X | X | X | X | | | X |
| ROL, ROR | X | X | X | X | X | X | | | X |
| ROXL, ROXR | X | X | X | X | X | X | | | X |
| RTD | | | X | X | X | X | | | X |
| RTE^1 | X | X | X | X | X | X | | | X |
| RTM | | | | X | | | | | |
| RTR | X | X | X | X | X | X | | | X |
| RTS | X | X | X | X | X | X | | | X |
| SBCD | X | X | X | X | X | X | | | X |
| Scc | X | X | X | X | X | X | | | X |
| STOP^1 | X | X | X | X | X | X | | | X |
| SUB | X | X | X | X | X | X | | | X |
| SUBA | X | X | X | X | X | X | | | X |
| SUBI | X | X | X | X | X | X | | | X |
| SUBQ | X | X | X | X | X | X | | | X |
| SUBX | X | X | X | X | X | X | | | X |
| SWAP | X | X | X | X | X | X | | | X |
| TAS | X | X | X | X | X | X | | | X |
| TBLS, TBLSN | | | | | | | | | X |
| TBLU, TBLUN | | | | | | | | | X |
| TRAP | X | X | X | X | X | X | | | X |
| TRAPcc | | | | X | X | X | | | X |
| TRAPV | X | X | X | X | X | X | | | X |
| TST | X | X | X | X | X | X | | | X |
| UNLK | X | X | X | X | X | X | | | X |
| UNPK | | | | X | X | X | | | |

**NOTES:**
1. Privileged (Supervisor) Instruction.
2. Not applicable to MC68EC040 and MC68LC040.
3. These instructions are software supported on the MC68040.
4. This instruction is not privileged for the MC68000 and MC68008.
5. Not applicable to MC68EC030.

## Table A-2: M68000 Family Instruction Set

| Mnemonic | Description |
|----------|-------------|
| ABCD | Add Decimal with Extend |
| ADD | Add |
| ADDA | Add Address |
| ADDI | Add Immediate |
| ADDQ | Add Quick |
| ADDX | Add with Extend |
| AND | Logical AND |
| ANDI | Logical AND Immediate |
| ANDI to CCR | AND Immediate to Condition Code Register |
| ANDI to SR | AND Immediate to Status Register |
| ASL, ASR | Arithmetic Shift Left and Right |
| Bcc | Branch Conditionally |
| BCHG | Test Bit and Change |
| BCLR | Test Bit and Clear |
| BFCHG | Test Bit Field and Change |
| BFCLR | Test Bit Field and Clear |
| BFEXTS | Signed Bit Field Extract |
| BFEXTU | Unsigned Bit Field Extract |
| BFFFO | Bit Field Find First One |
| BFINS | Bit Field Insert |
| BFSET | Test Bit Field and Set |
| BFTST | Test Bit Field |
| BGND | Enter Background Mode |
| BKPT | Breakpoint |
| BRA | Branch |
| BSET | Test Bit and Set |
| BSR | Branch to Subroutine |
| BTST | Test Bit |
| CALLM | CALL Module |
| CAS | Compare and Swap Operands |
| CAS2 | Compare and Swap Dual Operands |
| CHK | Check Register Against Bound |
| CHK2 | Check Register Against Upper and Lower Bounds |
| CINV | Invalidate Cache Entries |
| CLR | Clear |
| CMP | Compare |
| CMPA | Compare Address |
| CMPI | Compare Immediate |
| CMPM | Compare Memory to Memory |
| CMP2 | Compare Register Against Upper and Lower Bounds |
| cpBcc | Branch on Coprocessor Condition |
| cpDBcc | Test Coprocessor Condition Decrement and Branch |
| cpGEN | Coprocessor General Function |
| cpRESTORE | Coprocessor Restore Function |
| cpSAVE | Coprocessor Save Function |
| cpScc | Set on Coprocessor Condition |
| cpTRAPcc | Trap on Coprocessor Condition |
| CPUSH | Push then Invalidate Cache Entries |
| DBcc | Test Condition, Decrement and Branch |
| DIVS, DIVSL | Signed Divide |
| DIVU, DIVUL | Unsigned Divide |
| EOR | Logical Exclusive-OR |
| EORI | Logical Exclusive-OR Immediate |
| EORI to CCR | Exclusive-OR Immediate to Condition Code Register |
| EORI to SR | Exclusive-OR Immediate to Status Register |
| EXG | Exchange Registers |
| EXT, EXTB | Sign Extend |
| FABS | Floating-Point Absolute Value |
| FSABS, FDABS | Floating-Point Absolute Value (Single/Double Precision) |
| FACOS | Floating-Point Arc Cosine |
| FADD | Floating-Point Add |
| FSADD, FDADD | Floating-Point Add (Single/Double Precision) |
| FASIN | Floating-Point Arc Sine |
| FATAN | Floating-Point Arc Tangent |
| FATANH | Floating-Point Hyperbolic Arc Tangent |
| FBcc | Floating-Point Branch |
| FCMP | Floating-Point Compare |
| FCOS | Floating-Point Cosine |
| FCOSH | Floating-Point Hyperbolic Cosine |
| FDBcc | Floating-Point Decrement and Branch |
| FDIV | Floating-Point Divide |
| FSDIV, FDDIV | Floating-Point Divide (Single/Double Precision) |
| FETOX | Floating-Point e^x |
| FETOXM1 | Floating-Point e^x - 1 |
| FGETEXP | Floating-Point Get Exponent |
| FGETMAN | Floating-Point Get Mantissa |
| FINT | Floating-Point Integer Part |
| FINTRZ | Floating-Point Integer Part, Round-to-Zero |
| FLOG10 | Floating-Point Log10 |
| FLOG2 | Floating-Point Log2 |
| FLOGN | Floating-Point Loge |
| FLOGNP1 | Floating-Point Loge (x + 1) |
| FMOD | Floating-Point Modulo Remainder |
| FMOVE | Move Floating-Point Register |
| FSMOVE, FDMOVE | Move Floating-Point Register (Single/Double Precision) |
| FMOVECR | Move Constant ROM |
| FMOVEM | Move Multiple Floating-Point Registers |
| FMUL | Floating-Point Multiply |
| FSMUL, FDMUL | Floating-Point Multiply (Single/Double Precision) |
| FNEG | Floating-Point Negate |
| FSNEG, FDNEG | Floating-Point Negate (Single/Double Precision) |
| FNOP | Floating-Point No Operation |
| FREM | IEEE Remainder |
| FRESTORE | Restore Floating-Point Internal State |
| FSAVE | Save Floating-Point Internal State |
| FSCALE | Floating-Point Scale Exponent |
| FScc | Floating-Point Set According to Condition |
| FSGLDIV | Single-Precision Divide |
| FSGLMUL | Single-Precision Multiply |
| FSIN | Sine |
| FSINCOS | Simultaneous Sine and Cosine |
| FSINH | Hyperbolic Sine |
| FSQRT | Floating-Point Square Root |
| FSSQRT, FDSQRT | Floating-Point Square Root (Single/Double Precision) |
| FSUB | Floating-Point Subtract |
| FSSUB, FDSUB | Floating-Point Subtract (Single/Double Precision) |
| FTAN | Tangent |
| FTANH | Hyperbolic Tangent |
| FTENTOX | Floating-Point 10^x |
| FTRAPcc | Floating-Point Trap On Condition |
| FTST | Floating-Point Test |
| FTWOTOX | Floating-Point 2^x |
| ILLEGAL | Take Illegal Instruction Trap |
| JMP | Jump |
| JSR | Jump to Subroutine |
| LEA | Load Effective Address |
| LINK | Link and Allocate |
| LPSTOP | Low-Power Stop |
| LSL, LSR | Logical Shift Left and Right |
| MOVE | Move |
| MOVEA | Move Address |
| MOVE from CCR | Move from Condition Code Register |
| MOVE from SR | Move from Status Register |
| MOVE to CCR | Move to Condition Code Register |
| MOVE to SR | Move to Status Register |
| MOVE USP | Move User Stack Pointer |
| MOVE16 | 16-Byte Block Move |
| MOVEC | Move Control Register |
| MOVEM | Move Multiple Registers |
| MOVEP | Move Peripheral |
| MOVEQ | Move Quick |
| MOVES | Move Alternate Address Space |
| MULS | Signed Multiply |
| MULU | Unsigned Multiply |
| NBCD | Negate Decimal with Extend |
| NEG | Negate |
| NEGX | Negate with Extend |
| NOP | No Operation |
| NOT | Logical Complement |
| OR | Logical Inclusive-OR |
| ORI | Logical Inclusive-OR Immediate |
| ORI to CCR | Inclusive-OR Immediate to Condition Code Register |
| ORI to SR | Inclusive-OR Immediate to Status Register |
| PACK | Pack BCD |
| PBcc | Branch on PMMU Condition |
| PDBcc | Test, Decrement, and Branch on PMMU Condition |
| PEA | Push Effective Address |
| PFLUSH | Flush Entry(ies) in the ATCs |
| PFLUSHA | Flush Entry(ies) in the ATCs |
| PFLUSHR | Flush Entry(ies) in the ATCs and RPT Entries |
| PFLUSHS | Flush Entry(ies) in the ATCs |
| PLOAD | Load an Entry into the ATC |
| PMOVE | Move PMMU Register |
| PRESTORE | PMMU Restore Function |
| PSAVE | PMMU Save Function |
| PScc | Set on PMMU Condition |
| PTEST | Test a Logical Address |
| PTRAPcc | Trap on PMMU Condition |
| PVALID | Validate a Pointer |
| RESET | Reset External Devices |
| ROL, ROR | Rotate Left and Right |
| ROXL, ROXR | Rotate with Extend Left and Right |
| RTD | Return and Deallocate |
| RTE | Return from Exception |
| RTM | Return from Module |
| RTR | Return and Restore |
| RTS | Return from Subroutine |
| SBCD | Subtract Decimal with Extend |
| Scc | Set Conditionally |
| STOP | Stop |
| SUB | Subtract |
| SUBA | Subtract Address |
| SUBI | Subtract Immediate |
| SUBQ | Subtract Quick |
| SUBX | Subtract with Extend |
| SWAP | Swap Register Words |
| TAS | Test Operand and Set |
| TBLS, TBLSN | Signed Table Lookup with Interpolate |
| TBLU, TBLUN | Unsigned Table Lookup with Interpolate |
| TRAP | Trap |
| TRAPcc | Trap Conditionally |
| TRAPV | Trap on Overflow |
| TST | Test Operand |
| UNLK | Unlink |
| UNPK | Unpack BCD |

## A.1 MC68000, MC68008, MC68010 Processors

### A.1.1 MC68000 and MC68008 Instruction Set (Table A-3)

The MC68000 and MC68008 support the following instructions:

ABCD, ADD, ADDA, ADDI, ADDQ, ADDX, AND, ANDI, ANDI to CCR, ANDI to SR, ASL, ASR, Bcc, BCHG, BCLR, BRA, BSET, BSR, BTST, CHK, CLR, CMP, CMPA, CMPI, CMPM, DBcc, DIVS, DIVU, EOR, EORI, EORI to CCR, EORI to SR, EXG, EXT, ILLEGAL, JMP, JSR, LEA, LINK, LSL, LSR, MOVE, MOVEA, MOVE to CCR, MOVE from SR, MOVE to SR, MOVE USP, MOVEM, MOVEP, MOVEQ, MULS, MULU, NBCD, NEG, NEGX, NOP, NOT, OR, ORI, ORI to CCR, ORI to SR, PEA, RESET, ROL, ROR, ROXL, ROXR, RTE, RTR, RTS, SBCD, Scc, STOP, SUB, SUBA, SUBI, SUBQ, SUBX, SWAP, TAS, TRAP, TRAPV, TST, UNLK.

### A.1.2 MC68010 Instruction Set (Table A-4)

The MC68010 adds the following instructions to the MC68000/MC68008 set:

BKPT, MOVE from CCR, MOVEC, MOVES, RTD.

### A.1.3 MC68000, MC68008, MC68010 Addressing Modes (Table A-5)

| Mode | Generation |
|------|-----------|
| Data Register Direct | \<ea\> = Dn |
| Address Register Direct | \<ea\> = An |
| Absolute Short | \<ea\> = (Next Word) |
| Absolute Long | \<ea\> = (Next Two Words) |
| PC Relative with Offset | \<ea\> = (PC) + d16 |
| PC Relative with Index and Offset | \<ea\> = (PC) + d8 |
| Register Indirect | \<ea\> = (An) |
| Postincrement Register Indirect | \<ea\> = (An), An <- An + N |
| Predecrement Register Indirect | An <- An - N, \<ea\> = (An) |
| Register Indirect with Offset | \<ea\> = (An) + d16 |
| Indexed Register Indirect with Offset | \<ea\> = (An) + (Xn) + d8 |
| Immediate | DATA = Next Word(s) |
| Quick Immediate | Inherent Data |
| Implied Register | \<ea\> = SR, USP, SSP, PC, VBR, SFC, DFC |

N = 1 for byte, 2 for word, and 4 for long word. If An is the stack pointer and the operand size is byte, N = 2 to keep the stack pointer on a word boundary.

## A.2 MC68020 Processors

### A.2.1 MC68020 Instruction Set (Table A-6)

The MC68020 adds the following to the MC68010 instruction set:

BFCHG, BFCLR, BFEXTS, BFEXTU, BFFFO, BFINS, BFSET, BFTST, CALLM, CAS, CAS2, CHK2, CMP2, cpBcc, cpDBcc, cpGEN, cpRESTORE, cpSAVE, cpScc, cpTRAPcc, DIVSL, DIVUL, EXTB, PACK, RTM, TRAPcc, UNPK.

### A.2.2 MC68020 Addressing Modes (Table A-7)

| Addressing Mode | Syntax |
|-----------------|--------|
| Data Register Direct | Dn |
| Address Register Direct | An |
| Address Register Indirect | (An) |
| Address Register Indirect with Postincrement | (An)+ |
| Address Register Indirect with Predecrement | -(An) |
| Address Register Indirect with Displacement | (d16,An) |
| Address Register Indirect with Index (8-Bit Displacement) | (d8,An,Xn) |
| Address Register Indirect with Index (Base Displacement) | (bd,An,Xn) |
| Memory Indirect Postindexed | ([bd,An],Xn,od) |
| Memory Indirect Preindexed | ([bd,An,Xn],od) |
| Program Counter Indirect with Displacement | (d16,PC) |
| PC Indirect with Index (8-Bit Displacement) | (d8,PC,Xn) |
| PC Indirect with Index (Base Displacement) | (bd,PC,Xn) |
| PC Memory Indirect Postindexed | ([bd,PC],Xn,od) |
| PC Memory Indirect Preindexed | ([bd,PC,Xn],od) |
| Absolute Short | (xxx).W |
| Absolute Long | (xxx).L |
| Immediate | #\<data\> |

## A.3 MC68030 Processors

### A.3.1 MC68030 Instruction Set (Table A-8)

The MC68030 uses the same instruction set as the MC68020, with the following changes:
- Removes: CALLM, RTM
- Adds: PFLUSH\*, PFLUSHA\*, PLOAD\*, PMOVE, PTEST (\* = Not applicable to MC68EC030)

### A.3.2 MC68030 Addressing Modes (Table A-9)

The MC68030 supports the same 18 addressing modes as the MC68020 (see Table A-7).

## A.4 MC68040 Processors

### A.4.1 MC68040 Instruction Set (Table A-10)

The MC68040 changes from the MC68030 instruction set:
- Removes: CALLM, RTM, cpBcc, cpDBcc, cpGEN, cpRESTORE, cpSAVE, cpScc, cpTRAPcc, PLOAD, PMOVE, PRESTORE, PSAVE
- Adds: CINV, CPUSH, MOVE16, PFLUSH (new encoding), PTEST (new encoding)
- Adds integrated FPU instructions: FABS, FADD, FBcc, FCMP, FDBcc, FDIV, FMOVE, FMOVEM, FMUL, FNEG, FNOP, FRESTORE, FSAVE, FScc, FSQRT, FSUB, FTRAPcc, FTST, and single/double precision variants (FSABS, FDABS, FSADD, FDADD, FSDIV, FDDIV, FSMOVE, FDMOVE, FSMUL, FDMUL, FSNEG, FDNEG, FSSQRT, FDSQRT, FSSUB, FDSUB)
- Software-supported FPU instructions (not in hardware): FACOS, FASIN, FATAN, FATANH, FCOS, FCOSH, FETOX, FETOXM1, FGETEXP, FGETMAN, FINT, FINTRZ, FLOG10, FLOG2, FLOGN, FLOGNP1, FMOD, FMOVECR, FREM, FSCALE, FSGLDIV, FSGLMUL, FSIN, FSINCOS, FSINH, FTAN, FTANH, FTENTOX, FTWOTOX

**NOTES:**
1. Not applicable to the MC68EC040 and MC68LC040.
2. These instructions are software supported.

### A.4.2 MC68040 Addressing Modes (Table A-11)

The MC68040 supports the same 18 addressing modes as the MC68020 (see Table A-7).

## A.5 MC68881/MC68882 Coprocessors

### A.5.1 MC68881/MC68882 Instruction Set (Table A-12)

FABS, FACOS, FADD, FASIN, FATAN, FATANH, FBcc, FCMP, FCOS, FCOSH, FDBcc, FDIV, FETOX, FETOXM1, FGETEXP, FGETMAN, FINT, FINTRZ, FLOG10, FLOG2, FLOGN, FLOGNP1, FMOD, FMOVE, FMOVECR, FMOVEM, FMUL, FNEG, FNOP, FREM, FRESTORE, FSAVE, FSCALE, FScc, FSGLDIV, FSGLMUL, FSIN, FSINCOS, FSINH, FSQRT, FSUB, FTAN, FTANH, FTENTOX, FTRAPcc, FTST, FTWOTOX.

### A.5.2 MC68881/MC68882 Addressing Modes

The MC68881/MC68882 does not perform address calculations. When the floating-point coprocessor instructs the processor to transfer an operand via the coprocessor interface, the processor performs the addressing mode calculation requested in the instruction.

## A.6 MC68851 Coprocessor

### A.6.1 MC68851 Instruction Set (Table A-13)

PBcc, PDBcc, PFLUSH, PFLUSHA, PFLUSHR, PFLUSHS, PLOAD, PMOVE, PRESTORE, PSAVE, PScc, PTEST, PTRAPcc, PVALID.

### A.6.2 MC68851 Addressing Modes

The MC68851 supports the same addressing modes as the MC68020 (see Table A-7).
