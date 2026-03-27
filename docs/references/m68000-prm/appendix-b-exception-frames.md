<!-- Converted from Motorola M68000 Family Programmer's Reference Manual (1992) -->

# Appendix B: Exception Processing Reference

Exception vector assignments and stack frame formats for each processor.

This appendix provides a quick reference for system programmers who are already familiar
with the stack frames. For more detail, please refer to the appropriate user's manual.

## B.1 Exception Vector Assignments for the M68000 Family

Many of these vector assignments are processor specific. For instance, vector 13, the
coprocessor protocol violation vector, only applies to the MC68020, MC68EC020,
MC68030, and MC68EC030. Refer to the appropriate user's manual to determine which
exception type is applicable to a specific processor.

### Table B-1: Exception Vector Assignments

| Vector Number(s) | Vector Offset (Hex) | Assignment |
|-------------------|---------------------|------------|
| 0 | 000 | Reset Initial Interrupt Stack Pointer |
| 1 | 004 | Reset Initial Program Counter |
| 2 | 008 | Access Fault |
| 3 | 00C | Address Error |
| 4 | 010 | Illegal Instruction |
| 5 | 014 | Integer Divide by Zero |
| 6 | 018 | CHK, CHK2 Instruction |
| 7 | 01C | FTRAPcc, TRAPcc, TRAPV Instructions |
| 8 | 020 | Privilege Violation |
| 9 | 024 | Trace |
| 10 | 028 | Line 1010 Emulator (Unimplemented A-Line Opcode) |
| 11 | 02C | Line 1111 Emulator (Unimplemented F-Line Opcode) |
| 12 | 030 | (Unassigned, Reserved) |
| 13 | 034 | Coprocessor Protocol Violation |
| 14 | 038 | Format Error |
| 15 | 03C | Uninitialized Interrupt |
| 16-23 | 040-05C | (Unassigned, Reserved) |
| 24 | 060 | Spurious Interrupt |
| 25 | 064 | Level 1 Interrupt Autovector |
| 26 | 068 | Level 2 Interrupt Autovector |
| 27 | 06C | Level 3 Interrupt Autovector |
| 28 | 070 | Level 4 Interrupt Autovector |
| 29 | 074 | Level 5 Interrupt Autovector |
| 30 | 078 | Level 6 Interrupt Autovector |
| 31 | 07C | Level 7 Interrupt Autovector |
| 32-47 | 080-0BC | TRAP #0-15 Instruction Vectors |
| 48 | 0C0 | FP Branch or Set on Unordered Condition |
| 49 | 0C4 | FP Inexact Result |
| 50 | 0C8 | FP Divide by Zero |
| 51 | 0CC | FP Underflow |
| 52 | 0D0 | FP Operand Error |
| 53 | 0D4 | FP Overflow |
| 54 | 0D8 | FP Signaling NAN |
| 55 | 0DC | FP Unimplemented Data Type (Defined for MC68040) |
| 56 | 0E0 | MMU Configuration Error |
| 57 | 0E4 | MMU Illegal Operation Error |
| 58 | 0E8 | MMU Access Level Violation Error |
| 59-63 | 0EC-0FC | (Unassigned, Reserved) |
| 64-255 | 100-3FC | User Defined Vectors (192) |

## B.2 Exception Stack Frames

### Figure B-1: MC68000 Group 1 and 2 Exception Stack Frame

```
         15                              0
    SP -> +-------------------------------+
          |        STATUS REGISTER        |
          +-------------------------------+
          |     PROGRAM COUNTER HIGH      |
          +-------------------------------+
          |     PROGRAM COUNTER LOW       |
          +-------------------------------+  HIGHER ADDRESS
```

### Figure B-2: MC68000 Bus or Address Error Exception Stack Frame

