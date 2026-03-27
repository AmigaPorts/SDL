---
title: 35 / Transcendental Mathematics Library / FFP Transcendental Functions
manual: libraries
chapter: libraries
section: 35-transcendental-mathematics-library-ffp-transcendental
functions: []
libraries: []
---

# 35 / Transcendental Mathematics Library / FFP Transcendental Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[SPAsin()](autodocs-2.0/mathtrans-library-spasin.md)   FLOAT SPAsin( FLOAT parm );

    Return arccosine of FFP variable.
[SPAcos()](autodocs-2.0/mathtrans-library-spacos.md)   FLOAT SPAcos( FLOAT parm );

    Return arctangent of FFP variable.
[SPAtan()](autodocs-2.0/mathtrans-library-spatan.md)   FLOAT SPAtan( FLOAT parm );

    Return arcsine of FFP variable.
[SPSin()](autodocs-2.0/mathtrans-library-spsin.md)    FLOAT SPSin( FLOAT parm );

    Return sine of FFP variable. This function accepts an FFP radian
    argument and returns the trigonometric sine value.  For extremely
    large arguments where little or no precision would result, the
    computation is aborted and the "V" condition code is set.  A direct
    return to the caller is made.
[SPCos()](autodocs-2.0/mathtrans-library-spcos.md)    FLOAT SPCos( FLOAT parm );

    Return cosine of FFP variable.  This function accepts an FFP radian
    argument and returns the trigonometric cosine value.  For extremely
    large arguments where little or no precision would result, the
    computation is aborted and the "V" condition code is set.  A direct
    return to the caller is made.
[SPTan()](autodocs-2.0/mathtrans-library-sptan.md)    FLOAT SPTan( FLOAT parm );

    Return tangent of FFP variable.  This function accepts an FFP radian
    argument and returns the trigonometric tangent value.  For extremely
    large arguments where little or no precision would result, the
    computation is aborted and the "V" condition code is set.  A direct
    return to the caller is made.
[SPSincos()](autodocs-2.0/mathtrans-library-spsincos.md) FLOAT SPSincos( FLOAT *cosResult, FLOAT parm);

```c
    Return sine and cosine of FFP variable.  This function accepts an FFP
    radian argument and returns the trigonometric sine as its result and
    the trigonometric cosine in the first parameter.  If both the sine
    and cosine are required for a single radian value, this function will
    result in almost twice the execution speed of calling the SPSin() and
    SPCos() functions independently.  For extremely large arguments where
    little or no precision would result, the computation is aborted and
    the "V" condition code is set.  A direct return to the caller is made.
```
[SPSinh()](autodocs-2.0/mathtrans-library-spsinh.md)   FLOAT SPSinh( FLOAT parm );

    Return hyperbolic sine of FFP variable.
[SPCosh()](autodocs-2.0/mathtrans-library-spcosh.md)   FLOAT SPCosh( FLOAT parm );

    Return hyperbolic cosine of FFP variable.
[SPTanh()](autodocs-2.0/mathtrans-library-sptanh.md)   FLOAT SPTanh( FLOAT parm );

    Return hyperbolic tangent of FFP variable.
[SPExp()](autodocs-2.0/mathtrans-library-spexp.md)    FLOAT SPExp( FLOAT parm );

```c
    Return e to the FFP variable power.  This function accepts an FFP
    argument and returns the result representing the value of e
    (2.71828...) raised to that power.
```
[SPLog()](autodocs-2.0/mathtrans-library-splog.md)    FLOAT SPLog( FLOAT parm );

```c
    Return natural log (base e) of FFP variable.
```
[SPLog10()](autodocs-2.0/mathtrans-library-splog10.md)  FLOAT SPLog10( FLOAT parm );

```c
    Return log (base 10) of FFP variable.
```
[SPPow()](autodocs-2.0/mathtrans-library-sppow.md) FLOAT SPPow( FLOAT power, FLOAT arg );

    Return FFP arg2 to FFP arg1.
[SPSqrt()](autodocs-2.0/mathtrans-library-spsqrt.md)   FLOAT SPSqrt( FLOAT parm );

    Return square root of FFP variable.
[SPTieee()](autodocs-2.0/mathtrans-library-sptieee.md)  FLOAT SPTieee( FLOAT parm );

    Convert FFP variable to IEEE format
[SPFieee()](autodocs-2.0/mathtrans-library-spfieee.md)  FLOAT SPFieee( FLOAT parm );

    Convert IEEE variable to FFP format.
