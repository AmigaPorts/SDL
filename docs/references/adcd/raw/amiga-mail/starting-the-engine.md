# Starting the Engine


There are several steps involved in using a font outline on the Amiga.

[Step 1.](../AmigaMail_Vol2_guide/node00D1.html) Open the font contents file (the ".font" file) and verify that

```c
        it has a corresponding outline tag file (an ".otag" file).
```
[Step 2.](../AmigaMail_Vol2_guide/node00D2.html) Open the otag file, verify that it is valid, load its tag list

        into memory, and resolve any memory indirections in the tag list.
[Step 3.](../AmigaMail_Vol2_guide/node00D3.html) Find out the name of the typeface's scaling engine and obtain a

        pointer to the engine's GlyphEngine structure.
[Step 4.](../AmigaMail_Vol2_guide/node00D4.html) Tell the engine which typeface to use.

[Step 5.](../AmigaMail_Vol2_guide/node00D5.html) Set other scaling engine parameters.

