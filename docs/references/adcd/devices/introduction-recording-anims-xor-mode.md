---
title: Introduction Recording ANIMs / XOR mode
manual: devices
chapter: devices
section: introduction-recording-anims-xor-mode
functions: []
libraries: []
---

# Introduction Recording ANIMs / XOR mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This mode is the original and is included here for historical interest.
In general, the delta modes are far superior. The creation of XOR mode is
quite simple.  One simply performs an exclusive-or (XOR) between all
corresponding bytes of the new frame and two frames back.  This results in
a new bitmap with 0 bits wherever the two frames were identical, and 1
bits where they are different.  Then this new bitmap is saved using
run-length-encoding.  A major obstacle of this mode is in the time
consumed in performing the XOR upon reconstructing the image.

