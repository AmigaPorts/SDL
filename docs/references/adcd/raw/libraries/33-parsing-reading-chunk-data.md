# 33 / Parsing / Reading Chunk Data


To read data from a chunk, use the functions [ReadChunkBytes()](../Includes_and_Autodocs_2._guide/node01D6.html) and
[ReadChunkRecords()](../Includes_and_Autodocs_2._guide/node01D7.html).  Both calls truncate attempts to read past the end of
a chunk.  For odd-length chunks, the parser will skip over the pad bytes
for you.  Remember that for chunks which have been gathered using
[PropChunk()](../Libraries_Manual_guide/node0434.html) (or [CollectionChunk()](../Libraries_Manual_guide/node0437.html) ), you may directly reference the data
by using [FindProp()](../Libraries_Manual_guide/node0434.html) (or [FindCollection()](../Libraries_Manual_guide/node0437.html#line9) ) to get a pointer to the data.
ReadChunkBytes() is commonly used when loading and decompressing bitmap
and sound sample data or sequentially reading in data chunks such as [FTXT](../Libraries_Manual_guide/node045D.html#line8)
[CHRS](../Libraries_Manual_guide/node0465.html#line9) text chunks.  See the code listing [ClipFTXT.c](../Libraries_Manual_guide/node059F.html) for an example usage of
ReadChunkBytes().

