---
title: commodities.library/ParseIX
manual: autodocs-2.0
chapter: autodocs-2.0
section: commodities-library-parseix
functions: []
libraries: []
---

# commodities.library/ParseIX

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

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
