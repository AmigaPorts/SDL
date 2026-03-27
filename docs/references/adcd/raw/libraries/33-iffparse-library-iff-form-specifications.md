# 33 IFFParse Library / IFF FORM Specifications


The specifications for Amiga [IFF](../Libraries_Manual_guide/node0428.html) formats are maintained by Commodore
Applications and Technical Support ([CATS](../Libraries_Manual_guide/node002A.html)) and updated periodically.  The
latest specifications are published in the Amiga ROM Kernel Reference
Manual: [Devices](../Devices_Manual_guide/node0129.html) (3rd edition) and also available in electronic form
directly from CATS.  Between updates of the IFF Manual, selected new FORMs
and changes to existing FORMs are documented in Amiga Mail a technical
newsletter for Amiga developers published by Commodore's CATS group.

Some of the most commonly used IFF FORMs are the four that were originally
specified in the EA IFF-85 standard:



```c
             ___________________________________
            |                                   |
            |  [ILBM](../Libraries_Manual_guide/node045E.html)  Bitmap images and palettes |
            |  [FTXT](../Libraries_Manual_guide/node0465.html)  Simple formatted text      |
            |  SMUS  Simple musical scores      |
            |  8SVX  8-bit sound samples        |
            |___________________________________|
```
Of these four, ILBM is the most commonly encountered FORM, and FTXT is
becoming increasingly important since the Release 2 conclip command passes
clipped console text through the clipboard as FTXT.  All data clipped to
the clipboard must be in an [IFF](../Libraries_Manual_guide/node0428.html) format.

This section will provide a brief summary of the ILBM and FTXT FORMs and
their most used common chunks.  Please consult the EA-IFF specifications
for additional information.

 [FORM ILBM](../Libraries_Manual_guide/node045E.html)    [FORM FTXT](../Libraries_Manual_guide/node0465.html) 

