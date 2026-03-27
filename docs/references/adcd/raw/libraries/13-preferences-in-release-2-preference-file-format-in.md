# 13 / Preferences in Release 2 / Preference File Format in Release 2


To understand the format of Preferences files, you must be familiar with
[IFF](../Libraries_Manual_guide/node0428.html) file standard (see the Amiga ROM Kernel Reference Manual: [Devices](../Devices_Manual_guide/node0129.html) for
the complete specification).

In general all Preferences files are stored in the [IFF](../Libraries_Manual_guide/node0428.html) format with a type
of PREF (see the [exceptions](../Libraries_Manual_guide/node0235.html) noted below).  Each file contains at least two
Chunks, a header Chunk and a data Chunk.

 [The Header Chunk](../Libraries_Manual_guide/node022B.html)    [The Data Chunk](../Libraries_Manual_guide/node022C.html) 

