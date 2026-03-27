# 31 Commodities Exchange Library / Function Reference


The following are brief descriptions of the Commodities Exchange functions
covered in this chapter.  All of these functions require Release 2 or a
later version of the Amiga operating system.  See the Amiga ROM Kernel
Reference Manual: Includes and Autodocs for details on each function call.


              Table 31-2: Commodities Exchange Functions
  _____________________________________________________________________
 |                                                                     |
 |         Function              Description                           |
 |=====================================================================|
 |         [CxBroker()](../Includes_and_Autodocs_2._guide/node01A2.html)  Creates a [CxObject](../Libraries_Manual_guide/node0401.html) of type [Broker](../Libraries_Manual_guide/node0402.html).              |
 |         [CxFilter()](../Includes_and_Autodocs_2._guide/node014D.html)  Creates a CxObject of type [Filter](../Libraries_Manual_guide/node0407.html).              |
 |         [CxSender()](../Includes_and_Autodocs_2._guide/node014E.html)  Creates a CxObject of type [Sender](../Libraries_Manual_guide/node0409.html).              |
 |      [CxTranslate()](../Includes_and_Autodocs_2._guide/node0150.html)  Creates a CxObject of type [Translate](../Libraries_Manual_guide/node040A.html).           |
 |         [CxSignal()](../Includes_and_Autodocs_2._guide/node014F.html)  Creates a CxObject of type [Signal](../Libraries_Manual_guide/node040D.html).              |
 |         [CxCustom()](../Includes_and_Autodocs_2._guide/node014B.html)  Creates a CxObject of type [Custom](../Libraries_Manual_guide/node040E.html).              |
 |          [CxDebug()](../Includes_and_Autodocs_2._guide/node014C.html)  Creates a CxObject of type [Debug](../Libraries_Manual_guide/node040F.html).               |
 |      [DeleteCxObj()](../Includes_and_Autodocs_2._guide/node01A8.html)  Frees a single CxObject                         |
 |   [DeleteCxObjAll()](../Includes_and_Autodocs_2._guide/node01A9.html)  Frees a group of connected CxObjects            |
 |---------------------------------------------------------------------|
 |    [ActivateCxObj()](../Includes_and_Autodocs_2._guide/node019D.html)  Activates a newly created [CxObject](../Libraries_Manual_guide/node0401.html) in the       |
 |                     commodities network.                            |
 |---------------------------------------------------------------------|
 |     [SetTranslate()](../Includes_and_Autodocs_2._guide/node01B5.html)  Sets up substitution of one input event for     |
 |                     another by translate CxObjects.                 |
 |---------------------------------------------------------------------|
 |        [CxMsgType()](../Includes_and_Autodocs_2._guide/node01A5.html)  Finds the type of a [CxMessage](../Libraries_Manual_guide/node0403.html).                  |
 |        [CxMsgData()](../Includes_and_Autodocs_2._guide/node01A3.html)  Returns the CxMessage data.                     |
 |          [CxMsgID()](../Includes_and_Autodocs_2._guide/node01A4.html)  Returns the CxMessage ID.                       |
 |---------------------------------------------------------------------|
 |       [CxObjError()](../Includes_and_Autodocs_2._guide/node01A6.html)  Returns the [CxObject](../Libraries_Manual_guide/node0401.html)'s accumulated error field. |
 |  [ClearCxObjError()](../Includes_and_Autodocs_2._guide/node01A0.html)  Clear the CxObject's accumulated error field.   |
 |---------------------------------------------------------------------|
 |     [ArgArrayInit()](../Includes_and_Autodocs_2._guide/node013D.html)  Create a Tool Types array from argc and argv    |
 |                     (Workbench or Shell).                           |
 |     [ArgArrayDone()](../Includes_and_Autodocs_2._guide/node013C.html)  Free the resources used by ArgArrayInit().      |
 |        [ArgString()](../Includes_and_Autodocs_2._guide/node013F.html)  Return the string associated with a given Tool  |
 |                     Type in the array.                              |
 |           [ArgInt()](../Includes_and_Autodocs_2._guide/node013E.html)  Return the integer associated with a given Tool |
 |                     Type in the array.                              |
 |---------------------------------------------------------------------|
 |      [AttachCxObj()](../Includes_and_Autodocs_2._guide/node019F.html)  Attaches a [CxObject](../Libraries_Manual_guide/node0401.html) to the end of a given       |
 |                     CxObject's list.                                |
 |      [InsertCxObj()](../Includes_and_Autodocs_2._guide/node01AD.html)  Inserts a CxObject in a given position in a     |
 |                     CxObject's list.                                |
 |     [EnqueueCxObj()](../Includes_and_Autodocs_2._guide/node01AC.html)  Inserts a CxObject in a CxObject's list by      |
 |                     priority.                                       |
 |      [SetCxObjPri()](../Includes_and_Autodocs_2._guide/node01B2.html)  Sets a CxObject's priority for EnqueueCxObj().  |
 |      [RemoveCxObj()](../Includes_and_Autodocs_2._guide/node01B0.html)  Removes a CxObject from a list.                 |
 |---------------------------------------------------------------------|
 |        [SetFilter()](../Includes_and_Autodocs_2._guide/node01B3.html)  Set a [filter](../Libraries_Manual_guide/node0407.html) for a [CxObject](../Libraries_Manual_guide/node0401.html) from an input       |
 |                     description string.                             |
 |      [SetFilterIX()](../Includes_and_Autodocs_2._guide/node01B4.html)  Set a filter for a CxObject from an IX data     |
 |                     structure.                                      |
 |---------------------------------------------------------------------|
 |          [ParseIX()](../Includes_and_Autodocs_2._guide/node01AF.html)  Convert an input description string to an IX    |
 |                     data structure.                                 |
 |---------------------------------------------------------------------|
 |      [DivertCxMsg()](../Includes_and_Autodocs_2._guide/node01AB.html)  Divert a [CxMessage](../Libraries_Manual_guide/node0403.html) to one [CxObject](../Libraries_Manual_guide/node0401.html) and return   |
 |                     it to another.                                  |
 |       [RouteCxMsg()](../Includes_and_Autodocs_2._guide/node01B1.html)  Redirect a CxMessage to a new CxObject.         |
 |     [DisposeCxMsg()](../Includes_and_Autodocs_2._guide/node01AA.html)  Cancel a CxMessage removing it from the         |
 |                     Commodities network.                            |
 |---------------------------------------------------------------------|
 |     [InvertString()](../Includes_and_Autodocs_2._guide/node0160.html)  Creates a linked list of input events that      |
 |                     correspond to a given string.                   |
 |      [FreeIEvents()](../Includes_and_Autodocs_2._guide/node015C.html)  Frees the linked list of input events created   |
 |                     with InvertString().                            |
 |       [AddIEvents()](../Includes_and_Autodocs_2._guide/node019E.html)  Converts a list of input events to [CxMessages](../Libraries_Manual_guide/node0403.html)   |
 |                     and puts them into the network.                 |
 |_____________________________________________________________________|

