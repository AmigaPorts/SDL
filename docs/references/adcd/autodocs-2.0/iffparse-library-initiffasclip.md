---
title: iffparse.library/InitIFFasClip
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-initiffasclip
functions: [OpenClipboard]
libraries: [iffparse.library]
---

# iffparse.library/InitIFFasClip

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    InitIFFasClip -- Initialize an [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) as a clipboard stream.
```
SYNOPSIS

```c
    InitIFFasClip (iff)
                   a0

    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *iff;
```
FUNCTION

```c
    Initializes the given [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) to be a clipboard stream.  The
    function initializes the stream processing vectors to operate on
    streams of the [ClipboardHandle](autodocs-2.0/includes-libraries-iffparse-h.md) type.  The iff_Stream field will still
    need to be initialized to point to a [ClipboardHandle](autodocs-2.0/includes-libraries-iffparse-h.md) as returned from
    [OpenClipboard()](autodocs-2.0/iffparse-library-openclipboard.md).
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.
```
RESULT

EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [OpenClipboard()](autodocs-2.0/iffparse-library-openclipboard.md)
```

---

## See Also

- [OpenClipboard — iffparse.library](../autodocs/iffparse.library.md#openclipboard)
