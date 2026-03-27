# 16 ASL Library / Function Reference


The following are brief descriptions of the ASL library functions.  See
the Amiga ROM Kernel Reference Manual: Includes and Autodocs for details
on each function call.  All of these functions require Release 2 or a
later version of the operating system.


                 Table 16-1: Functions for ASL Requesters
  ________________________________________________________________________
 |                                                                        |
 |           Function                   Description                       |
 |========================================================================|
 |                                                                        |
 |      [AllocAslRequest()](../Includes_and_Autodocs_2._guide/node017C.html)  Allocates an ASL font or file requester from   |
 |                         a [TagItem](../Libraries_Manual_guide/node0497.html) array                                |
 |  [AllocAslRequestTags()](../Includes_and_Autodocs_2._guide/node017C.html#line28)  Same as AllocAslRequest() but accepts tags     |
 |                         directly                                       |
 |           [AslRequest()](../Includes_and_Autodocs_2._guide/node017E.html)  Displays an ASL requester with options set up  |
 |                         in a TagItem array                             |
 |       [AslRequestTags()](../Includes_and_Autodocs_2._guide/node017E.html#line29)  Same as AslRequest() but accepts tags directly |
 |       [FreeAslRequest()](../Includes_and_Autodocs_2._guide/node017F.html)  Deallocates an ASL requester created with      |
 |                         AllocAslRequest()                              |
 |________________________________________________________________________|

