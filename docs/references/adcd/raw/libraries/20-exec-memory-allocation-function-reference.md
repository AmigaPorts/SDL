# 20 Exec Memory Allocation / Function Reference


The following are brief descriptions of the Exec functions that handle
memory management.  See the Amiga ROM Kernel Reference Manual: Includes
and Autodocs for details on each call.


                    Table 20-1: Exec Memory Functions
  ________________________________________________________________________
 |                                                                        |
 |  Memory Function               Description                             |
 |========================================================================|
 |      [AllocMem()](../Includes_and_Autodocs_2._guide/node0332.html)  Allocate memory with specified attributes.  If an     |
 |                  application needs to allocate some memory, it will    |
 |                  usually use this function.                            |
 |    [AddMemList()](../Includes_and_Autodocs_2._guide/node0328.html)  Add memory to the system free pool.                   |
 |      [AllocAbs()](../Includes_and_Autodocs_2._guide/node032F.html)  Allocate memory at a specified location.              |
 |      [Allocate()](../Includes_and_Autodocs_2._guide/node0330.html)  Allocate memory from a private memory pool.           |
 |    [AllocEntry()](../Includes_and_Autodocs_2._guide/node0331.html)  Allocate multiple memory blocks.                      |
 |      [AllocVec()](../Includes_and_Autodocs_2._guide/node0335.html)  Allocate memory with specified attributes and keep    |
 |                  track of the size (V36).                              |
 |      [AvailMem()](../Includes_and_Autodocs_2._guide/node0337.html)  Return the amount of free memory, given certain       |
 |                  conditions.                                           |
 |       [CopyMem()](../Includes_and_Autodocs_2._guide/node0342.html)  Copy memory block, which can be non-aligned and of    |
 |                  arbitrary length.                                     |
 |  [CopyMemQuick()](../Includes_and_Autodocs_2._guide/node0343.html)  Copy aligned memory block.                            |
 |    [Deallocate()](../Includes_and_Autodocs_2._guide/node0346.html)  Return memory block allocated, with Allocate() to the |
 |                  private memory pool.                                  |
 |     [FreeEntry()](../Includes_and_Autodocs_2._guide/node0354.html)  Free multiple memory blocks, allocated with           |
 |                  AllocEntry().                                         |
 |       [FreeMem()](../Includes_and_Autodocs_2._guide/node0355.html)  Free a memory block of specified size, allocated with |
 |                  AllocMem().                                           |
 |       [FreeVec()](../Includes_and_Autodocs_2._guide/node0358.html)  Free a memory block allocated with AllocVec().        |
 |    [InitStruct()](../Includes_and_Autodocs_2._guide/node035E.html)  Initialize memory from a table.                       |
 |     [TypeOfMem()](../Includes_and_Autodocs_2._guide/node0387.html)  Determine attributes of a specified memory address.   |
 |________________________________________________________________________|

