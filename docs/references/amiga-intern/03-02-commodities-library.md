# The Commodities Library

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

### 3.1.2 The Commodities Library

The utilities found in the Commodities directory of the Workbench are used to manipulate input queries for the A3000. These routines have been gathered into a  library. This allows you to add your own expansions to the Commodities utilities. The name "Commodities Library" is often shortened to Cx library. The base address is expected in register A6 with all function calls.

Functions of the Commodities Library 

1. Object Functions 

CreateCxObj 

CxBroker 

ActivateCxObj 

DeleteCxObj 

DeleteCxObjAll 

CxObjType 

CxObjError 

ClearCxObjError 

SetCxObjPri 

2. Object Linking 

AttachCxObj 

EnqueueCxObj 

InsertCxObj 

RemoveCxObj 

3. Special Functions 

FindBroker 

SetTranslate 

SetFilter 

SetFilterIX 

ParseDC 

4. General Messages 

CxMsgType 

CxMsgData 

CxMsgID 

5. Message Paths 

DivertCxMsg 

RouteCxMsg 

DisposeCxMsg 

6. InputEvent Processing 

InvertKeyMap 

AddlEvents 

7. Control Program Functions 

CopyBrokerList 

FreeBrokerList) 

BrokerCommand 

## 3.1 The Libraries and their Functions

8. Standard Macros CxSignal 

CxTranslate 

CxFilter CxDebug 

CxTypeFilter CxCustom 

CxSender 

Description of Functions 

7. Object Functions 

