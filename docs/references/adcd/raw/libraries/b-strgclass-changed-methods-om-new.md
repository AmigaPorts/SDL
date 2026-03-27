# B / strgclass / Changed Methods: OM_NEW


This method sets up the string gadget's [StringInfo](../Libraries_Manual_guide/node016B.html) and [StringExtend](../Libraries_Manual_guide/node016D.html)
structures.  It allocates a buffer if needed and will use shared data
buffers for [UndoBuffer](../Libraries_Manual_guide/node016B.html#line36) and [WorkBuffer](../Libraries_Manual_guide/node016D.html#line89) if the [MaxChars](../Libraries_Manual_guide/node016B.html#line49) is less than
SG_DEFAULTMAXCHARS (128).  Default text pens are: Foreground = 1,
Background = 0.  See the [rootclass](../Libraries_Manual_guide/node04BB.html) description of the [OM_NEW](../Libraries_Manual_guide/node04BC.html) method for
more details.

