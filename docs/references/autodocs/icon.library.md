# icon.library — Autodoc Reference

*Filtered to AmigaOS V39 and below.*

**Functions:** 14

## Function Index

- **AddFreeList** — 
- **BumpRevision** — 
- **BumpRevisionLength** — 
- **DeleteDiskObject** (V37) — 
- **FindToolType** — 
- **FreeAlloc** (V36) — 
- **FreeDiskObject** — 
- **FreeFreeList** — 
- **GetDefDiskObject** (V36) — 
- **GetDiskObject** — 
- **GetDiskObjectNew** (V36) — 
- **MatchToolValue** — 
- **PutDefDiskObject** (V36) — 
- **PutDiskObject** — 

## Functions

### icon.library/AddFreeList

**Synopsis:**
```c
BOOL status = AddFreeList(struct FreeList *freelist,
                   APTR mem, uint32 len);
```

**Description:**
This routine adds the specified memory to the free list.
The free list will be extended (if required).  If there
is not enough memory to complete the call, NULL is returned.

Note that AddFreeList() does NOT allocate the requested memory.
It only records the memory in the free list.

**Inputs:**
freelist -- a pointer to a FreeList structure
mem -- the base of the memory to be recorded
len -- the length of the memory to be recorded

**Result:**
status -- TRUE if the call succeeded else FALSE;

**See also:** exec.library/AllocTaskMemEntry
exec.library/FreeEntry
icon.library/FreeFreeList
workbench/workbench.h

---

### icon.library/BumpRevision

**Synopsis:**
```c
result = BumpRevision(newbuf, oldname)

STRPTR BumpRevision(STRPTR, STRPTR);
```

**Description:**
BumpRevision takes a name and turns it into a "copy_of_name".
It knows how to deal with copies of copies.  The routine
will truncate the new name to the maximum dos name size
(currently 30 characters).

**Inputs:**
newbuf - the new buffer that will receive the name
  (it must be at least 31 characters long).
oldname - the original name

**Result:**
result - a pointer to newbuf

**Example:**
```c
oldname                          newbuf
-------                          ------
"foo"                            "Copy_of_foo"
"Copy_of_foo"                    "Copy_2_of_foo"
"Copy_2_of_foo"                  "Copy_3_of_foo"
"Copy_199_of_foo"                "Copy_200_of_foo"
"Copy foo"                       "Copy_of_copy foo"
"Copy_0_of_foo"                  "Copy_1_of_foo"
"012345678901234567890123456789" "Copy_of_0123456789012345678901"
```

**Notes:**
Please use BumpRevisionLength() with a larger buffer with
icon.library 51.14 or higher.

**See also:** icon.library/BumpRevisionLength

---

### icon.library/BumpRevisionLength

**Synopsis:**
```c
result = BumpRevisionLength(newbuf, oldname, maxlength)

STRPTR BumpRevisionLength(STRPTR, STRPTR, uint32);
```

**Description:**
BumpRevisionLength takes a name and turns it into a "copy_of_name".
It knows how to deal with copies of copies.  The routine
will truncate the new name to the passed in maximum length.

**Inputs:**
newbuf - the new buffer that will receive the name
  (it must be at least maxlength + 1 characters long).
oldname - the original name
maxlength - the maximum length of the new name. Must be at least 30.

**Result:**
result - a pointer to newbuf or NULL when maxlength was smaller
  than 30.

**Example:**
```c
oldname                maxlength newbuf
-------                --------- ------
"foo"                         30 "Copy_of_foo"
"Copy_of_foo"                 30 "Copy_2_of_foo"
"Copy_2_of_foo"               30 "Copy_3_of_foo"
"Copy_199_of_foo"             30 "Copy_200_of_foo"
"Copy foo"                    30 "Copy_of_copy foo"
"Copy_0_of_foo"               30 "Copy_1_of_foo"
"01234567890123456789012345"  30 "Copy_of_0123456789012345678901"
"01234567890123456789012345" 100 "Copy_of_01234567890123456789012345"
```

