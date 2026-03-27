---
title: OM_GET
manual: amiga-mail
chapter: amiga-mail
section: om-get
functions: []
libraries: []
---

# OM_GET

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Retrieve an object's attribute.  This method receives the following
parameters:


```c
    struct opGet
    {
        ULONG MethodID;
        ULONG opg_AttrID;
        ULONG *opg_Storage;
    };
```
If the new class recognizes the attribute, the new class should fill in
opg_Storage's target with the attribute's value.  If the attribute is
actually the attribute of some component object, you might want to pass
the message on and let the component object process the OM_GET. If
completely unrecognized, you should pass the message to your superclass.

