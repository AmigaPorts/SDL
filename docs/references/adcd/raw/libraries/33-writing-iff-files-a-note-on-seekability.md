# 33 / Writing IFF Files / A Note On Seekability


As you can see from the above examples, IFFParse works best with a stream
that can seek randomly.  However, it is not possible to seek on some
streams (e.g., pipes).

IFFParse will read and write streams with limited or no seek capability.
In the case of reading, only forward-seek capability is desirable.
Failing this, IFFParse will fake forward seeks with a number of short
reads.

In the case of writing, if the stream lacks random seek capability,
IFFParse will buffer the entire contents of the file until you do the
final [PopChunk()](../Libraries_Manual_guide/node0442.html), or when you [CloseIFF()](../Libraries_Manual_guide/node042F.html) the handle.  At that time, the
entire stream will be written in one go.  This buffering happens whether
or not you specify all the chunk sizes to [PushChunk()](../Libraries_Manual_guide/node0441.html).


    About the Internal Buffering.
    -----------------------------
    The current implementation of this internal buffering could be
    more efficient.  Be aware that Amiga, Inc. reserves the right to alter
    this behavior of the parser, to improve performance or reduce memory
    requirements.  We mention this behavior on the off chance it is
    important to you.
