---
title: 4 / Writing to the Console Device / Example Console Control Sequences
manual: devices
chapter: devices
section: 4-writing-to-the-console-device-example-console-control
functions: []
libraries: []
---

# 4 / Writing to the Console Device / Example Console Control Sequences

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
                                     Character String       Numeric (hex)
                                        Equivalent           Equivalent
                                     ----------------       -------------
    Move cursor right by 1:              <CSI>C or           9B 43
                                         <CSI>1C             9B 31 43

    Move cursor right by 20:             <CSI>20C            9B 32 30 43

    Move cursor to upper-left corner
    (Home Position)                      <CSI>H  or          9B 48
                                         <CSI>1;1H or        9B 31 3B 31 48
                                         <CSI>;1H or         9B 3B 31 48
                                         <CSI>1;H            9B 31 3B 48
    Move cursor to the fourth column
    of the first line of the window:     <CSI>1;4H or        9B 31 3B 34 48
                                         <CSI>;4H            9B 3B 34 48

    Clear the window:                    <FF> or             0C
                                         CTRL-L or
    (home and clear to end of window)    <CSI>H<CSI>J        9B 48 9B 4A
```
