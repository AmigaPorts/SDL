---
title: 31 Commodities Exchange Library / Function Reference
manual: libraries
chapter: libraries
section: 31-commodities-exchange-library-function-reference
functions: [ActivateCxObj, AddIEvents, AttachCxObj, ClearCxObjError, CxBroker, CxMsgData, CxMsgID, CxMsgType, CxObjError, DeleteCxObj, DeleteCxObjAll, DisposeCxMsg, DivertCxMsg, EnqueueCxObj, InsertCxObj, ParseIX, RemoveCxObj, RouteCxMsg, SetCxObjPri, SetFilter, SetFilterIX, SetTranslate]
libraries: [commodities.library]
---

# 31 Commodities Exchange Library / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following are brief descriptions of the Commodities Exchange functions
covered in this chapter.  All of these functions require Release 2 or a
later version of the Amiga operating system.  See the Amiga ROM Kernel
Reference Manual: Includes and Autodocs for details on each function call.


              Table 31-2: Commodities Exchange Functions
  _____________________________________________________________________
 |                                                                     |
 |         Function              Description                           |
 |=====================================================================|
 |         [CxBroker()](autodocs-2.0/commodities-library-cxbroker.md)  Creates a [CxObject](libraries/31-commodities-exchange-library-cxobjects.md) of type [Broker](libraries/31-commodities-exchange-library-installing-a-broker-object.md).              |
 |         [CxFilter()](autodocs-2.0/amiga-lib-cxfilter.md)  Creates a CxObject of type [Filter](libraries/31-commodities-exchange-filter-objects-and-input.md).              |
 |         [CxSender()](autodocs-2.0/amiga-lib-cxsender.md)  Creates a CxObject of type [Sender](libraries/31-commodities-exchange-library-sender-cxobjects.md).              |
 |      [CxTranslate()](autodocs-2.0/amiga-lib-cxtranslate.md)  Creates a CxObject of type [Translate](libraries/31-commodities-exchange-library-translate-cxobjects.md).           |
 |         [CxSignal()](autodocs-2.0/amiga-lib-cxsignal.md)  Creates a CxObject of type [Signal](libraries/31-commodities-exchange-library-signal-cxobjects.md).              |
 |         [CxCustom()](autodocs-2.0/amiga-lib-cxcustom.md)  Creates a CxObject of type [Custom](libraries/31-commodities-exchange-library-custom-cxobjects.md).              |
 |          [CxDebug()](autodocs-2.0/amiga-lib-cxdebug.md)  Creates a CxObject of type [Debug](libraries/31-commodities-exchange-library-debug-cxobjects.md).               |
 |      [DeleteCxObj()](autodocs-2.0/commodities-library-deletecxobj.md)  Frees a single CxObject                         |
 |   [DeleteCxObjAll()](autodocs-2.0/commodities-library-deletecxobjall.md)  Frees a group of connected CxObjects            |
 |---------------------------------------------------------------------|
 |    [ActivateCxObj()](autodocs-2.0/commodities-library-activatecxobj.md)  Activates a newly created [CxObject](libraries/31-commodities-exchange-library-cxobjects.md) in the       |
 |                     commodities network.                            |
 |---------------------------------------------------------------------|
 |     [SetTranslate()](autodocs-2.0/commodities-library-settranslate.md)  Sets up substitution of one input event for     |
 |                     another by translate CxObjects.                 |
 |---------------------------------------------------------------------|
 |        [CxMsgType()](autodocs-2.0/commodities-library-cxmsgtype.md)  Finds the type of a [CxMessage](libraries/31-commodities-exchange-library-cxmessages.md).                  |
 |        [CxMsgData()](autodocs-2.0/commodities-library-cxmsgdata.md)  Returns the CxMessage data.                     |
 |          [CxMsgID()](autodocs-2.0/commodities-library-cxmsgid.md)  Returns the CxMessage ID.                       |
 |---------------------------------------------------------------------|
 |       [CxObjError()](autodocs-2.0/commodities-library-cxobjerror.md)  Returns the [CxObject](libraries/31-commodities-exchange-library-cxobjects.md)'s accumulated error field. |
 |  [ClearCxObjError()](autodocs-2.0/commodities-library-clearcxobjerror.md)  Clear the CxObject's accumulated error field.   |
 |---------------------------------------------------------------------|
 |     [ArgArrayInit()](autodocs-2.0/amiga-lib-argarrayinit.md)  Create a Tool Types array from argc and argv    |
 |                     (Workbench or Shell).                           |
 |     [ArgArrayDone()](autodocs-2.0/amiga-lib-argarraydone.md)  Free the resources used by ArgArrayInit().      |
 |        [ArgString()](autodocs-2.0/amiga-lib-argstring.md)  Return the string associated with a given Tool  |
 |                     Type in the array.                              |
 |           [ArgInt()](autodocs-2.0/amiga-lib-argint.md)  Return the integer associated with a given Tool |
 |                     Type in the array.                              |
 |---------------------------------------------------------------------|
 |      [AttachCxObj()](autodocs-2.0/commodities-library-attachcxobj.md)  Attaches a [CxObject](libraries/31-commodities-exchange-library-cxobjects.md) to the end of a given       |
 |                     CxObject's list.                                |
 |      [InsertCxObj()](autodocs-2.0/commodities-library-insertcxobj.md)  Inserts a CxObject in a given position in a     |
 |                     CxObject's list.                                |
 |     [EnqueueCxObj()](autodocs-2.0/commodities-library-enqueuecxobj.md)  Inserts a CxObject in a CxObject's list by      |
 |                     priority.                                       |
 |      [SetCxObjPri()](autodocs-2.0/commodities-library-setcxobjpri.md)  Sets a CxObject's priority for EnqueueCxObj().  |
 |      [RemoveCxObj()](autodocs-2.0/commodities-library-removecxobj.md)  Removes a CxObject from a list.                 |
 |---------------------------------------------------------------------|
 |        [SetFilter()](autodocs-2.0/commodities-library-setfilter.md)  Set a [filter](libraries/31-commodities-exchange-filter-objects-and-input.md) for a [CxObject](libraries/31-commodities-exchange-library-cxobjects.md) from an input       |
 |                     description string.                             |
 |      [SetFilterIX()](autodocs-2.0/commodities-library-setfilterix.md)  Set a filter for a CxObject from an IX data     |
 |                     structure.                                      |
 |---------------------------------------------------------------------|
 |          [ParseIX()](autodocs-2.0/commodities-library-parseix.md)  Convert an input description string to an IX    |
 |                     data structure.                                 |
 |---------------------------------------------------------------------|
 |      [DivertCxMsg()](autodocs-2.0/commodities-library-divertcxmsg.md)  Divert a [CxMessage](libraries/31-commodities-exchange-library-cxmessages.md) to one [CxObject](libraries/31-commodities-exchange-library-cxobjects.md) and return   |
 |                     it to another.                                  |
 |       [RouteCxMsg()](autodocs-2.0/commodities-library-routecxmsg.md)  Redirect a CxMessage to a new CxObject.         |
 |     [DisposeCxMsg()](autodocs-2.0/commodities-library-disposecxmsg.md)  Cancel a CxMessage removing it from the         |
 |                     Commodities network.                            |
 |---------------------------------------------------------------------|
 |     [InvertString()](autodocs-2.0/amiga-lib-invertstring.md)  Creates a linked list of input events that      |
 |                     correspond to a given string.                   |
 |      [FreeIEvents()](autodocs-2.0/amiga-lib-freeievents.md)  Frees the linked list of input events created   |
 |                     with InvertString().                            |
 |       [AddIEvents()](autodocs-2.0/commodities-library-addievents.md)  Converts a list of input events to [CxMessages](libraries/31-commodities-exchange-library-cxmessages.md)   |
 |                     and puts them into the network.                 |
 |_____________________________________________________________________|

