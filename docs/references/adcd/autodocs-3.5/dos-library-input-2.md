---
title: dos.library/Input
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-input-2
functions: [Input, Output, SelectInput]
libraries: [dos.library]
---

# dos.library/Input

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	Input -- Identify the program's initial input file handle

    SYNOPSIS
	file = Input()
	D0

	[BPTR](autodocs-3.5/include-dos-dos-h.md) Input(void)

    FUNCTION
	Input() is used to identify the initial input stream allocated when
	the program was initiated.  Never close the filehandle returned by
	Input!

    RESULTS
	file - BCPL pointer to a file handle

    SEE ALSO
	[Output()](autodocs-3.5/dos-library-output-2.md), [SelectInput()](autodocs-3.5/dos-library-selectinput-2.md)

---

## See Also

- [Input — dos.library](../autodocs/dos.library.md#input)
- [Output — dos.library](../autodocs/dos.library.md#output)
- [SelectInput — dos.library](../autodocs/dos.library.md#selectinput)
