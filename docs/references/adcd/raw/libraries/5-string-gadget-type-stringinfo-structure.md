# 5 / String Gadget Type / StringInfo Structure


[String](../Libraries_Manual_guide/node0164.html) gadgets require their own special structure called the [StringInfo](../Includes_and_Autodocs_2._guide/node00D4.html#line524)
structure.


```c
    struct StringInfo
        {
        UBYTE *Buffer;
        UBYTE *UndoBuffer;
        WORD BufferPos;
        WORD MaxChars;
        WORD DispPos;
        WORD UndoPos;
        WORD NumChars;
        WORD DispCount;
        WORD CLeft, CTop;
        struct StringExtend *Extension;
        LONG LongInt;
        struct KeyMap *AltKeyMap;
        };
```
Buffer

```c
    The application must supply an input buffer (Buffer) and an optional
    undo buffer (UndoBuffer) for the gadget.  The input buffer is where
    data typed into the gadget is placed by Intuition.  The program can
    examine this buffer at any time.

    A string copied into the input buffer before the gadget is added to
    the system will be displayed in the gadget when it is displayed, and
    may then be edited by the user.  The input buffer may be initialized
    to any starting value, as long as the initial string is NULL
    terminated and fits within the buffer.  To initialize the buffer to
    the empty string (no characters), put a NULL in the first position of
    the buffer.

    [Integer](../Libraries_Manual_guide/node0165.html) gadgets must have the ASCII value of the initial number
    placed into the Buffer before the gadget is added to the system.
```
UndoBuffer

```c
    If a [string](../Libraries_Manual_guide/node0164.html) gadget has an undo buffer, the undo feature will be
    enabled.  "Undo" allows the user to revert to the initial string (the
    value in the buffer before gadget activation) at any time before the
    gadget becomes inactive.  The UndoBuffer is used to hold a copy of
    the previous string while the user edits the current string.  When
    the gadget is activated, the Buffer is copied to the UndoBuffer. The
    Buffer may be restored at any time up to the time the gadget is
    deactivated, by typing right-Amiga Q.

    Multiple [string](../Libraries_Manual_guide/node0164.html) gadgets may share the same undo buffer as long as the
    buffer is as large as the largest input buffer.
```
MaxChars

    MaxChars tells Intuition the size of the input buffer. This count
    includes the trailing NULL of any data entered into the buffer, so
    the number of characters the gadget may hold is MaxChars - 1.
BufferPos

    BufferPos is initialized to the current position of the cursor in the
    buffer.  BufferPos runs from zero to one less than the length of the
    string.  If this position is not within the characters that will be
    displayed, Intuition will adjust DispPos for the gadget to make the
    cursor visible.
DispPos

    DispPos is initialized to the starting character in the string to
    display on screen.  This allows strings longer than the number of
    displayable characters to be positioned within the gadget.  Intuition
    will not position the string such that there is empty character space
    to the right of the string and characters scrolled out of the gadget
    box to the left.
UndoPos, NumChars, DispCount, CLeft and CTop

```c
    These variables are maintained by Intuition and should not be
    modified by the application.  UndoPos specifies the character
    position in the undo buffer.  NumChars specifies the number of
    characters currently in the buffer.  DispCount specifies the number
    of whole characters visible in the [container](../Libraries_Manual_guide/node0159.html).
```
Extension

```c
    The StringInfo Extension allows for additional control over [string](../Libraries_Manual_guide/node0164.html)
    gadget behavior and appearance.  [See below](../Libraries_Manual_guide/node016D.html) for details.
```
LongInt

```c
    LongInt contains the integer value entered into an Integer type of
    [string](../Libraries_Manual_guide/node0164.html) gadget.  After the user has finished entering an integer, the
    application can read the value in this variable.
```
 [Gadget Key Mapping](../Libraries_Manual_guide/node016C.html) 

