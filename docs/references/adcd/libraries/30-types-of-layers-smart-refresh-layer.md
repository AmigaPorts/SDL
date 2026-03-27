---
title: 30 / / Types of Layers / Smart Refresh Layer
manual: libraries
chapter: libraries
section: 30-types-of-layers-smart-refresh-layer
functions: []
libraries: []
---

# 30 / / Types of Layers / Smart Refresh Layer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Under smart refresh, the system provides dynamic backup of obscured
sections of the layer. The graphics routines will automatically draw into
these backup areas when they encounter an obscured part of the layer. The
backup memory will be used to automatically update the display when
obscured sections later become exposed.

With smart refresh layers, the system handles all of the refresh
requirements of the layer, except when the layer is made larger. When
parts of the layer are exposed by a sizing operation, the application must
refresh the newly exposed areas.

The advantage of smart refresh is the speed of updating exposed regions of
the layer and the ability of the system to manage part of the updating
process for the application.. Its main disadvantage is the additional
memory required to handle this automatic refresh.

