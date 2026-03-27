# 5 / Boolean Gadget Type / Mutual Exclude


Mutual exclusion of [boolean](../Libraries_Manual_guide/node014C.html) gadgets (sometimes referred to as "radio
buttons") is not directly supported by Intuition.  This section describes
the method an application should use to implement this feature.  It is up
to the application to handle the manipulation of excluded gadgets in an
Intuition compatible way.  The program must proceed with caution so as to
maintain the synchronization of the gadget and its imagery.  The rules
provided in this section for the implementation of mutual exclude gadgets
minimize the risk and complexity of the application.  Other techniques may
seem to work with simple input, but may fail in subtle ways when stressed.

 [Gadget Type for Mutual Exclusion](../Libraries_Manual_guide/node0150.html) 
 [Gadget Highlighting for Mutual Exclusion](../Libraries_Manual_guide/node0151.html) 
 [Handling of Mutually Exclusive Gadgets](../Libraries_Manual_guide/node0152.html) 

