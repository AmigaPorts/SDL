# iffparse.library — Autodoc Reference

*Filtered to AmigaOS V39 and below.*

**Functions:** 40

## Function Index

- **AllocIFF** (V36) — create a new IFFHandle structure.
- **AllocLocalItem** (V36) — create a local context item structure.
- **CloseClipboard** (V36) — close and free an open ClipboardHandle.
- **CloseIFF** (V36) — close an IFF context.
- **CollectionChunk** (V36) — declare a chunk type for collection.
- **CollectionChunks** (V36) — declare many collection chunks at once.
- **CurrentChunk** (V36) — get context node for current chunk.
- **EntryHandler** (V36) — add an entry handler to the IFFHandle context.
- **ExitHandler** (V36) — add an exit handler to the IFFHandle context.
- **FindCollection** (V36) — get a pointer to the current list of collection
- **FindLocalItem** (V36) — return a local context item from the context stack.
- **FindProp** (V36) — search for a stored property chunk.
- **FindPropContext** (V36) — get the property context for the current state.
- **FreeIFF** (V36) — deallocate an IFFHandle structure.
- **FreeLocalItem** (V36) — deallocate a local context item structure.
- **GoodID** (V36) — test if an identifier follows the IFF 85 specification.
- **GoodType** (V36) — test if a type follows the IFF 85 specification.
- **IDtoStr** (V36) — convert a longword identifier to a null-terminated string.
- **InitIFF** (V36) — initialize an IFFHandle structure as a user stream.
- **InitIFFasClip** (V36) — initialize an IFFHandle as a clipboard stream.
- **InitIFFasDOS** (V36) — initialize an IFFHandle as a DOS stream.
- **LocalItemData** (V36) — get pointer to user data for local context item.
- **OpenClipboard** (V36) — create a handle on a clipboard unit.
- **OpenIFF** (V36) — prepare an IFFHandle to read or write a new IFF stream.
- **ParentChunk** (V36) — get the nesting context node for the given chunk.
- **ParseIFF** (V36) — parse an IFF file from an IFFHandle structure stream.
- **PopChunk** (V36) — pop top context node off context stack.
- **PropChunk** (V36) — specify a property chunk to store.
- **PropChunks** (V36) — declare many property chunks at once.
- **PushChunk** (V36) — push a new context node on the context stack.
- **ReadChunkBytes** (V36) — read bytes from the current chunk into a buffer.
- **ReadChunkRecords** (V36) — read record elements from the current chunk into
- **SetLocalItemPurge** (V36) — set purge vector for a local context item.
- **StopChunk** (V36) — declare a chunk which should cause ParseIFF to return.
- **StopChunks** (V36) — declare many stop chunks at once.
- **StopOnExit** (V36) — declare a stop condition for exiting a chunk.
- **StoreItemInContext** (V36) — store local context item in given context node.
- **StoreLocalItem** (V36) — insert a local context item into the context stack.
- **WriteChunkBytes** (V36) — write data from a buffer into the current chunk.
- **WriteChunkRecords** (V36) — write records from a buffer to the current

## Functions

### iffparse.library/AllocIFF (V36)

**create a new IFFHandle structure.**

**Synopsis:**
```c
iff = AllocIFF()

struct IFFHandle *AllocIFF(VOID);
```

**Description:**
Allocates and initializes a new IFFHandle structure.
This function is the only supported way to create an IFFHandle
structure since there are private fields that need to be initialized.

**Result:**
iff - pointer to IFFHandle structure or NULL if the allocation failed.

**See also:** FreeIFF(), <libraries/iffparse.h>

---

### iffparse.library/AllocLocalItem (V36)

**create a local context item structure.**

**Synopsis:**
```c
item = AllocLocalItem(type, id, ident, dataSize);

struct LocalContextItem *AllocLocalItem(LONG, LONG, LONG, LONG);
```

**Description:**
Allocates and initializes a LocalContextItem structure with "dataSize"
bytes of associated user data. This is the only supported way to
create such an item. The user data can be accessed with the
LocalItemData() function. An item created with this function
automatically has its purge vectors set up correctly to dispose of
itself and its associated user data area. Any additional cleanup
should be done with a user-supplied purge vector.

**Inputs:**
type,id - additional longword identification values
ident - longword identifier for class of context item
dataSize - number of bytes of user data to allocate for this item

**Result:**
item - pointer to initialized LocalContextItem or NULL if the
allocation failed.

**See also:** FreeLocalItem(), LocalItemData(), StoreLocalItem(),
StoreItemInContext(), SetLocalItemPurge(), <libraries/iffparse.h>

---

### iffparse.library/CloseClipboard (V36)

**close and free an open ClipboardHandle.**

**Synopsis:**
```c
CloseClipboard(clipHandle);

VOID CloseClipboard(struct ClipboardHandle *);
```

**Description:**
Closes the clipboard.device and frees the ClipboardHandle structure.

**Inputs:**
clipHandle - pointer to ClipboardHandle struct created with
      OpenClipboard(). Starting with V39, this may be NULL.

**See also:** OpenClipboard(), InitIFFasClip(), <libraries/iffparse.h>

---

### iffparse.library/CloseIFF (V36)

**close an IFF context.**

**Synopsis:**
```c
CloseIFF(iff);

VOID CloseIFF(struct IFFHandle *);
```

