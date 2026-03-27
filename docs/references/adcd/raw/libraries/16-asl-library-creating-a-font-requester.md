# 16 ASL Library / Creating a Font Requester


The ASL library also contains a font requester.  Using the font requester
is very similar to using the file requester.  First, allocate a requester
structure with [AllocAslRequest()](../Libraries_Manual_guide/node027B.html) or [AllocAslRequestTags()](../Libraries_Manual_guide/node027D.html#line44).  The type
should be set to ASL_FontRequest in order to get a [FontRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line140) structure:


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
Once the requester is set up, call [AslRequest()](../Libraries_Manual_guide/node027B.html#line43) or [AslRequestTags()](../Libraries_Manual_guide/node027D.html#line44) to
make the requester appear on screen.  These functions return TRUE if the
user makes a selection.  In that case, the font selected is returned as a
[TextAttr](../Libraries_Manual_guide/node03D6.html#line21) structure in the fo_Attr field of the FontRequester structure.
(The TextAttr structure is defined in <graphics/[text.h](../Includes_and_Autodocs_2._guide/node00A8.html#line65)>.  See the Amiga
ROM Kernel Manual: Includes and Autodocs for a complete listing.)  If the
user cancels the font requester FALSE is returned.


```c
     [Figure 16-2: The ASL Font Requester](../Libraries_Manual_guide/node05E4.html) 
```
When the requester is no longer needed, call [FreeAslRequest()](../Includes_and_Autodocs_2._guide/node017F.html) to
deallocate the requester data structure.

 [Specifying Font Requester Options with TagItems](../Libraries_Manual_guide/node0282.html) 
 [Example Font Requester](../Libraries_Manual_guide/node057E.html) 

