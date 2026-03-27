# 31 Commodities Exchange Library / CxObjects


CxObjects are the basic building blocks used to construct a commodity.  A
commodity uses CxObjects to take care of all manipulations of [CxMessages](../Libraries_Manual_guide/node0403.html).
When a CxMessage "arrives" at a CxObject, that CxObject carries out its
primitive action and then, if it has not deleted the CxMessage, it passes
the CxMessage on to the next CxObject.  A commodity links together
CxObjects into a tree, organizing these simple action objects to perform
some higher function.

A CxObject is in one of two states, active or inactive.  An active
CxObject performs its primitive action every time it receives a [CxMessage](../Libraries_Manual_guide/node0403.html).
If a CxObject is inactive, CxMessages bypass it, continuing to the
CxObject that follows the inactive one.  By default, all CxObjects except
the type called brokers are created in the active state.

Currently, there are seven types of CxObjects (Table 31-1).


   Object Type   Purpose
   -----------   -------

```c
    [Broker](../Libraries_Manual_guide/node0402.html)       Registers a new commodity with the commodity network
    [Filter](../Libraries_Manual_guide/node0407.html)       Accepts or rejects input events based on criteria set
                 up by the application
    [Sender](../Libraries_Manual_guide/node0409.html)       Sends a message to a message port
    [Translate](../Libraries_Manual_guide/node040A.html)    Replaces the input event with a different one
    [Signal](../Libraries_Manual_guide/node040D.html)       Signals a task
    [Custom](../Libraries_Manual_guide/node040E.html)       Calls a custom function provided by the commodity
    [Debug](../Libraries_Manual_guide/node040F.html)        Sends debug information out the serial port


                 Table 31-1: Commodities Exchange Object Types
```
