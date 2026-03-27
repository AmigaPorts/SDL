---
title: Zooming
manual: amiga-mail
chapter: amiga-mail
section: zooming
functions: []
libraries: []
---

# Zooming

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A very simple, but convenient feature you can ask the system to add to
your window is a zoom gadget.  A zoom gadget allows the user to toggle
between two window sizes simply by clicking on a gadget.  In 2.0, a window
gets a zoom gadget automatically when it has both a sizing and depth
gadget, although you don't need a sizing gadget to get a zoom gadget.  You
can ask for a zoom gadget by specifying the WA_Zoom tag when opening the
window.  The WA_Zoom tag takes an array of four WORDs, describing the
initial LeftEdge, TopEdge, Width, and Height values of the window's
alternate dimensions and position. Because such a window has no sizing
gadget, the user can only toggle between two window sizes, the original
size and the alternate size specified with the WA_Zoom tag.  The
preference editors use this feature to toggle between a full-sized window
and a window displaying only the title bar.  The example [zoom.c](amiga-mail/iv-69-zoom-c.md) shows how
easy it is to implement this feature.

