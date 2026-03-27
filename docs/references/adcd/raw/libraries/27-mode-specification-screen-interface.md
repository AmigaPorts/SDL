# 27 / / / Mode Specification, Screen Interface


Opening an Intuition screen in one of the new modes requires the
specification of 32 bits of mode data.  The [NewScreen.ViewModes](../Includes_and_Autodocs_2._guide/node00DD.html#line303) field is a
UWORD (16 bits).  Therefore, the new Release 2 function [OpenScreenTags()](../Libraries_Manual_guide/node00DF.html#line6)
must be used along with a SA_DisplayID tag which specifies the 32-bit
ModeID.  See the "[Intuition Screens](../Libraries_Manual_guide/node00EE.html)" chapter for more on this.

The new display modes also introduce some complexity for applications that
want to support "mode-sensitive" processing.  If a program wishes to open
a screen in the highest resolution that a user has available, there are
many more cases to handle under Release 2.  Therefore, it will become
increasingly important to algorithmically layout a screen for correct,
functional and aesthetic operation.  All the information needed to be
mode-flexible is available through the display database functions
(explained below).