**Description:**
Completes an IFF read or write operation by closing the IFF context
established for this IFFHandle structure. The IFFHandle structure
itself is left ready for re-use and a new context can be opened with
OpenIFF(). This function can be used for cleanup if a read or write
fails partway through.

As part of its cleanup operation, CloseIFF() calls the client-
supplied stream hook vector. The IFFStreamCmd packet will be set
as follows:

	sc_Command:	IFFCMD_CLEANUP
	sc_Buf:		(Not applicable)
	sc_NBytes:	(Not applicable)

This operation is NOT permitted to fail;  any error code returned
will be ignored (best to return 0, though). DO NOT write to this
structure.

**Inputs:**
iff - pointer to IFFHandle structure previously opened with
      OpenIFF(). Starting with V39, this may be NULL.

**See also:** OpenIFF(), InitIFF(), <libraries/iffparse.h>

---

### iffparse.library/CollectionChunk (V36)

**declare a chunk type for collection.**

**Synopsis:**
```c
error = CollectionChunk(iff, type, id);

LONG CollectionChunk(struct IFFHandle *, LONG, LONG);
```

**Description:**
Installs an entry handler for chunks with the given type and id so
that the contents of those chunks will be stored as they are
encountered. This is like PropChunk() except that more than one
chunk of this type can be stored in lists which can be returned by
FindCollection(). The storage of these chunks still follows the
property chunk scoping rules for IFF files so that at any given
point, stored collection chunks will be valid in the current context.

**Inputs:**
iff - pointer to IFFHandle structure (does not need to be open)
type - type code for the chunk to declare (ex. "ILBM")
id - identifier for the chunk to declare (ex. "CRNG")

**Result:**
error - 0 if successful or an IFFERR_#? error code if unsuccessful.

**See also:** CollectionChunks(), FindCollection(), PropChunk(),
<libraries/iffparse.h>

---

### iffparse.library/CollectionChunks (V36)

**declare many collection chunks at once.**

**Synopsis:**
```c
error = CollectionChunks(iff, propArray, numPairs);

LONG CollectionChunks(struct IFFHandle *, LONG *, LONG);
```

**Description:**
Declares multiple collection chunks from a list. The propArray argument
is a pointer to an array of longwords arranged in pairs. The format
for the list is as follows:

	TYPE1, ID1, TYPE2, ID2, ..., TYPEn, IDn

The argument numPairs is the number of pairs. CollectionChunks() just calls
CollectionChunk() numPairs times.

**Inputs:**
iff - pointer to IFFHandle structure (does not need to be open)
propArray - pointer to array of longword chunk types and identifiers
numPairs - number of pairs in array.

**Result:**
error - 0 if successful or an IFFERR_#? error code if unsuccessful

**See also:** CollectionChunk(), <libraries/iffparse.h>

---

### iffparse.library/CurrentChunk (V36)

**get context node for current chunk.**

**Synopsis:**
```c
top = CurrentChunk(iff);

struct ContextNode *CurrentChunk(struct IFFHandle *);
```

**Description:**
Returns the top context node for the given IFFHandle structure. The top
context node corresponds to the chunk most recently pushed on the
stack, which is the chunk where the stream is currently positioned.
The ContextNode structure contains information on the type of chunk
currently being parsed (or written), its size and the current
position within the chunk.

**Inputs:**
iff - pointer to IFFHandle structure

**Result:**
top - pointer to top context node or NULL if none

**See also:** PushChunk(), PopChunk(), ParseIFF(), ParentChunk(),
<libraries/iffparse.h>

---

### iffparse.library/EntryHandler (V36)

**add an entry handler to the IFFHandle context.**

**Synopsis:**
```c
error = EntryHandler(iff, type, id, position, handler, object);

LONG EntryHandler(struct IFFHandle *, LONG, LONG, LONG,
           struct Hook *, APTR);
```

**Description:**
Installs an entry handler vector for a specific type of chunk into
the context for the given IFFHandle structure. Type and id are the
longword identifiers for the chunk to handle. The handler is a client-
supplied standard Hook structure, properly initialized. position
tells where to put the handler in the context. The handler will be
called whenever the parser enters a chunk of the given type, so the
IFF stream will be positioned to read the first data byte in the
chunk. The handler will execute in the same context as whoever
called ParseIFF(). The handler will be called (through the hook)
with the following arguments:

	A0:	the Hook pointer you passed.
	A2:	the 'object' pointer you passed.
	A1:	pointer to a LONG containing the value
		IFFCMD_ENTRY.

The error code your call-back routine returns will affect the parser
in three different ways:

Return value		Result
------------		------
0:			Normal success;  ParseIFF() will continue
			through the file.
IFF_RETURN2CLIENT:	ParseIFF() will stop and return the value 0.
			(StopChunk() is internally implemented using
			this return value.)
Any other value:	ParseIFF() will stop and return the value
			you supplied. This is how errors should be
			returned.

**Inputs:**
iff - pointer to IFFHandle structure.
type - type code for chunk to handle (ex. "ILBM").
id - ID code for chunk to handle (ex. "CMAP").
position- local context item position. One of the IFFSLI_#? codes.
handler - pointer to Hook structure.
object - a client-defined pointer which is passed in A2 during call-
	 back.

**Result:**
error - 0 if successful or an IFFERR_#? error code if unsuccessful.

**Bugs:**
Returning the values IFFERR_EOF or IFFERR_EOC from the call-back
routine *may* confuse the parser.

