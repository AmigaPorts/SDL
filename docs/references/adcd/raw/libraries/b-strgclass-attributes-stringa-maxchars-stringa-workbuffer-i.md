# B / strgclass / Attributes: STRINGA_MaxChars - STRINGA_WorkBuffer (I)


STRINGA_MaxChars, STRINGA_Buffer, STRINGA_UndoBuffer, STRINGA_WorkBuffer
(I) - Specify various buffers defined for string gadgets and extended
string gadgets.  If your value of STRINGA_MaxChars is less than
SG_DEFAULTMAXCHARS (128 for now), then this class can provide all these
buffers for you.  Note that [UndoBuffer](../Libraries_Manual_guide/node016B.html#line36) and [WorkBuffer](../Libraries_Manual_guide/node016D.html#line89) can be shared by
many separate gadgets, providing they are as large as the largest [MaxChars](../Libraries_Manual_guide/node016B.html#line49)
they will encounter.

