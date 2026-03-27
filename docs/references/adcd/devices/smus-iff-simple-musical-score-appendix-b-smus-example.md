---
title: SMUS IFF Simple Musical Score / Appendix B. SMUS Example
manual: devices
chapter: devices
section: smus-iff-simple-musical-score-appendix-b-smus-example
functions: []
libraries: []
---

# SMUS IFF Simple Musical Score / Appendix B. SMUS Example

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Here's a box diagram for a simple example, a [SMUS](devices/smus-iff-simple-musical-score-introduction.md) with two instruments and
two tracks.  Each track contains 1 note event and 1 rest event.

	          +-----------------------+
	          |                       |
	          |   'FORM'        94    |  FORM 94 SMUS
	          |                       |
	       -- +-----------------------+
	       |  |                       |
	       |  |   'SMUS'              |
	       |  |                       |
	       |  |  +-----------------+  |
	       |  |  | 'SHDR'       4  |  |  .SHDR 4
	       |  |  |-----------------|  |
	       |  |  | 12800, 127, 2   |  |
	       |  |  +-----------------+  |
	       |  |                       |
	       |  |  +-----------------+  |
	       |  |  | 'NAME'      10  |  |  .NAME 10
	       |  |  |-----------------|  |
	       |  |  | 'Fugue in C'    |  |
	       |  |  +-----------------+  |
	       |  |                       |
	       |  |  +-----------------+  |
	       |  |  | 'INS1'      9   |  |  .INS1 9
	       |  |  |-----------------|  |
	       |  |  |   1, 0, 0, 0,   |  |
	       |  |  |   'Piano'       |  |
	  94  <   |  +-----------------+  |
	 bytes |  |    0                  |
	       |  |  +-----------------+  |
	       |  |  | 'INS1'      10  |  |  .INS1 10
	       |  |  |-----------------|  |
	       |  |  |   2, 0, 0, 0,   |  |
	       |  |  |   'Guitar'      |  |
	       |  |  +-----------------+  |
	       |  |                       |
	       |  |  +-----------------+  |
	       |  |  | 'TRAK'       4  |  |  .TRAK 4
	       |  |  |-----------------|  |
	       |  |  | 60, 16, 128, 16 |  |
	       |  |  +-----------------+  |
	       |  |                       |
	       |  |  +-----------------+  |
	       |  |  | 'TRAK'       4  |  |  .TRAK 4
	       |  |  |-----------------|  |
	       |  |  | 128, 16, 60, 16 |  |
	       |  |  +-----------------+  |
	       |  |                       |
	       -- +-----------------------+

The "0" after the first INS1 chunk is a pad byte.

