# 5 / String Gadget Type / Integer Gadget Type


The integer gadget is really a special case of the [string](../Libraries_Manual_guide/node0164.html) gadget type.
Initialize the gadget as a string gadget, then set the [GACT_LONGINT](../Libraries_Manual_guide/node014B.html#line91) flag
in the gadget's [Activation](../Libraries_Manual_guide/node0149.html#line53) field.

The user interacts with an integer gadget using exactly the same rules as
for a [string](../Libraries_Manual_guide/node0164.html) gadget, but Intuition filters the input, allows the user to
enter only a plus or minus sign and digits.  The integer gadget returns a
signed 32-bit integer in the [StringInfo](../Libraries_Manual_guide/node016B.html) variable [LongInt](../Libraries_Manual_guide/node016B.html#line80).

To initialize an integer gadget to a value, preload the input buffer with
an ASCII representation of the initial integer. It is not sufficient to
initialize the gadget by merely setting a value in the [LongInt](../Libraries_Manual_guide/node016B.html#line80) variable.

Integer gadgets have the [LongInt](../Libraries_Manual_guide/node016B.html#line80) value updated whenever the ASCII contents
of the gadget changes, and again when the gadget is deactivated.