There is no way to explicitly remove a handler once installed.
However, by installing a do-nothing handler using IFFSLI_TOP,
previous handlers will be overridden until the context expires.

**See also:** ExitHandler(), StoreLocalItem(), StoreItemInContext(),
<utility/hooks.h>, <libraries/iffparse.h>

---

### iffparse.library/ExitHandler (V36)

**add an exit handler to the IFFHandle context.**

**Synopsis:**
```c
error = ExitHandler(iff, type, id, position, handler, object);

LONG ExitHandler(struct IFFHandle *, LONG, LONG, LONG,
          struct Hook *, APTR object(;
```

**Description:**
Installs an exit handler vector for a specific type of chunk into the
context for the given IFFHandle structure. Type and id are the longword
identifiers for the chunk to handle. The handler is a client-supplied
standard Hook structure, properly initialized. Position tells
where to put the handler in the context. The handler will be called
just before the parser exits the given chunk in the "pause" parse
state. The IFF stream may not be positioned predictably within the
chunk. The handler will execute in the same context as whoever
called ParseIFF(). The handler will be called (through the hook)
with the following arguments:

	A0:	the Hook pointer you passed.
	A2:	the 'object' pointer you passed.
	A1:	pointer to a LONG containing the value
		IFFCMD_EXIT.

The error code your call-back routine returns will affect the parser
in three different ways:

Return value		Result
------------		------
0:			Normal success;  ParseIFF() will continue
			through the file.
IFF_RETURN2CLIENT:	ParseIFF() will stop and return the value 0.
			(StopChunk() is internally implemented using
			this return value.)
Any other value:	ParseIFF() will stop and return the value
			you supplied. This is how errors should be
			returned.

**Inputs:**
iff - pointer to IFFHandle structure.
type - type code for chunk to handle (ex. "ILBM").
id - identifier code for chunk to handle (ex. "CMAP").
position - local context item position. One of the IFFSLI_#? codes.
handler - pointer to Hook structure.
object - a client-defined pointer which is passed in A2 during call-
	 back.

**Result:**
error - 0 if successful or an IFFERR_#? error code if unsuccessful.

**Bugs:**
Returning the values IFFERR_EOF or IFFERR_EOC from the call-back
routine *may* confuse the parser.

There is no way to explicitly remove a handler once installed.
However, by installing a do-nothing handler using IFFSLI_TOP,
previous handlers will be overridden until the context expires.

**See also:** EntryHandler(), StoreLocalItem(), StoreItemInContext(),
<utility/hooks.h>, <libraries/iffparse.h>

---

### iffparse.library/FindCollection (V36)

**get a pointer to the current list of collection
		  items.**

**Synopsis:**
```c
ci = FindCollection(iff, type, id);

struct CollectionItem *FindCollection(struct IFFHandle *, LONG, LONG);
```

**Description:**
Returns a pointer to a list of CollectionItem structures for each of
the collection chunks of the given type encountered so far in the
course of parsing this IFF file. The items appearing first in the
list will be the ones encountered most recently.

**Inputs:**
iff - pointer to IFFHandle structure.
type - type code to search for.
id - identifier code to search for.

**Result:**
ci - pointer to last collection chunk encountered with
     links to previous ones.

**See also:** CollectionChunk(), CollectionChunks(), <libraries/iffparse.h>

---

### iffparse.library/FindLocalItem (V36)

**return a local context item from the context stack.**

**Synopsis:**
```c
lci = FindLocalItem(iff, type, id, ident);

struct LocalContextItem	*FindLocalItem(struct IFFHandle	*,
                                LONG, LONG, LONG);
```

**Description:**
Searches the context stack of the given IFFHandle structure for a
local context item which matches the given ident, type and id. This
function searches the context stack from the most current context
backwards, so that the item found (if any) will be the one with
greatest precedence in the context stack.

**Inputs:**
iff - pointer to IFFHandle structure.
type - type code to search for.
id - ID code to search for.
ident - ident code for the class of context item to search for
	(ex. "exhd" -- exit handler).

**Result:**
lci - pointer to local context item, or NULL if nothing matched.

**See also:** StoreLocalItem(), <libraries/iffparse.h>

---

### iffparse.library/FindProp (V36)

**search for a stored property chunk.**

**Synopsis:**
```c
sp = FindProp(iff, type, id);

struct StoredProperty *FindProp(struct IFFHandle *, LONG, LONG);
```

**Description:**
Searches for the stored property which is valid in the given context.
Property chunks are automatically stored by ParseIFF() when
pre-declared by PropChunk() or PropChunks(). The StoredProperty
struct, if found, contains a pointer to a data buffer containing the
contents of the stored property.

**Inputs:**
iff - pointer to IFFHandle structure.
type - type code for chunk to search for (ex. "ILBM").
id - identifier code for chunk to search for (ex. "CMAP").

**Result:**
sp - pointer to stored property, or NULL if none found.

**See also:** PropChunk(), PropChunks(), <libraries/iffparse.h>

---

### iffparse.library/FindPropContext (V36)

**get the property context for the current state.**

**Synopsis:**
```c
cn = FindPropContext(iff);

struct ContextNode *FindPropContext(struct IFFHandle *);
```

**Description:**
Locates the context node which would be the scoping chunk for
properties in the current parsing state. (Huh?)  This is used for
locating the proper scoping context for property chunks i.e. the
scope from which a property would apply. This is usually the FORM
or LIST with the highest precedence in the context stack.

