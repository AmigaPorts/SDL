# 5 / / Stringinfo Structure / Gadget Key Mapping


By default, screen characters appear using simple ASCII key translations.
If desired, the application can set up alternate key mapping.  A pointer
to the [KeyMap](../Libraries_Manual_guide/node0469.html) structure is placed into the AltKeyMap field of the
[StringInfo](../Libraries_Manual_guide/node016B.html) structure.  The [GACT_ALTKEYMAP](../Libraries_Manual_guide/node014B.html#line97) bit in the [Activation](../Libraries_Manual_guide/node0149.html#line53) flags of
the gadget must also be set.

See the "[Console Device](../Devices_Manual_guide/node0080.html)" chapter in the Amiga ROM Kernel Reference Manual:
Devices, and the "[Keymap Library](../Libraries_Manual_guide/node0468.html)" chapter in this manual for more
information about the console device and key mapping.

