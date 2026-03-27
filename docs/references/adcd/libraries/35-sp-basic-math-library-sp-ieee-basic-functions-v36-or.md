---
title: 35 / SP Basic Math Library / SP IEEE Basic Functions (V36 or Greater)
manual: libraries
chapter: libraries
section: 35-sp-basic-math-library-sp-ieee-basic-functions-v36-or
functions: []
libraries: []
---

# 35 / SP Basic Math Library / SP IEEE Basic Functions (V36 or Greater)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[IEEESPAbs()](autodocs-2.0/mathieeesingbas-library-ieeespabs.md)    FLOAT ( FLOAT parm );

    Take absolute value of IEEE single-precision variable.
[IEEESPAdd()](autodocs-2.0/mathieeesingbas-library-ieeespadd.md)    FLOAT IEEESPAdd( FLOAT leftParm, FLOAT rightParm);

    Add two IEEE single-precision variables.
[IEEESPCeil()](autodocs-2.0/mathieeesingbas-library-ieeespceil.md)   FLOAT IEEESPCeil( FLOAT parm );

    Compute least integer greater than or equal to variable.
[IEEESPCmp()](autodocs-2.0/mathieeesingbas-library-ieeespcmp.md)    LONG  IEEESPCmp( FLOAT leftParm, FLOAT rightParm );

    Compare two IEEE single-precision variables.
[IEEESPDiv()](autodocs-2.0/mathieeesingbas-library-ieeespdiv.md)    FLOAT IEEESPDiv( FLOAT dividend, FLOAT divisor );

    Divide two IEEE single-precision variables.
[IEEESPFix()](autodocs-2.0/mathieeesingbas-library-ieeespfix.md)    LONG  IEEESPFix( FLOAT parm );

    Convert IEEE single-precision  variable to integer.
[IEEESPFloor()](autodocs-2.0/mathieeesingbas-library-ieeespfloor.md)  FLOAT IEEESPFloor( FLOAT parm );

    Compute largest integer less than or equal to variable.
[IEEESPFlt()](autodocs-2.0/mathieeesingbas-library-ieeespflt.md)    FLOAT IEEESPFlt( long integer );

    Convert integer variable to IEEE single-precision.
[IEEESPMul()](autodocs-2.0/mathieeesingbas-library-ieeespmul.md)    FLOAT IEEESPMul( FLOAT leftParm, FLOAT rightParm );

    Multiply two IEEE single-precision variables.
[IEEESPNeg()](autodocs-2.0/mathieeesingbas-library-ieeespneg.md)    FLOAT IEEESPNeg( FLOAT parm );

    Take two's complement of IEEE single-precision variable.
[IEEESPSub()](autodocs-2.0/mathieeesingbas-library-ieeespsub.md)    FLOAT IEEESPSub( FLOAT leftParm, FLOAT rightParm );

    Subtract two IEEE single-precision variables.
[IEEESPTst()](autodocs-2.0/mathieeesingbas-library-ieeesptst.md)    LONG  IEEESPTst( FLOAT parm );

    Test an IEEE single-precision variable against zero.
Be sure to include proper data type definitions, as shown in the example
below.


```c
     [mathieeesingbas.c](libraries/lib-examples-mathieeesingbas-c.md) 
```
The Amiga assembly language interface to the IEEE single-precision basic
math routines is shown below, including some details about how the system
flags are affected by each operation.  Note that the access mechanism from
assembly language is as shown below:


```c
        MOVEA.L _MathIeeeSingBasBase,A6
        JSR     _LVOIEEESPFix(A6)
```
 _________________________________________________________________________
