---
title: 9 Intuition Input and Output Methods / Overview of System I/O
manual: libraries
chapter: libraries
section: 9-intuition-input-and-output-methods-overview-of-system-i-o
functions: []
libraries: []
---

# 9 Intuition Input and Output Methods / Overview of System I/O

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This section provides a very simplified model of how Amiga I/O and
application programs interact.  The main elements of the Amiga's I/O
system are shown in the diagram below.  Input events begin when mouse
movement is detected by the gameport device or key presses are received by
the keyboard device.  These and other input events are merged into a
single stream by the input device, which then submits the stream to
Intuition for further processing.


```c
     [Figure 9-1: Amiga Input Block Diagram](libraries/lib-pics-9-1-pic.md) 
```
The application program can receive its input from Intuition or the
Console device.  The application may choose to listen to neither, one or
both of these input sources.


```c
     [Figure 9-2: Amiga Output Block Diagram](libraries/lib-pics-9-2-pic.md) 
```
An application's display output can go through the high level interfaces
of the console device or through the Intuition library.  Additionally,
display output may be sent directly to the graphics library.  Notice that
both the Console and Intuition call the graphics library to render to the
display.

