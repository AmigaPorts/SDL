---
title: Glossary / burst
manual: hardware
chapter: hardware
section: glossary-burst
functions: []
libraries: []
---

# Glossary / burst

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A short name for Multiple Transfer Cycle mode.  Essentially, within one
full Zorro III cycle there can be any number of Multiple Transfer Cycles.
Each full cycle has a complete 32-bit address supplied and a complete
32-bit datum transferred.  Each burst cycle supplies only the 8-bit page
address, but transfers a complete 32-bit datum faster than the standard
full cycle would allow.

