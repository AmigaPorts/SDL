---
title: G Keyboard Interface / Special Codes
manual: hardware
chapter: hardware
section: g-keyboard-interface-special-codes
functions: []
libraries: []
---

# G Keyboard Interface / Special Codes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The special codes that the keyboard uses to communicate with the main unit
are summarized here.

   About the special codes.
   ------------------------
   The special codes are 8-bit numbers; there is no  [up/down flag](hardware/g-keyboard-interface-keycodes.md) 
   associated with them.  However, the  [transmission bit order](hardware/g-keyboard-interface-keyboard-communications.md)  is the
   same as previously described.



```c
        Code       Name            Meaning
        --------------------------------------------------------------
        78       [Reset warning](hardware/g-keyboard-interface-reset-warning.md) .  Ctrl-Amiga-Amiga has been hit -
                computer will be reset in 10 seconds. (see text)
        F9      Last key code bad, next code is the same code
                   retransmitted (used when keyboard and main unit
                   get  [out of sync](hardware/g-keyboard-interface-out-of-sync-condition.md) ).
        FA      Keyboard output buffer overflow
        FB      Unused (was controller failure)
        FC      Keyboard  [selftest failed](hardware/g-keyboard-interface-power-up-sequence.md) 
        FD      Initiate  [power-up key stream](hardware/g-keyboard-interface-power-up-sequence.md)  (keys pressed at powerup)
        FE      Terminate  [power-up key stream](hardware/g-keyboard-interface-power-up-sequence.md) 
        FF      Unused (was interrupt)
```
