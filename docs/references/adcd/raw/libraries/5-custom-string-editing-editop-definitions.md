# 5 / / Custom String Editing / EditOp Definitions


These values indicate the basic type of operation the global editing hook
has performed on the string before the application gadget's custom editing
hook gets called.  Only global editing hooks must update the value in the
[EditOp](../Libraries_Manual_guide/node016F.html#line57) field before they return.  The value placed in the field should
reflect the action taken.


  EditOp          Action Taken by Global Hook
  ------          ---------------------------
  EO_NOOP         Did nothing.
  EO_DELBACKWARD  Deleted some chars (possibly 0).
  EO_DELFORWARD   Deleted some characters under and in front of the cursor.
  EO_MOVECURSOR   Moved the cursor.
  EO_ENTER        Enter or Return key, terminate.
  EO_RESET        Current Intuition-style undo.
  EO_REPLACECHAR  Replaced one character and (maybe) advanced cursor.
  EO_INSERTCHAR   Inserted one character into string or added one at end.
  EO_BADFORMAT    Didn't like the text data,
```c
                  e.g., alpha characters in a [GACT_LONGINT](../Libraries_Manual_guide/node014B.html#line91) type.
```
  EO_BIGCHANGE    Complete or major change to the text, e.g. new string.
  EO_UNDO         Some other style of undo.
  EO_CLEAR        Clear the string.
  EO_SPECIAL      An operation that doesn't fit into the categories here.

