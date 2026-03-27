# 33 / / Custom Chunk Handlers / Installing a Custom Chunk Handler


To install an entry handler, you call [EntryHandler()](../Includes_and_Autodocs_2._guide/node01BF.html) in the following
manner:


```c
    error = EntryHandler (iff, type, id, position, hookptr, object);
```
An exit handler is installed by saying:


```c
    error = ExitHandler (iff, type, id, position, hookptr, object);
```
In both cases, a handler is installed for chunks having the specified type
and id.  The position argument specifies in what context to install the
handler, and is identical to the position argument used by
[StoreLocalItem()](../Libraries_Manual_guide/node044E.html).  The hookptr argument given above is a pointer to your
[Hook](../Libraries_Manual_guide/node04A3.html) structure.

