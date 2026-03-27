---
title: 5 / / Custom String Editing / Actions with SGH_CLICK
manual: libraries
chapter: libraries
section: 5-custom-string-editing-actions-with-sgh-click
functions: []
libraries: []
---

# 5 / / Custom String Editing / Actions with SGH_CLICK

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[SGA_END](libraries/5-custom-string-editing-actions-definitions.md) or [SGA_REUSE](libraries/5-custom-string-editing-actions-definitions.md) may not be set for the [SGH_CLICK command](libraries/5-custom-string-editing-the-sgh-click-command.md). Intuition
will not allow gadgets which go inactive when chosen by the user. The
gadget always consumes mouse events in its select box.

With SGH_CLICK, always leave the [SGA_REDISPLAY](libraries/5-custom-string-editing-actions-definitions.md) flag set, since Intuition
uses this when activating a [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget.

