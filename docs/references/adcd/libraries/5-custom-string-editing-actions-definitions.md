---
title: 5 / / Custom String Editing / Actions Definitions
manual: libraries
chapter: libraries
section: 5-custom-string-editing-actions-definitions
functions: []
libraries: []
---

# 5 / / Custom String Editing / Actions Definitions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

These are the actions to be taken by Intuition after the hook returns.
Set or clear these bits in [SGWork](libraries/5-custom-string-editing-sgwork-structure.md) structure Actions field.  A number of
these flags may already be set when the hook is called.


  Actions Flag    Purpose
  ------------    -------
  SGA_USE         If set, use contents of [SGWork](libraries/5-custom-string-editing-sgwork-structure.md).
  SGA_END         Terminate gadget, Code field is sent to application
```c
                  in [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) event code field.
```
  SGA_BEEP        Beep (i.e., flash) the screen.
  SGA_REUSE       Reuse the input event.  Only valid with SGA_END.
  SGA_REDISPLAY   Gadget visuals have changed, update on screen.
  SGA_NEXTACTIVE  Make next possible gadget active (new for V37).
  SGA_PREVACTIVE  Make previous possible gadget active (new for V37).

