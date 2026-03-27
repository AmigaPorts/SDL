---
title: B / icclass / Attributes: ICA_MAP (IS)
manual: libraries
chapter: libraries
section: b-icclass-attributes-ica-map-is
functions: []
libraries: []
---

# B / icclass / Attributes: ICA_MAP (IS)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This attribute points to a tag list of attribute mappings which the
[icclass](libraries/b-boopsi-class-reference-icclass.md) object uses to change the attribute IDs of an [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md)'s
attribute/value pairs.  For example, if an icclass object had the
following ICA_MAP:


```c
    struct TagItem map[] =
    {
        {PGA_Top, STRINGA_LongVal},
        {MYATTR, MYNEWATTR},
        {TAG_END, }
    };
```
before sending an [OM_UPDATE](libraries/b-icclass-changed-methods-om-update-om-notify.md) to its [ICA_TARGET](libraries/b-icclass-attributes-ica-target-is.md), the [icclass](libraries/b-boopsi-class-reference-icclass.md) object scans
through the [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md) message's attribute/value pairs looking for the
[PGA_Top](libraries/b-propgclass-pga-top-isgnu-pga-visible-pga-total-isu.md) and MYATTR attributes.  If it finds the PGA_Top attribute, it
changes PGA_Top to [STRINGA_LongVal](libraries/b-strgclass-attributes-stringa-longval-isgnu.md).  Likewise, if the icclass object finds
the MYATTR attribute, it changes MYATTR to MYNEWATTR.  The icclass object
does not disturb the attribute's value.

