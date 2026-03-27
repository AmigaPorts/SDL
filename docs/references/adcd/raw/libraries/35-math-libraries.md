# 35 Math Libraries


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
    Each [Task](../Libraries_Manual_guide/node02BB.html) using an IEEE math library must open the library itself.
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

 [Math Libraries and Functions](../Libraries_Manual_guide/node047C.html) 
 [FFP Floating Point Data Format](../Libraries_Manual_guide/node047D.html) 
 [FFP Basic Mathematics Library](../Libraries_Manual_guide/node047E.html) 
 [FFP Transcendental Mathematics Library](../Libraries_Manual_guide/node0480.html) 
 [FFP Mathematics Conversion Library](../Libraries_Manual_guide/node0482.html) 
 [IEEE Single-Precision Data Format](../Libraries_Manual_guide/node0484.html) 
 [IEEE Single-Precision Basic Math Library](../Libraries_Manual_guide/node0485.html) 
 [IEEE Single-Precision Transcendental Math Library](../Libraries_Manual_guide/node0487.html) 
 [IEEE Double-Precision Data Format](../Libraries_Manual_guide/node0489.html) 
 [IEEE Double-Precision Basic Math Library](../Libraries_Manual_guide/node048A.html) 
 [IEEE Double-Precision Transcendental Math Library](../Libraries_Manual_guide/node048C.html) 
 [Function Reference](../Libraries_Manual_guide/node048E.html) 
 [Compile and Link Commands for SAS C 5.10](../Libraries_Manual_guide/node048F.html) 

