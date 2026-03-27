# 2 / ADCMD_ALLOCATE / The Allocation Key


If you want to perform multi-channel commands, all the channels must have
the same key since the [IOAudio](../Devices_Manual_guide/node001E.html#line9) block has only one allocation key field.
The channels must all have that same key even when they were not allocated
simultaneously. If you want to use a key you already have, you can pass
that key in the ioa_AllocKey field and [ADCMD_ALLOCATE](../Includes_and_Autodocs_2._guide/node04A6.html) can allocate other
channels with that existing key. The ADCMD_ALLOCATE command returns a new
and unique key only if you pass it a zero in the allocation key field.

