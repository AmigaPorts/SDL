---
title: 37 / / Advanced Tag Usage / Locating an Attribute
manual: libraries
chapter: libraries
section: 37-advanced-tag-usage-locating-an-attribute
functions: [FindTagItem, TagInArray]
libraries: [utility.library]
---

# 37 / / Advanced Tag Usage / Locating an Attribute

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To see if an attribute is in a tag array, the [TagInArray()](autodocs-2.0/utility-library-taginarray.md) function is
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
The [FindTagItem()](autodocs-2.0/utility-library-findtagitem.md) function will return a pointer to the actual tag that
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

---

## See Also

- [FindTagItem — utility.library](../autodocs/utility.library.md#findtagitem)
- [TagInArray — utility.library](../autodocs/utility.library.md#taginarray)
