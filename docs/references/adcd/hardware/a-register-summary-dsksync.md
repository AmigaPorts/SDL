---
title: A Register Summary / DSKSYNC
manual: hardware
chapter: hardware
section: a-register-summary-dsksync
functions: []
libraries: []
---

# A Register Summary / DSKSYNC

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
DSKSYNC    07E      W       P     Disk sync register


```c
                 holds the match code for disk read synchronization.
                 See  [ADKCON](hardware/a-register-summary-adkcon-adkconr.md)  bit 10.
```
