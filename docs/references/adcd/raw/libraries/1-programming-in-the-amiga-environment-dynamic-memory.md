# 1 / Programming in the Amiga Environment / Dynamic Memory Architecture


Unlike some microcomputer operating systems, the Amiga OS relies on
absolute memory addresses as little as possible.  Instead the Amiga OS
uses a technique (sometimes referred to as soft machine architecture)
which allows system routines and data structures to be positioned anywhere
in memory.

Amiga [run-time](../Libraries_Manual_guide/node0010.html#line9) libraries may be positioned anywhere in memory because they
are always accessed through a jump table.  Each library whether in ROM or
loaded from disk has an associated Library structure and jump table in RAM.




                            Low Memory
                               /|\
                                |
                       _________|_________
                      |                   |
                      |  JMP Function  N  |
                      |         ·         |
                      |         ·         |
                      |  JMP Function  3  |
                      |  JMP Function  2  |
                      |  JMP Function  1  |
      Library Base____|___________________|
                      |                   |
                      | Library Structure |
                      |___________________|
                      |                   |
                      |     Data Area     |
                      |___________________|
                                |
                                |
                               \|/
                           High Memory


      Figure 1-2: Amiga Library Structure and Jump Table
The system knows where the jump table starts in RAM because when a library
is opened for the first time, [Exec](../Libraries_Manual_guide/node0013.html) creates the library structure and keeps
track of its location.  The order of the entries in the library's jump
table is always preserved between versions of the OS but the functions
they point to can be anywhere in memory.  Hence, system routines in ROM
may be moved from one version of the OS to another.  Given the location of
the jump table and the appropriate offset into the table, any function can
always be found.

Not only are system routines relocatable but system data structures are
too.  In the Amiga's [multitasking](../Libraries_Manual_guide/node000A.html) environment, multiple applications run
at the same time and each may have its own screen, memory, open files, and
even its own subtasks.  Since any number of application tasks are run and
stopped at the user's option, system data structures have to be set up as
needed.  They cannot be set up ahead of time at a fixed memory location
because there is no way to tell how many and what type will be needed.

The Amiga system software manages this confusion by using linked lists of
information about items such as libraries, tasks, screens, files and
available memory.  A linked list is a chain of data items with each data
item containing a pointer to the next item in the chain.  Given a pointer
to the first item in a linked list, pointers to all the other items in the
chain can be found.

 [Exec: The System Executive](../Libraries_Manual_guide/node0013.html) 

