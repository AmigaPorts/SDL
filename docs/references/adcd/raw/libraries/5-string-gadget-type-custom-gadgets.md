# 5 / String Gadget Type / Custom Gadgets


Intuition also supports custom gadgets, where the application can supply
to Intuition its own code to manage gadgets.  This allows the creation of
gadgets with behavior quite different from standard [boolean](../Libraries_Manual_guide/node014C.html), [proportional](../Libraries_Manual_guide/node0153.html),
or [string](../Libraries_Manual_guide/node0164.html) gadgets.  For example, it would be possible to create a dial
gadget, where the user could rotate the [knob](../Libraries_Manual_guide/node015A.html) of a gadget.  The code for a
custom gadget needs to respond to various commands and requests from
Intuition, such as "is this pixel in your hit-area?", "please go active"
and "please go inactive".

Intuition has an object-oriented creation and delegation method called
BOOPSI, that allows custom gadgets to be easily created, deleted,
specialized from existing classes of custom gadget, and so on.  See the
Intuition chapter "[BOOPSI](../Libraries_Manual_guide/node0218.html)" for details.

