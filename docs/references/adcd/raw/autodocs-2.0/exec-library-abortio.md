# exec.library/AbortIO



NAME

    AbortIO - attempt to abort an in-progress I/O request
SYNOPSIS

```c
    AbortIO(iORequest)
            A1

    VOID AbortIO(struct [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) *);
```
FUNCTION

```c
    Ask a device to abort a previously started [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19).  This is done
    by calling the device's ABORTIO vector, with your given [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19).


    AbortIO is a command the device that may or may not grant.  If
    successful, the device will stop processing the [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19), and
    reply to it earlier than it would otherwise have done.
```
NOTE

```c
    AbortIO() does NOT [Remove()](../Includes_and_Autodocs_2._guide/node0373.html) the [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) from your ReplyPort, OR
    wait for it to complete.  After an AbortIO() you must wait normally
    for the reply message before actually reusing the request.

    If a request has already completed when AbortIO() is called, no
    action is taken.
```
EXAMPLE

```c
        AbortIO(timer_request);
        WaitIO(timer_request);
        /* [Message](../Includes_and_Autodocs_2._guide/node0099.html#line48) is free to be reused */
```
INPUTS

```c
    iORequest - pointer to an I/O request block (must have been used
            at least once.  May be active or finished).
```
SEE ALSO

```c
    [WaitIO](../Includes_and_Autodocs_2._guide/node038B.html), [DoIO](../Includes_and_Autodocs_2._guide/node034B.html), [SendIO](../Includes_and_Autodocs_2._guide/node037A.html), [CheckIO](../Includes_and_Autodocs_2._guide/node033E.html)
```
