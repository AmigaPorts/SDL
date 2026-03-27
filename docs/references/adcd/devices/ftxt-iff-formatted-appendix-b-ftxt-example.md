---
title: FTXT IFF Formatted / Appendix B. FTXT Example
manual: devices
chapter: devices
section: ftxt-iff-formatted-appendix-b-ftxt-example
functions: []
libraries: []
---

# FTXT IFF Formatted / Appendix B. FTXT Example

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Here's a box diagram for a simple example: "The quick brown fox jumped.
Four score and seven", written in a proportional serif font named "Roman".


	          +-----------------------+
	          |                       |
	          |   'FORM'        86    |  FORM 86 FTXT
	          |                       |
	       -- +-----------------------+
	       |  |                       |
	       |  |   'FTXT'              |
	       |  |                       |
	       |  |  +-----------------+  |
	       |  |  | 'FONS'      10  |  |  .FONS 10
	       |  |  |-----------------|  |
	       |  |  | 01, 00, 02, 02  |  |
	       |  |  |-----------------|  |
	       |  |  | Roman\0         |  |
	       |  |  +-----------------+  |
	       |  |                       |
	       |  |  +-----------------+  |
	  86  <   |  | 'CHRS'      27  |  |  .CHRS 27
	 bytes |  |  |-----------------|  |
	       |  |  | The quick brown |  |
	       |  |  | fox jumped      |  |
	       |  |  +-----------------+  |
	       |  |    0                  |
	       |  |  +-----------------+  |
	       |  |  | 'CHRS'      20  |  |  .CHRS 20
	       |  |  |-----------------|  |
	       |  |  | Four score and  |  |
	       |  |  | seven           |  |
	       |  |  +-----------------+  |
	       |  |                       |
	       -- +-----------------------+

The "0" after the first [CHRS](devices/standard-data-and-property-chunks-data-chunk-chrs.md) chunk is a pad byte.

