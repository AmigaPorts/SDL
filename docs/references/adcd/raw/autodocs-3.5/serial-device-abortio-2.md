# serial.device/AbortIO



   NAME

```c
       AbortIO(ioRequest) -- abort an I/O request
               A1
```
   FUNCTION

```c
      This is an exec.library call.

      This function attempts to aborts a specified read or write request.
      If the request is active, it is stopped immediately. If the request is
      queued, it is painlessly removed.  The request will be returned
      in the same way any completed request it.

      After AbortIO(), you must generally do a [WaitIO()](../Includes_and_Autodocs_3._guide/node0247.html).
```
   INPUTS

```c
      iORequest  -- pointer to the [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) Block that is to be aborted.
```
   RESULTS

```c
       io_Error -- if the Abort succeded, then io_Error will be #IOERR_ABORTED

           (-2) and the request will be flagged as aborted (bit 5 of
           io_Flags is set).  If the Abort failed, then the Error will be zero.
```
   BUGS

```c
       Previous to version 34, the serial.device would often hang when
       aborting CTS/RTS handshake requests.  This was the cause of the
       incorrect assumption that AbortIO() does not need to be followed
       by a wait for a reply (or a WaitIO()).
```
