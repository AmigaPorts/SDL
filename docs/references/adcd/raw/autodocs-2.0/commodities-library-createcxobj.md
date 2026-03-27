# commodities.library/CreateCxObj



NAME

```c
    CreateCxObj -- create a new commodity object. (V36)
```
SYNOPSIS

```c
    co = CreateCxObj(type,arg1,arg2);
                     D0   A0   A1

    CxObj *CreateCxObj(ULONG,LONG,LONG);
```
FUNCTION

```c
    This function creates a commodity object of type 'type'. It is not
    proper to call this function directly. Each object creation routine
    except [CxBroker()](../Includes_and_Autodocs_2._guide/node01A2.html) is defined as a macro in [<libraries/commodities.h>](../Includes_and_Autodocs_2._guide/node00F0.html)
    These are independently documented.

    All functions which operate on a commodity object are made with
    a reference to the thirty-two bit value returned by this function
    (or by [CxBroker()](../Includes_and_Autodocs_2._guide/node01A2.html)).
```
INPUTS
```c
    type - the type of object to create as defined in
           [<libraries/commodities.h>](../Includes_and_Autodocs_2._guide/node00F0.html)
```
   arg1 - first argument, meaning depends on 'type'

    arg2 - second argument, meaning depends on 'type'
RESULTS

```c
    co - a pointer to the new object or NULL if it could not be created.
         A NULL return indicates typically a lack of system memory. Minor
         problems in creating an object, such as providing a bad filter
         description to [cx_lib/CxFilter()](../Includes_and_Autodocs_2._guide/node014D.html), typically don't cause failure,
         but are recorded in an internal error field in the new object
         which can be accessed via [CxObjError()](../Includes_and_Autodocs_2._guide/node01A6.html).
```
SEE ALSO

```c
    [CxObjError()](../Includes_and_Autodocs_2._guide/node01A6.html), [cx_lib/CxFilter()](../Includes_and_Autodocs_2._guide/node014D.html), [cx_lib/CxSender()](../Includes_and_Autodocs_2._guide/node014E.html),
    [cx_lib/CxSignal()](../Includes_and_Autodocs_2._guide/node014F.html), [cx_lib/CxTranslate()](../Includes_and_Autodocs_2._guide/node0150.html), [cx_lib/CxDebug()](../Includes_and_Autodocs_2._guide/node014C.html),
    [cx_lib/CxCustom()](../Includes_and_Autodocs_2._guide/node014B.html), [CxBroker()](../Includes_and_Autodocs_2._guide/node01A2.html)
```
