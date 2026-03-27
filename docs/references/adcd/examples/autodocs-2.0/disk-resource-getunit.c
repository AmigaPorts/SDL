/* Source: ADCD 2.1
 * Section: disk-resource-getunit
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/disk-resource-getunit.md
 */

    This routine allocates the disk to a driver.  It is either
    immediately available, or the request is saved until the disk
    is available.  When it is available, your unitPointer is
    sent back to you (via ReplyMsg).  You may then reattempt the
    GetUnit.

    Allocating the disk allows you to use the disk's resources.
    [Remember](../Includes_and_Autodocs_2._guide/node00D4.html#line1233) however that there are four units to the disk; you are
    only one of them.  Please be polite to the other units (by never
    selecting them, and by not leaving interrupts enabled, etc.).

    When you are done, please leave the disk in the following state:
        dmacon dma bit ON
        dsklen dma bit OFF (write a #DSKDMAOFF to dsklen)
        adkcon disk bits -- any way you want
        entena:disk sync and disk block interrupts -- Both DISABLED
        [CIA](../Includes_and_Autodocs_2._guide/node00C7.html#line30) resource index interrupt -- DISABLED
        8520 outputs -- doesn't matter, because all bits will be
            set to inactive by the resource.
        8520 data direction regs -- restore to original state.

    NOTE: GetUnit() does NOT turn on the interrupts for you.
          You must use [AbleICR](../Includes_and_Autodocs_2._guide/node0536.html) (for the index interrupt) or intena
          (for the diskbyte and diskblock interrupts) to turn them
          on.  You should turn them off before calling [GiveUnit](../Includes_and_Autodocs_2._guide/node054A.html),
          as stated above.