|                                                                         |
|                    SP IEEE Basic Assembly Functions                     |
|                                                                         |
| Function          Input              Output              Condition Codes|
|_________________________________________________________________________|
|                 |                  |                    |               |
| _LVOIEEESPFix   | D0=IEEE arg      | D0=Integer         | N=undefined   |
|                 | double-precision | (two's complement) | Z=undefined   |
|                 |                  |                    | V=undefined   |
|                 |                  |                    | C=undefined   |
|                 |                  |                    | X=undefined   |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEESPFlt   | D0=Integer arg   | D0=IEEE            | N=undefined   |
|                 |    (two's        | single-precision   | Z=undefined   |
|                 |  complement)     |                    | V=undefined   |
|                 |                  |                    | C=undefined   |
|                 |                  |                    | X=undefined   |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEESPCmp   | D0=IEEE arg1     | D0=+1 if arg1>arg2 | N=1 if result |
|                 | single-precision | D0=-1 if arg1<arg2 | is negative   |
|                 | D1=IEEE arg2     | D0=0 if arg1=arg2  | Z=1 if result |
|                 | single-precision |                    |     is zero   |
|                 |                  |                    | V=0           |
|                 |                  |                    | C=undefined   |
|                 |                  |                    | X=undefined   |
|                 |                  |                    | GT=arg2>arg1  |
|                 |                  |                    | GE=arg2>=arg1 |
|                 |                  |                    | EQ=arg2=arg1  |
|                 |                  |                    | NE=arg2<>arg1 |
|                 |                  |                    | LT=arg2<arg1  |
|                 |                  |                    | E= arg2<=arg1 |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEESPTst   | D0=IEEE arg      | D0=+1 if arg>0.0   | N=1 if result |
|                 | single-precision | D0=-1 if arg<0.0   |   is negative |
|                 |                  | D0=0 if arg=0.0    | Z=1 if result |
|                 |                  |                    |     is zero   |
|                 |                  |                    | V=0           |
|                 |                  |                    | C=undefined   |
|                 |                  |                    | X=undefined   |
|                 |                  |                    | EQ=arg=0.0    |
|                 |                  |                    | NE=arg<>0.0   |
|                 |                  |                    | PL=arg>=0.0   |
|                 |                  |                    | MI=arg<0.0    |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEESPAbs   | D0=IEEE arg      | D0=IEEE            | N=undefined   |
|                 | single-precision | single-precision   | Z=undefined   |
|                 |                  | absolute value     | V=undefined   |
|                 |                  |                    | C=undefined   |
|                 |                  |                    | X=undefined   |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEESPNeg   | D0=IEEE arg      | D0=IEEE            | N=undefined   |
|                 | single-precision | single-precision   | Z=undefined   |
|                 |                  | negated            | V=undefined   |
|                 |                  |                    | C=undefined   |
|                 |                  |                    | X=undefined   |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEESPAdd   | D0=IEEE arg1     | D0=IEEE            | N=undefined   |
|                 | single-precision | single-precision   | Z=undefined   |
|                 | D1=IEEE arg2     | addition of        | V=undefined   |
|                 | single-precision | arg1+arg2          | C=undefined   |
|                 |                  |                    | X=undefined   |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEESPSub   | D0=IEEE arg1     | D0=IEEE            | N=undefined   |
|                 | single-precision | single-precision   | Z=undefined   |
|                 | D1=IEEE arg2     | subtraction of     | V=undefined   |
|                 | single-precision | arg1-arg2          | C=undefined   |
|                 |                  |                    | X=undefined   |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEESPMul   | D0=IEEE arg1     | D0=IEEE            | N=undefined   |
|                 | single-precision | single-precision   | Z=undefined   |
|                 | D1=IEEE arg2     | multiplication of  | V=undefined   |
|                 | single-precision | arg1*arg2          | C=undefined   |
|                 |                  |                    | X=undefined   |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEESPDiv   | D0=IEEE arg1     | D0=IEEE            | N=undefined   |
|                 | single-precision | single-precision   | Z=undefined   |
|                 | D1=IEEE arg2     | division of        | V=undefined   |
|                 | single-precision | arg1/arg2          | C=undefined   |
|                 |                  |                    | X=undefined   |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEESPCeil  | D0=IEEE variable | D0=least integer   | N=undefined   |
|                 | single-precision | >= variable        | Z=undefined   |
|                 |                  |                    | V=undefined   |
|                 |                  |                    | C=undefined   |
|                 |                  |                    | X=undefined   |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEESPFloor | D0=IEEE variable | D0=largest integer | N=undefined   |
|                 | single-precision | <= arg             | Z=undefined   |
|                 |                  |                    | V=undefined   |
|                 |                  |                    | C=undefined   |
|                 |                  |                    | X=undefined   |
|_________________|__________________|____________________|_______________|

