# commodities.library — Autodoc Reference

*Filtered to AmigaOS V39 and below.*

**Functions:** 29

## Function Index

- **ActivateCxObj** (V36) — change the activation state of a commodity object.
- **AddIEvents** (V36) — add input events to commodities' input stream.
- **AttachCxObj** (V36) — attach a commodity object to the end of an existing
- **BrokerCommand** — Issue a commodity broker command. (V53.4)
- **ClearCxObjError** (V36) — clear the accumulated error value of a commodity
- **CopyBrokerList** — Copy the current commodity broker list. (V53.4)
- **CreateCxObj** (V36) — create a new commodity object.
- **CxBroker** (V36) — create a commodity broker.
- **CxMsgData** (V36) — obtain a pointer to a commodity message's data area.
- **CxMsgID** (V36) — obtain the ID of a commodity message.
- **CxMsgType** (V36) — obtain the type of a commodity message.
- **CxObjError** (V36) — obtain a commodity object's accumulated error.
- **CxObjType** (V36) — obtain the type of a commodity object.
- **DeleteCxObj** (V36) — delete a commmodity object.
- **DeleteCxObjAll** (V36) — recursively delete a tree of commodity objects.
- **DisposeCxMsg** (V36) — delete a commodity message.
- **DivertCxMsg** (V36) — send a commodity message down an object list.
- **EnqueueCxObj** (V36) — insert a commodity object within a list of objects
- **FreeBrokerList** — Frees the commodity broker list. (V53.4)
- **InsertCxObj** (V36) — insert a commodity object in a list after a given
- **InvertKeyMap** (V36) — generate an input event from an ANSI code.
- **MatchIX** (V38) — see if an input event matches an initialized input
- **ParseIX** (V36) — initialize an input expression given a description string.
- **RemoveCxObj** (V36) — remove a commodity object from a list.
- **RouteCxMsg** (V36) — set the next destination of a commodity message.
- **SetCxObjPri** (V36) — set the priority of a commodity object.
- **SetFilter** (V36) — change the matching condition of a commodity filter.
- **SetFilterIX** (V36) — change the matching condition of a commodity filter.
- **SetTranslate** (V36) — replace a translator object's translation list.

## Functions

### commodities.library/ActivateCxObj (V36)

**change the activation state of a commodity object.**

**Synopsis:**
```c
int32 previous = ActivateCxObj(CxObj *co, int32 true);
```

**Description:**
Commodity objects of all types maintain an activation state.
If an object is "active", then it performs its particular action
whenever a commodity message arrives. If the object is "inactive"
no action is taken, and the message goes on to its next destination.

All objects are created in the "active" state except brokers
which are created "inactive". Thus, after you create your
broker and hang a tree of objects off of it, you must remember
to use this function to activate it. This causes it to divert all
messages to your tree of objects.

This function activates 'co' if 'true' is different than 0. and
deactivates it otherwise. The previous activation state is
returned.

**Inputs:**
co - the commodity object to affect (may be NULL)
true - 0 to deactivate the object, anything else to activate it

**Result:**
previous - the previous activation state: 0 if the object was
	   inactive or if 'co' was NULL, anything else if the object
	   was active

**See also:** CxBroker()

---

### commodities.library/AddIEvents (V36)

**add input events to commodities' input stream.**

**Synopsis:**
```c
AddIEvents(events)

VOID AddIEvents(struct InputEvent *);
```

**Description:**
This function adds a null-terminated linked list of input events to
the input stream processed by commodities. It is a touch easier than
using the input device directly.

The contents of the input events are copied into commodity messages,
so they may be disposed of as soon as this call returns.

The messages are initially routed to the first broker in
commodities' object list.

**Inputs:**
events - the list of input events to add (may be NULL)

**Notes:**
The cx_lib/InvertString() function creates lists of input events that
are in reverse order. Thus, passing the result of InvertString()
to this function will insert a series of input events that will
generate a string that's a mirror image of the string passed to
InvertString() originally.

The solution to the above is to either flip the string before
passing it to InvertString(), or flip the resulting list of input
events.

**Bugs:**
Prior to V40, this function did not copy the data pointed to by
ie_EventAddress for any events of type IECLASS_NEWPOINTERPOS.

**See also:** cx_lib/FreeIEvents()

---

### commodities.library/AttachCxObj (V36)

