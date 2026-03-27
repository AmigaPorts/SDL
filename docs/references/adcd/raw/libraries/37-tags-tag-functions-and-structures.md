# 37 / Tags / Tag Functions and Structures


A tag is made up of an attribute/value pair as defined below (from
<utility/[tagitem.h](../Includes_and_Autodocs_2._guide/node012E.html#line18)>):


```c
    struct TagItem
    {
        ULONG  ti_Tag;    /* identifies the type of this item */
        ULONG  ti_Data;   /* type-specific data, can be a pointer */
    };
```
The ti_Tag field specifies an attribute to set.  The possible values of
ti_Tag are implementation specific.  System tags are defined in the
include files.  The value the attribute is set to is specified in ti_Data.
An example of the attribute/value pair that will specify a window's name
is:


```c
    ti_Tag  = WA_Title;
    ti_Data = "My Window's Name";
```
The ti_Data field often contains 32-bit data as well as pointers.

These are brief descriptions of the utility functions you can use to
manipulate and access tags.  For complete descriptions, see the
"[Simple Tag Usage](../Libraries_Manual_guide/node0498.html)" and "[Advanced Tag Usage](../Libraries_Manual_guide/node0499.html)" sections.

The following utility library calls are for supporting tags:


                Table 37-1: Utility Library Tag Functions
  ______________________________________________________________________
 |                                                                      |
 |     [AllocateTagItems()](../Libraries_Manual_guide/node049A.html)  Allocate a TagItem array (or chain).         |
 |         [FreeTagItems()](../Libraries_Manual_guide/node049A.html)  Frees allocated TagItem lists.               |
 |----------------------------------------------------------------------|
 |        [CloneTagItems()](../Libraries_Manual_guide/node049B.html)  Copies a TagItem list.                       |
 | [RefreshTagItemClones()](../Libraries_Manual_guide/node049C.html)  Rejuvenates a clone from the original.       |
 |----------------------------------------------------------------------|
 |          [FindTagItem()](../Libraries_Manual_guide/node049D.html#line13)  Scans TagItem list for a tag.                |
 |           [GetTagData()](../Libraries_Manual_guide/node049F.html)  Obtain data corresponding to tag.            |
 |          [NextTagItem()](../Libraries_Manual_guide/node049E.html)  Iterate TagItem lists.                       |
 |           [TagInArray()](../Libraries_Manual_guide/node049D.html)  Check if a tag value appears in a Tag array. |
 |----------------------------------------------------------------------|
 |     [FilterTagChanges()](../Libraries_Manual_guide/node049C.html)  Eliminate TagItems which specify no change.  |
 |       [FilterTagItems()](../Libraries_Manual_guide/node049C.html)  Remove selected items from a TagItem list.   |
 |              [MapTags()](../Libraries_Manual_guide/node04A1.html)  Convert ti_Tag values in a list via map      |
 |                         pairing.                                     |
 |         [PackBoolTags()](../Libraries_Manual_guide/node04A0.html)  Builds a "Flag" word from a TagItem list.    |
 |______________________________________________________________________|

