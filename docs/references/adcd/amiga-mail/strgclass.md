---
title: strgclass
manual: amiga-mail
chapter: amiga-mail
section: strgclass
functions: []
libraries: []
---

# strgclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  strgclass
Superclass:             gadgetclass
Description:            Intuition compatible string gadgets.
Include File:           <intuition/gadgetclass.h>


New Methods:
------------

None.


Changed Methods:
----------------

All methods defined by gadgetclass are handled to provide compatible
string gadget processing.


OM_NEW - Sets up StringInfo and StringExtend structures.  Will allocate
a Buffer if needed and will use shared data buffers for UndoBuffer and
WorkBuffer if the MaxChars is less than SG_DEFAULTMAXCHARS (128).
Default text pens are FG = 1, BG = 0;


Attributes:
-----------

GA_ID                           (ISG)

Will be included in OM_NOTIFY messages generated.


STRINGA_MaxChars                (I)
STRINGA_Buffer                  (I)
STRINGA_UndoBuffer              (I)
STRINGA_WorkBuffer              (I)

Specify various buffers defined for string gadgets and extended string
gadgets.  If your value of STRINGA_MaxChars is less than
SG_DEFAULTMAXCHARS (120 for now), then this class can provide all these
buffers for you.  Note that UndoBuffer and WorkBuffer can be shared by
many separate gadgets, providing they are as large as the largest
MaxChars they will encounter.


STRINGA_BufferPos               (ISU)
STRINGA_DispPos                 (ISU)

Familiar cursor and scroll position.


STRINGA_AltKeyMap               (IS)

Same as StringInfo.AltKeyMap.


STRINGA_Font                    (IS)

Font for string gadget text.  Must be an open TextFont.


STRINGA_Pens                    (IS)

Pen numbers, packed as two shorts into a longword, for rendering gadget
text.


STRINGA_ActivePens              (IS)

Optional pen numbers, packed as two shorts into a longword, for
rendering gadget text, when the gadget is active.


STRINGA_EditHook                (I)

Custom string gadget edit hook.


STRINGA_EditModes               (IS)

Value taken from flags defined in <intuition/sghooks.h> for initial
editing modes.


STRINGA_ReplaceMode             (IS)
STRINGA_FixedFieldMode          (IS)
STRINGA_NoFilterMode            (IS)

These three are independent Boolean equivalents to the individual flags
that you can set for STRINGA_EditModes.


STRINGA_Justification           (IS)

Takes the values STRINGCENTER, STRINGRIGHT, and STRINGLEFT (which is 0).


STRINGA_LongVal                 (ISGNU)

When you specify this to a string gadget object, it means first that the
gadget is now for integer entry only, and the value of the gadget takes
the numeric value passed in ti_Data.  Note that this attribute has
OM_NOTIFY and OM_UPDATE access.


STRINGA_TextVal                 (ISGNU)

When you specify this to a string gadget object, it means that the
gadget is for text entry only, and the value of the gadget is copied
from the string value passed as a UBYTE pointer in ti_Data.  Note that
this attribute has OM_NOTIFY and OM_UPDATE access.


STRINGA_ExitHelp                (IS)

Set this if you want the gadget to exit when the ``Help'' key is
pressed.  Look for a code of 0x5f, the rawkey code for help.

Notification messages will be issued whenever the gadget chooses to go
inactive (not when it is aborted).  The OPUF_INTERIM flag is always
clear.

