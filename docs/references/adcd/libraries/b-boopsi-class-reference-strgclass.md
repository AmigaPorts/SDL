---
title: B Boopsi Class Reference / strgclass
manual: libraries
chapter: libraries
section: b-boopsi-class-reference-strgclass
functions: []
libraries: []
---

# B Boopsi Class Reference / strgclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  strgclass
Superclass:             [gadgetclass](libraries/b-boopsi-class-reference-gadgetclass.md)
Include File:           <intuition/[gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md)>

Intuition compatible string gadgets.  The Boopsi string gadget can either
be a plain string gadget or an integer string gadget.  An integer gadget
filters out all characters except those that make up integer values.

New Methods:
------------
None.

Changed Methods:
----------------
 [OM_NEW](libraries/b-strgclass-changed-methods-om-new.md) 

Attributes:
-----------
 [STRINGA_LongVal (ISGNU)](libraries/b-strgclass-attributes-stringa-longval-isgnu.md)    [STRINGA_TextVal (ISGNU)](libraries/b-strgclass-attributes-stringa-textval-isgnu.md) 

The remaining strgclass attributes correspond to the flags and fields that
the conventional Intuition string gadget uses.  See the "STRING GADGET
TYPE" section of the "[Intuition Gadgets](libraries/5-intuition-gadgets-string-gadget-type.md)" chapter of the Amiga ROM Kernel
Reference Manual: Libraries for more information.

 [STRINGA_MaxChars, STRINGA_Buffer, (I)](libraries/b-strgclass-attributes-stringa-maxchars-stringa-workbuffer-i.md)      
 [STRINGA_UndoBuffer, STRINGA_WorkBuffer (I)](libraries/b-strgclass-attributes-stringa-maxchars-stringa-workbuffer-i.md) 
 [STRINGA_BufferPos, STRINGA_DispPos (ISU)](libraries/b-strgclass-attributes-stringa-bufferpos-stringa-disppos-isu.md) 
 [STRINGA_AltKeyMap (IS)](libraries/b-strgclass-attributes-stringa-altkeymap-is.md) 
 [STRINGA_Font (IS)](libraries/b-strgclass-attributes-stringa-font-is.md) 
 [STRINGA_Pens (IS)](libraries/b-strgclass-attributes-stringa-pens-is.md) 
 [STRINGA_ActivePens (IS)](libraries/b-strgclass-attributes-stringa-activepens-is.md) 
 [STRINGA_EditHook (I)](libraries/b-strgclass-attributes-stringa-edithook-i.md) 
 [STRINGA_EditModes (IS)](libraries/b-strgclass-attributes-stringa-editmodes-is.md) 
 [STRINGA_ReplaceMode, STRINGA_FixedFieldMode, STRINGA_NoFilterMode (IS)](libraries/b-strgclass-stringa-replacemode-stringa-nofiltermode-is.md) 
 [STRINGA_Justification (IS)](libraries/b-strgclass-attributes-stringa-justification-is.md) 
 [STRINGA_ExitHelp (IS)](libraries/b-strgclass-attributes-stringa-exithelp-is.md) 

