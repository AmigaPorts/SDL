---
title: 16 ASL Library / Creating a Font Requester
manual: libraries
chapter: libraries
section: 16-asl-library-creating-a-font-requester
functions: [AllocAslRequest, AslRequest, FreeAslRequest]
libraries: [asl.library]
---

# 16 ASL Library / Creating a Font Requester

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The ASL library also contains a font requester.  Using the font requester
is very similar to using the file requester.  First, allocate a requester
structure with [AllocAslRequest()](libraries/16-asl-library-creating-a-file-requester.md) or [AllocAslRequestTags()](libraries/16-file-pattern-matching-and-multiple-selects.md).  The type
should be set to ASL_FontRequest in order to get a [FontRequester](autodocs-2.0/includes-libraries-asl-h.md) structure:


```c
    struct FontRequester    {
        APTR    fo_Reserved1[2];
        struct TextAttr fo_Attr;        /* Returned TextAttr            */
        UBYTE   fo_FrontPen;            /* Returned pens, if selected   */
        UBYTE   fo_BackPen;
        UBYTE   fo_DrawMode;
        APTR    fo_UserData;
        /* missing from asl.h but present in this structure */
        SHORT   fo_LeftEdge, fo_TopEdge, fo_Width, fo_Height;
        };
```
Once the requester is set up, call [AslRequest()](libraries/16-asl-library-creating-a-file-requester.md) or [AslRequestTags()](libraries/16-file-pattern-matching-and-multiple-selects.md) to
make the requester appear on screen.  These functions return TRUE if the
user makes a selection.  In that case, the font selected is returned as a
[TextAttr](libraries/29-the-text-function-choosing-the-font.md) structure in the fo_Attr field of the FontRequester structure.
(The TextAttr structure is defined in <graphics/[text.h](autodocs-2.0/includes-graphics-text-h.md)>.  See the Amiga
ROM Kernel Manual: Includes and Autodocs for a complete listing.)  If the
user cancels the font requester FALSE is returned.


```c
     [Figure 16-2: The ASL Font Requester](libraries/lib-pics-16-2-pic.md) 
```
When the requester is no longer needed, call [FreeAslRequest()](autodocs-2.0/asl-library-freeaslrequest.md) to
deallocate the requester data structure.

 [Specifying Font Requester Options with TagItems](libraries/16-creating-a-font-requester-specifying-options-with.md) 
 [Example Font Requester](libraries/lib-examples-fontreq-c.md) 

---

## See Also

- [AllocAslRequest — asl.library](../autodocs/asl.library.md#allocaslrequest)
- [AslRequest — asl.library](../autodocs/asl.library.md#aslrequest)
- [FreeAslRequest — asl.library](../autodocs/asl.library.md#freeaslrequest)
