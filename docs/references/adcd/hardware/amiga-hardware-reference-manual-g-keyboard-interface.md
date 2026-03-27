---
title: Amiga® Hardware Reference Manual: G Keyboard Interface
manual: hardware
chapter: hardware
section: amiga-hardware-reference-manual-g-keyboard-interface
functions: []
libraries: []
---

# Amiga® Hardware Reference Manual: G Keyboard Interface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This appendix contains the keyboard interface specification for A1000,
A500, A2000 and A3000.

The keyboard plugs into the Amiga computer via a cable with four
 [primary connections](hardware/e-amiga-i-o-connector-pins-keyboard.md) .  The four wires provide 5-volt power, ground, and
signals called KCLK (keyboard clock) and KDAT (keyboard data).  KCLK is
unidirectional and always driven by the keyboard; KDAT is driven by both
the keyboard and the computer.  Both signals are open-collector; there are
pullup resistors in both the keyboard (inside the keyboard microprocessor)
and the computer.

 [Keyboard Communications](hardware/g-keyboard-interface-keyboard-communications.md)      [Reset Warning](hardware/g-keyboard-interface-reset-warning.md) 
 [Keycodes](hardware/g-keyboard-interface-keycodes.md)                     [Hard Reset](hardware/g-keyboard-interface-hard-reset.md) 
 [Caps Lock Key](hardware/g-keyboard-interface-caps-lock-key.md)                [Matrix Table](hardware/g-keyboard-interface-matrix-table.md) 
 [Out-of-Sync Condition](hardware/g-keyboard-interface-out-of-sync-condition.md)        [Special Codes](hardware/g-keyboard-interface-special-codes.md) 
 [Power-Up Sequence](hardware/g-keyboard-interface-power-up-sequence.md) 

