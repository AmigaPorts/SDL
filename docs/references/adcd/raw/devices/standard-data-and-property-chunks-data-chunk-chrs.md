# Standard Data and Property Chunks / Data Chunk CHRS


A CHRS chunk contains a sequence of 8-bit characters abiding by the
ISO/ANSI standards cited at the start of this document.  This includes the
character set and control sequences as described above and summarized in
[Appendix A](../Devices_Manual_guide/node0172.html) and [Appendix C](../Devices_Manual_guide/node0174.html).

A [FORM FTXT](../Devices_Manual_guide/node0168.html) may contain any number of CHRS chunks.  Taken together, they
represent a single stream of textual information.  That is, the contents
of CHRS chunks are effectively concatenated except that (1) each control
sequence must be completely within a single CHRS chunk, and (2) any
formatting property chunks appearing between two CHRS chunks affects the
formatting of the latter chunk's text.  Any formatting settings set by
control sequences inside a CHRS carry over to the next CHRS in the same
[FORM FTXT](../Devices_Manual_guide/node0168.html).  All formatting properties stop at the end of the [FORM](../Devices_Manual_guide/node01C7.html#line51) since
IFF specifies that adjacent FORMs are independent of each other (although
not independent of any properties inherited from an enclosing [LIST](../Devices_Manual_guide/node01CA.html#line49) or
FORM).