If you don't understand this, read the IFF spec a couple more times.

**Inputs:**
iff - pointer to IFFHandle structure.

**Result:**
cn - ContextNode of property scoping chunk.

**See also:** CurrentChunk(), ParentChunk(), StoreItemInContext(),
<libraries/iffparse.h>

---

### iffparse.library/FreeIFF (V36)

**deallocate an IFFHandle structure.**

**Synopsis:**
```c
FreeIFF(iff);

VOID FreeIFF(struct IFFHandle *);
```

**Description:**
Deallocates all resources associated with this IFFHandle structure.
The structure MUST have already been closed with CloseIFF().

**Inputs:**
iff - pointer to IFFHandle structure to free. Starting with V39,
      this may be NULL.

**See also:** AllocIFF(), CloseIFF(), <libraries/iffparse.h>

---

### iffparse.library/FreeLocalItem (V36)

**deallocate a local context item structure.**

**Synopsis:**
```c
FreeLocalItem(localItem);

VOID FreeLocalItem(struct LocalContextItem *);
```

**Description:**
Frees the memory for the local context item and any associated user
memory as allocated with AllocLocalItem(). User purge vectors should
call this function after they have freed any other resources
associated with this item.

Note that FreeLocalItem() does NOT call the custom purge vector set
up through SetLocalItemPurge(); all it does is free the local context
item. (This implies that your custom purge vector would want to call
this to ultimately free the LocalContextItem.)

**Inputs:**
localItem - pointer to LocalContextItem created with AllocLocalItem.
     Starting with V39, this may be NULL.

**See also:** AllocLocalItem(), <libraries/iffparse.h>

---

### iffparse.library/GoodID (V36)

**test if an identifier follows the IFF 85 specification.**

**Synopsis:**
```c
isok = GoodID(id);

LONG GoodID(LONG);
```

**Description:**
Tests the given longword identifier to see if it meets all the EA IFF
85 specifications for a chunk ID. If so, it returns non-zero,
otherwise 0.

**Inputs:**
id - potential 32 bit identifier.

**Result:**
isok - non-zero if this is a valid ID, 0 otherwise.

**See also:** GoodType()

---

### iffparse.library/GoodType (V36)

**test if a type follows the IFF 85 specification.**

**Synopsis:**
```c
isok = GoodType(type)

LONG GoodType(LONG);
```

**Description:**
Tests the given longword type identifier to see if it meets all the
EA IFF 85 specifications for a FORM type (requirements for a FORM
type are more stringent than those for a simple chunk ID). If it
complies, GoodType() returns non-zero, otherwise 0.

**Inputs:**
type - potential 32 bit format type identifier.

**Result:**
isok - non-zero if this is a valid type id, 0 otherwise.

**See also:** GoodID()

---

### iffparse.library/IDtoStr (V36)

**convert a longword identifier to a null-terminated string.**

**Synopsis:**
```c
str = IDtoStr(id, buf);

STRPTR IDtoStr(LONG, STRPTR);
```

**Description:**
Writes the ASCII equivalent of the given longword ID into buf as a
null-terminated string.

**Inputs:**
id - longword ID.
buf - character buffer to accept string (at least 5 chars).

**Result:**
str - the value of 'buf'.

---

### iffparse.library/InitIFF (V36)

**initialize an IFFHandle structure as a user stream.**

**Synopsis:**
```c
InitIFF(iff, flags, streamHook);

VOID InitIFF(struct IFFHandle *, LONG, struct Hook *);
```

**Description:**
Initializes an IFFHandle as a general user-defined stream by
allowing the user to declare a hook that the library will call to
accomplish the low-level reading, writing, and seeking of the stream.
Flags are the stream I/O flags for the specified stream; typically a
combination of the IFFF_?SEEK flags.

The stream vector is called with the following arguments:

	A0:	pointer to streamhook.
	A2:	pointer to IFFHandle structure.
	A1:	pointer to IFFStreamCmd structure.

The IFFStreamCmd packet appears as follows:

	sc_Command:	Contains an IFFCMD_#? value
	sc_Buf:		Pointer to memory buffer
	sc_NBytes:	Number of bytes involved in operation

The values taken on by sc_Command, and their meaning, are as follows:

IFFCMD_INIT:
	Prepare your stream for reading. This is used for certain
	streams that can't be read immediately upon opening, and need
	further preparation. (The clipboard.device is an example of
	such a stream.)  This operation is allowed to fail;  any
	error code will be returned directly to the client. sc_Buf
	and sc_NBytes have no meaning here.
IFFCMD_CLEANUP:
	Terminate the transaction with the associated stream. This
	is used with streams that can't simply be closed. (Again,
	the clipboard is an example of such a stream.)  This
	operation is not permitted to fail;  any error returned will
	be ignored (best to return 0, though). sc_Buf and sc_NBytes
	have no meaning here.
IFFCMD_READ:
	Read from the stream. You are to read sc_NBytes from the
	stream and place them in the buffer pointed to by sc_Buf.
	Any (non-zero) error returned will be remapped by the parser
	into IFFERR_READ.
IFFCMD_WRITE:
	Write to the stream. You are to write sc_NBytes to the
	stream from the buffer pointed to by sc_Buf. Any (non-zero)
	error returned will be remapped by the parser into
	IFFERR_WRITE.
