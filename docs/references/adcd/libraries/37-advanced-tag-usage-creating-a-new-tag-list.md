---
title: 37 / / Advanced Tag Usage / Creating a New Tag List
manual: libraries
chapter: libraries
section: 37-advanced-tag-usage-creating-a-new-tag-list
functions: [AllocateTagItems, FreeTagItems]
libraries: [utility.library]
---

# 37 / / Advanced Tag Usage / Creating a New Tag List

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [AllocateTagItems()](autodocs-2.0/utility-library-allocatetagitems.md) function can be used to create a new tag array
ready for use.  The tag array should be passed to [FreeTagItems()](autodocs-2.0/utility-library-freetagitems.md) when the
application is done with it.


```c
    struct TagItem *tags;
    ULONG tags_needed;

    /* Indicate how many tags we need */
    tags_needed = 10;

    /* Allocate a tag array */
    if (tags = AllocateTagItems(tags_needed))
    {
        /* ...do something with the array... */

        /* Free the array when your done with it */
        FreeTagItems (tags);
    }
```

---

## See Also

- [AllocateTagItems — utility.library](../autodocs/utility.library.md#allocatetagitems)
- [FreeTagItems — utility.library](../autodocs/utility.library.md#freetagitems)
