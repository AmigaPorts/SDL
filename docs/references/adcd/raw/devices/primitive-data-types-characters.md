# Primitive Data Types / Characters


The following character set is assumed wherever characters are used, e.g.,
in text strings, IDs, and TEXT chunks (see below).  Characters are encoded
in 8-bit ASCII.  Characters in the range NUL (hex 0) through DEL (hex 7F)
are well defined by the 7-bit ASCII standard.  IFF uses the graphic group
" " (SP, hex 20) through "~" (hex 7E).

Most of the control character group hex 01 through hex 1F have no standard
meaning in IFF.  The control character LF (hex 0A) is defined as a
"newline" character.  It denotes an intentional line break, that is, a
paragraph or line terminator.  (There is no way to store an automatic line
break.  That is strictly a function of the margins in the environment the
text is placed.) The controlcharacter ESC (hex 1B) is a reserved escape
character under the rules of ANSI standard 3.64-1979 American National
Standard Additional Control Codes for Use with ASCII, ISO standard 2022,
and ISO/DIS standard 6429.2.

Characters in the range hex 7F through hex FF are not globally defined in
IFF. They are best left reserved for future standardization.  (Note that
the [FORM](../Devices_Manual_guide/node01C7.html#line52) type [FTXT](../Devices_Manual_guide/node0168.html) (formatted text) defines the meaning of these
characters within FTXT forms.)  In particular, character values hex 7F
through hex 9F are control codes while characters hex A0 through hex FF
are extended graphic characters like Å, as per the ISO and ANSI standards
cited above.  [See the supplementary document "FTXT" IFF Formatted Text.]