**attach a commodity object to the end of an existing
	       list of objects.**

**Synopsis:**
```c
AttachCxObj(headObj,co);

VOID AttachCxObj(CxObj *,CxObj *);
```

**Description:**
Adds 'co' to the list of objects pointed to by 'headObj'. The
new object is added at the end of the list.

**Inputs:**
headObj - pointer to a list of objects. If this value is NULL, then
	  the entire tree of objects pointed to by 'co' is deleted
	  and becomes invalid.
co - the object to add to the list (may be NULL)

**Result:**
If 'co' is NULL, this function will record that fact in the
internal accumulated error of 'headObj'. This error record
can be retrieved using CxObjError() and cleared using
ClearCxObjError().

**Bugs:**
Until V38, passing a NULL 'headObj' parameter would cause low-memory
access and unpredictable results.

**See also:** CxObjError(), ClearCxObjError()

---

### commodities.library/BrokerCommand

**Issue a commodity broker command. (V53.4)**

**Synopsis:**
```c
int32 result = BrokerCommand(CONST_STRPTR name, int32 command);
```

**Description:**
Issues a command to the specified commodity broker. All commands
are delivered to the broker's port for processing asynchronously.

**Inputs:**
name    - Name of the broker to issue a command to.

   If NULL, command is issued to all the brokers with
   the COF_BROADCAST flag set. The return value is
   either CMDE_OK or CMDE_NOMEM only.

command - Command to issue to the broker. The list of valid
   commands are listed in <libraries/commodities.h>
   and are prefixed by CXCMD.

**Result:**
result - The result of issuing the command to the broker.

  CMDE_OK
  Command issued without error.

  CMDE_NOBROKER
  Could not find the broker by name.

  CMDE_NOPORT
  Could not find the broker's port to issue the
  command to.

  CMDE_NOMEM
  Out of memory error.

**Notes:**
This function was not made public until version 53.4 of
commodities.library. It is not backwards compatible.

**See also:** CopyBrokerList(), FreeBrokerList()

---

### commodities.library/ClearCxObjError (V36)

**clear the accumulated error value of a commodity
		   object.**

**Synopsis:**
```c
ClearCxObjError(co);

VOID ClearCxObjError(CxObj *);
```

**Description:**
This function clears the accumulated error value of commodity object
'co'.

It is unwise to do this to a filter if COERR_BADFILTER is set.
This will fool commodities into thinking the filter is OK. Set
another valid filter, or leave the error value alone.

**Inputs:**
co - the object to affect (may be NULL)

**See also:** CxObjError()

---

### commodities.library/CopyBrokerList

**Copy the current commodity broker list. (V53.4)**

**Synopsis:**
```c
int32 num_brokers = CopyBrokerList(struct List *blist);
```

**Description:**
This function creates a copy of the current broker list. The
caller is responsible for providing an empty list to populate.

Each broker in the list has the following structure:

struct CxBrokerCopy
{
    struct Node   Node;
    uint32        StructSize;
    struct Task  *Owner;
    CONST_STRPTR  Name;
    CONST_STRPTR  Title;
    CONST_STRPTR  Description;
    uint32        Flags;
}

Node
Embedded struct Node used for linking in the provided List.
The ln_Name field points to the Name of the broker which makes
it possible to use the FindName() function.

StructSize
Size of this data structure in bytes. This may continue to grow in
future releases as new members are added at the end of the structure.

Owner
The Task which created the broker via the CxBroker() function.

Name
This is the name of the broker. It is possible for name may be
extended beyond the CBD_NAMELEN limit in a future release.

Title, Description
These are two strings describe the application the broker is
representing. It is possible these strings will be extended
beyond the CBD_TITLELEN and CBD_DESCRLEN limits in a future
release.

Flags
This bit field toggles features defined by constants in
<libraries/commodities.h>.

**Inputs:**
blist - Pointer to an initialized List structure. The list is
 cleared with FreeBrokerList() prior to being populated.
 May be NULL in which case this function does nothing.

**Result:**
num_brokers - The number of brokers populated in the list or
       -1 on error.

**Notes:**
This function was not made public until version 53.4 of
commodities.library. It is not backwards compatible.

**See also:** FreeBrokerList(), BrokerCommand()

---

### commodities.library/CreateCxObj (V36)

**create a new commodity object.**