IFFCMD_SEEK:
	Seek on the stream. You are to perform a seek on the stream
	relative to the current position. sc_NBytes is signed;
	negative values mean seek backward, positive values mean seek
	forward. sc_Buf has no meaning here. Any (non-zero) error
	returned will be remapped by the parser into IFFERR_SEEK.

All errors are returned in D0. A return of 0 indicates success.
UNDER NO CIRCUMSTANCES are you permitted to write to the IFFStreamCmd
structure.

**Inputs:**
iff - pointer to IFFHandle structure to initialize.
flags - stream I/O flags for the IFFHandle.
streamHook - pointer to Hook structure.

**See also:** <utility/hooks.h>, <libraries/iffparse.h>

---

### iffparse.library/InitIFFasClip (V36)

**initialize an IFFHandle as a clipboard stream.**

**Synopsis:**
```c
InitIFFasClip(iff);

VOID InitIFFasClip(struct IFFHandle *);
```

**Description:**
Initializes the given IFFHandle to be a clipboard stream. The
function initializes the stream processing vectors to operate on
streams of the ClipboardHandle type. The iff_Stream field will still
need to be initialized to point to a ClipboardHandle as returned from
OpenClipboard().

**Inputs:**
iff - pointer to IFFHandle structure.

**See also:** InitIFF(), OpenClipboard(), <libraries/iffparse.h>

---

### iffparse.library/InitIFFasDOS (V36)

**initialize an IFFHandle as a DOS stream.**

**Synopsis:**
```c
InitIFFasDOS(iff)

InitIFFasDOS(struct IFFHandle *);
```

**Description:**
The function initializes the given IFFHandle to operate on DOS
streams. The iff_Stream field will need to be initialized as a BPTR
returned from the DOS function Open().

**Inputs:**
iff - pointer to IFFHandle structure.

**See also:** InitIFF()

---

### iffparse.library/LocalItemData (V36)

**get pointer to user data for local context item.**

**Synopsis:**
```c
data = LocalItemData(localItem);

APTR LocalItemData(struct LocalContextItem *);
```

**Description:**
Returns pointer to the user data associated with the given local
context item. The size of the data area depends on the "dataSize"
argument used when allocating this item. If the pointer to the item
given (localItem) is NULL, this function returns NULL.

**Inputs:**
localItem - pointer to local context item or NULL.

**Result:**
data - pointer to user data area or NULL if localItem is NULL.

**Bugs:**
Currently, there is no way to determine the size of the user data
area; you have to 'know'.

**See also:** AllocLocalItem(), FreeLocalItem(), <libraries/iffparse.h>

---

### iffparse.library/OpenClipboard (V36)

**create a handle on a clipboard unit.**

**Synopsis:**
```c
ch = OpenClipboard(unitNumber)

struct ClipboardHandle *OpenClipboard(LONG);
```

**Description:**
Opens the clipboard.device and opens a stream for the specified unit
(usually PRIMARY_CLIP). This handle structure will be used as the
clipboard stream for IFFHandles initialized as clipboard streams by
InitIFFasClip().

**Inputs:**
unitNumber - clipboard unit number (usually PRIMARY_CLIP).

**Result:**
ch - pointer to ClipboardHandle structure or NULL if unsuccessful.

**Bugs:**
This function had several bugs prior to V39.

First bug was that if the clipboard.device couldn't open, two calls
to FreeSignal() were made with uninitialized values as parameters.
The result of this was a corrupt signal mask in the Task field.

Second bug was that OpenDevice() was called with an IO request that
didn't have a valid MsgPort pointer in it.

Third bug was that the two message ports allocated by the function
(ClipboardHandle->cbh_CBport and ClipboardHandle->cbh_SatisfyPort)
were not being initialized correctly and would cause a system crash
if a message ever got to either of them.


This function had several other bugs prior to V50.

First bug was that if one of the signals this function uses could
not be allocated, no previously allocated signal was never freed.

Second bug was that the cleanup function supposed to free any
allocated signals in case of failure then tried to free signal
#0 twice.

Third bug was that if any of the signals could not be allocated,
then the cleanup routine would attempt to close clipboard.device
without having actually opened it. Because the IOClipReq's
io_Device structure member would contain random data, a serious
crash would result.

**See also:** InitIFFasClip(), CloseClipboard(), <libraries/iffparse.h>

---

### iffparse.library/OpenIFF (V36)

**prepare an IFFHandle to read or write a new IFF stream.**

**Synopsis:**
```c
error = OpenIFF(iff, rwMode);

LONG OpenIFF(struct IFFHandle *, LONG);
```

**Description:**
Initializes an IFFHandle structure for a new read or write. The
direction of the I/O is given by the value of rwMode, which can be
either IFFF_READ or IFFF_WRITE.

As part of its initialization procedure, OpenIFF() calls the client-
supplied stream hook vector. The IFFStreamCmd packet will contain
the following:

	sc_Command:	IFFCMD_INIT
	sc_Buf:		(Not applicable)
	sc_NBytes:	(Not applicable)

This operation is permitted to fail. DO NOT write to this structure.

**Inputs:**
iff - pointer to IFFHandle structure. Starting with V39, this may be
      NULL, in which case IFFERR_NOMEM is returned.
rwMode - IFFF_READ or IFFF_WRITE

**Result:**
error - contains an error code or 0 if successful

**See also:** CloseIFF(), InitIFF(), <libraries/iffparse.h>

---

### iffparse.library/ParentChunk (V36)

**get the nesting context node for the given chunk.**

