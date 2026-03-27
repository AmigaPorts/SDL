# 33 / / Other Chunk Management Functions / StopOnExit()


Whereas [StopChunk()](../Libraries_Manual_guide/node0433.html) will stop the parser just as it enters the declared
chunk, [StopOnExit()](../Includes_and_Autodocs_2._guide/node01DB.html) will stop just before it leaves the chunk. This is
useful for finding the end of [FORM](../Libraries_Manual_guide/node042A.html#line7)s, which would indicate that you've
collected all possible data in this FORM and may now act on it.


```c
    /* Ask ParseIFF() to stop with IFFERR_EOC when leaving a FORM ILBM */
    StopOnExit(iff,ID_ILBM, ID_FORM);
```
