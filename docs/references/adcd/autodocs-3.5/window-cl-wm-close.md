---
title: window_cl/WM_CLOSE
manual: autodocs-3.5
chapter: autodocs-3.5
section: window-cl-wm-close
functions: []
libraries: []
---

# window_cl/WM_CLOSE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       WM_CLOSE -- [Close](autodocs-3.5/dos-library-close-2.md) a window
```
   SYNOPSIS

```c
       DoMethod( winobj, WM_CLOSE );
```
   FUNCTION

```c
       [Close](autodocs-3.5/dos-library-close-2.md) the window of this object. The gadgets are not disposed,
       only detached of a window. If the window is sharing a message
       port with another window, the port will be cleaned of message
       intended for this window. If the window was iconified, the icon
       will be removed.
```
