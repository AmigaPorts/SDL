---
title: ILBM.CLUT.doc / CLUT Example
manual: devices
chapter: devices
section: ilbm-clut-doc-clut-example
functions: []
libraries: []
---

# ILBM.CLUT.doc / CLUT Example

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Normally, the CLUT chunk will appear after the BMHD of an FORM ILBM before
the BODY chunk, in the same "section" as CMAPs are normally found.
However, a FORM may contain only CLUTs with no other supporting
information.

As a general guideline, it is desirable to group all CLUTs together in a
form without other chunk types between them. If you were using CLUTs to
store RGB intensity corrections, you would write three CLUTs in a row, R,
G, then B.

Here is a box diagram for a 320x200x8 image stored as an IFF ILBM with a
single CLUT chunk for intensity mapping:


```c
      	+-----------------------------------+
      	|'FORM'		64284		    |     FORM 64284 ILBM
      	+-----------------------------------+
      	|'ILBM'				    |
      	+-----------------------------------+
      	| +-------------------------------+ |
      	| | 'BMHD'	20		  | |     .BMHD 20
      	| | 320, 200, 0, 0, 8, 0, 0, ...  | |
      	| | ------------------------------+ |
      	| | 'CLUT'	264	          | |     .CLUT 264
      	| | 0, 0, 0; 32, 0, 0; 64,0,0; .. | |
      	| +-------------------------------+ |
      	| +-------------------------------+ |
      	| |'BODY'		64000     | |     .BODY 64000
      	| |0, 0, 0, ...			  | |
      	| +-------------------------------+ |
      	+-----------------------------------+
```
