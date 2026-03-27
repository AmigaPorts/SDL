# 35 /IEEE Double-Precision Basic Math Library / DP IEEE Basic Functions


[IEEEDPAbs()](../Includes_and_Autodocs_2._guide/node03FA.html)    DOUBLE IEEEDPAbs( DOUBLE parm );

    Take absolute value of IEEE double-precision variable.
[IEEEDPAdd()](../Includes_and_Autodocs_2._guide/node03FB.html)    DOUBLE IEEEDPAdd( DOUBLE leftParm, DOUBLE rightParm );

    Add two IEEE double-precision variables.
[IEEEDPCeil()](../Includes_and_Autodocs_2._guide/node03FC.html)   DOUBLE IEEEDPCeil( DOUBLE parm );

    Compute least integer greater than or equal to variable.
[IEEEDPCmp()](../Includes_and_Autodocs_2._guide/node03FD.html)    LONG IEEEDPCmp( DOUBLE leftParm, DOUBLE rightParm );

    Compare two IEEE double-precision variables.
[IEEEDPDiv()](../Includes_and_Autodocs_2._guide/node03FE.html)    DOUBLE IEEEDPDiv( DOUBLE dividend, DOUBLE divisor );

    Divide two IEEE double-precision variables.
[IEEEDPFix()](../Includes_and_Autodocs_2._guide/node03FF.html)    LONG IEEEDPFix( DOUBLE parm );

    Convert IEEE double-precision  variable to integer.
[IEEEDPFloor()](../Includes_and_Autodocs_2._guide/node0400.html)  DOUBLE IEEEDPFloor( DOUBLE parm );

    Compute largest integer less than or equal to variable.
[IEEEDPFlt()](../Includes_and_Autodocs_2._guide/node0401.html)    DOUBLE IEEEDPFlt( long integer );

    Convert integer variable to IEEE double-precision.
[IEEEDPMul()](../Includes_and_Autodocs_2._guide/node0402.html)    DOUBLE IEEEDPMul( DOUBLE factor1, DOUBLE factor2 );

    Multiply two IEEE double-precision variables.
[IEEEDPNeg()](../Includes_and_Autodocs_2._guide/node0403.html)    DOUBLE IEEEDPNeg( DOUBLE parm );

    Take two's complement of IEEE double-precision variable.
[IEEEDPSub()](../Includes_and_Autodocs_2._guide/node0404.html)    DOUBLE IEEEDPSub( DOUBLE leftParm, DOUBLE rightParm );

    Subtract two IEEE double-precision variables.
[IEEEDPTst()](../Includes_and_Autodocs_2._guide/node0405.html)    LONG IEEEDPTst( DOUBLE parm );

    Test an IEEE double-precision variable against zero.
Be sure to include proper data type definitions, as shown in the example
below.


```c
     [mathieeedoubbas.c](../Libraries_Manual_guide/node0601.html) 
```
The Amiga assembly language interface to the IEEE double-precision
floating-point basic math routines is shown below, including some details
about how the system flags are affected by each operation.  The access
mechanism from assembly language is:



```c
        MOVEA.L _MathIeeeDoubBasBase,A6
        JSR     _LVOIEEEDPFix(A6)
```
 _________________________________________________________________________
