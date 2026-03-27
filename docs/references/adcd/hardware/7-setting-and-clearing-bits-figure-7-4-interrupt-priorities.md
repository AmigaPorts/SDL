---
title: 7 / / Setting and Clearing Bits / Figure 7-4: Interrupt Priorities
manual: hardware
chapter: hardware
section: 7-setting-and-clearing-bits-figure-7-4-interrupt-priorities
functions: []
libraries: []
---

# 7 / / Setting and Clearing Bits / Figure 7-4: Interrupt Priorities

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

               Exec
Hardware     Software
Priority     Priority     Description                  Name
--------     --------     -----------                  ----
```c
           ____
          |     1         transmitter buffer empty     [TBE](hardware/7-setting-and-clearing-bits-serial-port-interrupts.md) 
          |
```
   1 -----|     2         disk block complete          [DSKBLK](hardware/7-setting-and-clearing-bits-disk-interrupt.md) 
          |
          |     3         software interrupt           SOFTINT
          |----
   2 -----|     4         external INT2 & CIAA         [PORTS](hardware/7-setting-and-clearing-bits-external-interrupts.md) 
```c
          |----
          |     5         graphics coprocessor         [COPER](hardware/7-setting-and-clearing-bits-copper-interrupt.md) 
          |
```
   3 -----|     6         vertical blank interval      [VERTB](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md) 
```c
          |
          |     7         blitter finished             [BLIT](hardware/7-setting-and-clearing-bits-blitter-interrupt.md) 
          |----
          |     8         audio channel 2              [AUD2](hardware/7-setting-and-clearing-bits-audio-interrupts.md) 
          |
          |     9         audio channel 0              [AUD0](hardware/7-setting-and-clearing-bits-audio-interrupts.md) 
```
   4 -----|
```c
          |     10        audio channel 3              [AUD3](hardware/7-setting-and-clearing-bits-audio-interrupts.md) 
          |
          |     11        audio channel 1              [AUD1](hardware/7-setting-and-clearing-bits-audio-interrupts.md) 
          |----
          |     12        receiver buffer full         [RBF](hardware/7-setting-and-clearing-bits-serial-port-interrupts.md) 
```
   5 -----|
```c
          |     13        disk sync pattern found      [DSKSYNC](hardware/7-setting-and-clearing-bits-disk-interrupt.md) 
          |----
          |     14        external INT6 & CIAB         [EXTER](hardware/7-setting-and-clearing-bits-external-interrupts.md) 
```
   6 -----|
```c
          |     15        special (master enable)      [INTEN](hardware/7-setting-and-clearing-bits-master-interrupt-enable.md) 
          |----
```
   7 -----|____ --        non-maskable interrupt       [NMI](hardware/7-setting-and-clearing-bits-set-and-clear.md) 

