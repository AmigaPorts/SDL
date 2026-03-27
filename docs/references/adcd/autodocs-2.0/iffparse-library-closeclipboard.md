---
title: iffparse.library/CloseClipboard
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-closeclipboard
functions: [InitIFFasClip, OpenClipboard]
libraries: [iffparse.library]
---

# iffparse.library/CloseClipboard

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CloseClipboard -- Close and free an open [ClipboardHandle](autodocs-2.0/includes-libraries-iffparse-h.md).
```
SYNOPSIS

```c
    CloseClipboard (clip)
                     a0

    struct [ClipboardHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *clip;
```
FUNCTION

```c
    Closes the clipboard.device and frees the [ClipboardHandle](autodocs-2.0/includes-libraries-iffparse-h.md) structure.
```
INPUTS

```c
    clip    - pointer to [ClipboardHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct created with
              [OpenClipboard](autodocs-2.0/iffparse-library-openclipboard.md).
```
RESULT

EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [OpenClipboard()](autodocs-2.0/iffparse-library-openclipboard.md), [InitIFFasClip()](autodocs-2.0/iffparse-library-initiffasclip.md)
```

---

## See Also

- [InitIFFasClip — iffparse.library](../autodocs/iffparse.library.md#initiffasclip)
- [OpenClipboard — iffparse.library](../autodocs/iffparse.library.md#openclipboard)
