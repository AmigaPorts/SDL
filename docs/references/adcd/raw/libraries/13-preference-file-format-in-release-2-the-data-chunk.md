# 13 / / Preference File Format in Release 2 / The Data Chunk


The data Chunk that follows the header Chunk depends on the kind of
Preferences data the file contains.  The types of Preferences data Chunks
that are currently part of the system are:




```c
    Table 13-2: [IFF](../Libraries_Manual_guide/node0428.html) Chunk Types in Release 2 Preferences Data Files

    Chunk Name     Used With
    ----------     ---------
       [FONT](../Libraries_Manual_guide/node022D.html)        Fonts, used for all font Preferences files.
                   In future the PrefHeader may indicate what the
                   font is used for.
       [ICTL](../Libraries_Manual_guide/node022E.html)        IControl
       [INPT](../Libraries_Manual_guide/node022F.html)        Input
       [OSCN](../Libraries_Manual_guide/node0230.html)        Overscan
       [PGFX](../Libraries_Manual_guide/node0231.html)        PrinterGfx
       [PTXT](../Libraries_Manual_guide/node0232.html)        PrinterText
       [SCRM](../Libraries_Manual_guide/node0233.html)        ScreenMode
       [SERL](../Libraries_Manual_guide/node0234.html)        Serial
```
Each chunk contains a structure applicable to the type.

