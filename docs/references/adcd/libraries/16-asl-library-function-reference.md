---
title: 16 ASL Library / Function Reference
manual: libraries
chapter: libraries
section: 16-asl-library-function-reference
functions: [AllocAslRequest, AslRequest, FreeAslRequest]
libraries: [asl.library]
---

# 16 ASL Library / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

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
 |      [AllocAslRequest()](autodocs-2.0/asl-library-allocaslrequest.md)  Allocates an ASL font or file requester from   |
 |                         a [TagItem](libraries/37-tags-tag-functions-and-structures.md) array                                |
 |  [AllocAslRequestTags()](autodocs-2.0/asl-library-allocaslrequest.md)  Same as AllocAslRequest() but accepts tags     |
 |                         directly                                       |
 |           [AslRequest()](autodocs-2.0/asl-library-aslrequest.md)  Displays an ASL requester with options set up  |
 |                         in a TagItem array                             |
 |       [AslRequestTags()](autodocs-2.0/asl-library-aslrequest.md)  Same as AslRequest() but accepts tags directly |
 |       [FreeAslRequest()](autodocs-2.0/asl-library-freeaslrequest.md)  Deallocates an ASL requester created with      |
 |                         AllocAslRequest()                              |
 |________________________________________________________________________|

---

## See Also

- [AllocAslRequest — asl.library](../autodocs/asl.library.md#allocaslrequest)
- [AslRequest — asl.library](../autodocs/asl.library.md#aslrequest)
- [FreeAslRequest — asl.library](../autodocs/asl.library.md#freeaslrequest)
