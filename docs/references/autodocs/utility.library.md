# utility.library — Autodoc Reference

*Filtered to AmigaOS V39 and below.*

**Functions:** 34

## Function Index

- **AddNamedObject** (V39) — add a named object to the given namespace.
- **AllocateTagItems** (V36) — allocate a tag list.
- **AllocNamedObject** (V39) — allocate a named object.
- **Amiga2Date** (V36) — fill in a ClockData structure based on a system
- **ApplyTagChanges** (V39) — change a tag list based on a second tag list.
- **AttemptRemNamedObject** (V39) — attempt to remove a named object.
- **CallHookPkt** (V36) — invoke a Hook function callback.
- **CheckDate** (V36) — checks a ClockData structure for legal date.
- **CloneTagItems** (V36) — copy a tag list.
- **CreateSplayTree** — Allocate a splay tree data structure. (V53.2)
- **Date2Amiga** (V36) — calculate seconds from 01-Jan-1978.
- **FilterTagChanges** (V36) — eliminate tags which specify no change.
- **FilterTagItems** (V36) — remove selected items from a tag list.
- **FindNamedObject** (V39) — find the next object of a given name.
- **FindTagItem** (V36) — scan a tag list for a specific tag.
- **FreeNamedObject** (V39) — frees a name object.
- **FreeTagItems** (V36) — free an allocated tag list.
- **GetTagData** (V36) — obtain the data corresponding to a tag.
- **GetUniqueID** (V39) — return a relatively unique number.
- **MapTags** (V36) — convert ti_Tag values in a list via map pairing.
- **NamedObjectName** (V39) — return the name of the object.
- **NextTagItem** (V36) — iterate through a tag list.
- **PackBoolTags** (V36) — builds a "flag" word from a tag list.
- **PackStructureTags** (V39) — pack a structure with values from taglist.
- **RefreshTagItemClones** (V36) — rejuvenate a clone from the original.
- **ReleaseNamedObject** (V39) — free a named object.
- **RemNamedObject** (V39) — remove a named object.
- **Stricmp** (V37) — case-insensitive string comparison.
- **Strlen** — Determine the length of a string. (V53.4)
- **Strnicmp** (V37) — length-limited case-insensitive string compare.
- **TagInArray** (V36) — check if a tag value appears in an array of tag values.
- **ToLower** (V37) — convert a character to lower case.
- **ToUpper** (V37) — convert a character to upper case.
- **UnpackStructureTags** (V39) — unpack a structure to values in taglist.

## Functions

### utility.library/AddNamedObject (V39)

**add a named object to the given namespace.**

**Synopsis:**
```c
success = AddNamedObject(nameSpace, object);

BOOL AddNamedObject(struct NamedObject *, struct NamedObject *);
```

**Description:**
Adds a new item to a NameSpace.  If the NameSpace doesn't support
duplicate names, a search for a duplicate will be made, and
0 (failure) will be returned.  Otherwise, the entry will be
Enqueue()ed to the NameSpace.

**Inputs:**
nameSpace - the name space to add to (NULL for root namespace)
object - the object to add  (If NULL, will return failure)

**Result:**
success - whether the operation succeeded.  Check this always!

**See also:** AttemptRemNamedObject(), RemNamedObject()

---

### utility.library/AllocateTagItems (V36)

**allocate a tag list.**

**Synopsis:**
```c
tagList = AllocateTagItems(numTags);

 struct TagItem *AllocateTagItems(ULONG);
```

**Description:**
Allocates the specified number of usable TagItems slots.
 The TagItems are allocated in one linear block.

**Inputs:**
numTags - the number of TagItem slots you want to allocate.

**Result:**
tagList - the allocated chain of TagItem structures, or NULL if
           there was not enough memory. An allocated tag list must
           eventually be freed using FreeTagItems().

**See also:** <utility/tagitem.h>, FreeTagItems(), CloneTagItems()

---

### utility.library/AllocNamedObject (V39)

**allocate a named object.**

**Synopsis:**
```c
object = AllocNamedObjectA(name, tagList);

struct NamedObject *AllocNamedObjectA(STRPTR, struct TagItem *);

object = AllocNamedObject(name, Tag1, ...);

struct NamedObject *AllocNamedObject(STRPTR, ULONG, ...);
```

**Description:**
Allocates a NamedObject and initializes it as needed to the
name given. This object can then be used as an object in the
namespaces. Tags can be given to make an object contain a
namespace such that nested namespaces can be built.
When the object is allocated, it automatically has one use.
If you later wish to release this object such that others may
remove it from the namespace you must do a ReleaseNamedObject().

