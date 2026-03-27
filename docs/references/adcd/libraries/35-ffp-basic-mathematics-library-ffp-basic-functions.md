---
title: 35 / FFP Basic Mathematics Library / FFP Basic Functions
manual: libraries
chapter: libraries
section: 35-ffp-basic-mathematics-library-ffp-basic-functions
functions: [SPAbs, SPAdd, SPCeil, SPCmp, SPDiv, SPFix, SPFloor, SPFlt, SPMul, SPNeg, SPSub, SPTst]
libraries: [mathffp.library]
---

# 35 / FFP Basic Mathematics Library / FFP Basic Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[SPAbs()](autodocs-2.0/mathffp-library-spabs.md)    FLOAT SPAbs( FLOAT parm );
Take absolute value of FFP variable.

[SPAdd()](autodocs-2.0/mathffp-library-spadd.md)    FLOAT SPAdd( FLOAT leftParm, FLOAT rightParm);

    Add two FFP variables.
[SPCeil()](autodocs-2.0/mathffp-library-spceil.md)   FLOAT SPCeil( FLOAT parm ); 

    Computer largest integer less than or equal to variable.
[SPCmp()](autodocs-2.0/mathffp-library-spcmp.md)    LONG  SPCmp( FLOAT leftParm, FLOAT rightParm);

    Compare two FFP variables.
[SPDiv()](autodocs-2.0/mathffp-library-spdiv.md)    FLOAT SPDiv( FLOAT leftParm, FLOAT rightParm);

    Divide two FFP variables.
[SPFix()](autodocs-2.0/mathffp-library-spfix.md)    LONG  SPFix( FLOAT parm );

    Convert FFP variable to integer.
[SPFloor()](autodocs-2.0/mathffp-library-spfloor.md)  FLOAT SPFloor( FLOAT parm );

    Compute least integer greater than or equal to variable.
[SPFlt()](autodocs-2.0/mathffp-library-spflt.md)    FLOAT SPFlt( long integer );

    Convert integer variable to FFP.
[SPMul()](autodocs-2.0/mathffp-library-spmul.md)    FLOAT SPMul( FLOAT leftParm, FLOAT rightParm);

    Multiply two FFP variables.
[SPNeg()](autodocs-2.0/mathffp-library-spneg.md)    FLOAT SPNeg( FLOAT parm );

    Take two's complement of FFP variable.
[SPSub()](autodocs-2.0/mathffp-library-spsub.md)    FLOAT SPSub( FLOAT leftParm, FLOAT rightParm);

    Subtract two FFP variables.
[SPTst()](autodocs-2.0/mathffp-library-sptst.md)    LONG  SPTst( FLOAT parm );

    Test an FFP variable against zero.
Be sure to include the proper data type definitions shown below.


```c
    #include <exec/types.h>
    #include <libraries/mathffp.h>

    #include <clib/mathffp_protos.h>

    struct Library *MathBase;

    VOID main()
    {
    FLOAT f1, f2, f3;
    LONG   i1;

    if (MathBase = OpenLibrary("mathffp.library", 0))
        {
        i1 = SPFix(f1);            /* Call SPFix entry */
        f1 = SPFlt(i1);            /* Call SPFlt entry */

        if (SPCmp(f1,f2)) {};      /* Call SPCmp entry */
        if (!(SPTst(f1))) {};      /* Call SPTst entry */

        f1 = SPAbs(f2);            /* Call SPAbs entry */
        f1 = SPNeg(f2);            /* Call SPNeg entry */
        f1 = SPAdd(f2, f3);        /* Call SPAdd entry */
        f1 = SPSub(f2, f3);        /* Call SPSub entry */
        f1 = SPMul(f2, f3);        /* Call SPMul entry */
        f1 = SPDiv(f2, f3);        /* Call SPDiv entry */
        f1 = SPCeil(f2);           /* Call SPCeil entry */
        f1 = SPFloor(f2);          /* Call SPFloor entry */

        CloseLibrary(MathBase);
        }
    else
        printf("Can't open mathffp.library\n");
    }
```
The assembly language interface to the FFP basic math routines is shown
below, including some details about how the system flags are affected by
each operation.  The access mechanism is:


