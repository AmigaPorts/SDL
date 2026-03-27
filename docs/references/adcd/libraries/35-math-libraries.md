---
title: 35 Math Libraries
manual: libraries
chapter: libraries
section: 35-math-libraries
functions: []
libraries: []
---

# 35 Math Libraries

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This chapter describes the structure and calling sequences required to
access the Motorola Fast Floating Point (FFP), the IEEE single-precision
math libraries and the IEEE double-precision math libraries via the
Amiga-supplied interfaces.

In its present state, the FFP library consists of three separate entities:
the basic math library, the transcendental math library, and C and
assembly-language interfaces to the basic math library plus FFP conversion
functions.  The IEEE single-precision, introduced in Release 2, and the
double-precision libraries each presently consists of two entities: the
basic math library and the transcendental math library.


```c
    Open Each Library Separately.
    -----------------------------
    Each [Task](libraries/21-exec-tasks-task-structure.md) using an IEEE math library must open the library itself.
    Library base pointers to these libraries may not be shared.
    Libraries can be context sensitive and may use the Task structure to
    keep track of the current context.  Sharing of library bases by Tasks
    may seem to work in some systems.  This is true for any of the IEEE
    math libraries.
```
Depending on the compiler used, it is not always necessary to explicitly
call the library functions for basic floating point operations as adding,
subtracting, dividing, etc.  Consult the manual supplied with the compiler
for information regarding the compiler options for floating point
functions.

 [Math Libraries and Functions](libraries/35-math-libraries-math-libraries-and-functions.md) 
 [FFP Floating Point Data Format](libraries/35-math-libraries-ffp-floating-point-data-format.md) 
 [FFP Basic Mathematics Library](libraries/35-math-libraries-ffp-basic-mathematics-library.md) 
 [FFP Transcendental Mathematics Library](libraries/35-math-libraries-ffp-transcendental-mathematics-library.md) 
 [FFP Mathematics Conversion Library](libraries/35-math-libraries-ffp-mathematics-conversion-library.md) 
 [IEEE Single-Precision Data Format](libraries/35-math-libraries-ieee-single-precision-data-format.md) 
 [IEEE Single-Precision Basic Math Library](libraries/35-math-libraries-ieee-single-precision-basic-math-library.md) 
 [IEEE Single-Precision Transcendental Math Library](libraries/35-math-libraries-ieee-single-precision-transcendental-math.md) 
 [IEEE Double-Precision Data Format](libraries/35-math-libraries-ieee-double-precision-data-format.md) 
 [IEEE Double-Precision Basic Math Library](libraries/35-math-libraries-ieee-double-precision-basic-math-library.md) 
 [IEEE Double-Precision Transcendental Math Library](libraries/35-math-libraries-ieee-double-precision-transcendental-math.md) 
 [Function Reference](libraries/35-math-libraries-function-reference.md) 
 [Compile and Link Commands for SAS C 5.10](libraries/35-math-libraries-compile-and-link-commands-for-sas-c-5-10.md) 

