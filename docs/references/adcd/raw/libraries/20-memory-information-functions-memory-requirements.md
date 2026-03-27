# 20 / / Memory Information Functions / Memory Requirements


The same attribute flags used in memory allocation routines are valid for
the memory information routines.  There is also an additional flag,
[MEMF_LARGEST](../Includes_and_Autodocs_2._guide/node0089.html#line76), which can be used in the [AvailMem()](../Libraries_Manual_guide/node02AD.html) routine to find out what
the largest available memory block of a particular type is.  Specifying
the [MEMF_TOTAL](../Includes_and_Autodocs_2._guide/node0089.html#line76) flag will return the total amount of memory currently
available.

