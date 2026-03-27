# 23 Exec Lists and Queues


The Amiga system software operates in a dynamic environment of data
structures.  An early design goal of Exec was to keep the system flexible
and open-ended by eliminating artificial boundaries on the number of
system structures used.  Rather than using static system tables, Exec uses
dynamically created structures that are added and removed as needed.
These structures can be put in an unordered list, or in an ordered list
known as a queue.  A list can be empty, but never full.  This concept is
central to the design of Exec.  Understanding lists and queues is
important to understanding not only Exec itself, but also the mechanism
behind the Amiga's message and port based interprocess communication.

Exec uses lists to maintain its internal database of system structures.
Tasks, interrupts, libraries, devices, messages, I/O requests, and all
other Exec data structures are supported and serviced through the
consistent application of Exec's list mechanism.  Lists have a common data
structure, and a common set of functions is used for manipulating them.
Because all of these structures are treated in a similar manner, only a
small number of list handling functions need be supported by Exec.

 [List Structure](../Libraries_Manual_guide/node02D8.html)    [List Functions](../Libraries_Manual_guide/node02DD.html)    [Function Reference](../Libraries_Manual_guide/node02E9.html) 

