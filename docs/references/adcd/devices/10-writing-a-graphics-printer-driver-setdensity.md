---
title: 10 / Writing A Graphics Printer Driver / SetDensity()
manual: devices
chapter: devices
section: 10-writing-a-graphics-printer-driver-setdensity
functions: []
libraries: []
---

# 10 / Writing A Graphics Printer Driver / SetDensity()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

SetDensity() is a short function which implements multiple densities. It
is called in the Pre-master initialization case of the Render() function.
It is passed the density code in density_code. This is used to select the
desired density or, if the user asked for a higher density than is
supported, the maximum density available.  SetDensity() should also handle
narrow and wide tractor paper sizes.

Densities below 80 dpi should not be supported in SetDensity(), so that a
minimum of 640 dots across for a standard 8.5x11-inch paper is guaranteed.
This results in a 1:1 correspondence of dots on the printer to dots on the
screen in standard screen sizes. The HP LaserJet is an exception to this
rule. Its minimum density is 75 dpi because the original HP LaserJet had
too little memory to output a full page at a higher density.

