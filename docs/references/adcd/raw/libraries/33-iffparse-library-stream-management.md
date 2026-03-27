# 33 IFFParse Library / Stream Management


A stream is a linear array of bytes that may be accessed sequentially or
randomly.  DOS files are streams.  IFFParse uses Release 2 [Hook](../Libraries_Manual_guide/node04A3.html) structures
(defined in <utility/[hooks.h](../Includes_and_Autodocs_2._guide/node012D.html)>) to implement a general stream management
facility.  This allows the IFFParse library to read, write, and seek any
type of file handle or device by using an application-provided hook
function to open, read, write, seek and close the stream.

Built on top of this facility, IFFParse has two internal stream managers:
one for unbuffered DOS files (AmigaDOS filehandles), and one for the
Clipboard.

 [Initialization](../Libraries_Manual_guide/node042E.html)    [Termination](../Libraries_Manual_guide/node042F.html)    [Custom Streams](../Libraries_Manual_guide/node0430.html) 

