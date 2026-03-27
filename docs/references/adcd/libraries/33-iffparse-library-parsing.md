---
title: 33 IFFParse Library / Parsing
manual: libraries
chapter: libraries
section: 33-iffparse-library-parsing
functions: []
libraries: []
---

# 33 IFFParse Library / Parsing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is both simple and complicated.  It's simple in that it's just one
call.  It's complicated in that you have to seize control of the parser to
get your data.

The parser operates automatically, scanning the file, verifying syntax and
layout rules.  If left to its default behavior, it will scan through the
entire file until it reaches the end, whereupon it will tell you that it
got to the end.

The whole scanning procedure is controlled through one call:


```c
    error = ParseIFF (iff, controlmode);
```
The control modes are IFFPARSE_SCAN, [IFFPARSE_STEP](libraries/33-other-parsing-modes-iffparse-step.md) and [IFFPARSE_RAWSTEP](libraries/33-other-parsing-modes-iffparse-rawstep.md).
For now, only the IFFPARSE_SCAN control mode is considered.

 [Controlling Parsing](libraries/33-parsing-controlling-parsing.md)                 [Reading Chunk Data](libraries/33-parsing-reading-chunk-data.md) 
 [Putting It Together](libraries/33-parsing-putting-it-together.md)                 [Other Parsing Modes](libraries/33-parsing-other-parsing-modes.md) 
 [Other Chunk Management Functions](libraries/33-parsing-other-chunk-management-functions.md) 