**See also:** icon.library/BumpRevision

---

### icon.library/DeleteDiskObject (V37)

**Synopsis:**
```c
result = DeleteDiskObject(name)

BOOL DeleteDiskObject(STRPTR);
```

**Description:**
This routine will try to delete a Workbench disk object from disk.
The name parameter will have ".info" postpended to it, and the
icon file of that name will be deleted.  If the call fails,
it will return FALSE. The reason for the failure may be obtained
via dos.library/IoErr().

This call also updates the Workbench screen if needed.

Using this routine protects you from any future changes to
the way icons are stored within the system.

**Inputs:**
name -- name of the object (char *)

**Result:**
result -- TRUE if it worked, FALSE if not.

**Example:**
```c
error = 0;

/* Check if you have the right library version */
if(IconBase->lib_Version > 36)
{
    if (!DeleteDiskObject(name))
 error = IoErr();
}
else
{
    /* Delete name plus ".info" */
}

if (error != 0)
{
    /* Do error routine...*/
}
```

**See also:** dos.library/IoErr
icon.library/PutDiskObject
icon.library/GetDiskObject
icon.library/FreeDiskObject
icon.library/GetIconTagList
icon.library/PutIconTagList

---

### icon.library/FindToolType

**Synopsis:**
```c
value = FindToolType(toolTypeArray, typeName)

STRPTR FindToolType(STRPTR *, STRPTR);
```

**Description:**
This function searches a tool type array for a given entry,
and returns a pointer to that entry.  This is useful for
finding standard tool type variables.  The returned
value is not a new copy of the string but is only
a pointer to the part of the string after typeName.

**Inputs:**
toolTypeArray -- an array of strings (STRPTR *).
typeName -- the name of the tooltype entry (STRPTR).

**Result:**
value -- a pointer to a string that is the value bound to typeName,
 or NULL if typeName is not in the toolTypeArray.

**Example:**
```c
Assume the tool type array has two strings in it:
    "FILETYPE=text"
    "TEMPDIR=:t"

FindToolType( toolTypeArray, "FILETYPE" ) returns "text"
FindToolType( toolTypeArray, "filetype" ) returns "text"
FindToolType( toolTypeArray, "TEMPDIR" )  returns ":t"
FindToolType( toolTypeArray, "MAXSIZE" )  returns NULL
FindToolType( toolTypeArray, "text" )     returns NULL
FindToolType( toolTypeArray, ":t" )       returns NULL
```

**Notes:**
icon.library V44 tolerates tool type strings with additional
blanks around the '=' character, such as in "FILETYPE = text".
Older icon.library versions did not support this.

**See also:** icon.library/MatchToolValue

---

### icon.library/FreeAlloc (V36)

**Synopsis:**
```c
APTR memory = FreeAlloc(struct FreeList *freelist,
                 uint32 len, uint32 type);
```

**Description:**
This routine allocates the amount of memory specified and
then adds it to the free list.  The free list will be extended
(if required).  If there is not enough memory to complete the call,
a null is returned.

Note that FreeAlloc not only allocates the requested memory
but also records the memory in the free list.

**Inputs:**
freelist -- a pointer to a FreeList structure
len -- the length of the memory to be recorded; must be > 0
type -- the type of memory to be allocated

**Result:**
memory -- a pointer to the newly allocated memory chunk
   or zero if the call failed.

**Notes:**
This function was implemented in all icon.library versions starting
with V36. However, it was never documented.

**See also:** AllocTaskMemEntry, FreeEntry, FreeFreeList, FreeFree

---

### icon.library/FreeDiskObject

**Synopsis:**
```c
FreeDiskObject(diskobj)

void FreeDiskObject(struct DiskObject *);
```

**Description:**
This routine frees all memory in a Workbench disk object, and the
object itself.  It is implemented via FreeFreeList().

GetDiskObject() takes care of all the initialization required
to set up the object's free list.  This procedure may ONLY
be called on a DiskObject allocated via GetDiskObject().

