/* Source: ADCD 2.1
 * Section: 1-general-development-guidelines-hardware-programming
 * Library: libraries
 * ADCD reference: libraries/1-general-development-guidelines-hardware-programming.md
 */

    differently than 1.3 did.  To ensure compatibility, you must always
    ask for CIA access using the cia.resource [AddICRVector()](../Includes_and_Autodocs_2._guide/node0537.html) and
    [RemICRVector()](../Includes_and_Autodocs_2._guide/node0538.html) functions.  Do not make assumptions about what the
    system might be using the CIA chips for.  If you write directly to
    the CIA chip registers, do not expect system services such as the
    trackdisk device to function.  If you are leaving the system up, do
    not read or write to the CIA Interrupt Control Registers directly;
    use the cia.resource [AbleICR()](../Includes_and_Autodocs_2._guide/node0536.html), and [SetICR()](../Includes_and_Autodocs_2._guide/node0539.html) functions.  Even if you
    are taking over the machine, do not assume the initial contents of
    any of the CIA registers or the state of any enabled interrupts.