```c
        MOVEA.L _MathBase,A6
        JSR _LVOSPFix(A6)
```
  __________________________________________________________________
 |                                                                  |
 |                FFP Basic Assembly Functions                      |
 |                                                                  |
 | Function      Input         Output               Condition Codes |
 |__________________________________________________________________|
 |             |             |                    |                 |
 | _LVOSPAbs   | D0=FFP arg  | D0=FFP absolute    | N=0             |
 |             |             |        value       | Z=1 if result   |
 |             |             |                    |     is zero     |
 |             |             |                    | V=0             |
 |             |             |                    | C=undefined     |
 |             |             |                    | X=undefined     |
 |-------------|-------------|--------------------|-----------------|
 | _LVOSPAdd   | D1=FFP arg1 | D0=FFP addition    | N=1 if result   |
 |             | D0=FFP arg2 |    of arg1 + arg2  |     is negative |
 |             |             |                    | Z=1 if result   |
 |             |             |                    |     is zero     |
 |             |             |                    | V=1 if result   |
 |             |             |                    |     overflowed  |
 |             |             |                    | C=undefined     |
 |             |             |                    | Z=undefined     |
 |-------------|-------------|--------------------|-----------------|
 | _LVOSPCeil  | D0=FFP arg  | D0=least integer   | N=1 if result   |
 |             |             | >=arg              |     is negative |
 |             |             |                    | Z=1 if result   |
 |             |             |                    |     is zero     |
 |             |             |                    | V=undefined     |
 |             |             |                    | C=undefined     |
 |             |             |                    | Z=undefined     |
 |-------------|-------------|--------------------|-----------------|
 | _LVOSPCmp   | D1=FFP arg1 | D0=+1 if arg1>arg2 | N=0             |
 |             | D0=FFP arg2 | D0=-1 if arg1<arg2 | Z=1 if result   |
 |             |             | D0=0 if arg1=arg2  |     is zero     |
 |             |             |                    | V=0             |
 |             |             |                    | C=undefined     |
 |             |             |                    | X=undefined     |
 |             |             |                    | GT=arg2>arg1    |
 |             |             |                    | GE=arg2>=arg1   |
 |             |             |                    | EQ=arg2=arg1    |
 |             |             |                    | NE=arg2<>arg1   |
 |             |             |                    | LT=arg2<arg1    |
 |             |             |                    | LE=arg2<=arg1   |
 |-------------|-------------|--------------------|-----------------|
 | _LVOSPDiv   | D1=FFP arg1 | D0=FFP division    | N=1 if result   |
 |             | D0=FFP arg2 |    of arg2/arg1    |     is negative |
 |             |             |                    | Z=1 if result   |
 |             |             |                    |     is zero     |
 |             |             |                    | V=1 if result   |
 |             |             |                    |     overflowed  |
 |             |             |                    | C=undefined     |
 |             |             |                    | Z=undefined     |
 |-------------|-------------|--------------------|-----------------|
 | _LVOSPFix   | D0=FFP arg  | D0=Integer         | N=1 if result   |
 |             |             | (two's complement) |     is negative |
 |             |             |                    | Z=1 if result   |
 |             |             |                    |     is zero     |
 |             |             |                    | V=1 if overflow |
 |             |             |                    |     occurred    |
 |             |             |                    | C=undefined     |
 |             |             |                    | X=undefined     |
 |-------------|-------------|--------------------|-----------------|
 | _LVOSPFloor | D0=FFP arg  | D0=largest integer | N=1 if result   |
 |             |             | <= arg             |     is negative |
 |             |             |                    | Z=1 if result   |
 |             |             |                    |     is zero     |
 |             |             |                    | V=undefined     |
 |             |             |                    | C=undefined     |
 |             |             |                    | Z=undefined     |
 |-------------|-------------|--------------------|-----------------|
 | _LVOSPFlt   | D0=Integer  | D0=FFP result      | N=1 if result   |
 |             |   (two's    |                    |     is negative |
 |             | complement) |                    | Z=1 if result   |
 |             |             |                    |     is zero     |
 |             |             |                    | V=0             |
 |             |             |                    | C=undefined     |
 |             |             |                    | X=undefined     |
 |-------------|-------------|--------------------|-----------------|
 | _LVOSPMul   | D0=FFP arg1 | D0=FFP             | N=1 if result   |
 |             | D1=FFP arg2 |    multiplication  |     is negative |
 |             |             |    of arg1*arg2    | Z=1 if result   |
 |             |             |                    |     is zero     |
 |             |             |                    | V=1 if result   |
 |             |             |                    |     overflowed  |
 |             |             |                    | C=undefined     |
 |             |             |                    | Z=undefined     |
 |             |             |                    |                 |
 |-------------|-------------|--------------------|-----------------|
 | _LVOSPNeg   | D0=FFP arg  | D0=FFP negated     | N=1 if result   |
 |             |             |                    |     is negative |
 |             |             |                    | Z=1 if result   |
 |             |             |                    |     is zero     |
 |             |             |                    | V=0             |
 |             |             |                    | C=undefined     |
 |             |             |                    | X=undefined     |
 |-------------|-------------|--------------------|-----------------|
 | _LVOSPSub   | D1=FFP arg1 | D0=FFP subtraction | N=1 if result   |
 |             | D0=FFP arg2 |    of arg2-arg1    |     is negative |
 |             |             |                    | Z=1 if result   |
 |             |             |                    |     is zero     |
 |             |             |                    | V=1 if result   |
 |             |             |                    |     overflowed  |
 |             |             |                    | C=undefined     |
 |             |             |                    | Z=undefined     |
 |-------------|-------------|--------------------|-----------------|
 | _LVOSPTst   | D1=FFP arg  | D0=+1 if arg>0.0   | N=1 if result   |
 |             |             | D0=-1 if arg<0.0   |     is negative |
 |             |             | D0=0 if arg=0.0    | Z=1 if result   |
 |             |             |                    |     is zero     |
 |             |             |                    | V=0             |
 |             |             |                    | C=undefined     |
 |             |             |                    | X=undefined     |
 |             | Note: This  |                    | EQ=arg=0.0      |
 |             | routine     |                    | NE=arg<>0.0     |
 |             | trashes the |                    | PL=arg>=0.0     |
 |             | arg in D1.  |                    | MI=arg<0.0      |
 |_____________|_____________|____________________|_________________|

---

## See Also

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
