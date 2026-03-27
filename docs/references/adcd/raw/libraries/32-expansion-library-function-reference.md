# 32 Expansion Library / Function Reference


The following are brief descriptions of the expansion library functions
that are useful for expansion device drivers and related applications.
See the Amiga ROM Kernel Reference Manual: Includes and Autodocs for the
complete descriptions of all the expansion library functions.


                 Table 32-2: Expansion Library Functions
  ______________________________________________________________________
 |                                                                      |
 |            Function                 Description                      |
 |======================================================================|
 |          [FindConfigDev()](../Includes_and_Autodocs_2._guide/node03B4.html)  Returns a pointer to the [ConfigDev](../Libraries_Manual_guide/node0416.html#line6)         |
 |                           structure of a given expansion device.     |
 |----------------------------------------------------------------------|
 |            [MakeDosNode()](../Includes_and_Autodocs_2._guide/node03B8.html)  Creates the DOS device node for disk and   |
 |                           similar expansion devices.                 |
 |             [AddDosNode()](../Includes_and_Autodocs_2._guide/node03B0.html)  Adds a DOS device node to the system.      |
 |            [AddBootNode()](../Includes_and_Autodocs_2._guide/node03AE.html)  Adds an [autobooting](../Libraries_Manual_guide/node041B.html) DOS device node to the |
 |                           system (V36).                              |
 |----------------------------------------------------------------------|
 |      [GetCurrentBinding()](../Includes_and_Autodocs_2._guide/node03B7.html)  Returns a pointer to the CurrentBinding    |
 |                           structure of a given device.               |
 |      [SetCurrentBinding()](../Includes_and_Autodocs_2._guide/node03BE.html)  Set up for reading the CurrentBinding with |
 |                           GetCurrentBinding().                       |
 |    [ObtainConfigBinding()](../Includes_and_Autodocs_2._guide/node03B9.html)  Protect the [ConfigDev](../Libraries_Manual_guide/node0416.html#line6) structure with a     |
 |                           semaphore.                                 |
 |   [ReleaseConfigBinding()](../Includes_and_Autodocs_2._guide/node03BC.html)  Release a semaphore on ConfigDev set up    |
 |                           with ObtainCurrentBinding().               |
 |______________________________________________________________________|

