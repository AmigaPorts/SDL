---
title: HookEntry
manual: autodocs-2.0
chapter: autodocs-2.0
section: hookentry
functions: [EntryHandler, ExitHandler, InitIFF, SetLocalItemPurge]
libraries: [iffparse.library]
---

# HookEntry

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    HookEntry -- call-back stub vector (LANGUAGE SPECIFIC LINK ROUTINE)
```
SYNOPSIS

    This function is never called directly by the client.
FUNCTION

```c
    HookEntry's purpose is to do language-specific setup and conversion
    of parameters passed from a library to a client call-back routine.
    Under Kickstart 2.0, a standard for call-backs has been established.
    The registers will contain the following items:

            A0:     pointer to hook that enabled us to get here.
            A2:     pointer to "object."
            A1:     pointer to "message packet."

    In iffparse, the "object" will vary from routine to routine.  The
    "message packet" is also specific to the operation involved (RTFM!).

    THIS ROUTINE IS NOT PART OF IFFPARSE.  It, or something similar, is
    part of the compiler vendor's link library.  (If it's not there,
    cobbling up your own isn't too hard.)
```
SEE ALSO

```c
    [EntryHandler()](autodocs-2.0/iffparse-library-entryhandler.md), [ExitHandler()](autodocs-2.0/iffparse-library-exithandler.md), [InitIFF()](autodocs-2.0/iffparse-library-initiff.md), [SetLocalItemPurge()](autodocs-2.0/iffparse-library-setlocalitempurge.md),
    [utility/hooks.h](autodocs-2.0/includes-utility-hooks-h.md) (A must-read;  LOTS of details in there)
```

---

## See Also

- [EntryHandler — iffparse.library](../autodocs/iffparse.library.md#entryhandler)
- [ExitHandler — iffparse.library](../autodocs/iffparse.library.md#exithandler)
- [InitIFF — iffparse.library](../autodocs/iffparse.library.md#initiff)
- [SetLocalItemPurge — iffparse.library](../autodocs/iffparse.library.md#setlocalitempurge)
