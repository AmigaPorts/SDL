---
title: B / gadgetclass / Attributes: ICA_MAP (IS)
manual: libraries
chapter: libraries
section: b-gadgetclass-attributes-ica-map-is
functions: []
libraries: []
---

# B / gadgetclass / Attributes: ICA_MAP (IS)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This attribute points to a tag list of attribute mappings which the gadget
uses to change the attribute IDs of an [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md)'s attribute/value pairs.
For example, if a gadget had the following ICA_MAP:


```c
    struct TagItem map[] =
    {
        {PGA_Top, STRINGA_LongVal},
        {MYATTR, MYNEWATTR},
        {TAG_END, }
    };
```
before it sends an [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md) to its [ICA_TARGET](libraries/b-gadgetclass-attributes-ica-target-is.md), the gadget scans through
the OM_UPDATE message's attribute/value pairs looking for the [PGA_Top](libraries/b-propgclass-pga-top-isgnu-pga-visible-pga-total-isu.md) and
MYATTR attributes.  If it finds the PGA_Top attribute, it changes PGA_Top
to [STRINGA_LongVal](libraries/b-strgclass-attributes-stringa-longval-isgnu.md).  Likewise, if the gadget finds the MYATTR attribute,
it changes MYATTR to MYNEWATTR.  The gadget does not disturb the
attribute's value, only its ID.

