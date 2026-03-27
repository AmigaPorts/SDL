# 5 / Proportional Gadget Type / Modifying an Existing Gadget


To change the flags and the [pot](../Libraries_Manual_guide/node015B.html) and [body](../Libraries_Manual_guide/node015C.html) variables after the gadget is
displayed, the program can call [NewModifyProp()](../Includes_and_Autodocs_2._guide/node022E.html).


```c
    void NewModifyProp( struct Gadget *gadget, struct Window *window,
                        struct Requester *requester, unsigned long flags,
                        unsigned long horizPot, unsigned long vertPot,
                        unsigned long horizBody, unsigned long vertBody,
                        long numGad );
```
The gadget's internal state will be recalculated and the imagery will be
redisplayed to show the new state.  When numGads (in the prototype above)
is set to all ones, [NewModifyProp()](../Includes_and_Autodocs_2._guide/node022E.html) will only update those parts of the
imagery that have changed, which is much faster than removing the gadget,
changing values, adding the gadget back and refreshing its imagery.

