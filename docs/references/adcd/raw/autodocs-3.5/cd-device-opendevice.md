# cd.device/OpenDevice



   NAME

```c
       OpenDevice - [Open](../Includes_and_Autodocs_3._guide/node0196.html) a CD unit for access
```
   SYNOPSIS

```c
       error = OpenDevice("cd.device", UnitNumber, [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17), flags);
       D0                 A0           D0          A1         D1
```
   FUNCTION

```c
       Opens the cd.device and creates an [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) for use in accessing
       the CD.
```
   INPUTS

```c
       UnitNumber - Normally zero; however, this is described as:
                    Ones digit      = [Unit](../Includes_and_Autodocs_3._guide/node05FB.html#line30) (SCSI unit number)
                    Tens digit      = LUN (disk within disk changer)
                    Hundreds digit  = Card number (SCSI card)
                    Thousands digit = Reserved (must be zero)
       [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17)  - Pointer to a struct(IOStdReq)
       flags      - Should be zero.
```
   RESULTS

```c
       error        0 = success, otherwise this is an error.
```
   NOTES

   SEE ALSO

```c
       [CloseDevice()](../Includes_and_Autodocs_3._guide/node00BA.html)
```