```
         15        5  4  3  2  1  0
          +--------+-----+---------+
          | R/W|I/N|  FUNCTION CODE |
          +-------------------------------+
          |      ACCESS ADDRESS HIGH      |
          +-------------------------------+
          |      ACCESS ADDRESS LOW       |
          +-------------------------------+
          |     INSTRUCTION REGISTER      |
          +-------------------------------+
          |        STATUS REGISTER        |
          +-------------------------------+
          |     PROGRAM COUNTER HIGH      |
          +-------------------------------+
          |     PROGRAM COUNTER LOW       |
          +-------------------------------+

R/W (READ/WRITE): WRITE = 0, READ = 1.
I/N (INSTRUCTION/NOT): INSTRUCTION = 0, NOT = 1.
```

### Figure B-3: Four-Word Stack Frame, Format $0

```
         15                              0
    SP -> +-------------------------------+
          |        STATUS REGISTER        |
   +$02 -> +-------------------------------+
          |        PROGRAM COUNTER        |
          |          (2 words)            |
   +$06 -> +-------------------------------+
          | 0 0 0 0 |   VECTOR OFFSET     |
          +-------------------------------+
```

### Figure B-4: Throwaway Four-Word Stack Frame, Format $1

```
         15                              0
    SP -> +-------------------------------+
          |        STATUS REGISTER        |
   +$02 -> +-------------------------------+
          |        PROGRAM COUNTER        |
          |          (2 words)            |
   +$06 -> +-------------------------------+
          | 0 0 0 1 |   VECTOR OFFSET     |
          +-------------------------------+
```

### Figure B-5: Six-Word Stack Frame, Format $2

```
         15                              0
    SP -> +-------------------------------+
          |        STATUS REGISTER        |
   +$02 -> +-------------------------------+
          |        PROGRAM COUNTER        |
          |          (2 words)            |
   +$06 -> +-------------------------------+
          | 0 0 1 0 |   VECTOR OFFSET     |
   +$08 -> +-------------------------------+
          |          ADDRESS               |
          |          (2 words)            |
          +-------------------------------+
```

### Figure B-6: MC68040 Floating-Point Post-Instruction Stack Frame, Format $3

```
         15                              0
    SP -> +-------------------------------+
          |        STATUS REGISTER        |
   +$02 -> +-------------------------------+
          |        PROGRAM COUNTER        |
          |          (2 words)            |
   +$06 -> +-------------------------------+
          | 0 0 1 0 |   VECTOR OFFSET     |
   +$08 -> +-------------------------------+
          |       EFFECTIVE ADDRESS        |
          |          (2 words)            |
          +-------------------------------+
```

### Figure B-7: MC68EC040 and MC68LC040 FP Unimplemented Stack Frame, Format $4

```
         15                              0
    SP -> +-------------------------------+
          |        STATUS REGISTER        |
   +$02 -> +-------------------------------+
          |        PROGRAM COUNTER        |
          |          (2 words)            |
   +$06 -> +-------------------------------+
          | 0 1 0 0 |   VECTOR OFFSET     |
   +$08 -> +-------------------------------+
          |       EFFECTIVE ADDRESS (EA)   |
          |          (2 words)            |
   +$0C -> +-------------------------------+
          |  PC OF FAULTED INSTRUCTION     |
          |          (2 words)            |
          +-------------------------------+
```

### Figure B-8: MC68040 Access Error Stack Frame, Format $7

