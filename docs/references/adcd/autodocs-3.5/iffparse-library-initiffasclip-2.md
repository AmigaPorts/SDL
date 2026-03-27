---
title: iffparse.library/InitIFFasClip
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-initiffasclip-2
functions: [InitIFF, OpenClipboard]
libraries: [iffparse.library]
---

# iffparse.library/InitIFFasClip

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	InitIFFasClip -- initialize an [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) as a clipboard stream. (V36)

   SYNOPSIS
	InitIFFasClip(iff);
	              A0

	VOID InitIFFasClip(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *);

   FUNCTION
	Initializes the given [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) to be a clipboard stream. The
	function initializes the stream processing vectors to operate on
	streams of the [ClipboardHandle](autodocs-3.5/include-libraries-iffparse-h.md) type. The iff_Stream field will still
	need to be initialized to point to a [ClipboardHandle](autodocs-3.5/include-libraries-iffparse-h.md) as returned from
	[OpenClipboard()](autodocs-3.5/iffparse-library-openclipboard-2.md).

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure.

   SEE ALSO
	[InitIFF()](autodocs-3.5/iffparse-library-initiff-2.md), [OpenClipboard()](autodocs-3.5/iffparse-library-openclipboard-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [InitIFF — iffparse.library](../autodocs/iffparse.library.md#initiff)
- [OpenClipboard — iffparse.library](../autodocs/iffparse.library.md#openclipboard)
