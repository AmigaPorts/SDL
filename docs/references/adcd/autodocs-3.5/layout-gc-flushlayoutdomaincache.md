---
title: layout_gc/FlushLayoutDomainCache
manual: autodocs-3.5
chapter: autodocs-3.5
section: layout-gc-flushlayoutdomaincache
functions: []
libraries: []
---

# layout_gc/FlushLayoutDomainCache

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  NAME

```c
      FlushLayoutDomainCache -- [Flush](autodocs-3.5/dos-library-flush-2.md) layout domain cache below a level.
```
  SYNOPSIS

```c
      FlushLayoutDomainCache( layout )
                              a0

      void FlushLayoutDomainCache( struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) * )
```
  FUNCTION

```c
      Layout gadget normally caches GM_DOMAIN results from the child
      objects to speed up window re-layout. However, on some rare
      occassions a gadget's minimum or maximum domain might change
      after creation. For these instances layout gadget provides two
      methods of controlling the domain cache. You can set a caching on
      a child-by-child basis, using the CHILD_CacheDomain attribute, so
      that on each relayout the domain is calculated again. This
      method might have an extra performance hit, if the domain
      changes infrequently. It also has to be set for each parent
      layout level, which makes the amount of extra calculations grow
      quickly. The other method, for the cases where the application
      will know when a gadget's domain changes, it can call
      FlushLayoutDomainCache() with a pointer to the parent layout object.
      This call will flush the whole hierarchy, so that the next window
      re-layout will re-calculate child domains.
```
  INPUTS

```c
      layout = the layout object to flush. This should be the topmost
                  layout object for the window.
```
  SEE ALSO

```c
            --datasheet-- (CHILD_CacheDomain attribute)
```
