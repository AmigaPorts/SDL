# amiga.lib/CxDebug



NAME

```c
    CxDebug -- create a commodity debug object. (V36)
```
SYNOPSIS

```c
    debugObj = CxDebug(id);

    CxObj *CxDebug(LONG);
```
FUNCTION

```c
    This function creates a Commodities debug object. The action of this
    object on receiving a Commodities message is to print out information
    about the Commodities message through the serial port (using the
    kprintf() routine). The value of 'id' will also be displayed.

    Note that this is a synchronous occurence (the printing is done by
    the input device task). If screen or file output is desired, using a
    sender object instead of a debug object is necessary, since such
    output is best done by your application process.

    This function is a C-language macro for [CreateCxObj()](../Includes_and_Autodocs_2._guide/node01A1.html), defined
    in [<libraries/commodities.h>](../Includes_and_Autodocs_2._guide/node00F0.html).
```
INPUTS

    id - the id to assign to the debug object, this value is output
         whenever the debug object sends data to the serial port.
RESULTS

    debugObj - a pointer to the debug object, or NULL if it could
               not be created.
SEE ALSO

```c
    [commodities.library/CreateCxObj()](../Includes_and_Autodocs_2._guide/node01A1.html), [CxSender()](../Includes_and_Autodocs_2._guide/node014E.html), debug.lib/kprintf()
```
