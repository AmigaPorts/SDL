# 10 / The Mouse / Mouse Usage Example


The example program below shows the use of [IDCMP_MOUSEBUTTONS](../Libraries_Manual_guide/node01DC.html),
[IDCMP_MOUSEMOVE](../Libraries_Manual_guide/node01DC.html#line23) and [DoubleClick()](../Includes_and_Autodocs_2._guide/node020E.html).  DoubleClick() is used to test the
interval between two times and determine if the interval is within the
user specified time for double clicking as set in the Preferences Input
editor.


```c
    BOOL DoubleClick( unsigned long sSeconds, unsigned long sMicros,
                      unsigned long cSeconds, unsigned long cMicros );
```
The sSeconds and sMicros arguments specify a timestamp value describing
the start of the double click time interval to be tested.  The cSeconds
and cMicros arguments specify a timestamp value describing the end of the
double click time interval to be tested.

[DoubleClick()](../Includes_and_Autodocs_2._guide/node020E.html) returns TRUE if the time interval was short enough to
qualify as a double-click.  A FALSE return indicates that the time
interval between presses took too long.  The button presses should be
treated as separate events in that case.


```c
     [mousetest.c](../Libraries_Manual_guide/node05A9.html) 
```