```
         15                              0
    SP -> +-------------------------------+
          |        STATUS REGISTER        |
   +$02 -> +-------------------------------+
          |        PROGRAM COUNTER        |
          |          (2 words)            |
   +$06 -> +-------------------------------+
          | 0 1 1 1 |   VECTOR OFFSET     |
   +$08 -> +-------------------------------+
          |    EFFECTIVE ADDRESS (EA)      |
          |          (2 words)            |
   +$0C -> +-------------------------------+
          |          $00                   |
   +$0E -> +-------------------------------+
          |     SPECIAL STATUS WORD        |
   +$10 -> +-------------------------------+
          | WRITEBACK 3 STATUS (WB3S)      |
   +$12 -> +-------------------------------+
          | WRITEBACK 2 STATUS (WB2S)      |
   +$14 -> +-------------------------------+
          | WRITEBACK 1 STATUS (WB1S)      |
   +$18 -> +-------------------------------+
          |      FAULT ADDRESS (FA)        |
          |          (2 words)            |
   +$1C -> +-------------------------------+
          |   WRITEBACK 3 ADDRESS (WB3A)   |
          |          (2 words)            |
   +$20 -> +-------------------------------+
          |    WRITEBACK 3 DATA (WB3D)     |
          |          (2 words)            |
   +$24 -> +-------------------------------+
          |   WRITEBACK 2 ADDRESS (WB2A)   |
          |          (2 words)            |
   +$28 -> +-------------------------------+
          |    WRITEBACK 2 DATA (WB2D)     |
          |          (2 words)            |
   +$2C -> +-------------------------------+
          |   WRITEBACK 1 ADDRESS (WB1A)   |
          |          (2 words)            |
   +$30 -> +-------------------------------+
          | WB1D/PUSH DATA LW0 (WB1D/PD0) |
          |          (2 words)            |
   +$34 -> +-------------------------------+
          |     PUSH DATA LW 1 (PD1)       |
          |          (2 words)            |
   +$38 -> +-------------------------------+
          |     PUSH DATA LW 2 (PD2)       |
          |          (2 words)            |
          +-------------------------------+
          |     PUSH DATA LW 3 (PD3)       |
          |          (2 words)            |
          +-------------------------------+
```

### Figure B-9: MC68010 Bus and Address Error Stack Frame, Format $8

```
         15                              0
    SP -> +-------------------------------+
          |        STATUS REGISTER        |
   +$02 -> +-------------------------------+
          |     PROGRAM COUNTER HIGH      |
          +-------------------------------+
          |     PROGRAM COUNTER LOW       |
   +$06 -> +-------------------------------+
          | 1 0 0 0 |   VECTOR OFFSET     |
   +$08 -> +-------------------------------+
          |     SPECIAL STATUS WORD        |
   +$0C -> +-------------------------------+
          |     FAULT ADDRESS HIGH         |
          +-------------------------------+
          |     FAULT ADDRESS LOW          |
   +$10 -> +-------------------------------+
          |     UNUSED, RESERVED           |
          +-------------------------------+
          |     DATA OUTPUT BUFFER         |
          +-------------------------------+
          |     UNUSED, RESERVED           |
          +-------------------------------+
          |     DATA INPUT BUFFER          |
          +-------------------------------+
          |     UNUSED, RESERVED           |
          +-------------------------------+
          |     INSTRUCTION OUTPUT BUFFER  |
          +-------------------------------+
          |VERSION|                        |
          |NUMBER |                        |
          +-------------------------------+
          |  INTERNAL INFORMATION, 16 WORDS|
   +$50 -> +-------------------------------+

NOTE: The stack pointer decrements by 29 words,
although only 26 words of information actually
write to memory. Motorola reserves the three
additional words for future use.
```

### Figure B-10: MC68020 and MC68030 Coprocessor Mid-Instruction Stack Frame, Format $9

```
         15                              0
    SP -> +-------------------------------+
          |        STATUS REGISTER        |
   +$02 -> +-------------------------------+
          |        PROGRAM COUNTER        |
          |          (2 words)            |
   +$06 -> +-------------------------------+
          | 1 0 0 1 |   VECTOR OFFSET     |
   +$08 -> +-------------------------------+
          |     INSTRUCTION ADDRESS        |
          |          (2 words)            |
   +$0C -> +-------------------------------+
          |  INTERNAL REGISTERS, 4 WORDS   |
   +$12 -> +-------------------------------+
```

