# 33 / / Basic Functions and Structures of IFFParse Library


The structures and flags of the IFFParse library are defined in the
include files <libraries/[iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html)> and <libraries/[iffparse.i](../Includes_and_Autodocs_2._guide/node00EC.html)>.  [IFF](../Libraries_Manual_guide/node0428.html)
files are manipulated through a structure called an [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line28).  Only some
of the fields in the IFFHandle are publicly documented.  The rest are
managed internally by IFFParse.  This handle is passed to all IFFParse
functions, and contains the current parse state and position in the file.
An IFFHandle is obtained by calling [AllocIFF()](../Includes_and_Autodocs_2._guide/node01B8.html), and freed through
[FreeIFF()](../Includes_and_Autodocs_2._guide/node01C5.html).  This is the only legal way to obtain and dispose of an
IFFHandle.

The public portion of if IFFHandle is defined as follows:


```c
    /*
     * Structure associated with an active IFF stream.
     * "iff_Stream" is a value used by the client's read/write/seek
     * functions - it will not be accessed by the library itself and
     * can have any value (could even be a pointer or a BPTR).
     */
    struct IFFHandle {
            ULONG   iff_Stream;
            ULONG   iff_Flags;
            LONG    iff_Depth;      /*  Depth of context stack.  */
            /*  There are private fields hiding here.  */
    };
```
