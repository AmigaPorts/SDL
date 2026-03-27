---
title: window_cl/WM_OPEN
manual: autodocs-3.5
chapter: autodocs-3.5
section: window-cl-wm-open
functions: []
libraries: []
---

# window_cl/WM_OPEN

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       WM_OPEN -- [Open](autodocs-3.5/dos-library-open-2.md) a window
```
   SYNOPSIS

```c
       window = DoMethod( winobj, WM_OPEN );
```
   FUNCTION

       This function opens the window the object should be handling.
       If the window is already open, it does nothing. If no shared
       message port is set, a message port will be created for this
       window.
   RESULTS

```c
       window -- a pointer to the struct [Window](autodocs-3.5/include-intuition-intuition-h.md) for this window, or
               NULL if the window could not be opened.
```
