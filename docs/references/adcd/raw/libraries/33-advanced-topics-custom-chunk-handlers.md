# 33 / Advanced Topics / Custom Chunk Handlers


Like custom stream handlers, custom chunk handlers are implemented using
Release 2 [Hook](../Libraries_Manual_guide/node04A3.html) structures.  See the [previous section](../Libraries_Manual_guide/node0454.html) for details on how a
handler function may be interfaced using a Hook structure.

There are two types of chunk handlers:  entry handlers and exit handlers.
Entry handlers are invoked just after the parser enters the chunk; the
stream will be positioned to read the first byte in the chunk. (If the
chunk is a [FORM](../Libraries_Manual_guide/node042A.html#line7), [LIST](../Libraries_Manual_guide/node042A.html#line7), [CAT](../Libraries_Manual_guide/node042A.html#line7), or [PROP](../Libraries_Manual_guide/node042A.html#line7), the longword type will be read by the
parser; the stream will be positioned to read the byte immediately
following the type.)  Exit handlers are invoked just before the parser
leaves the chunk; the stream is not positioned predictably within the
chunk.

 [Installing a Custom Chunk Handler](../Libraries_Manual_guide/node0458.html) 
 [Inside a Custom Chunk Handler](../Libraries_Manual_guide/node0459.html) 
 [The Object Parameter](../Libraries_Manual_guide/node045A.html) 

