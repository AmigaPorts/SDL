# 32 / The Expansion Sequence / Simple Expansion Library Example


The following example uses [FindConfigDev()](../Includes_and_Autodocs_2._guide/node03B4.html) to print out information about
all of the configured expansion peripherals in the system.
FindConfigDev() searches the system's list of [ConfigDev](../Libraries_Manual_guide/node0416.html#line6) structures and
returns a pointer to the ConfigDev structure matching a specified board:


```c
    newconfigdev = struct ConfigDev *
                       FindConfigDev( struct ConfigDev *oldconfigdev,
                                      LONG manufacturer, LONG product )
```
The oldconfigdev argument may be set to NULL to begin searching at the top
of the system list or, if it points to a valid [ConfigDev](../Libraries_Manual_guide/node0416.html#line6), searching will
begin after that entry in the system list.  The manufacturer and product
arguments can be set to search for a specific manufacturer and product by
number, or, if these are set to -1, the function will match any board.


```c
     [findboards.c](../Libraries_Manual_guide/node0593.html) 
```
