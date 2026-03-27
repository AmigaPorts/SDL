/* Source: ADCD 2.1
 * Section: cd-device-opendevice
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/cd-device-opendevice.md
 */

       UnitNumber - Normally zero; however, this is described as:
                    Ones digit      = [Unit](../Includes_and_Autodocs_3._guide/node05FB.html#line30) (SCSI unit number)
                    Tens digit      = LUN (disk within disk changer)
                    Hundreds digit  = Card number (SCSI card)
                    Thousands digit = Reserved (must be zero)
       [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17)  - Pointer to a struct(IOStdReq)
       flags      - Should be zero.
