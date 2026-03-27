---
title: FD/mathieeedoubbas_lib.fd
manual: autodocs-2.0
chapter: autodocs-2.0
section: fd-mathieeedoubbas-lib-fd
functions: []
libraries: []
---

# FD/mathieeedoubbas_lib.fd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* "mathieeedoubbas.library"
##base _MathIeeeDoubBasBase
##bias 30
##public
IEEEDPFix(parm)(d0/d1)
IEEEDPFlt(integer)(d0)
IEEEDPCmp(leftParm,rightParm)(d0/d1/d2/d3)
IEEEDPTst(parm)(d0/d1)
IEEEDPAbs(parm)(d0/d1)
IEEEDPNeg(parm)(d0/d1)
IEEEDPAdd(leftParm,rightParm)(d0/d1/d2/d3)
IEEEDPSub(leftParm,rightParm)(d0/d1/d2/d3)
IEEEDPMul(factor1,factor2)(d0/d1/d2/d3)
IEEEDPDiv(dividend,divisor)(d0/d1/d2/d3)
*--- functions in V33 or higher (distributed as Release 1.2) ---
IEEEDPFloor(parm)(d0/d1)
IEEEDPCeil(parm)(d0/d1)
##end

