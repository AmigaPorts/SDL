---
title: A Register Summary / JOY0DAT, JOY1DAT
manual: hardware
chapter: hardware
section: a-register-summary-joy0dat-joy1dat
functions: []
libraries: []
---

# A Register Summary / JOY0DAT, JOY1DAT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
JOY0DAT    00A      R       D     Joystick-mouse 0 data (left vertical,
```c
                                      horizontal)
```
JOY1DAT    00C      R       D     Joystick-mouse 1 data (right vertical,

```c
                                      horizontal)

                 These addresses each read a pair of 8-bit mouse
                 counters.  0=left controller pair, 1=right
                 controller pair (four counters total).  The bit
                 usage for both left and right addresses is shown
                 below.  Each counter is clocked by signals from
                 two controller pins.  Bits 1 and 0 of each counter
                 may be read to determine the state of these two
                 clock pins.  This allows these pins to double as
                 joystick switch inputs.

                 Mouse counter usage:
                 (pins 1,3=Yclock, pins 2,4=Xclock)

                 BIT# 15,14,13,12,11,10,09,08  07,06,05,04,03,02,01,00
                      -----------------------  -----------------------
                 0DAT Y7 Y6 Y5 Y4 Y3 Y2 Y1 Y0  X7 X6 X5 X4 X3 X2 X1 X0
                 1DAT Y7 Y6 Y5 Y4 Y3 Y2 Y1 Y0  X7 X6 X5 X4 X3 X2 X1 X0

                 The following table shows the mouse/joystick
                 connector pin usage.  The pins (and their functions)
                 are sampled (multiplexed) into the DENISE chip
                 during the clock times shown in the table.
                 This table is for reference only and should
                 not be needed by the programmer.  (Note that the
                 joystick functions are all "active low" at the
                 connector pins.)

                                            Sampled by DENISE
                 Conn   Joystick  Mouse     -----------------
                 Pin    Function  Function  Pin  Name  Clock
                 ----   --------  --------  ---  ----  -----
                 L1     FORW*        Y      38   M0V at CCK
                 L3     LEFT*        YQ     38   M0V at CCK*
                 L2     BACK*        X       9   M0H at CCK
                 L4     RIGH*        XQ      9   M0H at CCK*
                 R1     FORW*        Y      39   M1V at CCK
                 R3     LEFT*        YQ     39   M1V at CCK*
                 R2     BACK*        X       8   M1H at CCK
                 R4     RIGH*        XQ      8   M1H at CCK*

                 After being sampled, these connector pin signals
                 are used in quadrature to clock the mouse counters.
                 The LEFT and RIGHT joystick functions (active high)
                 are directly available on the Y1 and X1 bits of
                 each counter.  In order to recreate the FORWARD
                 and BACK joystick functions, however, it is
                 necessary to logically combine (exclusive OR)
                 the lower two bits of each counter.
                 This is illustrated in the following table.

                 To detect              Read these counter bits
                 --------               ----------------
                 Forward                 Y1 xor Y0 (BIT#09 xor BIT#08)
                 Left                    Y1
                 Back                    X1 xor X0 (BIT#01 xor BIT#00)
                 Right                   X1
```