**Synopsis:**
```c
CxObj *co = CreateCxObj(uint32 type, int32 arg1, int32 arg2);
```

**Description:**
This function creates a commodity object of type 'type'. It is not
proper to call this function directly. Each object creation routine
except CxBroker() is defined as a macro in <libraries/commodities.h>
These are independently documented.

All functions which operate on a commodity object are made with
a reference to the thirty-two bit value returned by this function
(or by CxBroker()).

**Inputs:**
type - the type of object to create as defined in
<libraries/commodities.h>
arg1 - first argument, meaning depends on 'type'
arg2 - second argument, meaning depends on 'type'

**Result:**
co - a pointer to the new object or NULL if it could not be created.
     A NULL return indicates typically a lack of system memory. Minor
     problems in creating an object, such as providing a bad filter
     description to cx_lib/CxFilter(), typically don't cause failure,
     but are recorded in an internal error field in the new object
     which can be accessed via CxObjError().

**See also:** CxObjError(), cx_lib/CxFilter(), cx_lib/CxSender(),
cx_lib/CxSignal(), cx_lib/CxTranslate(), cx_lib/CxDebug(),
cx_lib/CxCustom(), CxBroker()

---

### commodities.library/CxBroker (V36)

**create a commodity broker.**

**Synopsis:**
```c
CxObj *broker = CxBroker(struct NewBroker *nb, int32 *error);
```

**Description:**
This function creates a broker from the specification found in the
NewBroker structure pointed to by 'nb'. The purpose and meaning of the
fields of the NewBroker structure are described below. Also see
<libraries/commodities.h> for more info.

struct NewBroker
{
    int8            nb_Version;
    CONST_STRPTR    nb_Name;
    CONST_STRPTR    nb_Title;
    CONST_STRPTR    nb_Descr;
    int16           nb_Unique;
    int16           nb_Flags;
    int8            nb_Pri;
    struct MsgPort *nb_Port;
    int16           nb_ReservedChannel;
};

nb_Version
This is the way that future versions of commodities can identify
which version of the NewBroker structure you are using. This should be
set to NB_VERSION as defined in <libraries/commodities.h>

nb_Name
This is the name of the broker. This name is used to find the broker
in commodities' object list and is the name shown in the listview
gadget of the Exchange program. The name string is copied in the
broker object upon creation so it can be discarded right after
CxBroker() returns. The maximum length of the name string is defined
by a constant in <libraries/commodities.h>.

nb_Title, nb_Descr
These are two strings which appear to the user in the Exchange
program and describe the application the broker is representing.
Note that these strings are copied into the broker object so they
can be discarded right after CxBroker() returns. The maximum length
of these strings that will be recognized are defined by constants in
<libraries/commodities.h>.

nb_Unique
This field indicates what should happen if a broker of the same name
(nb_Name) already exists in commodities' object list. Constants
in <libraries/commodities.h> allow the caller to specify whether
another broker is to be created, and whether any existing broker of
the same name should be notified that an attempt at creating a
duplicate has been made.

nb_Flags
This bit field toggles certain features of Commodities Exchange based
on their values defined by constants in <libraries/commodities.h>.

nb_Pri
This specifies with what priority the new broker is to be inserted
within commodities' object list. Higher priority nodes appear
earlier in a list. It is strongly recommended that the ToolTypes
environment of an application be used to allow the end-user to set
the priority of the broker.

**Inputs:**
nb - an initialized NewBroker structure
error - a pointer to an int32 where to store a failure code (may be
	NULL)

**Result:**
broker - a pointer to the broker object or NULL upon failure. If the
	 'error' pointer is not NULL, a further diagnostic code is
	 placed at that address. Error codes are defined in
	 <libraries/commodities.h> and include:

		CBERR_OK
		No problems; broker created OK.

 			CBERR_SYSERR
		System problems, not your fault, sign of low memory.

		CBERR_DUP
		The nb_Unique field specified that only one broker of
		'nb_Name' should be allowed, and one already exists.

		CBERR_VERSION
		The version specified in 'nb_Version' is unknown to the
		library.

**See also:** SetCxObjPri(), <libraries/commodities.h>

---

### commodities.library/CxMsgData (V36)

**obtain a pointer to a commodity message's data area.**

**Synopsis:**
```c
APTR data = CxMsgData(const CxMsg *cxm);
```

