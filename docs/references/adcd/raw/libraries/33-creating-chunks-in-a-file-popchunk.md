# 33 / / Creating Chunks In a File / PopChunk()


When you are through writing data to a chunk, you complete the write by
calling [PopChunk()](../Includes_and_Autodocs_2._guide/node01D2.html):


```c
    error = PopChunk (iff);
```
If you wrote fewer bytes than you declared with [PushChunk()](../Libraries_Manual_guide/node0441.html), [PopChunk()](../Includes_and_Autodocs_2._guide/node01D2.html)
will return an error.  If you specified IFFSIZE_UNKNOWN, PopChunk() will
seek backward on the stream and write the final size.  If you specified a
chunk size that was odd, PopChunk() will write the pad byte automatically.

[PushChunk()](../Libraries_Manual_guide/node0441.html) and [PopChunk()](../Includes_and_Autodocs_2._guide/node01D2.html) nest; every call to PushChunk() must have a
corresponding call to PopChunk().

