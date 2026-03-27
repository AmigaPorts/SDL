---
title: A Register Summary / REFPTR
manual: hardware
chapter: hardware
section: a-register-summary-refptr
functions: []
libraries: []
---

# A Register Summary / REFPTR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
REFPTR     028      W       A      Refresh pointer


                 This register is used as a dynamic RAM refresh
                 address generator. It is writeable for test
                 purposes only, and should never be written by
                 the microprocessor.
