---
title: dos.library/Output
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-output-2
functions: [Input, Output]
libraries: [dos.library]
---

# dos.library/Output

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	Output -- Identify the programs' initial output file handle

    SYNOPSIS
	file = Output()
	D0

	[BPTR](autodocs-3.5/include-dos-dos-h.md) Output(void)

    FUNCTION
	Output() is used to identify the initial output stream allocated
	when the program was initiated.  Never close the filehandle returned
	by Output().

    RESULTS
	file - BCPL pointer to a file handle

    SEE ALSO
	[Input()](autodocs-3.5/dos-library-input-2.md)

---

## See Also

- [Input — dos.library](../autodocs/dos.library.md#input)
- [Output — dos.library](../autodocs/dos.library.md#output)
