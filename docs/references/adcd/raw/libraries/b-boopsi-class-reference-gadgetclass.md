# B Boopsi Class Reference / gadgetclass


Class:                  gadgetclass
Superclass:             [rootclass](../Libraries_Manual_guide/node04BB.html)
Include File:           <intuition/[gadgetclass.h](../Includes_and_Autodocs_2._guide/node00D3.html)>

This is a base class for Intuition compatible gadget objects.  The
dispatcher for this class takes care of creating an Intuition [Gadget](../Libraries_Manual_guide/node0149.html)
structure as part of its local instance data.  All of the standard Boopsi
gadget classes build on this class.  Normally there are no direct
instances of this class, only instances of subclasses of gadgetclass.

The behavior of a Boopsi gadget depends on how it handles the five Boopsi
gadget methods: GM_HITTEST, GM_RENDER, GM_GOACTIVE, GM_HANDLEINPUT, and
GM_GOINACTIVE.  Intuition controls a Boopsi gadget by sending it these
types of messages.  The structures that these methods use for their
messages begin with the method's ID followed by a pointer to a [GadgetInfo](../Libraries_Manual_guide/node0219.html#line23)
structure (defined in <intuition/[cghooks.h](../Includes_and_Autodocs_2._guide/node00D2.html#line23)>).  The GadgetInfo structure is
a read-only structure that contains information about the gadget's
rendering environment.  The gadget uses this to find things like its
window, screen, or pen array.  Although this structure does contain a
pointer to a [RastPort](../Libraries_Manual_guide/node034A.html) for the gadget, the gadget must not use this
RastPort for rendering.  The gadget can obtain a RastPort for rendering by
calling the Intuition function [ObtainGIRPort()](../Includes_and_Autodocs_2._guide/node0232.html) using the GadgetInfo
structure.  See the intuition.library Autodocs for more details on this
function.

These methods are not defined directly by gadgetclass.  It is up to
subclasses of gadgetclass to implement them.

Like all Boopsi methods, these methods run on the context of the task that
called the method.  Normally, Intuition is the only entity that calls
these methods, so these normally operate in the input.device's task.
Because a gadget may have to process a large number of input events, poor
implementations of gadget methods (especially the GM_HANDLEINPUT method)
can degrade system performance.

New Methods:
------------
 [GM_HITTEST](../Libraries_Manual_guide/node04F3.html)    [GM_GOACTIVE](../Libraries_Manual_guide/node04F5.html)       [GM_GOINACTIVE](../Libraries_Manual_guide/node04F7.html) 
 [GM_RENDER](../Libraries_Manual_guide/node04F4.html)     [GM_HANDLEINPUT](../Libraries_Manual_guide/node04F6.html) 

Changed Methods:
----------------
 [OM_NEW](../Libraries_Manual_guide/node04F8.html)    [OM_NOTIFY](../Libraries_Manual_guide/node04F9.html) 

Attributes:
-----------
 [GA_Previous (I)](../Libraries_Manual_guide/node04FA.html) 
 [ICA_TARGET (IS)](../Libraries_Manual_guide/node04FB.html) 
 [ICA_MAP (IS)](../Libraries_Manual_guide/node04FC.html) 
 [GA_Left, GA_Top, GA_Width, GA_Height (IS)](../Libraries_Manual_guide/node04FD.html) 
 [GA_RelRight, GA_RelBottom, GA_RelWidth, GA_RelHeight (IS)](../Libraries_Manual_guide/node04FE.html) 

The remaining attributes defined by gadgetclass are used to set the fields
in the [Gadget](../Libraries_Manual_guide/node0149.html) structure of the Boopsi gadget.  Some Boopsi gadgets do not
pay attention to many of the fields in its Gadget structure, so most
applications will not have to worry about the majority of these
attributes.  Some gadget classes assign special meanings to these
attributes.  See the documentation of the specific gadget classes for more
details.

 [GA_IntuiText, GA_Text, GA_LabelImage (IS)](../Libraries_Manual_guide/node04FF.html) 
 [GA_Image (IS)](../Libraries_Manual_guide/node0500.html) 
 [GA_Border, GA_SelectRender, GA_ID, GA_UserData, GA_SpecialInfo (IS)](../Libraries_Manual_guide/node0501.html) 
 [GA_GZZGadget, GA_SysGadget (IS)](../Libraries_Manual_guide/node0502.html) 
 [GA_Disabled, GA_Selected (IS)](../Libraries_Manual_guide/node0503.html) 
 [GA_EndGadget, GA_Immediate, GA_RelVerify, GA_FollowMouse, (IS)](../Libraries_Manual_guide/node0504.html)     
 [GA_RightBorder, GA_LeftBorder, GA_TopBorder, GA_BottomBorder, (IS)](../Libraries_Manual_guide/node0504.html) 
 [GA_ToggleSelect, GA_TabCycle (IS)](../Libraries_Manual_guide/node0504.html)                                  
 [GA_Highlight (IS)](../Libraries_Manual_guide/node0505.html) 
 [GA_SysGType (IS)](../Libraries_Manual_guide/node0506.html) 

