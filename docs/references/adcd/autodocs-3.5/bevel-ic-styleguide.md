---
title: bevel_ic/--styleguide--
manual: autodocs-3.5
chapter: autodocs-3.5
section: bevel-ic-styleguide
functions: []
libraries: []
---

# bevel_ic/--styleguide--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    BEVEL STYLE

        Several ReAction objects allow overriding the default bevel
        style. This is NOT recommended practice for application authors.
        But instead, its provided to add some extra flexability to BOOPSI
        class authors who may wish to sub-class a ReAction gadget or
        utilize it within a larger composite (model class) object.

        When using bevel.image directly be sure to select the appropriate
        bevel for your usage. Do not provide a bevel style override tag
        unless it makes sence to do so. The idea being that all applications
        and BOOPSI objects should be presented using a standard beveling
        style. For example, a button gadget using a BVS_FIELD string bevel
        would be an illogical choice.  Any button should use BVS_BUTTON, a
        text entry field should use BVS_FIELD, and ofcourse a layout group,
        if using a bevel, should use BVS_GROUP, BVS_SBAR_VERT or
        BVS_SBAR_HORIZ.
```
