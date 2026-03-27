---
title: 37 / / Advanced Tag Usage / Obtaining Boolean Values
manual: libraries
chapter: libraries
section: 37-advanced-tag-usage-obtaining-boolean-values
functions: [PackBoolTags]
libraries: [utility.library]
---

# 37 / / Advanced Tag Usage / Obtaining Boolean Values

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Often times data is best represented as simple boolean (TRUE or FALSE)
values.  The [PackBoolTags()](autodocs-2.0/utility-library-packbooltags.md) function provides an easy method for
converting a tag list to bit fields.


```c
    /* These are the attributes that we understand, with the
     * corresponding flag value. */
    struct TagItem activation_bools[] =
    {
        /* Attribute            Flags */
        {GA_ENDGADGET,          ENDGADGET},
        {GA_IMMEDIATE,          GADGIMMEDIATE},
        {GA_RELVERIFY,          RELVERIFY},
        {GA_FOLLOWMOUSE,        FOLLOWMOUSE},
        {GA_RIGHTBORDER,        RIGHTBORDER},
        {GA_LEFTBORDER,         LEFTBORDER},
        {GA_TOPBORDER,          TOPBORDER},
        {GA_BOTTOMBORDER,       BOTTOMBORDER},
        {GA_TOGGLESELECT,       TOGGLESELECT},

        /* Terminate the array */
        {TAG_END}
    };

    /* Set the activation field, based on the attributes passed */
    g->Activation = PackBoolTags(g->Activation, tags, activation_bools);
```

---

## See Also

- [PackBoolTags — utility.library](../autodocs/utility.library.md#packbooltags)
