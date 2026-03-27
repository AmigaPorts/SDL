# mathieeedoubbas.library — Autodoc Reference

*Filtered to AmigaOS V39 and below.*

**Functions:** 13

## Function Index

- **--Background--** — 
- **IEEEDPAbs** — compute absolute value of IEEE double precision argument
- **IEEEDPAdd** — add one double precision IEEE number to another
- **IEEEDPCeil** — compute Ceil function of IEEE double precision number
- **IEEEDPCmp** — compare two double precision floating point numbers
- **IEEEDPDiv** — divide one double precision IEEE by another
- **IEEEDPFix** — convert IEEE double float to integer
- **IEEEDPFloor** — compute Floor function of IEEE double precision number
- **IEEEDPFlt** — convert integer to IEEE double precision number
- **IEEEDPMul** — multiply one double precision IEEE number by another
- **IEEEDPNeg** — compute negative value of IEEE double precision number
- **IEEEDPSub** — subtract one double precision IEEE number from another
- **IEEEDPTst** — compare IEEE double precision value to 0.0

## Functions

### mathieeedoubbas.library/--Background--

**Bugs:**
Pre V45 releases could have forgotten to re-initialize the FPU
properly if re-opened; in fact, pre-V45 might have even crashed if
something in the startup went wrong.

---

### mathieeedoubbas.library/IEEEDPAbs

**compute absolute value of IEEE double precision argument**

**Synopsis:**
```c
x   = IEEEDPAbs(  y  );
d0/d1		  d0/d1

double	x,y;
```

**Description:**
Take the absolute value of argument y and return it to caller.

**Inputs:**
y -- IEEE double precision floating point value

**Result:**
x -- IEEE double precision floating point value

**Bugs:**


---

### mathieeedoubbas.library/IEEEDPAdd

**add one double precision IEEE number to another**

**Synopsis:**
```c
x   = IEEEDPAdd(  y  ,  z  );
d0/d1		  d0/d1 d2/d3

double	x,y,z;
```

**Description:**
Compute x = y + z in IEEE double precision.

**Inputs:**
y -- IEEE double precision floating point value
z -- IEEE double precision floating point value

**Result:**
x -- IEEE double precision floating point value

**Bugs:**


**See also:** IEEEDPSub()

---

### mathieeedoubbas.library/IEEEDPCeil

**compute Ceil function of IEEE double precision number**

**Synopsis:**
```c
x   = IEEEDPCeil(  y  );
d0/d1		   d0/d1

double	x,y;
```

**Description:**
Calculate the least integer greater than or equal to x and return it.
This value may have more than 32 bits of significance.
This identity is true.  Ceil(x) = -Floor(-x).

**Inputs:**
y -- IEEE double precision floating point value

**Result:**
x -- IEEE double precision floating point value

**Bugs:**


**See also:** IEEEDPFloor()

---

### mathieeedoubbas.library/IEEEDPCmp

**compare two double precision floating point numbers**

**Synopsis:**
```c
c   = IEEEDPCmp(  y  ,  z  );
  d0		  d0/d1 d2/d3

double	y,z;
long	c;
```

**Description:**
Compare y with z. Set the condition codes for less, greater, or
equal. Set return value c to -1 if y<z, or +1 if y>z, or 0 if
y == z.

**Inputs:**
y -- IEEE double precision floating point value
z -- IEEE double precision floating point value

**Result:**
c = 1   cc = gt         for (y > z)
c = 0   cc = eq         for (y == z)
c = -1  cc = lt         for (y < z)

**Bugs:**
Did not work correctly prior to V45 and might have returned results
indicating the wrong order for negative numbers of small absolute
value. This has been fixed in V45.

---

### mathieeedoubbas.library/IEEEDPDiv

**divide one double precision IEEE by another**

**Synopsis:**
```c
x   = IEEEDPDiv(  y  ,  z  );
d0/d1		  d0/d1 d2/d3

double	x,y,z;
```

**Description:**
Compute x = y / z in IEEE double precision.