**Inputs:**
ANO_NameSpace - BOOL tag, default FALSE.  If this tag is
                TRUE, the named object will also have a
                name space attached to it.
ANO_UserSpace - ULONG tag, default 0.  If this tag is non-NULL
                it defines the size (in bytes) of the user
                space to be allocated with the named object
                and that will be pointed to by the no_Object
                pointer.  This memory is long-word aligned.
                If no space is defined, no_Object will be NULL.
ANO_Priority  - BYTE tag, default 0.  This tag lets you pick
                a priority for the named object for when it is
                placed into a name space.
ANO_Flags     - ULONG tag, default 0.  This tag lets you set
                the flags of the NameSpace (if you allocated
                one)  There currently are only TWO flags.
                Do *NOT* set *any* other bits as they are for
                future use!!!  (You can't read them anyway)
                The flags are:
                NSF_NODUPS      - Name space must be unique.
                NSF_CASE        - Name space is case sensitive

**Result:**
object - the object allocated, or NULL for failure. The object
         is defined as a pointer to a pointer.  You can do what you
         wish with the pointer. (It may be NULL or contain a pointer
         to memory that you had asked for in the tags.)

**See also:** FreeNamedObject(), <utility/name.h>

---

### utility.library/Amiga2Date (V36)

**fill in a ClockData structure based on a system
              time stamp**

**Synopsis:**
```c
Amiga2Date(seconds,result);

VOID Amiga2Date(ULONG,struct ClockData *);
```

**Description:**
Fills in a ClockData structure with the date and time calculated
from a ULONG containing the number of seconds from 01-Jan-1978
to the date.

**Inputs:**
seconds - the number of seconds from 01-Jan-1978.
result - a pointer to a ClockData structure that will be altered
         by this function

**See also:** CheckDate(), Date2Amiga()

---

### utility.library/ApplyTagChanges (V39)

**change a tag list based on a second tag list.**

**Synopsis:**
```c
ApplyTagChanges(list,changeList);

 VOID ApplyTagChanges(struct TagItem *, struct TagItem *);
```

**Description:**
For any tag that appears in both 'list' and 'changeList', this
 function will change the ti_Data field of the tag in 'list' to
 match the ti_Data field of the tag in 'changeList'. In effect,
 'changeList' contains a series of new values for tags already in
 'list'. Any tag in 'changeList' that is not in 'list' is ignored.

**Inputs:**
list - a list of existing tags (may be NULL)
 changeList - a list of tags to modify 'list' with (may be NULL)

**See also:** <utility/tagitem.h>, FilterTagChanges()

---

### utility.library/AttemptRemNamedObject (V39)

**attempt to remove a named object.**

**Synopsis:**
```c
result = AttemptRemNamedObject(object);

LONG AttemptRemNamedObject(struct NamedObject *);
```

**Description:**
Attempts to remove an object from whatever NameSpace it's in.
You must have found the object first (in order to get a use count)
before trying to remove it.  If the object is in use or is
in the process of being removed, this function will return
a failure code.  If the object is fully removed, the object will
then be available to be FreeNamedObject().

**Inputs:**
object - the object to attempt to remove  The object must be valid

**Result:**
success - FALSE if object is still in use (somewhere)
          TRUE if object was removed

**See also:** RemNamedObject(), AddNamedObject(), ReleaseNamedObject()

---

### utility.library/CallHookPkt (V36)

**invoke a Hook function callback.**

**Synopsis:**
```c
return = CallHookPkt(hook,object,message);

ULONG CallHookPkt(struct Hook *,APTR,APTR);

return = CallHook(hook, object, ...);
     
ULONG CallHook(struct Hook *, APTR, ...);
```

**Description:**
Performs the callback standard defined by a Hook structure.
Starting with release 50, Hooks *must* be called via one
of the system-supplied functions. Emulated code might need
a different calling convention than native code.

The prototype for a hook function looks like this:
ULONG HookFunc(struct Hook *hook, APTR object, APTR message);

'hook' is a pointer to the hook structure, 'object' points to the
object receiving the message, and 'message' points to the message
packet.

The second form, CallHook, allows the message packet to be built
on the stack.

**Inputs:**
hook    - pointer to an initialized Hook structure as defined in
          <utility/hooks.h>
object  - useful data structure in the particular context the hook is
          being used for.
message - pointer to a message to be passed to the hook. This is not
          an Exec Message structure, but is a message in the OOP sense.

**Result:**
return - the value returned by the hook function.

**Notes:**
Starting with V50, hooks and hook functions must completely adhere
to the standards set out in the documentation. This basically means:
- No direct calling of hook functions. This has been documented as being
  OK in the past, but this is not allowed anymore. You'll get away with
  it for now (to stay backward compatible), but this *is* considered
  a programming error.
- Don't mix up parameters, or ommit them. The parameters for a hook
  function are hook, object, message. No ommisions, no change in order.

	CallHookPkt calls the code in h_Entry. This pointer can either be a
	pointer to legacy 68k code, or to native code. ExecSG takes care to
	place native code into specially marked segments of memory. When h_Entry
	points to such a place, CallHookPkt knows that the code is native, and
	will directly branch to the code pointer. If it doesn't, then the code
	is assumed to be non-native (i.e. legacy 68k code), and the emulator
	is invoked at this code address.

	This form of transparency comes at a price: h_Entry must not be jumped
	to directly, as calling 68k legacy code from native code will result in
	a crash, and calling native code from 68k legacy code will result in
	native code being interpreted as 68k code, with completely unpredictable
	results.

	This function does not access any member of the hook structure except
	for the h_Entry field, therefore all other members are available for
	the applications use.

**See also:** <utility/hooks.h>

---

### utility.library/CheckDate (V36)

**checks a ClockData structure for legal date.**

**Synopsis:**
```c
seconds = CheckDate(date);

ULONG CheckDate(struct ClockData *);
```

**Description:**
Determines if the ClockData structure contains legal date information
and returns the number of seconds from 01-Jan-1978 to that date, or 0
if the ClockData structure contains illegal data.

**Inputs:**
date - a filled-in ClockData structure

**Result:**
seconds - 0 if date is invalid, otherwise the number of seconds from
          01-Jan-1978 to the date

**Bugs:**
The wday field of the ClockData structure is not checked.

**See also:** Amiga2Date(), Date2Amiga()

---

### utility.library/CloneTagItems (V36)

**copy a tag list.**

**Synopsis:**
```c
clone = CloneTagItems(original);

 struct TagItem *CloneTagItems(struct TagItem *);
```

**Description:**
Copies the essential contents of a tag list into a new tag list.

 The cloning is such that calling FindTagItem() with a given tag on
 the original or cloned tag lists will always return the same
 tag value. That is, the ordering of the tags is maintained.

**Inputs:**
original - tag list to clone. May be NULL, in which case an
            empty tag list is returned.

**Result:**
clone - copy of the original tag list, or NULL if there was not enough
         memory. This tag list must eventually by freed by calling
         FreeTagItems().

**See also:** <utility/tagitem.h>, AllocateTagItems(), FreeTagItems(),
 RefreshTagItemClones()

---

### utility.library/CreateSplayTree

**Allocate a splay tree data structure. (V53.2)**

**Synopsis:**
```c
tree = CreateSplayTree(hook)

struct SplayTree * CreateSplayTree(struct Hook * hook);
```

**Description:**
This function allocates and initializes a splay tree data structure
which will be empty to start with. Subsequently, nodes can be added,
searched for and removed.

A splay tree is a binary tree which reorganizes itself as new nodes
are added, removed and searched for. In response to the search
operations, the tree will become flatter and wider, improving the
responsiveness to search queries. As such, it is particularly
well-suited for cache operations.

**Inputs:**
hook -- Hook to invoke for comparing node keys in the tree.
    Your hook function is called as follows:

        difference = hook_function(hook,key1,key2)
            D0                      A0   A2   A1

        LONG hook_function(struct Hook * hook,
                           APTR key1,APTR key2);

    Your hook function must compare the two keys and return
    a value which indicates whether there is a difference between
    the two. The difference must be < 0 if key1 < key2, it must
    be 0 if key1 == key2 and it must be > 0 if key1 > key2.
    This is the same order a 'C' library function such as
    strcmp() uses.

**Result:**
tree -- If sufficient memory was available, a pointer to an empty
    splay tree. NULL otherwise. NULL will be returned if you
    forget to provide for the hook parameter.

**Notes:**
This function originally was documented to be present since version
50 of utility.library, but in fact was broken until 53.2.

Access arbitration is not ensured by the functions dealing with this
data structure and is therefore up to the caller. Both,
InsertSplayNode() and FindSplayNode() assume to have exclusive
access.

**See also:** DeleteSplayTree(), InsertSplayNode(), FindSplayNode()

---

### utility.library/Date2Amiga (V36)

**calculate seconds from 01-Jan-1978.**

**Synopsis:**
```c
seconds = Date2Amiga(date);

ULONG Date2Amiga(struct ClockData *);
```

**Description:**
Calculates the number of seconds from 01-Jan-1978 to the date
specified in the ClockData structure.

**Inputs:**
date - pointer to a ClockData structure containing the date of
       interest.

**Result:**
seconds - the number of seconds from 01-Jan-1978 to the date specified.

**Notes:**
This function does no sanity checking of the data in the ClockData
structure.

**See also:** Amiga2Date(), CheckDate()

---

### utility.library/FilterTagChanges (V36)

**eliminate tags which specify no change.**

**Synopsis:**
```c
FilterTagChanges(changeList,originalList,apply);

 VOID FilterTagChanges(struct TagItem *, struct TagItem *, ULONG);
```

**Description:**
This function goes through changeList. For each item found in
 changeList, if the item is also present in originalList, and their
 data values are identical, then the tag is removed from changeList.
 If the two tag's data values are different and the 'apply' value is
 non-zero, then the tag data in originalList will be updated to match
 the value from changeList.

**Inputs:**
changeList - list of new tags (may be NULL)
 originalList - a list of existing tags (may be NULL)
 apply - boolean specification as to whether the data values in
         originalList are to be updated to the data values in
         changeList.

**Example:**
```c
Assume you have an attribute list for an object (originalList)
 which looks like this:

         {ATTR_Size,  "large"},
         {ATTR_Color, "orange"},
         {ATTR_Shape, "square"}

 If you receive a new tag list containing some changes (changeList),
 which looks like this:

         {ATTR_Size,  "large"},
         {ATTR_Shape, "triangle"}

 If you call FilterTagChanges(), changeList will be modified to
 contain only those attributes which are different from those
 in originalList. All other items will have their tag values set to
 TAG_IGNORE. The resulting changeList will become:

         {TAG_IGNORE, "large"},
         {ATTR_Shape, "triangle"}

 If 'apply' was set to 0, originalList would be unchanged. If 'apply'
 was non-zero, originalList would be changed to:

         {ATTR_Size,  "large"},
         {ATTR_Color, "orange"},
         {ATTR_Shape, "triangle"}
```

**See also:** <utility/tagitem.h>, ApplyTagChanges()

---

### utility.library/FilterTagItems (V36)

**remove selected items from a tag list.**

**Synopsis:**
```c
numValid = FilterTagItems(tagList,filterArray,logic);

 ULONG FilterTagItems(struct TagItem *,Tag *,ULONG);
```

**Description:**
Removes tag items from a tag list (by changing ti_Tag to
 TAG_IGNORE) depending on whether its ti_Tag value is
 found in an array of tag values.

 If the 'logic' parameter is TAGFILTER_AND, then all items
 not appearing in 'tagArray' are excluded from 'tagList'.

 If 'logic' is TAGFILTER_NOT, then items not found in 'tagArray'
 are preserved, and the ones in the array are cast out.

**Inputs:**
tagList - input list of tag items which is to be filtered by having
           selected items changed to TAG_IGNORE.
 filterArray - an array of tag values, terminated by TAG_DONE, as
               specified in the documentation for TagInArray().
 logic - specification whether items in 'tagArray' are to be included
         or excluded in the filtered result.

**Result:**
numValid - number of valid items left in resulting filtered list.

**See also:** <utility/tagitem.h>, TagInArray()

---

### utility.library/FindNamedObject (V39)

**find the next object of a given name.**

**Synopsis:**
```c
object = FindNamedObject(nameSpace, name, lastObject);

struct NamedObject *FindNamedObject(struct NamedObject *, STRPTR,
                                    struct NamedObject *);
```

**Description:**
Finds an object and adds to the open count of the object. The
object is guaranteed not to be freed until ReleaseNamedObject() is
called. The name comparison is caseless, using the current
locale string comparison routines.

If name is NULL, then all objects will be matched.

If lastObject is non-NULL, it must be an object from the same
NameSpace found on a previous call to FindNamedObject(). It
will not be freed by this call. The search will start at the
node after lastobject, if non-NULL.

nameSpace is the name space from the named object given
or the root name space if NULL is given.

**Inputs:**
nameSpace - the name space to search
name - the name of the object to search for
lastObject - the starting point for the search or NULL

**Result:**
object - the first match found, or NULL for no match

**See also:** ReleaseNamedObject(), <utility/name.h>

---

### utility.library/FindTagItem (V36)

**scan a tag list for a specific tag.**

**Synopsis:**
```c
tag = FindTagItem(tagValue,tagList);

 struct TagItem *FindTagItem(Tag,struct TagItem *);
```

**Description:**
Scans a tag list and returns a pointer to the first item with
 ti_Tag matching the 'tagValue' parameter.

**Inputs:**
tagValue - tag value to search for
 tagList - tag item list to search (may be NULL)

**Result:**
tag - a pointer to the item with ti_Tag matching 'tagValue' or NULL
       if no match was found.

**See also:** <utility/tagitem.h>, GetTagData(), PackBoolTags(), NextTagItem()

---

### utility.library/FreeNamedObject (V39)

**frees a name object.**

**Synopsis:**
```c
FreeNamedObject(object);

VOID FreeNamedObject(struct NamedObject *);
```

**Description:**
Free one of a number of structures used by utility.library.
The item must not be a member of any NameSpace, and no one
may have it open other than yourself. If the object also
contained a NameSpace, that namespace must be empty.
Any additional space allocated via the datasize parameter
for AllocNamedObject() is also released.

**Inputs:**
object - the object to be freed

**See also:** AllocNamedObjectA()

---

### utility.library/FreeTagItems (V36)

**free an allocated tag list.**

**Synopsis:**
```c
FreeTagItems(tagList);

 VOID FreeTagItems(struct TagItem *);
```

**Description:**
Frees the memory of a TagItem list allocated either by
 AllocateTagItems() or CloneTagItems().

**Inputs:**
tagList - list to free, must have been obtained from
           AllocateTagItems() or CloneTagItems() (may be NULL)

**See also:** <utility/tagitem.h>, AllocateTagItems(), CloneTagItems()

---

### utility.library/GetTagData (V36)

**obtain the data corresponding to a tag.**

**Synopsis:**
```c
value = GetTagData(tagValue,defaultVal,tagList);

 ULONG GetTagData(Tag,ULONG,struct TagItem *);
```

**Description:**
Searches a tag list for a matching tag, and returns the
 corresponding ti_Data value for the TagItem found. If no match is
 found, this function returns the value passed in as 'default'.

**Inputs:**
tagValue - tag value to search for.
 defaultVal - value to be returned if tagValue is not found.
 tagList - the tag list to search.

**Result:**
value - the ti_Data value for the first matching TagItem, or 'default'
         if a ti_Tag matching 'Tag' is not found.

**See also:** <utility/tagitem.h>, FindTagItem(), PackBoolTags(), NextTagItem()

---

### utility.library/GetUniqueID (V39)

**return a relatively unique number.**

**Synopsis:**
```c
id = GetUniqueID();

ULONG GetUniqueID(VOID);
```

**Description:**
Returns a unique value each time it is called. This is useful for
things that need unique ID such as the GadgetHelp ID, etc.
Note that this is only unique for 4,294,967,295 calls to this
function. Under normal use this is not a problem.
This function is safe in interrupts.

**Result:**
id - a 32-bit value that is unique.

---

### utility.library/MapTags (V36)

**convert ti_Tag values in a list via map pairing.**

**Synopsis:**
```c
MapTags(tagList,mapList,mapType);

 VOID MapTags(struct TagItem *,struct TagItem *,ULONG);
```

**Description:**
Apply a "mapping list" mapList to tagList.

 If the ti_Tag field of an item in tagList appears as ti_Tag in some
 item in mapList, overwrite ti_Tag with the corresponding ti_Data
 from the map list.

 The mapType parameter specifies how the mapping operation is to
 proceed, with the following available types:

         MAP_REMOVE_NOT_FOUND
         If a tag in tagList does not appear in the mapList, remove
         it from tagList.

         MAP_KEEP_NOT_FOUND
         To have items which do not appear in the mapList survive the
         mapping process as-is.

 MapTags() is central to BOOPSI gadget interconnections where you want
 to convert the tag values from one space (the sender) to another (the
 receiver).

 The procedure will change the values of the input tag list
 tagList (but not mapList).

 You can "filter" a list by passing MAP_REMOVE_NOT_FOUND as mapType,
 and having the data items in mapList equal the corresponding tags.

 You can perform the inverse filter ("everything but") by passing
 a mapType of MAP_KEEP_NOT_FOUND, and creating a map item for every tag
 you want to filter out, pairing it with a mapped data value of
 TAG_IGNORE.

 For safety and "order independence" of tag item arrays, if you
 attempt to map some tag to the value TAG_DONE, the value TAG_IGNORE
 will be substituted instead.

**Inputs:**
tagList - input list of tag items which is to be mapped to tag values
           as specified in mapList.
 mapList - a "mapping list" tag list which pairs tag values expected to
           appear in tagList with new values to be substituted in the
           ti_Tag fields of tagList (may be NULL)
 mapType - one of the available mapping types as defined in
           <utility/tagitem.h>

**Example:**
```c
/* Consider this source list: */
     struct TagItem list[] =
     {
         {MY_SIZE,       71},
         {MY_WEIGHT,     200},
         {TAG_DONE,      }
    };

 /* And the mapping list: */
     struct TagItem map[] =
     {
         {MY_SIZE,       HIS_TALL},
         {TAG_DONE,      }
     };

 /* Then after MapTags(list,map,MAP_REMOVE_NOT_FOUND), 'list' will
    become: */
         {HIS_TALL,71},
         {TAG_IGNORE,},
         {TAG_DONE,}

 /* Or after MapTags(list,map,MAP_KEEP_NOT_FOUND), 'list' will
    become: */
         {HIS_TALL,  71},
         {MY_WEIGHT, 200},
         {TAG_DONE,  }
```

**Bugs:**
Prior to V39, the mapType parameter did not work. The function
 always behaved as if the parameter was set to MAP_KEEP_NOT_FOUND.

**See also:** <utility/tagitem.h>, ApplyTagChanges(), FilterTagChanges()

---

### utility.library/NamedObjectName (V39)

**return the name of the object.**

**Synopsis:**
```c
name = NamedObjectName(object);

STRPTR NamedObjectName(struct NamedObject *);
```

**Description:**
Returns the name of the object passed in...
Note that the name string is passed back as just a pointer to
a read-only name. If the object goes away, so does the name.

**Inputs:**
object - the object, may be NULL in which case this function
         returns NULL.

**Result:**
name - pointer to the name string, or NULL if 'object' is NULL.

**See also:** FindNamedObject(), RemNamedObject()

---

### utility.library/NextTagItem (V36)

**iterate through a tag list.**

**Synopsis:**
```c
tag = NextTagItem(tagItemPtr);

 struct TagItem *NextTagItem(struct TagItem **);
```

**Description:**
Iterates through a tag list, skipping and chaining as dictated by
 system tags. TAG_SKIP will cause it to skip the entry and a number
 of following tags as specified in ti_Data. TAG_IGNORE ignores that
 single entry, and TAG_MORE has a pointer to another array of tags (and
 terminates the current array!). TAG_DONE also terminates the current
 array. Each call returns either the next tagitem you should examine,
 or NULL when the end of the list has been reached.

**Inputs:**
tagItemPtr - doubly-indirect reference to a TagItem structure.
              The pointer will be changed to keep track of the
              iteration.

**Result:**
nextTag - each TagItem in the array or chain of arrays that should be
           processed according to system tag values defined in
           <utility/tagitem.h>) is returned in turn with successive
           calls.

