---
title: 7 / True Requesters / Requester Refresh Type
manual: libraries
chapter: libraries
section: 7-true-requesters-requester-refresh-type
functions: []
libraries: []
---

# 7 / True Requesters / Requester Refresh Type

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A requester appears in a [Layer](libraries/30-layers-the-layer-structure.md).  By default, the requester layer is of
type LAYERSMART, or, in window terminology, [WFLG_SMART_REFRESH](libraries/4-window-attributes-boolean-window-attribute-tags.md); so
rendering is preserved in the requester when the window is moved or
revealed.

Requesters may also be simple refresh.  This is the recommended type.  If
possible, make the requester a simple refresh layer requester by
specifying the SIMPLEREQ flag.

For all refresh types, Intuition will keep the gadget, border, image and
bitmap imagery properly refreshed.