**Description:**
Most commodity messages contain meaningful data such as an InputEvent
structure. This function returns a pointer to this data.

You may get a commodity message from a synchronous (custom object) or
asynchronous (sender object) source. In the second case, 'data' is
not valid after you have replied to the message.

**Inputs:**
cxm - the commodity message to get the data pointer from (may be NULL)

**Result:**
data - a pointer to the message's data, or NULL if 'cxm' is NULL.
The meaning of the data varies depending on which kind of
object is being inspected.

**Bugs:**
Until V38, passing a NULL 'cxm' parameter would cause low-memory
access and unpredictable results.

Until V40, whenever the data pointer is a (struct InputEvent), the
ie_EventAddress field of these structures was not reliable whenever
the message was generated by a sender object.

**See also:** cx_lib/CxSender(), cx_lib/CxCustom()

---

### commodities.library/CxMsgID (V36)

**obtain the ID of a commodity message.**

**Synopsis:**
```c
int32 id = CxMsgID(const CxMsg *cxm);
```

**Description:**
This function returns the value associated with the cause or source
of the commodity message 'cxm'. Values are provided by the application
when a sender or custom object is created.

**Inputs:**
cxm - the commodity message to inquire about (must NOT be NULL)

**Result:**
id - if not specified by the application, the ID value of a
     commodity message will be 0. It is suggested that using
     non-zero values in your program as a rule may identify some
     possible errors.

**See also:** cx_lib/CxSender(), cx_lib/CxCustom()

---

### commodities.library/CxMsgType (V36)

**obtain the type of a commodity message.**

**Synopsis:**
```c
uint32 type = CxMsgType(const CxMsg *cxm);
```

**Description:**
This function returns the type of a commodity message. Possible values
of 'type' are defined in <libraries/commodities.h>. Most commodity
messages are of type CXM_IEVENT.

**Inputs:**
cxm - the commodity message to inquire about (must NOT be NULL)

**Result:**
type - the type of the commodity message, possible values are defined
in <libraries/commodities.h>

---

### commodities.library/CxObjError (V36)

**obtain a commodity object's accumulated error.**

**Synopsis:**
```c
int32 error = CxObjError(CxObj *co);
```

**Description:**
When a function acting on an object fails, it records the failure
in the object. This function returns the accumulated error value.
The values are represented by flag bits defined in
<libraries/commodities.h>. Several errors may be recorded by multiple
bits in 'error'.

The currently defined errors are:

COERR_ISNULL
  The value of parameter 'co' was in fact NULL. This error
  means "the problem with the object you inquire about is
  that it failed to be created."

  	COERR_NULLATTACH
  Using the commodities' list manipulation functions, an attempt was
  made to add a NULL object to the list belonging to 'co'. This allows
  a line of code as follows to exist in an error-tolerant program:

    AttachCxObj(filter,CxSender(myport,MY_ID));

  	COERR_BADFILTER
  The most recent filter specification for a filter object
  was faulty. This happens if no sense can be made out of a
  description string, or if an input expression (IX) has an
  invalid format or version byte. When this bit is set in a
  filter's error field, the filter will match nothing, but this
  is not the proper way to "turn off" a filter, use ActivateCxObj().

  	COERR_BADTYPE
  A type specific operation, such as SetFilterIX(), was called
  for object 'co', but 'co' isn't of the proper type.

**Inputs:**
co - the commodity object to get the accumulated error from (may be
     NULL)

**Result:**
error - the accumulated error, or 0 if 'co' is NULL

**See also:** SetFilter(), SetFilterIX(), AttachCxObj(), ActivateCxObj(),
ClearCxObjError()

---

### commodities.library/CxObjType (V36)

**obtain the type of a commodity object.**

**Synopsis:**
```c
uint32 type = CxObjType(CxObj *co);
```

**Description:**
This function should not really be necessary. It returns
the type of a commodity object, which you should already
know, since you created it in the first place.

**Inputs:**
co - the commodity object to inquire about (may be NULL)

**Result:**
type - the type of the commodity object, possible values are
defined in <libraries/commodities.h>. Returns CX_INVALID
if 'co' is NULL.

**See also:** CreateCxObj()

---

### commodities.library/DeleteCxObj (V36)

**delete a commmodity object.**

**Synopsis:**
```c
DeleteCxObj(co);

VOID DeleteCxObj(CxObj *);
```

