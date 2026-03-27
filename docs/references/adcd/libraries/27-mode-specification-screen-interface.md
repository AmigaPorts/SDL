---
title: 27 / / / Mode Specification, Screen Interface
manual: libraries
chapter: libraries
section: 27-mode-specification-screen-interface
functions: []
libraries: []
---

# 27 / / / Mode Specification, Screen Interface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Opening an Intuition screen in one of the new modes requires the
specification of 32 bits of mode data.  The [NewScreen.ViewModes](autodocs-2.0/includes-intuition-screens-h.md) field is a
UWORD (16 bits).  Therefore, the new Release 2 function [OpenScreenTags()](libraries/3-intuition-screens-custom-screen-functions.md)
must be used along with a SA_DisplayID tag which specifies the 32-bit
ModeID.  See the "[Intuition Screens](libraries/3-drawinfo-and-the-3d-look-cloning-a-public-screen-workbench.md)" chapter for more on this.

The new display modes also introduce some complexity for applications that
want to support "mode-sensitive" processing.  If a program wishes to open
a screen in the highest resolution that a user has available, there are
many more cases to handle under Release 2.  Therefore, it will become
increasingly important to algorithmically layout a screen for correct,
functional and aesthetic operation.  All the information needed to be
mode-flexible is available through the display database functions
(explained below).

