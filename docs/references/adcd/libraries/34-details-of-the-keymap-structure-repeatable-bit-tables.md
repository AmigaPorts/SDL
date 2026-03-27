---
title: 34 / / Details Of the Keymap Structure / Repeatable Bit Tables
manual: libraries
chapter: libraries
section: 34-details-of-the-keymap-structure-repeatable-bit-tables
functions: []
libraries: []
---

# 34 / / Details Of the Keymap Structure / Repeatable Bit Tables

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The vectors [km_LoRepeatable](libraries/34-keymap-functions-details-of-the-keymap-structure.md) and [km_HiRepeatable](libraries/34-keymap-functions-details-of-the-keymap-structure.md) each point to an array of
8 bytes that contain additional information about the keytable entries. A
bit for each key indicates whether or not the specified key should repeat
at the rate set by the Input Preferences program.

The bit positions correspond to those specified in the [capsable](libraries/34-details-of-the-keymap-structure-capsable-bit-tables.md) bit table.
If there is a 1 in a specific position, the key can repeat. There are 64
bits (8 bytes) in each of the two repeatable tables.