[CreateCxObj Create Commodities object | 

Call: co =  CreateCxObj (type, argl, arg2) 

DO -30 (A6) DO A0 Al 

STRUCT CxObj *CO 

ULONG type 

LONG argl 

LONG arg2 

Function: Creates a  Commodities of type 'type'. 

Parameters: type Object type 

args Object arguments

Result: Address of a  CxObj structure, a  type of handle for Cx 

objects. A  result of 0  indicates a  system error, such as lack of memory.

See also: CxObjError(), CxFilter(), CxTypeFilter(), CxSender(), 

CxSignal(), CxTranslate(), CxDebugO, CxCustom(), 

CxBrokerO 

fCxBroker Create CxObj of type broker |

Call: broker =  CxBroker(nb, error) 

DO -3 6 (A6) A0 DO 

STRUCT CxObj *broker 

STRUCT NewBroker *nb 

LONG *error 

Function: Creates a  broker according to the information passed in the 

NewBroker structure. As opposed to a  normal CxObj, a 

broker is inactive when created.

Parameters: nb NewBroker structure used to define the broker. 

error Address of error code or 0.

Dec Hex STRUCTURE NewBroker , 0 

0 $0 BYTE nb_Version /version 5 

1 $1 BYTE nb_Pad 

2 $2 APTR nb_Name   Broker name 

6 $6 APTR nb_Title  strings, description of 

10 $A APTR nb_Descr the application 

14 $E SHORT nb_Unique what happens with a  Broker of 

the same name
16 $10 WORD nb_Flags 

18 $12 BYTE nb_Pri .-priority in the object list 

19 $13 BYTE nb_Pad2 

20 $14 APTR nb_Port ,-MsgPort 

24 $18 WORD nb_ReservedChannel 

Result: Address of a  CxObj structure, or 0  in the case of an error. 

If you specify an address in error, the following codes will be used at this address:

CBERR_OK No error, broker was created. 

CBERR_SYSERR 

System error, such as lack of memory. 

CBERR_DUP 

Duplicate definition with this name. 

CBERR_VERSION 

Unknown version number. 

See also: Brokers and Application Sub-Trees (in the Reference 

Manual). 

| ActivateCxObi Activate object functions | 

Call: previous =  ActivateCxObj (co, true) 

DO -42 (A6) AO DO 

STRUCT CxObj *CO 

BOOL true  

Function: Every Commodities object can be activated and 

deactivated. If it's active, it executes a  specific operation when a  Commodities message is received. This function is used to activate and deactivate objects.

Parameters: co CxObj structure of the object whose activation 

you want to control. true Boolean argument. A  value of 0  indicates inactivation.

Result: previous Previous status 

See also: CxBroker() 

iDeleteCxObj Delete Commodities object|

Call: DeleteCxObj (co)  

-48 (A6) AO 

STRUCT CxObj *CO 

Function: Deletes a  selected Commodities object. If this object is part 

of a  list, it's also removed from the list. If the object has some other underlying substructure(s) in the system hierarchy, then DeleteCxObjAH() must be used.

Parameters: co CxObj 

Result: None. Invalid parameter may cause system crash. 

See also: exec.library/Remove(), DeleteCxObj All() 

DeleteCxObjAH 

Delete Commodities object and all underlying substructures 

Call: DeleteCxObjAll(co) ,• 

-54 (a6) aO 

STRUCT CxObj *co 

Function: Deletes a  selected Commodities object. If the object is part 

of a  list, it's also removed from the list. If the object has some other underlying substructure(s) in the system hierarchy, they are also deleted.

Parameters: co CxObj structure of any type. 

Result: None. Improper use of this function will crash the system. 

See also: exec.library/Remove(), DeleteCxObjO 

ICxObjType Get object type I 

Call: type =  CxObjType(co)  

DO -60 (A6) AO 

ULONG type 

STRUCT CxObj *co 

Function: Returns the object type for a  selected Commodities object. 

The CxObj must be known, but you will normally only have this information for your own objects. That makes this function rather meaningless.

Parameters: co CxObj structure 

Result: Object type. If you pass the value 0  as the parameter, the 

result is type CXJNVALID. This function only reads a  data structure. If you enter the wrong parameter value, the result will be meaningless.

See also: CreateCxObjO, CxBrokerQ 

ICxObjError <H* error codel 

Call: error =  CxObj Error ( co )  

DO -66 (A6) AO 

LONG error 

STRUCT CxObj *co 

Function: When a  function fails, the cause of the error is encoded in 

various different bits. CxObjError() gives you access to read these bits.

Parameters: co CxObj structure 

Result: A  longword where the set bits have the following 

meanings:

COERRJSNULL 

A value of 0  was passed for CxObj.

COERR_NULLATTACH 

Attempt to enter a  non-existent object in a 

Commodities list. 

COERR_BADFDLTER 

Bad filter string. 

COERR_BADTYPE 

A type-specific function was attempted on an object of the wrong type.

See also: SetFilter(), SetFilterIX(), AttachCxObjO, ActivateCxObjO, 

ClearCxObjError() 

IClearCxObjError Delete error number of a  Cx objectl 

Call: ClearCxObj Error ( co )  

-72 (A6) AO 

STRUCT CxObj *CO 

Function: Deletes the error code of a  Commodities object. 

Parameters: co CxObj structure 

Result: None. 

Warning: This routine may not be used with filter objects if the error 

bit COERRjBADFILTER is set.

See also: CxObjError() 

ISetCxObjPri Change priority of a  Cx oTiectl 

Call: SetCxObjPri(co, pri) 

-78 (A6) AO DO 

STRUCT CxObj *co 

LONG pri 

Function: This function sets the priority of an object that was entered 

in a  list with EnqueueCxObj(). The mechanism corresponds to that of the Exec Lists System.

Parameters: co CxObj structure 

pri Priority (127 through -128)

Result: None. 

See also: ToolTypes and the Commodities Environment (in the 

Reference Manual), EnqueueCxObjO 

2. Object Linking 

[AttachCxObj Attach object to a  head object I 

Call: AttachCxObj (headobj ,    co) 

-84 (A6) AO Al 

STRUCT CxObj *headobj 

STRUCT CxObj *co 

Function: Attaches an object to the end of the list of another object. 

Parameters: headobj CxObj structure of the head object to which 

this object will be attached. co CxObj structure of the object to be attached as a sub-object.

Result: If co is 0, then the error is noted in headobj. This can be 

queried with CxObjError() and cleared with
ClearCxObjError(). 

See also: exec.library/AddTail(), Objects and Messages (in the 

Reference Manual), CxObjError(), ClearCxObjError() 

lEnqueueCxObj Enter object as a  sub-object|

Call: EnqueueCxObj (headobj ,    co) 

-90 (A6) A0 Al 

STRUCT CxObj *headobj 

STRUCT CxObj *CO 

Function: Enters an object in the list of another object according to 

its priority.

Parameters: headobj CxObj structure of the head object that 

possesses the sub-object list. co CxObj structure of the object to be entered in the sub-object list.

Result: If co has a  value of 0, the error is noted in headobj. This can 

be queried with CxObjError() and cleared with
ClearCxObjErrorO. 

See also: exec.library/Enqueue(), SetCxObjPri(), Objects and 

Messages (in the Reference Manual), CxObjError(), 

ClearCxObjErrorO 

llnsertCxObj Insert an object in front of another object!

Call: insertCxObj (headobj ,    co, pred)  

-96 (A6) A0 Al A2 

STRUCT CxObj *headobj 

STRUCT CxObj *co 

STRUCT CxObj *pred 

Function: The object co is inserted as a  sub-object, in the list of object 

headobj, in front of sub-object pred.

Parameters: headobj CxObj structure that possesses the sub-object 

list co Object to be entered in the list. pred Sub-object in front of which co is inserted.

Result: If co has a  value of 0, the error is noted in headobj. This can 

be queried with CxObjError() and cleared with
ClearCxObjErrorO. 

Warning: Since the Exec function Insert() needs the list header, the 

headobj may not be 0  in cases where pred is 0.

See also: exec.library/Insert(), Objects and Messages (in the 

Reference Manual), CxObjError(), ClearCxObjErrorO 

IRemoveCxObj Remove an object from a  list| 

Call: RemoveCxOb j ( co )  

-102 (a6) A0 

STRUCT CxObj *co 

Function: Removes a  Commodities object from a  selected list. This 

function will not crash if you pass it a  value of 0  or the value of an object not found in the list.

Parameters: co CxObj structure of the object to be removed. 

Result: None. 

Warning: This routine was not intended to remove a  broker from the 

master list.

See also: Objects and Messages (in the Reference Manual) 

3. Special Functions 

fFindBroker Find the broker with a  given name |

Call: broker=FindBroker (name) 

DO -108 (A6) A0 

STRUCT CxObj *broker 

APTR name 

Function: Returns the address of a  broker when you know its name. 

Parameters: name Address of the name string. 

Result: broker CxObj structure of the broker or 0. 

See also: exec.library/Find function 

[SetTranslate Replace the translation list | 

Call: Error =  SetTranslate (translator, ie)  

DO -114 (a6) A0 Al 

LONG Error 

STRUCT CxObj *translator 

STRUCT IX *ie 

Function: Replaces the translation list of a  translator object with the 

list at address ie. If a  value of 0  is passed for ie, then all events are taken. The InputEvents are copied to
Commodities messages during the translation. 

Parameters: translator CxObj structure of a  translator object. 

ie InputEvent list

Result: 0  if the function was successfully executed. 

See also: InputDevice/InputEvent, CxTranslateQ 

| SetFilter Set pattern matching for a  filter objectl 

Call: SetFilter (filter, text) 

-120 (A6) A0 Al 

STRUCT CxObj * filter 

APTR text 

Function: Sets the pattern matching according to the pattern string 

passed in text.

Parameters: filter CxObj structure of a  filter object. 

text Pattern string

Result: None. A  bad filter error can be queried with CxObjError() 

(COERR.BADFILTER). 

See also: SetFilterIX(), CxObjError(), Commodities Input Messages 

and Filters, Input Expressions and Description Strings (in the Reference Manual)

| SetFilterIX Set pattern matching of a  filter objectl 

Call: error =  SetFilterIX (filter, ix)  

DO -126 (A6) A0 Al 

STRUCT CxObj *filter 

STRUCT IX *ix 

Function: Sets the pattern matching according to the contents of the 

Input Expression structure. 

Parameters: filter CxObj structure of a  filter object. 

ix Input Expression structure

Result: error 0  or error number 

See also: SetFilter(), CxObjError(), Commodities Input Messages and 

Filters, Input Expressions and Description Strings (in the 

Reference Manual) 

fParselX Translate string with IX structure]

Call: failurecode =  ParselX (string, ix)  

DO -132 (A6) AO Al 

LONG failurecode 

APTR string 

STRUCT IX *ix 

Function: Translates the parts of a  given string to an IX structure. 

Parameters: string The string to be processed. 

ix Input Expression structure

Result: 0  if no error occurred. 

See also: Input Expressions and Description Strings (in the 

Reference Manual) 

4. General Messages 

[CxMsgType Query Commodities message type| 

Call: type =  CxMsgType(cxm) 

DO -138 (A6) AO 

ULONG type 

STRUCT CxMsg *cxm 

Function: Returns the Commodities message type. 

Parameters: cxm Address of a  Commodities message. 

Result: Message type, 0  in the case of an invalid message. 

See also: CxMsgData(), CxMsgID() 

[CxMsgData Obtain the data address for a  CxMsgl 

Call: contents =  CxMsgData (cxm)  

DO -144 (A6) AO 

APTR contents 

STRUCT CxMsg *cxm 

Function: Most Commodities messages contain data, for example an 

InputEvent structure. CxMsgData() can be used to return a 

pointer to this data.

Parameters: cxm Address of a  CxMsg. 

Result: Address of the data 0  in the case of an invalid message. 

Warning: If a  message is received from a  sender object, the address 

cannot be used after the reply is made.

See also: CxSender(), CxCustom() 

[CxMsglD Obtain the source identification of a  CxMsg | 

Call: id =  CxMsgiD(cxm) ,• 

DO -150 (A6) A0 

LONG id 

STRUCT CxMsg *cxm 

Function: Returns the source identification code specified by an 

application for a  message.

Parameters: cxm Address of a  CxMsg. 

Result: ID of the message 0  if the message has no ID. 

See also: CxSender(), CxCustom() 

5. Message Paths 

[DivertCxMsg Send a  message to a  sub-object | 

Call: DivertCxMsg (cxm, headobj ,    returnobj) 

-156 (A6) A0 Al A2 

STRUCT CxMsg *cxm 

STRUCT CxObj *headobj 

STRUCT CxObj *returnobj 

Function: Sends a  CxMsg to objects in the sub-object list of a 

Commodity object. The message is sent on down the list 

until the next object is the specified returnobj. For example, a Filter object (named 'Filter' for the sake of this example) would send a  message to its sub-objects as follows:
DivertCxMsg(cxm,FilterJJilter). 

Parameters: cxm CxMsg structure to be sent. 

headobj Head object that owns the sub-objects that will receive the message. returnobj SUCC object that indicates the last sub-object in the chain.

Result: None. 

See also: The Reference Manual 

| RouteCxMsg Set the next destination for a  message | 

Call: RouteCxMsg (cxm, co) 

-162 (A6) AO Al 

STRUCT CxMsg *cxm 

STRUCT CxObj *co 

Function: Determines the next object that will receive the message. 

Parameters: cxm CxMsg to be sent. 

co CxObj that will be the next object to receive the message.

Result: None. 

See also: DivertCxMsgO 

[DlsposeCxMsg Delete a  message | 

Call: DisposeCxMsg(cxm) 

-168 (A6) AO 

STRUCT CxMsg *cxm 

Function: Deletes the specified Commodities message. This is good 

for disposing of InputE vents (type CXM_E3VENT).

Parameters: cxm Address of the CxMsg. 

Result: None. 

6. InputEvent Processing 

[InvertKeyMap Convert ANSI codes | 

Call: retval =  InvertKeyMap (ansicode, ie, km) 

DO -174 (A6) DO AO Al 

ULONG retval 

ULONG ansicode 

STRUCT InputEvent *ie 

STRUCT KeyMap *km 

Function: The MapANSI() function determines whether an ANSI 

code conversion should take place when an InputEvent is received. The given KeyMap is used. Simple DeadKeys are converted.

Parameters: ansicode ANSI code to be checked. 

ie InputEvent structure to be filled. km KeyMap, default =  0

Result: 0  No conversion 

See also: InvertStringQ 

[AddlEvents Add a  list of InputEvents to the Cxflstl 

Call: AddlEvents (ie) 

-180 (A6) A0 

STRUCT InputEvent *ie 

Function: Normally, the Commodities Library Input Handler gets its 

information directly from the input device. But it would not be convenient to send messages to the Commodities
Library via this device. Therefore, AddlEvents was 

implemented. The InputEvents are copied to the
Commodities messages and sent to the objects in the 

internal object list.

Parameters: ie Linked list of InputEvents. 

Result: None. 

See also: FreeIEvents() 

7. Control Program Functions 

[CopyBrokerList Copy the broker list | 

Call: list =  CopyBrokerList (blist) 

DO -186 (A6) A0 

Warning: FOR CONTROL PROGRAMS ONLY! 

[FreeBrokerList Free broker listj 

Call: FreeBrokerList (list) 

-192(A6) A0 

Warning : FOR CONTROL PROGRAMS ONLY! 

[BrokerComrnand Broker command"] 

Call: result =  BrokerComrnand (name, id) 

DO -198 (A6) A0 DO 

Warning: FOR CONTROL PROGRAMS ONLY! 

8. Standard Macros 

Creation ofCxObj: 

CxFilter(d) 

CxTypeFi Iter (type) 

CxSender (port , id) 

CxSignal (task, sig) 

CxTrans late ( ie ) 

CxDebug(id) 

CxCustom(action, id) 

CreateCxObj (CX_FILTER, d, 0 ) 

CreateCxObj (CX_TYPEFILTER, type, 0) 

CreateCxObj (CX_SEND,port, id) 

CreateCxObj (CX_SIGNAL, task, sig) 

CreateCxObj ( CX_TRANSLATE , ie, 0) 

CreateCxObj (CX_DEBUG, id, 0) 

CreateCxObj (CX_CUSTOM, action, id) 

Buffer size of Broker: 

CBD_NAMELEN =  24 

CBD_TITLELEN =40 

CBD_DESCRLEN =40 

CxBroker() error: 

CBERR_OK =0 no error 

CBERR_SYSERR =  1  system error 

CBERR_DUP =  2 ,-duplicate definition 

CBERR_VERSION =  3  unknown version 

NB_VERSION 

= 5  /version of NewBroker 

Dec Hex STRUCTURE NewBroker, 0 

0 $0 BYTE nb_Version  vers ion 5 

1 $1 BYTE nb_Pad 

2 $2 APTR nb_Name 

6 $6 APTR nb_Title 

10 $A APTR nb_Descr 

14 $E SHORT nb_Unique 

,- Broker name 

/strings, description of the 

,-application 

what happens with a  Broker of the same name

16 $10 WORD nb_Flags 

18 $12 BYTE nb_Pri 

19 $13 BYTE nb_Pad2 

20 $14 APTR nb_Port MsgPort 

24 $18 WORD nb_ReservedChannel 

,-priority in the Object list 

Flags for nbJJnique: 

NBU_DUPLICATE =  0 ,-duplicate definition allowed 

NBU_UNIQUE =  1 ,-duplicate definition not allowed 

NBU_NOTIFY =  2 ,-CxMsg CXM_UNIQUE to existing Broker 

Flag for nb_Flags: 

COF_SHOW_HIDE =  4 

CX_INVALID =  0 

CX_FILTER =  1 

CX_TYPEFILTER =  2 

CX_SEND =  3 

CX_SIGNAL =  4 

CXJTRANSLATE =  5 

CX_BROKER =  6 

CX_DEBUG =  7 

CX_CUSTOM =  8 

CX_ZERO =  9 

Object types: 

no object f or InputEvent messages only

/message Type filter 

/message sender 

signal sender

 InputEvent translator 

most applications sends Debug info to serial port

/custom Function 

last entry

CXM_UNIQUE 

CXM_I EVENT 

CXM_COMMAND 

CXCMD_DISABLE 

CXCMD_ENABLE 

CXCMD_APPEAR 

CXCMD_DISAPPEAR 

CXCMD_KILL 

CXCMD_UNIQUE 

CXCMD_LIST CHG 

Message Types: 

16 from CxBroker ( ) 

32  InputEvent 

64 /from BrokerCommand ( ) 

ID Values: 

= 15 /deactivate 

= 17 /activate 

= 19 /open window 

=21 /close window 

=23 / remove 

= 25 /duplicate definition attempted 

= 27 /Broker list changed 

Results of BrokerCommand(): 

CMDE_OK =  0 

CMDE_NOBROKER =  -1 

CMDE_NOPORT =  -2 

CMDE_NOMEM =  -3 

Error Flags from CxObj (CxObjError()): 

COERR_ISNULL =  1 /call was CxError (NULL) 

COERR_NULLATTACH =  2 /sub-object was 0 

COERR_BADFILTER =  4 /invalid Filter 

COERR_BADTYPE 

8  invalid object type 

Version of IX Structure: 

IX_VERSION =  2 

Dec Hex 

STRUCTURE IX, 0 

$0 UBYTE ix_Version 

$1 UBYTE ix_Class 

$2 UWORD ix_Code 

version 2

Event class 

Event data 

$4 UWORD ix_CodeMask data mask 

$6 UWORD ix_Qualifierexact description 

$8 UWORD ix_QualMask QualSame mask 

$A UWORD ix_QualSame  Qualifier with the same meaning 

Flags for ixjQualSame: 

IXSYM_SHIFT =  1 left and right Shift keys together 

IXSYM_CAPS =  2 Caps-Lock at the same time 

IXSYM_ALT =  4  lef t and right Alt keys together 

Corresponding QualMasks (see InputEvent): 

IXSYM_SHIFTMASK =  IEQUALIFIER_LSHIFT I  IEQUALIFIER_RSHIFT 

IXSYM_CAPSMASK =  IXSYM_SHIFTMASK I  IEQUALIFIER_CAPSLOCK 

IXSYM_ALTMASK =  IEQUALIFIER_LALT I  IEQUALIFIER_RALT 

IX_NORMALQUALS =  $7FFF  normal QualMask 

