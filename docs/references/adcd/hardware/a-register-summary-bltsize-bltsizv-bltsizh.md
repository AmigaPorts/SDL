---
title: A Register Summary / BLTSIZE, BLTSIZV, BLTSIZH
manual: hardware
chapter: hardware
section: a-register-summary-bltsize-bltsizv-bltsizh
functions: []
libraries: []
---

# A Register Summary / BLTSIZE, BLTSIZV, BLTSIZH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
BLTSIZE    058      W       A      Blitter start and size (window width,

```c
                                       height)

                 This register contains the width and height of
                 the blitter operation (in line mode, width must
                 = 2, height = line length).  Writing to this
                 register will start the blitter, and should be
                 done last, after all pointers and control
                 registers have been initialized.

                 BIT#  15,14,13,12,11,10,09,08,07,06,05,04,03,02,01,00
                       -----------------------------------------------
                       h9 h8 h7 h6 h5 h4 h3 h2 h1 h0,w5 w4 w3 w2 w1 w0

                 h=height=vertical lines (10 bits=1024 lines max)
                 w=width =horizontal pixels (6 bits=64
                                      words=1024 pixels max)

                 LINE DRAW   BLTSIZE controls the line length and starts
                 LINE DRAW   the line draw when written to.  The h field
                 LINE DRAW   controls the line length (10 bits gives
                 LINE DRAW   lines up to 1024 dots long).  The w field
                 LINE DRAW   must be set to 02 for all line drawing.
```
BLTSIZV    05C      W      A( [E](hardware/c-ecs-hardware-and-the-graphics-library-big-blits.md) ) Blitter V size (for 15 bit vertical size)
BLTSIZH    05E      W      A( [E](hardware/c-ecs-hardware-and-the-graphics-library-big-blits.md) ) Blitter H size and start (for 11 bit

```c
                                      H size)
```
