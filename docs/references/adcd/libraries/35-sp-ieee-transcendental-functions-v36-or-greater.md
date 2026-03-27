---
title: 35 / / SP IEEE Transcendental Functions (V36 Or Greater)
manual: libraries
chapter: libraries
section: 35-sp-ieee-transcendental-functions-v36-or-greater
functions: []
libraries: []
---

# 35 / / SP IEEE Transcendental Functions (V36 Or Greater)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[IEEESPAsin()](autodocs-2.0/mathieeesingtrans-library-ieeespasin.md)   FLOAT IEEESPAsin( FLOAT parm );

    Return arcsine of IEEE single-precision variable.
[IEEESPAcos()](autodocs-2.0/mathieeesingtrans-library-ieeespacos.md)   FLOAT IEEESPAcos( FLOAT parm );

    Return arccosine of IEEE single-precision variable.
[IEEESPAtan()](autodocs-2.0/mathieeesingtrans-library-ieeespatan.md)   FLOAT IEEESPAtan( FLOAT parm );

    Return arctangent of IEEE single-precision variable.
[IEEESPSin()](autodocs-2.0/mathieeesingtrans-library-ieeespsin.md)    FLOAT IEEESPSin( FLOAT parm );

    Return sine of IEEE single-precision variable.  This function accepts
    an IEEE radian argument and returns the trigonometric sine value.
[IEEESPCos()](autodocs-2.0/mathieeesingtrans-library-ieeespcos.md)    FLOAT IEEESPCos( FLOAT parm );

    Return cosine of IEEE single-precision variable.  This function
    accepts an IEEE radian argument and returns the trigonometric cosine
    value.
[IEEESPTan()](autodocs-2.0/mathieeesingtrans-library-ieeesptan.md)    FLOAT IEEESPTan( FLOAT parm );

    Return tangent of IEEE single-precision variable.  This function
    accepts an IEEE radian argument and returns the trigonometric tangent
    value.
[IEEESPSincos()](autodocs-2.0/mathieeesingtrans-library-ieeespsincos.md) FLOAT IEEESPSincos( FLOAT *cosptr, FLOAT parm );

    Return sine and cosine of IEEE single-precision variable.  This
    function accepts an IEEE radian argument and returns the
    trigonometric sine as its result and the cosine in the first
    parameter.
[IEEESPSinh()](autodocs-2.0/mathieeesingtrans-library-ieeespsinh.md)   FLOAT IEEESPSinh( FLOAT parm );

    Return hyperbolic sine of IEEE single-precision variable.
[IEEESPCosh()](autodocs-2.0/mathieeesingtrans-library-ieeespcosh.md)   FLOAT IEEESPCosh( FLOAT parm );

    Return hyperbolic cosine of IEEE single-precision variable.
[IEEESPTanh()](autodocs-2.0/mathieeesingtrans-library-ieeesptanh.md)   FLOAT IEEESPTanh( FLOAT parm );

    Return hyperbolic tangent of IEEE single-precision variable.
[IEEESPExp()](autodocs-2.0/mathieeesingtrans-library-ieeespexp.md)    FLOAT IEEESPExp( FLOAT parm );

```c
    Return e to the IEEE variable power.  This function accept an IEEE
    single-precision argument and returns the result representing the
    value of e (2.712828...) raised to that power.
```
[IEEESPFieee()](autodocs-2.0/mathieeesingtrans-library-ieeespfieee.md)  FLOAT IEEESPFieee( FLOAT parm );

    Convert IEEE single-precision number to IEEE single-precision number.
    The only purpose of this function is to provide consistency with the
    double-precision math IEEE library.
[IEEESPLog()](autodocs-2.0/mathieeesingtrans-library-ieeesplog.md)    FLOAT IEEESPLog( FLOAT parm );

```c
    Return natural log (base e of IEEE single-precision variable.
```
[IEEESPLog10()](autodocs-2.0/mathieeesingtrans-library-ieeesplog10.md)  FLOAT IEEESPLog10( FLOAT parm );

```c
    Return log (base 10) of IEEE single-precision variable.
```
[IEEESPPow()](autodocs-2.0/mathieeesingtrans-library-ieeesppow.md)    FLOAT IEEESPPow( FLOAT exp, FLOAT arg );

    Return IEEE single-precision arg2 to IEEE single-precision arg1.
[IEEESPSqrt()](autodocs-2.0/mathieeesingtrans-library-ieeespsqrt.md)   FLOAT IEEESPSqrt( FLOAT parm );

    Return square root of IEEE single-precision variable.
[IEEESPTieee()](autodocs-2.0/mathieeesingtrans-library-ieeesptieee.md)  FLOAT IEEESPTieee( FLOAT parm );

    Convert IEEE single-precision number to IEEE single-precision number.
    The only purpose of this function is to provide consistency with the
    double-precision math IEEE library.
Be sure to include the proper data type definitions as shown below.


```c
     [mathieeesingtrans.c](libraries/lib-examples-mathieeesingtrans-c.md) 
```
The section below describes the Amiga assembly interface to the IEEE
single-precision transcendental math library.  The access mechanism from
assembly language is:



```c
        MOVEA.L _MathIeeeSingTransBase,A6
        JSR     _LVOIEEESPAsin(A6)
```
 _________________________________________________________________________
