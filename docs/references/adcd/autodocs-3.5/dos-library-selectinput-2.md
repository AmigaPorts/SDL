---
title: dos.library/SelectInput
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-selectinput-2
functions: [Input, Output, SelectOutput]
libraries: [dos.library]
---

# dos.library/SelectInput

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SelectInput -- Select a filehandle as the default input channel (V36)

   SYNOPSIS
	old_fh = SelectInput(fh)
	D0                   D1

	[BPTR](autodocs-3.5/include-dos-dos-h.md) SelectInput(BPTR)

   FUNCTION
	Set the current input as the default input for the process.
	This changes the value returned by [Input()](autodocs-3.5/dos-library-input-2.md).  old_fh should
	be closed or saved as needed.

   INPUTS
	fh     - Newly default input handle

   RESULT
	old_fh - Previous default input filehandle

   SEE ALSO
	[Input()](autodocs-3.5/dos-library-input-2.md), [SelectOutput()](autodocs-3.5/dos-library-selectoutput-2.md), [Output()](autodocs-3.5/dos-library-output-2.md)

---

## See Also

- [Input — dos.library](../autodocs/dos.library.md#input)
- [Output — dos.library](../autodocs/dos.library.md#output)
- [SelectOutput — dos.library](../autodocs/dos.library.md#selectoutput)
