# D / Errors / Fails only on Older ROMs or Older WB


This can be caused by asking for a library version higher than you need
(Do not use the #define LIBRARY_VERSION when compiling!).  Can also be
caused by calling functions or using structures which do not exist in the
older version of the operating system.  Ask for the lowest version which
provides the functions you need (usually 33), and exit gracefully and
informatively if an [OpenLibrary()](../Libraries_Manual_guide/node028E.html#line15) fails (returns NULL).  Or code
conditionally to only use new functions and structures if the available
Library's [lib_Version](../Libraries_Manual_guide/node0292.html#line6) supports them.

