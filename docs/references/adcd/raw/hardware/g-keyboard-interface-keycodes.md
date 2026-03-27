# G Keyboard Interface / Keycodes


Each key has a keycode associated with it (see accompanying  [table](../Hardware_Manual_guide/node017A.html) ).
Keycodes are always 7 bits long.  The eighth bit is a "key-up"/"key-down"
flag; a 0 (high level) means that the key was pushed down, and a 1 (low
level) means the key was released (the  [Caps Lock key](../Hardware_Manual_guide/node0175.html)  is different -- see
below).

For example, here is a diagram of the "B" key being pushed down. The
keycode for "B" is $35 = 00110101; due to the rotation of the byte, the
bits transmitted are 01101010.


             _____   ___   ___   ___   ___   ___   ___   ___   _________
        KCLK      \_/   \_/   \_/   \_/   \_/   \_/   \_/   \_/
             _________             _____       _____       _____________
        KDAT          \___________/     \_____/     \_____/
                   0     1     1     0     1     0     1     0
In the next example, the B key is released.  The keycode is still $35,
except that bit 7 is set to indicate "key-up," resulting in a code of $B5
= 10110101.  After rotating, the transmission will be 01101011:


             _____   ___   ___   ___   ___   ___   ___   ___   _________
        KCLK      \_/   \_/   \_/   \_/   \_/   \_/   \_/   \_/
             _________             _____       _____             _______
        KDAT          \___________/     \_____/     \___________/
                   0     1     1     0     1     0     1     1
