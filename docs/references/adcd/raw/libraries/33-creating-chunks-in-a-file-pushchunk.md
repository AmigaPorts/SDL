# 33 / / Creating Chunks In a File / PushChunk()


To tell IFFParse you are about to begin writing a new chunk, you use the
function [PushChunk()](../Includes_and_Autodocs_2._guide/node01D5.html):


```c
    error = PushChunk (iff, ID_ILBM, ID_BMHD,chunksize);
```
The chunk ID and size are written to the stream.  IFFParse will enforce
the chunk size you specified; attempts to write past the end of the chunk
will be truncated.  If, as a chunk size argument, you pass IFFSIZE_UNKNOWN,
the chunk will be expanded in size as you write data to it.