**Description:**
Deletes a commodity object of any type. If the object
is linked into a list, it is first removed. Note that
the handle 'co' is invalid after this function is called.

Also note that deleting an object which has other objects attached
to it may be undesirable. Use the function DeleteCxObjAll()
to delete an entire sub-tree of objects.

**Inputs:**
co - the commodity object to delete (may be NULL)

**See also:** DeleteCxObjAll()

---

### commodities.library/DeleteCxObjAll (V36)

**recursively delete a tree of commodity objects.**

**Synopsis:**
```c
DeleteCxObjAll(co);

VOID DeleteCxObjAll(CxObj *);
```

**Description:**
This function deletes the commodity object 'co', and
recursively deletes all objects attached to it, and the
objects attached to them, etc.

If 'co' is linked into a list, it is first removed. Note
that the handle 'co' is invalid after this function is called.

This function is useful when an application exits: most
applications can clean up completely by deleting the
entire sub-tree of objects starting at their broker.

**Inputs:**
co - the first commodity object to delete (may be NULL)

**See also:** DeleteCxObj()

---

### commodities.library/DisposeCxMsg (V36)

**delete a commodity message.**

**Synopsis:**
```c
VOID DisposeCxMsg(CxMsg *cxm);
```

**Description:**
This function eliminates the commodity message pointed to by 'cxm'.
Can be used to 'swallow' input events by disposing of every commodity
message of type CXM_IEVENT.

This function can only be called from within a custom object running
on the input handler's context. It cannot be called from code running
on a commodities' context, such as when receiving a CXM_IEVENT message
from a sender object. CxMsg sent to a commodity program from a sender
object must be sent back using ReplyMsg().

**Inputs:**
cxm - the commodity message to delete (must NOT be NULL)

---

### commodities.library/DivertCxMsg (V36)

**send a commodity message down an object list.**

**Synopsis:**
```c
VOID DivertCxMsg(CxMsg *cxm, CxObj *headObj, CxObj *returnObj);
```

**Description:**
This function sends the commodity message 'cxm' down the list of
objects attached to 'headObj'. The pointer 'returnObj' is first
pushed onto the routing stack of 'cxm' so that when the end of the
list of 'headObj' is reached the SUCCESSOR of 'returnObj' is the
next destination.

For example, when a filter finds a match with a message, the
message is diverted down the filter's list like this:

  DivertCxMsg(cxm,filter,filter);

**Inputs:**
cxm - the commodity message to divert (must NOT be NULL)
headObj - the list of objects to divert the message to
returnObj - the object to use as a place holder

**See also:** RouteCxMsg()

---

### commodities.library/EnqueueCxObj (V36)

**insert a commodity object within a list of objects
	        based on object priority.**

**Synopsis:**
```c
EnqueueCxObj(headObj,co);

VOID EnqueueCxObj(CxObj *,CxObj *);
```

**Description:**
This function puts object 'co' into the list of object 'headObj'.
The insertion point is determined by the object's priority. The
objects are kept in the list from the highest priority to the
lowest. New nodes are inserted in front of the first node with a
lower priority. Hence a FIFO queue for nodes of equal priority.

The priority of the commodity object can be set using SetCxObjPri().

**Inputs:**
headObj - pointer to a list of objects. If this value is NULL, then
	  the entire tree of objects pointed to by 'co' is deleted
	  and becomes invalid.
co - the object to add to the list (may be NULL)

**Result:**
If 'co' is NULL, this function will record that fact in the
internal accumulated error of 'headObj'. This error record
can be retrieved using CxObjError() and cleared using
ClearCxObjError().

**Bugs:**
Until V38, passing a NULL 'headObj' parameter would cause low-memory
access and unpredictable results.

**See also:** SetCxObjPri(), CxObjError(), ClearCxObjError()

---

### commodities.library/FreeBrokerList

**Frees the commodity broker list. (V53.4)**

**Synopsis:**
```c
VOID FreeBrokerList(struct List *blist);
```

**Description:**
This function frees the broker list populated by the CopyBrokerList()
function.

**Inputs:**
blist - Pointer to the List populated by CopyBrokerList().
 May be NULL in which case this function does nothing.

**Notes:**
This function was not made public until version 53.4 of
commodities.library. It is not backwards compatible.

**See also:** CopyBrokerList(), BrokerCommand()

