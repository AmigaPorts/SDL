---
title: 35 Math Libraries / Function Reference
manual: libraries
chapter: libraries
section: 35-math-libraries-function-reference
functions: [IEEEDPAbs, IEEEDPAdd, IEEEDPCeil, IEEEDPCmp, IEEEDPDiv, IEEEDPFix, IEEEDPFloor, IEEEDPFlt, IEEEDPMul, IEEEDPNeg, IEEEDPSub, IEEEDPTst, SPAbs, SPAdd, SPCeil, SPCmp, SPDiv, SPFix, SPFloor, SPFlt, SPMul, SPNeg, SPSub, SPTst]
libraries: [mathffp.library, mathieeedoubbas.library]
---

# 35 Math Libraries / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Here's a brief summary of the functions covered in this chapter.  Refer to
the Amiga ROM Kernel Reference Manual: Includes and Autodocs for
additional information.

  _______________________________________________________________________
 |                                                                       |
 |                          FFP Basic Functions                          |
 |=======================================================================|
 |    [SPAbs()](autodocs-2.0/mathffp-library-spabs.md)  Take absolute value of FFP variable                       |
 |    [SPAdd()](autodocs-2.0/mathffp-library-spadd.md)  Add two FFP variables                                     |
 |   [SPCeil()](autodocs-2.0/mathffp-library-spceil.md)  Compute least integer greater than or equal to variable.  |
 |    [SPCmp()](autodocs-2.0/mathffp-library-spcmp.md)  Compare two FFP variables                                 |
 |    [SPDiv()](autodocs-2.0/mathffp-library-spdiv.md)  Divide two FFP variables                                  |
 |    [SPFix()](autodocs-2.0/mathffp-library-spfix.md)  Convert FFP variable to integer                           |
 |  [SPFloor()](autodocs-2.0/mathffp-library-spfloor.md)  Computer largest integer less than or equal to variable.  |
 |    [SPFlt()](autodocs-2.0/mathffp-library-spflt.md)  Convert integer variable to FFP                           |
 |    [SPMul()](autodocs-2.0/mathffp-library-spmul.md)  Multiply two FFP variables                                |
 |    [SPNeg()](autodocs-2.0/mathffp-library-spneg.md)  Take two's complement of FFP variable                     |
 |    [SPSub()](autodocs-2.0/mathffp-library-spsub.md)  Subtract two FFP variables                                |
 |    [SPTst()](autodocs-2.0/mathffp-library-sptst.md)  Test an FFP variable against zero                         |
 |_______________________________________________________________________|

  _______________________________________________________________________
 |                                                                       |
 |                      FFP Transcendental Functions                     |
 |=======================================================================|
 |       [SPAcos()](autodocs-2.0/mathtrans-library-spacos.md)  Return arccosine of FFP variable.                     |
 |       [SPAsin()](autodocs-2.0/mathtrans-library-spasin.md)  Return arcsine of FFP variable.                       |
 |       [SPAtan()](autodocs-2.0/mathtrans-library-spatan.md)  Return arctangent of FFP variable.                    |
 |        [SPCos()](autodocs-2.0/mathtrans-library-spcos.md)  Return cosine of FFP variable.                        |
 |       [SPCosh()](autodocs-2.0/mathtrans-library-spcosh.md)  Return hyperbolic cosine of FFP variable.             |
 |        [SPExp()](autodocs-2.0/mathtrans-library-spexp.md)  Return e to the FFP variable power.                   |
 |      [SPFieee()](autodocs-2.0/mathtrans-library-spfieee.md)  Convert IEEE variable to FFP format.                  |
 |        [SPLog()](autodocs-2.0/mathtrans-library-splog.md)  Return natural log (base e) of FFP variable.          |
 |      [SPLog10()](autodocs-2.0/mathtrans-library-splog10.md)  Return log (base 10) of FFP variable.                 |
 |        [SPPow()](autodocs-2.0/mathtrans-library-sppow.md)  Return FFP arg2 to FFP arg1.                          |
 |        [SPSin()](autodocs-2.0/mathtrans-library-spsin.md)  Return sine of FFP variable.                          |
 |     [SPSincos()](autodocs-2.0/mathtrans-library-spsincos.md)  Return sine and cosine of FFP variable.               |
 |       [SPSinh()](autodocs-2.0/mathtrans-library-spsinh.md)  Return hyperbolic sine of FFP variable.               |
 |       [SPSqrt()](autodocs-2.0/mathtrans-library-spsqrt.md)  Return square root of FFP variable.                   |
 |        [SPTan()](autodocs-2.0/mathtrans-library-sptan.md)  Return tangent of FFP variable.                       |
 |       [SPTanh()](autodocs-2.0/mathtrans-library-sptanh.md)  Return hyperbolic tangent of FFP variable.            |
 |      [SPTieee()](autodocs-2.0/mathtrans-library-sptieee.md)  Convert FFP variable to IEEE format                   |
 |_______________________________________________________________________|

  _______________________________________________________________________
 |                                                                       |
 |                        Math Support Functions                         |
 |=======================================================================|
 |      [afp()](autodocs-2.0/amiga-lib-afp.md)  Convert ASCII string into FFP equivalent.                 |
 |      [fpa()](autodocs-2.0/amiga-lib-fpa.md)  Convert FFP variable into ASCII equivalent.               |
 |     [arnd()](autodocs-2.0/amiga-lib-arnd.md)  Round ASCII representation of FFP number.                 |
 |      [dbf()](autodocs-2.0/amiga-lib-dbf.md)  Convert FFP dual-binary number to FFP equivalent.         |
 |_______________________________________________________________________|

  _______________________________________________________________________
 |                                                                       |
 |                    SP IEEE Basic Functions (V36)                      |
 |=======================================================================|
 |   [IEEESPAbs()](autodocs-2.0/mathieeesingbas-library-ieeespabs.md)  Take absolute value of IEEE single-precision variable. |
 |   [IEEESPAdd()](autodocs-2.0/mathieeesingbas-library-ieeespadd.md)  Add two IEEE single-precision variables.               |
 |  [IEEESPCeil()](autodocs-2.0/mathieeesingbas-library-ieeespceil.md)  Compute least integer greater than or equal to         |
 |                variable.                                              |
 |   [IEEESPCmp()](autodocs-2.0/mathieeesingbas-library-ieeespcmp.md)  Compare two IEEE single-precision variables.           |
 |   [IEEESPDiv()](autodocs-2.0/mathieeesingbas-library-ieeespdiv.md)  Divide two IEEE single-precision variables.            |
 |   [IEEESPFix()](autodocs-2.0/mathieeesingbas-library-ieeespfix.md)  Convert IEEE single-precision  variable to integer.    |
 | [IEEESPFloor()](autodocs-2.0/mathieeesingbas-library-ieeespfloor.md)  Compute largest integer less than or equal to          |
 |                variable.                                              |
 |   [IEEESPFlt()](autodocs-2.0/mathieeesingbas-library-ieeespflt.md)  Convert integer variable to IEEE single-precision.     |
 |   [IEEESPMul()](autodocs-2.0/mathieeesingbas-library-ieeespmul.md)  Multiply two IEEE single-precision variables.          |
 |   [IEEESPNeg()](autodocs-2.0/mathieeesingbas-library-ieeespneg.md)  Take two's complement of IEEE single-precision         |
 |                variable.                                              |
 |   [IEEESPSub()](autodocs-2.0/mathieeesingbas-library-ieeespsub.md)  Subtract two IEEE single-precision variables.          |
 |   [IEEESPTst()](autodocs-2.0/mathieeesingbas-library-ieeesptst.md)  Test an IEEE single-precision variable against zero.   |
 |_______________________________________________________________________|

  _______________________________________________________________________
 |                                                                       |
 |                SP IEEE Transcendental Functions (V36)                 |
 |=======================================================================|
 |   [IEEESPACos()](autodocs-2.0/mathieeesingtrans-library-ieeespacos.md)  Return arccosine of IEEE single-precision variable.   |
 |   [IEEESPASin()](autodocs-2.0/mathieeesingtrans-library-ieeespasin.md)  Return arcsine of IEEE single-precision variable.     |
 |   [IEEESPAtan()](autodocs-2.0/mathieeesingtrans-library-ieeespatan.md)  Return arctangent of IEEE single-precision variable.  |
 |    [IEEESPCos()](autodocs-2.0/mathieeesingtrans-library-ieeespcos.md)  Return cosine of IEEE single-precision variable.      |
 |   [IEEESPCosh()](autodocs-2.0/mathieeesingtrans-library-ieeespcosh.md)  Return hyperbolic cosine of IEEE single-precision     |
 |                 variable.                                             |
 |    [IEEESPExp()](autodocs-2.0/mathieeesingtrans-library-ieeespexp.md)  Return e to the IEEE variable power.                  |
 |    [IEEESPLog()](autodocs-2.0/mathieeesingtrans-library-ieeesplog.md)  Return natural log (base e of IEEE single-precision   |
 |                 variable.                                             |
 |  [IEEESPLog10()](autodocs-2.0/mathieeesingtrans-library-ieeesplog10.md)  Return log (base 10) of IEEE single-precision         |
 |                 variable.                                             |
 |    [IEEESPPow()](autodocs-2.0/mathieeesingtrans-library-ieeesppow.md)  Return power of IEEE single-precision variable.       |
 |    [IEEESPSin()](autodocs-2.0/mathieeesingtrans-library-ieeespsin.md)  Return sine of IEEE single-precision variable.        |
 | [IEEESPSincos()](autodocs-2.0/mathieeesingtrans-library-ieeespsincos.md)  Return sine and cosine of IEEE single-precision       |
 |                 variable.                                             |
 |   [IEEESPSinh()](autodocs-2.0/mathieeesingtrans-library-ieeespsinh.md)  Return hyperbolic sine of IEEE single-precision       |
 |                variable.                                              |
 |   [IEEESPSqrt()](autodocs-2.0/mathieeesingtrans-library-ieeespsqrt.md)  Return square root of IEEE single-precision variable. |
 |    [IEEESPTan()](autodocs-2.0/mathieeesingtrans-library-ieeesptan.md)  Return tangent of IEEE single-precision variable.     |
 |   [IEEESPTanh()](autodocs-2.0/mathieeesingtrans-library-ieeesptanh.md)  Return hyperbolic tangent of IEEE single-precision    |
 |                 variable.                                             |
 |_______________________________________________________________________|

  _______________________________________________________________________
 |                                                                       |
 |                       DP IEEE Basic Functions                         |
 |=======================================================================|
 |   [IEEEDPAbs()](autodocs-2.0/mathieeedoubbas-library-ieeedpabs.md)  Take absolute value of IEEE double-precision variable. |
 |   [IEEEDPAdd()](autodocs-2.0/mathieeedoubbas-library-ieeedpadd.md)  Add two IEEE double-precision variables.               |
 |  [IEEEDPCeil()](autodocs-2.0/mathieeedoubbas-library-ieeedpceil.md)  Compute least integer greater than or equal to         |
 |                variable.                                              |
 |   [IEEEDPCmp()](autodocs-2.0/mathieeedoubbas-library-ieeedpcmp.md)  Compare two IEEE double-precision variables.           |
 |   [IEEEDPDiv()](autodocs-2.0/mathieeedoubbas-library-ieeedpdiv.md)  Divide two IEEE double-precision variables.            |
 |   [IEEEDPFix()](autodocs-2.0/mathieeedoubbas-library-ieeedpfix.md)  Convert IEEE double-precision  variable to integer.    |
 | [IEEEDPFloor()](autodocs-2.0/mathieeedoubbas-library-ieeedpfloor.md)  Compute largest integer less than or equal to          |
 |                variable.                                              |
 |   [IEEEDPFlt()](autodocs-2.0/mathieeedoubbas-library-ieeedpflt.md)  Convert integer variable to IEEE double-precision.     |
 |   [IEEEDPMul()](autodocs-2.0/mathieeedoubbas-library-ieeedpmul.md)  Multiply two IEEE double-precision variables.          |
 |   [IEEEDPNeg()](autodocs-2.0/mathieeedoubbas-library-ieeedpneg.md)  Take two's complement of IEEE double-precision         |
 |                variable.                                              |
 |   [IEEEDPSub()](autodocs-2.0/mathieeedoubbas-library-ieeedpsub.md)  Subtract two IEEE single-precision variables.          |
 |   [IEEEDPTst()](autodocs-2.0/mathieeedoubbas-library-ieeedptst.md)  Test an IEEE double-precision variable against zero.   |
 |_______________________________________________________________________|

  _______________________________________________________________________
 |                                                                       |
 |                   DP IEEE Transcendental Functions                    |
 |=======================================================================|
 |   [IEEEDPACos()](autodocs-2.0/mathieeedoubtrans-library-ieeedpacos.md)  Return arccosine of IEEE double-precision variable.   |
 |   [IEEEDPASin()](autodocs-2.0/mathieeedoubtrans-library-ieeedpasin.md)  Return arcsine of IEEE double-precision variable.     |
 |   [IEEEDPAtan()](autodocs-2.0/mathieeedoubtrans-library-ieeedpatan.md)  Return arctangent of IEEE double-precision variable.  |
 |    [IEEEDPCos()](autodocs-2.0/mathieeedoubtrans-library-ieeedpcos.md)  Return cosine of IEEE double-precision variable.      |
 |   [IEEEDPCosh()](autodocs-2.0/mathieeedoubtrans-library-ieeedpcosh.md)  Return hyperbolic cosine of IEEE double-precision     |
 |                 variable.                                             |
 |    [IEEEDPExp()](autodocs-2.0/mathieeedoubtrans-library-ieeedpexp.md)  Return e to the IEEE variable power.                  |
 |  [IEEEDPFieee()](autodocs-2.0/mathieeedoubtrans-library-ieeedpfieee.md)  Convert IEEE single-precision number to IEEE          |
 |                 double-precision number.                              |
 |    [IEEEDPLog()](autodocs-2.0/mathieeedoubtrans-library-ieeedplog.md)  Return natural log (base e of IEEE double-precision   |
 |                 variable.                                             |
 |  [IEEEDPLog10()](autodocs-2.0/mathieeedoubtrans-library-ieeedplog10.md)  Return log (base 10) of IEEE double-precision         |
 |                 variable.                                             |
 |    [IEEEDPPow()](autodocs-2.0/mathieeedoubtrans-library-ieeedppow.md)  Return power of IEEE double-precision variable.       |
 |    [IEEEDPSin()](autodocs-2.0/mathieeedoubtrans-library-ieeedpsin.md)  Return sine of IEEE double-precision variable.        |
 | [IEEEDPSincos()](autodocs-2.0/mathieeedoubtrans-library-ieeedpsincos.md)  Return sine and cosine of IEEE double-precision       |
 |                 variable.                                             |
 |   [IEEEDPSinh()](autodocs-2.0/mathieeedoubtrans-library-ieeedpsinh.md)  Return hyperbolic sine of IEEE double-precision       |
 |                 variable.                                             |
 |   [IEEEDPSqrt()](autodocs-2.0/mathieeedoubtrans-library-ieeedpsqrt.md)  Return square root of IEEE double-precision variable. |
 |    [IEEEDPTan()](autodocs-2.0/mathieeedoubtrans-library-ieeedptan.md)  Return tangent of IEEE double-precision variable.     |
 |   [IEEEDPTanh()](autodocs-2.0/mathieeedoubtrans-library-ieeedptanh.md)  Return hyperbolic tangent of IEEE double-precision    |
 |                 variable.                                             |
 |  [IEEEDPTieee()](autodocs-2.0/mathieeedoubtrans-library-ieeedptieee.md)  Convert IEEE double-precision number to IEEE          |
 |                 single-precision number.                              |
 |_______________________________________________________________________|

---

## See Also

- [IEEEDPAbs — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpabs)
- [IEEEDPAdd — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpadd)
- [IEEEDPCeil — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpceil)
- [IEEEDPCmp — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpcmp)
- [IEEEDPDiv — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpdiv)
- [IEEEDPFix — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpfix)
- [IEEEDPFloor — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpfloor)
- [IEEEDPFlt — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpflt)
- [IEEEDPMul — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpmul)
- [IEEEDPNeg — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpneg)
- [IEEEDPSub — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpsub)
- [IEEEDPTst — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedptst)
- [SPAbs — mathffp.library](../autodocs/mathffp.library.md#spabs)
- [SPAdd — mathffp.library](../autodocs/mathffp.library.md#spadd)
- [SPCeil — mathffp.library](../autodocs/mathffp.library.md#spceil)
- [SPCmp — mathffp.library](../autodocs/mathffp.library.md#spcmp)
- [SPDiv — mathffp.library](../autodocs/mathffp.library.md#spdiv)
- [SPFix — mathffp.library](../autodocs/mathffp.library.md#spfix)
- [SPFloor — mathffp.library](../autodocs/mathffp.library.md#spfloor)
- [SPFlt — mathffp.library](../autodocs/mathffp.library.md#spflt)
- [SPMul — mathffp.library](../autodocs/mathffp.library.md#spmul)
- [SPNeg — mathffp.library](../autodocs/mathffp.library.md#spneg)
- [SPSub — mathffp.library](../autodocs/mathffp.library.md#spsub)
- [SPTst — mathffp.library](../autodocs/mathffp.library.md#sptst)
