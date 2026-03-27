# 12 / / The Public Classes / The Imageclass Subclasses


Normally, an application does not create an [imageclass](../Libraries_Manual_guide/node04D1.html) object. Instead, it
will use a subclass of imageclass.  Currently, there are four subclasses:
frameiclass, sysiclass, fillrectclass, and itexticlass.

[frameiclass](../Libraries_Manual_guide/node04DF.html)

```c
    An embossed or recessed rectangular frame image, that renders itself
    using the proper [DrawInfo](../Libraries_Manual_guide/node00DE.html#line6) pens.  This class is intelligent enough to
    bound or center its contents.
```
[sysiclass](../Libraries_Manual_guide/node04E7.html)

    The class of system images.  The class includes the images for the
    system and GadTools gadgets.
[fillrectclass](../Libraries_Manual_guide/node04EB.html)

    A class of rectangle images that have frame and patternfill support.
[itexticlass](../Libraries_Manual_guide/node04F0.html)

    A specialized image class used for rendering text.
For more information on these classes see the Boopsi Class Reference in
the [Appendix B](../Libraries_Manual_guide/node04B9.html) of this manual.  It describes all of the existing public
classes, their methods, and their attributes.

 [The Gadgetclass Subclasses](../Libraries_Manual_guide/node0209.html) 

