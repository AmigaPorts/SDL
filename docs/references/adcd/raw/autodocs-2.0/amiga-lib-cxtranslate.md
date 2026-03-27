# amiga.lib/CxTranslate



NAME

```c
    CxTranslate -- create a commodity translator object. (V36)
```
SYNOPSIS

```c
    translatorObj = CxTranslate(ie);

    CxObj *CxTranslate(struct [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198) *);
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
    can be changed using the [SetTranslate()](../Includes_and_Autodocs_2._guide/node01B5.html) function.

    If 'ie' is NULL, the null translation occurs: that is, the original
    commodities input message is disposed, and no others are created to
    take its place.

    This function is a C-language macro for [CreateCxObj()](../Includes_and_Autodocs_2._guide/node01A1.html), defined
    in [<libraries/commodities.h>](../Includes_and_Autodocs_2._guide/node00F0.html).
```
INPUTS

    ie - the input event list used as replacement by the translator
RESULTS

    translatorObj - a pointer to the translator object, or NULL if it could
                    not be created.
SEE ALSO

```c
    [commodities.library/CreateCxObj()](../Includes_and_Autodocs_2._guide/node01A1.html), [commodities.library/SetTranslate()](../Includes_and_Autodocs_2._guide/node01B5.html)
```
