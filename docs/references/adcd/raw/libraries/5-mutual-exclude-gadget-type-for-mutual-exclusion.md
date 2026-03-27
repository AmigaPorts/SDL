# 5 / / Mutual Exclude / Gadget Type for Mutual Exclusion


To implement mutual exclusion, gadgets must be hit-select (not
[GACT_TOGGLESELECT](../Libraries_Manual_guide/node014B.html#line2)) [boolean](../Libraries_Manual_guide/node014C.html) gadgets, with the [GACT_IMMEDIATE](../Libraries_Manual_guide/node014B.html#line9) activation
type (never [GACT_RELVERIFY](../Libraries_Manual_guide/node014B.html#line14)).  All state changes must be executed upon
receiving the [IDCMP_GADGETDOWN](../Libraries_Manual_guide/node01DD.html) message for the gadgets.  Failure to do
this could introduce subtle out-of-phase imagery problems.

