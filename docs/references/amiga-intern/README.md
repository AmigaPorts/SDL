# Amiga Intern (1992) Reference Documentation

Converted from the OCR text of "Amiga Intern" by Christian Kuhnert, Stefan Maelger, and Johannes Schemmel (Abacus, 1992). Source: [Internet Archive](https://archive.org/details/Amiga_Intern_1992_Abacus).

992 pages covering AmigaOS 2.x system programming, ARexx, and A3000 hardware internals.

## Contents

### Part 1: System Programming

| File | Topic | Priority |
|------|-------|----------|
| [01-kickstart.md](01-kickstart.md) | Kickstart 2.04 internals | Medium |
| [02-using-amiga-3000.md](02-using-amiga-3000.md) | Workbench and CLI | Low |
| [03-01-asl-library.md](03-01-asl-library.md) | ASL Library | Low (covered by ADCD) |
| [03-02-commodities-library.md](03-02-commodities-library.md) | Commodities Library | Low |
| [03-03-diskfont-library.md](03-03-diskfont-library.md) | Diskfont Library | Low |
| [03-04-dos-library.md](03-04-dos-library.md) | DOS Library (116KB) | Medium |
| [03-05-exec-library.md](03-05-exec-library.md) | Exec Library (73KB) | Medium |
| [03-06-expansion-library.md](03-06-expansion-library.md) | Expansion Library | Low |
| [03-07-gadtools-library.md](03-07-gadtools-library.md) | GadTools Library | Low |
| [03-08-graphics-library.md](03-08-graphics-library.md) | Graphics Library (83KB) | Medium |
| [03-09-icon-library.md](03-09-icon-library.md) | Icon Library | Low |
| [03-10-iffparse-library.md](03-10-iffparse-library.md) | IFFParse Library | Low |
| [03-11-intuition-library.md](03-11-intuition-library.md) | Intuition Library (97KB) | Low (Cat 5 only) |
| [03-12-layers-library.md](03-12-layers-library.md) | Layers Library | Low |
| [03-13-math-libraries.md](03-13-math-libraries.md) | MathFFP Libraries | Low |
| [03-14-math-trans-libraries.md](03-14-math-trans-libraries.md) | MathTrans Libraries | Low |
| [03-15-utility-library.md](03-15-utility-library.md) | Utility Library | Low |
| [03-16-workbench-library.md](03-16-workbench-library.md) | Workbench Library | Low |

### Part 2: ARexx

| File | Topic | Priority |
|------|-------|----------|
| [04-arexx-intro.md](04-arexx-intro.md) | ARexx Introduction | Medium |
| [05-arexx-syntax.md](05-arexx-syntax.md) | ARexx Syntax | Medium |
| [06-arexx-instructions.md](06-arexx-instructions.md) | ARexx Instructions | Medium |
| [07-arexx-functions.md](07-arexx-functions.md) | ARexx Functions (69KB) | Medium |
| [09-arexx-on-amiga.md](09-arexx-on-amiga.md) | ARexx on the Amiga | Medium |
| [10-arexx-interface.md](10-arexx-interface.md) | ARexx Interface (66KB) | Medium |

### Part 3: A3000 Hardware (HIGH PRIORITY)

| File | Topic | Priority |
|------|-------|----------|
| [11-01-processor-generations.md](11-01-processor-generations.md) | 68000/010/020/030 overview | **High** |
| [11-02-the-68030.md](11-02-the-68030.md) | 68030 CPU, PMMU, FPU, Cache (95KB) | **High** |
| [11-03-cia-8520.md](11-03-cia-8520.md) | CIA 8520 timer/IO chip | Medium |
| [11-04-custom-chips.md](11-04-custom-chips.md) | Agnus, Denise, Paula structure | **High** |
| [11-05-amiga-interfaces.md](11-05-amiga-interfaces.md) | Audio, RGB, serial, parallel, Zorro | Medium |
| [11-06-keyboard.md](11-06-keyboard.md) | Keyboard protocol | Low |
| [11-07-01-memory-layout.md](11-07-01-memory-layout.md) | Memory map and register addresses | **High** |
| [11-07-02-fundamentals.md](11-07-02-fundamentals.md) | DMA slots, bus timing | **High** |
| [11-07-03-interrupts.md](11-07-03-interrupts.md) | Interrupt system | **High** |
| [11-07-04-copper.md](11-07-04-copper.md) | Copper coprocessor | **High** |
| [11-07-05-playfields.md](11-07-05-playfields.md) | Playfield/bitplane graphics (47KB) | Medium |
| [11-07-06-sprites.md](11-07-06-sprites.md) | Hardware sprites | Medium |
| [11-07-07-ecs.md](11-07-07-ecs.md) | ECS enhancements | Medium |
| [11-07-08-blitter.md](11-07-08-blitter.md) | Blitter operations (58KB) | **High** |
| [11-07-09-sound.md](11-07-09-sound.md) | Audio DMA and output | Medium |
| [11-07-10-input-devices.md](11-07-10-input-devices.md) | Mouse, joystick, paddles | Low |
| [11-07-11-serial.md](11-07-11-serial.md) | Serial interface hardware | Low |
| [11-07-12-disk-controller.md](11-07-12-disk-controller.md) | Disk controller and MFM | Low |

## How This Complements ADCD

The ADCD docs (`../adcd/`) cover the **API surface** — function signatures, parameters, return values. Amiga Intern covers the **internals** — why things work the way they do, hardware architecture, bus timing, DMA allocation. Together they give agents both "how to call it" and "how it works underneath."

Key unique content not in ADCD:
- 68030 CPU internals, PMMU, cache behavior (Ch 11.2)
- Custom chip internal structure and pin descriptions (Ch 11.4)
- Complete memory map with address ranges (Ch 11.7.1)
- DMA slot allocation and bus arbitration (Ch 11.7.2)
- Full custom chip register table with chip assignments (Ch 11.7.1)
- Blitter algorithm and minterm logic (Ch 11.7.8)

## OCR Quality Notes

Converted from DJVU OCR via `scripts/convert-amiga-intern.py`. Known artifacts:
- Some stray diagram labels where figures couldn't be OCR'd
- Occasional double-space artifacts within words (e.g. "1 6" for "16")
- Register tables may have alignment issues from the OCR
- Code examples may have OCR errors in variable names
