/* Source: ADCD 2.1
 * Section: expansion-library-makedosnode
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/expansion-library-makedosnode.md
 */

    This routine manufactures the data structures needed to enter
    a dos disk device into the system.  This consists of a [DeviceNode](../Includes_and_Autodocs_2._guide/node0066.html#line100),
    a [FileSysStartupMsg](../Includes_and_Autodocs_2._guide/node0066.html#line85), a disk environment vector, and up to two
    bcpl strings.  See the [libraries/dosextens.h](../Includes_and_Autodocs_2._guide/node00EB.html) and
    libraries/filehandler.h include files for more information.

    MakeDosNode will allocate all the memory it needs, and then
    link the various structure together.  It will make sure all
    the structures are long-word aligned (as required by the DOS).
    It then returns the information to the user so he can
    change anything else that needs changing.  Typically he will
    then call [AddDosNode()](../Includes_and_Autodocs_2._guide/node03B0.html) to enter the new device into the dos
    tables.
