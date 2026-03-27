---
title: Introduction / Recording ANIMs / General Delta mode
manual: devices
chapter: devices
section: introduction-recording-anims-general-delta-mode
functions: []
libraries: []
---

# Introduction / Recording ANIMs / General Delta mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The above two delta compression modes were hastily put together. This mode
was an attempt to provide a well-thought-out delta compression scheme.
Options provide for both short and long word compression, either vertical
or horizontal compression, XOR mode (which permits reverse playback), etc.
About the time this was being finalized, the fifth mode, below, was
developed by Jim Kent.  In practice the short-vertical-run-length-encoded
deltas in this mode play back faster than the fifth mode (which is in
essence a byte-vertical-run-length-encoded delta mode) but does not
compress as well - especially for very noisy data such as digitized
images.  In most cases, playback speed not being terrifically slower, the
better compression (sometimes 2x) is preferable due to limited storage
media in most machines.

Details on this method are contained in the Format for Method 4
sub-section within the Delta Chunk section.

