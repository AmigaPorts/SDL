# B / gadgetclass / Attributes: ICA_MAP (IS)


This attribute points to a tag list of attribute mappings which the gadget
uses to change the attribute IDs of an [OM_UPDATE](../Libraries_Manual_guide/node04C4.html)'s attribute/value pairs.
For example, if a gadget had the following ICA_MAP:


```c
    struct TagItem map[] =
    {
        {PGA_Top, STRINGA_LongVal},
        {MYATTR, MYNEWATTR},
        {TAG_END, }
    };
```
before it sends an [OM_UPDATE](../Libraries_Manual_guide/node04C4.html) to its [ICA_TARGET](../Libraries_Manual_guide/node04FB.html), the gadget scans through
the OM_UPDATE message's attribute/value pairs looking for the [PGA_Top](../Libraries_Manual_guide/node050F.html) and
MYATTR attributes.  If it finds the PGA_Top attribute, it changes PGA_Top
to [STRINGA_LongVal](../Libraries_Manual_guide/node0512.html).  Likewise, if the gadget finds the MYATTR attribute,
it changes MYATTR to MYNEWATTR.  The gadget does not disturb the
attribute's value, only its ID.

