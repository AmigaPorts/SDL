# colorwheel.gadget/ConvertHSBToRGB



   NAME
	ConvertHSBToRGB -- convert from an HSB color space to an RGB color
			   space. (V39)

   SYNOPSIS
	ConvertHSBToRGB(hsb, rgb);
		        A0   A1

	VOID ConvertHSBToRGB(struct [ColorWheelHSB](../Includes_and_Autodocs_3._guide/node05EE.html#line22) *, struct [ColorWheelRGB](../Includes_and_Autodocs_3._guide/node05EE.html#line30) *);

   FUNCTION
	Converts a color from an HSB representation to an RGB representation.

   INPUTS
	hsb - filled-in [ColorWheelHSB](../Includes_and_Autodocs_3._guide/node05EE.html#line22) structure containing the values to
	      convert
	rgb - structure to receive the converted values

   BUGS
	Even though all communication with the color wheel is done using full
	32-bit color components, color calculations are currently done using
	16-bit math, which can cause certain rounding errors to appear.

