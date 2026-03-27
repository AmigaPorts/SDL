---
title: 4 / Reading from the Console Device / Cursor Position Report
manual: devices
chapter: devices
section: 4-reading-from-the-console-device-cursor-position-report
functions: []
libraries: []
---

# 4 / Reading from the Console Device / Cursor Position Report

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If you have sent the DEVICE STATUS REPORT command sequence, the console
device returns a cursor position report into your input stream.  It takes
the form:


```c
    <CSI><row>;<column>R
```
For example, if the cursor is at column 40 and row 12, here are the ASCII
values (in hex) you receive in a stream:


    9B 34 30 3B 31 32 52
