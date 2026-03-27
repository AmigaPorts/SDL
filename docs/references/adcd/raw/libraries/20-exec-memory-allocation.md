# 20 Exec Memory Allocation


Exec manages all of the free memory currently available in the system.
Using linked list structures, Exec keeps track of memory and provides the
functions to allocate and access it.

When an application needs some memory, it can either declare the memory
statically within the program or it can ask Exec for some memory.  When
Exec receives a request for memory, it looks through its list of free
memory regions to find a suitably sized block that matches the size and
attributes requested.

 [Memory Functions](../Libraries_Manual_guide/node02A7.html)                     [Other Memory Functions](../Libraries_Manual_guide/node02B6.html) 
 [Allocating Multiple Memory Blocks](../Libraries_Manual_guide/node02B1.html)    [Function Reference](../Libraries_Manual_guide/node02B9.html) 

