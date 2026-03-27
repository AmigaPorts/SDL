# 14 / Device Interface / Closing The Trackdisk Device


As with all devices, you must close the trackdisk device when you have
finished using it. To release the device, a [CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html) call is executed
with the same [IOExtTD](../Devices_Manual_guide/node00DE.html#line12) used when the device was opened. This only closes
the device and makes it available to the rest of the system. It does not
deallocate the [IOExtTD](../Devices_Manual_guide/node00DE.html#line12) structure.


```c
    CloseDevice((struct IORequest *)DiskIO);
```
