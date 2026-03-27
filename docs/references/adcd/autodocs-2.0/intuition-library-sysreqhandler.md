---
title: intuition.library/SysReqHandler
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-sysreqhandler
functions: [AutoRequest, BuildSysRequest, FreeSysRequest, SysReqHandler, WaitPort]
libraries: [exec.library, intuition.library]
---

# intuition.library/SysReqHandler

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SysReqHandler -- Handle system requester input. (V36)
```
SYNOPSIS

```c
    num = SysReqHandler( [Window](autodocs-2.0/includes-intuition-intuition-h.md), IDCMPFlagsPtr, WaitInput )
    D0                   A0      A1             D0

    LONG SysReqHandler( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *, ULONG *, BOOL );
```
FUNCTION

```c
    Handles input for a window returned by either [BuildSysRequest()](autodocs-2.0/intuition-library-buildsysrequest.md)
    or BuildEasyRequest().  These functions with SysReqHandler()
    you can perform an "asynchronous" EasyRequest() or [AutoRequest()](autodocs-2.0/intuition-library-autorequest.md).
    That is to say, you can perform other processing while you
    wait for the requester to be satisfied.

    Each time this function is called, it will process all
    IDCMPMessages that the window has received.  If the parameter
    'WaitInput' is non-zero, SysReqHandler() will wait for input
    (by calling [WaitPort()](autodocs-2.0/exec-library-waitport.md)) if there are no IDCMP messages.

    SysReqHandler() returns the same values as EasyRequest(): A gadget
    ID greater than equal to 0, and  -1 if one of the other IDCMP
    events were received.

    An additional value of -2 is returned if the input processed
    does not satisfy the requester.  In this case, you might
    perform some processing and call SysReqHandler() again.

    Note: this function does NOT terminate the system request.
    Not only must you call [FreeSysRequest()](autodocs-2.0/intuition-library-freesysrequest.md) to eliminate the request,
    but you may also continue processing after an event which would
    normally terminate a normal call to EasyRequest().
```
EXAMPLE

```c
    Implementation of EasyRequest() input loop:

    window = BuildEasyRequest( ZZZZ )
    while ( (retval = SysReqHandler( window, idcmp_ptr, TRUE )) == -2 )
    {
        /* loop     */;
    }
    FreeSysRequest( window );
```
EXAMPLE

```c
    Request a volume, but don't remove the requester when the
    user inserts the wrong disk:

    struct [EasyStruct](autodocs-2.0/includes-intuition-intuition-h.md) volumeES = {
        sizeof (struct EasyStruct),
        0,
        "Volume Request",
        "Please insert volume %s in any drive.",
        "Cancel"
    };

    Volume *
    getVolume( volname )
    UBYTE   *volname;
    {
        struct [Window](autodocs-2.0/includes-intuition-intuition-h.md)       *window;
        Volume              *volume = NULL;
        Volume              *findVolume();
        int                 retval;

        window = BuildEasyRequest( NULL, &volumeES, IDCMP_DISKINSERTED,
                  volname );

        while ( (retval = SysReqHandler( window, NULL, TRUE )) != 0 )
        {
            /* not cancelled yet    */

            /* when IDCMP_DISKINSERTED, check for volume */
            if (( retval == -1 ) && (volume = findVolume( volname )))
                break;
        }
        FreeSysRequest( window );
        return ( volume );
    }
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = [Window](autodocs-2.0/includes-intuition-intuition-h.md) pointer returned from [BuildSysRequest()](autodocs-2.0/intuition-library-buildsysrequest.md) or
            BuildEasyRequest().  Those functions can also return
            values '0' or '1', and these values may also be
            passed to SysReqHandler(), which will immediately
            return the same value.

    IDCMPFlagsPtr = If you passed application specific IDCMP
            flags to [BuildSysRequest()](autodocs-2.0/intuition-library-buildsysrequest.md) or BuildEasyRequest(),
            SysReqHandler() will return -1 if that IDCMP message
            is received.  If IDCMPFlagsPtr is non-null, it
            points to a ULONG where the IDCMP class received
            will be copied for your examination.

            This pointer can be NULL if you have provided no
            application specific IDCMP flags or if you do
            not need to know which application specific IDCMP
            event occurred.

            If you provide more than on flag in the flags variable
            this pointer points to, you will have to refresh
            the variable whenever -1 is returned, since the
            variable will have been changed to show just the
            single IDCMP Class bit that caused the return.

    WaitInput = Specifies that you want SysReqHandler() to
            to wait for IDCMP input if there is none pending.
```
RESULT

```c
    0, 1, ..., N = Successive GadgetID values, for the gadgets
        you specify for the requester.  NOTE: The numbering
        from left to right is actually: 1, 2, ..., N, 0.
        This is for compatibility with AutoRequests which has
        FALSE for the rightmost gadget.

    -1 = Means that one of the caller-supplied IDCMPFlags occurred.
        The IDCMPFlag value is in the longword pointed to by UDCMP_ptr.

    -2 = input processed did not satisfy the requester. One example
        is a keystroke that does not satisfy the requester.  Another
        example is if there is no input pending and you specified
        FALSE for WaitInput.
```
BUGS

SEE ALSO

```c
    [exec.library/WaitPort()](autodocs-2.0/exec-library-waitport.md)
```

---

## See Also

- [AutoRequest — intuition.library](../autodocs/intuition.library.md#autorequest)
- [BuildSysRequest — intuition.library](../autodocs/intuition.library.md#buildsysrequest)
- [FreeSysRequest — intuition.library](../autodocs/intuition.library.md#freesysrequest)
- [SysReqHandler — intuition.library](../autodocs/intuition.library.md#sysreqhandler)
- [WaitPort — exec.library](../autodocs/exec.library.md#waitport)
