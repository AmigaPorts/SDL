---
title: ILBM.DRNG.doc / Enhanced Color Cycling Capabilities
manual: devices
chapter: devices
section: ilbm-drng-doc-enhanced-color-cycling-capabilities
functions: []
libraries: []
---

# ILBM.DRNG.doc / Enhanced Color Cycling Capabilities

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* DPaintIV supports a new color cycling model which does NOT
  require that color cycles contain a contiguous range of color
  registers.

For example:
  If your range looks like:  [1][3][8][2]
  then at each cycle tick

```c
     temp = [2],
     [2] = [8],
     [8] = [3],
     [3] = [1],
     [1] = temp
```
* You can now cycle a single register thru a series of rgb values.
  For example:

```c
     If your range looks like: [1] [orange] [blue] [purple]
     then at each cycle tick color register 1 will take on the
     next color in the cycle.

     ie:  t=0:  [1] = curpal[1]
          t=1:  [1] = purple
          t=2:  [1] = blue
          t=3:  [1] = orange
          t=4:  goto t=0
```
* You can combine rgb cycling with traditional color cycling.
  For example:

```c
      Your range can look like:
          [1] [orange] [blue] [2] [green] [yellow]

      t=0: [1] = curpal[1], [2] = curpal[2]
      t=1: [1] = yellow,    [2] = blue
      t=2: [1] = green,     [2] = orange
      t=3: [1] = curpal[2], [2] = curpal[1]
      t=4: [1] = blue,      [2] = yellow
      t=5: [1] = orange,    [2] = green
      t=6: goto t=0
```
Note:
   * DPaint will save out an old style range CRNG if the range fits
     the CRNG model otherwise it will save out a DRNG chunk.
   * no thought has been given (yet) to interlocking cycles

