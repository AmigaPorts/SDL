---
title: 37 / / Advanced Tag Usage / Filtering an Existing Tag List
manual: libraries
chapter: libraries
section: 37-advanced-tag-usage-filtering-an-existing-tag-list
functions: [FilterTagChanges, FilterTagItems, RefreshTagItemClones]
libraries: [utility.library]
---

# 37 / / Advanced Tag Usage / Filtering an Existing Tag List

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Sometimes it is necessary to only allow certain attributes to be visible
in a tag list.  In order to achieve this, the tag array would need to be
filtered.

A number of functions are provided for filtering items in a tag array.
They are [FilterTagChanges()](autodocs-2.0/utility-library-filtertagchanges.md), [FilterTagItems()](autodocs-2.0/utility-library-filtertagitems.md) and [RefreshTagItemClones()](autodocs-2.0/utility-library-refreshtagitemclones.md).



```c
    /* We want the text entry gadget to receive the following tags */
    Tag string_attrs[] =
    {
        STRINGA_MaxChars,
        STRINGA_Buffer,
        STRINGA_TextVal,
        TAG_END,
    };

    /* These are attributes that the model understands */
    Tag model_attrs[] =
    {
        CGTA_Total,
        CGTA_Visible,
        CGTA_Top,
        ICA_TARGET,
        ICA_MAP,
        TAG_END,
    };

    struct TagItem *otags;      /* Original tag list */
    struct TagItem *ntags;      /* New, work, tag list */

    /* Make a copy of the original for us to work with */
    ntags = CloneTagItems (otags);

    /* Create a tag list that only contains attributes that are
     * listed in the model_attrs list. */
    if (FilterTagItems (ntags, model_attrs, TAGFILTER_AND))
    {
        /* Work with filtered tag list (ntags) */

        /* Restore the tag list */
        RefreshTagItemClones (ntags, otags);

        /* Create a tag list that only contains attributes that
         * aren't in the model_attrs list. */
        if (FilterTagItems (ntags, model_attrs, TAGFILTER_NOT))
        {
            /* Work with filtered tag list (ntags) */
        }

        /* Restore the tag list */
        RefreshTagItemClones (ntags, otags);

        /* Create a tag list that only contains attributes that
         * are in the string_attrs list. */
        if (FilterTagItems (ntags, string_attrs, TAGFILTER_AND))
        {
            /* Work with filtered tag list (ntags) */
        }
    }

    /* Free work tag list. */
    FreeTagItems (ntags);
```

---

## See Also

- [FilterTagChanges — utility.library](../autodocs/utility.library.md#filtertagchanges)
- [FilterTagItems — utility.library](../autodocs/utility.library.md#filtertagitems)
- [RefreshTagItemClones — utility.library](../autodocs/utility.library.md#refreshtagitemclones)
