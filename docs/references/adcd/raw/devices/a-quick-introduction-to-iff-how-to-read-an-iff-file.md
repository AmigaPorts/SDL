# A Quick Introduction to IFF / How to read an IFF file?


Example code and modules are provided for reading IFF files using
iffparse.library. However, if you wish to read a non-complex FORM by hand,
the following logic can be used.

Once you have entered the [FORM](../Devices_Manual_guide/node01C7.html#line52) (for example, the FORM [ILBM](../Devices_Manual_guide/node01AC.html) shown above),
stored the FORM length (24070 in the ILBM example) and are positioned on
the first [chunk](../Devices_Manual_guide/node01C7.html), you may:

Loop: (Until end-of-file or end-of-form)


```c
        - Read the 4-character identifier of the chunk
        - Read the 32-bit (4 byte) chunklength
        - Decide if you want that chunk
              if yes, read chunklength bytes into destination
              structure or buffer
              if no, seek forward chunklength bytes
        - If chunklength is odd, seek one more byte.
```
Every IFF file is a [FORM](../Devices_Manual_guide/node01C7.html#line52), [LIST](../Devices_Manual_guide/node01CA.html#line49), or [CAT](../Devices_Manual_guide/node01CA.html#line2) chunk.  You can recognize an
IFF file by those first 4 bytes.  ("FORM" is far and away the most common.
We'll get to LIST and CAT below.)  If the file contains a FORM, dispatch
on the FORM type ID to a chunk-reader loop like the one above.

