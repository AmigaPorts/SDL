---
title: Backfill Hook
manual: amiga-mail
chapter: amiga-mail
section: backfill-hook
functions: []
libraries: []
---

# Backfill Hook

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Whenever a layer sustains damage, the damaged region is cleared to
color 0.  Clearing the region requires an often lengthy Blitter
operation which is unnecessary if the application plans to redraw the
damaged region anyway.  Such an application can improve its
performance by preventing the Layers library from clearing the
damaged regions.  This is what layer backfill hooks are for.

Backfill hooks are a new Layers library feature added in Release 2.
A backfill hook is a custom function that an application attaches to
a specific layer.  Whenever damage occurs to a layer, the Layers
library calls that layer's custom backfill hook.  The Layers library
passes the position and dimensions of the damage area to the backfill
hook.  The backfill hook can render into the damage area, refreshing
it.  Theoretically, the backfill hook can redraw a layer's damaged
regions instead of clearing the damage area to color 0.

Unfortunately, refreshing a layer from a backfill hook can be quite
difficult.  The backfill hook code is usually called from a different
task than the main application.  If the backfill hook and the
application do not properly arbitrate access to the application's
data, dangerous race conditions can occur if the hook and the
application try to access the same data.  Another problem with
rendering through the backfill hook is that no clipping is available.
The backfill hook must do its own clipping to ensure that no
rendering goes outside the dimensions specified when the hook is
called, which in itself can be quite difficult.

For many situations, the best use of a backfill hook is to have it do
nothing.  Whenever the hook is called, it simply returns without
doing any rendering.  This has the effect of eliminating the extra
blit done to clear the damage region to color 0.  This can speed
layer operations quite a bit.

There is one problem with a no-op backfill hook.  If the application
is busy doing some processing and damage occurs to its layer, the
display will remain dirty until the application finishes its
processing and notices that the layer is damaged.  This damage can
include remnants of system imagery, like window borders, which can
confuse the user.

One way to overcome this problem is to use a backfill hook that
changes its behavior depending on the state of the application.  If
the application is not too busy to notice damage to its window's
layer, the backfill hook does not erase the display.  However, if the
application is too busy to refresh its damaged window, the backfill
hook clears the damaged portion of the display.  Using this method,
the backfill hook will not waste time erasing the damage when the
application will update it immediately, but the backfill hook will
erase the damage if the application can't refresh for a while.

