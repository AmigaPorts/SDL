---
title: layers.library (basename: _LayersBase)
manual: amiga-mail
chapter: amiga-mail
section: layers-library-basename-layersbase
functions: []
libraries: []
---

# layers.library (basename: _LayersBase)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

CreateBehindHookLayer(li,bm,x0,y0,x1,y1,flags,hook,bm2)
```c
                                         (a0/a1,d0/d1/d2/d3/d4/a3,a2)
                                        - Create a new layer behind all
                                          existing layers.
```
CreateUpfrontHookLayer(li,bm,x0,y0,x1,y1,flags,hook,bm2)
```c
                                         (a0/a1,d0/d1/d2/d3/d4/a3,a2)
                                        - Create a new layer on top of
                                          existing layers.
```
InstallLayerHook(layer,hook)(a0/a1)     - Safely install a new
                                          Layer->BackFill hook.
MoveSizeLayer(layer,dx,dy,dw,dh)(a0,d0/d1/d2/d3)

                                        - Position/Size layer
