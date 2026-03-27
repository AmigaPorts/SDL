# commodities.library/ParseIX



NAME

```c
    ParseIX -- initialize an input expression given a description string.
               (V36)
```
SYNOPSIS

```c
    failureCode = ParseIX(description,ix);
                          A0          A1

    LONG ParseIX(STRPTR,IX *);
```
FUNCTION

    Given an input description string and an allocated input
    expression, sets the fields of the input expression to
    correspond to the description string.
INPUTS

    description - the string to parse
    ix - the input expression to hold the result of the parse
RESULTS

```c
    failureCode -  0 if all went well,
                  -1 if tokens after end (code spec)
                  -2 if 'description' was NULL
```
