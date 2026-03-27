# 68k Hardware Reference for Crash Debugging

Target audience: AI agents (debug-agent, code-transformer, build-manager). Optimized for structured lookup, not prose.

Covers: Amiga memory map, 68000/68020 addressing, register conventions, stack behavior, trap frames, Guru codes, vamos differences, and instruction reference (stub for Layer 2 GDB).

Platform context: AmigaOS 3.x on 68EC020+ (project default). Note: stock A1200 uses 68EC020 (24-bit address bus), NOT full 68020. Only A3000/A4000 or accelerator-upgraded machines have true 32-bit addressing.

---

## 1. Crash Signature Quick Reference

**Use this table first when diagnosing Enforcer hits or vamos InvalidMemoryAccessErrors.**

| Address / Condition | Diagnosis | Action |
|---|---|---|
| `0x00000004`, LONG-READ | ExecBase read (`*(APTR *)4`) | Normal — not a bug |
| `< 0x1000` (except 0x4) | NULL pointer + struct offset | Find unchecked pointer; offset reveals which struct field |
| Odd address + WORD/LONG on 68000 | Alignment error (address error trap, vector 3) | Check struct packing, pointer casts, arithmetic |
| `0xDEADBEEF` | Mungwall: freed memory | Use-after-free — find the `free()` call |
| `0xABADCAFE` | Mungwall: allocated but uninitialized | Missing initialization after `malloc`/`AllocMem` |
| `0xCCCCCCCC` | Mungwall: uninitialized (alternate) | Same as `0xABADCAFE` |
| `0xDFF000–0xDFF1FF` | Custom chip registers (Agnus, Denise, Paula) | Hardware access, not a code bug in POSIX ports. Wild pointer in Category 1-2. |
| `0xBFD000` (even addresses) | CIA-B (8520) | Hardware access — not a code bug |
| `0xBFE001` (odd addresses) | CIA-A (8520) | Hardware access — not a code bug |
| `0xF80000–0xFFFFFF` (data access) | Kickstart ROM area | Read is OK; write triggers Enforcer |
| PC in `0xF80000–0xFFFFFF` | Crash inside Kickstart ROM | Bug is in calling code — bad args to ROM function |
| SP in `0xFFFFxxxx` on 68000 | 24-bit address wrapping | Real address is `0x00FFxxxx` — see Section 3 |
| SP near task's stack lower bound | Stack overflow | Increase `long __stack`; move large arrays to heap |
| Valid RAM, unexpected value | Use-after-free / buffer overflow / corrupted pointer | Needs source-level investigation |

---

## 2. Amiga Memory Map

Stock A1200 (68EC020, 2MB Chip) / A4000 (68040, 2MB Chip + Fast):

| Address Range | Size | What's There |
|---|---|---|
| `0x000000–0x0003FF` | 1KB | Exception vector table (68k trap vectors) |
| `0x000400–0x1FFFFF` | ~2MB | Chip RAM (DMA-accessible by custom chips; 2MB max with AGA Alice, 1MB with Fat Agnus, 512KB with Thin Agnus) |
| `0x200000–0x9FFFFF` | 8MB | Zorro II expansion + motherboard Fast RAM |
| `0xA00000–0xBEFFFF` | ~2MB | Slow I/O space |
| `0xBFD000` | — | CIA-B (8520) — even addresses only |
| `0xBFE001` | — | CIA-A (8520) — odd addresses only |
| `0xC00000–0xD7FFFF` | 1.5MB | Slow/ranger expansion |
| `0xD80000–0xDBFFFF` | 256KB | Reserved |
| `0xDC0000–0xDCFFFF` | 64KB | Real-time clock (A2000, A3000, A4000) |
| `0xDFF000–0xDFF1FF` | 512B | Custom chip registers (Agnus/Alice, Denise/Lisa, Paula) |
| `0xE00000–0xE7FFFF` | 512KB | Reserved (A3000/A4000 motherboard resources) |
| `0xE80000–0xEFFFFF` | 512KB | Autoconfig expansion space (Zorro II cards) |
| `0xF00000–0xF7FFFF` | 512KB | Reserved / diagnostic ROM / A3000 Fast ROM |
| `0xF80000–0xFFFFFF` | 512KB | Kickstart ROM (256KB on KS 1.x/2.x, mirrored at $FC0000; 512KB on KS 3.x, fills full range) |