**Example:**
```c
Iterate(struct TagItem *tags);
 {
     struct TagItem *tstate;
     struct TagItem *tag;

     tstate = tags;
     while (tag = NextTagItem(&tstate))
     {
         switch (tag->ti_Tag)
         {
             case TAG1: ...
                        break;

             case TAG2: ...
                        break;

             ...
         }
     }
 }
```

**Notes:**
Do NOT use the value of *tagItemPtr, but rather use the pointer
 returned by NextTagItem().

**See also:** <utility/tagitem.h>, GetTagData(), PackBoolTags(), FindTagItem()

---

### utility.library/PackBoolTags (V36)

**builds a "flag" word from a tag list.**

**Synopsis:**
```c
flags = PackBoolTags(initialFlags,tagList,boolMap);

 ULONG PackBoolTags(ULONG,struct TagItem *,struct TagItem *);
```

**Description:**
Picks out the boolean tag items in a tag list and converts
 them into bit-flag representations according to a correspondence
 defined by the tag list 'boolMap'.

 A boolean tag item is one where only the logical value of
 the ti_Data is relevant. If this field is 0, the value is
 FALSE, otherwise TRUE.

**Inputs:**
initialFlags - a starting set of bit-flags which will be changed
                by the processing of TRUE and FALSE boolean tags
                in tagList.
 tagList - a TagItem list which may contain several tag items defined to
           be boolean by their presence in boolMap. The logical value of
           ti_Data determines whether a tag item causes the bit-flag
           value related by boolMap to be set or cleared in the returned
           flag longword.
 boolMap - a tag list defining the boolean tags to be recognized, and
           the bit (or bits) in the returned longword that are to be set
           or cleared when a boolean Tag is found to be TRUE or FALSE in
           tagList.

