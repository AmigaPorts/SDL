# 16 / / File Pattern Matching and Multiple Selects


A file requester can filter out certain file and directory entries using
the "wildcard" feature of  AmigaDOS.  To activate the wildcard feature for
a file requester, you use the ASL_FuncFlags tag.  Each bit in the
ASL_FuncFlags tag item controls a special option of the requester
depending on its type (file or font).  See <libraries/[asl.h](../Includes_and_Autodocs_2._guide/node00EA.html#line107)> for a
complete listing of the options that the ASL_FuncFlags tag controls.


 File Requester Flag  Used For
 -------------------  --------
  FILF_PATGAD         Enables the file name pattern matching gadget
  FILF_MULTISELECT    Enables multiple selection of files
  FILF_NEWIDCMP       Use separate IDCMP for requester sharing a custom
```c
                      screen ([see below](../Libraries_Manual_guide/node027E.html))
```
  FILF_SAVE           Makes the file requester a save requester ([see below](../Libraries_Manual_guide/node027F.html))


If the FILF_PATGAD bit of the ASL_FuncFlags tag is set, the file requester
will appear with a "Pattern" gadget in addition to the usual file name and
directory name gadgets.  The user can type an AmigaDOS wildcard pattern
into this gadget and the pattern will be used to limit the file names that
appear in the requester.  An application can also supply a default pattern
using the ASL_Pattern tag item. A hidden unchangeable pattern can be
created by supplying an ASL_Pattern without a FILF_PATGAD gadget. Such
invisible patterns should not be used if there is any reason that the user
may need to access a file which does not match the pattern.

Another feature of the ASL file requester is multiple selection.  When
multiple selection is enabled, the user can choose more than one file name
in a single directory by selecting names in the requester's scrolling list
gadget with the mouse.  This option, like pattern matching, is set up with
the ASL_FuncFlags tag.

If the FILF_MULTISELECT bit of the ASL_FuncFlags tag is set, the file
requester will allow multiple selection.  When the user selects several
file names through the multiple selection feature, the [FileRequester](../Libraries_Manual_guide/node027B.html#line15)'s
rf_NumArgs field contains the number of files selected and the rf_ArgList
field contains a pointer to an array of [WBArg](../Libraries_Manual_guide/node023E.html#line49) structures (defined in
<workbench/[startup.h](../Includes_and_Autodocs_2._guide/node0134.html#line26)>).  There is a WBArg structure containing a file name
for each file the user selected.

The following example illustrates a file requester with both a pattern
matching gadget and multiple selection enabled.


```c
     [filepat.c](../Libraries_Manual_guide/node057D.html) 
```
The previous example demonstrates two alternate functions for creating and
using ASL requesters:


```c
    APTR AllocAslRequestTags( unsigned long type, Tag Tag1, ... );
    BOOL AslRequestTags( APTR request, Tag Tag1, ... );
```
[AllocAslRequestTags()](../Includes_and_Autodocs_2._guide/node017C.html#line28) can be used instead of [AllocAslRequest()](../Libraries_Manual_guide/node027B.html) to allocate
and set up the file requester.  This is an amiga.lib function that will
accept [TagItem](../Libraries_Manual_guide/node0497.html)s directly in its parameter list, rather than a pointer to
an array of TagItems.

Similarly, [AslRequestTags()](../Includes_and_Autodocs_2._guide/node017E.html#line29) will accept [TagItem](../Libraries_Manual_guide/node0497.html)s directly instead of
requiring a pointer to an array of TagItems as [AslRequest()](../Libraries_Manual_guide/node027B.html#line43) does.

