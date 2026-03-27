# 16 ASL Library / Creating a File Requester


Opening an ASL requester requires the use of three functions:


```c
    APTR request =  AllocAslRequest( unsigned long type,
                                     struct TagItem *tagList );
    BOOL success =  AslRequest( APTR request, struct TagItem *tagList );
    void            FreeAslRequest( APTR request );
```
The first function you should call is [AllocAslRequest()](../Includes_and_Autodocs_2._guide/node017C.html).  This allocates
the main data structure you will use, either a FileRequester structure or
a [FontRequester](../Libraries_Manual_guide/node0281.html) structure.  You specify the type of requester you want for
AllocAslRequest() by setting the type argument.  This can be one of two
values defined in <libraries/[asl.h](../Includes_and_Autodocs_2._guide/node00EA.html#line53)>:  either ASL_FileRequest, to ask for a
FileRequester structure, or ASL_FontRequest, to ask for a FontRequester
structure.

Here's a listing of the FileRequester structure.  (The [FontRequester](../Libraries_Manual_guide/node0281.html)
structure is discussed in more detail later in this chapter.)


```c
    struct FileRequester    {          /* (from <libraries/asl.h>)     */
        APTR    rf_Reserved1;
        BYTE    *rf_File;          /* Filename pointer             */
        BYTE    *rf_Dir;           /* Directory name pointer       */
        CPTR    rf_Reserved2;
        UBYTE   rf_Reserved3;
        UBYTE   rf_Reserved4;
        APTR    rf_Reserved5;
        WORD    rf_LeftEdge,rf_TopEdge; /* Preferred window pos   */
        WORD    rf_Width,rf_Height;     /* Preferred window size  */
        WORD    rf_Reserved6;
        LONG    rf_NumArgs;        /* A-la WB Args, for multiselects */
        struct WBArg *rf_ArgList;
        APTR    rf_UserData;       /* Applihandle (you may write!!)  */
        APTR    rf_Reserved7;
        APTR    rf_Reserved8;
        BYTE    *rf_Pat;           /* Pattern match pointer          */
        };                         /* note - more reserved fields follow */
```
Whichever requester type you use, you must allocate the requester
structure with the [AllocAslRequest()](../Includes_and_Autodocs_2._guide/node017C.html) function call.  Do not create the
data structure yourself.  The values in this structure are for read access
only.  Any changes to them must be performed only through asl.library
function calls.

Once you have set up a requester structure with [AllocAslRequest()](../Includes_and_Autodocs_2._guide/node017C.html), call
[AslRequest()](../Includes_and_Autodocs_2._guide/node017E.html) to make the requester appear on screen.  AslRequest() takes
the requester data structure as an argument using it as a specification
for the requester that it creates on screen.


```c
     [Figure 16-1: The ASL File Requester](../Libraries_Manual_guide/node05E3.html) 
```
[AslRequest()](../Includes_and_Autodocs_2._guide/node017E.html) is always synchronous to the calling program.  That is,
control does not return to your program until the user makes a selection
or cancels.  AslRequest() returns TRUE, if the user selects a file (or a
font).  In that case the file (or font) name that the user selected is
returned in the requester data structure.  AslRequest() returns FALSE if
the user cancels the requester or the requester failed for some reason.

When you have finished with a requester use the [FreeAslRequest()](../Includes_and_Autodocs_2._guide/node017F.html) function
to deallocate the requester data structure.

 [Specifying Requester Options with TagItems](../Libraries_Manual_guide/node027C.html) 
 [Simple ASL File Requester Example](../Libraries_Manual_guide/node057F.html) 
 [File Pattern Matching and Multiple Selects](../Libraries_Manual_guide/node027D.html) 
 [ASL Requesters and Custom Screens](../Libraries_Manual_guide/node027E.html) 
 [The Save Requester](../Libraries_Manual_guide/node027F.html) 
 [The Directory Requester](../Libraries_Manual_guide/node0280.html) 

