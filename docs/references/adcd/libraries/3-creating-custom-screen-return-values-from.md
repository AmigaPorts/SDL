---
title: 3 / / Creating Custom Screen / Return Values from OpenScreenTagList()
manual: libraries
chapter: libraries
section: 3-creating-custom-screen-return-values-from
functions: [OpenScreenTagList]
libraries: [intuition.library]
---

# 3 / / Creating Custom Screen / Return Values from OpenScreenTagList()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[OpenScreenTagList()](libraries/3-intuition-screens-custom-screen-functions.md) and its variants return a pointer to a [Screen](libraries/3-screen-data-structures-other-screen-data-structures.md)
structure on the successful creation of a new screen and NULL on failure.
With V36, the call now supports extended error codes on failure.  The
error returns provide information on the type of failure, giving the
application a greater chance of recovery.  To get the extended error code,
you need to use the [SA_ErrorCode](libraries/3-custom-screen-functions-screen-attributes.md) tag; the code itself will be placed into
the LONG pointed to by the [TagItem.ti_Data](libraries/37-tags-tag-functions-and-structures.md) field.  Here are the codes:

OSERR_NOMONITOR

    The monitor needed to display the requested mode is not available. An
    example of this error would be opening a Productivity mode screen on
    a system without a VGA or multisync monitor.
OSERR_NOCHIPS

```c
    Newer custom chips are required for this screen mode.  For instance,
    the ECS Denise is required for the [productivity modes](libraries/27-about-ecs-productivity-mode.md).
```
OSERR_NOMEM

    Could not allocate enough memory.
OSERR_NOCHIPMEM

    Could not allocate enough Chip memory.
OSERR_PUBNOTUNIQUE

```c
    Could not create [public screen](libraries/3-public-screen-functions-taking-a-new-custom-screen-public.md)--name already used.  The system
    requires that public screen names be unique.
```
OSERR_UNKNOWNMODE

```c
    Display mode requested was not recognized.  The system does not
    understand the value specified with the [SA_DisplayID](libraries/3-custom-screen-functions-screen-attributes.md) tag.
```

---

## See Also

- [OpenScreenTagList — intuition.library](../autodocs/intuition.library.md#openscreentaglist)
