---
title: E / / Game Controller Interface Specification / Digital Joysticks
manual: hardware
chapter: hardware
section: e-game-controller-interface-specification-digital-joysticks
functions: []
libraries: []
---

# E / / Game Controller Interface Specification / Digital Joysticks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A joystick is a device with four normally opened switches arranged 90
degrees apart.  The  [JOY[0/1]DAT](../Hardware_Manual_guide/node0038.html)  registers become encoded switch input
ports as follows:


        Forward:  bit#9 xor bit#8
        Left:     bit#9
        Back:     bit#1 xor bit#0
        Right:    bit#1
Data is encoded to facilitate the mouse/trackball operating mode.

   NOTE:
   -----
   The right and left direction inputs are also designed to be right and
   left buttons, respectively, for use with proportional inputs.  In
   this case, the forward and back inputs are not used, while right and
   left become button inputs rather than joystick inputs.

The  [JOY[0/1]DAT](../Hardware_Manual_guide/node0038.html)  registers are always valid and may be read at any time.


CONNECTOR PIN USAGE FOR DIGITAL JOYSTICK INPUTS
-----------------------------------------------

   PIN   MNEMONIC   DESCRIPTION                 HARDWARE REGISTER/NOTES
   ---   --------   -----------                 -----------------------
   1      FORWARD*  Forward joystick switch     JOY[0/1]DAT<9 xor 8>
   2      BACK*     Back joystick switch        JOY[0/1]DAT(1 xor 0>
   3      LEFT*     Left joystick switch        JOY[0/1]DAT<9>
   4      RIGHT*    Right joystick switch       JOY[0/1]DAT<1>
   5      Unused
   6      FIRE*     Left mouse button           See  [Fire Button](hardware/e-game-controller-interface-specification-fire-buttons.md) .
   7      +5V       125ma max, 200ma surge      Total both ports.
   8      Ground
   9      Unused

