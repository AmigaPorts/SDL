# 34 / / Details Of the Keymap Structure / Repeatable Bit Tables


The vectors [km_LoRepeatable](../Libraries_Manual_guide/node046F.html) and [km_HiRepeatable](../Libraries_Manual_guide/node046F.html) each point to an array of
8 bytes that contain additional information about the keytable entries. A
bit for each key indicates whether or not the specified key should repeat
at the rate set by the Input Preferences program.

The bit positions correspond to those specified in the [capsable](../Libraries_Manual_guide/node0474.html) bit table.
If there is a 1 in a specific position, the key can repeat. There are 64
bits (8 bytes) in each of the two repeatable tables.

