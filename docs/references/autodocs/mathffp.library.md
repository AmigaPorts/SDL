# mathffp.library — Autodoc Reference

*Filtered to AmigaOS V39 and below.*

**Functions:** 12

## Function Index

- **SPAbs** — Obtain the absolute value of the fast floating point number.
- **SPAdd** — Add two floating point numbers.
- **SPCeil** — Compute Ceil function of a number.
- **SPCmp** — Compares two floating point numbers.
- **SPDiv** — Divide two floating point numbers.
- **SPFix** — Convert fast floating point number to integer.
- **SPFloor** — compute Floor function of a number.
- **SPFlt** — Convert integer number to fast floating point.
- **SPMul** — Multiply two floating point numbers.
- **SPNeg** — Negate the supplied floating point number.
- **SPSub** — Subtract two floating point numbers.
- **SPTst** — 

## Functions

### mathffp.library/SPAbs

**Obtain the absolute value of the fast floating point number.**

**Synopsis:**
```c
fnum2 = SPAbs(fnum1)
D0	      D0

float SPAbs(float fnum1);
```

**Description:**
Accepts a floating point number and returns the absolute value of
said number.

**Inputs:**
fnum1 	- floating point number.

**Result:**
fnum2 	- floating point absolute value of fnum1.

**Bugs:**
None

---

### mathffp.library/SPAdd

**Add two floating point numbers.**

**Synopsis:**
```c
fnum3 = SPAdd(fnum1, fnum2)
D0	      D1     D0

float SPAdd(float fnum1, float fnum2);
```

**Description:**
Accepts two floating point numbers and returns the arithmetic
sum of said numbers.

**Inputs:**
fnum1 	- floating point number to add.
fnum2 	- other floating point number to add.

**Result:**
fnum3 	- floating point number, sum of fnum1 and fnum2.

**Bugs:**
None.

---

### mathffp.library/SPCeil

**Compute Ceil function of a number.**

**Synopsis:**
```c
x = SPCeil(y)
D0         D0

float SPCeil(float y);
```

**Description:**
Calculate the least integer greater than or equal to x and return it.
This identity is true.  Ceil(x) = -Floor(-x).

**Inputs:**
y 	- Motorola Fast Floating Point Format Number.

**Result:**
x 	- Motorola Fast Floating Point Format Number.

**Bugs:**
None.

**See also:** SPFloor()

---

### mathffp.library/SPCmp

**Compares two floating point numbers.**

**Synopsis:**
```c
result = SPCmp(fnum1, fnum2)
D0               D0     D1

int SPCmp(float fnum1, float fnum2);
```

**Description:**
Accepts two floating point numbers and returns the condition
codes set to indicate the result of said comparison.  Additionally,
the integer functional result is returned to indicate the result
of said comparison.

**Inputs:**
fnum1 	- floating point number.
fnum2 	- floating point number.

**Result:**
Condition codes set to reflect the following branches:

	GT - fnum2 >  fnum1
	GE - fnum2 >= fnum1
	EQ - fnum2 =  fnum1
	NE - fnum2 != fnum1
	LT - fnum2 <  fnum1
	LE - fnum2 <= fnum1

Integer functional result as:

	+1 => fnum1 > fnum2
	-1 => fnum1 < fnum2
	 0 => fnum1 = fnum2

**Bugs:**
None.

---

### mathffp.library/SPDiv

**Divide two floating point numbers.**

**Synopsis:**
```c
fnum3 = SPDiv(fnum1, fnum2)
D0	      D1     D0

float SPDiv(float fnum1, float fnum2);
```

**Description:**
Accepts two floating point numbers and returns the arithmetic
division of said numbers.

**Inputs:**
fnum1 	- floating point number.
fnum2	- floating point number.

**Result:**
fnum3 	- floating point number (fnum3 = fnum2/fnum1).

**Bugs:**
None.

---

### mathffp.library/SPFix

**Convert fast floating point number to integer.**

**Synopsis:**
```c
inum = SPFix(fnum)
D0	     D0

int SPFix(float fnum);
```

**Description:**
Accepts a floating point number and returns the truncated
integer portion of said number.

**Inputs:**
fnum 	- floating point number.

**Result:**
inum 	- signed integer number.

**Bugs:**
None.

---

### mathffp.library/SPFloor

**compute Floor function of a number.**

**Synopsis:**
```c
x = SPFloor(y)
D0 	    D0

float SPFloor(float y);
```

**Description:**
Calculate the largest integer less than or equal to x and return it.

**Inputs:**
y 	- Motorola Fast Floating Point number.

**Result:**
x 	- Motorola Fast Floating Point number.

**Bugs:**
None.

**See also:** SPCeil()

---

### mathffp.library/SPFlt

**Convert integer number to fast floating point.**

**Synopsis:**
```c
fnum = SPFlt(inum)
D0	     D0

float SPFlt(inet inum);
```

**Description:**
Accepts an integer and returns the converted
floating point result of said number.

**Inputs:**
inum 	- signed integer number

**Result:**
fnum 	- floating point number

**Bugs:**
None.

---

### mathffp.library/SPMul

**Multiply two floating point numbers.**

**Synopsis:**
```c
fnum3 = SPMul(fnum1, fnum2)
D0	      D1     D0

float SPMul(float fnum1, float fnum2);
```

**Description:**
Accepts two floating point numbers and returns the arithmetic
multiplication of said numbers.

**Inputs:**
fnum1 	- floating point number
fnum2 	- floating point number

**Result:**
fnum3 	- floating point number

**Bugs:**
None

---

### mathffp.library/SPNeg

**Negate the supplied floating point number.**

**Synopsis:**
```c
fnum2 = SPNeg(fnum1)
D0	      D0

float SPNeg(float fnum1);
```

**Description:**
Accepts a floating point number and returns the value
of said number after having been subtracted from 0.0.

**Inputs:**
fnum1 	- floating point number.

**Result:**
fnum2 	- floating point negation of fnum1.

**Bugs:**
None

---

### mathffp.library/SPSub

**Subtract two floating point numbers.**

**Synopsis:**
```c
fnum3 = SPSub(fnum1, fnum2)
D0	      D1     D0

float SPSub(float fnum1, float fnum2);
```

**Description:**
Accepts two floating point numbers and returns the arithmetic
subtraction of said numbers.

**Inputs:**
fnum1 	- floating point number.
fnum2 	- floating point number.

**Result:**
fnum3 	- floating point number.

**Bugs:**
None.

---

### mathffp.library/SPTst

**Synopsis:**
```c
result = SPTst(fnum)
D0	       D1

int SPTst(float fnum);
```

**Description:**
Accepts a floating point number and returns the condition
codes set to indicate the result of a comparison against
the value of zero (0.0).  Additionally, the integer functional
result is returned.

**Inputs:**
fnum 	- floating point number.

**Result:**
Condition codes set to reflect the following branches:

	EQ - fnum =  0.0
	NE - fnum != 0.0
	PL - fnum >= 0.0
	MI - fnum <  0.0

Integer functional result as:

	+1 => fnum > 0.0
	-1 => fnum < 0.0
	 0 => fnum = 0.0

**Bugs:**
None.

---
