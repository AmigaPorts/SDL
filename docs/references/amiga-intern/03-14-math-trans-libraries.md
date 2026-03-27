# The MathTrans Libraries

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

### 3.1.14 The MathTrans, MathlEEESingTrans, and

MathlEEEDoubTrans Libraries 

Now we will look at the libraries for trigonometrical functions. What is true for the basic mathematical functions also applies to these functions.

Trigonometrical functions 

Acos 

Asin 

Atan 

Cos 

Cosh 

Exp 

Fieee 

Log 

LoglO 

Pow 

Sin 

Sincos 

Sinh 

Sqrt 

Tan 

Tanh 

Tieee 

Description of the functions 

ISPAcos/IEEESPAcos/IEEEDPAcos arc cosliil 

Call: x  = ... Acos (  y ) 

-120 (A6) 

d0 SPAcos dO dO IEEESPAcos dO dO/dl IEEEDPAcos dO/dl

Function: Returns the arc cos of 'y'. 

[SPAsin/IEEESPAsin/IEEEDPAsin arc sln| 

Call: x  = . . .Asin( y  ) 

-114 (A6) 

## 3.1 The Libraries and their Functions

dO SPAsin dO dO IEEESPAsin dO dO/dl IEEEDPAsin dO/dl

Function: Returns the arc sin of 'y'. 

I SPAtan/IEEESPAtan/IEEEDPAtan 

Call: x  = ... Atan (  y ) 

-30 (A6) 

dO SPAtan dO dO IEEESPAtan dO dO/dl IEEEDPAtan dO/dl

Function: Returns the arc tan of 'y' • 

| SPCos/IEEESPCos/IEEEDPCos 

Call: x  = ... Cos (  y ) 

-42 (A6) 

dO SPCos dO dO lEEESPCos dO dO/dl IEEEDPCos dO/dl

Function: Returns the cos of 'y'. 

| SPCosh/IEEESPCosh/IEEEDPCosh 

Call: x  = ... Cosh (  y ) 

-66 (A6) 

dO SPCosh dO dO IEEESPCosh dO dO/dl IEEEDPCosh dO/dl arc tangent cosinl hyperbolic cosin|

Function: Returns the hyperbolic cos of 'y'. 

ISPExp/IEEESPExp/IEEEDPExp Exponential function, base e| 

Call: 

X = 

. . . Exp (  y ) 

-78 (A6) 

dO

SPExp dO 

dO

IEEESPExp dO 

dO/dl IEEEDPExp dO/dl

Function: x  = eAy 

| SPFieee/IEEESPFieee/IEEEDPFieee 

Convert IEEE single | 

Call: 

x =

Function: 

. . .Fieee( y   ) 

-108 (A6) 

dO SPFieee dO
(dO IEEESPFieee dO) 

dO/dl lEEEDPFieee dO

Converts a  32 bit IEEE value to the format of the current 

library.

I SPLog/IEEESPLog/IEEEDPLog 

Natural logarithm] 

Call: x  = ... Log (  y ) 

-84 (A6) 

dO SPLog dO dO IEEESPLog dO dO/dl IEEEDPLog dO/dl

Function: Returns the natural log of 'y'. 

ISPLoglO/IEEESPLoglO/IEEEDPLoglO Logarithm, base 10 1 

Call: x  = .  . .Logl0( y   ) 

-126 (A6) 

dO SPLoglO dO dO IEEESPLoglO dO dO/dl IEEEDPLoglO dO/dl

Function: Returns the base 10 log of 'y'. 

ISPPow/IEEESPPow/IEEEDPPow 

Exponential function] 

Call: z  = ... Pow (  x ,       y ) 

-90 (A6) 

dO SPPow dO dl dO lEEESPPow dO dl dO/dl IEEEDPPow dO/dl d2/d3

Function: z  = xAy 

| SPSin/IEEESPSin/IEEEDPSiiT 

sin

Call: x  = . . .sin( y  ) 

-36 (A6) 

dO SPSin dO dO IEEESPSin dO dO/dl IEEEDPSin dO/dl

Function: Returns the sin of 'y'. 

ISPSincos/IEEESPSincos/IEEEDPSincos 

Sin and Cosinl 

Call: x  = ...Sincos( y, z   ) 

-54 (A6) 

dO SPSincos dO dl- dO IEEESPSincos dO aO dO/dl IEEEDPSincos dO/dl aO

Function: x  = ...Sin(y) AND (z)=Cos(y). 'z' is the address of the cos 

result.

| SPSinh/IEEESPSinh/IEEEDPSinh 

Hyperbolic sin) 

Call: x  = . . .sinh( y  ) 

-60 (A6) 

dO SPSinh dO dO IEEESPSinh dO dO/dl IEEEDPSinh dO/dl

Function: Returns the hyperbolic sin of 'y'. 

ISPSprt/IEEESPSqrt/IEEEDPSqrt 

Square root] 

Call: x  = ... Sqrt (  y ) 

-96 (A6) 

dO SPSqrt dO dO IEEESPSqrt dO dO/dl IEEEDPSqrt dO/dl

Function: Returns the square root of 'y'. 

| SPTan/IEEESPTan/lEEEDPTan 

Call: x  = ... Tan (  y ) 

-48 (A6) 

dO SPTan dO dO IEEESPTan dO dO/dl lEEEDPTan dO/dl

Function: Returns the tangent of 'y'. 

ISPTanh/IEEESPTanh/IEEEDPTanh 

Call: x  = ... Tanh (  y ) 

-72 (A6) 

dO SPTanh dO dO IEEESPTanh dO dO/dl lEEEDPTanh dO/dl tangent |

Hyperbolic tangent] 

Function: Returns the hyperbolic tangent of 'y'. 

| SPTieee/IEEESPTieee/IEEEDPTieee Create an IEEE single] 

Call: x  = ...Tieee( y   ) 

-102 (A6) 

dO SPTieee dO

(dO IEEESPTieee dO) 

dO IEEEDPTieee dO/dl

Function: Converts a  value from the library format to a  32 bit IEEE 

value.

## 3.1 .1 5 The Translator Library

The "translatorJibrary" consists of only one routine. It is used to translate text into Phoneme codes for the Narrator device.

Description of function 

| Translate

Generate Phoneme | 

Call: rtnCode =  Translate (inString, inLength, outBuffer, outLength) 

DO -30 (A6) AO DO Al Dl 

LONG rtnCode,inLength,outLength 

APTR inString,outBuffer 

Function: Translates text into Phoneme codes. 

Parameters: inString Text 

inLength Text length outBuffer Buffer for Phonemes outLength Buffer length

Result: 0  Okay, otherwise negative cancel offset from 

start of text.
