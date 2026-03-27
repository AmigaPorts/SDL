---
title: 35 Math Libraries / Compile and Link Commands for SAS C 5.10
manual: libraries
chapter: libraries
section: 35-math-libraries-compile-and-link-commands-for-sas-c-5-10
functions: []
libraries: []
---

# 35 Math Libraries / Compile and Link Commands for SAS C 5.10

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

FFP Basic, Transcendental and Math Support functions
----------------------------------------------------


    lc -b1 -cfistq -ff -v -y <filename>.c
    blink lib:c.o + <filename>.o TO
        <filename> LIB lib:lcmffp.lib + lib:lc.lib + lib:amiga.lib
IEEE Single-Precision and Double-Precision Basic and Transcendental
Functions
-------------------------------------------------------------------

    lc -b1 -cfistq -fi -v -y <filename>.c
    blink lib:c.o + <filename>.o TO
         <filename> LIB lib:lcmieee.lib + lib:lc.lib + lib:amiga.lib
