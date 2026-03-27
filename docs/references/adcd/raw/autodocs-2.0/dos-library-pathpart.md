# dos.library/PathPart



NAME

```c
    PathPart -- Returns a pointer to the end of the next-to-last (V36)
                component of a path.
```
SYNOPSIS

```c
    fileptr = PathPart( path )
    D0                   D1

    STRPTR PathPart( STRPTR )
```
FUNCTION

```c
    This function returns a pointer to the character after the next-to-last
    component of a path specification, which will normally be the directory
    name.  If there is only one component, it returns a pointer to the
    beginning of the string.  The only real difference between this and
    [FilePart()](../Includes_and_Autodocs_2._guide/node02A4.html) is the handling of '/'.
```
INPUTS

    path - pointer to an path string.  May be relative to the current
           directory or the current disk.
RESULT

    fileptr - pointer to the end of the next-to-last component of the path.
EXAMPLE

```c
    PathPart("xxx:yyy/zzz/qqq") would return a pointer to the last '/'.
    PathPart("xxx:yyy") would return a pointer to the first 'y').
```
SEE ALSO

```c
    [FilePart()](../Includes_and_Autodocs_2._guide/node02A4.html), [AddPart()](../Includes_and_Autodocs_2._guide/node027D.html)
```
