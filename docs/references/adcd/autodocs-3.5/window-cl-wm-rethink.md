---
title: window_cl/WM_RETHINK
manual: autodocs-3.5
chapter: autodocs-3.5
section: window-cl-wm-rethink
functions: []
libraries: []
---

# window_cl/WM_RETHINK

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       WM_RETHINK -- Re-evaluate an open window's size requirement
   SYNOPSIS

```c
       window = DoMethod( winobj, WM_RETHINK );
```
   FUNCTION

       This function re-evaluates the layout group's minimum size
       and adjusts the window size to contain it if needed.
   RESULTS

       Non-Zero if implemented.
