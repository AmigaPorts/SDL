---
title: 8 / / Type Of Data Received / F0-FF hex
manual: hardware
chapter: hardware
section: 8-type-of-data-received-f0-ff-hex
functions: []
libraries: []
---

# 8 / / Type Of Data Received / F0-FF hex

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

These key codes are used for keyboard to 680x0 communication, and are not
associated with a keystroke. They have no key transition flag, and are
therefore described completely by 8-bit codes:

   78      Reset warning.  Ctrl-Amiga-Amiga has been pressed. The

```c
           keyboard will wait a maximum of 10 seconds before
           resetting the machine. (Not available on all keyboard
           models)
```
   F9      Last key code bad, next key is same code retransmitted

   FA      Keyboard key buffer overflow

   FC      Keyboard self-test fail.  Also, the caps-lock LED will

           blink to indicate the source of the error.  Once for ROM
           failure, twice for RAM failure and three times if the
           watchdog timer fails to function.
   FD      Initiate power-up key stream (for keys held or stuck at

```c
           power on)
```
   FE      Terminate power-up key stream.

These key codes will usually be filtered out by keyboard drivers.

