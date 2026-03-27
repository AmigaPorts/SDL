---
title: reaction.lib/GetCode
manual: autodocs-3.5
chapter: autodocs-3.5
section: reaction-lib-getcode
functions: []
libraries: []
---

# reaction.lib/GetCode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       GetCode -- return the true IDCMP message code
   SYNOPSIS

```c
       code = GetCode( imsg )

       [UWORD](autodocs-3.5/include-exec-types-h.md) GetCode( struct [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) * )
```
   FUNCTION

```c
       Returns the true [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) code field. Layout.gadget replaces
       the IDCMP_GADGETUP message with an IDCMP_IDCMPUPDATE. This function
       will return the "gadgetup code" from the IDCMPUPDATE taglist if it
       is found there, and otherwise the normal imsg->Code.
```
   INPUTS

```c
       imsg -- a pointer to an [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md)
```
   RESULTS

       The message's code field
