# 33 IFFParse Library / Parsing


This is both simple and complicated.  It's simple in that it's just one
call.  It's complicated in that you have to seize control of the parser to
get your data.

The parser operates automatically, scanning the file, verifying syntax and
layout rules.  If left to its default behavior, it will scan through the
entire file until it reaches the end, whereupon it will tell you that it
got to the end.

The whole scanning procedure is controlled through one call:


```c
    error = ParseIFF (iff, controlmode);
```
The control modes are IFFPARSE_SCAN, [IFFPARSE_STEP](../Libraries_Manual_guide/node043E.html) and [IFFPARSE_RAWSTEP](../Libraries_Manual_guide/node043D.html).
For now, only the IFFPARSE_SCAN control mode is considered.

 [Controlling Parsing](../Libraries_Manual_guide/node0432.html)                 [Reading Chunk Data](../Libraries_Manual_guide/node043B.html) 
 [Putting It Together](../Libraries_Manual_guide/node0435.html)                 [Other Parsing Modes](../Libraries_Manual_guide/node043C.html) 
 [Other Chunk Management Functions](../Libraries_Manual_guide/node0436.html) 

