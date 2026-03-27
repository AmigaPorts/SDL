# VII-1: The DR2D FORM


by Ross Cunniff and John Orr


A standard IFF FORM to describe 2D drawings has been sorely needed for
a long time.  Several commercial drawing packages have been available
for some time but none has established its file format as the Amiga
standard.  The absence of a 2D drawing standard hinders the
development of applications that use 2D drawings as it forces each
application to understand several private standards instead of a
single one.  Without a standard, data exchange for both the developer
and the user is difficult, if not impossible.

The DR2D FORM fills this void.  This FORM was developed by Taliesin,
Inc. for use as the native file format for their two-dimensional
structured drawing package, ProVector.  Saxon Industries and Soft
Logik Publishing Corporation are planning to support this new FORM in
the near future.

Many of the values stored in the DR2D FORM are stored as IEEE single
precision floating point numbers.  These numbers consist of 32 bits,
arranged as follows:

 _______________________________________________________________________
| s e e e e e e e | e m m m m m m m | m m m m m m m m | m m m m m m m m |
 -----------------------------------------------------------------------
  31            24  23            16  15            8   7             0


where:


```c
    s   is the sign of the number where 1 is negative and 0 is
          positive.
    e   is the 8 bit exponent in excess 127 form.  This number
          is the power of two to which the mantissa is raised
          (Excess 127 form means that 127 is added to the
          exponent before packing it into the IEEE number.)
    m   is the 23 bit mantissa.  It ranges from 1.0000000 to
          1.999999..., where the leading base-ten one is
          assumed.
```
An IEEE single precision with the value of 0.0000000 has all its bits
cleared.

 [The DR2D Chunks](../AmigaMail_Vol2_guide/node00E1.html)                          [The Object Chunks](../AmigaMail_Vol2_guide/node00F1.html) 
 [The Global Drawing Attribute Chunks](../AmigaMail_Vol2_guide/node00E4.html)      [A Simple DR2D Example](../AmigaMail_Vol2_guide/node00F7.html) 
 [The Object Attribute Chunks](../AmigaMail_Vol2_guide/node00ED.html)              [The OFNT FORM](../AmigaMail_Vol2_guide/node00F8.html) 

