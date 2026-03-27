---
title: asl.library/RequestFile
manual: autodocs-3.5
chapter: autodocs-3.5
section: asl-library-requestfile-2
functions: [AslRequest]
libraries: [asl.library]
---

# asl.library/RequestFile

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RequestFile -- request user to select files. (V36)

   SYNOPSIS
	result = RequestFile(requester);
	D0                   A0

	[BOOL](autodocs-3.5/include-exec-types-h.md) RequestFile(struct [FileRequester](autodocs-3.5/include-libraries-asl-h.md) *);

   NOTES
	This function is obsolete, please use [AslRequest()](autodocs-3.5/asl-library-aslrequest-2.md) instead.

   SEE ALSO
	[AslRequest()](autodocs-3.5/asl-library-aslrequest-2.md)

---

## See Also

- [AslRequest — asl.library](../autodocs/asl.library.md#aslrequest)
