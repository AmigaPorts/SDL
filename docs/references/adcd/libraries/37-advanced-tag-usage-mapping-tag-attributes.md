---
title: 37 / / Advanced Tag Usage / Mapping Tag Attributes
manual: libraries
chapter: libraries
section: 37-advanced-tag-usage-mapping-tag-attributes
functions: [MapTags]
libraries: [utility.library]
---

# 37 / / Advanced Tag Usage / Mapping Tag Attributes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To translate all occurrences of an attribute to another attribute, the
[MapTags()](autodocs-2.0/utility-library-maptags.md) function is used.

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

---

## See Also

- [MapTags — utility.library](../autodocs/utility.library.md#maptags)
