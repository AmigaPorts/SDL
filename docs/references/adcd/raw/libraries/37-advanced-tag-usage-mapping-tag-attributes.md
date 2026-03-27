# 37 / / Advanced Tag Usage / Mapping Tag Attributes


To translate all occurrences of an attribute to another attribute, the
[MapTags()](../Includes_and_Autodocs_2._guide/node03D9.html) function is used.

For Release 2, the third parameter of this function is always TRUE (tags
remain in the array even if they can't be mapped).


```c
    struct TagItem map_list[] =
    {
        /* Original     New */
        {MGA_LeftEdge,  GA_LeftEdge},
        {MGA_TopEdge,   GA_TopEdge},
        {MGA_Width,     GA_Width},
        {MGA_Height,    GA_Height},

        /* Terminate the array */
        {TAG_END},
    }

    /* Map the tags to the new attributes, keeping all attributes that
     * aren't included in the mapping array */
    MapTags(tags, map_list, TRUE);
```
