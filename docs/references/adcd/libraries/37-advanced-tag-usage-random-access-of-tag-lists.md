---
title: 37 / / Advanced Tag Usage / Random Access of Tag Lists
manual: libraries
chapter: libraries
section: 37-advanced-tag-usage-random-access-of-tag-lists
functions: [GetTagData]
libraries: [utility.library]
---

# 37 / / Advanced Tag Usage / Random Access of Tag Lists

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [GetTagData()](autodocs-2.0/utility-library-gettagdata.md) function will return the data for the specified
attribute.  If there isn't a tag that matches, then the default value is
returned.


```c
    APTR sound;

    /* Get the sound data that our function will use. */
    sound = (APTR) GetTagData (MGA_Sound, (ULONG) DefaultSound, attrs);
```

---

## See Also

- [GetTagData — utility.library](../autodocs/utility.library.md#gettagdata)