**Inputs:**
diskobj -- a pointer to a DiskObject structure; as of V44,
    a NULL diskobj pointer will be ignored.

**See also:** icon.library/GetDiskObject
icon.library/PutDiskObject
icon.library/DeleteDiskObject
icon.library/FreeFreeList
icon.library/GetIconTagList
icon.library/PutIconTagList

---

### icon.library/FreeFreeList

**Synopsis:**
```c
void FreeFreeList(struct FreeList *freelist);
```

**Description:**
This routine frees all memory in a free list, and the
free list itself.  It is useful for easily getting
rid of all memory in a series of structures.  There is
a free list in a Workbench object, and this contains
all the memory associated with that object.

A FreeList is a list of MemList structures.  See the
MemList and MemEntry documentation for more information.

If the FreeList itself is in the free list, it must be
in the first MemList in the FreeList.

**Inputs:**
freelist -- a pointer to a FreeList structure; as of V44
    a NULL free parameter will be ignored.

**See also:** exec.library/AllocTaskMemEntry
exec.library/FreeEntry
icon.library/AddFreeList
workbench/workbench.h

---

### icon.library/GetDefDiskObject (V36)

**Synopsis:**
```c
diskobj = GetDefDiskObject(def_type)

struct DiskObject *GetDefDiskObject(LONG);
```

**Description:**
This routine reads in a default Workbench disk object from disk.
The valid def_types can be found in workbench/workbench.h and
currently include WBDISK thru WBKICK. If the call fails,
it will return NULL. The reason for the failure may be obtained
via IoErr().

Using this routine protects you from any future changes to
the way default icons are stored within the system.

**Inputs:**
def_type -- default icon type (WBDISK thru WBKICK).

**Result:**
diskobj -- the default Workbench disk object in question

**Notes:**
icon.library V36 through V40 did not support the WBDEVICE default
icon type.

**See also:** dos.library/IoErr
icon.library/PutDefDiskObject
icon.library/PutIconTagList

---

### icon.library/GetDiskObject

**Synopsis:**
```c
diskobj = GetDiskObject(name)

struct DiskObject *GetDiskObject(STRPTR);
```

**Description:**
This routine reads in a Workbench disk object in from disk.  The
name parameter will have ".info" postpended to it, and the
icon file of that name will be read.  If the call fails,
it will return NULL.  The reason for the failure may be obtained
via IoErr().

Using this routine protects you from any future changes to
the way icons are stored within the system.

A FreeList structure is allocated just after the DiskObject
structure; FreeDiskObject makes use of this to get rid of the
memory that was allocated.

**Inputs:**
name -- name of the object (STRPTR) or NULL if you just want a
 DiskObject structure allocated for you (useful when
 calling AddAppIcon() in workbench.library).

**Result:**
diskobj -- the Workbench disk object in question

**See also:** dos.library/IoErr
icon.library/DeleteDiskObject
icon.library/FreeDiskObject
icon.library/GetDiskObjectNew
icon.library/GetIconTagList
icon.library/NewDiskObject
icon.library/PutDiskObject
icon.library/PutIconTagList
workbench.library/AddAppIconA

---

### icon.library/GetDiskObjectNew (V36)

**Synopsis:**
```c
diskobj = GetDiskObjectNew(name)

struct DiskObject *GetDiskObjectNew(STRPTR);
```

**Description:**
This routine reads in a Workbench disk object in from disk.  The
name parameter will have ".info" postpended to it, and the
icon file of that name will be read.  If the call fails,
it will return zero.  The reason for the failure may be obtained
via IoErr().

Using this routine protects you from any future changes to
the way icons are stored within the system.

A FreeList structure is allocated just after the DiskObject
structure; FreeDiskObject makes use of this to get rid of the
memory that was allocated.

