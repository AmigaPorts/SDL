---
title: 4 / Reading from the Console Device / Window Bounds Report
manual: devices
chapter: devices
section: 4-reading-from-the-console-device-window-bounds-report
functions: []
libraries: []
---

# 4 / Reading from the Console Device / Window Bounds Report

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A user may have either moved or resized the window to which your console
is bound.  By issuing a WINDOW STATUS REPORT to the console, you can read
the current position and size in the input stream.  This window bounds
report takes the following form:


```c
    <CSI>1;1;<bottom margin>;<right margin> r
```
The bottom and right margins give you the window row and column dimensions
as well. For a window that holds 20 lines with 60 characters per line, you
will receive the following in the input stream:


    9B 31 3B 31 3B 32 30 3B 36 30 20 72
