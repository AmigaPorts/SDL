---
title: amiga.lib/CxTranslate
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-cxtranslate
functions: [CreateCxObj, SetTranslate]
libraries: [commodities.library]
---

# amiga.lib/CxTranslate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CxTranslate -- create a commodity translator object. (V36)
```
SYNOPSIS

```c
    translatorObj = CxTranslate(ie);

    CxObj *CxTranslate(struct [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md) *);
```
FUNCTION

```c
    This function creates a Commodities 'translator' object.
    The action of this object on receiving a Commodities message is to
    replace that message in the commodities network with a chain of
    Commodities input messages.

    There is one new Commodities input message generated for each input
    event in the linked list starting at 'ie' (and NULL terminated). The
    routing information of the new input messages is copied from the input
    message they replace.

    The linked list of input events associated with a translator object
    can be changed using the [SetTranslate()](autodocs-2.0/commodities-library-settranslate.md) function.

    If 'ie' is NULL, the null translation occurs: that is, the original
    commodities input message is disposed, and no others are created to
    take its place.

    This function is a C-language macro for [CreateCxObj()](autodocs-2.0/commodities-library-createcxobj.md), defined
    in [<libraries/commodities.h>](autodocs-2.0/includes-libraries-commodities-h.md).
```
INPUTS

    ie - the input event list used as replacement by the translator
RESULTS

    translatorObj - a pointer to the translator object, or NULL if it could
                    not be created.
SEE ALSO

```c
    [commodities.library/CreateCxObj()](autodocs-2.0/commodities-library-createcxobj.md), [commodities.library/SetTranslate()](autodocs-2.0/commodities-library-settranslate.md)
```

---

## See Also

- [CreateCxObj — commodities.library](../autodocs/commodities.library.md#createcxobj)
- [SetTranslate — commodities.library](../autodocs/commodities.library.md#settranslate)
