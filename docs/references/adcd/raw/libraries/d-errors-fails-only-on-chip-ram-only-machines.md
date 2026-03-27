# D / Errors / Fails only on Chip-RAM-Only Machines


Caused by specifically asking for or requiring [MEMF_FAST](../Libraries_Manual_guide/node02A8.html#line20) memory.  If you
don't need Chip RAM, ask for memory type 0L, or [MEMF_CLEAR](../Libraries_Manual_guide/node02A8.html#line37), or
[MEMF_PUBLIC](../Libraries_Manual_guide/node02A8.html#line31)|MEMF_CLEAR as applicable.  If there is Fast memory available,
you will be given Fast memory.  If not, you will get Chip RAM.  May also
be caused by trackdisk-level loading of code or data over important system
memory or structures which might reside in low Chip memory on a
Chip-RAM-Only machine.

