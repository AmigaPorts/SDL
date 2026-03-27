# amigaguide.library/--rexxhost--



   HOST INTERFACE

```c
        amigaguide.library provides an ARexx function host interface that
        enables ARexx programs to take advantage of the features of
        AmigaGuide. The functions provided by the interface are directly
        related to the functions described herein, with the differences
        mostly being in the way they are called.

        The function host library vector is located at offset -30 from
        the library. This is the value you provide to ARexx in the
        AddLib() function call.
```
   FUNCTIONS

```c
        ShowNode (PUBSCREEN,DATABASE,NODE,LINE,XREF)

        LoadXRef (NAME)

        GetXRef (NODE)

        AddXRef (WORD,FILE,LINE,TYPE)

        ExpungeXRef ()
```
   BUGS

```c
        V39, V40 and V41 did not support the ExpungeXRef() and
        AddXRef() commands. This was fixed in V44.
```
