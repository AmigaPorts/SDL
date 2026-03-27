/* Source: ADCD 2.1
 * Section: dos-library-deviceproc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-deviceproc.md
 */

    DeviceProc() returns the process identifier of the process which
    handles the device associated with the specified name. If no
    process handler can be found then the result is zero. If the name
    refers to an assign then a directory lock is returned in [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).
    This lock should not be UnLock()ed or Examine()ed (if you wish to do
    so, [DupLock()](../Includes_and_Autodocs_2._guide/node0297.html) it first).
