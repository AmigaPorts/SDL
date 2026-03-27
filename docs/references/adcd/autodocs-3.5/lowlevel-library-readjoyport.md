---
title: lowlevel.library/ReadJoyPort
manual: autodocs-3.5
chapter: autodocs-3.5
section: lowlevel-library-readjoyport
functions: [WaitTOF]
libraries: [graphics.library]
---

# lowlevel.library/ReadJoyPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ReadJoyPort -- return the state of the selected joy/mouse port. (V40)

   SYNOPSIS
	portState = ReadJoyPort(portNumber);
	D0                      D0

	ULONG ReadJoyPort(ULONG);

   FUNCTION
	This function is used to determine what device is attached to the
	joy port and the current position/button state. The user may attach
	a mouse, game controller, or joystick to the port and this function
	will dynamically detect which device is attached and return the
	appropriatly formatted portState.

	To determine the type of controller that is attached, this function
	clocks the game controller and/or interprets changes in the joy
	port data. Valid clocked data from the game controller is immediately
	detected. However, to accuratly determine if a mouse or joystick is
	attached, several calls to this function are required along with some
	movement at the joy port by the user.

	This function always executes immediatly.

	This is a low level single threaded function that does not fit the
	normal Amiga multitasking model. Only one task can be executing
	this routine at any time. All others will return immediately with
	JP_TYPE_NOTAVAIL.

	The nature of this routine is not meant to encourage non-multitasking
	friendly programming practices like polling loops. If your task
	is waiting for a transition to be returned use a [WaitTOF()](autodocs-3.5/graphics-library-waittof-2.md) between
	calls to minimize the total system impact.

	When called the first time, for each port, this function attempts to
	acquire certain system resources. In order to aquire these resources
	this function MUST be called from a task, or a DOS process. If this
	function fails to aquire the necessary resources, it will
	return with JP_TYPE_NOTAVAIL. Once the resources are aquired (return
	value other than JP_TYPE_NOTAVAIL) this function may be used in
	interrupts.

   INPUTS
	portNumber - port to read, in the range 0 to 3.

   RESULT
	portState - bit map that identifies the device and the current
	            state of that device. The format of the bit map is
	            dependant on the type of device attached.

	            The following constants from [<libraries/lowlevel.h>](autodocs-3.5/include-libraries-lowlevel-h.md)
	            are used to determine which device is attached and
	            the state of that device.

	            The type of device can be determined by applying
	            the mask JP_TYPE_MASK to the return value and comparing
	            the resultant value with the following:

	                JP_TYPE_NOTAVAIL        port data unavailable
	                JP_TYPE_GAMECTLR        game controller
	                JP_TYPE_MOUSE           mouse
	                JP_TYPE_JOYSTK          joystick
	                JP_TYPE_UNKNOWN         unknown device

	            If type = JP_TYPE_GAMECTLR the bit map of portState is:
	                JPF_BUTTON_BLUE         Blue - Stop
	                JPF_BUTTON_RED          Red - Select
	                JPF_BUTTON_YELLOW       Yellow - Repeat
	                JPF_BUTTON_GREEN        Green - Shuffle
	                JPF_BUTTON_FORWARD      Charcoal - Forward
	                JPF_BUTTON_REVERSE      Charcoal - Reverse
	                JPF_BUTTON_PLAY         Grey - Play/Pause
	                JPF_JOY_UP              Up
	                JPF_JOY_DOWN            Down
	                JPF_JOY_LEFT            Left
	                JPF_JOY_RIGHT           Right

	            If type = JP_TYPE_JOYSTK the bit map of portState is:
	                JPF_BUTTON_BLUE         Right
	                JPF_BUTTON_RED          Fire
	                JPF_JOY_UP              Up
	                JPF_JOY_DOWN            Down
	                JPF_JOY_LEFT            Left
	                JPF_JOY_RIGHT           Right

	            If type = JP_TYPE_MOUSE the bit map of portState is:
	                JPF_BUTTON_BLUE         Right mouse
	                JPF_BUTTON_RED          Left mouse
	                JPF_BUTTON_PLAY         Middle mouse
	                JP_MVERT_MASK           Mask for vertical counter
	                JP_MHORZ_MASK           Mask for horizontal counter

   SEE ALSO
	SetJoyPortAttrs()

---

## See Also

- [WaitTOF — graphics.library](../autodocs/graphics.library.md#waittof)
