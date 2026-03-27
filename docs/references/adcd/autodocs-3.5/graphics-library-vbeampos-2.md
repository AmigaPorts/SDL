---
title: graphics.library/VBeamPos
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-vbeampos-2
functions: [VBeamPos]
libraries: [graphics.library]
---

# graphics.library/VBeamPos

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME   
	VBeamPos -- Get vertical beam position at this instant.

   SYNOPSIS
	pos = VBeamPos()
	 d0

	[LONG](autodocs-3.5/include-exec-types-h.md) VBeamPos( void );

   FUNCTION
	Get the vertical beam position from the hardware.

   INPUTS
	none

   RESULT
	interrogates hardware for beam position and returns value.
	valid results in are the range of 0-511.
	Because of multitasking, the actual value returned may have
	no use. If you are the highest priority task then the value
	returned should be close, within 1 line.

   BUGS

   SEE ALSO

---

## See Also

- [VBeamPos — graphics.library](../autodocs/graphics.library.md#vbeampos)
