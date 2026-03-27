---
title: AIFF.doc / AIFF / Data Organization
manual: devices
chapter: devices
section: aiff-doc-aiff-data-organization
functions: []
libraries: []
---

# AIFF.doc / AIFF / Data Organization

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

All data is stored in Motorola 68000 format.  The bytes of multiple-byte
values are stored with the high-order bytes first.  Data is organized as
follows:

                7  6  5  4  3  2  1  0
	      +-----------------------+
	char: | msb              lsb  |
	      +-----------------------+

               15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0
	      +-----------------------+-----------------------+
	char: | msb    byte 0         |        byte 1     lsb |
	      +-----------------------+-----------------------+

               15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0
	      +-----------------------+-----------------------+
	char: | msb    byte 0         |        byte 1         |
	      +-----------------------+-----------------------+
	char: |        byte 2         |        byte 3     lsb |
	      +-----------------------+-----------------------+

		Figure 1: IFF data storage formats

