---
title: FTXT IFF Formatted / Appendix C. ISO/ANSI Control Sequences
manual: devices
chapter: devices
section: ftxt-iff-formatted-appendix-c-iso-ansi-control-sequences
functions: []
libraries: []
---

# FTXT IFF Formatted / Appendix C. ISO/ANSI Control Sequences

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is a racetrack diagram of the ISO/ANSI characters and control
sequences as used in FTXT CHRS chunks.

     line terminator
---+-----------------> LF------------------------------------------------>
   |
   |\  ESC-Seq
   | +---------------> ESC--------------------------+---> 0 through ~ --->
   |                        |                       |
   |                        +<----SP through \  <---+
   |
   |\  printable
   | +----------+----> SP through ~ ------------------------------------->
   |            |                      /
   |            +----> G1------------>+
   |
   |\  ShiftToG2
   | +---------------> G0----------------------> (produces a G2 character)
   |
   |\  ShiftToG3
   | +---------------> G0----------------------> (produces a G3 character)
   |
   |
   |\  CSI-Seq
   | +--------------> CSI--+-----------------------+----> @ through ~ --->
   |                       |                       |
   |                       +<--- SP through ?  <---+
   |
   |\  DCS-Seq
   | +---------> DCS, OSC,-+-----------------------+----------> ST ------>
   |             PM, APC   |                       |    \
   |                       +<--- SP through ~  <---+     +----> G1 ------>
   |


    \  discard
     +--------------------> any other character-------------------------->
Of the various control sequences, only CSI-Seq is used for [FTXT](devices/ftxt-iff-formatted-text-introduction.md) character
formatting information.  The others are reserved for future use and for
compatibility with ISO/ANSI standards.  Certain character sequences are
syntactically malformed, e.g., CSI followed by a C0, C1, or G1 character.
Writer programs should not generate reserved or malformed sequences and
reader programs should skip them.

Consult the ISO/ANSI standards for the meaning of the CSI-Seq control
sequences.

The two character set shifts SS2 and SS3 may be used when the graphic
character groups G2 and G3 become standardized.