|                                                                         |
|                    DP IEEE Basic Assembly Functions                     |
|                                                                         |
| Function          Input              Output             Condition Codes |
|_________________________________________________________________________|
|                 |                  |                    |               |
| _LVOIEEEDPFix   | D0/D1=IEEE arg   | D0=Integer         | N=undefined   |
|                 | double-precision | (two's complement) | Z=undefined   |
|                 |                  |                    | V=undefined   |
|                 |                  |                    | C=undefined   |
|                 |                  |                    | X=undefined   |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEEDPFl    | D0=Integer arg   | D0/D1=IEEE         | N=undefined   |
|                 |     (two's       | double-precision   | Z=undefined   |
|                 |   complement)    |                    | V=undefined   |
|                 |                  |                    | C=undefined   |
|                 |                  |                    | X=undefined   |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEEDPCmp   | D0/D1=IEEE arg1  | D0=+1 if arg1>arg2 | N=1 if result |
|                 | double-precision | D0=-1 if arg1<arg2 |   is negative |
|                 | D2/D3=IEEE arg2  | D0=0 if arg1=arg2  | Z=1 if result |
|                 | double-precision |                    |     is zero   |
|                 |                  |                    | V=0           |
|                 |                  |                    | C=undefined   |
|                 |                  |                    | X=undefined   |
|                 |                  |                    | GT=arg2>arg1  |
|                 |                  |                    | GE=arg2>=arg1 |
|                 |                  |                    | EQ=arg2=arg1  |
|                 |                  |                    | NE=arg2<>arg1 |
|                 |                  |                    | LT=arg2<arg1  |
|                 |                  |                    | LE=arg2<=arg1 |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEEDPTst   | D0/D1=IEEE arg   | D0=+1 if arg>0.0   | N=1 if result |
|                 | double-precision | D0=-1 if arg<0.0   |   is negative |
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
| _LVOIEEEDPAbs   | D0/D1=IEEE arg   | D0/D1=IEEE         | N=undefined   |
|                 | double-precision | double-precision   | Z=undefined   |
|                 |                  | absolute value     | V=undefined   |
|                 |                  |                    | C=undefined   |
|                 |                  |                    | X=undefined   |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEEDPNeg   | D0/D1=IEEE arg   | D0/D1=IEEE         | N=undefined   |
|                 | double-precision | double-precision   | Z=undefined   |
|                 |                  | negated            | V=undefined   |
|                 |                  |                    | C=undefined   |
|                 |                  |                    | X=undefined   |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEEDPAdd   | D0/D1=IEEE arg1  | D0/D1=IEEE         | N=undefined   |
|                 | double-precision | double-precision   | Z=undefined   |
|                 |                  | addition of        | V=undefined   |
|                 | D2/D3=IEEE arg2  | arg1+arg2          | C=undefined   |
|                 | double-precision |                    | X=undefined   |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEEDPSub   | D0/D1=IEEE arg1  | D0/D1=IEEE         | N=undefined   |
|                 | double-precision | double-precision   | Z=undefined   |
|                 |                  | subtraction of     | V=undefined   |
|                 | D2/D3=IEEE arg2  | arg1-arg2          | C=undefined   |
|                 | double-precision |                    | X=undefined   |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEEDPMul   | D0/D1=IEEE arg1  | D0/D1=IEEE         | N=undefined   |
|                 | double-precision | double-precision   | Z=undefined   |
|                 |                  | multiplication of  | V=undefined   |
|                 | D2/D3=IEEE arg2  | arg1*arg2          | C=undefined   |
|                 | double-precision |                    | X=undefined   |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEEDPDiv   | D0/D1=IEEE arg1  | D0/D1=IEEE         | N=undefined   |
|                 | double-precision | double-precision   | Z=undefined   |
|                 |                  | division of        | V=undefined   |
|                 | D2/D3=IEEE arg2  | arg1/arg2          | C=undefined   |
|                 | double-precision |                    | X=undefined   |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEEDPCeil  | D0/D1=IEEE arg   | D0/D1=least        | N=undefined   |
|                 | double-precision |       integer      | Z=undefined   |
|                 |                  | >= arg             | V=undefined   |
|                 |                  |                    | C=undefined   |
|                 |                  |                    | X=undefined   |
|-----------------|------------------|--------------------|---------------|
| _LVOIEEEDPFloor | D0/D1=IEEE arg   | D0/D1=largest      | N=undefined   |
|                 | double-precision |       integer      | Z=undefined   |
|                 |                  | <= arg             | V=undefined   |
|                 |                  |                    | C=undefined   |
|                 |                  |                    | X=undefined   |
|_________________|__________________|____________________|_______________|

