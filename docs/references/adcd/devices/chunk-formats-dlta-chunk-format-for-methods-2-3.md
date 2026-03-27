---
title: Chunk Formats / DLTA Chunk / Format for methods 2 & 3
manual: devices
chapter: devices
section: chunk-formats-dlta-chunk-format-for-methods-2-3
functions: []
libraries: []
---

# Chunk Formats / DLTA Chunk / Format for methods 2 & 3

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This chunk is a basic data chunk used to hold the delta compression data.
The minimum size of this chunk is 32 bytes as the first 8 long-words are
byte pointers into the chunk for the data for each of up to 8 bitplanes.
The pointer for the plane data starting immediately following these 8
pointers will have a value of 32 as the data starts in the 33-rd byte of
the chunk (index value of 32 due to zero-base indexing).

The data for a given plane consists of groups of data words.  In Long
Delta mode, these groups consist of both short and long words - short
words for offsets and numbers, and long words for the actual data.  In
Short Delta mode, the groups are identical except data words are also
shorts so all data is short words. Each group consists of a starting word
which is an offset.  If the offset is positive then it indicates the
increment in long or short words (whichever is appropriate) through the
bitplane. In other words, if you were reconstructing the plane, you would
start a pointer (to shorts or longs depending on the mode) to point to the
first word of the bitplane.  Then the offset would be added to it and the
following data word would be placed at that position.  Then the next
offset would be added to the pointer and the following data word would be
placed at that position.  And so on...  The data terminates with an offset
equal to 0xFFFF.

A second interpretation is given if the offset is negative.  In that case,
the absolute value is the offset+2.  Then the following short-word
indicates the number of data words that follow.  Following that is the
indicated number of contiguous data words (longs or shorts depending on
mode) which are to be placed in contiguous locations of the bitplane.

If there are no changed words in a given plane, then the pointer in the
first 32 bytes of the chunk is =0.