|                                                                         |
|               SP IEEE Transcendental Assembly Functions                 |
|                                                                         |
| Function           Input              Output            Condition Codes |
|_________________________________________________________________________|
|                  |                  |                     |             |
| _LVOIEEESPAsin   | D0=IEEE arg      | D0=IEEE arcsine     | N=undefined |
|                  |                  |    radian           | Z=undefined |
|                  |                  |                     | V=undefined |
|                  |                  |                     | C=undefined |
|                  |                  |                     | X=undefined |
|------------------|------------------|---------------------|-------------|
| _LVOIEEESPAcos   | D0=IEEE arg      | D0=IEEE arccosine   | N=undefined |
|                  | single-precision |    radian           | Z=undefined |
|                  |                  |                     | V=undefined |
|                  |                  |                     | C=undefined |
|                  |                  |                     | X=undefined |
|------------------|------------------|---------------------|-------------|
| _LVOIEEESPAtan   | D0=IEEE arg      | D0=IEEE arctangent  | N=undefined |
|                  | single-precision |    radian           | Z=undefined |
|                  |                  |                     | V=undefined |
|                  |                  |                     | C=undefined |
|                  |                  |                     | X=undefined |
|------------------|------------------|---------------------|-------------|
| _LVOIEEESPSin    | D0=IEEE arg      | D0=IEEE sine        | N=undefined |
|                  |    in radians    |                     | Z=undefined |
|                  | single-precision |                     | V=undefined |
|                  |                  |                     | C=undefined |
|                  |                  |                     | X=undefined |
|------------------|------------------|---------------------|-------------|
| _LVOIEEESPCos    | D0=IEEE arg      | D0=IEEE cosine      | N=undefined |
|                  |    in radians    |                     | Z=undefined |
|                  | single-precision |                     | V=undefined |
|                  |                  |                     | C=undefined |
|                  |                  |                     | X=undefined |
|------------------|------------------|---------------------|-------------|
| _LVOIEEESPTan    | D0=IEEE arg      | D0=IEEE tangent     | N=undefined |
|                  |    in radians    |                     | Z=undefined |
|                  | single-precision |                     | V=undefined |
|                  |                  |                     | C=undefined |
|                  |                  |                     | X=undefined |
|------------------|------------------|---------------------|-------------|
| _LVOIEEESPSincos | A0=Addr to store | D0=IEEE sine        | N=undefined |
|                  |    cosine result | (A0)=IEEE cosine    | Z=undefined |
|                  | D0=IEEE arg      |                     | V=undefined |
|                  |    in radians    |                     | C=undefined |
|                  |                  |                     | X=undefined |
|------------------|------------------|---------------------|-------------|
| _LVOIEEESPSinh   | D0=IEEE arg      | D0=IEEE hyperbolic  | N=undefined |
|                  |    in radians    |    sine             | Z=undefined |
|                  | single-precision |                     | V=undefined |
|                  |                  |                     | C=undefined |
|                  |                  |                     | X=undefined |
|------------------|------------------|---------------------|-------------|
| _LVOIEEESPCosh   | D0=IEEE arg      | D0=IEEE hyperbolic  | N=undefined |
|                  |    in radians    |    cosine           | Z=undefined |
|                  | single-precision |                     | V=undefined |
|                  |                  |                     | C=undefined |
|                  |                  |                     | X=undefined |
|------------------|------------------|---------------------|-------------|
| _LVOIEEESPTanh   | D0=IEEE arg      | D0=IEEE hyperbolic  | N=undefined |
|                  |    in radians    |    tangent          | Z=undefined |
|                  | single-precision |                     | V=undefined |
|                  |                  |                     | C=undefined |
|                  |                  |                     | X=undefined |
|------------------|------------------|---------------------|-------------|
| _LVOIEEESPExp    | D0=IEEE arg      | D0=IEEE exponential | N=undefined |
|                  | single-precision |                     | Z=undefined |
|                  |                  |                     | V=undefined |
|                  |                  |                     | C=undefined |
|                  |                  |                     | X=undefined |
|------------------|------------------|---------------------|-------------|
| _LVOIEEESPLog    | D0=IEEE arg      | D0=IEEE natural     | N=undefined |
|                  | single-precision |    logarithm        | Z=undefined |
|                  |                  |                     | V=undefined |
|                  |                  |                     | C=undefined |
|                  |                  |                     | X=undefined |
|------------------|------------------|---------------------|-------------|
| _LVOIEEESPLog10  | D0=IEEE arg      | D0=IEEE logarithm   | N=undefined |
|                  | single-precision |    (base 10)        | Z=undefined |
|                  |                  |                     | V=undefined |
|                  |                  |                     | C=undefined |
|                  |                  |                     | X=undefined |
|------------------|------------------|---------------------|-------------|
| _LVOIEEESPPow    | D0=IEEE          | D0=IEEE result of   | N=undefined |
|                  |   exponent value |    arg taken to     | Z=undefined |
|                  | single-precision |    exp power        | V=undefined |
|                  | D1=IEEE          |                     | C=undefined |
|                  |    arg value     |                     | X=undefined |
|                  | single-precision |                     |             |
|------------------|------------------|---------------------|-------------|
| _LVOIEEESPSqrt   | D0=IEEE arg      | D0=IEEE square root | N=undefined |
|                  | single-precision |                     | Z=undefined |
|                  |                  |                     | V=undefined |
|                  |                  |                     | C=undefined |
|                  |                  |                     | X=undefined |
|__________________|__________________|_____________________|_____________|

