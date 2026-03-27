# Standard File Structure / Rules for Writer Programs


Here are some notes on building programs that write IFF files, which is
much easier than reading them.

   o An IFF file is a single [FORM](../Devices_Manual_guide/node01C7.html#line52), [LIST](../Devices_Manual_guide/node01CA.html#line49), or [CAT](../Devices_Manual_guide/node01CA.html#line2)  [chunk](../Devices_Manual_guide/node01DD.html).

   o Any IFF-85 file must start with the 4 characters "[FORM](../Devices_Manual_guide/node01C7.html#line52)", "[LIST](../Devices_Manual_guide/node01CA.html#line49)", or

```c
      "[CAT](../Devices_Manual_guide/node01CA.html#line2) ", followed by a LONG ckSize.  There should be no data after
      the [chunk](../Devices_Manual_guide/node01DD.html) end.
```
   o [Chunk](../Devices_Manual_guide/node01DD.html) types [LIST](../Devices_Manual_guide/node01CA.html#line49), [FORM](../Devices_Manual_guide/node01C7.html#line52), [PROP](../Devices_Manual_guide/node01CA.html#line49), and [CAT](../Devices_Manual_guide/node01CA.html#line2)  are generic.  They always

      contain a subtype ID followed by chunks.  These three IDs are
      universally reserved, as are "LIS1" through "LIS9", "FOR1" through
      "FOR9", "CAT1" through "CAT9", and "    ".
   o Don't forget to write a 0 pad byte after each odd-length [chunk](../Devices_Manual_guide/node01DD.html).

   o Do not try to edit a file that you don't know how to create.  Programs

```c
      may look into a file and copy out nested [FORM](../Devices_Manual_guide/node01C7.html#line52)s of types that they
      recognize, but they should not edit and replace the nested FORMs and
      not add or remove them.  Breaking these rules could make the
      containing structure inconsistent.  You may write a new file
      containing items you copied, or copied and modified, but don't copy
      structural parts you don't understand.
```
   o You must adhere to the syntax descriptions in Appendix A.  E.g., [PROP](../Devices_Manual_guide/node01CA.html#line49)s

```c
      may only appear inside [LIST](../Devices_Manual_guide/node01CA.html#line49)s.
```
There are at least four common techniques for writing an IFF group:

  (1)  build the data in a file mapped into virtual memory.
  (2)  build the data in memory blocks and use block I/O.
  (3)  stream write the data piecemeal and (don't forget!) random
```c
          access back to set the group (or [FORM](../Devices_Manual_guide/node01C7.html#line52))
          length count.
```
  (4)  make a preliminary pass to compute the length count then stream

          write the data.
Issue: The standard disallows "blind" [chunk](../Devices_Manual_guide/node01DD.html) copying for consistency
reasons. Perhaps we can define a ckID convention for chunks that are OK to
replicate without knowledge of the contents.  Any such chunks would need
to be internally consistent, and not be bothered by changed external
references.

Issue: Stream-writing an IFF [FORM](../Devices_Manual_guide/node01C7.html#line52) can be inconvenient.  With random access
files one can write all the [chunk](../Devices_Manual_guide/node01DD.html)s then go back to fix up the FORM size.
With stream access, the FORM size must be calculated before the file is
written. When compression is involved, this can be slow or inconvenient.
Perhaps we can define an "END " chunk.  The stream writer would use -1
($FFFFFFFF) as the FORM size.  The reader would follow each chunk, when
the reader reaches an "END ", it would terminate the last -1 sized chunk.
Certain new IFF FORMs could require that readers understand "END ".

