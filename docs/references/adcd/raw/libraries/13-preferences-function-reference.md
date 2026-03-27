# 13 Preferences / Function Reference


The following are brief descriptions of the system functions that relate
to the use of Preferences.  See the Amiga ROM Kernel Reference Manual:
Includes and Autodocs for details on each function call.


               Table 13-3: Functions Used with Preferences
  _______________________________________________________________________
 |                                                                       |
 |      Function                Description                              |
 |=======================================================================|
 |      [GetPrefs()](../Includes_and_Autodocs_2._guide/node021E.html)  Old 1.3 (V34) function for making a copy of the      |
 |                  Preferences structure                                |
 |      [SetPrefs()](../Includes_and_Autodocs_2._guide/node0256.html)  Old 1.3 (V34) function for overwriting Preferences   |
 |                  with new data                                        |
 |   [GetDefPrefs()](../Includes_and_Autodocs_2._guide/node021D.html)  Old 1.3 (V34) function for copying default           |
 |                  Preferences from ROM                                 |
 |-----------------------------------------------------------------------|
 |   [StartNotify()](../Includes_and_Autodocs_2._guide/node0301.html)  Release 2 DOS library function for monitoring a      |
 |                  .prefs file for changes                              |
 |     [EndNotify()](../Includes_and_Autodocs_2._guide/node0299.html)  Ends notification started with StartNotify()         |
 |-----------------------------------------------------------------------|
 |      [AllocIFF()](../Includes_and_Autodocs_2._guide/node01B8.html)  IFFParse library function that creates an IFFHandle  |
 |                  for parsing                                          |
 |  [InitIFFasDOS()](../Includes_and_Autodocs_2._guide/node01CC.html)  Initialize the IFFHandle as a DOS stream             |
 |       OpenIFF()  Initialize an IFFHandle for reading or writing a new |
 |                  stream                                               |
 |     [PropChunk()](../Includes_and_Autodocs_2._guide/node01D3.html)  Specify a property chunk to store                    |
 |      [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html)  Parse an [IFF](../Libraries_Manual_guide/node0428.html) file from the IFFHandle stream          |
 |  [CurrentChunk()](../Includes_and_Autodocs_2._guide/node01BE.html)  Returns the top level context of an IFF stream       |
 |      [FindProp()](../Includes_and_Autodocs_2._guide/node01C3.html)  Search for a property chunk previously declared with |
 |                  PropChunk()                                          |
 |      [CloseIFF()](../Includes_and_Autodocs_2._guide/node01BB.html)  Closes an IFF context opened with OpenIFF()          |
 |       [FreeIFF()](../Includes_and_Autodocs_2._guide/node01C5.html)  Frees the IFFHandle created with AllocIFF()          |
 |_______________________________________________________________________|

