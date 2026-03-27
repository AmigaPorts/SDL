---
title: VII-1: The DR2D FORM
manual: amiga-mail
chapter: amiga-mail
section: vii-1-the-dr2d-form
functions: []
libraries: []
---

# VII-1: The DR2D FORM

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

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

 [The DR2D Chunks](amiga-mail/the-dr2d-chunks.md)                          [The Object Chunks](amiga-mail/the-object-chunks.md) 
 [The Global Drawing Attribute Chunks](amiga-mail/the-global-drawing-attribute-chunks.md)      [A Simple DR2D Example](amiga-mail/a-simple-dr2d-example.md) 
 [The Object Attribute Chunks](amiga-mail/the-object-attribute-chunks.md)              [The OFNT FORM](amiga-mail/the-ofnt-form.md) 