---

### commodities.library/InsertCxObj (V36)

**insert a commodity object in a list after a given
	       object.**

**Synopsis:**
```c
InsertCxObj(headObj,co,pred);

VOID InsertCxObj(CxObj *,CxObj *,CxObj *);
```

**Description:**
Adds 'co' to the list of objects pointed to by 'headObj' after
object 'pred'.

**Inputs:**
headObj - pointer to a list of objects. If this value is NULL, then
	  the entire tree of objects pointed to by 'co' is deleted
	  and becomes invalid.
co - the object to add to the list (may be NULL)
pred - the object after which 'co' should be inserted. If this is NULL
then 'co' is added to the head of the list.

**Result:**
If 'co' is NULL, this function will record that fact in the
internal accumulated error of 'headObj'. This error record
can be retrieved using CxObjError() and cleared using
ClearCxObjError().

**Bugs:**
Until V38, passing a NULL 'headObj' parameter would cause low-memory
access and unpredictable results.

**See also:** CxObjError(), ClearCxObjError()

---

### commodities.library/InvertKeyMap (V36)

**generate an input event from an ANSI code.**

**Synopsis:**
```c
BOOL success = InvertKeyMap(uint32 ansiCode,
                     struct InputEvent *event,
                     struct KeyMap *km);
```

**Description:**
This function uses the system call MapANSI() to figure out what
InputEvent translates to an ANSI character code 'ansiCode'. The
InputEvent pointed to by 'event' is filled in with that information.
The KeyMap 'km' is used for the translation, unless it is NULL, in
which case the current system default keymap is used.

**Inputs:**
ansiCode - the ANSI code to convert to an input event
event - the InputEvent to fill-in
km - the keymap to use for the translation, or NULL to use the
     current system default keymap.

**Result:**
success - TRUE if the translation worked, FALSE otherwise.

**Notes:**
Older versions of this documentation stated "It does not look up
the high key map (keystrokes with scan codes greater than 0x40)."
which was wrong.

**Bugs:**
This function currently handles one-deep dead keys (such as
<alt f>o ).

Prior to V40, this function was not initializing the ie_SubClass
and ie_TimeStamp fields of the InputEvent structure. A simple work
around to the problem is to clear these values to 0 before making
a call to this function:

	struct InputEvent ie;

	    ie.ie_SubClass           = 0;
	    ie.ie_TimeStamp.tv_secs  = 0;
	    ie.ie_TimeStamp.tv_micro = 0;
	    if (InvertKeyMap(ansiCode,&ie,NULL))
	    ...

**See also:** cx_lib/InvertString()

---

### commodities.library/MatchIX (V38)

**see if an input event matches an initialized input
	   expression.**

**Synopsis:**
```c
match = MatchIX(event,ix);

BOOL MatchIX(struct InputEvent *,IX *);
```

**Description:**
This function determines whether an input event matches an
initialized input expression. Applications generally do not
need to call this function as filter objects will normally provide
all the event filtering needed. Nevertheless, MatchIX()
can come in handy as it is the same function used to match an
event to the various filter objects when an event makes its way
through the input network.

**Inputs:**
event - the input event to match against the input expression
ix - the input expression for the comparison

**Result:**
match - TRUE if the input event matches the input expression, or
	FALSE if not

**See also:** <libraries/commodities.h>, ParseIX()

---

### commodities.library/ParseIX (V36)

**initialize an input expression given a description string.**

**Synopsis:**
```c
int32 failureCode = ParseIX(CONST_STRPTR description, IX *ix);
```

**Description:**
Given an input description string and an allocated input
expression, sets the fields of the input expression to
correspond to the description string.

**Inputs:**
description - the string to parse
ix - the input expression to hold the result of the parse

**Result:**
failureCode -  0 if all went well,
       -1 if tokens after end (code spec)
       -2 if 'description' was NULL
       -3 if mousecode/keycode is missing

**See also:** <libraries/commodities.h>, MatchIX()

---

### commodities.library/RemoveCxObj (V36)

**remove a commodity object from a list.**

**Synopsis:**
```c
RemoveCxObj(co);

VOID RemoveCxObj(CxObj *);
```

**Description:**
This function removes 'co' from any list it may be a part of.
Will not crash if 'co' is NULL, or if it has not been inserted
in a list.

