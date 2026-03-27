---
title: FD/cia_lib.fd
manual: autodocs-2.0
chapter: autodocs-2.0
section: fd-cia-lib-fd
functions: []
libraries: []
---

# FD/cia_lib.fd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* "CiaA.Resource" and "CiaB.Resource"
##bias 6
##public
AddICRVector(resource,iCRBit,interrupt)(a6,d0/a1)
RemICRVector(resource,iCRBit,interrupt)(a6,d0/a1)
AbleICR(resource,mask)(a6,d0)
SetICR(resource,mask)(a6,d0)
##end

