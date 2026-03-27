---
title: iffparse.library/OpenClipboard
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-openclipboard
functions: [CloseClipboard, InitIFFasClip]
libraries: [iffparse.library]
---

# iffparse.library/OpenClipboard

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    OpenClipboard -- Create a handle on a clipboard unit.
SYNOPSIS

```c
    ch = OpenClipboard (unit)
    d0                   d0

    struct [ClipboardHandle](autodocs-2.0/includes-libraries-iffparse-h.md)   *ch;
    LONG                    unit;
```
FUNCTION

```c
    Opens the clipboard.device and opens a stream for the specified unit
    (usually PRIMARY_CLIP).  This handle structure will be used as the
    clipboard stream for IFFHandles initialized as clipboard streams by
    [InitIFFasClip()](autodocs-2.0/iffparse-library-initiffasclip.md).
```
INPUTS

```c
    unit    - clipboard unit number (usually PRIMARY_CLIP).
```
RESULT

```c
    ch      - pointer to [ClipboardHandle](autodocs-2.0/includes-libraries-iffparse-h.md) structure or NULL if
              unsuccessful.
```
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [InitIFFasClip()](autodocs-2.0/iffparse-library-initiffasclip.md), [CloseClipboard()](autodocs-2.0/iffparse-library-closeclipboard.md)
```

---

## See Also

- [CloseClipboard — iffparse.library](../autodocs/iffparse.library.md#closeclipboard)
- [InitIFFasClip — iffparse.library](../autodocs/iffparse.library.md#initiffasclip)
