# 29 Graphics Library and Text / Function Reference


The following are brief descriptions of the Graphics and Diskfont library
functions that deal with text.  See the Amiga ROM Kernel Reference Manual:
Includes and Autodocs for details on each function call.


               Table 29-1: Graphics Library Text Functions
  _______________________________________________________________________
 |                                                                       |
 |      Function                  Description                            |
 |=======================================================================|
 |          [Text()](../Includes_and_Autodocs_2._guide/node0482.html)  Render a text string to a [RastPort](../Libraries_Manual_guide/node034A.html).                  |
 |       [SetFont()](../Includes_and_Autodocs_2._guide/node0479.html)  Set a RastPort's font.                               |
 |       [AskFont()](../Includes_and_Autodocs_2._guide/node041B.html)  Get the [TextAttr](../Libraries_Manual_guide/node03D6.html#line21) for a RastPort's font.              |
 |      [OpenFont()](../Includes_and_Autodocs_2._guide/node0462.html)  Open a font currently in the system font list.       |
 |     [CloseFont()](../Includes_and_Autodocs_2._guide/node042E.html)  Close a font.                                        |
 |       [AddFont()](../Includes_and_Autodocs_2._guide/node0410.html)  Add a font to the system list.                       |
 |       [RemFont()](../Includes_and_Autodocs_2._guide/node046F.html)  Remove a font from the system list.                  |
 |     [StripFont()](../Includes_and_Autodocs_2._guide/node0480.html)  Remove the tf_Extension from a font (V36).           |
 |  [WeighTAMatch()](../Includes_and_Autodocs_2._guide/node048C.html)  Get a measure of how well two fonts match (V36).     |
 |-----------------------------------------------------------------------|
 |   [ClearScreen()](../Includes_and_Autodocs_2._guide/node042C.html)  Clear [RastPort](../Libraries_Manual_guide/node034A.html) from the current position to the end  |
 |                  of the RastPort.                                     |
 |      [ClearEOL()](../Includes_and_Autodocs_2._guide/node0429.html)  Clear RastPort from the current position to the end  |
 |                  of the line.                                         |
 |  [AskSoftStyle()](../Includes_and_Autodocs_2._guide/node041C.html)  Get the soft style bits of a RastPort's font.        |
 |  [SetSoftStyle()](../Includes_and_Autodocs_2._guide/node047E.html)  Set the soft style bits of a RastPort's font.        |
 |    [TextLength()](../Includes_and_Autodocs_2._guide/node0485.html)  Determine the horizontal raster length of a text     |
 |                  string using the current RastPort settings.          |
 |    [TextExtent()](../Includes_and_Autodocs_2._guide/node0483.html)  Determine the raster extent (along the X and Y axes) |
 |                  of a text string using the current RastPort settings |
 |                  (V36).                                               |
 |    [FontExtent()](../Includes_and_Autodocs_2._guide/node043D.html)  Fill in a [TextExtent](../Libraries_Manual_guide/node03DA.html#line37) structure with the bounding box |
 |                  for the characters in the specified font (V36).      |
 |       [TextFit()](../Includes_and_Autodocs_2._guide/node0484.html)  Count the number of characters in a given string     |
 |                  that will fit into a given bounds, using the current |
 |                  RastPort settings (V36).                             |
 |_______________________________________________________________________|


               Table 29-2: Diskfont Library Text Functions
  _______________________________________________________________________
 |                                                                       |
 |           Function             Description                            |
 |=======================================================================|
 |           [AvailFonts()](../Includes_and_Autodocs_2._guide/node01F3.html)  Inquire which fonts are available from disk   |
 |                         and/or memory.                                |
 |      [NewFontContents()](../Includes_and_Autodocs_2._guide/node01F5.html)  Create a [FontContents](../Libraries_Manual_guide/node03E0.html#line33) image for a font.       |
 |  [DisposeFontContents()](../Includes_and_Autodocs_2._guide/node01F4.html)  Free the result from NewFontContents().       |
 |    [NewScaledDiskFont()](../Includes_and_Autodocs_2._guide/node01F6.html)  Create a DiskFont scaled from another font    |
 |                         (V36).                                        |
 |         [OpenDiskFont()](../Includes_and_Autodocs_2._guide/node01F7.html)  Open a font, loading it from disk if          |
 |                         necessary.                                    |
 |_______________________________________________________________________|