This call is functionally identical to GetDiskObject() with one
exception. If its call to GetDiskObject() fails, this function calls
GetDefDiskObject(). This is useful when there is no .info file for the
icon you are trying to get a disk object for. Applications that use
workbench application windows MUST use this call if they want to handle
the user dropping an icon (that doesn't have a ".info" file) on their
window. The V2.0 icon editor program is an example of a Workbench
application window that uses this call.

**Inputs:**
name -- name of the object (STRPTR) or NULL if you just want a
 DiskObject structure allocated for you (useful when
 calling AddAppIcon() in workbench.library).

**Result:**
diskobj -- the Workbench disk object in question

**See also:** dos.library/IoErr
icon.library/FreeDiskObject
icon.library/GetDiskObject
icon.library/PutDiskObject
icon.library/DeleteDiskObject
icon.library/GetIconTagList
icon.library/PutIconTagList
workbench.library/AddAppIconA

---

### icon.library/MatchToolValue

**Synopsis:**
```c
result = MatchToolValue(typeString, value)

BOOL MatchToolValue(STRPTR, STRPTR);
```

**Description:**
MatchToolValue is useful for parsing a tool type value for
a known value.  It knows how to parse the syntax for a tool
type value (in particular, it knows that '|' separates
alternate values).  Note that the parsing is case insensitive.

**Inputs:**
typeString -- a ToolType value (as returned by FindToolType)
value -- you are interested if value appears in typeString

**Result:**
result -- TRUE if the value was in typeString else FALSE.

**Example:**
```c
Assume there are two type strings:
    type1 = "text"
    type2 = "a|b|c"

MatchToolValue( type1, "text" ) returns TRUE
MatchToolValue( type1, "TEXT" ) returns TRUE
MatchToolValue( type1, "data" ) returns FALSE
MatchToolValue( type2, "a" )    returns TRUE
MatchToolValue( type2, "b" )    returns TRUE
MatchToolValue( type2, "d" )    returns FALSE
MatchToolValue( type2, "a|b" )  returns FALSE
```

**Notes:**
icon.library V44 skips blank spaces surrounding the typeString
options and the value string. Older icon.library versions did
not support this.

**See also:** icon.library/FindToolType
utility.library/Stricmp

---

### icon.library/PutDefDiskObject (V36)

**Synopsis:**
```c
status = PutDefDiskObject(diskobj)

BOOL PutDefDiskObject(struct DiskObject *);
```

**Description:**
This routine writes out a DiskObject structure, and its
associated information.  If the call fails, FALSE will
be returned.  The reason for the failure may be obtained
via IoErr().

Note that this function calls PutDiskObject() internally which means
that this call (if sucessful) notifies workbench than an icon has
been created/modified.

Using this routine protects you from any future changes to
the way default icons are stored within the system.

**Inputs:**
diskobj -- a pointer to a DiskObject

**Result:**
status -- TRUE if the call succeeded else FALSE

**See also:** dos.library/IoErr
icon.library/GetDefDiskObject
icon.library/GetIconTagList
icon.library/PutDiskObject

---

### icon.library/PutDiskObject

**Synopsis:**
```c
status = PutDiskObject(name, diskobj)

BOOL PutDiskObject(STRPTR, struct DiskObject *);
```

**Description:**
This routine writes out a DiskObject structure, and its
associated information.  The file name of the info
file will be the name parameter with ".info" postpended
to it.  If the call fails, FALSE will be returned.  The
reason for the failure may be obtained via IoErr().

As of release V2.0, PutDiskObject() (if successful) notifies Workbench
when an icon has been created/modified.

Using this routine protects you from any future changes to
the way icons are stored within the system.

**Inputs:**
name -- name of the object (pointer to a character string)
diskobj -- a pointer to a DiskObject

**Result:**
status -- TRUE if the call succeeded else FALSE

**Notes:**
It is recommended that if you wish to copy an icon from one place
to another than you use GetDiskObject() and PutDiskObject()
and do not copy them directly.

**See also:** dos.library/IoErr
icon.library/DeleteDiskObject
icon.library/FreeDiskObject
icon.library/GetDiskObject
icon.library/GetIconTagList
icon.library/PutIconTagList

---
