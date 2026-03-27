# graphics.library/CoerceMode



   NAME
	CoerceMode -- calculate [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) mode coercion (V39)

   SYNOPSIS
	ID = CoerceMode(RealViewPort, MonitorID, Flags);
	d0              a0            d0         d1

	ULONG CoerceMode(struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) *, ULONG, ULONG);

   FUNCTION
	To determine the best mode in the MonitorID to coerce RealViewPort to,
	given the restrictions set in Flags.

   INPUTS
	RealViewPort - [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) to coerce
	MonitorID    - Montor number to coerce to (ie a mode masked with
	               MONITOR_ID_MASK).
	Flags        - PRESERVE_COLORS - keep the number of bitplanes
	               in the [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46).
	               AVOID_FLICKER - do not coerce to an interlace mode

   RESULTS
	ID      - ID of the best mode to coerce to, or INVALID_ID if could not
	          coerce (see NOTES).

   NOTES
	This function takes into account the compatibility of the Monitor
	being coerced to, and the [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) that is being coerced.
	Incompatibilities will cause a result of INVALID_ID.

   EXAMPLE
	newmode = CoerceMode(vp, VGA_MONITOR_ID, PRESERVE_COLORS);

   SEE ALSO
	[<graphics/coerce.h>](../Includes_and_Autodocs_3._guide/node0662.html) [<graphics/displayinfo.h>](../Includes_and_Autodocs_3._guide/node05FF.html)

