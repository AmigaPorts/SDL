# Gadgetclass Subclasses


A gadgetclass object contains an Intuition Gadget structure.  Like
imageclass, applications do not normally create objects of this class,
but instead create objects of subclasses of gadgetclass.  Currently,
gadgetclass has four subclasses:

propgclass - An easy to use, one-dimensional proportional gadget.

strgclass - A string gadget.

groupgclass - A special gadget class that creates one composite gadget
  out of several others.

buttongclass - A repeating boolean button gadget.


buttongclass has a subclass of its own:

frbuttongclass - A button that outlines its label with a frame.


The example [boopsi1.c](../AmigaMail_Vol2_guide/node01AE.html) (at the end of this article) uses sysiclass images
and several boopsi gadgets.  The example takes care of processing and
updating the gadgets.

