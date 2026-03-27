# B / icclass / Attributes: ICA_MAP (IS)


This attribute points to a tag list of attribute mappings which the
[icclass](../Libraries_Manual_guide/node04C6.html) object uses to change the attribute IDs of an [OM_UPDATE](../Libraries_Manual_guide/node04C4.html)'s
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
before sending an [OM_UPDATE](../Libraries_Manual_guide/node04C8.html) to its [ICA_TARGET](../Libraries_Manual_guide/node04C9.html), the [icclass](../Libraries_Manual_guide/node04C6.html) object scans
through the [OM_UPDATE](../Libraries_Manual_guide/node04C4.html) message's attribute/value pairs looking for the
[PGA_Top](../Libraries_Manual_guide/node050F.html) and MYATTR attributes.  If it finds the PGA_Top attribute, it
changes PGA_Top to [STRINGA_LongVal](../Libraries_Manual_guide/node0512.html).  Likewise, if the icclass object finds
the MYATTR attribute, it changes MYATTR to MYNEWATTR.  The icclass object
does not disturb the attribute's value.

