# 33 / Writing IFF Files / Creating Chunks In a File


Because the [IFF](../Libraries_Manual_guide/node0428.html) specification has nesting and scoping rules, you can nest
chunks inside one another.  One instance is the [BMHD](../Libraries_Manual_guide/node0461.html#line3) chunk, which is
commonly nested inside a [FORM](../Libraries_Manual_guide/node042A.html#line7) chunk.  Thus, it is necessary for you to
inform IFFParse when you are starting and ending chunks.

 [PushChunk()](../Libraries_Manual_guide/node0441.html)    [PopChunk()](../Libraries_Manual_guide/node0442.html) 