**Zorro III (A3000/A4000 only):**

| Address Range | What's There |
|---|---|
| `0x40000000–0x7FFFFFFF` | Zorro III Fast RAM and expansion |
| `0xFF000000` | Zorro III autoconfig space (different protocol from Zorro II $E80000) |

**Key addresses for crash diagnosis:**
- `0x00000004` — ExecBase pointer (always valid, every program reads this)
- `0x000000–0x0003FF` — Exception vectors; writes here are intentional (Exec sets them)
- `0xDFF000+` — Custom chip area; any access from POSIX-ported code is a wild pointer

---

## 3. 68000 vs 68020+ Addressing

### 24-bit vs 32-bit

| CPU | Amiga Model | Address Bus | Behavior |
|---|---|---|---|
| 68000 | A500, A2000 | 24-bit | Upper 8 bits ignored. `0xFFFF0044` = `0x00FF0044`. (68010 was never used in any production Amiga.) |
| **68EC020** | **A1200 (stock)** | **24-bit** | EC variant — same 24-bit wrapping as 68000 despite 32-bit internals. |
| 68020 (full) | Accelerator cards | 32-bit | Full 32-bit addressing. No wrapping. |
| 68030 (full) | A3000, accelerators | 32-bit | Full 32-bit addressing. MMU available. |
| **68EC030** | **A4000/030** | **32-bit** | Full 32-bit addressing. **No MMU** — Enforcer won't work. |
| 68040 / 68060 | A4000/040, accelerators | 32-bit | Full 32-bit addressing. MMU available. |

**Critical:** The "EC" suffix means cost-reduced with material capability loss:
- **68EC020** (stock A1200, CD32) = 24-bit address bus (same wrapping as 68000)
- **68EC030** (A4000/030) = no MMU (Enforcer cannot run)

### The 24-bit wrapping trap

On a 68000 or 68EC020 (stock A1200), the CPU internally computes 32-bit addresses but only puts 24 bits on the external address bus. This means:

- `0xFFFF0044` aliases to `0x00FF0044`
- Code that accidentally computes a negative stack offset (e.g., stack underflow) may appear to access the `0xFFFF0000` range
- **Real hardware wraps silently** — the program keeps running with corrupted data
- **vamos rejects these addresses** — you see `InvalidMemoryAccessError` instead of silent corruption

### Practical impact

When the debug-agent sees SP or an address in the `0xFFFF0000–0xFFFFFFFF` range:

1. If targeting 68000 or 68EC020 (stock A1200): this is 24-bit wrapping. The real address is `0x00FF0000–0x00FFFFFF`.
2. If targeting 68030+ (A3000/A4000 or accelerator): this is a genuine invalid address (stack overflow or wild pointer).
3. On vamos: always rejected regardless of target CPU, because vamos uses 32-bit addressing.

The diff port crash (SP=0xffff0044) was this exact pattern — stack overflowed downward past 0x00000000, wrapped to 0xFFFF0044, which vamos rejected.

### Self-modifying code

The 68020+ has an instruction cache. Code that modifies instructions in memory (self-modifying code, runtime patching, JIT) will execute stale cached instructions unless the cache is explicitly flushed with `CacheClearU()` or `CacheClearE()`. This is not an issue on 68000 (no cache). GCC-generated code never self-modifies, but some hand-optimized or generated code (e.g., Lua JIT, regex engines with compiled patterns) may.

---

## 4. Register Conventions

### SAS C / GCC (amiga-gcc) calling convention

| Register | Usage | Saved by |
|---|---|---|
| D0 | Return value (LONG), scratch | Caller |
| D1 | Scratch | Caller |
| D2–D7 | General purpose | Callee (must preserve) |
| A0 | Return value (pointer), scratch | Caller |
| A1 | Scratch | Caller |
| A2–A5 | General purpose | Callee (must preserve) |
| A6 | Library base pointer | Callee (must preserve) |
| A7 (SP) | Stack pointer | Hardware |

### Key conventions for crash diagnosis

- **A6 = library base:** Every AmigaOS library call expects the library base in A6. If A6 is corrupted, the next library call crashes inside ROM (PC in `0xF80000–0xFFFFFF`). Look for missing `OpenLibrary()` or A6 clobbered by user code.
- **D0 = return value:** After an OS call, D0 contains the result. D0 = 0 often means failure (NULL pointer). Check if the caller tests D0 before using it.
- **ExecBase at address 4:** `*(struct ExecBase **)4` is always valid. This is the bootstrap for all AmigaOS operations. A LONG-READ from address 4 is never a bug.

