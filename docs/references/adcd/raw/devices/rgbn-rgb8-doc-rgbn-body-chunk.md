# RGBN-RGB8.doc / RGBN BODY Chunk


For each RGB value, a WORD (16-bits) is written: with the 12 RGB bits in
the MSB (most significant bit) positions; the "genlock" bit next; and then
a 3 bit repeat count. If the repeat count is greater than 7, the 3-bit
count is zero, and a BYTE repeat count follows.  If the repeat count is
greater than 255, the BYTE count is zero, and a WORD repeat count follows.
Repeat counts greater than 65536 are not supported.

