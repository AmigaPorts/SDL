---
title: 5 / String Gadget Type / Integer Gadget Type
manual: libraries
chapter: libraries
section: 5-string-gadget-type-integer-gadget-type
functions: []
libraries: []
---

# 5 / String Gadget Type / Integer Gadget Type

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The integer gadget is really a special case of the [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget type.
Initialize the gadget as a string gadget, then set the [GACT_LONGINT](libraries/5-gadget-structure-gadget-activation-flags.md) flag
in the gadget's [Activation](libraries/5-intuition-gadgets-gadget-structure.md) field.

The user interacts with an integer gadget using exactly the same rules as
for a [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget, but Intuition filters the input, allows the user to
enter only a plus or minus sign and digits.  The integer gadget returns a
signed 32-bit integer in the [StringInfo](libraries/5-string-gadget-type-stringinfo-structure.md) variable [LongInt](libraries/5-string-gadget-type-stringinfo-structure.md).

To initialize an integer gadget to a value, preload the input buffer with
an ASCII representation of the initial integer. It is not sufficient to
initialize the gadget by merely setting a value in the [LongInt](libraries/5-string-gadget-type-stringinfo-structure.md) variable.

Integer gadgets have the [LongInt](libraries/5-string-gadget-type-stringinfo-structure.md) value updated whenever the ASCII contents
of the gadget changes, and again when the gadget is deactivated.

