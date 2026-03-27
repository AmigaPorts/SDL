# commodities.library/InvertKeyMap



NAME

```c
    InvertKeyMap -- generate an input event from an ANSI code. (V36)
```
SYNOPSIS

```c
    success = InvertKeyMap(ansicode,event,km)
                           D0       A0    A1

    BOOL InvertKeyMap(ULONG,struct [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198) *,struct [KeyMap](../Includes_and_Autodocs_2._guide/node003A.html#line22) *);
```
FUNCTION

```c
    This function uses the system call [MapANSI()](../Includes_and_Autodocs_2._guide/node0314.html) to figure out what
    [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198) translates to an ANSI character code 'ansicode'. The
    [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198) pointed to by 'event' is filled in with that information.
    The [KeyMap](../Includes_and_Autodocs_2._guide/node003A.html#line22) 'km' is used for the translation, unless it is NULL, in
    which case the system default keymap (as defined when
    commodities.library is initialized) is used.
```
INPUTS

```c
    ansicode - the ANSI code to convert to an input event
    event - the [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198) to fill-in
    km - the keymap to use for the translation, or NULL to use the
         system default keymap.
```
RESULTS

    success - TRUE if the translation worked, FALSE otherwise.
BUGS

```c
    This function currently handles one-deep dead keys (such as
    <alt f>o). It does not look up the high key map (keystrokes
    with scan codes greater than 0x40), and misses system changes to
    the default key map.
```
SEE ALSO

```c
    [cx_lib/InvertString()](../Includes_and_Autodocs_2._guide/node0160.html)
```
