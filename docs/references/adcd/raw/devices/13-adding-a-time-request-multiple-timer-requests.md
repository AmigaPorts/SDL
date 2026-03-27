# 13 / Adding a Time Request / Multiple Timer Requests


Multiple requests may be posted to the timer driver. For example, you can
make three timer requests in a row:


```c
    Signal me in 20 seconds (request 1)
    Signal me in 30 seconds (request 2)
    Signal me in 10 seconds (request 3)
```
As the timer queues these requests, it changes the time values and sorts
the timer requests to service each request at the desired interval,
resulting effectively in the following order:


```c
    (request 3) in now+10 seconds
    (request 1) 10 seconds after request 3 is satisfied
    (request 2) 10 seconds after request 1 is satisfied
```
If you wish to send out multiple timer requests, you have to create
multiple request blocks. You can do this by allocating memory for each
[timerequest](../Devices_Manual_guide/node00BF.html#line16) you need and filling in the appropriate fields with command
data.  Some fields are initialized by the call to the [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)
function.  So, for convenience, you may allocate memory for the
[timerequest](../Devices_Manual_guide/node00BF.html#line16) you need, call [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html) with one of them, and then copy
the initialized fields into all the other [timerequest](../Devices_Manual_guide/node00BF.html#line16).

It is also permissible to open the timer device multiple times.  In some
cases this may be easier than opening it once and using multiple requests.
When multiple requests are given, [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html) should be used to transmit each
one to the timer.


```c
     [Multiple_Timers.c](../Devices_Manual_guide/node0198.html) 
```
If all goes according to plan, TimerIO[1] will finish first, TimerIO[2]
will finish next, and TimerIO[0] will finish last.

