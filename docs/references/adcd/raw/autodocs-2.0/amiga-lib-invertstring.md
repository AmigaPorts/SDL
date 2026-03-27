# amiga.lib/InvertString



NAME

```c
    InvertString -- produce input events that would generate the
                    given string. (V36)
```
SYNOPSIS

```c
    events = InvertString(str,km)

    struct [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198) *InvertString(STRPTR,struct [KeyMap](../Includes_and_Autodocs_2._guide/node003A.html#line22) *);
```
FUNCTION

```c
    This function returns a linked list of input events which would
    translate into the string using the supplied keymap (or the system
    default keymap if 'km' is NULL).

    'str' is null-terminated and may contain:
       - ANSI character codes
       - backslash escaped characters:
            n   -   CR
            r   -   CR
            t   -   TAB
            0   -   illegal, do not use!
            \   -   backslash
       - a text description of an input event as used by [ParseIX()](../Includes_and_Autodocs_2._guide/node01AF.html),
         enclosed in angle brackets.

    An example is:

      abc<alt f1>nhi there.
```
INPUTS

    str - null-terminated string to convert to input events
    km - keymap to use for the conversion, or NULL to use the default
         keymap.
RESULTS

```c
    events - a chain of input events, or NULL if there was a problem. The
             most likely cause of failure is an illegal description
             enclosed in angled brackets.

             This chain should eventually be freed using [FreeIEvents()](../Includes_and_Autodocs_2._guide/node015C.html).
```
SEE ALSO

```c
    [commodities.library/ParseIX()](../Includes_and_Autodocs_2._guide/node01AF.html), [FreeIEvents()](../Includes_and_Autodocs_2._guide/node015C.html)
```