### Figure B-11: MC68020 and MC68030 Short Bus Cycle Stack Frame, Format $A

```
         15                              0
    SP -> +-------------------------------+
          |        STATUS REGISTER        |
   +$02 -> +-------------------------------+
          |        PROGRAM COUNTER        |
          |          (2 words)            |
   +$06 -> +-------------------------------+
          | 1 0 1 0 |   VECTOR OFFSET     |
   +$08 -> +-------------------------------+
          |     INTERNAL REGISTER          |
   +$0A -> +-------------------------------+
          |  SPECIAL STATUS REGISTER       |
   +$0C -> +-------------------------------+
          |  INSTRUCTION PIPE STAGE C      |
   +$0E -> +-------------------------------+
          |  INSTRUCTION PIPE STAGE B      |
   +$10 -> +-------------------------------+
          |  DATA CYCLE FAULT ADDRESS      |
          |          (2 words)            |
   +$14 -> +-------------------------------+
          |     INTERNAL REGISTER          |
   +$16 -> +-------------------------------+
          |     INTERNAL REGISTER          |
   +$18 -> +-------------------------------+
          |     DATA OUTPUT BUFFER         |
          |          (2 words)            |
   +$1C -> +-------------------------------+
          |     INTERNAL REGISTER          |
   +$1E -> +-------------------------------+
          |     INTERNAL REGISTER          |
          +-------------------------------+
```

### Figure B-12: MC68020 and MC68030 Long Bus Cycle Stack Frame, Format $B

```
         15                              0
    SP -> +-------------------------------+
          |        STATUS REGISTER        |
   +$02 -> +-------------------------------+
          |        PROGRAM COUNTER        |
          |          (2 words)            |
   +$06 -> +-------------------------------+
          | 1 0 1 1 |   VECTOR OFFSET     |
   +$08 -> +-------------------------------+
          |     INTERNAL REGISTER          |
   +$0A -> +-------------------------------+
          |  SPECIAL STATUS REGISTER       |
   +$0C -> +-------------------------------+
          |  INSTRUCTION PIPE STAGE C      |
   +$0E -> +-------------------------------+
          |  INSTRUCTION PIPE STAGE B      |
   +$10 -> +-------------------------------+
          |  DATA CYCLE FAULT ADDRESS      |
          |          (2 words)            |
   +$14 -> +-------------------------------+
          |     INTERNAL REGISTER          |
   +$16 -> +-------------------------------+
          |     INTERNAL REGISTER          |
   +$18 -> +-------------------------------+
          |     DATA OUTPUT BUFFER         |
          |          (2 words)            |
   +$1C -> +-------------------------------+
          |  INTERNAL REGISTERS, 4 WORDS   |
   +$22 -> +-------------------------------+
          |     STAGE B ADDRESS            |
          |          (2 words)            |
   +$28 -> +-------------------------------+
          |  INTERNAL REGISTERS, 2 WORDS   |
   +$2C -> +-------------------------------+
          |     DATA INPUT BUFFER          |
          |          (2 words)            |
   +$30 -> +-------------------------------+
          |  INTERNAL REGISTERS, 3 WORDS   |
   +$36 -> +-------------------------------+
          |     VERSION #                  |
   +$38 -> +-------------------------------+
          |     INTERNAL INFORMATION       |
          +-------------------------------+
          |  INTERNAL REGISTERS, 18 WORDS  |
   +$5A -> +-------------------------------+
```

### Figure B-13: CPU32 Bus Error for Prefetches and Operands Stack Frame, Format $C

