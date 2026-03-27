# 33 / / Other Parsing Modes / IFFPARSE_RAWSTEP


This mode causes the parser to progress through the stream step by step,
rather than in the automated fashion provided by [IFFPARSE_SCAN](../Libraries_Manual_guide/node0431.html).  In this
mode, [ParseIFF()](../Libraries_Manual_guide/node0432.html) will return upon every entry to and departure from a
context.

When the parser enters a context, [ParseIFF()](../Libraries_Manual_guide/node0432.html) will return zero.
[CurrentChunk()](../Libraries_Manual_guide/node0447.html) will report the type and ID of the chunk just entered, and
the stream will be positioned to read the first byte in the chunk.  When
entering a [FORM](../Libraries_Manual_guide/node042A.html#line7), [LIST](../Libraries_Manual_guide/node042A.html#line7), [CAT](../Libraries_Manual_guide/node042A.html#line7) or [PROP](../Libraries_Manual_guide/node042A.html#line7) chunk, the longword containing the type
(e.g., [ILBM](../Libraries_Manual_guide/node045D.html#line8), [FTXT](../Libraries_Manual_guide/node045D.html#line8), etc.) is read by the parser.  In this case, the stream
will be positioned to read the byte immediately following the type.)

When the parser leaves a context, [ParseIFF()](../Libraries_Manual_guide/node0432.html) will return the value
IFFERR_EOC.  This is not strictly an error, but an indication that you are
about to leave the current context.  [CurrentChunk()](../Libraries_Manual_guide/node0447.html) will report the type
and ID of the chunk you are about to leave.  The stream is not positioned
predictably within the chunk.

The parser does not call any installed chunk handlers when using this mode
(e.g., property chunks declared with [PropChunk()](../Libraries_Manual_guide/node0434.html) will not be collected).

See the example program, [Sift.c](../Libraries_Manual_guide/node05A0.html), for a demonstration of IFFPARSE_RAWSTEP.

