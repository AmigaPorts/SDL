---
title: FD/mathffp_lib.fd
manual: autodocs-2.0
chapter: autodocs-2.0
section: fd-mathffp-lib-fd
functions: []
libraries: []
---

# FD/mathffp_lib.fd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* "mathffp.library"
##base _MathBase
##bias 30
##public
SPFix(parm)(d0)
SPFlt(integer)(d0)
SPCmp(leftParm,rightParm)(d1,d0)
SPTst(parm)(d1)
SPAbs(parm)(d0)
SPNeg(parm)(d0)
SPAdd(leftParm,rightParm)(d1,d0)
SPSub(leftParm,rightParm)(d1,d0)
SPMul(leftParm,rightParm)(d1,d0)
SPDiv(leftParm,rightParm)(d1,d0)
*--- functions in V33 or higher (distributed as Release 1.2) ---
SPFloor(parm)(d0)
SPCeil(parm)(d0)
##end

