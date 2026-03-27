---
title: colorwheel.gadget/ConvertRGBToHSB
manual: autodocs-3.5
chapter: autodocs-3.5
section: colorwheel-gadget-convertrgbtohsb
functions: []
libraries: []
---

# colorwheel.gadget/ConvertRGBToHSB

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ConvertRGBToHSB -- convert from an RGB color space to an HSB color
			   space. (V39)

   SYNOPSIS
	ConvertRGBToHSB(rgb, hsb);
		        A0   A1

	VOID ConvertRGBToHSB(struct [ColorWheelRGB](autodocs-3.5/include-gadgets-colorwheel-h.md) *, struct [ColorWheelHSB](autodocs-3.5/include-gadgets-colorwheel-h.md) *);

   FUNCTION
	Converts a color from an RGB representation to an HSB representation.

   INPUTS
	rgb - filled-in [ColorWheelRGB](autodocs-3.5/include-gadgets-colorwheel-h.md) structure containing the values to
	      convert
	hsb - structure to receive the converted values

   BUGS
	Even though all communication with the color wheel is done using full
	32-bit color components, color calculations are currently done using
	16-bit math, which can cause certain rounding errors to appear.

