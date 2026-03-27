# Standard File Structure / Rules for Reader Programs


Here are some notes on building programs that read IFF files.  For [LIST](../Devices_Manual_guide/node01CA.html#line49)
and [PROP](../Devices_Manual_guide/node01CA.html#line49) work, you should also read up on recursive descent parsers. [See,
for example, Compiler Construction, An Advanced Course.]

  o The standard is very flexible so many programs can exchange data.

     This implies a program has to scan the file and react to what's
     actually there in whatever order it appears.  An IFF reader program
     is a parser.
  o For interchange to really work, programs must be willing to do some

     conversion during read-in.  If the data isn't exactly what you expect,
     say, the raster is smaller than those created by your program, then
     adjust it.  Similarly, your program could crop a large picture, add
     or drop bitplanes, or create/discard a mask plane.  The program
     should give up gracefully on data that it can't convert.
  o If it doesn't start with "[FORM](../Devices_Manual_guide/node01C7.html#line52)", "[LIST](../Devices_Manual_guide/node01CA.html#line49)", or "[CAT](../Devices_Manual_guide/node01CA.html#line2) ", it's not an IFF-85

     file.
  o For any [chunk](../Devices_Manual_guide/node01DD.html) you encounter, you must recognize its type ID to

     understand its contents.
  o For any [FORM](../Devices_Manual_guide/node01C7.html#line52) [chunk](../Devices_Manual_guide/node01DD.html) you encounter, you must recognize its FORM type ID

```c
     to understand the contained "local chunks".  Even if you don't
     recognize the FORM type, you can still scan it for nested FORMs,
     [LIST](../Devices_Manual_guide/node01CA.html#line49)s, and [CAT](../Devices_Manual_guide/node01CA.html#line2) s of interest.
```
  o Don't forget to skip the implied pad byte after every odd-length [chunk](../Devices_Manual_guide/node01DD.html),

     this is not  included in the chunk count!
  o [Chunk](../Devices_Manual_guide/node01DD.html) types [LIST](../Devices_Manual_guide/node01CA.html#line49), [FORM](../Devices_Manual_guide/node01C7.html#line52), [PROP](../Devices_Manual_guide/node01CA.html#line49), and [CAT](../Devices_Manual_guide/node01CA.html#line2)  are generic groups.  They always

     contain a subtype ID followed by chunks.
  o Readers ought to handle a [CAT](../Devices_Manual_guide/node01CA.html#line2)  of [FORM](../Devices_Manual_guide/node01C7.html#line52)s in a file.  You may treat the

     FORMs like document pages to sequence through, or just use the first
     FORM.
  o Many  IFF readers completely skip [LIST](../Devices_Manual_guide/node01CA.html#line49)s.  "Fully IFF-conforming"

```c
     readers are those that handle LISTs, even if just to read the first
     [FORM](../Devices_Manual_guide/node01C7.html#line52) from a file.  If you do look into a LIST, you must process
     shared properties (in [PROP](../Devices_Manual_guide/node01CA.html#line49) [chunk](../Devices_Manual_guide/node01DD.html)s) properly.  The idea is to get the
     correct data or none at all.
```
  o The nicest readers are willing to look into unrecognized [FORM](../Devices_Manual_guide/node01C7.html#line52)s for

     nested FORM types that they do recognize.  For example, a musical
     score may contain nested instrument descriptions and animation or
     desktop publishing files may contain still pictures.   This extra
     step is highly recommended.
Note to programmers: Processing PROP [chunk](../Devices_Manual_guide/node01DD.html)s is not simple! You'll need
some background in interpreters with stack frames.  If this is foreign to
you, build programs that read/write only one [FORM](../Devices_Manual_guide/node01C7.html#line52) per file.  For the more
intrepid programmers, the next paragraph summarizes how to process [LIST](../Devices_Manual_guide/node01CA.html#line49)s
and [PROP](../Devices_Manual_guide/node01CA.html#line49)s.

Allocate a stack frame for every [LIST](../Devices_Manual_guide/node01CA.html#line49) and [FORM](../Devices_Manual_guide/node01C7.html#line52) you encounter and
initialize it by copying the stack frame of the parent LIST or FORM.  At
the top level, you'll need a stack frame initialized to your program's
global defaults. While reading each LIST or FORM, store all encountered
properties into the current stack frame.  In the example ShowILBM, each
stack frame has a place for a bitmap header property ILBM.[BMHD](../Devices_Manual_guide/node01AF.html) and a color
map property ILBM.[CMAP](../Devices_Manual_guide/node01B0.html). When you finally get to the ILBM's [BODY](../Devices_Manual_guide/node01B7.html) [chunk](../Devices_Manual_guide/node01DD.html), use
the property settings accumulated in the current stack frame.

An alternate implementation would just remember [PROP](../Devices_Manual_guide/node01CA.html#line49)s encountered,
forgetting each on reaching the end of its scope (the end of the
containing [LIST](../Devices_Manual_guide/node01CA.html#line49)).  When a [FORM](../Devices_Manual_guide/node01C7.html#line52) XXXX is encountered, scan the [chunk](../Devices_Manual_guide/node01DD.html)s in all
remembered [PROP](../Devices_Manual_guide/node01CA.html#line49)s XXXX, in order, as if they appeared before the chunks
actually in the FORM XXXX.  This gets trickier if you read FORMs inside of
FORMs.

