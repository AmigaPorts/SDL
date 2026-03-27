# expansion.library/AddDosNode



NAME

    AddDosNode -- mount a disk to the system
SYNOPSIS

```c
    ok = AddDosNode( bootPri, flags, deviceNode )
    D0               D0       D1     A0

    BOOL AddDosNode( BYTE,ULONG,struct [DeviceNode](../Includes_and_Autodocs_2._guide/node0066.html#line100) *);
```
FUNCTION

```c
    This is the old (pre V36) function that works just like
    [AddBootNode()](../Includes_and_Autodocs_2._guide/node03AE.html).  It should only be used if you *MUST* work
    in a 1.3 system and you don't need to autoboot.
```
RESULTS

    ok - non-zero everything went ok, zero if we ran out of memory
        or some other weirdness happened.
EXAMPLE

```c
    /* enter a bootable disk into the system.  Start a file handler
    ** process immediately.
    */
    if(  AddDosNode( 0, ADNF_STARTPROC, MakeDosNode( paramPacket ) )  )
            ...AddDosNode ok...
```
BUGS

```c
    Before V36 Kickstart, no function existed to add BOOTNODES.
    If an older expansion.library is in use, driver code will need
    to manually construct a [BootNode](../Includes_and_Autodocs_2._guide/node00FA.html#line34) and [Enqueue()](../Includes_and_Autodocs_2._guide/node034D.html) it to eb_Mountlist.
    If you have a V36 or better expansion.library, your code should
    use [AddBootNode()](../Includes_and_Autodocs_2._guide/node03AE.html).
```
SEE ALSO

```c
    [MakeDosNode](../Includes_and_Autodocs_2._guide/node03B8.html), [AddBootNode](../Includes_and_Autodocs_2._guide/node03AE.html)
```
