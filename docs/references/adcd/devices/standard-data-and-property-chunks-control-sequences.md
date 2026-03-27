---
title: Standard Data and Property Chunks / Control Sequences
manual: devices
chapter: devices
section: standard-data-and-property-chunks-control-sequences
functions: []
libraries: []
---

# Standard Data and Property Chunks / Control Sequences

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Eight of the control characters begin ISO/ANSI standard "control
sequences" (or "escape sequences").  These sequences are described below
and diagramed in [Appendix C](devices/ftxt-iff-formatted-appendix-c-iso-ansi-control-sequences.md).

	G0	  ::= (SP through DEL)
	G1	  ::= (NBSP through "ÿ")

	ESC-Seq	  ::= ESC (SP through "/") * ("0" through "~")
	ShiftToG2 ::= SS2 G0
	ShiftToG3 ::= SS3 G0
	CSI-Seq	  ::= CSI (SP through "?") * ("@" through "~")
	DCS-Seq   ::= (DCS | OSC | PM | APC) (SP through "~" | G1) * ST

"ESC-Seq" is the control sequence ESC (hex 1B), followed by zero or more
characters in the range SP through "/" (hex 20 through hex 2F), followed
by a character in the range "0" through "~" (hex 30 through hex 7E).
These sequences are reserved for future use and should be skipped by
current [FTXT](devices/ftxt-iff-formatted-text-introduction.md) reader programs.

SS2 (hex 8E) and SS3 (hex 8F) shift the single following G0 character into
yet-to-be-defined graphic sets G2 and G3, respectively.  These sequences
should not be used until the character sets G2 and G3 are standardized.  A
reader may simply skip the SS2 or SS3 (taking the following character as a
corresponding G0 character) or replace the two-character sequence with a
character like "?" to mean "absent".

[FTXT](devices/ftxt-iff-formatted-text-introduction.md) uses "CSI-Seq" control sequences to store character formatting (font
selection by number, type face, and text size) and perhaps layout
information (position and rotation).  "CSI-Seq" control sequences start
with CSI (the "control sequence introducer", hex 9B).  Syntactically, the
sequence includes zero or more characters in the range SP through "?" (hex
20 through hex 3F) and a concluding character in the range "@" through "~"
(hex 40 through hex 7E).  These sequences may be skipped by a minimal [FTXT](devices/ftxt-iff-formatted-text-introduction.md)
reader, i.e., one that ignores formatting information.

Note: A future [FTXT](devices/ftxt-iff-formatted-text-introduction.md) standardization document will explain the uses of
CSI-Seq sequences for setting character face (light weight vs. medium vs.
bold, italic vs. upright, height, pitch, position, and rotation).  For
now, consult the ISO/ANSI references.

"DCS-Seq" is the control sequences starting with DCS (hex 90), OSC (hex
9D), PM (hex 9E), or APC (hex 9F), followed by zero or more characters
each of which is in the range SP through "~" (hex 20 through hex 7E) or
else a G1 character, and terminated by an ST (hex 9C).  These sequences
are reserved for future use and should be skipped by current [FTXT](devices/ftxt-iff-formatted-text-introduction.md) reader
programs.

