---
title: Memory
manual: amiga-mail
chapter: amiga-mail
section: memory
functions: []
libraries: []
---

# Memory

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An Amiga with an A570 may have various amounts of RAM.  In a CDTV the
minimum memory configuration is 1 Mbyte of Chip RAM.  Do not assume
that all systems have the same memory configuration.  Some users might
try to run your application on an Amiga + A570 with only 512K of Chip
RAM and no Fast RAM.  Others may have a 512K Chip/512K Fast RAM system.
To avoid crashing due to memory shortages, check the amount of memory
available when your application begins execution.  If not enough memory
is available, you should display a message to that effect and stop
operating rather than crashing the machine.

Others may have more than 1 Mbyte of RAM: either Fast or Chip memory.
Your title should also work properly under these conditions.

