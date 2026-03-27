---
title: 35 / / DP IEEE Transcendental Functions
manual: libraries
chapter: libraries
section: 35-dp-ieee-transcendental-functions
functions: []
libraries: []
---

# 35 / / DP IEEE Transcendental Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[IEEEDPAsin()](autodocs-2.0/mathieeedoubtrans-library-ieeedpasin.md)   DOUBLE IEEEDPAsin( DOUBLE parm );

    Return arcsine of IEEE variable.
[IEEEDPAcos()](autodocs-2.0/mathieeedoubtrans-library-ieeedpacos.md)   DOUBLE IEEEDPAcos( DOUBLE parm );

    Return arccosine of IEEE variable.
[IEEEDPAtan()](autodocs-2.0/mathieeedoubtrans-library-ieeedpatan.md)   DOUBLE IEEEDPAtan( DOUBLE parm );

    Return arctangent of IEEE variable.
[IEEEDPSin()](autodocs-2.0/mathieeedoubtrans-library-ieeedpsin.md)    DOUBLE IEEEDPSin( DOUBLE parm );

    Return sine of IEEE variable.  This function accepts an IEEE radian
    argument and returns the trigonometric sine value.
[IEEEDPCos()](autodocs-2.0/mathieeedoubtrans-library-ieeedpcos.md)    DOUBLE IEEEDPCos( DOUBLE parm );

    Return cosine of IEEE variable.  This function accepts an IEEE radian
    argument and returns the trigonometric cosine value.
[IEEEDPTan()](autodocs-2.0/mathieeedoubtrans-library-ieeedptan.md)    DOUBLE IEEEDPTan( DOUBLE parm );

    Return tangent of IEEE variable.  This function accepts an IEEE
    radian argument and returns the trigonometric tangent value.
[IEEEDPSincos()](autodocs-2.0/mathieeedoubtrans-library-ieeedpsincos.md) DOUBLE IEEEDPSincos( DOUBLE *pf2, DOUBLE parm );

    Return sine and cosine of IEEE variable.  This function accepts an
    IEEE radian argument and returns the trigonometric sine as its result
    and the trigonometric cosine in the first parameter.
[IEEEDPSinh()](autodocs-2.0/mathieeedoubtrans-library-ieeedpsinh.md)   DOUBLE IEEEDPSinh( DOUBLE parm );

    Return hyperbolic sine of IEEE variable.
[IEEEDPCosh()](autodocs-2.0/mathieeedoubtrans-library-ieeedpcosh.md)   DOUBLE IEEEDPCosh( DOUBLE parm );

    Return hyperbolic cosine of IEEE variable.
[IEEEDPTanh()](autodocs-2.0/mathieeedoubtrans-library-ieeedptanh.md)   DOUBLE IEEEDPTanh( DOUBLE parm );

    Return hyperbolic tangent of IEEE variable.
[IEEEDPExp()](autodocs-2.0/mathieeedoubtrans-library-ieeedpexp.md)    DOUBLE IEEEDPExp( DOUBLE parm );

```c
    Return e to the IEEE variable power.  This function accept an IEEE
    argument and returns the result representing the value of e
    (2.712828...) raised to that power.
```
[IEEEDPFieee()](autodocs-2.0/mathieeedoubtrans-library-ieeedpfieee.md)  DOUBLE IEEEDPFieee( FLOAT single );

    Convert IEEE single-precision number to IEEE double-precision number.
[IEEEDPLog()](autodocs-2.0/mathieeedoubtrans-library-ieeedplog.md)    DOUBLE IEEEDPLog( DOUBLE parm );

```c
    Return natural log (base e of IEEE variable.
```
[IEEEDPLog10()](autodocs-2.0/mathieeedoubtrans-library-ieeedplog10.md)  DOUBLE IEEEDPLog10( DOUBLE parm );

```c
    Return log (base 10) of IEEE variable.
```
[IEEEDPPow()](autodocs-2.0/mathieeedoubtrans-library-ieeedppow.md)    DOUBLE IEEEDPPow( DOUBLE exp, DOUBLE arg );

    Return IEEE arg2 to IEEE arg1.
[IEEEDPSqrt()](autodocs-2.0/mathieeedoubtrans-library-ieeedpsqrt.md)   DOUBLE IEEEDPSqrt( DOUBLE parm );

    Return square root of IEEE variable.
[IEEEDPTieee()](autodocs-2.0/mathieeedoubtrans-library-ieeedptieee.md)  FLOAT IEEEDPTieee( DOUBLE parm );

    Convert IEEE double-precision number to IEEE single-precision number.
Be sure to include proper data type definitions as shown below.


```c
     [mathieeedoubtrans.c](libraries/lib-examples-mathieeedoubtrans-c.md) 
```
The section below describes the Amiga assembly interface to the IEEE
double-precision transcendental math library.  The access mechanism from
assembly language is:


```c
        MOVEA.L _MathIeeeDoubTransBase,A6
        JSR     _LVOIEEEDPAsin(A6)
```
  _______________________________________________________________________
 |                                                                       |
 |             DP IEEE Transcendental Assembly Functions                 |
 |                                                                       |
 | Function           Input            Output            Condition Codes |
 |_______________________________________________________________________|
 |                  |                |                     |             |
 | _LVOIEEEDPAsin   | D0/D1=IEEE arg | D0/D1=IEEE          | N=undefined |
 |                  |                | arcsine radian      | Z=undefined |
 |                  |                |                     | V=undefined |
 |                  |                |                     | C=undefined |
 |                  |                |                     | X=undefined |
 |------------------|----------------|---------------------|-------------|
 | _LVOIEEEDPAcos   | D0/D1=IEEE arg | D0/D1=IEEE          | N=undefined |
 |                  |                | arccosine radian    | Z=undefined |
 |                  |                |                     | V=undefined |
 |                  |                |                     | C=undefined |
 |                  |                |                     | X=undefined |
 |------------------|----------------|---------------------|-------------|
 | _LVOIEEEDPAtan   | D0/D1=IEEE arg | D0/D1=IEEE          | N=undefined |
 |                  |                | arctangent radian   | Z=undefined |
 |                  |                |                     | V=undefined |
 |                  |                |                     | C=undefined |
 |                  |                |                     | X=undefined |
 |------------------|----------------|---------------------|-------------|
 | _LVOIEEEDPSin    | D0/D1=IEEE arg | D0/D1=IEEE sine     | N=undefined |
 |                  |   in radians   |                     | Z=undefined |
 |                  |                |                     | V=undefined |
 |                  |                |                     | C=undefined |
 |                  |                |                     | X=undefined |
 |------------------|----------------|---------------------|-------------|
 | _LVOIEEEDPCos    | D0/D1=IEEE arg | D0/D1=IEEE cosine   | N=undefined |
 |                  |   in radians   |                     | Z=undefined |
 |                  |                |                     | V=undefined |
 |                  |                |                     | C=undefined |
 |                  |                |                     | X=undefined |
 |------------------|----------------|---------------------|-------------|
 | _LVOIEEEDPTan    | D0/D1=IEEE arg | D0/D1=IEEE tangent  | N=undefined |
 |                  |   in radians   |                     | Z=undefined |
 |                  |                |                     | V=undefined |
 |                  |                |                     | C=undefined |
 |                  |                |                     | X=undefined |
 |------------------|----------------|---------------------|-------------|
 | _LVOIEEEDPSincos | A0=Address to  | D0/D1=IEEE sine     | N=undefined |
 |                  |   store cosine | (A0)=IEEE cosine    | Z=undefined |
 |                  |   result       |                     | V=undefined |
 |                  | D0/D1=IEEE arg |                     | C=undefined |
 |                  |   in radians   |                     | X=undefined |
 |------------------|----------------|---------------------|-------------|
 | _LVOIEEEDPSin    | D0/D1=IEEE arg | D0/D1=IEEE          | N=undefined |
 |                  |   in radians   | hyperbolic sine     | Z=undefined |
 |                  |                |                     | V=undefined |
 |                  |                |                     | C=undefined |
 |                  |                |                     | X=undefined |
 |------------------|----------------|---------------------|-------------|
 | _LVOIEEEDPCosh   | D0/D1=IEEE arg | D0/D1=IEEE          | N=undefined |
 |                  |   in radians   | hyperbolic cosine   | Z=undefined |
 |                  |                |                     | V=undefined |
 |                  |                |                     | C=undefined |
 |                  |                |                     | X=undefined |
 |------------------|----------------|---------------------|-------------|
 | _LVOIEEEDPTanh   | D0/D1=IEEE arg | D0/D1=IEEE          | N=undefined |
 |                  |   in radians   | hyperbolic tangent  | Z=undefined |
 |                  |                |                     | V=undefined |
 |                  |                |                     | C=undefined |
 |                  |                |                     | X=undefined |
 |------------------|----------------|---------------------|-------------|
 | _LVOIEEEDPExp    | D0/D1=IEEE arg | D0/D1=IEEE          | N=undefined |
 |                  |                | exponential         | Z=undefined |
 |                  |                |                     | V=undefined |
 |                  |                |                     | C=undefined |
 |                  |                |                     | X=undefined |
 |------------------|----------------|---------------------|-------------|
 | _LVOIEEEDPLog    | D0/D1=IEEE arg | D0/D1=IEEE natural  | N=undefined |
 |                  |                |  logarithm          | Z=undefined |
 |                  |                |                     | V=undefined |
 |                  |                |                     | C=undefined |
 |                  |                |                     | X=undefined |
 |------------------|----------------|---------------------|-------------|
 | _LVOIEEEDPLog10  | D0/D1=IEEE arg | D0/D1=IEEE          | N=undefined |
 |                  |                | logarithm           | Z=undefined |
 |                  |                | (base 10)           | V=undefined |
 |                  |                |                     | C=undefined |
 |                  |                |                     | X=undefined |
 |------------------|----------------|---------------------|-------------|
 | _LVOIEEEDPPow    | D0/D1=IEEE exp | D0/D1=IEEE          | N=undefined |
 |                  | D2/D3=IEEE arg | of arg taken to     | Z=undefined |
 |                  |                | exp power           | V=undefined |
 |                  |                |                     | C=undefined |
 |                  |                |                     | X=undefined |
 |------------------|----------------|---------------------|-------------|
 | _LVOIEEEDPSqrt   | D0/D1=IEEE arg | D0/D1=IEEE          | N=undefined |
 |                  |                | square root         | Z=undefined |
 |                  |                |                     | V=undefined |
 |                  |                |                     | C=undefined |
 |                  |                |                     | X=undefined |
 |------------------|----------------|---------------------|-------------|
 | _LVOIEEEDPTieee  | D0/D1=IEEE arg | D0=single-precision | N=undefined |
 |                  |                | IEEE floating-point | Z=undefined |
 |                  |                | format              | V=undefined |
 |                  |                |                     | C=undefined |
 |                  |                |                     | X=undefined |
 |__________________|________________|_____________________|_____________|

