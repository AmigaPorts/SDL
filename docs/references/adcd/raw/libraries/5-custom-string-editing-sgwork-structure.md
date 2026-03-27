# 5 / / Custom String Editing / SGWork Structure




```c
    struct SGWork" link Includes/intuition/sghooks.h/MAIN 32}
        {
        struct Gadget       *Gadget;
        struct StringInfo   *StringInfo;
        UBYTE               *WorkBuffer;
        UBYTE               *PrevBuffer;
        ULONG               Modes;
        struct InputEvent   *IEvent;
        UWORD               Code;
        WORD                BufferPos;
        WORD                NumChars;
        ULONG               Actions;
        LONG                LongInt;
        struct GadgetInfo   *GadgetInfo;
        UWORD               EditOp;
        };
```
The local (application) hook may only change the Code, Actions,
WorkBuffer, NumChars, BufferPos and LongInt fields.  None of the other
fields in the SGWork structure may be modified.

Gadget and StringInfo

```c
    The values in the [string](../Libraries_Manual_guide/node0164.html) gadget before any modification are available
    through the [Gadget](../Libraries_Manual_guide/node0149.html) and [StringInfo](../Libraries_Manual_guide/node016B.html) pointers.
```
PrevBuffer

    The PrevBuffer provides a shortcut to the old, unmodified string
    buffer.
WorkBuffer, BufferPos, NumChars and LongInt

```c
    WorkBuffer, BufferPos, NumChars and LongInt contain the values that
    the [string](../Libraries_Manual_guide/node0164.html) gadget will take if the edits are accepted.  If the edit
    hook updates these values, the gadget will take on the updated values.
```
IEvent

    IEvent contains the input event that caused this call to the hook.
    This input event is not keymapped.  Only use this event for action
    keys, like the Return key, function keys or the Esc key.
Code

```c
    If the input event maps to a single character, the keymapped value
    will be in the Code field.  The Code field may also be modified, and
    the value placed in it will be passed back to the application in the
    [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) message when [SGA_END](../Libraries_Manual_guide/node0171.html#line5) is specified in the Actions field.
```
GadgetInfo

```c
    A structure of information defined in <intuition/[cghooks.h](../Includes_and_Autodocs_2._guide/node00D2.html)>.  This
    structure is read only.  See the "[BOOPSI](../Libraries_Manual_guide/node0219.html)" chapter for more
    information.
```
Modes

    The modes of the gadget such as insert mode, defined below.
Actions

```c
    The action taken by the edit hook, [defined below](../Libraries_Manual_guide/node0171.html).
```
EditOp

```c
    The type of edit operation done by the global hook, [defined below](../Libraries_Manual_guide/node0170.html).
```
