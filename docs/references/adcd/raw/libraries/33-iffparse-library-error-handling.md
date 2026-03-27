# 33 IFFParse Library / Error Handling


If at any time during reading or writing you encounter an error, the
[IFFHandle](../Libraries_Manual_guide/node042C.html) is left in an undefined state.  Upon detection of an error, you
should perform an abort sequence and [CloseIFF()](../Libraries_Manual_guide/node042F.html) the IFFHandle.  Once
CloseIFF() has been called, the IFFHandle is restored to normalcy and may
be reused.

