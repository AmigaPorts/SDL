---
title: 3 / Color Selection / Color Selection in Hold-And-Modify Mode
manual: hardware
chapter: hardware
section: 3-color-selection-color-selection-in-hold-and-modify-mode
functions: []
libraries: []
---

# 3 / Color Selection / Color Selection in Hold-And-Modify Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In hold-and-modify mode, the color register contents are changed as shown
in Table 3-19.  This mode is in effect only if bit 10 of  [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md)  = 1.


  Bitplane 6  Bitplane 5                Result
  ----------  ----------                ------

```c
      0           0      Normal operation     (use color register itself)
      0           1      Hold green and red   B = Bitplane 4-1 contents
      1           0      Hold green and blue  R = Bitplane 4-1 contents
      1           1      Hold blue and red    G = Bitplane 4-1 contents

      Table 3-19: Color Selection in Hold-and-modify Mode
```
