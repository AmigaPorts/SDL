---
title: utility.library (basename: _UtilityBase)  V36
manual: amiga-mail
chapter: amiga-mail
section: utility-library-basename-utilitybase-v36
functions: []
libraries: []
---

# utility.library (basename: _UtilityBase)  V36

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

AllocateTagItems(numItems)(d0)          - Allocate a TagItem array (or
```c
                                          chain). (V36)
```
Amiga2Date(amigaTime,date)(d0/a0)       - Calculate the date from a
```c
                                          timestamp.  (V36)
```
CallHookPkt(hook,object,paramPacket)(a0/a2,a1)
```c
                                        - Invoke a Hook function callback.
                                          (V36)
```
CheckDate(date)(a0)                     - Checks ClockData struct for
```c
                                          legal date. (V36)
```
CloneTagItems(tagList)(a0)              - Copies a TagItem list.  (V36)
Date2Amiga(date)(a0)                    - Calculate seconds from
```c
                                          01-Jan-1978.  (V36)
```
FilterTagChanges(newTagList,oldTagList,apply)(a0/a1,d0)
```c
                                        - Eliminate TagItems which specify
                                          no change. (V36)
```
FilterTagItems(tagList,filterArray,logic)(a0/a1,d0)
```c
                                        - Remove selected items from a
                                          TagItem list. (V36)
```
FindTagItem(tagVal,tagList)(d0/a0)      - Scans TagItem list for a Tag.
```c
                                          (V36)
```
FreeTagItems(tagList)(a0)               - Frees allocated TagItem lists.
```c
                                          (V36)
```
GetTagData(tagVal,defaultVal,tagList)(d0/d1/a0)
```c
                                        - Obtain data corresponding to
                                          Tag. (V36)
```
MapTags(tagList,mapList,includeMiss)(a0/a1,d0)
```c
                                        - Convert ti_Tag values in a list
                                          via map pairing. (V36)
```
NextTagItem(tagListPtr)(a0)             - Iterate TagItem lists. (V36)
PackBoolTags(initialFlags,tagList,boolMap)(d0/a0/a1)
```c
                                        - Builds a "Flag" word from a
                                          TagList. (V36)
```
RefreshTagItemClones(cloneList,origList)(a0/a1)
```c
                                        - Rejuvenates a clone from the
                                          original. (V36)
```
SDivMod32(dividend,divisor)(d0/d1)      - Signed 32 by 32 bit division and
```c
                                          modulus. (V36)
```
SMult32(factor1,factor2)(d0/d1)         - Signed 32 by 32 bit multiply
```c
                                          with 32 bit result. (V36)
```
Stricmp(string1,string2)(a0/a1)         - Case-insensitive string compare.
```c
                                          (V37)
```
Strnicmp(string1,string2,length)(a0/a1,d0)
```c
                                        - Case-insensitive string compare,
                                          length-limited. (V37)
```
TagInArray(tagVal,tagArray)(d0/a0)      - Check if a Tag value appears in
```c
                                          a Tag array. (V36)
```
ToLower(character)(d0)                  - Convert a character to
```c
                                          lowercase. (V37)
```
ToUpper(character)(d0)                  - Convert a character to
```c
                                          uppercase. (V37)
```
UDivMod32(dividend,divisor)(d0/d1)      - Unsigned 32 by 32 bit division
```c
                                          and modulus. (V36)
```
UMult32(factor1,factor2)(d0/d1)         - Unsigned 32 by 32 bit multiply

```c
                                          with 32 bit result. (V36)
```
