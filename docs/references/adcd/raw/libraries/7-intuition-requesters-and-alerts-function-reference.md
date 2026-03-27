# 7 Intuition Requesters and Alerts / Function Reference


The following are brief descriptions of the Intuition functions that
relate to the use of Intuition requesters and alerts.  See the Amiga ROM
Kernel Reference Manual: Includes and Autodocs for details on each
function call.

         Table 7-1: Functions for Intuition Requesters and Alerts
  ________________________________________________________________________
 |                                                                        |
 |          Function                   Description                        |
 |========================================================================|
 |               [Request()](../Includes_and_Autodocs_2._guide/node0249.html)  Open a requester in an open window.           |
 |            [EndRequest()](../Includes_and_Autodocs_2._guide/node0214.html)  Close an open requester in a window.          |
 |         [InitRequester()](../Includes_and_Autodocs_2._guide/node0221.html)  Clear a requester structure before use.       |
 |------------------------------------------------------------------------|
 |       [EasyRequestArgs()](../Includes_and_Autodocs_2._guide/node0212.html)  Open a [system](../Libraries_Manual_guide/node01AF.html) requester.                      |
 |           [EasyRequest()](../Includes_and_Autodocs_2._guide/node0212.html)  Alternate calling sequence for                |
 |                          EasyRequestArgs().                            |
 |  [BuildEasyRequestArgs()](../Includes_and_Autodocs_2._guide/node0201.html)  Low level function to open an EasyRequester.  |
 |      [BuildEasyRequest()](../Includes_and_Autodocs_2._guide/node0201.html)  Alternate calling sequence for                |
 |                          BuildEasyRequestArgs().                       |
 |         [SysReqHandler()](../Includes_and_Autodocs_2._guide/node025B.html)  Event handler function for EasyRequestArgs(). |
 |------------------------------------------------------------------------|
 |           [AutoRequest()](../Includes_and_Autodocs_2._guide/node01FF.html)  Open a pre-V36 system requester.              |
 |       [BuildSysRequest()](../Includes_and_Autodocs_2._guide/node0202.html)  Low level function to open an AutoRequest().  |
 |        [FreeSysRequest()](../Includes_and_Autodocs_2._guide/node0219.html)  Low level function to close an AutoRequest(). |
 |------------------------------------------------------------------------|
 |          [SetDMRequest()](../Includes_and_Autodocs_2._guide/node0250.html)  Set a [double menu](../Libraries_Manual_guide/node01A9.html) requester for an open       |
 |                          window.                                       |
 |        [ClearDMRequest()](../Includes_and_Autodocs_2._guide/node0204.html)  Clear a double menu requester from an open    |
 |                          window.                                       |
 |------------------------------------------------------------------------|
 |          [DisplayAlert()](../Includes_and_Autodocs_2._guide/node020B.html)  Open an alert on the screen.                  |
 |________________________________________________________________________|

