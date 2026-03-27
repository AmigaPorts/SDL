# icon.library/MatchToolValue



NAME

    MatchToolValue - check a tool type variable for a particular value.
SYNOPSIS

```c
    result = MatchToolValue(typeString, value)
      D0                        A0        A1

    BOOL MatchToolValue(char *, char *);
```
FUNCTION

```c
    MatchToolValue is useful for parsing a tool type value for
    a known value.  It knows how to parse the syntax for a tool
    type value (in particular, it knows that '|' separates
    alternate values).  Note that the parsing is case insensitve.
```
INPUTS

```c
    typeString - a ToolType value (as returned by FindToolType)
    value - you are interested if value appears in typeString
```
RESULTS

    result - TRUE if the value was in typeString else FALSE.
EXAMPLE

```c
    Assume there are two type strings:
        type1 = "text"
        type2 = "a|b|c"

    MatchToolValue( type1, "text" ) returns TRUE
    MatchToolValue( type1, "TEXT" ) returns TRUE
    MatchToolValue( type1, "data" ) returns FALSE
    MatchToolValue( type2, "a" ) returns TRUE
    MatchToolValue( type2, "b" ) returns TRUE
    MatchToolValue( type2, "d" ) returns FALSE
    MatchToolValue( type2, "a|b" ) returns FALSE
```
SEE ALSO

```c
    [FindToolType()](../Includes_and_Autodocs_2._guide/node0186.html)
```
BUGS

    None
