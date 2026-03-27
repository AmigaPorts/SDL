# 12 / Alternative Modes for Serial Input or Output / High Speed Operation


The more characters that are processed in each I/O request, the higher the
total throughput of the device.  The following technique will minimize
device overhead for reads:

   *  Use the [SDCMD_QUERY](../Includes_and_Autodocs_2._guide/node04D6.html) command to get the number of characters currently

```c
      in the buffer (see the devices/[serial.h](../Includes_and_Autodocs_2._guide/node004B.html) Autodocs for information on
      SDCMD_QUERY).
```
   *  Use [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html) to read all available characters (or the maximum size of

```c
      your buffer).  In this case, [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html) is guaranteed to return without
      waiting.
```
   *  If zero characters are in the buffer, post an asynchronous request

```c
      ([SendIO()](../Includes_and_Autodocs_2._guide/node037A.html)) for 1 character.  When at least one is ready, the device
      will return it.  Now go back to the first step.
```
   *  If the user decides to quit the program, [AbortIO()](../Includes_and_Autodocs_2._guide/node04CA.html) any pending

      requests.