**Result:**
flags - the accumulated longword of bit-flags, starting with
         initialFlags and modified by each boolean tag item
         encountered.

**Example:**
```c
/* define some nice user tag values ... */
 enum mytags { tag1 = TAG_USER+1, tag2, tag3, tag4, tag5 };

 /* this TagItem list defines the correspondence between boolean tags
  * and bit-flag values.
  */
 struct TagItem boolMap[] =
 {
     {tag1,     0x0001},
     {tag2,     0x0002},
     {tag3,     0x0004},
     {tag4,     0x0008},
     {TAG_DONE, }
 };

 /* You are probably passed these by some client, and you want
  * to "collapse" the boolean content into a single longword.
  */

 struct TagItem boolExample[] =
 {
     {tag1,     TRUE},
     {tag2,     FALSE},
     {tag5,     Irrelevant},
     {tag3,     TRUE},
     {TAG_DONE, }
 };

 /* Perhaps 'boolFlags' already has a current value of 0x800002. */
 boolFlags = PackBoolTags(boolFlags,boolExample,boolMap);

 /* The resulting new value of 'boolFlags' will be 0x80005. */
```

**Notes:**
In a case where there is duplication of a tag in tagList, the
 last of the identical tags will hold sway.

**See also:** <utility/tagitem.h>, GetTagData(), FindTagItem(), NextTagItem()

