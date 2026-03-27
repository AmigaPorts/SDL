# 34 / Keymap Functions / Asking For the Default Keymap


The [AskKeyMapDefault()](../Includes_and_Autodocs_2._guide/node0313.html) returns a pointer to the current default keymap.
To use the mapping functions in keymap.library it is normally not
necessary to call this function. They accept NULL as equivalent to 'use
default keymap' and will call this function for you. You can use this
pointer for example to cache the system default in order to temporarily
change the keymap your applications uses, or find the keymap in the
keymap.resource list of loaded keymaps.  You should never change the
system wide default keymap unless the user asks you to do so; since the
Amiga is a multitasking system, changing the keymap could interfere with
the behaviour of other applications.

