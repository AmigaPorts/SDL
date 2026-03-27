# 35 / / SP IEEE Transcendental Functions (V36 Or Greater)


[IEEESPAsin()](../Includes_and_Autodocs_2._guide/node01E2.html)   FLOAT IEEESPAsin( FLOAT parm );

    Return arcsine of IEEE single-precision variable.
[IEEESPAcos()](../Includes_and_Autodocs_2._guide/node01E1.html)   FLOAT IEEESPAcos( FLOAT parm );

    Return arccosine of IEEE single-precision variable.
[IEEESPAtan()](../Includes_and_Autodocs_2._guide/node01E3.html)   FLOAT IEEESPAtan( FLOAT parm );

    Return arctangent of IEEE single-precision variable.
[IEEESPSin()](../Includes_and_Autodocs_2._guide/node01EB.html)    FLOAT IEEESPSin( FLOAT parm );

    Return sine of IEEE single-precision variable.  This function accepts
    an IEEE radian argument and returns the trigonometric sine value.
[IEEESPCos()](../Includes_and_Autodocs_2._guide/node01E4.html)    FLOAT IEEESPCos( FLOAT parm );

    Return cosine of IEEE single-precision variable.  This function
    accepts an IEEE radian argument and returns the trigonometric cosine
    value.
[IEEESPTan()](../Includes_and_Autodocs_2._guide/node01EF.html)    FLOAT IEEESPTan( FLOAT parm );

    Return tangent of IEEE single-precision variable.  This function
    accepts an IEEE radian argument and returns the trigonometric tangent
    value.
[IEEESPSincos()](../Includes_and_Autodocs_2._guide/node01EC.html) FLOAT IEEESPSincos( FLOAT *cosptr, FLOAT parm );

    Return sine and cosine of IEEE single-precision variable.  This
    function accepts an IEEE radian argument and returns the
    trigonometric sine as its result and the cosine in the first
    parameter.
[IEEESPSinh()](../Includes_and_Autodocs_2._guide/node01ED.html)   FLOAT IEEESPSinh( FLOAT parm );

    Return hyperbolic sine of IEEE single-precision variable.
[IEEESPCosh()](../Includes_and_Autodocs_2._guide/node01E5.html)   FLOAT IEEESPCosh( FLOAT parm );

    Return hyperbolic cosine of IEEE single-precision variable.
[IEEESPTanh()](../Includes_and_Autodocs_2._guide/node01F0.html)   FLOAT IEEESPTanh( FLOAT parm );

    Return hyperbolic tangent of IEEE single-precision variable.
[IEEESPExp()](../Includes_and_Autodocs_2._guide/node01E6.html)    FLOAT IEEESPExp( FLOAT parm );

```c
    Return e to the IEEE variable power.  This function accept an IEEE
    single-precision argument and returns the result representing the
    value of e (2.712828...) raised to that power.
```
[IEEESPFieee()](../Includes_and_Autodocs_2._guide/node01E7.html)  FLOAT IEEESPFieee( FLOAT parm );

    Convert IEEE single-precision number to IEEE single-precision number.
    The only purpose of this function is to provide consistency with the
    double-precision math IEEE library.
[IEEESPLog()](../Includes_and_Autodocs_2._guide/node01E8.html)    FLOAT IEEESPLog( FLOAT parm );

```c
    Return natural log (base e of IEEE single-precision variable.
```
[IEEESPLog10()](../Includes_and_Autodocs_2._guide/node01E9.html)  FLOAT IEEESPLog10( FLOAT parm );

```c
    Return log (base 10) of IEEE single-precision variable.
```
[IEEESPPow()](../Includes_and_Autodocs_2._guide/node01EA.html)    FLOAT IEEESPPow( FLOAT exp, FLOAT arg );

    Return IEEE single-precision arg2 to IEEE single-precision arg1.
[IEEESPSqrt()](../Includes_and_Autodocs_2._guide/node01EE.html)   FLOAT IEEESPSqrt( FLOAT parm );

    Return square root of IEEE single-precision variable.
[IEEESPTieee()](../Includes_and_Autodocs_2._guide/node01F1.html)  FLOAT IEEESPTieee( FLOAT parm );

    Convert IEEE single-precision number to IEEE single-precision number.
    The only purpose of this function is to provide consistency with the
    double-precision math IEEE library.
Be sure to include the proper data type definitions as shown below.


```c
     [mathieeesingtrans.c](../Libraries_Manual_guide/node0600.html) 
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