---

### utility.library/PackStructureTags (V39)

**pack a structure with values from taglist.**

**Synopsis:**
```c
num = PackStructureTags(pack,packTable,tagList);

ULONG PackStructureTags(APTR,ULONG *,struct TagItem *);
```

**Description:**
For each table entry, a FindTagItem() will be done and if the
matching tag is found in the taglist, the data field will be
packed into the given structure based on the packtable
definition.

**Inputs:**
pack - a pointer to the data area to fill in.
packTable - a pointer to the packing information table.
            See <utility/pack.h> for definition and macros.
tagList - a pointer to the taglist to pack into the structure

**Result:**
num - the number of tag items packed

**See also:** <utility/pack.h>, FindTagItem(), UnpackStructureTags()

---

### utility.library/RefreshTagItemClones (V36)

**rejuvenate a clone from the original.**

**Synopsis:**
```c
RefreshTagItemClones(clone,original)

 VOID RefreshTagItemClones(struct TagItem *,struct TagItem *);
```

**Description:**
If (and only if) the tag list 'clone' was created from 'original' by
 CloneTagItems(), and if 'original' has not been changed in any way,
 you can reset the clone list to its original state by using this
 function.

**Inputs:**
clone - return value from CloneTagItems(original)
 original - a tag list that hasn't changed since CloneTagItems()