Be sure to include proper data type definitions, as shown in the example
below.


```c
     [mathtrans.c](libraries/lib-examples-mathtrans-c.md) 
```
The Amiga assembly language interface to the FFP transcendental math
routines is shown below, including some details about how the system flags
are affected by the operation.  This interface resides in the library file
amiga.lib and must be linked with the user code. Note that the access
mechanism from assembly language is:


```c
        MOVEA.L _MathTransBase,A6
        JSR     _LVOSPAsin(A6)
```
  _______________________________________________________________________
 |                                                                       |
 |               FFP Transcendental Assembly Functions                   |
 |                                                                       |
 | Function       Input            Output               Condition Codes  |
 |_______________________________________________________________________|
 |              |                |                    |                  |
 | _LVOSPAsin   | D0=FFP arg     | D0=FFP arcsine     | N=0              |
 |              |                |    radian          | Z=1 if result    |
 |              |                |                    |     is zero      |
 |              |                |                    | V=0              |
 |              |                |                    | C=undefined      |
 |              |                |                    | X=undefined      |
 |--------------|----------------|--------------------|------------------|
 | _LVOSPAcos   | D0=FFP arg     | D0=FFP arccosine   | N=0              |
 |              |                |    radian          | Z=1 if result    |
 |              |                |                    |     is zero      |
 |              |                |                    | V=1 if overflow  |
 |              |                |                    |     occurred     |
 |              |                |                    | C=undefined      |
 |              |                |                    | X=undefined      |
 |--------------|----------------|--------------------|------------------|
 | _LVOSPAtan   | D0=FFP arg     | D0=FFP arctangent  | N=0              |
 |              |                |    radian          | Z=1 if result    |
 |              |                |                    |     is zero      |
 |              |                |                    | V=0              |
 |              |                |                    | C=undefined      |
 |              |                |                    | X=undefined      |
 |--------------|----------------|--------------------|------------------|
 | _LVOSPSin    | D0=FFP arg     | D0=FFP sine        | N=1 if result    |
 |              |    in radians  |                    |     is negative  |
 |              |                |                    | Z=1 if result    |
 |              |                |                    |     is zero      |
 |              |                |                    | V=1 if result    |
 |              |                |                    | is meaningless   |
 |              |                |                    | (input magnitude |
 |              |                |                    |  too large)      |
 |              |                |                    | C=undefined      |
 |              |                |                    | X=undefined      |
 |--------------|----------------|--------------------|------------------|
 | _LVOSPCos    | D0=FFP arg     | D0=FFP cosine      | N=1 if result    |
 |              |    in radians  |                    |     is negative  |
 |              |                |                    | Z=1 if result    |
 |              |                |                    |     is zero      |
 |              |                |                    | V=1 if result    |
 |              |                |                    | is meaningless   |
 |              |                |                    | (input magnitude |
 |              |                |                    |  too large)      |
 |              |                |                    | C=undefined      |
 |              |                |                    | X=undefined      |
 |--------------|----------------|--------------------|------------------|
 | _LVOSPTan    | D0=FFP arg     | D0=FFP tangent     | N=1 if result    |
 |              |    in radians  |                    |     is negative  |
 |              |                |                    | Z=1 if result    |
 |              |                |                    |     is zero      |
 |              |                |                    | V=1 if result    |
 |              |                |                    | is meaningless   |
 |              |                |                    | (input magnitude |
 |              |                |                    |  too large)      |
 |              |                |                    | C=undefined      |
 |              |                |                    | X=undefined      |
 |--------------|----------------|--------------------|------------------|
 | _LVOSPSincos | D0=FFP arg     | D0=FFP sine        | N=1 if result    |
 |              |    in radians  | (D1)=FFP cosine    |     is negative  |
 |              | D1=Address     |                    | Z=1 if result    |
 |              |    to store    |                    |     is zero      |
 |              | cosine result  |                    | V=1 if result    |
 |              |                |                    | is meaningless   |
 |              |                |                    | (input magnitude |
 |              |                |                    |  too large)      |
 |              |                |                    | C=undefined      |
 |              |                |                    | X=undefined      |
 |--------------|----------------|--------------------|------------------|
 | _LVOSPSinh   | D0=FFP arg     | D0=FFP hyperbolic  | N=1 if result    |
 |              |    in radians  |    sine            |     is negative  |
 |              |                |                    | Z=1 if result    |
 |              |                |                    |     is zero      |
 |              |                |                    | V=1 if overflow  |
 |              |                |                    |     occurred     |
 |              |                |                    | C=undefined      |
 |              |                |                    | X=undefined      |
 |--------------|----------------|--------------------|------------------|
 | _LVOSPCosh   | D0=FFP arg     | D0=FFP hyperbolic  | N=1 if result    |
 |              |    in radians  |    cosine          |     is negative  |
 |              |                |                    | Z=1 if result    |
 |              |                |                    |     is zero      |
 |              |                |                    | V=1 if overflow  |
 |              |                |                    |     occurred     |
 |              |                |                    | C=undefined      |
 |              |                |                    | X=undefined      |
 |--------------|----------------|--------------------|------------------|
 | _LVOSPTanh   | D0=FFP arg     | D0=FFP hyperbolic  | N=1 if result    |
 |              |    in radians  |    tangent         |     is negative  |
 |              |                |                    | Z=1 if result    |
 |              |                |                    |     is zero      |
 |              |                |                    | V=1 if overflow  |
 |              |                |                    |     occurred     |
 |              |                |                    | C=undefined      |
 |              |                |                    | X=undefined      |
 |--------------|----------------|--------------------|------------------|
 | _LVOSPExp    | D0=FFP arg     | D0=FFP exponential | N=0              |
 |              |                |                    | Z=1 if result    |
 |              |                |                    |     is zero      |
 |              |                |                    | V=1 if overflow  |
 |              |                |                    |     occurred     |
 |              |                |                    | C=undefined      |
 |              |                |                    | Z=undefined      |
 |--------------|----------------|--------------------|------------------|
 | _LVOSPLog    | D0=FFP arg     | D0=FFP natural     | N=1 if result    |
 |              |                |    logarithm       |     is negative  |
 |              |                |                    | Z=1 if result    |
 |              |                |                    |     is zero      |
 |              |                |                    | V=1 if arg is    |
 |              |                |                    | negative or zero |
 |              |                |                    | C=undefined      |
 |              |                |                    | Z=undefined      |
 |--------------|----------------|--------------------|------------------|
 | _LVOSPLog10  | D0=FFP arg     | D0=FFP logarithm   | N=1 if result    |
 |              |                |    (base 10)       |     is negative  |
 |              |                |                    |Z=1 if result     |
 |              |                |                    |    is zero       |
 |              |                |                    |V=1 if arg is     |
 |              |                |                    | negative or zero |
 |              |                |                    | C=undefined      |
 |              |                |                    | Z=undefined      |
 |--------------|----------------|--------------------|------------------|
 | _LVOSPPow    | D0=FFP         | D0=FFP result of   | N=0              |
 |              | exponent value |    arg taken to    | Z=1 if result    |
 |              | D1=FFP         |    exp power       |     is zero      |
 |              | arg value      |                    | V=1 if result    |
 |              |                |                    |     overflowed   |
 |              |                |                    |     or arg < 0   |
 |              |                |                    | C=undefined      |
 |              |                |                    | Z=undefined      |
 |--------------|----------------|--------------------|------------------|
 | _LVOSPSqrt   | D0=FFP arg     | D0=FFP square root | N=0              |
 |              |                |                    | Z=1 if result    |
 |              |                |                    |     is zero      |
 |              |                |                    | V=1 if arg was   |
 |              |                |                    |     negative     |
 |              |                |                    | C=undefined      |
 |              |                |                    | Z=undefined      |
 |--------------|----------------|--------------------|------------------|
 | _LVOSPTieee  | D0=FFP         | D0=IEEE            | N=1 if result    |
 |              | format arg     |    floating-point  |     is negative  |
 |              |                |    format          | Z=1 if result    |
 |              |                |                    |     is zero      |
 |              |                |                    | V=undefined      |
 |              |                |                    | C=undefined      |
 |              |                |                    | Z=undefined      |
 |--------------|----------------|--------------------|------------------|
 | _LVOSPFieee  | D0=IEEE        | D0=FFP format      | N=undefined      |
 |              | floating-point |                    | Z=1 if result    |
 |              | format arg     |                    |     is zero      |
 |              |                |                    | V=1 if result    |
 |              |                |                    |     overflowed   |
 |              |                |                    | C=undefined      |
 |              |                |                    | Z=undefined      |
 |______________|________________|____________________|__________________|

