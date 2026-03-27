# 4 / About Console I/O / Console Keyboard Input


If you read from the console device, the keyboard inputs are preprocessed
for you and you will get ASCII characters, such as "B." Most normal
text-gathering programs will read from the console device in this manner.
Some programs may also ask to receive raw events in their console stream.
Keypresses are converted to ASCII characters or CSI sequences via the
keymap associated with the unit.

