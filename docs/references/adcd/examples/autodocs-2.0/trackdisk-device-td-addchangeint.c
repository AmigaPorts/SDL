/* Source: ADCD 2.1
 * Section: trackdisk-device-td-addchangeint
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/trackdisk-device-td-addchangeint.md
 */

    This command lets you add a software interrupt handler to the
    disk device that gets invoked whenever a disk insertion or removal
    occurs.

    You must pass in a properly initialized Exec [Interrupt](../Includes_and_Autodocs_2._guide/node008C.html#line23) structure
    and be prepared to deal with disk insertions/removals
    immediately. From within the interrupt handler, you may only call the
    status commands that can use IOF_QUICK.

    To set up the handler, an [Interrupt](../Includes_and_Autodocs_2._guide/node008C.html#line23) structure must be initialized.
    This structure is supplied as the io_Data to the TD_ADDCHANGEINT
    command. The handler then gets linked into the handler chain and
    gets invoked whenever a disk change happens. You must eventually
    remove the handler before you exit.

    This command only returns when the handler is removed. That is,
    the device holds onto the IO request until the [TD_REMCHANGEINT](../Includes_and_Autodocs_2._guide/node052F.html) command
    is executed with that same IO request. Hence, you must use [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html)
    with this command.
