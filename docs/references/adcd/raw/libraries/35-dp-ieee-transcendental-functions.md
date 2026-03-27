# 35 / / DP IEEE Transcendental Functions


[IEEEDPAsin()](../Includes_and_Autodocs_2._guide/node0494.html)   DOUBLE IEEEDPAsin( DOUBLE parm );

    Return arcsine of IEEE variable.
[IEEEDPAcos()](../Includes_and_Autodocs_2._guide/node0493.html)   DOUBLE IEEEDPAcos( DOUBLE parm );

    Return arccosine of IEEE variable.
[IEEEDPAtan()](../Includes_and_Autodocs_2._guide/node0495.html)   DOUBLE IEEEDPAtan( DOUBLE parm );

    Return arctangent of IEEE variable.
[IEEEDPSin()](../Includes_and_Autodocs_2._guide/node049D.html)    DOUBLE IEEEDPSin( DOUBLE parm );

    Return sine of IEEE variable.  This function accepts an IEEE radian
    argument and returns the trigonometric sine value.
[IEEEDPCos()](../Includes_and_Autodocs_2._guide/node0496.html)    DOUBLE IEEEDPCos( DOUBLE parm );

    Return cosine of IEEE variable.  This function accepts an IEEE radian
    argument and returns the trigonometric cosine value.
[IEEEDPTan()](../Includes_and_Autodocs_2._guide/node04A1.html)    DOUBLE IEEEDPTan( DOUBLE parm );

    Return tangent of IEEE variable.  This function accepts an IEEE
    radian argument and returns the trigonometric tangent value.
[IEEEDPSincos()](../Includes_and_Autodocs_2._guide/node049E.html) DOUBLE IEEEDPSincos( DOUBLE *pf2, DOUBLE parm );

    Return sine and cosine of IEEE variable.  This function accepts an
    IEEE radian argument and returns the trigonometric sine as its result
    and the trigonometric cosine in the first parameter.
[IEEEDPSinh()](../Includes_and_Autodocs_2._guide/node049F.html)   DOUBLE IEEEDPSinh( DOUBLE parm );

    Return hyperbolic sine of IEEE variable.
[IEEEDPCosh()](../Includes_and_Autodocs_2._guide/node0497.html)   DOUBLE IEEEDPCosh( DOUBLE parm );

    Return hyperbolic cosine of IEEE variable.
[IEEEDPTanh()](../Includes_and_Autodocs_2._guide/node04A2.html)   DOUBLE IEEEDPTanh( DOUBLE parm );

    Return hyperbolic tangent of IEEE variable.
[IEEEDPExp()](../Includes_and_Autodocs_2._guide/node0498.html)    DOUBLE IEEEDPExp( DOUBLE parm );

```c
    Return e to the IEEE variable power.  This function accept an IEEE
    argument and returns the result representing the value of e
    (2.712828...) raised to that power.
```
[IEEEDPFieee()](../Includes_and_Autodocs_2._guide/node0499.html)  DOUBLE IEEEDPFieee( FLOAT single );

    Convert IEEE single-precision number to IEEE double-precision number.
[IEEEDPLog()](../Includes_and_Autodocs_2._guide/node049A.html)    DOUBLE IEEEDPLog( DOUBLE parm );

```c
    Return natural log (base e of IEEE variable.
```
[IEEEDPLog10()](../Includes_and_Autodocs_2._guide/node049B.html)  DOUBLE IEEEDPLog10( DOUBLE parm );

```c
    Return log (base 10) of IEEE variable.
```
[IEEEDPPow()](../Includes_and_Autodocs_2._guide/node049C.html)    DOUBLE IEEEDPPow( DOUBLE exp, DOUBLE arg );

    Return IEEE arg2 to IEEE arg1.
[IEEEDPSqrt()](../Includes_and_Autodocs_2._guide/node04A0.html)   DOUBLE IEEEDPSqrt( DOUBLE parm );

    Return square root of IEEE variable.
[IEEEDPTieee()](../Includes_and_Autodocs_2._guide/node04A3.html)  FLOAT IEEEDPTieee( DOUBLE parm );

    Convert IEEE double-precision number to IEEE single-precision number.
Be sure to include proper data type definitions as shown below.


```c
     [mathieeedoubtrans.c](../Libraries_Manual_guide/node0602.html) 
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

