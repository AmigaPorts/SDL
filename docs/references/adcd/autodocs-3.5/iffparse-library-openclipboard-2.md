---
title: iffparse.library/OpenClipboard
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-openclipboard-2
functions: [CloseClipboard, FreeSignal, InitIFFasClip, OpenDevice]
libraries: [exec.library, iffparse.library]
---

# iffparse.library/OpenClipboard

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	OpenClipboard -- create a handle on a clipboard unit. (V36)

   SYNOPSIS
	ch = OpenClipboard(unitNumber)
	D0                 D0

	struct [ClipboardHandle](autodocs-3.5/include-libraries-iffparse-h.md) *OpenClipboard(LONG);

   FUNCTION
	Opens the clipboard.device and opens a stream for the specified unit
	(usually PRIMARY_CLIP). This handle structure will be used as the
	clipboard stream for IFFHandles initialized as clipboard streams by
	[InitIFFasClip()](autodocs-3.5/iffparse-library-initiffasclip-2.md).

   INPUTS
	unitNumber - clipboard unit number (usually PRIMARY_CLIP).

   RESULT
	ch - pointer to [ClipboardHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure or NULL if unsuccessful.

   BUGS
	This function had several bugs prior to V39.

       First bug was that if the clipboard.device couldn't open, two calls
	to [FreeSignal()](autodocs-3.5/exec-library-freesignal-2.md) were made with uninitialized values as parameters.
	The result of this was a corrupt signal mask in the [Task](autodocs-3.5/include-exec-tasks-h.md) field.

	Second bug was that [OpenDevice()](autodocs-3.5/serial-device-opendevice-2.md) was called with an IO request that
	didn't have a valid [MsgPort](autodocs-3.5/include-exec-ports-h.md) pointer in it.

	Third bug was that the two message ports allocated by the function
	(ClipboardHandle->cbh_CBport and ClipboardHandle->cbh_SatisfyPort)
	were not being initialized correctly and would cause a system crash
	if a message ever got to either of them.

   SEE ALSO
	[InitIFFasClip()](autodocs-3.5/iffparse-library-initiffasclip-2.md), [CloseClipboard()](autodocs-3.5/iffparse-library-closeclipboard-2.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [CloseClipboard — iffparse.library](../autodocs/iffparse.library.md#closeclipboard)
- [FreeSignal — exec.library](../autodocs/exec.library.md#freesignal)
- [InitIFFasClip — iffparse.library](../autodocs/iffparse.library.md#initiffasclip)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