```
         15                              0
    SP -> +-------------------------------+
          |        STATUS REGISTER        |
   +$02 -> +-------------------------------+
          |  RETURN PROGRAM COUNTER HIGH   |
          +-------------------------------+
          |  RETURN PROGRAM COUNTER LOW    |
   +$06 -> +-------------------------------+
          | 1 1 0 0 |   VECTOR OFFSET     |
   +$08 -> +-------------------------------+
          |     FAULTED ADDRESS HIGH       |
          +-------------------------------+
          |     FAULTED ADDRESS LOW        |
   +$0C -> +-------------------------------+
          |        DBUF HIGH               |
          +-------------------------------+
          |        DBUF LOW                |
   +$10 -> +-------------------------------+
          | CURRENT INSTR PROG COUNTER HIGH|
          +-------------------------------+
          | CURRENT INSTR PROG COUNTER LOW |
   +$14 -> +-------------------------------+
          | INTERNAL TRANSFER COUNT REG    |
   +$16 -> +-------------------------------+
          | 0 0 | SPECIAL STATUS WORD      |
          +-------------------------------+
```

### Figure B-14: CPU32 Bus Error on MOVEM Operand Stack Frame, Format $C

Same as Figure B-13 but with bits 1-0 of the last word = 01.

### Figure B-15: CPU32 Four- and Six-Word Bus Error Stack Frame, Format $C

Same as Figure B-13 but with bits 1-0 of the last word = 10.

## B.3 Floating-Point Stack Frames

### Figure B-16: MC68881/MC68882 and MC68040 Null Stack Frame

```
         31        23        15         7         0
   +$00 -> +--------+---------+---------+---------+
          |  $00   |(UNDEFINED)|(RESERVED)|        |
          +--------+---------+---------+---------+
```

### Figure B-17: MC68881 Idle Stack Frame

```
         31        23        15         7         0
   +$00 -> +--------+---------+---------+---------+
          | VERSION NUMBER    |  $18    |(RESERVED)|
   +$04 -> +--------+---------+---------+---------+
          |           (RESERVED)                   |
   +$08 -> +--------+---------+---------+---------+
          |     COMMAND/CONDITION REGISTER         |
   +$0C -> +--------+---------+---------+---------+
          |     EXCEPTIONAL OPERAND                |
          |          (12 BYTES)                    |
   +$10 -> +--------+---------+---------+---------+
          |                                        |
   +$14 -> +--------+---------+---------+---------+
          |     OPERAND REGISTER   | BIU FLAGS     |
   +$18 -> +--------+---------+---------+---------+
```

### Figure B-18: MC68881 Busy Stack Frame

```
         31        23        15         7         0
   +$00 -> +--------+---------+---------+---------+
          | VERSION NUMBER    |  $B4    |(RESERVED)|
   +$04 -> +--------+---------+---------+---------+
          |                                        |
          |     INTERNAL REGISTERS                 |
          |          (180 BYTES)                   |
          |                                        |
   +$B4 -> +--------+---------+---------+---------+
```

### Figure B-19: MC68882 Idle Stack Frame

```
         31        23        15         7         0
   +$00 -> +--------+---------+---------+---------+
          | VERSION NUMBER    |  $38    |(RESERVED)|
   +$04 -> +--------+---------+---------+---------+
          |           (RESERVED)                   |
   +$08 -> +--------+---------+---------+---------+
          |     COMMAND/CONDITION REGISTER         |
          +--------+---------+---------+---------+
          |     INTERNAL REGISTERS (32 BYTES)      |
   +$28 -> +--------+---------+---------+---------+
          |     EXCEPTIONAL OPERAND (12 BYTES)     |
   +$30 -> +--------+---------+---------+---------+
          |     OPERAND REGISTER                   |
   +$34 -> +--------+---------+---------+---------+
          |     BIU FLAGS                          |
   +$38 -> +--------+---------+---------+---------+
```

### Figure B-20: MC68882 Busy Stack Frame

```
         31        23        15         7         0
   +$00 -> +--------+---------+---------+---------+
          | VERSION NUMBER    |  $D4    |(RESERVED)|
   +$04 -> +--------+---------+---------+---------+
          |                                        |
          |     INTERNAL REGISTERS                 |
          |          (212 BYTES)                   |
          |                                        |
   +$D4 -> +--------+---------+---------+---------+
```