**See also:** <utility/tagitem.h>, CloneTagItems(), AllocateTagItems(),
 FreeTagItems(), ApplyTagChanges()

---

### utility.library/ReleaseNamedObject (V39)

**free a named object.**

**Synopsis:**
```c
ReleaseNamedObject(object);

VOID ReleaseNamedObject(struct NamedObject *);
```

**Description:**
Decrements the open count of the object. If the object has been
removed, and the count goes to 0, the remover will be notified
that the object is now free.

**Inputs:**
object - the object to release.  (No action if NULL)

**See also:** FindNamedObject(), RemNamedObject()

---

### utility.library/RemNamedObject (V39)

**remove a named object.**

**Synopsis:**
```c
RemNamedObject(object, message);

VOID RemNamedObject(struct NamedObject *, struct Message *);
```

**Description:**
This function will post a request to release the object
from whatever NameSpace it is in.  It will reply the message
when the object is fully removed.  The message.mn_Node.ln_Name
field will contain the object pointer or NULL if the object
was removed by another process.

This function will effectively do a ReleaseNamedObject()
thus you must have "found" the object first.

**Inputs:**
object - the object to remove: Must be a valid NamedObject.
message - message to ReplyMsg() (must be supplied)

**Result:**
The message is replied with the ln_Name field either being
the object or NULL. If it contains the object, the object
is completely removed.

