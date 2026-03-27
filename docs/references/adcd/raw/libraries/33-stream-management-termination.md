# 33 / Stream Management / Termination


Termination is simple.  Just call [CloseIFF](../Includes_and_Autodocs_2._guide/node01BB.html)(iff).  This may be called at
any time, and terminates IFFParse's transaction with the stream.  The
stream itself is not closed.  The [IFFHandle](../Libraries_Manual_guide/node042C.html) may be reused; you may safely
call [OpenIFF()](../Libraries_Manual_guide/node042E.html#line55) on it again.  You are responsible for closing the streams
you opened.  A stream used in an IFFHandle must generally remain open
until you CloseIFF().

