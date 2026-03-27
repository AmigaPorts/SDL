# 21 / Processor and Cache Control / Status Register


The processor status register bits can be set or read with the [SetSR()](../Includes_and_Autodocs_2._guide/node037F.html)
function.  This function operates in [supervisor mode](../Libraries_Manual_guide/node02CA.html), thus both the upper
and lower byte of the SR can be read or set.  Be very sure you know what
you are doing when you use this function to set bits in the SR and above
all never try to use this function to enter supervisor mode. Refer to the
M68000 Programmers Reference Manual by Motorola Inc. for information about
the definition of individual SR bits per processor type.

