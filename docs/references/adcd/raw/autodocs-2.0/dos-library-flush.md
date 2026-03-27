# dos.library/Flush



NAME

```c
    Flush -- Flushes buffers for a buffered filehandle (V36)
```
SYNOPSIS

```c
    success = Flush(fh)
    D0              D1

    LONG Flush(BPTR)
```
FUNCTION

```c
    Flushes any pending buffered writes to the filehandle.  All buffered
    writes will also be flushed on [Close()](../Includes_and_Autodocs_2._guide/node028A.html).  If the filehandle was being
    used for input, it drops the buffer, and tries to [Seek()](../Includes_and_Autodocs_2._guide/node02ED.html) back to the
    last read position  (so subsequent reads or writes will occur at the
    expected position in the file).
```
INPUTS

    fh      - Filehandle to flush.
RESULT

    success - Success or failure.
BUGS

```c
    Before V37 release, Flush() returned a random value.  As of V37,
    it always returns success (this will be fixed in some future
    release).
```
SEE ALSO

```c
    FputC(), [FGetC()](../Includes_and_Autodocs_2._guide/node02A2.html), [UnGetC()](../Includes_and_Autodocs_2._guide/node0305.html), [Seek()](../Includes_and_Autodocs_2._guide/node02ED.html), [Close()](../Includes_and_Autodocs_2._guide/node028A.html)
```
