# 35 / SP Basic Math Library / SP IEEE Basic Functions (V36 or Greater)


[IEEESPAbs()](../Includes_and_Autodocs_2._guide/node0190.html)    FLOAT ( FLOAT parm );

    Take absolute value of IEEE single-precision variable.
[IEEESPAdd()](../Includes_and_Autodocs_2._guide/node0191.html)    FLOAT IEEESPAdd( FLOAT leftParm, FLOAT rightParm);

    Add two IEEE single-precision variables.
[IEEESPCeil()](../Includes_and_Autodocs_2._guide/node0192.html)   FLOAT IEEESPCeil( FLOAT parm );

    Compute least integer greater than or equal to variable.
[IEEESPCmp()](../Includes_and_Autodocs_2._guide/node0193.html)    LONG  IEEESPCmp( FLOAT leftParm, FLOAT rightParm );

    Compare two IEEE single-precision variables.
[IEEESPDiv()](../Includes_and_Autodocs_2._guide/node0194.html)    FLOAT IEEESPDiv( FLOAT dividend, FLOAT divisor );

    Divide two IEEE single-precision variables.
[IEEESPFix()](../Includes_and_Autodocs_2._guide/node0195.html)    LONG  IEEESPFix( FLOAT parm );

    Convert IEEE single-precision  variable to integer.
[IEEESPFloor()](../Includes_and_Autodocs_2._guide/node0196.html)  FLOAT IEEESPFloor( FLOAT parm );

    Compute largest integer less than or equal to variable.
[IEEESPFlt()](../Includes_and_Autodocs_2._guide/node0197.html)    FLOAT IEEESPFlt( long integer );

    Convert integer variable to IEEE single-precision.
[IEEESPMul()](../Includes_and_Autodocs_2._guide/node0198.html)    FLOAT IEEESPMul( FLOAT leftParm, FLOAT rightParm );

    Multiply two IEEE single-precision variables.
[IEEESPNeg()](../Includes_and_Autodocs_2._guide/node0199.html)    FLOAT IEEESPNeg( FLOAT parm );

    Take two's complement of IEEE single-precision variable.
[IEEESPSub()](../Includes_and_Autodocs_2._guide/node019A.html)    FLOAT IEEESPSub( FLOAT leftParm, FLOAT rightParm );

    Subtract two IEEE single-precision variables.
[IEEESPTst()](../Includes_and_Autodocs_2._guide/node019B.html)    LONG  IEEESPTst( FLOAT parm );

    Test an IEEE single-precision variable against zero.
Be sure to include proper data type definitions, as shown in the example
below.


```c
     [mathieeesingbas.c](../Libraries_Manual_guide/node05FF.html) 
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

