---
title: reaction.lib/GetAttrs
manual: autodocs-3.5
chapter: autodocs-3.5
section: reaction-lib-getattrs
functions: []
libraries: []
---

# reaction.lib/GetAttrs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       GetAttrsA -- Get multiple object attributes
       GetAttrs -- Varargs stub to GetAttrsA
   SYNOPSIS

```c
       count = GetAttrsA( object, taglist )

       count = GetAttrs( object, tag, address, ... )

       ULONG GetAttrsA( [Object](autodocs-3.5/include-intuition-classusr-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) * )

       ULONG GetAttrs( [Object](autodocs-3.5/include-intuition-classusr-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ... )
```
   FUNCTION

```c
       Gets multiple attributes of an object iin a single call.
       [Remember](autodocs-3.5/include-intuition-intuition-h.md) that while the function returns the number of
       attributes that were getable, it can not inform WHICH
       attributes, if any, were not. Thus, you shouldn't use this
       function when you are not sure that an attribute is getable.
```
   INPUTS

       object - pointer to the object that should be queried
       taglist - a list of tag and ULONG address pairs to fill
   RESULTS

       The number of attributes that succeeded.
