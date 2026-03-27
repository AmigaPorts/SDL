---
title: mathieeedoubbas.library/IEEEDPCmp
manual: autodocs-3.5
chapter: autodocs-3.5
section: mathieeedoubbas-library-ieeedpcmp-2
functions: []
libraries: []
---

# mathieeedoubbas.library/IEEEDPCmp

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	IEEEDPCmp -- compare two double precision floating point numbers

   SYNOPSIS
	  c   = IEEEDPCmp(  y  ,  z  );
	  d0		  d0/d1 d2/d3

	double	y,z;
	long	c;

   FUNCTION
	Compare y with z. Set the condition codes for less, greater, or
	equal. Set return value c to -1 if y<z, or +1 if y>z, or 0 if
	y == z.

   INPUTS
	y -- IEEE double precision floating point value
	z -- IEEE double precision floating point value

   RESULT

```c
       c = 1   cc = gt         for (y > z)
       c = 0   cc = eq         for (y == z)
       c = -1  cc = lt         for (y < z)
```
   BUGS

   SEE ALSO

