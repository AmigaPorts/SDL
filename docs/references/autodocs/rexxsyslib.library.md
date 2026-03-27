# rexxsyslib.library — Autodoc Reference

*Filtered to AmigaOS V39 and below.*

**Functions:** 10

## Function Index

- **ClearRexxMsg** — 
- **CreateArgstring** — 
- **CreateRexxMsg** — 
- **DeleteArgstring** — 
- **DeleteRexxMsg** — 
- **FillRexxMsg** — 
- **IsRexxMsg** — 
- **LengthArgstring** — 
- **LockRexxBase** — 
- **UnlockRexxBase** — 

## Functions

### rexxsyslib.library/ClearRexxMsg

**Synopsis:**
```c
ClearRexxMsg(msgptr, count)

VOID ClearRexxMsg(struct RexxMsg *,ULONG);
```

**Description:**
This function will DeleteArgstring() one or more argstrings from
the RexxMsg and clear the slot.  The count is used to select the
number of slots to clear.

**Inputs:**
msgptr - A pointer to a RexxMsg
count - The number of slots to be cleared.  The number can be from
 1 to 16.  (There are 16 slots)

**Result:**
All of the slots in the given count will be cleared and the argstring
will have been released.

**See also:** FillRexxMsg(), DeleteRexxMsg(), DeleteArgstring(), CreateArgstring()

---

### rexxsyslib.library/CreateArgstring

**Synopsis:**
```c
argstr = CreateArgstring(string, length)

STRPTR CreateArgstring(STRPTR, ULONG);
```

**Description:**
Allocates a RexxArg structure and copies the supplied string into it.
The returned pointer points at the string part of the structure
and can be treated like an ordinary string pointer.  (However, care
must be taken that you do not change the string)

**Inputs:**
string - A pointer at your input string
length - The number of bytes of your input string you wish copied.
  (NOTE:  You are limited to 65,535 byte strings)

**Result:**
argstr - A pointer to the argument string.  The results are returned
  in both A0 and D0.  You should always check the result
  as an allocation failure would cause an error.

**See also:** DeleteArgstring(), LengthArgstring(), ClearRexxMsg(), FillRexxMsg()

---

### rexxsyslib.library/CreateRexxMsg

**Synopsis:**
```c
rexxmsg = CreateRexxMsg(port, extension, host)

struct RexxMsg *CreateRexxMsg(struct MsgPort *, STRPTR, STRPTR);
```

**Description:**
This functions allocates an ARexx message packet.  The RexxMsg
consists of a standard EXEC message structure extended to include
the ARexx specific information.

**Inputs:**
port - A pointer to a public or private message port.  This *MUST*
be a valid port as this is where the message will be replied.

extension - A pointer to a NULL terminated string that is to be used
     as the default extension for the REXX scripts.  If this
     is NULL, the default is "REXX"

host - A pointer to a NULL terminated string that is to be used
as the default host port.  The name must be the same as the
name of the public message port that is to be the default host.
If this field is NULL, the default is REXX.

**Result:**
rexxmsg - A RexxMsg structure

**Notes:**
The extension and host strings must remain valid for as long as the
RexxMsg exists as only the pointer to those strings are stored.

**See also:** DeleteRexxMsg(), ClearRexxMsg(), FillRexxMsg()

---

### rexxsyslib.library/DeleteArgstring

**Synopsis:**
```c
DeleteArgstring(argstring)

VOID DeleteArgstring(STRPTR);
```

**Description:**
Releases an argstring.  The argstring must have been created by ARexx

**Inputs:**
argstring - A pointer to the string buffer of an argstring.

**See also:** CreateArgstring(), ClearRexxMsg(), FillRexxMsg()

---

### rexxsyslib.library/DeleteRexxMsg

**Synopsis:**
```c
DeleteRexxMsg(packet)

VOID DeleteRexxMsg(struct RexxMsg *);
```

