---
title: commodities.library/ActivateCxObj
manual: autodocs-2.0
chapter: autodocs-2.0
section: commodities-library-activatecxobj
functions: [CxBroker]
libraries: [commodities.library]
---

# commodities.library/ActivateCxObj

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ActivateCxObj -- change the activation state of a commodity object.
                     (V36)
```
SYNOPSIS

```c
    previous = ActivateCxObj(co,true);
                             A0 D0

    LONG ActivateCxObj(CxObj *,LONG);
```
FUNCTION

    Commodity objects of all types maintain an "activation state".
    If an object is "active", then it performs its particular action
    whenever a commodity message arrives. If the object is "inactive"
    no action is taken, and the message goes on to its next destination.

    All objects are created in the "active" state except brokers
    which are created "inactive". Thus, after you create your
    broker and hang a tree of objects off of it, you must remember
    to use this function to activate it. This causes it to divert all
    messages to your tree of objects.

    This function activates 'co' if 'true' is different than 0. and
    deactivates it otherwise. The previous activation state is
    returned.
INPUTS

    co - the commodity object to affect
    true - 0 to deactivate the object, anything else to activate it
RESULTS

    previous - the previous activation state: 0 if the object was
               inactive, anything else if the object was active
SEE ALSO

```c
    [CxBroker()](autodocs-2.0/commodities-library-cxbroker.md)
```

---

## See Also

- [CxBroker — commodities.library](../autodocs/commodities.library.md#cxbroker)