### Figure B-21: MC68040 Idle Stack Frame

```
         31        23        15         7         0
   +$00 -> +--------+---------+---------+---------+
          | VERSION = $41     |  $00    |(RESERVED)|
          +--------+---------+---------+---------+
```

### Figure B-22: MC68040 Unimplemented Instruction Stack Frame

```
         31        23        15         7         0
   +$00 -> +--------+---------+---------+---------+
          | VERSION = $41     |  $30    |(RESERVED)|
   +$04 -> +--------+---------+---------+---------+
          |     CMDREG3B                           |
   +$08 -> +--------+---------+---------+---------+
          |WBT M66 | STAG    |WBT M1  |           |
   +$0C -> +--------+---------+---------+---------+
          | SBIT   | CMDREG1B          |           |
   +$10 -> +--------+---------+---------+---------+
          |WBT E15 | DTAG    |WBT M0  |           |
   +$14 -> +--------+---------+---------+---------+
          | E1  FPTS         | E3   T  FPTE       |
   +$18 -> +--------+---------+---------+---------+
   +$1C -> +--------+---------+---------+---------+
          |     FPTM 63-32                         |
   +$20 -> +--------+---------+---------+---------+
          |     FPTM 31-00                         |
   +$24 -> +--------+---------+---------+---------+
          | ETS    | ETE                           |
   +$28 -> +--------+---------+---------+---------+
          |     ETM 63-32                          |
   +$2C -> +--------+---------+---------+---------+
          |     ETM 31-00                          |
   +$30 -> +--------+---------+---------+---------+
          |     Reserved                           |
          +--------+---------+---------+---------+
```

### Figure B-23: MC68040 Busy Stack Frame

```
         31        23        15         7         0
   +$00 -> +--------+---------+---------+---------+
          | VERSION = $41     |  $60    |(RESERVED)|
   +$04 -> +--------+---------+---------+---------+
          |     CU_SAVEPC                          |
          |          (2 words)                     |
   +$0C -> +--------+---------+---------+---------+
          |                                        |
   +$10 -> +--------+---------+---------+---------+
          |                                        |
   +$14 -> +--------+---------+---------+---------+
          |     WBTS                               |
   +$18 -> +--------+---------+---------+---------+
          |     WBTE 14-00                         |
   +$1C -> +--------+---------+---------+---------+
          |     WBTM 65-34                         |
   +$20 -> +--------+---------+---------+---------+
          |     WBTM 33-02                         |
   +$24 -> +--------+---------+---------+---------+
          |     FPIARCU                            |
          |          (2 words)                     |
   +$2C -> +--------+---------+---------+---------+
          |                                        |
   +$30 -> +--------+---------+---------+---------+
          |     CMDREG3B                           |
   +$38 -> +--------+---------+---------+---------+
          |WBT M66 | STAG    |WBT M1  |           |
   +$3C -> +--------+---------+---------+---------+
          | SBIT   | CMDREG1B          |           |
   +$40 -> +--------+---------+---------+---------+
          |WBT E15 | DTAG    |WBT M0  |           |
   +$44 -> +--------+---------+---------+---------+
          | E1  FPTS         | E3   T  FPTE       |
   +$48 -> +--------+---------+---------+---------+
   +$4C -> +--------+---------+---------+---------+
          |     FPTM 63-32                         |
   +$50 -> +--------+---------+---------+---------+
          |     FPTM 31-00                         |
   +$54 -> +--------+---------+---------+---------+
          | ETS    | ETE                           |
   +$58 -> +--------+---------+---------+---------+
          |     ETM 63-32                          |
   +$5C -> +--------+---------+---------+---------+
          |     ETM 31-00                          |
   +$60 -> +--------+---------+---------+---------+
          |     Reserved                           |
          +--------+---------+---------+---------+
```
