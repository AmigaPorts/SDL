---
title: colorwheel.gadget/ConvertHSBToRGB
manual: autodocs-3.5
chapter: autodocs-3.5
section: colorwheel-gadget-converthsbtorgb
functions: []
libraries: []
---

# colorwheel.gadget/ConvertHSBToRGB

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ConvertHSBToRGB -- convert from an HSB color space to an RGB color
			   space. (V39)

   SYNOPSIS
	ConvertHSBToRGB(hsb, rgb);
		        A0   A1

	VOID ConvertHSBToRGB(struct [ColorWheelHSB](autodocs-3.5/include-gadgets-colorwheel-h.md) *, struct [ColorWheelRGB](autodocs-3.5/include-gadgets-colorwheel-h.md) *);

   FUNCTION
	Converts a color from an HSB representation to an RGB representation.

   INPUTS
	hsb - filled-in [ColorWheelHSB](autodocs-3.5/include-gadgets-colorwheel-h.md) structure containing the values to
	      convert
	rgb - structure to receive the converted values

   BUGS
	Even though all communication with the color wheel is done using full
	32-bit color components, color calculations are currently done using
	16-bit math, which can cause certain rounding errors to appear.