**Inputs:**
co - the object to remove (may be NULL)

**See also:** AttachCxObj(), EnqueueCxObj(), InsertCxObj()

---

### commodities.library/RouteCxMsg (V36)

**set the next destination of a commodity message.**

**Synopsis:**
```c
VOID RouteCxMsg(CxMsg *cxm, CxObj *co);
```

**Description:**
Establishes the next destination of a commodity message
to be 'co', which must be a valid commodity object, and
must be linked in ultimately to commodities' object list.

Routing of an object is analogous to a 'goto' in a program.
There is no effect on the message's routing stack.

**Inputs:**
cxm - the commodity message to route (must NOT be NULL)
co - the commodity object to route the message to (must NOT be NULL)

**See also:** DivertCxMsg()

---

### commodities.library/SetCxObjPri (V36)

**set the priority of a commodity object.**

**Synopsis:**
```c
int32 oldPri = SetCxObjPri(CxObj *co, int32 pri);
```

**Description:**
This function sets the priority of a commodity object for the
purposes of EnqueueCxObj().

It is strongly recommended that the ToolTypes environment be
utilized to provide end-user control over the priority of
 	brokers, but application specific ordering of other objects
within their lists is not dictated.

**Inputs:**
co - the commodity object to affect (may be NULL)
pri - the object's new priority in the range -128 to +127. A value
      of 0 is normal.

**Result:**
oldPri - the previous priority of the object or 0 if 'co' was NULL.
	 This value is only returned in V38 and beyond.

**Bugs:**
This function will not reposition an object within its list when
its priority changes. To attain the same effect, first remove the
object from its list using RemoveCxObj(), set its priority using
SetCxObjPri(), and reinsert it in the list using EnqueueCxObj().

**See also:** EnqueueCxObj()

---

### commodities.library/SetFilter (V36)

**change the matching condition of a commodity filter.**

**Synopsis:**
```c
SetFilter(filter,text);

VOID SetFilter(CxObj *,STRPTR);
```

**Description:**
This function changes the matching condition of a commodity input
filter to that described by the input description string 'text'.

**Inputs:**
filter - the filter object to affect (may be NULL)
text - the new matching conditions for the filter

**Result:**
The internal error of 'filter' will have the COERR_BADFILTER
bit set or cleared depending on the failure or success of this
function.

**See also:** SetFilterIX(), CxObjError()

---

### commodities.library/SetFilterIX (V36)

**change the matching condition of a commodity filter.**

**Synopsis:**
```c
SetFilterIX(filter,ix);

VOID SetFilterIX(CxObj *,IX *);
```

**Description:**
This function changes the matching condition of a commodity input
filter to that described by the binary input expression pointed by
'ix'.

Input expressions are defined in <libraries/commodities.h>.
It is important to remember that the first field of the input
expression structure must indicate which version of the
input expression structure is being used.

**Inputs:**
filter - the filter object to affect (may be NULL)
ix - the new matching conditions for the filter

**Result:**
The internal error of 'filter' will have the COERR_BADFILTER
bit set or cleared depending on the failure or success of this
function.

**See also:** SetFilter(), CxObjError()

---

### commodities.library/SetTranslate (V36)

**replace a translator object's translation list.**

**Synopsis:**
```c
SetTranslate(translator,events);

VOID SetTranslate(CxObj *,struct InputEvent *);
```

**Description:**
This function replaces the translation list of a commodity
translator object with the linked list starting at 'events'.

A NULL value for 'events' indicates that the object 'translator'
should swallow all commodity messages that are sent its way.

Note that the input events are not copied into commodities' private
memory, but the value of 'events' is used -- asynchronously to the
application program -- to find a chain of InputEvents in the
application's data space. At the time of translation, each input event
is copied into its own new commodity message.

The above means that no other commodities' user, nor
commodities.library itself will be modifying your list of InputEvents.
On the other hand, your program must not corrupt the input event
chain that has been presented to a translator.

**Inputs:**
translator - the translator object to affect (may be NULL)
events - the new input event translation list

**Bugs:**
The list of input events manipulated by a translator object is
inserted in reverse order in the commodities network, and come out
of the network in reverse order as well. The cx_lib/InvertString()
function creates lists of input events that are in reverse order so
they can be used directly with translator objects.

**See also:** <devices/inputevent.h>, cx_lib/CxTranslate()

---
