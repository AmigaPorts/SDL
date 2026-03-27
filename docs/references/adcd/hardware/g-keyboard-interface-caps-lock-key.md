---
title: G Keyboard Interface / Caps Lock Key
manual: hardware
chapter: hardware
section: g-keyboard-interface-caps-lock-key
functions: []
libraries: []
---

# G Keyboard Interface / Caps Lock Key

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This key is different from all the others in that it generates a keycode
only when it is pushed down, never when it is released. However, the
up/down bit is still used.  When pushing the Caps Lock key turns on the
Caps Lock LED, the up/down bit will be 0; when pushing Caps Lock shuts off
the LED, the up/down bit will be 1.

