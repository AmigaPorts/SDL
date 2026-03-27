# 33 / / Controlling Parsing / StopChunk()


You can instruct the parser to stop when it encounters a specific [IFF](../Libraries_Manual_guide/node0428.html)
chunk by using the function [StopChunk()](../Includes_and_Autodocs_2._guide/node01D9.html):


```c
    error = StopChunk (iff, ID_ILBM, ID_BODY);
```
When the parser encounters the requested chunk, parsing will stop, and
[ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html) will return the value zero.  The stream will be positioned
ready to read the first data byte in the chunk.  You may then call
[ReadChunkBytes()](../Libraries_Manual_guide/node043B.html) or [ReadChunkRecords()](../Libraries_Manual_guide/node043B.html) to pull the data out of the chunk.

You may call [StopChunk()](../Includes_and_Autodocs_2._guide/node01D9.html) any number of times for any number of different
chunk types.  If you wish to identify the chunk on which you've stopped,
you may call [CurrentChunk()](../Libraries_Manual_guide/node0447.html) to get a pointer to the current [ContextNode](../Libraries_Manual_guide/node0446.html),
and examine the cn_Type and cn_ID fields.

Using [StopChunk()](../Includes_and_Autodocs_2._guide/node01D9.html) for every chunk, you can parse [IFF](../Libraries_Manual_guide/node0428.html) files in a manner
very similar to the way you're probably doing it now, using a state
machine.  However, this would be a terrible underuse of IFFParse.