**Inputs:**
y -- IEEE double precision floating point value
z -- IEEE double precision floating point value

**Result:**
x -- IEEE double precision floating point value

**Bugs:**


**See also:** IEEEDPMul()

---

### mathieeedoubbas.library/IEEEDPFix

**convert IEEE double float to integer**

**Synopsis:**
```c
x   = IEEEDPFix(  y  );
d0		d0/d1

long	x;
double	y;
```

**Description:**
Convert IEEE double precision argument to a 32 bit signed integer
and return result.

**Inputs:**
y -- IEEE double precision floating point value

**Result:**
if no overflow occured then return
	x -- 32 bit signed integer
if overflow return largest +- integer
	For round to zero

**Bugs:**


**See also:** IEEEDPFlt()

---

### mathieeedoubbas.library/IEEEDPFloor

**compute Floor function of IEEE double precision number**

**Synopsis:**
```c
x   = IEEEDPFloor(  y  );
d0/d1		    d0/d1

double	x,y;
```

**Description:**
Calculate the largest integer less than or equal to x and return it.
This value may have more than 32 bits of significance.

**Inputs:**
y -- IEEE double precision floating point value

**Result:**
x -- IEEE double precision floating point value

**Bugs:**


**See also:** IEEEDPCeil()

---

### mathieeedoubbas.library/IEEEDPFlt

**convert integer to IEEE double precision number**

**Synopsis:**
```c
x   = IEEEDPFlt(  y  );
d0/d1		   d0

double	x;
long	y;
```

**Description:**
Convert a signed 32 bit value to a double precision IEEE value
and return it in d0/d1. No exceptions can occur with this
function.

**Inputs:**
y -- 32 bit integer in d0

**Result:**
x is a 64 bit double precision IEEE value

**Bugs:**


**See also:** IEEEDPFix()

---

### mathieeedoubbas.library/IEEEDPMul

**multiply one double precision IEEE number by another**

**Synopsis:**
```c
x   = IEEEDPMul(  y  ,  z  );
d0/d1		  d0/d1 d2/d3

double	x,y,z;
```

**Description:**
Compute x = y * z in IEEE double precision.

**Inputs:**
y -- IEEE double precision floating point value
z -- IEEE double precision floating point value

**Result:**
x -- IEEE double precision floating point value

**Bugs:**


**See also:** IEEEDPDiv()

---

### mathieeedoubbas.library/IEEEDPNeg

**compute negative value of IEEE double precision number**

**Synopsis:**
```c
x   = IEEEDPNeg(  y  );
d0/d1		  d0/d1

double	x,y;
```

**Description:**
Invert the sign of argument y and return it to caller.

**Inputs:**
y - IEEE double precision floating point value

**Result:**
x - IEEE double precision floating point value

**Bugs:**


---

### mathieeedoubbas.library/IEEEDPSub

**subtract one double precision IEEE number from another**

**Synopsis:**
```c
x   = IEEEDPSub(  y  ,  z  );
d0/d1		  d0/d1 d2/d3

double	x,y,z;
```

**Description:**
Compute x = y - z in IEEE double precision.

**Inputs:**
y -- IEEE double precision floating point value
z -- IEEE double precision floating point value

**Result:**
x -- IEEE double precision floating point value

**Bugs:**


**See also:** IEEEDPAdd()

---

### mathieeedoubbas.library/IEEEDPTst

**compare IEEE double precision value to 0.0**

**Synopsis:**
```c
c   = IEEEDPTst(  y  );
  d0		  d0/d1

double	y;
long	c;
```

**Description:**
Compare y to 0.0, set the condition codes for less than, greater
than, or equal to 0.0.  Set the return value c to -1 if less than,
to +1 if greater than, or 0 if equal to 0.0.

**Inputs:**
y -- IEEE double precision floating point value

**Result:**
c = 1	cc = gt		for (y > 0.0)
c = 0	cc = eq		for (y == 0.0)
c = -1  cc = lt		for (y < 0.0)

**Bugs:**


---