**Synopsis:**
```c
parent = ParentChunk(contextNode);

struct ContextNode *ParentChunk(struct ContextNode *);
```

**Description:**
Returns a context node for the chunk containing the chunk for the
given context node. This function effectively moves down the context
stack into previously pushed contexts. For example, to get a
ContextNode pointer for the enclosing FORM chunk while reading a data
chunk, use: ParentChunk(CurrentChunk(iff)) to find this pointer.
The ContextNode structure contains information on the type of chunk
and its size.

**Inputs:**
contextNode - pointer to a context node.

**Result:**
parent - pointer to the enclosing context node or NULL if none.

**See also:** CurrentChunk(), <libraries/iffparse.h>

---

### iffparse.library/ParseIFF (V36)

**parse an IFF file from an IFFHandle structure stream.**

**Synopsis:**
```c
error = ParseIFF(iff, control);

LONG ParseIFF(struct IFFHandle *, LONG);
```

**Description:**
This is the biggie.

Traverses a file opened for read by pushing chunks onto the context
stack and popping them off directed by the generic syntax of IFF
files. As it pushes each new chunk, it searches the context stack
for handlers to apply to chunks of that type. If it finds an entry
handler it will invoke it just after entering the chunk. If it finds
an exit handler it will invoke it just before leaving the chunk.
Standard handlers include entry handlers for pre-declared
property chunks and collection chunks and entry and exit handlers for
for stop chunks - that is, chunks which will cause the ParseIFF()
function to return control to the client. Client programs can also
provide their own custom handlers.

The control flag can have three values:

IFFPARSE_SCAN:
	In this normal mode, ParseIFF() will only return control to
	the caller when either:
		1) an error is encountered,
		2) a stop chunk is encountered, or a user handler
		   returns the special IFF_RETURN2CLIENT code, or
		3) the end of the logical file is reached, in which
		   case IFFERR_EOF is returned.

	ParseIFF() will continue pushing and popping chunks until one
	of these conditions occurs. If ParseIFF() is called again
	after returning, it will continue to parse the file where it
	left off.

IFFPARSE_STEP and _RAWSTEP:
	In these two modes, ParseIFF() will return control to the
	caller after every step in the parse, specifically, after
	each push of a context node and just before each pop. If
	returning just before a pop, ParseIFF() will return
	IFFERR_EOC, which is not an error, per se, but is just an
	indication that the most recent context is ending. In STEP
	mode, ParseIFF() will invoke the handlers for chunks, if
	any, before returning. In RAWSTEP mode, ParseIFF() will not
	invoke any handlers and will return right away. In both
	cases the function can be called multiple times to step
	through the parsing of the IFF file.

**Inputs:**
iff - pointer to IFFHandle structure.
control	- control code (IFFPARSE_SCAN, _STEP or _RAWSTEP).

**Result:**
error - 0 or IFFERR_#? value or return value from user handler.

**See also:** PushChunk(), PopChunk(), EntryHandler(), ExitHandler(),
PropChunk(), CollectionChunk(), StopChunk(), StopOnExit(),
<libraries/iffparse.h>

---

### iffparse.library/PopChunk (V36)

**pop top context node off context stack.**

**Synopsis:**
```c
error = PopChunk(iff);

LONG PopChunk(struct IFFHandle *);
```

**Description:**
Pops top context chunk and frees all associated local context items.
The function is normally called only for writing files and signals
the end of a chunk.

**Inputs:**
iff - pointer to IFFHandle structure.

**Result:**
error - 0 if successful or an IFFERR_#? error code if unsuccessful.

**See also:** PushChunk(), <libraries/iffparse.h>

---

### iffparse.library/PropChunk (V36)

**specify a property chunk to store.**

**Synopsis:**
```c
error = PropChunk(iff, type, id);

LONG PropChunk(struct IFFHandle *, LONG, LONG);
```

**Description:**
Installs an entry handler for chunks with the given type and ID so
that the contents of those chunks will be stored as they are
encountered. The storage of these chunks follows the property chunk
scoping rules for IFF files so that at any given point, a stored
property chunk returned by FindProp() will be the valid property for
the current context.

**Inputs:**
iff - pointer to IFFHandle structure (does not need to be open).
type - type code for the chunk to declare (ex. "ILBM").
id - identifier for the chunk to declare (ex. "CMAP").

**Result:**
error - 0 if successful or an IFFERR_#? error code if unsuccessful.

**See also:** PropChunks(), FindProp(), CollectionChunk(), <libraries/iffparse.h>

---

### iffparse.library/PropChunks (V36)

**declare many property chunks at once.**

**Synopsis:**
```c
error = PropChunks(iff, propArray, numPairs);

LONG PropChunks(struct IFFHandle *, LONG *, LONG);
```

**Description:**
Declares multiple property chunks from a list. The propArray argument
if a pointer to an array of longwords arranged in pairs, and has the
following format:

	TYPE1, ID1, TYPE2, ID2, ..., TYPEn, IDn

The argument numPairs is the number of pairs. PropChunks() just calls
PropChunk() numPairs times.

**Inputs:**
iff - pointer to IFFHandle structure.
propArray - pointer to array of longword chunk types and identifiers.
numPairs - number of pairs in the array.

**Result:**
error - 0 if successful or an IFFERR_#? error code if unsuccessful.

**See also:** PropChunk(), <libraries/iffparse.h>

---

### iffparse.library/PushChunk (V36)

