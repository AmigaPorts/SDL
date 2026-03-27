---
title: 5 Intuition Gadgets / String Gadget Type
manual: libraries
chapter: libraries
section: 5-intuition-gadgets-string-gadget-type
functions: []
libraries: []
---

# 5 Intuition Gadgets / String Gadget Type

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A string gadget is an area of the display in which a single field of
character data may be entered.  When a string gadget is activated, either
by the user or by the application, a cursor appears prompting the user to
enter some text.  Any characters typed will be placed into the active
string gadget, unless the gadget is deactivated by other mouse activity or
program interaction.

In Release 2, the system also supports tabbing between a group of string
gadgets.  In this mode, pressing the tab key will advance the active
gadget to the next string gadget and pressing shifted tab will advance to
the previous string gadget.

Control characters are generally filtered out, but may be entered by
pressing the Left Amiga key with the desired control character.  The
filtering may be disabled by the program, or by the user via the IControl
Preferences editor.

String gadgets feature auto-insert, which allows the user to insert
characters wherever the cursor is.  Overwrite mode is also available, and
the application may toggle the gadget between the two modes.

When the user activates a string gadget with the mouse, the gadget's
cursor moves to the position of the mouse.  The user may change the
position of the cursor both with the cursor keys and with the mouse
pointer.

A number of simple, keyboard driven editing functions are available to the
user.  These editing functions are shown in the following table.




```c
          Table 5-1: Editing Keys and Their Functions


            Key              Function
            ---              --------
                 <-  Cursor to previous character.

           Shift <-  Cursor to beginning of string.

                 ->  Cursor to next character.

           Shift ->  Cursor to end of string.

                Del  Delete the character under the cursor. Does
                     nothing in fixed field mode.

          Shift Del  Delete from the character under the cursor to the
                     end of the line. Does nothing in fixed field mode.

          Backspace  Delete the character to left of cursor. In fixed
                     field mode, move cursor to previous character.

    Shift Backspace  Delete from the character to the left of the
                     cursor to the start of the line. In fixed field
                     mode, move cursor to beginning of string.

    Return or Enter  Terminate input and deactivate the gadget. If the
                     [GACT_RELVERIFY](libraries/5-gadget-structure-gadget-activation-flags.md) activation flag is set, the
                     program will receive a [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) event for
                     this gadget.

      Right Amiga Q  Undo (cancel) the last editing change to the
                     string.

      Right Amiga X  Clears the input buffer. The undo buffer is left
                     undisturbed. In fixed field mode, move cursor to
                     beginning of string.
```
The following additional editing functions are available only when "Filter
Control Characters" is on for the string gadget. Control character
filtering is only available if the IControl preferences editor has "Text
Gadget Filter" selected and the individual gadget does not have
[SGM_NOFILTER](libraries/5-string-gadget-type-extended-string-gadgets.md) set.




```c
          Table 5-2: Additional Editing Keys and Their Functions


          Key                Function
          ---                --------
         Ctrl A      Jump cursor to start of buffer.

         Ctrl H      Delete the character to the left of the cursor.
                     In fixed field mode, move cursor to previous
                     character.

         Ctrl K      Delete from the character under the cursor to the
                     end of the string. Does nothing in fixed field
                     mode.

         Ctrl M      Equivalent to Return or Enter (end gadget).

         Ctrl W      Delete the previous word. In fixed field mode,
                     jump cursor to the start of the previous word.

         Ctrl U      Delete from the character to the left of the
                     cursor to the start of the buffer. In fixed field
                     mode, jump cursor to the start of the buffer.

         Ctrl X      Clears the input buffer (like Right Amiga X). In
                     fixed field mode, jump cursor to the start of the
                     buffer.

         Ctrl Z      Jump cursor to end of buffer.
```
 [Integer Gadget Type](libraries/5-string-gadget-type-integer-gadget-type.md)                    [StringInfo Structure](libraries/5-string-gadget-type-stringinfo-structure.md) 
 [String Gadget IDCMP Messages](libraries/5-string-gadget-type-string-gadget-idcmp-messages.md)           [Extended String Gadgets](libraries/5-string-gadget-type-extended-string-gadgets.md) 
 [Program Control of String Gadgets](libraries/5-string-gadget-type-program-control-of-string-gadgets.md)      [Custom String Editing](libraries/5-string-gadget-type-custom-string-editing.md) 
 [Tabbing Between String Gadgets](libraries/5-string-gadget-type-tabbing-between-string-gadgets.md) 
 [Gadget Structure For String Gadgets](libraries/5-string-gadget-type-gadget-structure-for-string-gadgets.md) 

