---
title: G Keyboard Interface / Power-Up Sequence
manual: hardware
chapter: hardware
section: g-keyboard-interface-power-up-sequence
functions: []
libraries: []
---

# G Keyboard Interface / Power-Up Sequence

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are two possible ways for the keyboard to be powered up under normal
circumstances: <1> the computer can be turned on with the keyboard plugged
in, or <2> the keyboard can be plugged into an already "on" computer.  The
keyboard and computer must handle either case without causing any upset.

The first thing the keyboard does on power-up is to perform a self-test.
This involves a ROM checksum test, simple RAM test, and watchdog timer
test.  Whenever the keyboard is powered up (or  [restarted](hardware/g-keyboard-interface-reset-warning.md)  -- see below), it
must not transmit anything until it has achieved synchronization with the
computer. The way it does this is by slowly  [clocking out 1 bits](hardware/g-keyboard-interface-out-of-sync-condition.md) , as
described above, until it receives a handshake pulse.

If the keyboard is plugged in before power-up, the keyboard may continue
this process for several minutes as the computer struggles to boot up and
get running.  The keyboard must continue clocking out 1s for however long
is necessary, until it receives its handshake.

If the keyboard is plugged in after power-up, no more than eight clocks
will be needed to achieve sync.  In this case, however, the computer may
be in any state imaginable but must not be adversely affected by the
 [garbage character](hardware/g-keyboard-interface-out-of-sync-condition.md)  it will receive.  Again, because it receives a key
release, the damage should be minimal.  The keyboard driver must
anticipate this happening and handle it, as should any application that
uses raw keycodes.

   Warning:
   --------
   The keyboard must not transmit a " [lost sync](hardware/g-keyboard-interface-out-of-sync-condition.md) " code after
   re-synchronizing due to a power-up or  [restart](hardware/g-keyboard-interface-reset-warning.md) ; only after
   re-synchronizing due to a handshake time-out.

Once the keyboard and computer are in sync, the keyboard must inform the
computer of the results of the self-test.  If the self-test failed for any
reason, a "selftest failed" code (value $FC = 11111100) is transmitted
(the keyboard does not wait for a handshake pulse after sending the
"selftest failed" code).  After this, the keyboard processor goes into a
loop in which it blinks the Caps Lock LED to inform the user of the
failure.  The blinks are coded as bursts of one, two, three, or four
blinks, approximately one burst per second:


```c
     One blink        ROM checksum failure.
     Two blinks       RAM test failed.
     Three blinks     Watchdog timer test failed.
     Four blinks      A short exists between two row lines or one of
                          the seven special keys (not implemented).
```
If the self-test succeeds, then the keyboard will proceed to transmit any
keys that are currently down.  First, it sends an "initiate power-up key
stream" code (value $FD = 11111101), followed by the key codes of all
depressed keys (with keyup/down set to "down" for each key).  After all
keys are sent (usually there won't be any at all), a "terminate key
stream" code (value $FE = 11111110) is sent.  Finally, the Caps Lock LED
is shut off. This marks the end of the start-up sequence, and normal
processing commences.

The usual sequence of events will therefore be:  power-up; synchronize;
transmit "initiate power-up key stream" ($FD); transmit "terminate key
stream" ($FE).

