# 31 Commodities Exchange Library / CxObject Errors


A Commodities Exchange function that acts on a [CxObject](../Libraries_Manual_guide/node0407.html) records errors in
the CxObject's accumulated error field.  The function [CxObjError()](../Includes_and_Autodocs_2._guide/node01A6.html) returns
a CxObject's error field.


```c
    co_errorfield = LONG CxObjError( CxObj *co );
```
Each bit in the error field corresponds to a specific type of error.  The
following is a list of the currently defined [CxObject errors](../Includes_and_Autodocs_2._guide/node00F0.html#line156) and their
corresponding bit mask constants.




```c
    Error Constant    Meaning
    --------------    -------
    COERR_ISNULL      [CxObjError()](../Includes_and_Autodocs_2._guide/node01A6.html) was passed a NULL.
    COERR_NULLATTACH  Someone tried to attach a NULL [CxObject](../Libraries_Manual_guide/node0407.html) to this
                      CxObject.
    COERR_BADFILTER   This [filter CxObject](../Libraries_Manual_guide/node0407.html) currently has an invalid
                      filter description.
    COERR_BADTYPE     Someone tried to perform a type specific function
                      on the wrong type of [CxObject](../Libraries_Manual_guide/node0407.html) (for example calling
                      [SetFilter()](../Libraries_Manual_guide/node0410.html#line66) on a [sender CxObject](../Libraries_Manual_guide/node0409.html)).
```
The remaining bits are reserved for future use.  [HotKey.c](../Libraries_Manual_guide/node0587.html)
checks the error field of its [filter CxObject](../Libraries_Manual_guide/node0407.html) to make sure the filter is
valid.  HotKey.c does not need to check the other objects with
[CxObjError()](../Includes_and_Autodocs_2._guide/node01A6.html) because it already makes sure that these other objects are
not NULL, which is the only other kind of error the other objects can
cause in this situation.

Commodities Exchange has a function that clears a [CxObject](../Libraries_Manual_guide/node0407.html)'s accumulated
error field, [ClearCxObjError()](../Includes_and_Autodocs_2._guide/node01A0.html).


```c
    void ClearCxObjError( CxObj *co );
```
A commodity should be careful about using this, especially on a [filter](../Libraries_Manual_guide/node0403.html).
If a commodity clears a filter's error field and the COERR_BADFILTER bit
is set, Commodities Exchange will think that the filter is OK and start
sending messages through it.

