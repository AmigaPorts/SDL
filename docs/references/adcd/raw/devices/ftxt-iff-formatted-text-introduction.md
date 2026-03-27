# FTXT IFF Formatted Text / Introduction


This memo is the IFF supplement for FORM FTXT.  An FTXT is an IFF "data
section" or "[FORM](../Devices_Manual_guide/node01C7.html#line51) type" - which can be an IFF file or a part of one -
containing a stream of text plus optional formatting information.
[EA IFF 85](../Devices_Manual_guide/node01C5.html) is Electronic Arts' standard for interchange format files.
(See the IFF reference.)

An FTXT is an archival and interchange representation designed for three
uses. The simplest use is for a "console device" or "glass teletype" (the
minimal 2-D text layout means): a stream of "graphic" ("printable")
characters plus positioning characters "space" ("SP") and line terminator
("LF").  This is not intended for cursor movements on a screen although it
does not conflict with standard cursor-moving characters.  The second use
is text that has explicit formatting information (or "looks") such as font
family and size, typeface, etc.  The third use is as the lowest layer of a
structured document that also has "inherited" styles to implicitly control
character looks.  For that use, FORMs FTXT would be embedded within a
future document [FORM](../Devices_Manual_guide/node01C7.html#line51) type.  The beauty of FTXT is that these three uses
are interchangeable, that is, a program written for one purpose can read
and write the others' files.  So a word processor does not have to write a
separate plain text file to communicate with other programs.

Text is stored in one or more "[CHRS](../Devices_Manual_guide/node016D.html)" chunks inside an FTXT.  Each CHRS
contains a stream of 8-bit text compatible with ISO and ANSI data
interchange standards.  FTXT uses just the central character set from the
ISO/ANSI standards.  (These two standards are henceforth called "ISO/ANSI"
as in "see the ISO/ANSI reference".)

Since it's possible to extract just the text portions from future document
[FORM](../Devices_Manual_guide/node01C7.html#line51) types, programs can exchange data without having to save both plain
text and formatted text representations.

Character looks are stored as embedded control sequences within [CHRS](../Devices_Manual_guide/node016D.html)
chunks. This document specifies which class of control sequences to use:
the CSI group.  This document does not yet specify their meanings, e.g.,
which one means "turn on italic face".  Consult ISO/ANSI.

Section 2 defines the chunk types character stream "[CHRS](../Devices_Manual_guide/node016D.html)" and font
specifier "[FONS](../Devices_Manual_guide/node016E.html)".  These are the "standard" chunks.  Specialized chunks
for private or future needs can be added later.  Section 3 outlines an
FTXT reader program that strips a document down to plain unformatted text.
[Appendix A](../Devices_Manual_guide/node0172.html) is a code table for the 8-bit ISO/ANSI character set used here.
[Appendix B](../Devices_Manual_guide/node0173.html) is an example FTXT shown as a box diagram.  [Appendix C](../Devices_Manual_guide/node0174.html) is a
racetrack diagram of the syntax of ISO/ANSI control sequences.

 [Reference](../Devices_Manual_guide/node0169.html) 

