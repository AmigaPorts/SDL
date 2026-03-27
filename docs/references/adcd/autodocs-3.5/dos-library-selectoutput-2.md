---
title: dos.library/SelectOutput
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-selectoutput-2
functions: [Input, Output, SelectInput]
libraries: [dos.library]
---

# dos.library/SelectOutput

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SelectOutput -- Select a filehandle as the default output channel (V36)

   SYNOPSIS
	old_fh = SelectOutput(fh)
	D0                    D1

	[BPTR](autodocs-3.5/include-dos-dos-h.md) SelectOutput(BPTR)

   FUNCTION
	Set the current output as the default output for the process.
	This changes the value returned by [Output()](autodocs-3.5/dos-library-output-2.md).  old_fh should
	be closed or saved as needed.

   INPUTS
	fh     - Newly desired output handle

   RESULT
	old_fh - Previous current output

   SEE ALSO
	[Output()](autodocs-3.5/dos-library-output-2.md), [SelectInput()](autodocs-3.5/dos-library-selectinput-2.md), [Input()](autodocs-3.5/dos-library-input-2.md)

---

## See Also

- [Input — dos.library](../autodocs/dos.library.md#input)
- [Output — dos.library](../autodocs/dos.library.md#output)
- [SelectInput — dos.library](../autodocs/dos.library.md#selectinput)
