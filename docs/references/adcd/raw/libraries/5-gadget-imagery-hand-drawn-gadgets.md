# 5 / Gadget Imagery / Hand Drawn Gadgets


Bitmap or custom images are used as imagery for a gadget by setting the
[GFLG_GADGIMAGE](../Libraries_Manual_guide/node014A.html#line23) flag in the [Flags](../Libraries_Manual_guide/node0149.html#line48) field of the [Gadget](../Libraries_Manual_guide/node0149.html) structure.  An [Image](../Libraries_Manual_guide/node01BA.html)
structure must be set up to manage the bitmap data.  The address of the
Image structure is placed into the gadget's [GadgetRender](../Libraries_Manual_guide/node0149.html#line91) field.  The
bitmap image will be positioned relative to the gadget's select box.  For
more information about creating Intuition images, see the chapter
"[Intuition Images, Line Drawing, and Text](../Libraries_Manual_guide/node01B9.html)."  For a listing of the Gadget
structure and all its flags see the "[Gadget Structure](../Libraries_Manual_guide/node0149.html)" section later in
this chapter.

