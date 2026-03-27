# The Math Libraries

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

### 3.1.13 The MathFFP, MathlEEESingBas, and

MathlEEEDoubBas Libraries 

The Amiga supports three different floating point formats: the international IEEE formats for 32 and 64 bit floating point numbers
(which can be directly processed by the FPU 68882), and the 

FastFloatingPoint format. 

The FFP format is the fastest 32 bit floating point format as long as you don't have an FPU, which will process the IEEE formats faster than any
CPU. 

Two libraries exist for each format. First, we will discuss the library for 

basic mathematical functions. The functions and their function offsets are the same for all three libraries.

MathFFP functions begin with 'SF and expect 32 bit FFP values. 

MathlEEESingBas functions begin with 'IEEESP' and expect 32 bit 

IEEE values. MathlEEEDoubBas functions begin with 'IEEEEDF and 

expect 64 bit IEEEs. The 64 bit numbers are always distributed across two registers (upper 32 bits/lower 32 bits).

Functions of the Base Libraries 

Abs 

Add 

Ceil 

Cmp 

Div 

Fix 

Floor 

Fit 

Mul 

Neg 

Sub 

Tst 

Description of the functions 

ISPAbs/IEEESPAbs/IEEEDPAbs Absolute value \ 

Call: 

X = 

. . .Abs ( 

-54 (A6) 

y ) dO

SPAbs 

dO dO

IEEESPAbs 

dO dO/dl

IEEEDPAbs 

dO/dl

Function: 

Returns the positive value of V. 

## 3.1 The Libraries and their Functions

ISPAdd/IEEESPAdd/IEEEDPAdd Add two values] 

Call: x  = . . .Add (  y ,        z ) 

-66 (A6) 

dO SPAdd dO dl dO IEEESPAdd dO dl dO/dl IEEEDPAdd dO/dl d2/d3

Function: x  = y  + z 

ISPCeil/IEEESPCeil/IEEEDPCeil Round up] 

Call: x           = .  . .ceil (  y ) 

-96(A6) 

dO SPCeil dO dO IEEESPCeil dO dO/dl lEEEDPCeil dO/dl

Function: Rounds 'y' to the next whole number '>=y'. 

I SPCmp/IEEESPCmp/IEEEDPCmp Compare values 1 

Call: c  = . . .cmp (  y ,        z ) 

-42 (A6) 

dO,cc SPCmp dl dO dO,cc IEEESPCmp dl dO dO.cc IEEEDPCmp dO/dl d2/d3

Function: Compare two values. 

Result: c= l,cc =  gt:y>z 

c =  0, cc =  eq: y  = z c =  -l,cc =  lt:y<z
| SPDi v/IEEESPDi v/lEEEDPDi v  Djvjsjon] 

Call: 

... Div (  y , 

z

-84 (A6) 

dO

SPDiv dO 

dl dO

IEEESPDiv dO 

dl dO/dl IEEEDPDiv dO/dl d2/d3
Function: x  = y  / z 

I SPFix/IEEESPFix/IEEEDPFix Convert float to 32 bit integer | 

Call: 

X = 

. ..Fix( 

-30 (A6) 

y ) dO

SPFix 

dO dO

IEEESPFix 

dO dO

IEEEDPFix 

dO/dl

Function: 

Converts floating pc 

lint num

SPFloor/IEEESPFloor/IEEEDPFloor Round down| 

Call: x  = ... Floor (  y ) 

-90 (A6) 

dO SPFloor dO dO IEEESPFloor dO dO/dl IEEEDPFloor dO/dl

Function: Rounds 'y' to the next whole number '<=y'. 

| SPFIt/IEEESPFlt/IEEEDPFlt Convert long to floatl 

Call: x  = ...Flt( y  ) 

-36 (A6) 

dO SPFlt dO dO IEEESPFlt dO dO/dl IEEEDPFlt dO

Function: Converts a  32 bit integer to a  floating point number. 

I SPMul/IEEESPMul IEEEDPMul Multiplication | 

Call: x  = . . .Mul( y  , z   ) 

-78 (A6) 

dO SPMul dO dl dO IEEESPMul dO dl dO/dl IEEEDPMul dO/dl d2/d3

Function: x  = y  * z 

I SPNeg/IEEESPNeg/IEEEDPNeg 

Call: x  = . . .Neg( y  ) 

-60 (A6) 

dO SPNeg dO dO IEEESPNeg dO dO/dl IEEEDPNeg dO/dl

Function: x  = -y 

| SPSub/IEEESPSub/IEEEDPSub 

1 SPTst/IEEESPTst/IEEEDPTst 

Call: c  = ... Tst (  y ) 

-48 (A6) 

dO, cc SPTst dO dO, cc IEEESPTst dO dO,cc IEEEDPTst dO/dl

Function: Compares a  value with 0. 

Result: c= l,cc =  gt:y>0.0 

c =  0, cc =  eq: y  = 0.0 c =  -l,cc =  lt:y<0.0

Negation] 

Subtraction] 

Call: x  = ... Sub (  y ,       z ) 

-72 (A6) 

dO SPSub dO dl dO IEEESPSub dO dl dO/dl IEEEDPSub dO/dl d2/d3

Function: x  = y  - z 

Test a  value] 

