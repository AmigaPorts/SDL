# cd.device/CloseDevice



   NAME

       CloseDevice - terminate access to the CD
   SYNOPSIS

```c
       CloseDevice(IORequest);
                   A1
```
   FUNCTION

```c
       This function will terminate access to the unit openned with
       [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html).
```
   INPUTS

```c
       iORequest - pointer to a struct(IOStdReq)
```
   RESULTS

   NOTES

   SEE ALSO

```c
       [OpenDevice()](../Includes_and_Autodocs_3._guide/node00BB.html)
```
