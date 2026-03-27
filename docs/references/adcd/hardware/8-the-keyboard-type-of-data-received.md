---
title: 8 / The Keyboard / Type of Data Received
manual: hardware
chapter: hardware
section: 8-the-keyboard-type-of-data-received
functions: []
libraries: []
---

# 8 / The Keyboard / Type of Data Received

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The keyboard data is not received in the form of ASCII characters.
Instead, for maximum versatility, it is received in the form of keycodes.
These codes include both the down and up transitions of the keys. This
allows your software to use both sets of information to determine exactly
what is happening on the keyboard.

Here is a list of the hexadecimal values that are assigned to the
keyboard. A downstroke of the key transmits the value shown here. An
upstroke of the key transmits this value plus $80. The picture of the
keyboard shows the positions that correspond to the description in the
sections below.

Note that raw keycodes provide positional information only, the legend
which is printed on top of the keys changes from country to country.

 [RAW Keycodes -> 00-3F hex](hardware/8-type-of-data-received-raw-keycodes-00-3f-hex.md) 
 [RAW Keycodes -> 40-5F hex  (Codes common to all keyboards)](hardware/8-type-of-data-received-raw-keycodes-40-5f-hex.md) 
 [RAW Keycodes -> 60-67 hex  (Key codes for qualifier keys)](hardware/8-type-of-data-received-raw-keycodes-60-67-hex.md) 
 [F0-FF hex](hardware/8-type-of-data-received-f0-ff-hex.md) 

