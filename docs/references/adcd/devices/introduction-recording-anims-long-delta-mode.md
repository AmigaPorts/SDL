---
title: Introduction / Recording ANIMs / Long Delta mode
manual: devices
chapter: devices
section: introduction-recording-anims-long-delta-mode
functions: []
libraries: []
---

# Introduction / Recording ANIMs / Long Delta mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This mode stores the actual new frame long-words which are different,
along with the offset in the bitmap.  The exact format is shown and
discussed in section 2 below. Each plane is handled separately, with no
data being saved if no changes take place in a given plane.  Strings of 2
or more long-words in a row which change can be run together so offsets do
not have to be saved for each one.

Constructing this data chunk usually consists of having a buffer to hold
the data, and calculating the data as one compares the new frame,
long-word by long-word, with two frames back.