**Description:**
The function releases an ARexx message packet that was allocated
with CreateRexxMsg().  Any argument fields in the RexxMsg structure
should be cleared before calling this function as it does
not release them for you.

**Inputs:**
packet - A pointer to a RexxMsg structure allocated by CreateRexxMsg()

**Example:**
```c
if (rmsg=CreateRexxMsg(myport,"myapp","MYAPP_PORT"))
{
	/* Do my think with rmsg */
	ClearRexxMsg(rmsg,16);	/* We may not want to clear all 16 */
	DeleteRexxMsg(rmsg);
}
```

**See also:** CreateRexxMsg(), ClearRexxMsg()

---

### rexxsyslib.library/FillRexxMsg

**Synopsis:**
```c
result = FillRexxMsg(msgptr, count, mask)

BOOL FillRexxMsg(struct RexxMsg *,ULONG,ULONG);
```

**Description:**
This function will convert and install up to 16 argument strings into
a RexxMsg structure.  The message packet's argument fields must be
set to either a pointer to a NULL terminated string or an integer value
The mask, bits 0 to 15, correspond to the type of value is stored
in the argument slot.  If the bit is cleared, the argument is a
string pointer; if the bit is set, the argument is an integer.

**Inputs:**
msgptr - Pointer to a RexxMsg (allocated via CreateRexxMsg)
count - The number of argument slots to fill in.  This number should
 be from 1 to 16.

mask - A bit mask corresponding to the 16 fields that is used to
determine the type of the field.

**Result:**
result - A boolean.  If it is TRUE, the call worked.  If it is false,
  some allocation did not work.  All argstrings that were
  created will be released.

**See also:** ClearRexxMsg(), CreateArgstring(), DeleteArgstring(), CreateRexxMsg()

---

### rexxsyslib.library/IsRexxMsg

**Synopsis:**
```c
result = IsRexxMsg(msgptr)

BOOL IsRexxMsg(struct RexxMsg *);
```

**Description:**
This function can be used to determine if a message came from an
ARexx program.

**Inputs:**
msgptr - A pointer to the suspected RexxMsg.

**Result:**
result - A boolean:  TRUE if it is an ARexx message, FALSE if not.

**See also:** CreateRexxMsg()

---

### rexxsyslib.library/LengthArgstring

**Synopsis:**
```c
length = LengthArgstring(argstring)

ULONG LengthArgstring(STRPTR);
```

**Description:**
This function returns the length value stored in the argstring.
This is *NOT* the same as doing a strlen() type call on the
argstring.  (Note that argstrings may contain NULLs)

**Inputs:**
argstring - A pointer to an argstring that was created by ARexx

**Result:**
length - The length of the argstring.

**See also:** CreateArgstring()

---

### rexxsyslib.library/LockRexxBase

**Synopsis:**
```c
LockRexxBase(resource)

VOID LockRexxBase(ULONG);
```

**Description:**
Secures the specified resource in the ARexx library base.

**Inputs:**
resource - A manifest constant defining which resource to lock.
    ZERO locks all resources.

**Notes:**
Currently, only ZERO resource type is available.  You *MUST* make
sure that you do not call this function with an undefined value
as it may become defined at some future date and cause unwanted
behavior.

**See also:** UnlockRexxBase()

---

### rexxsyslib.library/UnlockRexxBase

**Synopsis:**
```c
UnlockRexxBase(resource)

VOID UnlockRexxBase(ULONG);
```

**Description:**
Releases the specified resource in the ARexx library base.

**Inputs:**
resource - A manifest constant defining which resource to unlock.
    This value *MUST* match the value used in the matching
    LockRexxBase() call.

**Notes:**
Currently, only ZERO resource type is available.  You *MUST* make
sure that you do not call this function with an undefined value
as it may become defined at some future date and cause unwanted
behavior.  You *MUST* make sure that you only call this function
after a matching call to LockRexxBase() was made.

**See also:** LockRexxBase()

---
