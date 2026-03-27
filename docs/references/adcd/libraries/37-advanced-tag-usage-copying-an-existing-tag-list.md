---
title: 37 / / Advanced Tag Usage / Copying an Existing Tag List
manual: libraries
chapter: libraries
section: 37-advanced-tag-usage-copying-an-existing-tag-list
functions: [CloneTagItems]
libraries: [utility.library]
---

# 37 / / Advanced Tag Usage / Copying an Existing Tag List

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [CloneTagItems()](autodocs-2.0/utility-library-clonetagitems.md) function is used to copy an existing tag array into a
new tag array.


```c
    struct TagItem *otags;      /* Original tag array */
    struct TagItem *ntags;      /* New tag array */

    /* Make sure there is a TagItem array */
    if (otags)
    {
        /* Copy the original tags into a new tag array */
        if (ntags = CloneTagItems(otags))
        {
            /* ...do something with the array... */

            /* Free the array when your done with it */
            FreeTagItems (ntags);
        }
    }
```
This function can also be used to implement a function that will insert
tag items into an array.


```c
    struct TagItem *otags;      /* Original tag array */
    struct TagItem *tags;       /* New tag array */

    /* Insert a couple of tags into an existing tag array */
    if (tags = MakeNewTagList (GA_LeftEdge, 10,
                               GA_TopEdge, 20,
                               TAG_MORE, otags))
    {
        /* ...do something with the array... */

        /* Free the array when your done with it */
        FreeTagItems (tags);
    }

    /* This function will create a tag array from tag pairs placed on
     * the stack */
    struct TagItem *MakeNewTagList (ULONG data,...)
    {
        struct TagItem *tags = (struct TagItem *) &data;

        return (CloneTagItems (tags));
    }
```

---

## See Also

- [CloneTagItems — utility.library](../autodocs/utility.library.md#clonetagitems)