**push a new context node on the context stack.**

**Synopsis:**
```c
error = PushChunk(iff, type, id, size);

LONG PushChunk(struct IFFHandle *, LONG, LONG, LONG);
```

**Description:**
Pushes a new context node on the context stack by reading it from the
stream if this is a read file, or by creating it from the passed
parameters if this is a write file. Normally this function is only
called in write mode, where the type and id codes specify the new
chunk to create. If this is a leaf chunk, i.e. a local chunk inside
a FORM or PROP chunk, then the type argument is ignored. If the size
is specified then the chunk writing functions will enforce this size.
If the size is given as IFFSIZE_UNKNOWN, the chunk will expand to
accommodate whatever is written into it.

**Inputs:**
iff - pointer to IFFHandle structure.
type - chunk type specifier (ex. ILBM) (ignored for read mode or
leaf chunks).
id - chunk id specifier (ex. CMAP) (ignored for read mode).
size - size of the chunk to create or IFFSIZE_UNKNOWN (ignored for
read mode).

**Result:**
error - 0 if successful or an IFFERR_#? error code if not unsuccessful.

**See also:** PopChunk(), WriteChunkRecords(), WriteChunkBytes(),
<libraries/iffparse.h>

---

### iffparse.library/ReadChunkBytes (V36)

**read bytes from the current chunk into a buffer.**

**Synopsis:**
```c
actual = ReadChunkBytes(iff, buf, numBytes);

LONG ReadChunkBytes(struct IFFHandle *, APTR buf, LONG);
```

**Description:**
Reads the IFFHandle stream into the buffer for the specified number
of bytes. Reads are limited to the size of the current chunk and
attempts to read past the end of the chunk will truncate. This
function returns positive number of bytes read or a negative error
code.

**Inputs:**
iff - pointer to IFFHandle structure.
buf - pointer to buffer area to receive data.
numBytes - number of bytes to read.

**Result:**
actual - (positive) number of bytes read if successful or a
	 (negative) IFFERR_#? error code if unsuccessful.

**See also:** ReadChunkRecords(), ParseIFF(), WriteChunkBytes(),
<libraries/iffparse.h>

---

### iffparse.library/ReadChunkRecords (V36)

**read record elements from the current chunk into
		    a buffer.**

**Synopsis:**
```c
actual = ReadChunkRecords(iff, buf, bytesPerRecord, numRecords);

LONG ReadChunkRecords(struct IFFHandle *, APTR, LONG, LONG);
```

**Description:**
Reads records from the current chunk into buffer. Truncates attempts
to read past end of chunk (only whole records are read; remaining
bytes that are not of a whole record size are left unread and
available for ReadChunkBytes()).

**Inputs:**
iff - pointer to IFFHandle structure.
buf - pointer to buffer area to receive data.
bytesPerRecord	- size of data records to read.
numRecords - number of data records to read.

**Result:**
actual - (positive) number of whole records read if successful or a
	 (negative) IFFERR_#? error code if unsuccessful.

**See also:** ReadChunkBytes(), ParseIFF(), WriteChunkRecords(),
<libraries/iffparse.h>

---

### iffparse.library/SetLocalItemPurge (V36)

**set purge vector for a local context item.**

**Synopsis:**
```c
SetLocalItemPurge(localItem, purgeHook);

VOID SetLocalItemPurge(struct LocalContextItem *, struct Hook *);
```

**Description:**
Sets a local context item to use a client-supplied cleanup (purge)
vector for disposal when its context is popped. The purge vector
will be called when the ContextNode containing this local item is
popped off the context stack and is about to be deleted itself. If
the purge vector has not been set, the parser will use FreeLocalItem()
to delete the item, but if this function is used to set the purge
vector, the supplied vector will be called with the following
arguments:

	A0:	pointer to purgeHook.
	A2:	pointer to LocalContextItem to be freed.
	A1:	pointer to a LONG containing the value
		IFFCMD_PURGELCI.

The user purge vector is then responsible for calling FreeLocalItem()
as part of its own cleanup. Although the purge vector can return a
value, it will be ignored -- purge vectors must always work (best to
return 0, though).

**Inputs:**
localItem - pointer to a local context item.
purgeHook - pointer to a Hook structure.

**See also:** AllocLocalItem(), FreeLocalItem(), <utility/hooks.h>
<libraries/iffparse.h>

---

### iffparse.library/StopChunk (V36)

**declare a chunk which should cause ParseIFF to return.**

**Synopsis:**
```c
error = StopChunk(iff, type, id);

LONG StopChunk(struct IFFHandle *, LONG, LONG);		 type;
```

**Description:**
Installs an entry handler for the specified chunk which will cause
the ParseIFF() function to return control to the caller when this
chunk is encountered. This is only of value when ParseIFF() is
called with the IFFPARSE_SCAN control code.

**Inputs:**
iff - pointer to IFFHandle structure (need not be open).
type - type code for chunk to declare (ex. "ILBM").
id - identifier for chunk to declare (ex. "BODY").

**Result:**
error - 0 if successful or an IFFERR_#? error code if unsuccessful.

**See also:** StopChunks(), ParseIFF(), <libraries/iffparse.h>

---

### iffparse.library/StopChunks (V36)

**declare many stop chunks at once.**

**Synopsis:**
```c
error = StopChunks(iff, propArray, numPairs);

LONG StopChunks(struct IFFHandle *, LONG *, LONG);
```

