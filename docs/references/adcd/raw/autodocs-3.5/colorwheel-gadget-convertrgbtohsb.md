# colorwheel.gadget/ConvertRGBToHSB



   NAME
	ConvertRGBToHSB -- convert from an RGB color space to an HSB color
			   space. (V39)

   SYNOPSIS
	ConvertRGBToHSB(rgb, hsb);
		        A0   A1

	VOID ConvertRGBToHSB(struct [ColorWheelRGB](../Includes_and_Autodocs_3._guide/node05EE.html#line30) *, struct [ColorWheelHSB](../Includes_and_Autodocs_3._guide/node05EE.html#line22) *);

   FUNCTION
	Converts a color from an RGB representation to an HSB representation.

   INPUTS
	rgb - filled-in [ColorWheelRGB](../Includes_and_Autodocs_3._guide/node05EE.html#line30) structure containing the values to
	      convert
	hsb - structure to receive the converted values

   BUGS
	Even though all communication with the color wheel is done using full
	32-bit color components, color calculations are currently done using
	16-bit math, which can cause certain rounding errors to appear.

