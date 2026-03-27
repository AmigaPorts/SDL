/* Source: ADCD 2.1
 * Section: exec-library-remdevice
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-remdevice.md
 */

    This function calls the device's EXPUNGE vector, which requests
    that a device delete itself.  The device may refuse to do this if
    it is busy or currently open. This is not typically called by user
    code.

    There are certain, limited circumstances where it may be
    appropriate to attempt to specifically flush a certain device.
    Example:

     /* Attempts to flush the named device out of memory. */
     #include [<exec/types.h>](../Includes_and_Autodocs_2._guide/node0096.html)
     #include [<exec/execbase.h>](../Includes_and_Autodocs_2._guide/node009E.html)

     void FlushDevice(name)
     STRPTR name;
     {
     struct [Device](../Includes_and_Autodocs_2._guide/node0087.html#line25) *result;

        Forbid();
        if(result=(struct [Device](../Includes_and_Autodocs_2._guide/node0087.html#line25) *)FindName(&SysBase->DeviceList,name))
            RemDevice(result);
        Permit();
     }
