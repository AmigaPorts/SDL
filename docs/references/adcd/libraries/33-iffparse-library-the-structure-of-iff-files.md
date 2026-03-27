---
title: 33 IFFParse Library / The Structure of IFF Files
manual: libraries
chapter: libraries
section: 33-iffparse-library-the-structure-of-iff-files
functions: []
libraries: []
---

# 33 IFFParse Library / The Structure of IFF Files

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Many people have a misconception that IFF means image files.  This is not
the case.  IFF (short for Interchange File Format) is a method of portably
storing structured information in machine-readable form. The actual
information can be anything, but the manner in which it is stored is very
specifically detailed.  This specification is the IFF standard.

The IFF standard was originally designed in 1985 by Electronic Arts in
conjunction with a committee of developers.  The full standard along with
file descriptions and sample code is published in the Amiga ROM Kernel
Reference Manual: [Devices](devices/appendix-a-iff-interchange-file-format.md) (3rd edition).

The goal of the IFF standard is to allow customers to move their own data
between independently developed software products.  The types of data
objects to exchange are open-ended and currently include plain and
formatted text, raster and structured graphics, fonts, music, sound
effects, musical instrument descriptions, and animation.  IFF addresses
these needs by defining a standard for self-identifying file structures
and rules for accessing these files.

 [Chunks: The Building Blocks of IFF](libraries/33-the-structure-of-iff-files-chunks-the-building-blocks-of.md)    [Composite Data Types](libraries/33-the-structure-of-iff-files-composite-data-types.md) 

