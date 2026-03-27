---
title: G Keyboard Interface / Out-of-Sync Condition
manual: hardware
chapter: hardware
section: g-keyboard-interface-out-of-sync-condition
functions: []
libraries: []
---

# G Keyboard Interface / Out-of-Sync Condition

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Noise or other glitches may cause the keyboard to get out of sync with the
computer.  This means that the keyboard is finished transmitting a code,
but the computer is somewhere in the middle of receiving it.

If this happens, the keyboard will not receive its handshake pulse at the
end of its transmission.  If the handshake pulse does not arrive within
143 ms of the last clock of the transmission, the keyboard will assume
that the computer is still waiting for the rest of the transmission and is
therefore out of sync.  The keyboard will then attempt to restore sync by
going into "resync mode."  In this mode, the keyboard clocks out a 1 and
waits for a handshake pulse. If none arrives within 143 ms, it clocks out
another 1 and waits again.  This process will continue until a handshake
pulse arrives.

Once sync is restored, the keyboard will have clocked a garbage character
into the computer.  That is why the  [key-up/key-down flag](hardware/g-keyboard-interface-keycodes.md)  is always
transmitted last.  Since the keyboard clocks out 1's to restore sync, the
garbage character thus transmitted will appear as a key release, which is
less dangerous than a key hit.

Whenever the keyboard detects that it has lost sync, it will assume that
the computer failed to receive the keycode that it had been trying to
transmit.  Since the computer is unable to detect lost sync, it is the
keyboard's responsibility to inform the computer of the disaster.  It does
this by transmitting a "lost sync" code (value $F9 = 11111001) to the
computer. Then it retransmits the code that had been garbled.

   About Lost Sync.
   ----------------
   The only reason to transmit the "lost sync" code to the computer is
   to alert the software that something may be screwed up. The "lost
   sync" code does not help the recovery process, because the garbage
   key code can't be deleted, and the correct key code could simply be
   retransmitted without telling the computer that there was an error in
   the previous one.

