# dos.library/ExAll



NAME

```c
    ExAll -- Examine an entire directory (V36)
```
SYNOPSIS

```c
    continue = ExAll(lock, buffer, size, type, control)
    D0               D1     D2     D3    D4     D5

    BOOL ExAll(BPTR,STRPTR,LONG,LONG,struct [ExAllControl](../Includes_and_Autodocs_2._guide/node0079.html#line62) *)
```
FUNCTION

    Examines an entire directory.
Lock must be on a directory.  Size is the size of the buffer supplied.
The buffer will be filled with (partial) [ExAllData](../Includes_and_Autodocs_2._guide/node0079.html#line39) structures, as
specified by the type field.

Type is a value from those shown below that determines which information is
to be stored in the buffer.  Each higher value adds a new thing to the list
as described in the table below:-


```c
    ED_NAME         FileName
    ED_TYPE         Type
    ED_SIZE         Size in bytes
    ED_PROTECTION   Protection bits
    ED_DATE         3 longwords of date
    ED_COMMENT      Comment (will be NULL if no comment)
```
Thus, ED_NAME gives only filenames, and ED_COMMENT gives everything.

The ead_Next entry gives a pointer to the next entry in the buffer.  The
last entry will have NULL in ead_Next.

The control structure is required so that FFS can keep track if more than
one call to ExAll is required.  This happens when there are more names in
a directory than will fit into the buffer.  The format of the control
structure is as follows:-

NOTE: the control structure MUST be allocated by AllocDosObject!!!

Entries:  This field tells the calling application how many entries are

        in the buffer after calling ExAll.  Note: make sure your code
        handles the 0 entries case, including 0 entries with continue
        non-zero.
LastKey:  This field ABSOLUTELY MUST be initialised to 0 before calling

```c
        ExAll for the first time.  Any other value will cause nasty
        things to happen.  If ExAll returns non-zero, then this field
        should not be touched before making the second and subsequent
        calls to ExAll.  Whenever ExAll returns non-zero, there are more
        calls required before all names have been received.

        As soon as a FALSE return is received then ExAll has completed
        (if [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html) returns ERROR_NO_MORE_ENTRIES - otherwise it returns
        the error that occured, similar to ExNext.)
```
MatchString

```c
        If this field is NULL then all filenames will be returned.  If
        this field is non-null then it is interpreted as a pointer to
        a string that is used to pattern match all file names before
        accepting them and putting them into the buffer.  The default
        AmigaDOS caseless pattern match routine is used.  This string
        MUST have been parsed by ParsePatternNoCase()!
```
MatchFunc:

```c
        Contains a pointer to a hook for a routine to decide if the entry
        will be included in the returned list of entries.  The entry is
        filled out first, and then passed to the hook.  If no MatchFunc is
        to be called then this entry should be NULL.  The hook is
        called with the following parameters (as is standard for hooks):

        BOOL = MatchFunc( hookptr, data, typeptr )
                            a0      a1      a2
        (a0 = ptr to hook, a1 = ptr to filled in [ExAllData](../Includes_and_Autodocs_2._guide/node0079.html#line39), a2 = ptr
         to longword of type).

        MatchFunc should return FALSE if the entry is not to be
        accepted, otherwise return TRUE.

    Note that Dos will emulate ExAll() using [Examine()](../Includes_and_Autodocs_2._guide/node029C.html) and [ExNext()](../Includes_and_Autodocs_2._guide/node02A0.html)
    if the handler in question doesn't support the ExAll() packet.
```
INPUTS

```c
    lock    - Lock on directory to be examined.
    buffer  - Buffer for data returned (MUST be at least word-aligned,
              preferably long-word aligned).
    size    - Size in bytes of 'buffer'.
    type    - Type of data to be returned.
    control - Control data structure (see notes above).  MUST have been
              allocated by AllocDosObject!
```
RESULT

```c
    continue - Whether or not ExAll is done.  If FALSE is returned, either
               ExAll has completed (IoErr() == ERROR_NO_MORE_ENTRIES), or
               an error occurred (check IoErr()).  If non-zero is returned,
               you MUST call ExAll again until it returns FALSE.
```
EXAMPLE

eac = AllocDosObject(DOS_EXALLCONTROL,NULL);
if (!eac) ...
...
eac->eac_LastKey = 0;
do {
   more = ExAll(lock, EAData, sizeof(EAData), ED_FOO, eac);
   if ((!more) && (IoErr() != ERROR_NO_MORE_ENTRIES)) {
```c
       /* ExAll failed abnormally */
       break;
```
   }
   if (eac->eac_Entries == 0) {
```c
       /* ExAll failed normally with no entries */
       continue;                   /* ("more" is *usually* zero) */
```
   }
   ead = (struct [ExAllData](../Includes_and_Autodocs_2._guide/node0079.html#line39) *) EAData;
   do {
```c
       /* use ead here */
       ...
       /* get next ead */
       ead = ead->ed_Next;
```
   } while (ead);

} while (more);
...
FreeDosObject(DOS_EXALLCONTROL,eac);

BUGS

```c
    In V36, there were problems with ExAll (particularily with
    eac_MatchString, and ed_Next with the ramdisk and the emulation
    of it in Dos for handlers that do not support the packet.  It is
    advised you only use this under V37 and later.
```
SEE ALSO

```c
    [Examine()](../Includes_and_Autodocs_2._guide/node029C.html), [ExNext()](../Includes_and_Autodocs_2._guide/node02A0.html), [ExamineFH()](../Includes_and_Autodocs_2._guide/node029D.html), [MatchPatternNoCase()](../Includes_and_Autodocs_2._guide/node02D0.html),
    [ParsePatternNoCase()](../Includes_and_Autodocs_2._guide/node02DC.html), [AllocDosObject()](../Includes_and_Autodocs_2._guide/node027F.html)
```
