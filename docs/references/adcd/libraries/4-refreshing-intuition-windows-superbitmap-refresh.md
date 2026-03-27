---
title: 4 / / Refreshing Intuition Windows / SuperBitMap Refresh
manual: libraries
chapter: libraries
section: 4-refreshing-intuition-windows-superbitmap-refresh
functions: []
libraries: []
---

# 4 / / Refreshing Intuition Windows / SuperBitMap Refresh

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The SuperBitMap refresh type allows the application to provide and
maintain bitmap memory for graphics in the window.  The bitmap can be any
size as long as the window sizing limits respect the maximum size of the
bitmap.

SuperBitMap windows have their own memory for maintaining all obscured
parts of the window up to the size of the defined bitmap, including those
parts outside of the current window.  Intuition will update all parts of
the window that are revealed through changes in sizing and changes in
window overlapping.  The application never needs to redraw portions of the
window that were revealed by sizing or positioning windows in the screen.

SuperBitMap windows require the application to allocate a bitmap for use
as off-screen memory, instead of using Intuition managed buffers.  This
bitmap must be as large as, or larger than, the inner window's maximum
dimensions (that is, the window's outside dimensions less the border
sizes).

SuperBitMap windows are almost always [WFLG_GIMMEZEROZERO](libraries/4-window-attributes-boolean-window-attribute-tags.md), which renders
the borders and system gadgets in a separate bitmap.  If the application
wishes to create a SuperBitMap window that is not [GimmeZeroZero](libraries/4-window-types-gimmezerozero-window-type.md), it must
make the window borderless with no system gadgets, so that no border
imagery is rendered by Intuition into the application's bitmap.