**See also:** AttemptRemNamedObject(), AddNamedObject(), ReleaseNamedObject()

---

### utility.library/Stricmp (V37)

**case-insensitive string comparison.**

**Synopsis:**
```c
result = Stricmp(string1,string2);

LONG Stricmp(STRPTR,STRPTR);
```

**Description:**
This function compares two strings, ignoring case using a generic
case conversion routine. If the strings have different lengths,
the shorter is treated as if it were extended with zeros.

**Inputs:**
string1, string2 - strings to be compared

**Result:**
result - relationship between string1 and string2
                <0 means string1 < string2
                =0 means string1 = string2
                >0 means string1 > string2

**Notes:**
Whenever locale.library is installed in a system, this function is
replaced by language-specific code. This means that depending on
which language the user has currently selected, identical pairs of
strings may return different values when passed to this function.
This fact must be taken into consideration when using this function.

**See also:** Strnicmp(), locale.library/StrnCmp()

---

### utility.library/Strlen

**Determine the length of a string. (V53.4)**

**Synopsis:**
```c
uint32 length = Strlen(string);
```

**Description:**
Strlen() works very much like the standard 'C' library strlen()
routine. It is primarily useful for situations where the standard
'C' library is not available.

**Inputs:**
string -- Pointer to a NUL-terminated string to measure the length of.

