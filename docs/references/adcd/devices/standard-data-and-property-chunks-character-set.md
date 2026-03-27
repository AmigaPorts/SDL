---
title: Standard Data and Property Chunks / Character Set
manual: devices
chapter: devices
section: standard-data-and-property-chunks-character-set
functions: []
libraries: []
---

# Standard Data and Property Chunks / Character Set

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[FORM FTXT](devices/ftxt-iff-formatted-text-introduction.md) uses the core of the 8-bit character set defined by the ISO/ANSI
standards cited at the start of this document.  (See [Appendix A](devices/ftxt-iff-formatted-appendix-a-character-code-table.md) for a
character code table.)  This character set is divided into two "graphic"
groups plus two "control" groups.  Eight of the control characters begin
ISO/ANSI standard control sequences.  (See "[Control Sequences](devices/standard-data-and-property-chunks-control-sequences.md)", below.)
Most control sequences and control characters are reserved for future use
and for compatibility with ISO/ANSI.  Current reader programs should skip
them.

* C0 is the group of control characters in the range NUL (hex 0) through
  hex 1F.  Of these, only LF (hex 0A) and ESC (hex 1B) are significant.
  ESC begins a control sequence.  LF is the line terminator, meaning "go
  to the first horizontal position of the next line".  All other C0
  characters are not used.  In particular, CR (hex 0D) is not recognized
  as a line terminator.

* G0 is the group of graphic characters in the range hex 20 through hex
  7F.  SP (hex 20) is the space character.  DEL (hex 7F) is the delete
  character which is not used.  The rest are the standard ASCII printable
  characters "!" (hex 21) through "~" (hex 7E).

* C1 is the group of extended control characters in the range hex 80
  through hex 9F.  Some of these begin control sequences.  The control
  sequence starting with CSI (hex 9B) is used for [FTXT](devices/ftxt-iff-formatted-text-introduction.md) formatting.  All
  other control sequences and C1 control characters are unused.

* G1 is the group of extended graphic characters in the range NBSP (hex
  A0) through "ÿ" (hex FF).  It is one of the alternate graphic groups
  proposed for ISO/ANSI standardization.

