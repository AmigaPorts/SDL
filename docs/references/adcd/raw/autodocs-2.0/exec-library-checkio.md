# exec.library/CheckIO



NAME

```c
    CheckIO -- get the status of an [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19)
```
SYNOPSIS

```c
    result = CheckIO(iORequest)
    D0               A1

    BOOL CheckIO(struct [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) *);
```
FUNCTION

```c
    This function determines the current state of an I/O request and
    returns FALSE if the I/O has not yet completed.  This function
    effectively hides the internals of the I/O completion mechanism.

    CheckIO() will NOT remove the returned [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) from the reply port.
    This is best performed with [WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html). If the request has already
    completed, [WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html) will return quickly. Use of the [Remove()](../Includes_and_Autodocs_2._guide/node0373.html)
    function is dangerous, since other tasks may still be adding things
    to your message port; a [Disable()](../Includes_and_Autodocs_2._guide/node034A.html) would be required.

    This function should NOT be used to busy loop (looping until IO is
    complete).  [WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html) is provided for that purpose.
```
INPUTS

    iORequest - pointer to an I/O request block
RESULTS

```c
    result - NULL if I/O is still in progress.  Otherwise
             D0 points to the [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block.
```
NOTE

```c
    CheckIO can hang if called on an [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) that has never been used.
    This occurs if LN_TYPE of the [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) is set to "NT_MESSAGE".
    Instead simply set LN_TYPE to 0.
```
SEE ALSO

```c
    [DoIO](../Includes_and_Autodocs_2._guide/node034B.html), [SendIO](../Includes_and_Autodocs_2._guide/node037A.html), [WaitIO](../Includes_and_Autodocs_2._guide/node038B.html), [AbortIO](../Includes_and_Autodocs_2._guide/node04F7.html)
```