**Result:**
length -- Total length of the string excluding the NUL terminator.

---

### utility.library/Strnicmp (V37)

**length-limited case-insensitive string compare.**

**Synopsis:**
```c
result = Strnicmp(string1,string2,length);

LONG Strnicmp(STRPTR,STRPTR,LONG);
```

**Description:**
This function compares two strings, ignoring case using a generic
case conversion routine. If the strings have different lengths,
the shorter is treated as if it were extended with zeros. This function
never compares more than 'length' characters.

**Inputs:**
string1, string2 - strings to be compared
length - maximum number of characters to examine

**Result:**
result - relationship between string1 and string2
                <0 means string1 < string2
                =0 means string1 = string2
                >0 means string1 > string2

**Notes:**
Whenever locale.library is installed in a system, this function is
replaced by language-specific code. This means that depending on
which language the user has currently selected, identical pairs of
strings may return different values when passed to this function.
This fact must be taken into consideration when using this function.

**See also:** Stricmp(), locale.library/StrnCmp()

---

### utility.library/TagInArray (V36)

**check if a tag value appears in an array of tag values.**

**Synopsis:**
```c
result = TagInArray(tagValue,tagArray);

 BOOL TagInArray(Tag,Tag *);
```

**Description:**
Performs a quick scan to see if a tag value appears in an array
 terminated with TAG_DONE. Returns TRUE if the value is found.

 The 'tagArray' must be terminated by TAG_DONE. Note that this is an
 array of tag values, NOT an array of TagItems.

**Inputs:**
tagValue - tag value to search array for in array.
 tagArray - a simple array of tag values terminated by TAG_DONE.

**Result:**
result - TRUE if tagValue was found in tagArray.

**See also:** <utility/tagitem.h>, FilterTagItems()

---

### utility.library/ToLower (V37)

**convert a character to lower case.**

**Synopsis:**
```c
char = ToLower(char);

TEXT ToLower(TEXT);
```

**Description:**
Converts a character to lower case, handling international character
sets.

**Inputs:**
char - character to be converted.

**Result:**
char - lower case version of the input character.

**Notes:**
Whenever locale.library is installed in a system, this function is
replaced by language-specific code. This means that depending on
which language the user has currently selected, a given character may
return different results when passed to this function. This fact must
be taken into consideration when using this function.

**See also:** ToUpper(), locale.library/ConvToLower()

---

### utility.library/ToUpper (V37)

**convert a character to upper case.**

**Synopsis:**
```c
char = ToUpper(char);

TEXT ToUpper(TEXT);
```

**Description:**
Converts a character to upper case, handling international character
sets.

**Inputs:**
char - character to be converted.

**Result:**
char - upper case version of the input character.

**Notes:**
Whenever locale.library is installed in a system, this function is
replaced by language-specific code. This means that depending on
which language the user has currently selected, a given character may
return different results when passed to this function. This fact must
be taken into consideration when using this function.

**See also:** ToUpper(), locale.library/ConvToLower()

---

### utility.library/UnpackStructureTags (V39)

**unpack a structure to values in taglist.**

**Synopsis:**
```c
num = UnpackStructureTags(pack,packTable,tagList);

ULONG UnpackStructureTags(APTR,ULONG *,struct TagItem *);
```

**Description:**
For each table entry, a FindTagItem() will be done and if the
matching tag is found in the taglist, the data in the structure
will be placed into the memory pointed to by the tag's ti_Data.
ti_Data *must* point to a LONGWORD.

**Inputs:**
pack - a pointer to the data area to be unpacked
packTable - a pointer to the packing information table.
            See <utility/pack.h> for definition and macros
tagList - a pointer to the taglist to unpack into

**Result:**
num - the number of tag items unpacked

**See also:** <utility/pack.h>, FindTagItem(), PackStructureTags()

---
