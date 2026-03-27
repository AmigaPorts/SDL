/* Source: ADCD 2.1
 * Section: dos-library-getdeviceproc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-getdeviceproc.md
 */

    Finds the handler/filesystem to send packets regarding 'name' to.
    This may involve getting temporary locks.  It returns a structure
    that includes a lock and msgport to send to to attempt your operation.
    It also includes information on how to handle multiple-directory
    assigns (by passing the [DevProc](../Includes_and_Autodocs_2._guide/node0078.html#line418) back to GetDeviceProc() until it
    returns NULL).

    The initial call to GetDeviceProc() should pass NULL for devproc.  If
    after using the returned [DevProc](../Includes_and_Autodocs_2._guide/node0078.html#line418), you get an ERROR_OBJECT_NOT_FOUND,
    and (devproc->dvp_Flags & DVPF_ASSIGN) is true, you should call
    GetDeviceProc() again, passing it the devproc structure.  It will
    either return a modified devproc structure, or NULL (with
    ERROR_NO_MORE_ENTRIES in IoErr()).  Continue until it returns NULL.

    This call also increments the counter that locks a handler/fs into
    memory.  After calling [FreeDeviceProc()](../Includes_and_Autodocs_2._guide/node02B0.html), do not use the port or lock
    again!
