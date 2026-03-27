# 37 / / Advanced Tag Usage / Locating an Attribute


To see if an attribute is in a tag array, the [TagInArray()](../Includes_and_Autodocs_2._guide/node03E1.html) function is
used.


```c
    /* See if the listview labels attribute is located in a tag array */
    if (TagItemArray(GTLV_Labels, tags))
    {
        /* Yes, the attribute is in the list */
    }
    else
    {
        /* No, the attribute isn't in the list */
    }
```
The [FindTagItem()](../Includes_and_Autodocs_2._guide/node03D6.html) function will return a pointer to the actual tag that
has the desired attribute.  This allows you to manipulate the tag or to
determine if the attribute exists but just has a NULL value.


```c
    struct TagItem *tag;

    /* See if they are trying to set a sound */
    if (tag = FindTagItem(MGA_Sound, attrs))
    {
        /* Set the sound attribute to point to the specified sound data */
        tag->ti_Data = sound;
    }
```
