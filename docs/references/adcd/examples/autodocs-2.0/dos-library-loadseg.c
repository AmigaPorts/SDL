/* Source: ADCD 2.1
 * Section: dos-library-loadseg
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-loadseg.md
 */

    The file 'name' should be a load module produced by the linker.
    LoadSeg() scatterloads the CODE, DATA and BSS segments into memory,
    chaining together the segments with BPTR's on their first words.
    The end of the chain is indicated by a zero.  There can be any number
    of segments in a file.  All necessary relocation is handled by
    LoadSeg().

    In the event of an error any blocks loaded will be unloaded and a
    NULL result returned.

    If the module is correctly loaded then the output will be a pointer
    at the beginning of the list of blocks. Loaded code is unloaded via
    a call to [UnLoadSeg()](../Includes_and_Autodocs_2._guide/node0306.html).