---

## 5. Stack Behavior

### Growth direction

Stack grows **downward** (high addresses → low addresses). SP starts at the top of the allocated stack region and decrements on push/call.

```
Stack region:
  [stack base (low)]  ← stack overflow happens here
  ...
  ...
  [stack top (high)]  ← SP starts here
```

### Stack frames (GCC / SAS C)

**Function prologue:**
```asm
LINK    A5,#-N          ; Create stack frame, allocate N bytes for locals
MOVEM.L D2-D7/A2-A6,-(SP)  ; Save callee-saved registers
```

**Function epilogue:**
```asm
MOVEM.L (SP)+,D2-D7/A2-A6  ; Restore callee-saved registers
UNLK    A5              ; Destroy stack frame
RTS                     ; Return
```

### Stack cookie mechanism (amiga-gcc)

```c
long __stack = 32768;  /* Request 32KB stack from the system */
```

The startup code (`__startup` in libnix) reads this value and calls `StackSwap()` if the current stack is smaller. On real hardware, this works reliably. **vamos ignores `__stack` cookies** — see Section 7.

### Stack overflow signatures

- SP decrements below the stack base → access to memory below the stack region
- On 68000: may wrap to `0xFFFFxxxx` range (24-bit wrapping)
- On 68020+: Enforcer hit at an address near the stack base
- Guru Meditation `0x35000000` = explicit stack overflow alert (from Exec's stack check)
- Multiple rapid Enforcer hits at different addresses = stack frame chain has corrupted return addresses

---

## 6. Trap Frames & Guru Meditation Codes

### Exception vector table

Located at `0x000000–0x0003FF`. Each vector is a 4-byte pointer to a handler.

| Vector | Address | Exception |
|---|---|---|
| 2 | `0x008` | Bus error (access fault) |
| 3 | `0x00C` | Address error (misaligned access on 68000) |
| 4 | `0x010` | Illegal instruction |
| 5 | `0x014` | Zero divide |
| 6 | `0x018` | CHK instruction |
| 7 | `0x01C` | TRAPV instruction |
| 8 | `0x020` | Privilege violation |
| 9 | `0x024` | Trace |
| 32–47 | `0x080–0x0BF` | TRAP #0–#15 (used by AmigaOS) |

### Guru Meditation alert format

Alerts are 32-bit codes: `0xATDDDDEE`

- **AT** (bits 31-24): Alert type
  - `0x80` = deadend (system halted)
  - `0x00` = recoverable
- **DDDD** (bits 23-8): Subsystem ID
  - `0x0001` = exec.library
  - `0x0002` = graphics.library
  - `0x000F` = dos.library
- **EE** (bits 7-0): Error code within subsystem

### Common Guru codes

| Code | Meaning |
|---|---|
| `0x80000002` | Bus error (hardware fault) |
| `0x80000003` | Address error (misaligned access) |
| `0x80000004` | Illegal instruction |
| `0x80000005` | Zero divide |
| `0x35000000` | Stack overflow (Exec detected) |
| `0x81000009` | exec.library: free twice (double free) |
| `0x8100000E` | exec.library: bad free address |
| `0x82010005` | expansion: no memory for expansion |

### How Enforcer intercepts

Enforcer patches the MMU page tables to make unmapped or protected regions trigger a bus error. **Requires an MMU** — works on 68030 (full, not EC), 68040, 68060. Does NOT work on 68EC030 (A4000/030). When a bus error occurs, Enforcer's handler:

1. Captures the faulting address, access type (read/write/word/long), PC, and all registers
2. Looks up the PC in loaded segment lists to identify the program and offset
3. Logs the hit (serial port, file, or memory buffer)
4. Resumes execution (does NOT halt like a Guru)

On 68000, 68EC020, 68020, or 68EC030 (no MMU), Enforcer cannot run. Use Mungwall (heap sentinel checking) instead.

---

## 7. vamos vs Real Hardware

vamos (Virtual AmigaOS) is a POSIX-hosted AmigaOS runtime emulator from the amitools package. It differs from real hardware in several crash-relevant ways:

| Behavior | Real Hardware | vamos |
|---|---|---|
| `__stack` cookie | Honored by startup code (`StackSwap`) | **Ignored** — defaults to 8KB. Use `-s N` flag. |
| 24-bit address wrap (68000) | Silent — upper 8 bits ignored | **Rejected** — `InvalidMemoryAccessError` |
| Memory validation | None without Enforcer/Mungwall | Always active — rejects out-of-range accesses |
| Enforcer hit format | Structured (address, PC, type, registers) | N/A — uses `InvalidMemoryAccessError` with less detail |
| Mungwall sentinels | `0xDEADBEEF` / `0xABADCAFE` in freed/uninit memory | N/A — no Mungwall. Use-after-free appears as invalid access. |
| Custom chip registers | Readable/writable (hardware) | Not mapped — access crashes |
| CIA registers | Readable/writable (hardware) | Not mapped — access crashes |

### Implications for crash diagnosis

- A crash at `0xFFFFxxxx` on vamos = likely stack overflow (vamos rejects the wrapped address)
- The same crash on real 68000 hardware would **not crash** — it would silently corrupt memory at `0x00FFxxxx`
- vamos crashes are often **more informative** than real hardware crashes because vamos catches issues that real hardware masks
- When a program works on vamos but crashes on FS-UAE (or vice versa), suspect stack size (`__stack` vs `-s` flag) or memory layout differences

---

## 8. Instruction Reference (Layer 2 / GDB — Stub)

**This section is a placeholder.** Content will be filled when Layer 2 GDB debugging is implemented. The scope below defines what to document.

### Instructions to document

Core 68k instructions commonly generated by GCC for C code:

| Category | Instructions |
|---|---|
| Data movement | MOVE, LEA, PEA, CLR, EXT, SWAP |
| Arithmetic | ADD, ADDQ, SUB, SUBQ, MULS, MULU, DIVS, DIVU, NEG |
| Logic | AND, OR, EOR, NOT |
| Shift/rotate | LSL, LSR, ASL, ASR, ROL, ROR |
| Compare/test | CMP, TST |
| Branch | BEQ, BNE, BRA, BLT, BGT, BLE, BGE, BCC, BCS, DBRA |
| Subroutine | JSR, BSR, RTS |
| Stack frame | LINK, UNLK, MOVEM |
| Trap | TRAP |

### Addressing modes

| Mode | Syntax | Example | Used for |
|---|---|---|---|
| Register direct | `Dn` / `An` | `MOVE.L D0,D1` | Local variables, return values |
| Register indirect | `(An)` | `MOVE.L (A0),D0` | Pointer dereference |
| With displacement | `d(An)` | `MOVE.L 8(A5),D0` | Struct field access, local vars via frame pointer |
| With index | `d(An,Xn)` | `MOVE.L 0(A0,D1),D2` | Array access |
| Absolute short | `addr.W` | `MOVE.L $4.W,A6` | ExecBase access (address 4) |
| Absolute long | `addr.L` | `JSR $addr` | Direct function call |
| PC-relative | `d(PC)` | `LEA data(PC),A0` | Position-independent code, string literals |
| Pre-decrement | `-(An)` | `MOVE.L D0,-(SP)` | Stack push |
| Post-increment | `(An)+` | `MOVE.L (SP)+,D0` | Stack pop |

### Alignment rules

- **68000:** Word-aligned instruction fetches and word/long data accesses are required. Misaligned access triggers address error trap (vector 3, Guru `0x80000003`). Byte accesses can be unaligned.
- **68020+:** Handles misaligned word/long access in hardware. Slower (extra bus cycles) but no trap. Instructions can start at any even address.
- **68040/68060:** Same as 68020 for alignment. Additional: instruction cache and data cache may cause behavioral differences vs uncached 68020.

### GCC code generation patterns

**Function prologue (typical):**
```asm
LINK    A5,#-24         ; 24 bytes of local variables
MOVEM.L D2-D4/A2-A3,-(SP)  ; Save 5 callee-saved registers
```

**Function epilogue:**
```asm
MOVEM.L (SP)+,D2-D4/A2-A3
UNLK    A5
RTS
```

**Switch table:**
```asm
; GCC generates a jump table for dense switch statements
MOVE.L  D0,D1
SUB.L   #base,D1
CMP.L   #max,D1
BHI     .default
LSL.L   #2,D1
LEA     .table(PC),A0
MOVE.L  0(A0,D1.L),A0
JMP     (A0)
```
