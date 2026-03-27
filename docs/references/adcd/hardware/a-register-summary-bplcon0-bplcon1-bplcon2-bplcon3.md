---
title: A Register Summary / BPLCON0, BPLCON1, BPLCON2, BPLCON3
manual: hardware
chapter: hardware
section: a-register-summary-bplcon0-bplcon1-bplcon2-bplcon3
functions: []
libraries: []
---

# A Register Summary / BPLCON0, BPLCON1, BPLCON2, BPLCON3

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
BPLCON0    100      W     A D( [E](hardware/c-ecs-hardware-and-the-graphics-library-superhires-mode.md) ) Bitplane control register (misc.
```c
                                       control bits)
```
BPLCON1    102      W       D      Bitplane control register
```c
                                       (horizontal scroll control)
```
BPLCON2    104      W       D( [E](hardware/c-ecs-hardware-and-the-graphics-library-genlock-extensions.md) ) Bitplane control register

```c
                                       (video priority control)

                 These registers control the operation of the
                 bitplanes and various aspects of the display.

                 BIT#     BPLCON0    BPLCON1    BPLCON2
                 ----     --------   --------   --------
                 15       HIRES       X           X
                 14       BPU2        X           X
                 13       BPU1        X           X
                 12       BPU0        X           X
                 11       HOMOD       X           X
                 10       DBLPF       X           X
                 09       COLOR       X           X
                 08       GAUD        X           X
                 07        X         PF2H3        X
                 06        X         PF2H2      PF2PRI
                 05        X         PF2H1      PF2P2
                 04        X         PF2H0      PF2P1
                 03       LPEN       PF1H3      PF2P0
                 02       LACE       PF1H2      PF1P2
                 01       ERSY       PF1H1      PF1P1
                 00        X         PF1H0      PF1P0

               HIRES=High-resolution (70 ns pixels)
               BPU  =Bitplane use code 000-110 (NONE through 6 inclusive)
               HOMOD=Hold-and-modify mode (1 = Hold-and-modify mode (HAM);
                       0 = Extra Half Brite (EHB) if HAM=0 and BPU=6
                       and DBLPF=0 then bitplane 6 controls an intensity
                       reduction in the other five bitplanes)
               DBLPF=Double playfield (PF1=odd PF2=even bitplanes)
               COLOR=Composite video COLOR enable
               GAUD=Genlock audio enable (muxed on BKGND pin
                       during vertical blanking
               LPEN =Light pen enable (reset on power up)
               LACE =Interlace enable (reset on power up)
               ERSY =External resync (HSYNC, VSYNC pads become
                       inputs) (reset on power up)
               PF2PRI=Playfield 2 (even planes) has priority over
                       (appears in front of) playfield 1
                       (odd planes).
               PF2P=Playfield 2 priority code (with respect
                       to sprites)
               PF1P=Playfield 1 priority code (with respect
                       to sprites)
               PF2H=Playfield 2 horizontal scroll code
               PF1H=Playfield 1 horizontal scroll code
```
BPLCON3    106      W      D( [E](hardware/c-ecs-hardware-and-the-graphics-library-genlock-extensions.md) ) Bitplane control (enhanced features)