**Description:**
(is to StopChunk() as PropChunks() is to PropChunk().)

**Inputs:**
iff - pointer to IFFHandle structure.
propArray - pointer to array of longword chunk types and identifiers.
numPairs - number of pairs in the array.

**Result:**
error - 0 if successful or an IFFERR_#? error code if unsuccessful.

**See also:** StopChunk(), <libraries/iffparse.h>

---

### iffparse.library/StopOnExit (V36)

**declare a stop condition for exiting a chunk.**

**Synopsis:**
```c
error = StopOnExit(iff, type, id);

LONG StopOnExit(struct IFFHandle *, LONG, LONG);
```

**Description:**
Installs an exit handler for the specified chunk which will cause the
ParseIFF() function to return control to the caller when this chunk
is exhausted. ParseIFF() will return IFFERR_EOC when the declared
chunk is about to be popped. This is only of value when ParseIFF()
is called with the IFFPARSE_SCAN control code.

**Inputs:**
iff - pointer to IFFHandle structure (need not be open).
type - type code for chunk to declare (ex. "ILBM").
id - identifier for chunk to declare (ex. "BODY").

**Result:**
error - 0 if successful or an IFFERR_#? error code if unsuccessful.

**See also:** ParseIFF(), <libraries/iffparse.h>

---

### iffparse.library/StoreItemInContext (V36)

**store local context item in given context node.**

**Synopsis:**
```c
StoreItemInContext(iff, localItem, contextNode);

VOID StoreItemInContext(struct IFFHandle *, struct LocalContextItem *,
                        struct ContextNode *);
```

**Description:**
Adds the LocalContextItem to the list of items for the given context
node. If an LCI with the same Type, ID, and Ident is already
present in the ContextNode, it will be purged and replaced with the
new one. This is a raw form of StoreLocalItem().

**Inputs:**
iff - pointer to IFFHandle structure for this context.
localItem - pointer to a LocalContextItem to be stored.
contextNode - pointer to context node in which to store item.

**See also:** StoreLocalItem(), <libraries/iffparse.h>

---

### iffparse.library/StoreLocalItem (V36)

**insert a local context item into the context stack.**

**Synopsis:**
```c
error = StoreLocalItem(iff, localItem, position);

LONG StoreLocalItem(struct IFFHandle *, struct LocalContextItem	*,
             LONG);
```

**Description:**
Adds the local context item to the list of items for one of the
context nodes on the context stack and purges any other item in the
same context with the same ident, type and id. The position argument
determines where in the stack to add the item:

IFFSLI_ROOT:
	Add item to list at root (default) stack position.
IFFSLI_TOP:
	Add item to the top (current) context node.
IFFSLI_PROP:
	Add element in top property context. Top property context is
	either the top FORM chunk, or the top LIST chunk, whichever
	is closer to the top of the stack.

Items added to the root context, or added to the top context before
the IFFHandle has been opened or after it has been closed, are put in
the default context. That is, they will be the local items found
only after all other context nodes have been searched. Items in the
default context are also immune to being purged until the IFFHandle
structure itself is deleted with FreeIFF(). This means that handlers
installed in the root context will still be there after an IFFHandle
structure has been opened and closed. (Note that this implies that
items stored in a higher context will be deleted when that context
ends.)

**Inputs:**
iff - pointer to IFFHandle structure.
localItem - pointer to LocalContextItem struct to insert.
position - where to store the item (IFFSLI_ROOT, _TOP or _PROP).

**Result:**
error - 0 if successful or an IFFERR_#? error code if unsuccessful.

**See also:** FindLocalItem(), StoreItemInContext(), EntryHandler(), ExitHandler(),
<libraries/iffparse.h>

---

### iffparse.library/WriteChunkBytes (V36)

**write data from a buffer into the current chunk.**

**Synopsis:**
```c
error = WriteChunkBytes(iff, buf, numBytes);

LONG WriteChunkBytes(struct IFFHandle *, APTR, LONG);
```

**Description:**
Writes "numBytes" bytes from the specified buffer into the current
chunk. If the current chunk was pushed with IFFSIZE_UNKNOWN, the size
of the chunk gets increased by the size of the buffer written. If
the size was specified for this chunk, attempts to write past the end
of the chunk will be truncated.

**Inputs:**
iff - pointer to IFFHandle structure.
buf - pointer to buffer area with bytes to be written.
numBytes - number of bytes to write.

**Result:**
error - (positive) number of bytes written if successful or a
	(negative) IFFERR_#? error code if unsuccessful.

**See also:** PushChunk(), PopChunk(), WriteChunkRecords(), <libraries/iffparse.h>

---

### iffparse.library/WriteChunkRecords (V36)

**write records from a buffer to the current
		     chunk.**

**Synopsis:**
```c
error = WriteChunkRecords(iff, buf, recsize, numrec);

LONG WriteChunkRecords(struct IFFHandle *, APTR, LONG, LONG);
```

**Description:**
Writes record elements from the buffer into the top chunk. This
function operates much like ReadChunkBytes().

**Inputs:**
iff - pointer to IFFHandle structure.
buf - pointer to buffer area containing data.
recsize	- size of data records to write.
numrec - number of data records to write.

**Result:**
error - (positive) number of whole records written if successful
	or a (negative) IFFERR_#? error code if unsuccessful.

**See also:** WriteChunkBytes(), <libraries/iffparse.h>

---
