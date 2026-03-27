---
title: A / IFF Third Party Public Form and Chunk Specification / TDDD.doc
manual: devices
chapter: devices
section: a-iff-third-party-public-form-and-chunk-specification-tddd
functions: []
libraries: []
---

# A / IFF Third Party Public Form and Chunk Specification / TDDD.doc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

3-D rendering data, Turbo Silver (Impulse)

                               FORM TDDD
                               ---------
FORM TDDD is used by Impulse's Turbo Silver 3.0 for 3D rendering data.
TDDD stands for "3D data description".  The files contain object and
(optionally) observer data.

Turbo Silver's successor, "Imagine", uses an upgraded FORM TDDD when it
reads/writes object data.

Currently, in "standard IFF" terms, a FORM TDDD has only two chunk types:
an INFO chunk describing observer data;  and an OBJ chunk describing an
object heirarchy.  The INFO chunk appears only in Turbo Silver's "cell"
files, and the OBJ chunk appears in both "cell" files and "object" files.

The FORM has an (optional) INFO chunk followed by some number of OBJ
chunks.  (Note:  OBJ is followed by a space - ckID = "OBJ ")

The INFO and OBJ chunks, in turn, are made up of smaller chunks with the
standard IFF structure:  <ID> <data-size> <data>.

The INFO "sub-chunks" are relatively straightforward to interpret.

The OBJ "sub-chunks" support object heirarchies, and are slightly more
difficult to interpret.  Currently, there are 3 types of OBJ sub-chunks:
an EXTR chunk, describing an "external" object in a seperate file; a DESC
chunk, describing one node of a heirarchy; and a TOBJ chunk marking the
end of a heirarchy chain.  For each DESC chunk, there must be a
corresponding TOBJ chunk.  And an EXTR chunk is equivalent to a DESC/TOBJ
pair.

In Turbo Silver and Imagine, the structure of the object heirarchy is as
follows.  There is a head object, and its (sexist) brothers. Each brother
may have child objects.  The children may have grandchildren, and so on.
The brother nodes are kept in a doubly linked list, and each node has a
(possibly NULL) pointer to a doubly linked "child" list. The children
point to the "grandchildren" lists, and so on.  (In addition, each node
has a "back" pointer to its parent).

Each of the "head" brothers is written in a seperate OBJ chunk, along with
all its descendants.  The descendant heirarchy is supported as follows:


```c
    for each node of a doubly linked list,

    1)  A DESC chunk is written, describing its object.
    2)  If it has children, steps 1) to 3) are performed
            for each child.
    3)  A TOBJ chunk is written, marking the end of the children.
```
For "external" objects, steps 1) to 3) are not performed, but an EXTR
chunk is written instead.  (This means that an external object cannot have
children unless they are stored in the same "external" file).

The TOBJ sub-chunks have zero size -- and no data.  The DESC and EXTR
sub-chunks are made up of "sub-sub-chunks", again, with the standard IFF
structure:  <ID> <data-size> <data>.

( "External" objects were used by Turbo Silver to allow a its "cell" data
files to refer to an "object" data file that is "external" to the cell
file.  Imagine abandons the idea of individual cell files, and deals only
in TDDD "object" files. Currently, Imagine does not support EXTR chunks in
TDD files.)

Reader software WILL FOLLOW the standard IFF procedure of skipping over
any un-recognized chunks -- and "sub-chunks" or "sub-sub-chunks". The
<data-size> field indicates how many bytes to skip.  In addition it WILL
OBSERVE the IFF rule that an odd <data-size> may appear, in which case the
corredponding <data> field will be padded at the end with one extra byte
to give it an even size.

 [Now, on with the details](devices/tddd-doc-now-on-with-the-details.md) 

