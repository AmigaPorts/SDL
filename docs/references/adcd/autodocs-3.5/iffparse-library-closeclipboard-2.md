---
title: iffparse.library/CloseClipboard
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-closeclipboard-2
functions: [InitIFFasClip, OpenClipboard]
libraries: [iffparse.library]
---

# iffparse.library/CloseClipboard

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CloseClipboard -- close and free an open [ClipboardHandle](autodocs-3.5/include-libraries-iffparse-h.md). (V36)

   SYNOPSIS
	CloseClipboard(clipHandle);
	               A0

	VOID CloseClipboard(struct [ClipboardHandle](autodocs-3.5/include-libraries-iffparse-h.md) *);

   FUNCTION
	Closes the clipboard.device and frees the [ClipboardHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure.

   INPUTS
	clipHandle - pointer to [ClipboardHandle](autodocs-3.5/include-libraries-iffparse-h.md) struct created with
	             [OpenClipboard()](autodocs-3.5/iffparse-library-openclipboard-2.md). Starting with V39, this may be NULL.

   SEE ALSO
	[OpenClipboard()](autodocs-3.5/iffparse-library-openclipboard-2.md), [InitIFFasClip()](autodocs-3.5/iffparse-library-initiffasclip-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [InitIFFasClip — iffparse.library](../autodocs/iffparse.library.md#initiffasclip)
- [OpenClipboard — iffparse.library](../autodocs/iffparse.library.md#openclipboard)
