# 12 / / Using Boopsi / Getting an Object's Attributes


The Intuition function [GetAttr()](../Includes_and_Autodocs_2._guide/node021B.html) asks an object what the value of a
specific attribute is:


```c
    ULONG GetAttr(ULONG attrID, APTR myobject, ULONG *mydata);
```
where attrID is the attribute's ID number, myobject is the object to get
the attribute from, and mydata points to a data area that will hold the
attribute value.  This function returns a 0L if the object doesn't
recognize the attribute, otherwise it returns some non-zero value, the
meaning of which depends on the class.  In most cases, [GetAttr()](../Includes_and_Autodocs_2._guide/node021B.html) returns a
1 when it is successful.

Not all object attributes are obtainable using the [GetAttr()](../Includes_and_Autodocs_2._guide/node021B.html) function.
Some classes are set up so that applications cannot query the state of
certain attributes.  For example, using the [GA_Image](../Libraries_Manual_guide/node0509.html) attribute, an
application can give a Boopsi prop gadget ([propgclass](../Libraries_Manual_guide/node020A.html#line4)) an [Image](../Libraries_Manual_guide/node01BA.html) structure
which the gadget uses as the imagery for its knob. This attribute is not
"gettable" as there is no need for an application to have to ask the
gadget for the structure that the application passed it in the first
place.  Whether or not a specific attribute is "gettable" is class
dependent.  For more information about the attributes of specific classes,
see the Boopsi Class Reference in the [Appendix B](../Libraries_Manual_guide/node04B9.html) of this manual.

