# 19 Exec Device I/O / Function Reference


The following chart gives a brief description of the Exec functions that
control device I/O.  See the Amiga ROM Kernel Reference Manual: Includes
and Autodocs for details about each call.


                  Table 19-4: Exec Device I/O Functions
  ______________________________________________________________________
 |                                                                      |
 |     Exec Device                                                      |
 |     I/O Function                  Description                        |
 |======================================================================|
 |  [CreateIORequest()](../Includes_and_Autodocs_2._guide/node0344.html)  Create an [IORequest](../Libraries_Manual_guide/node029D.html) structure (V36).             |
 |  [DeleteIORequest()](../Includes_and_Autodocs_2._guide/node0348.html)  Delete an IORequest created by CreateIORequest() |
 |                     (V36).                                           |
 |       [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)  Gain access to an Exec device.                   |
 |      [CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html)  Close Exec device opened with OpenDevice().      |
 |             [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html)  Perform a device I/O command and wait for        |
 |                     completion.                                      |
 |           [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html)  Initiate an I/O command.  Do not wait for it to  |
 |                     complete.                                        |
 |          [CheckIO()](../Includes_and_Autodocs_2._guide/node033E.html)  Get the status of an IORequest.                  |
 |           [WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html)  Wait for completion of an I/O request.           |
 |          [AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html)  Attempt to abort an I/O request that is in       |
 |                     progress.                                        |
 |______________________________________________________________________|


             Table 19-5: Exec Support Functions in amiga.lib
  ______________________________________________________________________
 |                                                                      |
 |        Function                   Description                        |
 |======================================================================|
 |          [BeginIO()](../Includes_and_Autodocs_2._guide/node0141.html)  Initiate an asynchronous device I/O request.     |
 |      [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html)  Create an [IORequest](../Libraries_Manual_guide/node029D.html) data structure.              |
 |      [DeleteExtIO()](../Includes_and_Autodocs_2._guide/node0152.html)  Free an IORequest structure allocated by         |
 |                     CreateExtIO().                                   |
 |______________________________________________________________________|