---

## See Also

- [ActivateCxObj — commodities.library](../autodocs/commodities.library.md#activatecxobj)
- [AddIEvents — commodities.library](../autodocs/commodities.library.md#addievents)
- [AttachCxObj — commodities.library](../autodocs/commodities.library.md#attachcxobj)
- [ClearCxObjError — commodities.library](../autodocs/commodities.library.md#clearcxobjerror)
- [CxBroker — commodities.library](../autodocs/commodities.library.md#cxbroker)
- [CxMsgData — commodities.library](../autodocs/commodities.library.md#cxmsgdata)
- [CxMsgID — commodities.library](../autodocs/commodities.library.md#cxmsgid)
- [CxMsgType — commodities.library](../autodocs/commodities.library.md#cxmsgtype)
- [CxObjError — commodities.library](../autodocs/commodities.library.md#cxobjerror)
- [DeleteCxObj — commodities.library](../autodocs/commodities.library.md#deletecxobj)
- [DeleteCxObjAll — commodities.library](../autodocs/commodities.library.md#deletecxobjall)
- [DisposeCxMsg — commodities.library](../autodocs/commodities.library.md#disposecxmsg)
- [DivertCxMsg — commodities.library](../autodocs/commodities.library.md#divertcxmsg)
- [EnqueueCxObj — commodities.library](../autodocs/commodities.library.md#enqueuecxobj)
- [InsertCxObj — commodities.library](../autodocs/commodities.library.md#insertcxobj)
- [ParseIX — commodities.library](../autodocs/commodities.library.md#parseix)
- [RemoveCxObj — commodities.library](../autodocs/commodities.library.md#removecxobj)
- [RouteCxMsg — commodities.library](../autodocs/commodities.library.md#routecxmsg)
- [SetCxObjPri — commodities.library](../autodocs/commodities.library.md#setcxobjpri)
- [SetFilter — commodities.library](../autodocs/commodities.library.md#setfilter)
- [SetFilterIX — commodities.library](../autodocs/commodities.library.md#setfilterix)
- [SetTranslate — commodities.library](../autodocs/commodities.library.md#settranslate)
